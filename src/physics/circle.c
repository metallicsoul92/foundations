#include "../../include/physics/circle.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>



// Ensure error state is clear
#define CIRCLE_MALLOC_CLEAR_ERROR() \
    do { circle_clear_error(); } while (0)



// Helper macros for endianness conversion
#define U16_FROM_LE(b) ((uint16_t)(b)[0] | ((uint16_t)(b)[1] << 8))
#define U32_FROM_LE(b) ((uint32_t)(b)[0] | ((uint32_t)(b)[1] << 8) | \
                       ((uint32_t)(b)[2] << 16) | ((uint32_t)(b)[3] << 24))
#define U64_FROM_LE(b) ((uint64_t)(b)[0] | ((uint64_t)(b)[1] << 8) | \
                       ((uint64_t)(b)[2] << 16) | ((uint64_t)(b)[3] << 24) | \
                       ((uint64_t)(b)[4] << 32) | ((uint64_t)(b)[5] << 40) | \
                       ((uint64_t)(b)[6] << 48) | ((uint64_t)(b)[7] << 56))


 // Helper macros for endianness conversion (if needed for future big-endian versions)
#define U16_TO_NATIVE(val) (val)
#define U32_TO_NATIVE(val) (val)
#define U64_TO_NATIVE(val) (val)

// Helper functions for writing little-endian values
static inline void write_le16(uint8_t *dst, uint16_t value) {
    dst[0] = (uint8_t)(value);
    dst[1] = (uint8_t)(value >> 8);
}

static inline void write_le32(uint8_t *dst, uint32_t value) {
    dst[0] = (uint8_t)(value);
    dst[1] = (uint8_t)(value >> 8);
    dst[2] = (uint8_t)(value >> 16);
    dst[3] = (uint8_t)(value >> 24);
}

static inline void write_le64(uint8_t *dst, uint64_t value) {
    dst[0] = (uint8_t)(value);
    dst[1] = (uint8_t)(value >> 8);
    dst[2] = (uint8_t)(value >> 16);
    dst[3] = (uint8_t)(value >> 24);
    dst[4] = (uint8_t)(value >> 32);
    dst[5] = (uint8_t)(value >> 40);
    dst[6] = (uint8_t)(value >> 48);
    dst[7] = (uint8_t)(value >> 56);
}

// Helper functions for reading little-endian values
static inline uint16_t read_le16(const uint8_t *src) {
    return (uint16_t)src[0] | ((uint16_t)src[1] << 8);
}

static inline uint32_t read_le32(const uint8_t *src) {
    return (uint32_t)src[0] | ((uint32_t)src[1] << 8) |
           ((uint32_t)src[2] << 16) | ((uint32_t)src[3] << 24);
}

static inline uint64_t read_le64(const uint8_t *src) {
    return (uint64_t)src[0] | ((uint64_t)src[1] << 8) |
           ((uint64_t)src[2] << 16) | ((uint64_t)src[3] << 24) |
           ((uint64_t)src[4] << 32) | ((uint64_t)src[5] << 40) |
           ((uint64_t)src[6] << 48) | ((uint64_t)src[7] << 56);
}



/*
  Error Handling
*/
// Common error codes for all circle types
typedef enum {
    CIRCLE_SUCCESS = 0,
    CIRCLE_ERROR_MALLOC_FAILED,
    CIRCLE_ERROR_OVERFLOW,
    CIRCLE_ERROR_INVALID_DIMENSIONS,
    CIRCLE_ERROR_UNKNOWN
} circle_error_t;

// Global error state for all circle types
static circle_error_t circle_last_error = CIRCLE_SUCCESS;
static const char* circle_error_string = NULL;

// Error strings
static const char* CIRCLE_ERROR_STRINGS[] = {
    "Success",
    "Memory allocation failed",
    "Box would cause coordinate overflow",
    "Invalid dimensions provided",
    "Unknown error"
};

// Function to get the last error code
circle_error_t circle_get_error(void) {
    return circle_last_error;
}

// Function to get the last error string
const char* circle_get_error_string(void) {
    if (circle_error_string != NULL) {
        return circle_error_string;
    }
    return CIRCLE_ERROR_STRINGS[circle_last_error];
}

// Function to set a custom error string
void circle_set_error_string(const char* custom_error) {
    circle_error_string = custom_error;
}

// Function to clear error state
void circle_clear_error(void) {
    circle_last_error = CIRCLE_SUCCESS;
    circle_error_string = NULL;
}

/*
  Structure Definitions
*/

struct _circleu8_t{
  uint8_t _posX;
  uint8_t _posY;
  uint8_t _radius;
};
struct _circlei8_t{
  int8_t _posX;
  int8_t _posY;
  int8_t _radius;
};
struct _circleu16_t{
  uint16_t _posX;
  uint16_t _posY;
  uint16_t _radius;
};
struct _circlei16_t{
  int16_t _posX;
  int16_t _posY;
  int16_t _radius;
};
struct _circleu32_t{
  uint32_t _posX;
  uint32_t _posY;
  uint32_t _radius;
};
struct _circlei32_t{
  int32_t _posX;
  int32_t _posY;
  int32_t _radius;
};
struct _circleu64_t{
  uint64_t _posX;
  uint64_t _posY;
  uint64_t _radius;
};
struct _circlei64_t{
  int64_t _posX;
  int64_t _posY;
  int64_t _radius;
};
struct _circlef_t{
  float _posX;
  float _posY;
  float _radius;
};
struct _circled_t{
  double _posX;
  double _posY;
  double _radius;
};
struct _circleld_t{
  long double _posX;
  long double _posY;
  long double _radius;
};

circleu8_t * circleu8_malloc( uint8_t x,uint8_t y,uint8_t radius){
  circle_clear_error();
  if ((UINT8_MAX - x) < radius || (UINT8_MAX - y) < radius) {
      circle_last_error = CIRCLE_ERROR_OVERFLOW;
      return NULL;
  }
  circleu8_t * ret = malloc(sizeof(circleu8_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = x;
  ret->_posY = y;
  ret->_radius = radius;

  return ret;
}
circlei8_t * circlei8_malloc( int8_t x,int8_t y,int8_t radius){
  circle_clear_error();
  if ((radius > 0 && x > INT8_MAX - radius) ||
      (radius < 0 && x < INT8_MIN - radius) ||
      (radius > 0 && y > INT8_MAX - radius) ||
      (radius < 0 && y < INT8_MIN - radius)) {
      circle_last_error = CIRCLE_ERROR_OVERFLOW;
      return NULL;
  }
  circlei8_t * ret = malloc(sizeof(circlei8_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = x;
  ret->_posY = y;
  ret->_radius = radius;

  return ret;
}
circleu16_t * circleu16_malloc( uint16_t x,uint16_t y,uint16_t radius){
  circle_clear_error();
  if ((UINT16_MAX - x) < radius || (UINT16_MAX - y) < radius) {
      circle_last_error = CIRCLE_ERROR_OVERFLOW;
      return NULL;
  }
  circleu16_t * ret = malloc(sizeof(circleu16_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = x;
  ret->_posY = y;
  ret->_radius = radius;

  return ret;
}
circlei16_t * circlei16_malloc( int16_t x,int16_t y,int16_t radius){
  circle_clear_error();
  if ((radius > 0 && x > INT16_MAX - radius) ||
      (radius < 0 && x < INT16_MIN - radius) ||
      (radius > 0 && y > INT16_MAX - radius) ||
      (radius < 0 && y < INT16_MIN - radius)) {
      circle_last_error = CIRCLE_ERROR_OVERFLOW;
      return NULL;
  }
  circlei16_t * ret = malloc(sizeof(circlei16_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
          return NULL;
      }
      ret->_posX = x;
      ret->_posY = y;
      ret->_radius = radius;

      return ret;
  }
circleu32_t * circleu32_malloc( uint32_t x,uint32_t y,uint32_t radius){
      circle_clear_error();
      if ((radius > 0 && x > UINT32_MAX - radius) ||
          (radius < 0 && x < UINT32_MIN - radius) ||
          (radius > 0 && y > UINT32_MAX - radius) ||
          (radius < 0 && y <U INT32_MIN - radius)) {
          circle_last_error = CIRCLE_ERROR_OVERFLOW;
          return NULL;
      }
      circleu32_t * ret = malloc(sizeof(circleu32_t));
      if(ret == NULL){
        circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
        return NULL;
      }
      ret->_posX = x;
      ret->_posY = y;
      ret->_radius = radius;

      return ret;
    }
circlei32_t * circlei32_malloc( int32_t x,int32_t y,int32_t radius){
  circle_clear_error();
  if ((radius > 0 && x > INT32_MAX - radius) ||
      (radius < 0 && x < INT32_MIN - radius) ||
      (radius > 0 && y > INT32_MAX - radius) ||
      (radius < 0 && y < INT32_MIN - radius)) {
      circle_last_error = CIRCLE_ERROR_OVERFLOW;
      return NULL;
  }
  circlei32_t * ret = malloc(sizeof(circlei32_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = x;
  ret->_posY = y;
  ret->_radius = radius;

  return ret;
}
circleu64_t * circleu64_malloc( uint64_t x,uin64t_t y,uint64_t radius){
  circle_clear_error();
  if ((UINT64_MAX - x) < radius || (UINT64_MAX - y) < radius) {
      circle_last_error = CIRCLE_ERROR_OVERFLOW;
      return NULL;
  }
  circleu64_t * ret = malloc(sizeof(circleu64_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = x;
  ret->_posY = y;
  ret->_radius = radius;

  return ret;
}
circlei64_t * circlei64_malloc( int64_t x,in64t_t y,int64_t radius){
  circle_clear_error();
  if ((radius > 0 && x > INT64_MAX - radius) ||
      (radius < 0 && x < INT64_MIN - radius) ||
      (radius > 0 && y > INT64_MAX - radius) ||
      (radius < 0 && y < INT64_MIN - radius)) {
      circle_last_error = CIRCLE_ERROR_OVERFLOW;
      return NULL;
  }
  circlei64_t * ret = malloc(sizeof(circlei64_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = x;
  ret->_posY = y;
  ret->_radius = radius;

  return ret;
}
circlef_t * circlef_malloc( float x,float y,float radius){
  circle_clear_error();
  if (isnan(x) || isnan(y) || isnan(radius) ||
      isinf(x) || isinf(y) || isinf(radius) ) {
      circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
      return NULL;
  }
  circlef_t * ret = malloc(sizeof(circlef_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = x;
  ret->_posY = y;
  ret->_radius = radius;

  return ret;
}
circled_t * circled_malloc( double x,double y,double radius){
  circle_clear_error();
  if (isnan(x) || isnan(y) || isnan(radius) ||
      isinf(x) || isinf(y) || isinf(radius) ) {
      circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
      return NULL;
  }
  circled_t * ret = malloc(sizeof(circled_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = x;
  ret->_posY = y;
  ret->_radius = radius;

  return ret;
}
circleld_t * circleld_malloc( long double x,long double y,long double radius){
  circle_clear_error();
  if (isnan(x) || isnan(y) || isnan(radius) ||
      isinf(x) || isinf(y) || isinf(radius) ) {
      circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
      return NULL;
  }
  circleld_t * ret = malloc(sizeof(circleld_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = x;
  ret->_posY = y;
  ret->_radius = radius;

  return ret;
}

circleu8_t * circleu8_copy(const circleu8_t * copy){
  circle_clear_error();
  circleu8_t * ret = malloc(sizeof(circleu8_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = copy->_posX;
  ret->_posY = copy->_posY;
  ret->_radius = copy->_radius;

  return ret;
}
circlei8_t * circlei8_copy(const circlei8_t * copy){
  circle_clear_error();

  circlei8_t * ret = malloc(sizeof(circlei8_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = copy->_posX;
  ret->_posY = copy->_posY;
  ret->_radius = copy->_radius;

  return ret;
}
circleu16_t * circleu16_copy(const circleu16_t * copy){
  circle_clear_error();

  circleu16_t * ret = malloc(sizeof(circleu16_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = copy->_posX;
  ret->_posY = copy->_posY;
  ret->_radius = copy->_radius;

  return ret;
}
circlei16_t * circlei16_copy(const circlei16_t * copy){
  circle_clear_error();

  circlei16_t * ret = malloc(sizeof(circlei16_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
          return NULL;
      }
      ret->_posX = copy->_posX;
      ret->_posY = copy->_posY;
      ret->_radius = copy->_radius;

      return ret;
  }
circleu32_t * circleu32_copy(const circleu32_t * copy){
      circle_clear_error();

      circleu32_t * ret = malloc(sizeof(circleu32_t));
      if(ret == NULL){
        circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
        return NULL;
      }
      ret->_posX = copy->_posX;
      ret->_posY = copy->_posY;
      ret->_radius = copy->_radius;

      return ret;
    }
circlei32_t * circlei32_copy(const circlei32_t * copy){
  circle_clear_error();

  circlei32_t * ret = malloc(sizeof(circlei32_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = copy->_posX;
  ret->_posY = copy->_posY;
  ret->_radius = copy->_radius;

  return ret;
}
circleu64_t * circleu64_copy(const circleu64_t * copy){
  circle_clear_error();

  circleu64_t * ret = malloc(sizeof(circleu64_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = copy->_posX;
  ret->_posY = copy->_posY;
  ret->_radius = copy->_radius;

  return ret;
}
circlei64_t * circlei64_copy(const circlei64_t * copy){
  circle_clear_error();

  circlei64_t * ret = malloc(sizeof(circlei64_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = copy->_posX;
  ret->_posY = copy->_posY;
  ret->_radius = copy->_radius;

  return ret;
}
circlef_t * circlef_copy(const circlef_t * copy){
  circle_clear_error();

  circlef_t * ret = malloc(sizeof(circlef_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = copy->_posX;
  ret->_posY = copy->_posY;
  ret->_radius = copy->_radius;

  return ret;
}
circled_t * circled_copy(const circled_t * copy){
  circle_clear_error();

  circled_t * ret = malloc(sizeof(circled_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = copy->_posX;
  ret->_posY = copy->_posY;
  ret->_radius = copy->_radius;

  return ret;
}
circleld_t * circleld_copy(const circleld_t * copy){
  circle_clear_error();

  circleld_t * ret = malloc(sizeof(circleld_t));
  if(ret == NULL){
    circle_last_error = CIRCLE_ERROR_MALLOC_FAILED;
    return NULL;
  }
  ret->_posX = copy->_posX;
  ret->_posY = copy->_posY;
  ret->_radius = copy->_radius;

  return ret;
}

//Memmove
circleu8_t * circleu8_memmove(circleu8_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circleu8_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}
circlei8_t * circlei8_memmove(circlei8_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circlei8_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}
circleu16_t * circleu16_memmove(circleu16_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circleu16_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}
circlei16_t * circlei16_memmove(circlei16_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circlei16_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}
circleu32_t * circleu32_memmove(circleu32_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circleu32_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}
circlei32_t * circlei32_memmove(circlei32_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circlei32_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}
circleu64_t * circleu64_memmove(circleu64_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circleu64_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}
circlei64_t * circlei64_memmove(circlei64_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circlei64_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}
circlef_t * circlef_memmove(circlef_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circlef_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}
circled_t * circled_memmove(circled_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circled_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}
circleld_t * circleld_memmove(circleld_t ** move){
    circle_clear_error();

    if (move == NULL || *move == NULL) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    circleld_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}

void circleu8_free(circleu8_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}
void circlei8_free(circlei8_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}
void circleu16_free(circleu16_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}
void circlei16_free(circlei16_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}
void circleu32_free(circleu32_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}
void circlei32_free(circlei32_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}
void circleu64_free(circleu64_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}
void circlei64_free(circlei64_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}
void circlef_free(circlef_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}
void circled_free(circled_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}
void circleld_free(circleld_t * obj){
    if (obj != NULL) {
        free(obj);
    }
}

uint8_t circleu8_getX(const circleu8_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}
int8_t circlei8_getX(const circlei8_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}
uint16_t circleu16_getX(const circleu16_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}
int16_t circlei16_getX(const circlei16_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}
uint32_t circleu32_getX(const circleu32_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}
int32_t circlei32_getX(const circlei32_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}
uint64_t circleu64_getX(const circleu64_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}
int64_t circlei64_getX(const circlei64_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}
float circlef_getX(const circlef_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}
double circled_getX(const circled_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}
long double circleld_getX(const circleld_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posX;
}

uint8_t circleu8_getY(const circleu8_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}


int8_t circlei8_getY(const circlei8_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}


uint16_t circleu16_getY(const circleu16_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}


int16_t circlei16_getY(const circlei16_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}


uint32_t circleu32_getY(const circleu32_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}


int32_t circlei32_getY(const circlei32_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}


uint64_t circleu64_getY(const circleu64_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}


int64_t circlei64_getY(const circlei64_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}


float circlef_getY(const circlef_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}


double circled_getY(const circled_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}


long double circleld_getY(const circleld_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posY;
}

uint8_t circleu8_getRadius(const circleu8_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

int8_t circlei8_getRadius(const circlei8_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

uint16_t circleu16_getRadius(const circleu16_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

int16_t circlei16_getRadius(const circlei16_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

uint32_t circleu32_getRadius(const circleu32_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

int32_t circlei32_getRadius(const circlei32_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

uint64_t circleu64_getRadius(const circleu64_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

int64_t circlei64_getRadius(const circlei64_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

float circlef_getRadius(const circlef_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

double circled_getRadius(const circled_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

long double circleld_getRadius(const circleld_t * obj){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_radius;
}

//setX()
void circleu8_setX(circleu8_t * obj, uint8_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}

void circlei8_setX(circlei8_t * obj, int8_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}
void circleu16_setX(circleu16_t * obj, uint16_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}
void circlei16_setX(circlei16_t * obj, int16_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}
void circleu32_setX(circleu32_t * obj, uint32_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}
void circlei32_setX(circlei32_t * obj, int32_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}
void circleu64_setX(circleu64_t * obj, uint64_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}
void circlei64_setX(circlei64_t * obj, int64_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}
void circlef_setX(circlef_t * obj, float x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}
void circled_setX(circled_t * obj, double x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}
void circleld_setX(circleld_t * obj, long double x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX = x;
}

//setY()
void circleu8_setY(circleu8_t * obj, uint8_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}
void circlei8_setY(circlei8_t * obj, int8_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}
void circleu16_setY(circleu16_t * obj, uint16_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}
void circlei16_setY(circlei16_t * obj, int16_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}
void circleu32_setY(circleu32_t * obj, uint32_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}
void circlei32_setY(circlei32_t * obj, int32_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}
void circleu64_setY(circleu64_t * obj, uint64_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}
void circlei64_setY(circlei64_t * obj, int64_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}
void circlef_setY(circlef_t * obj, float y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}
void circled_setY(circled_t * obj, double y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}
void circleld_setY(circleld_t * obj, long double y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY = y;
}

//setRadius()
void circleu8_setRadius(circleu8_t * obj, uint8_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}
void circlei8_setRadius(circlei8_t * obj, int8_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}
void circleu16_setRadius(circleu16_t * obj, uint16_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}
void circlei16_setRadius(circlei16_t * obj, int16_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}
void circleu32_setRadius(circleu32_t * obj, uint32_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}
void circlei32_setRadius(circlei32_t * obj, int32_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}
void circleu64_setRadius(circleu64_t * obj, uint64_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}
void circlei64_setRadius(circlei64_t * obj, int64_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}
void circlef_setRadius(circlef_t * obj, float radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}
void circled_setRadius(circled_t * obj, double radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}
void circleld_setRadius(circleld_t * obj, long double radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius = radius;
}

//moveX()
void circleu8_moveX(circleu8_t * obj, uint8_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}

void circlei8_moveX(circlei8_t * obj, int8_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}

void circleu16_moveX(circleu16_t * obj, uint16_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}

void circlei16_moveX(circlei16_t * obj, int16_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}

void circleu32_moveX(circleu32_t * obj, uint32_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}
void circlei32_moveX(circlei32_t * obj, int32_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}

void circleu64_moveX(circleu64_t * obj, uint64_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}

void circlei64_moveX(circlei64_t * obj, int64_t x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}

void circlef_moveX(circlef_t * obj, float x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}

void circled_moveX(circled_t * obj, double x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}

void circleld_moveX(circleld_t * obj, long double x){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
}

//moveY()
void circleu8_moveY(circleu8_t * obj, uint8_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

void circlei8_moveY(circlei8_t * obj, int8_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

void circleu16_moveY(circleu16_t * obj, uint16_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

void circlei16_moveY(circlei16_t * obj, int16_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

void circleu32_moveY(circleu32_t * obj, uint32_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

void circlei32_moveY(circlei32_t * obj, int32_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

void circleu64_moveY(circleu64_t * obj, uint64_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

void circlei64_moveY(circlei64_t * obj, int64_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

void circlef_moveY(circlef_t * obj, float y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

void circled_moveY(circled_t * obj, double y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

void circleld_moveY(circleld_t * obj, long double y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posY += y;
}

//move()
void circleu8_move(circleu8_t * obj, uint8_t x, uint8_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}

void circlei8_move(circlei8_t * obj, int8_t x, int8_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}
void circleu16_move(circleu16_t * obj, uint16_t x, uint16_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}
void circlei16_move(circlei16_t * obj, int16_t x, int16_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}
void circleu32_move(circleu32_t * obj, uint32_t x, uint32_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}
void circlei32_move(circlei32_t * obj, int32_t x, int32_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}
void circleu64_move(circleu64_t * obj, uint64_t x, uint64_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}
void circlei64_move(circlei64_t * obj, int64_t x, int64_t y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}
void circlef_move(circlef_t * obj, float x, float y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}
void circled_move(circled_t * obj, double x, double y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}
void circleld_move(circleld_t * obj, long double x, long double y){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_posX += x;
     obj->_posY += y;
}

//grow()
void circleu8_grow(circleu8_t * obj, uint8_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}
void circlei8_grow(circlei8_t * obj, int8_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}
void circleu16_grow(circleu16_t * obj, uint16_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}
void circlei16_grow(circlei16_t * obj, int16_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}
void circleu32_grow(circleu32_t * obj, uint32_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}
void circlei32_grow(circlei32_t * obj, int32_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}
void circleu64_grow(circleu64_t * obj, uint64_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}
void circlei64_grow(circlei64_t * obj, int64_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}
void circlef_grow(circlef_t * obj, float radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}
void circled_grow(circled_t * obj, double radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}
void circleld_grow(circleld_t * obj, long double radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius += radius;
}

//shrink()
void circleu8_shrink(circleu8_t * obj, uint8_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}
void circlei8_shrink(circlei8_t * obj, int8_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}
void circleu16_shrink(circleu16_t * obj, uint16_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}
void circlei16_shrink(circlei16_t * obj, int16_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}
void circleu32_shrink(circleu32_t * obj, uint32_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}
void circlei32_shrink(circlei32_t * obj, int32_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}
void circleu64_shrink(circleu64_t * obj, uint64_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}
void circlei64_shrink(circlei64_t * obj, int64_t radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}
void circlef_shrink(circlef_t * obj, float radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}
void circled_shrink(circled_t * obj, double radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}
void circleld_shrink(circleld_t * obj, long double radius){
    if (!obj) {
        circle_last_error = CIRCLE_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
     obj->_radius -= radius;
}

bool circleu8_collides(const circleu8_t *obj, const circleu8_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu8_collides");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)other->_posX;
    int64_t dy = (int64_t)obj->_posY - (int64_t)other->_posY;
    int64_t r_sum = (int64_t)obj->_radius + (int64_t)other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}
bool circlei8_collides(const circlei8_t *obj, const circlei8_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei8_collides");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)other->_posX;
    int64_t dy = (int64_t)obj->_posY - (int64_t)other->_posY;
    int64_t r_sum = (int64_t)obj->_radius + (int64_t)other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}
bool circleu16_collides(const circleu16_t *obj, const circleu16_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu16_collides");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)other->_posX;
    int64_t dy = (int64_t)obj->_posY - (int64_t)other->_posY;
    int64_t r_sum = (int64_t)obj->_radius + (int64_t)other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}
bool circlei16_collides(const circlei16_t *obj, const circlei16_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei16_collides");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)other->_posX;
    int64_t dy = (int64_t)obj->_posY - (int64_t)other->_posY;
    int64_t r_sum = (int64_t)obj->_radius + (int64_t)other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}
bool circleu32_collides(const circleu32_t *obj, const circleu32_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu32_collides");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)other->_posX;
    int64_t dy = (int64_t)obj->_posY - (int64_t)other->_posY;
    int64_t r_sum = (int64_t)obj->_radius + (int64_t)other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}
bool circlei32_collides(const circlei32_t *obj, const circlei32_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei32_collides");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)other->_posX;
    int64_t dy = (int64_t)obj->_posY - (int64_t)other->_posY;
    int64_t r_sum = (int64_t)obj->_radius + (int64_t)other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}
bool circleu64_collides(const circleu64_t *obj, const circleu64_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu64_collides");
        return false;
    }

    uint64_t dx = (obj->_posX > other->_posX) ?
                 (obj->_posX - other->_posX) :
                 (other->_posX - obj->_posX);
    uint64_t dy = (obj->_posY > other->_posY) ?
                 (obj->_posY - other->_posY) :
                 (other->_posY - obj->_posY);
    uint64_t r_sum = obj->_radius + other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}
bool circlei64_collides(const circlei64_t *obj, const circlei64_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei64_collides");
        return false;
    }

    int64_t dx_val = obj->_posX - other->_posX;
    int64_t dy_val = obj->_posY - other->_posY;
    uint64_t dx = (dx_val < 0) ? (uint64_t)(-dx_val) : (uint64_t)dx_val;
    uint64_t dy = (dy_val < 0) ? (uint64_t)(-dy_val) : (uint64_t)dy_val;
    uint64_t r_sum = (uint64_t)obj->_radius + (uint64_t)other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}
bool circlef_collides(const circlef_t *obj, const circlef_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlef_collides");
        return false;
    }

    float dx = obj->_posX - other->_posX;
    float dy = obj->_posY - other->_posY;
    float r_sum = obj->_radius + other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}
bool circled_collides(const circled_t *obj, const circled_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circled_collides");
        return false;
    }

    double dx = obj->_posX - other->_posX;
    double dy = obj->_posY - other->_posY;
    double r_sum = obj->_radius + other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}
bool circleld_collides(const circleld_t *obj, const circleld_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleld_collides");
        return false;
    }

    long double dx = obj->_posX - other->_posX;
    long double dy = obj->_posY - other->_posY;
    long double r_sum = obj->_radius + other->_radius;
    return (dx * dx + dy * dy) <= (r_sum * r_sum);
}

bool circleu8_contains_point(const circleu8_t *obj, uint8_t x, uint8_t y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu8_contains_point");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)x;
    int64_t dy = (int64_t)obj->_posY - (int64_t)y;
    int64_t r_squared = (int64_t)obj->_radius * (int64_t)obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}
bool circlei8_contains_point(const circlei8_t *obj, int8_t x, int8_t y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei8_contains_point");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)x;
    int64_t dy = (int64_t)obj->_posY - (int64_t)y;
    int64_t r_squared = (int64_t)obj->_radius * (int64_t)obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}
bool circleu16_contains_point(const circleu16_t *obj, uint16_t x, uint16_t y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu16_contains_point");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)x;
    int64_t dy = (int64_t)obj->_posY - (int64_t)y;
    int64_t r_squared = (int64_t)obj->_radius * (int64_t)obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}
bool circlei16_contains_point(const circlei16_t *obj, int16_t x, int16_t y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei16_contains_point");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)x;
    int64_t dy = (int64_t)obj->_posY - (int64_t)y;
    int64_t r_squared = (int64_t)obj->_radius * (int64_t)obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}
bool circleu32_contains_point(const circleu32_t *obj, uint32_t x, uint32_t y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu32_contains_point");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)x;
    int64_t dy = (int64_t)obj->_posY - (int64_t)y;
    int64_t r_squared = (int64_t)obj->_radius * (int64_t)obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}
bool circlei32_contains_point(const circlei32_t *obj, int32_t x, int32_t y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei32_contains_point");
        return false;
    }

    int64_t dx = (int64_t)obj->_posX - (int64_t)x;
    int64_t dy = (int64_t)obj->_posY - (int64_t)y;
    int64_t r_squared = (int64_t)obj->_radius * (int64_t)obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}
bool circleu64_contains_point(const circleu64_t *obj, uint64_t x, uint64_t y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu64_contains_point");
        return false;
    }

    uint64_t dx = (obj->_posX > x) ? (obj->_posX - x) : (x - obj->_posX);
    uint64_t dy = (obj->_posY > y) ? (obj->_posY - y) : (y - obj->_posY);
    uint64_t r_squared = obj->_radius * obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}
bool circlei64_contains_point(const circlei64_t *obj, int64_t x, int64_t y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei64_contains_point");
        return false;
    }

    int64_t dx_val = obj->_posX - x;
    int64_t dy_val = obj->_posY - y;
    uint64_t dx = (dx_val < 0) ? (uint64_t)(-dx_val) : (uint64_t)dx_val;
    uint64_t dy = (dy_val < 0) ? (uint64_t)(-dy_val) : (uint64_t)dy_val;
    uint64_t r_squared = (uint64_t)obj->_radius * (uint64_t)obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}
bool circlef_contains_point(const circlef_t *obj, float x, float y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlef_contains_point");
        return false;
    }

    float dx = obj->_posX - x;
    float dy = obj->_posY - y;
    float r_squared = obj->_radius * obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}
bool circled_contains_point(const circled_t *obj, double x, double y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circled_contains_point");
        return false;
    }

    double dx = obj->_posX - x;
    double dy = obj->_posY - y;
    double r_squared = obj->_radius * obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}
bool circleld_contains_point(const circleld_t *obj, long double x, long double y) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleld_contains_point");
        return false;
    }

    long double dx = obj->_posX - x;
    long double dy = obj->_posY - y;
    long double r_squared = obj->_radius * obj->_radius;
    return (dx * dx + dy * dy) <= r_squared;
}

bool circleu8_equals(const circleu8_t *obj, const circleu8_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu8_equals");
        return false;
    }

    return (obj->_posX == other->_posX) &&
           (obj->_posY == other->_posY) &&
           (obj->_radius == other->_radius);
}
bool circlei8_equals(const circlei8_t *obj, const circlei8_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei8_equals");
        return false;
    }

    return (obj->_posX == other->_posX) &&
           (obj->_posY == other->_posY) &&
           (obj->_radius == other->_radius);
}
bool circleu16_equals(const circleu16_t *obj, const circleu16_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu16_equals");
        return false;
    }

    return (obj->_posX == other->_posX) &&
           (obj->_posY == other->_posY) &&
           (obj->_radius == other->_radius);
}
bool circlei16_equals(const circlei16_t *obj, const circlei16_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei16_equals");
        return false;
    }

    return (obj->_posX == other->_posX) &&
           (obj->_posY == other->_posY) &&
           (obj->_radius == other->_radius);
}
bool circleu32_equals(const circleu32_t *obj, const circleu32_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu32_equals");
        return false;
    }

    return (obj->_posX == other->_posX) &&
           (obj->_posY == other->_posY) &&
           (obj->_radius == other->_radius);
}
bool circlei32_equals(const circlei32_t *obj, const circlei32_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei32_equals");
        return false;
    }

    return (obj->_posX == other->_posX) &&
           (obj->_posY == other->_posY) &&
           (obj->_radius == other->_radius);
}
bool circleu64_equals(const circleu64_t *obj, const circleu64_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu64_equals");
        return false;
    }

    return (obj->_posX == other->_posX) &&
           (obj->_posY == other->_posY) &&
           (obj->_radius == other->_radius);
}
bool circlei64_equals(const circlei64_t *obj, const circlei64_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei64_equals");
        return false;
    }

    return (obj->_posX == other->_posX) &&
           (obj->_posY == other->_posY) &&
           (obj->_radius == other->_radius);
}
bool circlef_equals(const circlef_t *obj, const circlef_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlef_equals");
        return false;
    }

    const float tolerance = 1e-6f;
    return (fabsf(obj->_posX - other->_posX) <= tolerance) &&
           (fabsf(obj->_posY - other->_posY) <= tolerance) &&
           (fabsf(obj->_radius - other->_radius) <= tolerance);
}
bool circled_equals(const circled_t *obj, const circled_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circled_equals");
        return false;
    }

    const double tolerance = 1e-12;
    return (fabs(obj->_posX - other->_posX) <= tolerance) &&
           (fabs(obj->_posY - other->_posY) <= tolerance) &&
           (fabs(obj->_radius - other->_radius) <= tolerance);
}
bool circleld_equals(const circleld_t *obj, const circleld_t *other) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || other == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleld_equals");
        return false;
    }

    const long double tolerance = 1e-12L;
    return (fabsl(obj->_posX - other->_posX) <= tolerance) &&
           (fabsl(obj->_posY - other->_posY) <= tolerance) &&
           (fabsl(obj->_radius - other->_radius) <= tolerance);
}

void circleu8_print(const circleu8_t *obj) {
    if (obj == NULL) {
        printf("NULL circleu8_t pointer\n");
        return;
    }
    printf("Circleu8(x=%u, y=%u, radius=%u)\n",
           obj->_posX, obj->_posY, obj->_radius);
}
void circlei8_print(const circlei8_t *obj) {
    if (obj == NULL) {
        printf("NULL circlei8_t pointer\n");
        return;
    }
    printf("Circlei8(x=%d, y=%d, radius=%d)\n",
           obj->_posX, obj->_posY, obj->_radius);
}
void circleu16_print(const circleu16_t *obj) {
    if (obj == NULL) {
        printf("NULL circleu16_t pointer\n");
        return;
    }
    printf("Circleu16(x=%u, y=%u, radius=%u)\n",
           obj->_posX, obj->_posY, obj->_radius);
}
void circlei16_print(const circlei16_t *obj) {
    if (obj == NULL) {
        printf("NULL circlei16_t pointer\n");
        return;
    }
    printf("Circlei16(x=%d, y=%d, radius=%d)\n",
           obj->_posX, obj->_posY, obj->_radius);
}
void circleu32_print(const circleu32_t *obj) {
    if (obj == NULL) {
        printf("NULL circleu32_t pointer\n");
        return;
    }
    printf("Circleu32(x=%u, y=%u, radius=%u)\n",
           obj->_posX, obj->_posY, obj->_radius);
}
void circlei32_print(const circlei32_t *obj) {
    if (obj == NULL) {
        printf("NULL circlei32_t pointer\n");
        return;
    }
    printf("Circlei32(x=%d, y=%d, radius=%d)\n",
           obj->_posX, obj->_posY, obj->_radius);
}
void circleu64_print(const circleu64_t *obj) {
    if (obj == NULL) {
        printf("NULL circleu64_t pointer\n");
        return;
    }
    printf("Circleu64(x=%llu, y=%llu, radius=%llu)\n",
           (unsigned long long)obj->_posX,
           (unsigned long long)obj->_posY,
           (unsigned long long)obj->_radius);
}
void circlei64_print(const circlei64_t *obj) {
    if (obj == NULL) {
        printf("NULL circlei64_t pointer\n");
        return;
    }
    printf("Circlei64(x=%lld, y=%lld, radius=%lld)\n",
           (long long)obj->_posX,
           (long long)obj->_posY,
           (long long)obj->_radius);
}
void circlef_print(const circlef_t *obj) {
    if (obj == NULL) {
        printf("NULL circlef_t pointer\n");
        return;
    }
    printf("Circlef(x=%.6f, y=%.6f, radius=%.6f)\n",
           obj->_posX, obj->_posY, obj->_radius);
}
void circled_print(const circled_t *obj) {
    if (obj == NULL) {
        printf("NULL circled_t pointer\n");
        return;
    }
    printf("Circled(x=%.12f, y=%.12f, radius=%.12f)\n",
           obj->_posX, obj->_posY, obj->_radius);
}
void circleld_print(const circleld_t *obj) {
    if (obj == NULL) {
        printf("NULL circleld_t pointer\n");
        return;
    }
    printf("Circleld(x=%.12Lf, y=%.12Lf, radius=%.12Lf)\n",
           obj->_posX, obj->_posY, obj->_radius);
}

// getSize meta-function
size_t circleu8_size(void){
  return sizeof(circleu8_t);
}
size_t circlei8_size(void){
  return sizeof(circlei8_t);
}
size_t circleu16_size(void){
  return sizeof(circleu16_t);
}
size_t circlei16_size(void){
  return sizeof(circlei16_t);
}
size_t circleu32_size(void){
  return sizeof(circleu32_t);
}
size_t circlei32_size(void){
  return sizeof(circlei32_t);
}
size_t circleu64_size(void){
  return sizeof(circleu64_t);
}
size_t circlei64_size(void){
  return sizeof(circlei64_t);
}
size_t circlef_size(void){
  return sizeof(circlef_t);
}
size_t circled_size(void){
  return sizeof(circled_t);
}
size_t circleld_size(void){
  return sizeof(circleld_t);
}


void circleu8_toArray(uint8_t *output, const circleu8_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu8_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}
void circlei8_toArray(int8_t *output, const circlei8_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei8_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}
void circleu16_toArray(uint16_t *output, const circleu16_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu16_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}
void circlei16_toArray(int16_t *output, const circlei16_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei16_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}
void circleu32_toArray(uint32_t *output, const circleu32_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu32_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}
void circlei32_toArray(int32_t *output, const circlei32_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei32_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}
void circleu64_toArray(uint64_t *output, const circleu64_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu64_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}
void circlei64_toArray(int64_t *output, const circlei64_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei64_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}
void circlef_toArray(float *output, const circlef_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlef_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}
void circled_toArray(double *output, const circled_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circled_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}
void circleld_toArray(long double *output, const circleld_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleld_toArray");
        return;
    }

    output[0] = src->_posX;
    output[1] = src->_posY;
    output[2] = src->_radius;
}

void circleu8_fromArray(circleu8_t *output, const uint8_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu8_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}
void circlei8_fromArray(circlei8_t *output, const int8_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei8_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}
void circleu16_fromArray(circleu16_t *output, const uint16_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu16_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}
void circlei16_fromArray(circlei16_t *output, const int16_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei16_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}
void circleu32_fromArray(circleu32_t *output, const uint32_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu32_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}
void circlei32_fromArray(circlei32_t *output, const int32_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei32_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}
void circleu64_fromArray(circleu64_t *output, const uint64_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu64_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}
void circlei64_fromArray(circlei64_t *output, const int64_t *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei64_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}
void circlef_fromArray(circlef_t *output, const float *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlef_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}
void circled_fromArray(circled_t *output, const double *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circled_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}
void circleld_fromArray(circleld_t *output, const long double *src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (output == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleld_fromArray");
        return;
    }

    output->_posX = src[0];
    output->_posY = src[1];
    output->_radius = src[2];
}


void circleu8_toBytes(const circleu8_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu8_toBytes");
        return;
    }

    dst[0] = obj->_posX;
    dst[1] = obj->_posY;
    dst[2] = obj->_radius;
}
void circlei8_toBytes(const circlei8_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei8_toBytes");
        return;
    }

    dst[0] = (uint8_t)obj->_posX;
    dst[1] = (uint8_t)obj->_posY;
    dst[2] = (uint8_t)obj->_radius;
}
void circleu16_toBytes(const circleu16_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu16_toBytes");
        return;
    }

    memcpy(dst, &obj->_posX, sizeof(uint16_t));
    memcpy(dst + sizeof(uint16_t), &obj->_posY, sizeof(uint16_t));
    memcpy(dst + 2 * sizeof(uint16_t), &obj->_radius, sizeof(uint16_t));
}
void circlei16_toBytes(const circlei16_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei16_toBytes");
        return;
    }

    memcpy(dst, &obj->_posX, sizeof(int16_t));
    memcpy(dst + sizeof(int16_t), &obj->_posY, sizeof(int16_t));
    memcpy(dst + 2 * sizeof(int16_t), &obj->_radius, sizeof(int16_t));
}
void circleu32_toBytes(const circleu32_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu32_toBytes");
        return;
    }

    memcpy(dst, &obj->_posX, sizeof(uint32_t));
    memcpy(dst + sizeof(uint32_t), &obj->_posY, sizeof(uint32_t));
    memcpy(dst + 2 * sizeof(uint32_t), &obj->_radius, sizeof(uint32_t));
}
void circlei32_toBytes(const circlei32_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei32_toBytes");
        return;
    }

    memcpy(dst, &obj->_posX, sizeof(int32_t));
    memcpy(dst + sizeof(int32_t), &obj->_posY, sizeof(int32_t));
    memcpy(dst + 2 * sizeof(int32_t), &obj->_radius, sizeof(int32_t));
}
void circleu64_toBytes(const circleu64_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu64_toBytes");
        return;
    }

    memcpy(dst, &obj->_posX, sizeof(uint64_t));
    memcpy(dst + sizeof(uint64_t), &obj->_posY, sizeof(uint64_t));
    memcpy(dst + 2 * sizeof(uint64_t), &obj->_radius, sizeof(uint64_t));
}
void circlei64_toBytes(const circlei64_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei64_toBytes");
        return;
    }

    memcpy(dst, &obj->_posX, sizeof(int64_t));
    memcpy(dst + sizeof(int64_t), &obj->_posY, sizeof(int64_t));
    memcpy(dst + 2 * sizeof(int64_t), &obj->_radius, sizeof(int64_t));
}
void circlef_toBytes(const circlef_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlef_toBytes");
        return;
    }

    memcpy(dst, &obj->_posX, sizeof(float));
    memcpy(dst + sizeof(float), &obj->_posY, sizeof(float));
    memcpy(dst + 2 * sizeof(float), &obj->_radius, sizeof(float));
}
void circled_toBytes(const circled_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circled_toBytes");
        return;
    }

    memcpy(dst, &obj->_posX, sizeof(double));
    memcpy(dst + sizeof(double), &obj->_posY, sizeof(double));
    memcpy(dst + 2 * sizeof(double), &obj->_radius, sizeof(double));
}
void circleld_toBytes(const circleld_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleld_toBytes");
        return;
    }

    memcpy(dst, &obj->_posX, sizeof(long double));
    memcpy(dst + sizeof(long double), &obj->_posY, sizeof(long double));
    memcpy(dst + 2 * sizeof(long double), &obj->_radius, sizeof(long double));
}

void circleu8_fromBytes(circleu8_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu8_fromBytes");
        return;
    }

    obj->_posX = src[0];
    obj->_posY = src[1];
    obj->_radius = src[2];
}
void circlei8_fromBytes(circlei8_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei8_fromBytes");
        return;
    }

    obj->_posX = (int8_t)src[0];
    obj->_posY = (int8_t)src[1];
    obj->_radius = (int8_t)src[2];
}
void circleu16_fromBytes(circleu16_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu16_fromBytes");
        return;
    }

    memcpy(&obj->_posX, src, sizeof(uint16_t));
    memcpy(&obj->_posY, src + sizeof(uint16_t), sizeof(uint16_t));
    memcpy(&obj->_radius, src + 2 * sizeof(uint16_t), sizeof(uint16_t));
}
void circlei16_fromBytes(circlei16_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei16_fromBytes");
        return;
    }

    memcpy(&obj->_posX, src, sizeof(int16_t));
    memcpy(&obj->_posY, src + sizeof(int16_t), sizeof(int16_t));
    memcpy(&obj->_radius, src + 2 * sizeof(int16_t), sizeof(int16_t));
}
void circleu32_fromBytes(circleu32_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu32_fromBytes");
        return;
    }

    memcpy(&obj->_posX, src, sizeof(uint32_t));
    memcpy(&obj->_posY, src + sizeof(uint32_t), sizeof(uint32_t));
    memcpy(&obj->_radius, src + 2 * sizeof(uint32_t), sizeof(uint32_t));
}
void circlei32_fromBytes(circlei32_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei32_fromBytes");
        return;
    }

    memcpy(&obj->_posX, src, sizeof(int32_t));
    memcpy(&obj->_posY, src + sizeof(int32_t), sizeof(int32_t));
    memcpy(&obj->_radius, src + 2 * sizeof(int32_t), sizeof(int32_t));
}
void circleu64_fromBytes(circleu64_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu64_fromBytes");
        return;
    }

    memcpy(&obj->_posX, src, sizeof(uint64_t));
    memcpy(&obj->_posY, src + sizeof(uint64_t), sizeof(uint64_t));
    memcpy(&obj->_radius, src + 2 * sizeof(uint64_t), sizeof(uint64_t));
}
void circlei64_fromBytes(circlei64_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei64_fromBytes");
        return;
    }

    memcpy(&obj->_posX, src, sizeof(int64_t));
    memcpy(&obj->_posY, src + sizeof(int64_t), sizeof(int64_t));
    memcpy(&obj->_radius, src + 2 * sizeof(int64_t), sizeof(int64_t));
}
void circlef_fromBytes(circlef_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlef_fromBytes");
        return;
    }

    memcpy(&obj->_posX, src, sizeof(float));
    memcpy(&obj->_posY, src + sizeof(float), sizeof(float));
    memcpy(&obj->_radius, src + 2 * sizeof(float), sizeof(float));
}
void circled_fromBytes(circled_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circled_fromBytes");
        return;
    }

    memcpy(&obj->_posX, src, sizeof(double));
    memcpy(&obj->_posY, src + sizeof(double), sizeof(double));
    memcpy(&obj->_radius, src + 2 * sizeof(double), sizeof(double));
}
void circleld_fromBytes(circleld_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleld_fromBytes");
        return;
    }

    memcpy(&obj->_posX, src, sizeof(long double));
    memcpy(&obj->_posY, src + sizeof(long double), sizeof(long double));
    memcpy(&obj->_radius, src + 2 * sizeof(long double), sizeof(long double));
}

void circleu8_toBytesLE(const circleu8_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu8_toBytesLE");
        return;
    }

    dst[0] = obj->_posX;
    dst[1] = obj->_posY;
    dst[2] = obj->_radius;
}
void circlei8_toBytesLE(const circlei8_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei8_toBytesLE");
        return;
    }

    dst[0] = (uint8_t)obj->_posX;
    dst[1] = (uint8_t)obj->_posY;
    dst[2] = (uint8_t)obj->_radius;
}
void circleu16_toBytesLE(const circleu16_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu16_toBytesLE");
        return;
    }

    write_le16(dst, obj->_posX);
    write_le16(dst + 2, obj->_posY);
    write_le16(dst + 4, obj->_radius);
}
void circlei16_toBytesLE(const circlei16_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei16_toBytesLE");
        return;
    }

    write_le16(dst, (uint16_t)obj->_posX);
    write_le16(dst + 2, (uint16_t)obj->_posY);
    write_le16(dst + 4, (uint16_t)obj->_radius);
}
void circleu32_toBytesLE(const circleu32_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu32_toBytesLE");
        return;
    }

    write_le32(dst, obj->_posX);
    write_le32(dst + 4, obj->_posY);
    write_le32(dst + 8, obj->_radius);
}
void circlei32_toBytesLE(const circlei32_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei32_toBytesLE");
        return;
    }

    write_le32(dst, (uint32_t)obj->_posX);
    write_le32(dst + 4, (uint32_t)obj->_posY);
    write_le32(dst + 8, (uint32_t)obj->_radius);
}
void circleu64_toBytesLE(const circleu64_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu64_toBytesLE");
        return;
    }

    write_le64(dst, obj->_posX);
    write_le64(dst + 8, obj->_posY);
    write_le64(dst + 16, obj->_radius);
}
void circlei64_toBytesLE(const circlei64_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei64_toBytesLE");
        return;
    }

    write_le64(dst, (uint64_t)obj->_posX);
    write_le64(dst + 8, (uint64_t)obj->_posY);
    write_le64(dst + 16, (uint64_t)obj->_radius);
}
void circlef_toBytesLE(const circlef_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlef_toBytesLE");
        return;
    }

    uint32_t x_bits, y_bits, radius_bits;
    memcpy(&x_bits, &obj->_posX, sizeof(float));
    memcpy(&y_bits, &obj->_posY, sizeof(float));
    memcpy(&radius_bits, &obj->_radius, sizeof(float));

    write_le32(dst, x_bits);
    write_le32(dst + 4, y_bits);
    write_le32(dst + 8, radius_bits);
}
void circled_toBytesLE(const circled_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circled_toBytesLE");
        return;
    }

    uint64_t x_bits, y_bits, radius_bits;
    memcpy(&x_bits, &obj->_posX, sizeof(double));
    memcpy(&y_bits, &obj->_posY, sizeof(double));
    memcpy(&radius_bits, &obj->_radius, sizeof(double));

    write_le64(dst, x_bits);
    write_le64(dst + 8, y_bits);
    write_le64(dst + 16, radius_bits);
}
void circleld_toBytesLE(const circleld_t* obj, uint8_t* dst) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || dst == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleld_toBytesLE");
        return;
    }

    memcpy(dst, &obj->_posX, sizeof(long double));
    memcpy(dst + sizeof(long double), &obj->_posY, sizeof(long double));
    memcpy(dst + 2 * sizeof(long double), &obj->_radius, sizeof(long double));
}

void circleu8_fromBytesLE(circleu8_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu8_fromBytesLE");
        return;
    }

    obj->_posX = src[0];
    obj->_posY = src[1];
    obj->_radius = src[2];
}
void circlei8_fromBytesLE(circlei8_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei8_fromBytesLE");
        return;
    }

    obj->_posX = (int8_t)src[0];
    obj->_posY = (int8_t)src[1];
    obj->_radius = (int8_t)src[2];
}
void circleu16_fromBytesLE(circleu16_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu16_fromBytesLE");
        return;
    }

    obj->_posX = read_le16(src);
    obj->_posY = read_le16(src + 2);
    obj->_radius = read_le16(src + 4);
}
void circlei16_fromBytesLE(circlei16_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei16_fromBytesLE");
        return;
    }

    obj->_posX = (int16_t)read_le16(src);
    obj->_posY = (int16_t)read_le16(src + 2);
    obj->_radius = (int16_t)read_le16(src + 4);
}
void circleu32_fromBytesLE(circleu32_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu32_fromBytesLE");
        return;
    }

    obj->_posX = read_le32(src);
    obj->_posY = read_le32(src + 4);
    obj->_radius = read_le32(src + 8);
}
void circlei32_fromBytesLE(circlei32_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei32_fromBytesLE");
        return;
    }

    obj->_posX = (int32_t)read_le32(src);
    obj->_posY = (int32_t)read_le32(src + 4);
    obj->_radius = (int32_t)read_le32(src + 8);
}
void circleu64_fromBytesLE(circleu64_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleu64_fromBytesLE");
        return;
    }

    obj->_posX = read_le64(src);
    obj->_posY = read_le64(src + 8);
    obj->_radius = read_le64(src + 16);
}
void circlei64_fromBytesLE(circlei64_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlei64_fromBytesLE");
        return;
    }

    obj->_posX = (int64_t)read_le64(src);
    obj->_posY = (int64_t)read_le64(src + 8);
    obj->_radius = (int64_t)read_le64(src + 16);
}
void circlef_fromBytesLE(circlef_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circlef_fromBytesLE");
        return;
    }

    uint32_t x_bits = read_le32(src);
    uint32_t y_bits = read_le32(src + 4);
    uint32_t radius_bits = read_le32(src + 8);

    memcpy(&obj->_posX, &x_bits, sizeof(float));
    memcpy(&obj->_posY, &y_bits, sizeof(float));
    memcpy(&obj->_radius, &radius_bits, sizeof(float));
}
void circled_fromBytesLE(circled_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circled_fromBytesLE");
        return;
    }

    uint64_t x_bits = read_le64(src);
    uint64_t y_bits = read_le64(src + 8);
    uint64_t radius_bits = read_le64(src + 16);

    memcpy(&obj->_posX, &x_bits, sizeof(double));
    memcpy(&obj->_posY, &y_bits, sizeof(double));
    memcpy(&obj->_radius, &radius_bits, sizeof(double));
}
void circleld_fromBytesLE(circleld_t* obj, const uint8_t* src) {
    CIRCLE_MALLOC_CLEAR_ERROR();

    if (obj == NULL || src == NULL) {
        circle_last_error = CIRCLE_ERROR_UNKNOWN;
        circle_set_error_string("Null pointer passed to circleld_fromBytesLE");
        return;
    }

    memcpy(&obj->_posX, src, sizeof(long double));
    memcpy(&obj->_posY, src + sizeof(long double), sizeof(long double));
    memcpy(&obj->_radius, src + 2 * sizeof(long double), sizeof(long double));
}
