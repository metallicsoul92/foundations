#include "../../include/core/allocator.h"

#include <sys/mman.h>
#include <string.h>

#define HEAD 0xAF
#define FOOT 0xFA

#define FLAG_UINIT 0        //header uninitialized
#define FLAG_USED  1        //header used
#define FLAG_HERR 2         //header error
#define FLAG_FREED 255      //header freed

#define KB 1024
#define MB 1024 * KB


////////////////////////////////////////////////////////
//    PRIVATE API
////////////////////////////////////////////////////////

struct _allocHeader{
	uint8_t _HEADMAGIC;
	uint8_t _flags;
	uint16_t _binID;
	uint32_t _size;
	uint16_t _offset;
	uint8_t _bPad;
	uint8_t _FOOTMAGIC;
};

typedef struct _allocHeader aHeader_t;

aHeader_t error_Header = {
  ._HEADMAGIC = HEAD,
  ._flags = FLAG_HERR,
  ._binID = 0,
  ._size = 0,
  ._offset = 0,
  ._bPad = 0,
  ._FOOTMAGIC = FOOT
};

aHeader_t int_alloc_createHeader(size_t size, uint16_t binID, uint16_t offset) {
    aHeader_t header;

    // Initialize header fields
    header._HEADMAGIC = HEAD;
    header._flags = FLAG_UINIT;
    header._bPad = 0;
    header._size = size;
    header._binID = binID;
    header._offset = offset;
    header._FOOTMAGIC = FOOT;

    // Verify header integrity
    if (header._HEADMAGIC != HEAD || header._FOOTMAGIC != FOOT) {
        // Header integrity check failed, handle the error (e.g., log or return an error code)
        // You may also choose to handle this error in a way that's appropriate for your application.
        // For example, you can return an error code or log a message indicating header corruption.
        return error_Header;
    }

    return header;
}


struct _allocBlock{
	aHeader_t _head;
	struct _allocBlock *_prev;	//pointer to the previous block (NULL IF ROOT)
	struct _allocBlock *_next;	//pointer to the next block
	void * _addr;				//place within the chunk of allocated memory
};

/*
Block Struct
|          ALLOC BLOCK                       |         ALLOC BLOCK          |
|HEADER|_prev|_next| DATA                    |HEADER|_prev|_next|DATA       |




*/


typedef struct _allocBlock  aBlock_t;

size_t int_allocBlock_offset(){
	return (sizeof(aHeader_t) + (sizeof(aBlock_t*) * 2));
}

size_t int_allocBlock_fullSize(aBlock_t * block){
	size_t out;
	out = int_allocBlock_offset() + block->_head._size;
	return out;
}

void int_allocBlock_placeAtAddress(aBlock_t * block , void * address){
	memcpy(address, block, int_allocBlock_fullSize(block));
}

void int_allocBlock_initBlockAtAddress(size_t size, aBlock_t * prev, aBlock_t * next);

void int_allocBlock_setPrevious(aBlock_t * self, aBlock_t * prev){
	self->_prev = prev;
}
void int_allocBlock_setNext(aBlock_t * self, aBlock_t * next){
	self->_next = next;
}


aBlock_t * int_alloc_getBlock(void * address){
	return  (aBlock_t *)(address - int_allocBlock_offset());
}

aHeader_t * int_alloc_getHeader(aBlock_t * self){
	return &self->_head;
}
aBlock_t * int_alloc_getPrev(aBlock_t * self){
	return self->_prev;
}
aBlock_t * int_alloc_getNext(aBlock_t * self){
	return self->_next;
}

void * int_alloc_getData(aBlock_t * self){
	return self->_addr;
}

struct _allocBin{
	uint16_t _binID;
	uint16_t _sPad;
	uint32_t _elementMaxSize;
	uint32_t _elementCount;
	uint32_t _binSize;
	void * _baseAddr;
};

/*
Bin Struct:
| _binID| _sPad|  _elementMaxSize| _elementCount| _binSize|
| 2bytes|2bytes|        4bytes   |    4bytes    |  4bytes |
|				_baseAddr                                 |
|            _elementMaxSize bytes                        |





*/

typedef struct _allocBin aBin_t;


void int_allocBin_placeBlock(aBin_t * bin , aBlock_t * block){
	uint32_t offset = bin->_elementMaxSize * bin->_elementCount;
	void * blockAddress = bin->_baseAddr + offset;
	int_allocBlock_placeAtAddress(block, blockAddress);
	bin->_elementCount++;
}


/*
  1,048,576 bytes Per Bin?
  16,777,216 total ? Is this worth it?

*/

struct _allocator{
	aBin_t _binData[16];
	void * _baseAddress;
};

/*

Allocator:
|_binData[0] |_binData[1] |_binData[2] |_binData[3] |
|_binData[4] |_binData[5] |_binData[6] |_binData[7] |
|_binData[8] |_binData[9] |_binData[10]|_binData[11]|
|_binData[12]|_binData[13]|_binData[14]|_binData[15]|
|_baseAddress      _binData[0]._baseAddr            |
|                  _binData[1]._baseAddr            |
|                  _binData[2]._baseAddr            |
|                  _binData[3]._baseAddr            |
|                  _binData[4]._baseAddr            |
|                  _binData[5]._baseAddr            |
|                  _binData[6]._baseAddr            |
|                  _binData[7]._baseAddr            |
|                  _binData[8]._baseAddr            |
|                  _binData[9]._baseAddr            |
|                  _binData[10]._baseAddr           |
|                  _binData[11]._baseAddr           |
|                  _binData[12]._baseAddr           |
|                  _binData[13]._baseAddr           |
|                  _binData[14]._baseAddr           |
|                  _binData[15]._baseAddr           |
*/



// size = sizeof(aBin_t) + 16 * MB?

typedef struct _allocator allocator_t;


static allocator_t * _currAllocator = NULL;

void int_allocator_initBins(allocator_t * self) {
    uint32_t baseBinSize = MB; // Set your base bin size (16MB in this case)
    self->_baseAddress = NULL; // Ensure _baseAddress is properly initialized

    for (uint8_t i = 0; i < 16; i++) {
        self->_binData[i]._binID = i;
        self->_binData[i]._elementMaxSize = 1 << (i + 2);
        self->_binData[i]._elementCount = 0;
        self->_binData[i]._binSize = baseBinSize;

        // Calculate the base address for this bin
        if (i == 0) {
            self->_binData[i]._baseAddr = self->_baseAddress;
        } else {
            self->_binData[i]._baseAddr = self->_binData[i - 1]._baseAddr + baseBinSize;
        }
    }
}

size_t static_allocator_size(size_t binSize){
	return  (size_t)(sizeof(aBin_t) + (binSize * 16));
}


allocator_t *int_create_allocator(size_t binSize) {
    if (binSize == 0) {
        binSize = MB; // Set a default bin size (e.g., 1 MB)
    }

    // Allocate memory for the allocator and bins
    allocator_t *out = (allocator_t *)mmap(NULL, static_allocator_size(binSize),
                                           PROT_READ | PROT_WRITE,
                                           MAP_SHARED | MAP_ANONYMOUS,
                                           -1, 0);

    if (out == MAP_FAILED) {
        return NULL; // Allocation failed
    }

    // Initialize the base address (set to the beginning of the allocated memory)
    out->_baseAddress = (void *)(out + 1); // The "+1" ensures _baseAddress follows the allocator struct

    // Initialize the bins
    int_allocator_initBins(out);

    return out;
}

uint8_t int_determine_bin(size_t size) {
    size_t currAlignedSize;

    for (uint8_t i = 0; i < 16; i++) {
        currAlignedSize = 1 << (i + 2);
        if (size <= currAlignedSize) {
            return i;
        }
    }

    return ALLOC_BINFAIL; // Allocation size is too large for this allocator
}


void int_allocBlock_initBlockAtAddress(size_t size, aBlock_t *prev, aBlock_t *next) {
    size_t block_size = sizeof(aBlock_t) + size;
    aBlock_t *block = (aBlock_t *)mmap(NULL, block_size,
                                       PROT_READ | PROT_WRITE,
                                       MAP_SHARED | MAP_ANONYMOUS,
                                       -1, 0);

    if (block != MAP_FAILED) {
        block->_prev = prev;
        block->_next = next;
        block->_addr = (void *)(block + 1); // The data immediately follows the block struct
        block->_head = int_alloc_createHeader(size, 0, 0); // Initialize the header

        // Additional initialization of the block if needed

        // Place the block at the specified address
        int_allocBlock_placeAtAddress(block, block);
    }
}


////////////////////////////////////////////////////////
//    PUBLIC API
////////////////////////////////////////////////////////


uint8_t allocator_init(allocator_t * allocator){

	allocator = int_create_allocator(MB);

	if(allocator == NULL){
		return ALLOC_NOMEM;
	}

	_currAllocator = allocator;
	return ALLOC_SUCCESS;
}
uint8_t static_allocator_init(){

	allocator_init(_currAllocator);
	if(_currAllocator == NULL){
		return ALLOC_NOMEM;
	}

	return ALLOC_SUCCESS;
}

void allocator_destroy(allocator_t *self) {
    munmap(self->_baseAddress, static_allocator_size(self->_binData[0]._binSize));
}

void static_set_allocator(allocator_t * alloc){
	if(_currAllocator != NULL){
		allocator_destroy(_currAllocator);
	}
	_currAllocator = alloc;
}




//allocation from the specified allocator.
void *allocator_malloc(allocator_t *allocator, size_t size) {
    if (allocator == NULL || size == 0) {
        return NULL; // Invalid input, nothing to allocate
    }

    uint8_t binID = int_determine_bin(size);

    if (binID == ALLOC_BINFAIL) {
        return NULL; // Allocation size too large for this allocator
    }

    // Find the last block in the selected bin
    aBlock_t *lastBlock = NULL;
    size_t binSize = allocator->_binData[binID]._binSize;

    // Search for a block in the bin's linked list
    for (aBlock_t *block = int_alloc_getBlock(allocator->_binData[binID]._baseAddr);
         block != NULL;
         block = int_alloc_getNext(block)) {
        lastBlock = block;
    }

    // Calculate the offset for the new block
    size_t offset = 0;
    if (lastBlock != NULL) {
        offset = lastBlock->_head._offset + lastBlock->_head._size;
    }

    // Create a new block
    aBlock_t newBlock;
    int_allocBlock_initBlockAtAddress(size, lastBlock, NULL);

    // Place the header at the start of the new block
    aHeader_t *header = int_alloc_getHeader(&newBlock);
    *header = int_alloc_createHeader(size, binID, offset);

    // Set last block's next to the new block
    if (lastBlock != NULL) {
        int_allocBlock_setNext(lastBlock, &newBlock);
    }

    // Set the new block's prev to the last block
    newBlock._prev = lastBlock;

    // Return the address of the data in the new block
    return int_alloc_getData(&newBlock);
}


void * allocator_calloc(allocator_t * allocator, size_t size){
	return allocator_malloc(allocator,size);
}
void * allocator_realloc(allocator_t * allocator, void * address, size_t size) {
    if (allocator == NULL || size == 0 || address == NULL) {
        return NULL; // Invalid input, nothing to reallocate
    }

    // Find the block associated with the given address
    aBlock_t *block = int_alloc_getBlock(address);

    if (block->_head._HEADMAGIC != HEAD || block->_head._FOOTMAGIC != FOOT) {
        return NULL; // Invalid block, something went wrong
    }

    if (block->_head._flags == FLAG_FREED) {
        return NULL; // Attempting to reallocate a freed block
    }

    // Calculate the new bin ID for the given size
    uint8_t newBinID = int_determine_bin(size);

    if (newBinID == ALLOC_BINFAIL) {
        return NULL; // New size is too large for this allocator
    }

    // If the new size can fit in the same bin and there's enough room, reuse the block
    if (newBinID == block->_head._binID && size <= block->_head._size) {
        return address; // Reuse the same block
    }

    // Allocate a new block for the requested size
    void *newAddress = allocator_malloc(allocator, size);

    if (newAddress == NULL) {
        return NULL; // Allocation failed, return the original block
    }

    // Copy data from the old block to the new block
    size_t copySize = (size < block->_head._size) ? size : block->_head._size;
    memcpy(newAddress, address, copySize);

    // Free the old block
    allocator_free(allocator, address);

    return newAddress;
}
//freeing memory within the allocator
void static_allocator_free(void * address) {
    if (_currAllocator == NULL || address == NULL) {
        return; // Invalid input, nothing to free
    }

    allocator_free(_currAllocator, address);
}


void allocator_free(allocator_t * self, void * address) {
    if (self == NULL || address == NULL) {
        return; // Invalid input, nothing to do
    }

    aBlock_t *block = int_alloc_getBlock(address);

    if (block->_head._HEADMAGIC != HEAD || block->_head._FOOTMAGIC != FOOT) {
        return; // Invalid block, something went wrong
    }

    if (block->_head._flags == FLAG_FREED) {
        return; // Double-free, already freed
    }

    // Mark the block as freed
    block->_head._flags = FLAG_FREED;

    // Coalesce free blocks if the previous block is also free
    aBlock_t *prevBlock = int_alloc_getPrev(block);
    if (prevBlock != NULL && prevBlock->_head._flags == FLAG_FREED) {
        // Combine current block with the previous block
        size_t newSize = int_allocBlock_fullSize(block) + int_allocBlock_fullSize(prevBlock);
        block->_head._size = newSize;
        int_allocBlock_setPrevious(block, prevBlock->_prev);

        // Check if the previous block is the root block
        if (self->_baseAddress == prevBlock) {
            self->_baseAddress = block; // Update root if needed
        }
    }

    // Coalesce free blocks if the next block is also free
    aBlock_t *nextBlock = int_alloc_getNext(block);
    if (nextBlock != NULL && nextBlock->_head._flags == FLAG_FREED) {
        // Combine current block with the next block
        size_t newSize = int_allocBlock_fullSize(block) + int_allocBlock_fullSize(nextBlock);
        block->_head._size = newSize;
        int_allocBlock_setNext(block, nextBlock->_next);

        // Check if the next block is the root block
        if (self->_baseAddress == nextBlock) {
            self->_baseAddress = block; // Update root if needed
        }
    }
}

//allocation from the current alllocator that is initialized
void * static_allocator_malloc(size_t size){
	return allocator_malloc(_currAllocator,size);
}

void * static_allocator_calloc(size_t size){
  void * out = static_allocator_malloc(size);
	memset(out,0,size);
  return out;
}

void * static_allocator_realloc(void * address, size_t size){
	return allocator_realloc(_currAllocator,address,size);
}
