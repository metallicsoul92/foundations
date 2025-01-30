#include "../../include/core/allocator.h"
#include <sys/mman.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

// =====================
// Constants & Macros
// =====================
#define POOL_SIZE (16 * 1024 * 1024) // 16MB per pool
#define MIN_BLOCK_SIZE 16
#define MAX_BINS 20 // Covers sizes from 16 bytes to 524,288 bytes
#define MAGIC_HEAD 0xAF
#define MAGIC_FOOT 0xFA
#define ALIGNMENT 16

// =====================
// Structures
// =====================
typedef struct BlockHeader {
    uint8_t magic_head;
    size_t size;
    struct BlockHeader* next_free;
    uint8_t magic_foot;
    #ifdef DEBUG
    const char* alloc_file;
    int alloc_line;
    #endif
} BlockHeader;

typedef struct MemoryPool {
    void* base;
    size_t size;
    BlockHeader* free_list;
    unsigned allocation_count;
} MemoryPool;

struct _allocator {
    MemoryPool bins[MAX_BINS];
    pthread_mutex_t mutex;
    uint8_t initialized;
};

// =====================
// Global State
// =====================
static struct _allocator global_allocator = {0};
static pthread_once_t alloc_init_once = PTHREAD_ONCE_INIT;

// =====================
// Helper Functions
// =====================
static size_t align_size(size_t size) {
    return (size + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
}

static int get_bin_index(size_t size) {
    if(size < MIN_BLOCK_SIZE) size = MIN_BLOCK_SIZE;
    int index = 0;
    size_t aligned = MIN_BLOCK_SIZE;
    while(aligned < size && index < MAX_BINS-1) {
        aligned <<= 1;
        index++;
    }
    return index;
}

static void init_global_allocator(void) {
    pthread_mutex_init(&global_allocator.mutex, NULL);
    memset(global_allocator.bins, 0, sizeof(global_allocator.bins));
    global_allocator.initialized = 1;
}

static BlockHeader* get_header(void* ptr) {
    return (BlockHeader*)((char*)ptr - sizeof(BlockHeader));
}

static void initialize_pool(MemoryPool* pool) {
    if(pool->base) return;

    pool->base = mmap(NULL, POOL_SIZE,
                    PROT_READ|PROT_WRITE,
                    MAP_PRIVATE|MAP_ANONYMOUS,
                    -1, 0);
    if(pool->base == MAP_FAILED) return;

    BlockHeader* initial_block = (BlockHeader*)pool->base;
    initial_block->magic_head = MAGIC_HEAD;
    initial_block->size = POOL_SIZE - sizeof(BlockHeader);
    initial_block->next_free = NULL;
    initial_block->magic_foot = MAGIC_FOOT;

    pool->free_list = initial_block;
    pool->size = POOL_SIZE;
    pool->allocation_count = 0;
}

static void* pool_alloc(MemoryPool* pool, size_t size) {
    BlockHeader **current = &pool->free_list;
    while(*current) {
        BlockHeader* block = *current;

        // Verify magic numbers
        if(block->magic_head != MAGIC_HEAD || block->magic_foot != MAGIC_FOOT) {
            return NULL;
        }

        if(block->size >= size) {
            // Split block if there's enough space left
            if(block->size > size + sizeof(BlockHeader) + MIN_BLOCK_SIZE) {
                BlockHeader* new_block = (BlockHeader*)((char*)block + sizeof(BlockHeader) + size);
                new_block->magic_head = MAGIC_HEAD;
                new_block->size = block->size - size - sizeof(BlockHeader);
                new_block->next_free = block->next_free;
                new_block->magic_foot = MAGIC_FOT;

                *current = new_block;
            } else {
                // Use whole block
                *current = block->next_free;
            }

            block->size = size;
            pool->allocation_count++;
            return (void*)(block + 1);
        }
        current = &(*current)->next_free;
    }
    return NULL;
}

static void pool_free(MemoryPool* pool, BlockHeader* block) {
    // Coalesce with adjacent blocks
    BlockHeader* current = pool->free_list;
    BlockHeader* prev = NULL;

    while(current) {
        if((char*)current + sizeof(BlockHeader) + current->size == (char*)block) {
            // Merge with next block
            current->size += sizeof(BlockHeader) + block->size;
            block = current;
        } else if((char*)block + sizeof(BlockHeader) + block->size == (char*)current) {
            // Merge with previous block
            block->size += sizeof(BlockHeader) + current->size;
            block->next_free = current->next_free;
            if(prev) prev->next_free = block;
            else pool->free_list = block;
            current = block;
        }

        prev = current;
        current = current->next_free;
    }

    // Add to free list
    block->next_free = pool->free_list;
    pool->free_list = block;
    pool->allocation_count--;
}

// =====================
// Public API Implementation
// =====================
uint8_t allocator_init(allocator_t* allocator) {
    if(!allocator) return ALLOC_NOMEM;

    pthread_mutex_lock(&allocator->mutex);
    if(!allocator->initialized) {
        pthread_mutex_init(&allocator->mutex, NULL);
        memset(allocator->bins, 0, sizeof(allocator->bins));
        allocator->initialized = 1;
    }
    pthread_mutex_unlock(&allocator->mutex);
    return ALLOC_SUCCESS;
}

uint8_t static_allocator_init() {
    pthread_once(&alloc_init_once, init_global_allocator);
    return global_allocator.initialized ? ALLOC_SUCCESS : ALLOC_NOMEM;
}

void allocator_destroy(allocator_t* self) {
    if(!self) return;

    pthread_mutex_lock(&self->mutex);
    for(int i = 0; i < MAX_BINS; i++) {
        if(self->bins[i].base) {
            munmap(self->bins[i].base, self->bins[i].size);
            self->bins[i].base = NULL;
            self->bins[i].free_list = NULL;
        }
    }
    pthread_mutex_unlock(&self->mutex);
    pthread_mutex_destroy(&self->mutex);
}

void static_set_allocator(allocator_t* alloc) {
    // Not implemented in this version - would require atomic swap
}

void* allocator_malloc(allocator_t* allocator, size_t size) {
    if(!allocator || size == 0) return NULL;

    pthread_mutex_lock(&allocator->mutex);

    const size_t aligned_size = align_size(size);
    const int bin_index = get_bin_index(aligned_size);

    if(bin_index >= MAX_BINS) {
        pthread_mutex_unlock(&allocator->mutex);
        return NULL;
    }

    MemoryPool* pool = &allocator->bins[bin_index];
    if(!pool->base) initialize_pool(pool);

    void* result = pool_alloc(pool, aligned_size);
    pthread_mutex_unlock(&allocator->mutex);
    return result;
}

void* allocator_calloc(allocator_t* allocator, size_t size) {
    void* ptr = allocator_malloc(allocator, size);
    if(ptr) memset(ptr, 0, size);
    return ptr;
}

void* allocator_realloc(allocator_t* allocator, void* address, size_t size) {
    if(!address) return allocator_malloc(allocator, size);
    if(size == 0) {
        allocator_free(allocator, address);
        return NULL;
    }

    BlockHeader* old_header = get_header(address);
    const size_t old_size = old_header->size;
    const size_t new_size = align_size(size);

    if(new_size <= old_size) return address; // Can use existing block

    void* new_ptr = allocator_malloc(allocator, new_size);
    if(new_ptr) {
        memcpy(new_ptr, address, old_size);
        allocator_free(allocator, address);
    }
    return new_ptr;
}

void allocator_free(allocator_t* allocator, void* address) {
    if(!allocator || !address) return;

    pthread_mutex_lock(&allocator->mutex);
    BlockHeader* header = get_header(address);

    if(header->magic_head != MAGIC_HEAD || header->magic_foot != MAGIC_FOOT) {
        pthread_mutex_unlock(&allocator->mutex);
        return;
    }

    const int bin_index = get_bin_index(header->size);
    if(bin_index >= MAX_BINS) {
        pthread_mutex_unlock(&allocator->mutex);
        return;
    }

    MemoryPool* pool = &allocator->bins[bin_index];
    pool_free(pool, header);
    pthread_mutex_unlock(&allocator->mutex);
}

// =====================
// Static Allocator Functions
// =====================
void* static_allocator_malloc(size_t size) {
    return allocator_malloc(&global_allocator, size);
}

void* static_allocator_calloc(size_t size) {
    return allocator_calloc(&global_allocator, size);
}

void* static_allocator_realloc(void* address, size_t size) {
    return allocator_realloc(&global_allocator, address, size);
}

void static_allocator_free(void* address) {
    allocator_free(&global_allocator, address);
}
