#include "../../include/collections/vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


const char * NULL_VECTOR_BLOCK;
void * VECNULL = &NULL_VECTOR_BLOCK;

struct vector{

  size_t _elementSize;
  size_t _capacity;
  size_t _count;
  uint8_t _eflag;
  void * _data;
};

size_t vector_getSize(vector_t * out){
  return out->_elementSize;
}
size_t vector_getCapacity(vector_t * out){
  return out->_capacity;
}
size_t vector_getCount(vector_t * out){
  return out->_count;
}
uint8_t vector_eFlag(vector_t * out){
  return out->_eflag;
}
void * vector_getElementAt(vector_t * out, size_t index){
  if(out->_count < index){
    return VECNULL;
  }
  uint32_t offset = out->_elementSize * index;
	void * iter = out->_data +offset;
	return iter;
}

void * vector_getRawData(vector_t * out){
  return out->_data;
}

vector_t * vector_malloc(size_t size, size_t capacity){
  vector_t * out;
  out = malloc(sizeof(vector_t));
  out->_elementSize = size;
  out->_capacity =  capacity;
  out->_count = 0;
  out->_eflag = VEC_FLAG_EMPTY ;
  //allocate memory for the full vector
  out->_data = malloc(size * capacity);
  //Dont Do this??
  /**
  //allocate memory for each of the indicies
  for(size_t i = 0 ; i < capacity ; i++){
    out->_data[i] = malloc(size);
  }
  **/
  return out;
}
//what?
vector_t * vector_init(vector_t * out, size_t size, size_t capacity){
  out = malloc(sizeof(vector_t));
  out->_elementSize = size;
  out->_capacity =  capacity;
  out->_count = 0;
  out->_eflag = VEC_FLAG_EMPTY ;
  out->_data = malloc(size * capacity);
//Dont Do this??
/**
  for(size_t i = 0 ; i < capacity ; i++){
    out->_data[i] = malloc(size);
  }
**/
  return out;
}

vector_t * vector_copy(const vector_t * copy){
  vector_t * out = vector_malloc(copy->_elementSize ,copy->_capacity);
  out->_count = copy->_count;
  out->_eflag = copy->_eflag;
  memcpy(out->_data,copy->_data, (out->_elementSize * out->_capacity));
  return out;
}
vector_t * vector_move(vector_t * move){
  vector_t * out = vector_malloc(move->_elementSize,move->_capacity);
  out->_count = move->_count;
  out->_eflag = move->_eflag;
  memmove(out->_data,move->_data, (out->_elementSize * out->_capacity));
  move->_elementSize = 0;
  move->_capacity =  0;
  move->_count = 0;
  move->_eflag = VEC_FLAG_EMPTY ;
  free_vector(move);
  return out;
}


void free_vector(vector_t * out){
  free(out->_data);
  free(out);
}

void vector_empty(vector_t * out){
	memset(out->_data,0, out->_elementSize * out->_count);
	out->_count = 0;
}



void vector_push(vector_t *out, void * element){
  uint32_t offset = out->_elementSize * out->_count;
  void * addr = out->_data + offset;
  //check if its not filled
  if(out->_count <= out->_capacity){
    memcpy(addr,element, out->_elementSize);
    out->_count++;
    //out->_data[out->_count++]=element;

    if(out->_count == out->_capacity){
      out->_eflag = VEC_FLAG_FULL;
      }
    }

  //clear flags if needed
  if(out->_eflag == VEC_FLAG_EMPTY){
    out->_eflag = VEC_FLAG_NONE;
  }

}
void * vector_pop(vector_t * out){

  //check if its empty?
  if(out->_count == 0){
    out->_eflag = VEC_FLAG_EMPTY;
    return VECNULL;
  }
  uint32_t offset = out->_elementSize * out->_count;

  //get the return variable
  void * ret = out->_data + offset;
  out->_count--;
  //void * ret = out->_data[out->_count--];
  //clear flags if needed
  if(out->_eflag == VEC_FLAG_FULL){
    out->_eflag = VEC_FLAG_NONE;
  }
  return ret;
}


//Safe way of resizing
void vector_resize(vector_t * out){
  size_t newCap = out->_capacity *2;
  out->_capacity = newCap;
  out->_data = realloc(out->_data, newCap * out->_elementSize);
}

//Unsafe way of resizing
void vector_exactResize(vector_t * out, size_t newCap){
  if(out->_capacity < newCap){
    out->_capacity = newCap;
    out->_data = realloc(out->_data, newCap * out->_elementSize);
  }else
    out->_eflag = VEC_FLAG_INVALID_RESIZE;
}
