#include "../../include/core/estring.h"

#include <stdlib.h>
#include <string.h>

struct estring{
  uint32_t _length;
  char * _string;
};

//construction/destruction
estring_t * malloc_estring(const char * data){
  estring_t * out = malloc(sizeof(estring_t));
  out->_length = strlen(data);
  out->_string = malloc(sizeof(char) * out->_length);
  strcpy(out->_string,data);
  return out;
}

estring_t * copy_estring(const estring_t * data){
  estring_t * out = malloc(sizeof(estring_t));
  out->_length = data->_length;
  out->_string = malloc(sizeof(char) * out->_length);
  strcpy(out->_string, data->_string);
  return out;
}

estring_t * move_estring(estring_t * data){
  estring_t * out = malloc(sizeof(estring_t));
  out->_length = data->_length;
  out->_string = malloc(sizeof(char) * out->_length);
  strcpy(out->_string, data->_string);
  data->_length = 0;
  free_estring(data);
  return out;
}

void free_estring(estring_t * self){
  free(self->_string);
  free(self);
}
//getters
uint32_t estring_length(estring_t *self){
  return self->_length;
}
char * estring_str(estring_t*self){
  return self->_string;
}
 char estring_getAt(estring_t *self, uint32_t index){
    if(index >= self->_length){
      return '\0';
    }
    return self->_string[index];
}
bool estring_isEqual(estring_t * a, estring_t * b){
  //first check if they are the same length
  if(a->_length != b->_length){
    return false;
  }

  for(uint32_t i = 0; i < a->_length; i++ ){
    if(a->_string[i] != b->_string[i]){
      return false;
    }
  }
  return true;
}


//setters
void estring_append(estring_t * self, const char * extra){
  uint32_t added = strlen(extra);
  self->_length += added;
  self->_string = realloc(self->_string,self->_length);
  strcat(self->_string,extra);
}
void estring_setAt(estring_t * self, const char letter, uint32_t index){
  if(self->_length > index){
    self->_string[index] = letter;
  }
}

estring_t *estring_substr(estring_t *str, uint32_t start, uint32_t end) {
  // Check if the requested substring is within valid bounds.
  if (start >= end || end > str->_length) {
    return NULL;
  }

  uint32_t size = end - start;
  char *_intdata = malloc(sizeof(char) * (size + 1));  // +1 for the null-terminator
  if (_intdata == NULL) {
    // Handle memory allocation failure, if needed.
    return NULL;
  }

  memcpy(_intdata, str->_string + start, size);
  _intdata[size] = '\0';  // Null-terminate the new string.

  estring_t *out = malloc(sizeof(estring_t));
  out->_length = size;
  out->_string = _intdata;
  return out;
}
