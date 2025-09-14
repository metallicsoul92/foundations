#include "../../include/physics/rect.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

/*
  Error Handling
*/
// Common error codes for all rectangle types
typedef enum {
    RECT_SUCCESS = 0,
    RECT_ERROR_MALLOC_FAILED,
    RECT_ERROR_OVERFLOW,
    RECT_ERROR_INVALID_DIMENSIONS,
    RECT_ERROR_UNKNOWN
} rect_error_t;

// Global error state for all rectangle types
static rect_error_t rect_last_error = RECT_SUCCESS;
static const char* rect_error_string = NULL;

// Error strings
static const char* RECT_ERROR_STRINGS[] = {
    "Success",
    "Memory allocation failed",
    "Rectangle would cause coordinate overflow",
    "Invalid dimensions provided",
    "Unknown error"
};

// Function to get the last error code
rect_error_t rect_get_error(void) {
    return rect_last_error;
}

// Function to get the last error string
const char* rect_get_error_string(void) {
    if (rect_error_string != NULL) {
        return rect_error_string;
    }
    return RECT_ERROR_STRINGS[rect_last_error];
}

// Function to set a custom error string
void rect_set_error_string(const char* custom_error) {
    rect_error_string = custom_error;
}

// Function to clear error state
void rect_clear_error(void) {
    rect_last_error = RECT_SUCCESS;
    rect_error_string = NULL;
}


/*
  Structure Definitions
*/

struct _rectu8_t{
  uint8_t _posx;
  uint8_t _posy;
  uint8_t _width;
  uint8_t _height;
};

struct _recti8_t{
  int8_t _posx;
  int8_t _posy;
  int8_t _width;
  int8_t _height;
};

struct _rectu16_t{
  uint16_t _posx;
  uint16_t _posy;
  uint16_t _width;
  uint16_t _height;
};

struct _recti16_t{
  int16_t _posx;
  int16_t _posy;
  int16_t _width;
  int16_t _height;
};

struct _rectu32_t{
  uint32_t _posx;
  uint32_t _posy;
  uint32_t _width;
  uint32_t _height;
};

struct _recti32_t{
  int32_t _posx;
  int32_t _posy;
  int32_t _width;
  int32_t _height;
};

struct _rectu64_t{
  uint64_t _posx;
  uint64_t _posy;
  uint64_t _width;
  uint64_t _height;
};

struct _recti64_t{
  int64_t _posx;
  int64_t _posy;
  int64_t _width;
  int64_t _height;
};

struct _rectf_t{
  float _posx;
  float _posy;
  float _width;
  float _height;
};

struct _rectd_t{
  double _posx;
  double _posy;
  double _width;
  double _height;
};

struct _rectld_t{
  long double _posx;
  long double _posy;
  long double _width;
  long double _height;
};


//Memory Allocation
//malloc from parameters
rectu8_t* rectu8_malloc(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
    rect_clear_error();

    if ((UINT8_MAX - x) < width || (UINT8_MAX - y) < height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        return NULL;
    }

    rectu8_t* ret = malloc(sizeof(rectu8_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

recti8_t* recti8_malloc(int8_t x, int8_t y, int8_t width, int8_t height) {
    rect_clear_error();

    if ((width > 0 && x > INT8_MAX - width) ||
        (width < 0 && x < INT8_MIN - width) ||
        (height > 0 && y > INT8_MAX - height) ||
        (height < 0 && y < INT8_MIN - height)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        return NULL;
    }

    recti8_t* ret = malloc(sizeof(recti8_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

rectu16_t* rectu16_malloc(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
    rect_clear_error();

    if ((UINT16_MAX - x) < width || (UINT16_MAX - y) < height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        return NULL;
    }

    rectu16_t* ret = malloc(sizeof(rectu16_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

recti16_t* recti16_malloc(int16_t x, int16_t y, int16_t width, int16_t height) {
    rect_clear_error();

    if ((width > 0 && x > INT16_MAX - width) ||
        (width < 0 && x < INT16_MIN - width) ||
        (height > 0 && y > INT16_MAX - height) ||
        (height < 0 && y < INT16_MIN - height)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        return NULL;
    }

    recti16_t* ret = malloc(sizeof(recti16_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

rectu32_t* rectu32_malloc(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
    rect_clear_error();

    if ((UINT32_MAX - x) < width || (UINT32_MAX - y) < height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        return NULL;
    }

    rectu32_t* ret = malloc(sizeof(rectu32_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

recti32_t* recti32_malloc(int32_t x, int32_t y, int32_t width, int32_t height) {
    rect_clear_error();

    if ((width > 0 && x > INT32_MAX - width) ||
        (width < 0 && x < INT32_MIN - width) ||
        (height > 0 && y > INT32_MAX - height) ||
        (height < 0 && y < INT32_MIN - height)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        return NULL;
    }

    recti32_t* ret = malloc(sizeof(recti32_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

rectu64_t* rectu64_malloc(uint64_t x, uint64_t y, uint64_t width, uint64_t height) {
    rect_clear_error();

    if ((UINT64_MAX - x) < width || (UINT64_MAX - y) < height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        return NULL;
    }

    rectu64_t* ret = malloc(sizeof(rectu64_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

recti64_t* recti64_malloc(int64_t x, int64_t y, int64_t width, int64_t height) {
    rect_clear_error();

    if ((width > 0 && x > INT64_MAX - width) ||
        (width < 0 && x < INT64_MIN - width) ||
        (height > 0 && y > INT64_MAX - height) ||
        (height < 0 && y < INT64_MIN - height)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        return NULL;
    }

    recti64_t* ret = malloc(sizeof(recti64_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

rectf_t* rectf_malloc(float x, float y, float width, float height) {
    rect_clear_error();

    // Check for NaN or infinity
    if (isnan(x) || isnan(y) || isnan(width) || isnan(height) ||
        isinf(x) || isinf(y) || isinf(width) || isinf(height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    rectf_t* ret = malloc(sizeof(rectf_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

rectd_t* rectd_malloc(double x, double y, double width, double height) {
    rect_clear_error();

    // Check for NaN or infinity
    if (isnan(x) || isnan(y) || isnan(width) || isnan(height) ||
        isinf(x) || isinf(y) || isinf(width) || isinf(height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    rectd_t* ret = malloc(sizeof(rectd_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

rectld_t* rectld_malloc(long double x, long double y, long double width, long double height) {
    rect_clear_error();

    // Check for NaN or infinity
    if (isnan(x) || isnan(y) || isnan(width) || isnan(height) ||
        isinf(x) || isinf(y) || isinf(width) || isinf(height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    rectld_t* ret = malloc(sizeof(rectld_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = x;
    ret->_posy = y;
    ret->_width = width;
    ret->_height = height;

    return ret;
}

//malloc empty
rectu8_t* rectu8_mallocEmpty(void) {
    rect_clear_error();

    rectu8_t* ret = malloc(sizeof(rectu8_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0;
    ret->_posy = 0;
    ret->_width = 0;
    ret->_height = 0;

    return ret;
}

recti8_t* recti8_mallocEmpty(void) {
    rect_clear_error();

    recti8_t* ret = malloc(sizeof(recti8_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0;
    ret->_posy = 0;
    ret->_width = 0;
    ret->_height = 0;

    return ret;
}

rectu16_t* rectu16_mallocEmpty(void) {
    rect_clear_error();

    rectu16_t* ret = malloc(sizeof(rectu16_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0;
    ret->_posy = 0;
    ret->_width = 0;
    ret->_height = 0;

    return ret;
}

recti16_t* recti16_mallocEmpty(void) {
    rect_clear_error();

    recti16_t* ret = malloc(sizeof(recti16_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0;
    ret->_posy = 0;
    ret->_width = 0;
    ret->_height = 0;

    return ret;
}

rectu32_t* rectu32_mallocEmpty(void) {
    rect_clear_error();

    rectu32_t* ret = malloc(sizeof(rectu32_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0;
    ret->_posy = 0;
    ret->_width = 0;
    ret->_height = 0;

    return ret;
}

recti32_t* recti32_mallocEmpty(void) {
    rect_clear_error();

    recti32_t* ret = malloc(sizeof(recti32_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0;
    ret->_posy = 0;
    ret->_width = 0;
    ret->_height = 0;

    return ret;
}

rectu64_t* rectu64_mallocEmpty(void) {
    rect_clear_error();

    rectu64_t* ret = malloc(sizeof(rectu64_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0;
    ret->_posy = 0;
    ret->_width = 0;
    ret->_height = 0;

    return ret;
}

recti64_t* recti64_mallocEmpty(void) {
    rect_clear_error();

    recti64_t* ret = malloc(sizeof(recti64_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0;
    ret->_posy = 0;
    ret->_width = 0;
    ret->_height = 0;

    return ret;
}

rectf_t* rectf_mallocEmpty(void) {
    rect_clear_error();

    rectf_t* ret = malloc(sizeof(rectf_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0.0f;
    ret->_posy = 0.0f;
    ret->_width = 0.0f;
    ret->_height = 0.0f;

    return ret;
}

rectd_t* rectd_mallocEmpty(void) {
    rect_clear_error();

    rectd_t* ret = malloc(sizeof(rectd_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0.0;
    ret->_posy = 0.0;
    ret->_width = 0.0;
    ret->_height = 0.0;

    return ret;
}

rectld_t* rectld_mallocEmpty(void) {
    rect_clear_error();

    rectld_t* ret = malloc(sizeof(rectld_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = 0.0L;
    ret->_posy = 0.0L;
    ret->_width = 0.0L;
    ret->_height = 0.0L;

    return ret;
}

// Copy functions for all rectangle types
rectu8_t* rectu8_copy(const rectu8_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    rectu8_t* ret = malloc(sizeof(rectu8_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    // Copy all members
    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

recti8_t* recti8_copy(const recti8_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    recti8_t* ret = malloc(sizeof(recti8_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

rectu16_t* rectu16_copy(const rectu16_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    rectu16_t* ret = malloc(sizeof(rectu16_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

recti16_t* recti16_copy(const recti16_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    recti16_t* ret = malloc(sizeof(recti16_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

rectu32_t* rectu32_copy(const rectu32_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    rectu32_t* ret = malloc(sizeof(rectu32_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

recti32_t* recti32_copy(const recti32_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    recti32_t* ret = malloc(sizeof(recti32_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

rectu64_t* rectu64_copy(const rectu64_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    rectu64_t* ret = malloc(sizeof(rectu64_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

recti64_t* recti64_copy(const recti64_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    recti64_t* ret = malloc(sizeof(recti64_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

rectf_t* rectf_copy(const rectf_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    // Check for NaN or infinity in the source
    if (isnan(copy->_posx) || isnan(copy->_posy) || isnan(copy->_width) || isnan(copy->_height) ||
        isinf(copy->_posx) || isinf(copy->_posy) || isinf(copy->_width) || isinf(copy->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy rectangle with NaN or infinite values");
        return NULL;
    }

    rectf_t* ret = malloc(sizeof(rectf_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

rectd_t* rectd_copy(const rectd_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    // Check for NaN or infinity in the source
    if (isnan(copy->_posx) || isnan(copy->_posy) || isnan(copy->_width) || isnan(copy->_height) ||
        isinf(copy->_posx) || isinf(copy->_posy) || isinf(copy->_width) || isinf(copy->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy rectangle with NaN or infinite values");
        return NULL;
    }

    rectd_t* ret = malloc(sizeof(rectd_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

rectld_t* rectld_copy(const rectld_t* copy) {
    rect_clear_error();

    if (copy == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }

    // Check for NaN or infinity in the source
    if (isnan(copy->_posx) || isnan(copy->_posy) || isnan(copy->_width) || isnan(copy->_height) ||
        isinf(copy->_posx) || isinf(copy->_posy) || isinf(copy->_width) || isinf(copy->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot copy rectangle with NaN or infinite values");
        return NULL;
    }

    rectld_t* ret = malloc(sizeof(rectld_t));
    if (ret == NULL) {
        rect_last_error = RECT_ERROR_MALLOC_FAILED;
        return NULL;
    }

    ret->_posx = copy->_posx;
    ret->_posy = copy->_posy;
    ret->_width = copy->_width;
    ret->_height = copy->_height;

    return ret;
}

// Move functions for all rectangle types with safe ownership transfer
rectu8_t* rectu8_memmove(rectu8_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    rectu8_t* result = *move;
    *move = NULL;  // Nullify the original pointer

    return result;
}

recti8_t* recti8_memmove(recti8_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    recti8_t* result = *move;
    *move = NULL;

    return result;
}

rectu16_t* rectu16_memmove(rectu16_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    rectu16_t* result = *move;
    *move = NULL;

    return result;
}

recti16_t* recti16_memmove(recti16_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    recti16_t* result = *move;
    *move = NULL;

    return result;
}

rectu32_t* rectu32_memmove(rectu32_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    rectu32_t* result = *move;
    *move = NULL;

    return result;
}

recti32_t* recti32_memmove(recti32_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    recti32_t* result = *move;
    *move = NULL;

    return result;
}

rectu64_t* rectu64_memmove(rectu64_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    rectu64_t* result = *move;
    *move = NULL;

    return result;
}

recti64_t* recti64_memmove(recti64_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    recti64_t* result = *move;
    *move = NULL;

    return result;
}

rectf_t* rectf_memmove(rectf_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    rectf_t* result = *move;

    // Additional validation for floating-point rectangles
    if (isnan(result->_posx) || isnan(result->_posy) ||
        isnan(result->_width) || isnan(result->_height) ||
        isinf(result->_posx) || isinf(result->_posy) ||
        isinf(result->_width) || isinf(result->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move rectangle with NaN or infinite values");
        return NULL;
    }

    *move = NULL;

    return result;
}

rectd_t* rectd_memmove(rectd_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    rectd_t* result = *move;

    // Additional validation for floating-point rectangles
    if (isnan(result->_posx) || isnan(result->_posy) ||
        isnan(result->_width) || isnan(result->_height) ||
        isinf(result->_posx) || isinf(result->_posy) ||
        isinf(result->_width) || isinf(result->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move rectangle with NaN or infinite values");
        return NULL;
    }

    *move = NULL;

    return result;
}

rectld_t* rectld_memmove(rectld_t** move) {
    rect_clear_error();

    if (move == NULL || *move == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move NULL pointer");
        return NULL;
    }

    rectld_t* result = *move;

    // Additional validation for floating-point rectangles
    if (isnan(result->_posx) || isnan(result->_posy) ||
        isnan(result->_width) || isnan(result->_height) ||
        isinf(result->_posx) || isinf(result->_posy) ||
        isinf(result->_width) || isinf(result->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move rectangle with NaN or infinite values");
        return NULL;
    }

    *move = NULL;

    return result;
}

// Free functions for all rectangle types
void rectu8_free(rectu8_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

void recti8_free(recti8_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

void rectu16_free(rectu16_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

void recti16_free(recti16_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

void rectu32_free(rectu32_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

void recti32_free(recti32_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

void rectu64_free(rectu64_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

void recti64_free(recti64_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

void rectf_free(rectf_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

void rectd_free(rectd_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

void rectld_free(rectld_t* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

// Accessor functions for X coordinate
uint8_t rectu8_getX(const rectu8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posx;
}

int8_t recti8_getX(const recti8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posx;
}

uint16_t rectu16_getX(const rectu16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posx;
}

int16_t recti16_getX(const recti16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posx;
}

uint32_t rectu32_getX(const rectu32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posx;
}

int32_t recti32_getX(const recti32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posx;
}

uint64_t rectu64_getX(const rectu64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posx;
}

int64_t recti64_getX(const recti64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posx;
}

float rectf_getX(const rectf_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0f;
    }
    return obj->_posx;
}

double rectd_getX(const rectd_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0;
    }
    return obj->_posx;
}

long double rectld_getX(const rectld_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0L;
    }
    return obj->_posx;
}

// Accessor functions for Y coordinate
uint8_t rectu8_getY(const rectu8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posy;
}

int8_t recti8_getY(const recti8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posy;
}

uint16_t rectu16_getY(const rectu16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posy;
}

int16_t recti16_getY(const recti16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posy;
}

uint32_t rectu32_getY(const rectu32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posy;
}

int32_t recti32_getY(const recti32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posy;
}

uint64_t rectu64_getY(const rectu64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posy;
}

int64_t recti64_getY(const recti64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_posy;
}

float rectf_getY(const rectf_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0f;
    }
    return obj->_posy;
}

double rectd_getY(const rectd_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0;
    }
    return obj->_posy;
}

long double rectld_getY(const rectld_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0L;
    }
    return obj->_posy;
}

// Accessor functions for Width
uint8_t rectu8_getWidth(const rectu8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_width;
}

int8_t recti8_getWidth(const recti8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_width;
}

uint16_t rectu16_getWidth(const rectu16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_width;
}

int16_t recti16_getWidth(const recti16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_width;
}

uint32_t rectu32_getWidth(const rectu32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_width;
}

int32_t recti32_getWidth(const recti32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_width;
}

uint64_t rectu64_getWidth(const rectu64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_width;
}

int64_t recti64_getWidth(const recti64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_width;
}

float rectf_getWidth(const rectf_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0f;
    }
    return obj->_width;
}

double rectd_getWidth(const rectd_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0;
    }
    return obj->_width;
}

long double rectld_getWidth(const rectld_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0L;
    }
    return obj->_width;
}

// Accessor functions for Height
uint8_t rectu8_getHeight(const rectu8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_height;
}

int8_t recti8_getHeight(const recti8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_height;
}

uint16_t rectu16_getHeight(const rectu16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_height;
}

int16_t recti16_getHeight(const recti16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_height;
}

uint32_t rectu32_getHeight(const rectu32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_height;
}

int32_t recti32_getHeight(const recti32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_height;
}

uint64_t rectu64_getHeight(const rectu64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_height;
}

int64_t recti64_getHeight(const recti64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }
    return obj->_height;
}

float rectf_getHeight(const rectf_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0f;
    }
    return obj->_height;
}

double rectd_getHeight(const rectd_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0;
    }
    return obj->_height;
}

long double rectld_getHeight(const rectld_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0L;
    }
    return obj->_height;
}

// Setter functions for X coordinate
void rectu8_setPosX(rectu8_t* obj, uint8_t posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
}

void recti8_setPosX(recti8_t* obj, int8_t posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
}

void rectu16_setPosX(rectu16_t* obj, uint16_t posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
}

void recti16_setPosX(recti16_t* obj, int16_t posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
}

void rectu32_setPosX(rectu32_t* obj, uint32_t posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
}

void recti32_setPosX(recti32_t* obj, int32_t posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
}

void rectu64_setPosX(rectu64_t* obj, uint64_t posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
}

void recti64_setPosX(recti64_t* obj, int64_t posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
}

void rectf_setPosX(rectf_t* obj, float posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(posX) || isinf(posX)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set position to NaN or infinity");
        return;
    }

    obj->_posx = posX;
}

void rectd_setPosX(rectd_t* obj, double posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(posX) || isinf(posX)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set position to NaN or infinity");
        return;
    }

    obj->_posx = posX;
}

void rectld_setPosX(rectld_t* obj, long double posX) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(posX) || isinf(posX)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set position to NaN or infinity");
        return;
    }

    obj->_posx = posX;
}

// Setter functions for Y coordinate
void rectu8_setPosY(rectu8_t* obj, uint8_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posy = posY;
}

void recti8_setPosY(recti8_t* obj, int8_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posy = posY;
}

void rectu16_setPosY(rectu16_t* obj, uint16_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posy = posY;
}

void recti16_setPosY(recti16_t* obj, int16_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posy = posY;
}

void rectu32_setPosY(rectu32_t* obj, uint32_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posy = posY;
}

void recti32_setPosY(recti32_t* obj, int32_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posy = posY;
}

void rectu64_setPosY(rectu64_t* obj, uint64_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posy = posY;
}

void recti64_setPosY(recti64_t* obj, int64_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posy = posY;
}

void rectf_setPosY(rectf_t* obj, float posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(posY) || isinf(posY)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set position to NaN or infinity");
        return;
    }

    obj->_posy = posY;
}

void rectd_setPosY(rectd_t* obj, double posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(posY) || isinf(posY)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set position to NaN or infinity");
        return;
    }

    obj->_posy = posY;
}

void rectld_setPosY(rectld_t* obj, long double posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(posY) || isinf(posY)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set position to NaN or infinity");
        return;
    }

    obj->_posy = posY;
}

// Setter functions for Position (X and Y coordinates)
void rectu8_setPos(rectu8_t* obj, uint8_t posX, uint8_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
}

void recti8_setPos(recti8_t* obj, int8_t posX, int8_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
}

void rectu16_setPos(rectu16_t* obj, uint16_t posX, uint16_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
}

void recti16_setPos(recti16_t* obj, int16_t posX, int16_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
}

void rectu32_setPos(rectu32_t* obj, uint32_t posX, uint32_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
}

void recti32_setPos(recti32_t* obj, int32_t posX, int32_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
}

void rectu64_setPos(rectu64_t* obj, uint64_t posX, uint64_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
}

void recti64_setPos(recti64_t* obj, int64_t posX, int64_t posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
}

void rectf_setPos(rectf_t* obj, float posX, float posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point values
    if (isnan(posX) || isinf(posX) || isnan(posY) || isinf(posY)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set position to NaN or infinity");
        return;
    }

    obj->_posx = posX;
    obj->_posy = posY;
}

void rectd_setPos(rectd_t* obj, double posX, double posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point values
    if (isnan(posX) || isinf(posX) || isnan(posY) || isinf(posY)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set position to NaN or infinity");
        return;
    }

    obj->_posx = posX;
    obj->_posy = posY;
}

void rectld_setPos(rectld_t* obj, long double posX, long double posY) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point values
    if (isnan(posX) || isinf(posX) || isnan(posY) || isinf(posY)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set position to NaN or infinity");
        return;
    }

    obj->_posx = posX;
    obj->_posy = posY;
}

// Setter functions for Width
void rectu8_setWidth(rectu8_t* obj, uint8_t width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
}

void recti8_setWidth(recti8_t* obj, int8_t width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
}

void rectu16_setWidth(rectu16_t* obj, uint16_t width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
}

void recti16_setWidth(recti16_t* obj, int16_t width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
}

void rectu32_setWidth(rectu32_t* obj, uint32_t width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
}

void recti32_setWidth(recti32_t* obj, int32_t width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
}

void rectu64_setWidth(rectu64_t* obj, uint64_t width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
}

void recti64_setWidth(recti64_t* obj, int64_t width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
}

void rectf_setWidth(rectf_t* obj, float width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(width) || isinf(width) || width < 0.0f) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set width to NaN, infinity, or negative value");
        return;
    }

    obj->_width = width;
}

void rectd_setWidth(rectd_t* obj, double width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(width) || isinf(width) || width < 0.0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set width to NaN, infinity, or negative value");
        return;
    }

    obj->_width = width;
}

void rectld_setWidth(rectld_t* obj, long double width) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(width) || isinf(width) || width < 0.0L) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set width to NaN, infinity, or negative value");
        return;
    }

    obj->_width = width;
}

// Setter functions for Height
void rectu8_setHeight(rectu8_t* obj, uint8_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_height = height;
}

void recti8_setHeight(recti8_t* obj, int8_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_height = height;
}

void rectu16_setHeight(rectu16_t* obj, uint16_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_height = height;
}

void recti16_setHeight(recti16_t* obj, int16_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_height = height;
}

void rectu32_setHeight(rectu32_t* obj, uint32_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_height = height;
}

void recti32_setHeight(recti32_t* obj, int32_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_height = height;
}

void rectu64_setHeight(rectu64_t* obj, uint64_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_height = height;
}

void recti64_setHeight(recti64_t* obj, int64_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_height = height;
}

void rectf_setHeight(rectf_t* obj, float height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(height) || isinf(height) || height < 0.0f) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set height to NaN, infinity, or negative value");
        return;
    }

    obj->_height = height;
}

void rectd_setHeight(rectd_t* obj, double height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(height) || isinf(height) || height < 0.0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set height to NaN, infinity, or negative value");
        return;
    }

    obj->_height = height;
}

void rectld_setHeight(rectld_t* obj, long double height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point value
    if (isnan(height) || isinf(height) || height < 0.0L) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set height to NaN, infinity, or negative value");
        return;
    }

    obj->_height = height;
}

// Setter functions for Size (width and height)
void rectu8_setSize(rectu8_t* obj, uint8_t width, uint8_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
    obj->_height = height;
}

void recti8_setSize(recti8_t* obj, int8_t width, int8_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
    obj->_height = height;
}

void rectu16_setSize(rectu16_t* obj, uint16_t width, uint16_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
    obj->_height = height;
}

void recti16_setSize(recti16_t* obj, int16_t width, int16_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
    obj->_height = height;
}

void rectu32_setSize(rectu32_t* obj, uint32_t width, uint32_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
    obj->_height = height;
}

void recti32_setSize(recti32_t* obj, int32_t width, int32_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
    obj->_height = height;
}

void rectu64_setSize(rectu64_t* obj, uint64_t width, uint64_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
    obj->_height = height;
}

void recti64_setSize(recti64_t* obj, int64_t width, int64_t height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }
    obj->_width = width;
    obj->_height = height;
}

void rectf_setSize(rectf_t* obj, float width, float height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point values
    if (isnan(width) || isinf(width) || width < 0.0f ||
        isnan(height) || isinf(height) || height < 0.0f) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set size to NaN, infinity, or negative value");
        return;
    }

    obj->_width = width;
    obj->_height = height;
}

void rectd_setSize(rectd_t* obj, double width, double height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point values
    if (isnan(width) || isinf(width) || width < 0.0 ||
        isnan(height) || isinf(height) || height < 0.0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set size to NaN, infinity, or negative value");
        return;
    }

    obj->_width = width;
    obj->_height = height;
}

void rectld_setSize(rectld_t* obj, long double width, long double height) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point values
    if (isnan(width) || isinf(width) || width < 0.0L ||
        isnan(height) || isinf(height) || height < 0.0L) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot set size to NaN, infinity, or negative value");
        return;
    }

    obj->_width = width;
    obj->_height = height;
}

// Move functions for X coordinate
void rectu8_moveX(rectu8_t* obj, uint8_t dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if (dx > 0 && obj->_posx > UINT8_MAX - dx) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    obj->_posx += dx;
}

void recti8_moveX(recti8_t* obj, int8_t dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if ((dx > 0 && obj->_posx > INT8_MAX - dx) ||
        (dx < 0 && obj->_posx < INT8_MIN - dx)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    obj->_posx += dx;
}

void rectu16_moveX(rectu16_t* obj, uint16_t dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if (dx > 0 && obj->_posx > UINT16_MAX - dx) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    obj->_posx += dx;
}

void recti16_moveX(recti16_t* obj, int16_t dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if ((dx > 0 && obj->_posx > INT16_MAX - dx) ||
        (dx < 0 && obj->_posx < INT16_MIN - dx)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    obj->_posx += dx;
}

void rectu32_moveX(rectu32_t* obj, uint32_t dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if (dx > 0 && obj->_posx > UINT32_MAX - dx) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    obj->_posx += dx;
}

void recti32_moveX(recti32_t* obj, int32_t dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if ((dx > 0 && obj->_posx > INT32_MAX - dx) ||
        (dx < 0 && obj->_posx < INT32_MIN - dx)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    obj->_posx += dx;
}

void rectu64_moveX(rectu64_t* obj, uint64_t dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if (dx > 0 && obj->_posx > UINT64_MAX - dx) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    obj->_posx += dx;
}

void recti64_moveX(recti64_t* obj, int64_t dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if ((dx > 0 && obj->_posx > INT64_MAX - dx) ||
        (dx < 0 && obj->_posx < INT64_MIN - dx)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    obj->_posx += dx;
}

void rectf_moveX(rectf_t* obj, float dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dx) || isinf(dx)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move by NaN or infinity");
        return;
    }

    obj->_posx += dx;
}

void rectd_moveX(rectd_t* obj, double dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dx) || isinf(dx)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move by NaN or infinity");
        return;
    }

    obj->_posx += dx;
}

void rectld_moveX(rectld_t* obj, long double dx) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dx) || isinf(dx)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move by NaN or infinity");
        return;
    }

    obj->_posx += dx;
}

// Move functions for Y coordinate
void rectu8_moveY(rectu8_t* obj, uint8_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if (dy > 0 && obj->_posy > UINT8_MAX - dy) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posy += dy;
}

void recti8_moveY(recti8_t* obj, int8_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if ((dy > 0 && obj->_posy > INT8_MAX - dy) ||
        (dy < 0 && obj->_posy < INT8_MIN - dy)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posy += dy;
}

void rectu16_moveY(rectu16_t* obj, uint16_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if (dy > 0 && obj->_posy > UINT16_MAX - dy) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posy += dy;
}

void recti16_moveY(recti16_t* obj, int16_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if ((dy > 0 && obj->_posy > INT16_MAX - dy) ||
        (dy < 0 && obj->_posy < INT16_MIN - dy)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posy += dy;
}

void rectu32_moveY(rectu32_t* obj, uint32_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if (dy > 0 && obj->_posy > UINT32_MAX - dy) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posy += dy;
}

void recti32_moveY(recti32_t* obj, int32_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if ((dy > 0 && obj->_posy > INT32_MAX - dy) ||
        (dy < 0 && obj->_posy < INT32_MIN - dy)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posy += dy;
}

void rectu64_moveY(rectu64_t* obj, uint64_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if (dy > 0 && obj->_posy > UINT64_MAX - dy) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posy += dy;
}

void recti64_moveY(recti64_t* obj, int64_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow
    if ((dy > 0 && obj->_posy > INT64_MAX - dy) ||
        (dy < 0 && obj->_posy < INT64_MIN - dy)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posy += dy;
}

void rectf_moveY(rectf_t* obj, float dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dy) || isinf(dy)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move by NaN or infinity");
        return;
    }

    obj->_posy += dy;
}

void rectd_moveY(rectd_t* obj, double dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dy) || isinf(dy)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move by NaN or infinity");
        return;
    }

    obj->_posy += dy;
}

void rectld_moveY(rectld_t* obj, long double dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dy) || isinf(dy)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move by NaN or infinity");
        return;
    }

    obj->_posy += dy;
}

// Move functions for both X and Y coordinates
void rectu8_move(rectu8_t* obj, uint8_t dx, uint8_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow in X
    if (dx > 0 && obj->_posx > UINT8_MAX - dx) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    // Check for potential overflow in Y
    if (dy > 0 && obj->_posy > UINT8_MAX - dy) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

void recti8_move(recti8_t* obj, int8_t dx, int8_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow in X
    if ((dx > 0 && obj->_posx > INT8_MAX - dx) ||
        (dx < 0 && obj->_posx < INT8_MIN - dx)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    // Check for potential overflow in Y
    if ((dy > 0 && obj->_posy > INT8_MAX - dy) ||
        (dy < 0 && obj->_posy < INT8_MIN - dy)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

void rectu16_move(rectu16_t* obj, uint16_t dx, uint16_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow in X
    if (dx > 0 && obj->_posx > UINT16_MAX - dx) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    // Check for potential overflow in Y
    if (dy > 0 && obj->_posy > UINT16_MAX - dy) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

void recti16_move(recti16_t* obj, int16_t dx, int16_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow in X
    if ((dx > 0 && obj->_posx > INT16_MAX - dx) ||
        (dx < 0 && obj->_posx < INT16_MIN - dx)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    // Check for potential overflow in Y
    if ((dy > 0 && obj->_posy > INT16_MAX - dy) ||
        (dy < 0 && obj->_posy < INT16_MIN - dy)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

void rectu32_move(rectu32_t* obj, uint32_t dx, uint32_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow in X
    if (dx > 0 && obj->_posx > UINT32_MAX - dx) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    // Check for potential overflow in Y
    if (dy > 0 && obj->_posy > UINT32_MAX - dy) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

void recti32_move(recti32_t* obj, int32_t dx, int32_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow in X
    if ((dx > 0 && obj->_posx > INT32_MAX - dx) ||
        (dx < 0 && obj->_posx < INT32_MIN - dx)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    // Check for potential overflow in Y
    if ((dy > 0 && obj->_posy > INT32_MAX - dy) ||
        (dy < 0 && obj->_posy < INT32_MIN - dy)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

void rectu64_move(rectu64_t* obj, uint64_t dx, uint64_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow in X
    if (dx > 0 && obj->_posx > UINT64_MAX - dx) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    // Check for potential overflow in Y
    if (dy > 0 && obj->_posy > UINT64_MAX - dy) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

void recti64_move(recti64_t* obj, int64_t dx, int64_t dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow in X
    if ((dx > 0 && obj->_posx > INT64_MAX - dx) ||
        (dx < 0 && obj->_posx < INT64_MIN - dx)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("X coordinate would overflow");
        return;
    }

    // Check for potential overflow in Y
    if ((dy > 0 && obj->_posy > INT64_MAX - dy) ||
        (dy < 0 && obj->_posy < INT64_MIN - dy)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Y coordinate would overflow");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

void rectf_move(rectf_t* obj, float dx, float dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point deltas
    if (isnan(dx) || isinf(dx) || isnan(dy) || isinf(dy)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move by NaN or infinity");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

void rectd_move(rectd_t* obj, double dx, double dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point deltas
    if (isnan(dx) || isinf(dx) || isnan(dy) || isinf(dy)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move by NaN or infinity");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

void rectld_move(rectld_t* obj, long double dx, long double dy) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point deltas
    if (isnan(dx) || isinf(dx) || isnan(dy) || isinf(dy)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot move by NaN or infinity");
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
}

// Resize functions for Width
void rectu8_resizeWidth(rectu8_t* obj, uint8_t dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow (if decreasing width)
    if (dw > obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would underflow");
        return;
    }

    obj->_width += dw;
}

void recti8_resizeWidth(recti8_t* obj, int8_t dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow
    if ((dw > 0 && obj->_width > INT8_MAX - dw) ||
        (dw < 0 && obj->_width < INT8_MIN - dw)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would overflow");
        return;
    }

    // Check if result would be negative
    if (obj->_width + dw < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    obj->_width += dw;
}

void rectu16_resizeWidth(rectu16_t* obj, uint16_t dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow (if decreasing width)
    if (dw > obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would underflow");
        return;
    }

    obj->_width += dw;
}

void recti16_resizeWidth(recti16_t* obj, int16_t dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow
    if ((dw > 0 && obj->_width > INT16_MAX - dw) ||
        (dw < 0 && obj->_width < INT16_MIN - dw)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would overflow");
        return;
    }

    // Check if result would be negative
    if (obj->_width + dw < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    obj->_width += dw;
}

void rectu32_resizeWidth(rectu32_t* obj, uint32_t dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow (if decreasing width)
    if (dw > obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would underflow");
        return;
    }

    obj->_width += dw;
}

void recti32_resizeWidth(recti32_t* obj, int32_t dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow
    if ((dw > 0 && obj->_width > INT32_MAX - dw) ||
        (dw < 0 && obj->_width < INT32_MIN - dw)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would overflow");
        return;
    }

    // Check if result would be negative
    if (obj->_width + dw < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    obj->_width += dw;
}

void rectu64_resizeWidth(rectu64_t* obj, uint64_t dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow (if decreasing width)
    if (dw > obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would underflow");
        return;
    }

    obj->_width += dw;
}

void recti64_resizeWidth(recti64_t* obj, int64_t dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow
    if ((dw > 0 && obj->_width > INT64_MAX - dw) ||
        (dw < 0 && obj->_width < INT64_MIN - dw)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would overflow");
        return;
    }

    // Check if result would be negative
    if (obj->_width + dw < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    obj->_width += dw;
}

void rectf_resizeWidth(rectf_t* obj, float dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dw) || isinf(dw)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot resize by NaN or infinity");
        return;
    }

    // Check if result would be negative
    if (obj->_width + dw < 0.0f) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    obj->_width += dw;
}

void rectd_resizeWidth(rectd_t* obj, double dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dw) || isinf(dw)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot resize by NaN or infinity");
        return;
    }

    // Check if result would be negative
    if (obj->_width + dw < 0.0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    obj->_width += dw;
}

void rectld_resizeWidth(rectld_t* obj, long double dw) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dw) || isinf(dw)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot resize by NaN or infinity");
        return;
    }

    // Check if result would be negative
    if (obj->_width + dw < 0.0L) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    obj->_width += dw;
}

// Resize functions for Height
void rectu8_resizeHeight(rectu8_t* obj, uint8_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow (if decreasing height)
    if (dh > obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would underflow");
        return;
    }

    obj->_height += dh;
}

void recti8_resizeHeight(recti8_t* obj, int8_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow
    if ((dh > 0 && obj->_height > INT8_MAX - dh) ||
        (dh < 0 && obj->_height < INT8_MIN - dh)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would overflow");
        return;
    }

    // Check if result would be negative
    if (obj->_height + dh < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_height += dh;
}

void rectu16_resizeHeight(rectu16_t* obj, uint16_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow (if decreasing height)
    if (dh > obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would underflow");
        return;
    }

    obj->_height += dh;
}

void recti16_resizeHeight(recti16_t* obj, int16_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow
    if ((dh > 0 && obj->_height > INT16_MAX - dh) ||
        (dh < 0 && obj->_height < INT16_MIN - dh)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would overflow");
        return;
    }

    // Check if result would be negative
    if (obj->_height + dh < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_height += dh;
}

void rectu32_resizeHeight(rectu32_t* obj, uint32_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow (if decreasing height)
    if (dh > obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would underflow");
        return;
    }

    obj->_height += dh;
}

void recti32_resizeHeight(recti32_t* obj, int32_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow
    if ((dh > 0 && obj->_height > INT32_MAX - dh) ||
        (dh < 0 && obj->_height < INT32_MIN - dh)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would overflow");
        return;
    }

    // Check if result would be negative
    if (obj->_height + dh < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_height += dh;
}

void rectu64_resizeHeight(rectu64_t* obj, uint64_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow (if decreasing height)
    if (dh > obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would underflow");
        return;
    }

    obj->_height += dh;
}

void recti64_resizeHeight(recti64_t* obj, int64_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow
    if ((dh > 0 && obj->_height > INT64_MAX - dh) ||
        (dh < 0 && obj->_height < INT64_MIN - dh)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would overflow");
        return;
    }

    // Check if result would be negative
    if (obj->_height + dh < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_height += dh;
}

void rectf_resizeHeight(rectf_t* obj, float dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dh) || isinf(dh)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot resize by NaN or infinity");
        return;
    }

    // Check if result would be negative
    if (obj->_height + dh < 0.0f) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_height += dh;
}

void rectd_resizeHeight(rectd_t* obj, double dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dh) || isinf(dh)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot resize by NaN or infinity");
        return;
    }

    // Check if result would be negative
    if (obj->_height + dh < 0.0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_height += dh;
}

void rectld_resizeHeight(rectld_t* obj, long double dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point delta
    if (isnan(dh) || isinf(dh)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot resize by NaN or infinity");
        return;
    }

    // Check if result would be negative
    if (obj->_height + dh < 0.0L) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_height += dh;
}

// Resize functions for both Width and Height
void rectu8_resize(rectu8_t* obj, uint8_t dw, uint8_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow in width
    if (dw > obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would underflow");
        return;
    }

    // Check for potential underflow in height
    if (dh > obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would underflow");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

void recti8_resize(recti8_t* obj, int8_t dw, int8_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow in width
    if ((dw > 0 && obj->_width > INT8_MAX - dw) ||
        (dw < 0 && obj->_width < INT8_MIN - dw)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would overflow");
        return;
    }

    // Check if width result would be negative
    if (obj->_width + dw < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    // Check for potential overflow/underflow in height
    if ((dh > 0 && obj->_height > INT8_MAX - dh) ||
        (dh < 0 && obj->_height < INT8_MIN - dh)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would overflow");
        return;
    }

    // Check if height result would be negative
    if (obj->_height + dh < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

void rectu16_resize(rectu16_t* obj, uint16_t dw, uint16_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow in width
    if (dw > obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would underflow");
        return;
    }

    // Check for potential underflow in height
    if (dh > obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would underflow");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

void recti16_resize(recti16_t* obj, int16_t dw, int16_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow in width
    if ((dw > 0 && obj->_width > INT16_MAX - dw) ||
        (dw < 0 && obj->_width < INT16_MIN - dw)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would overflow");
        return;
    }

    // Check if width result would be negative
    if (obj->_width + dw < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    // Check for potential overflow/underflow in height
    if ((dh > 0 && obj->_height > INT16_MAX - dh) ||
        (dh < 0 && obj->_height < INT16_MIN - dh)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would overflow");
        return;
    }

    // Check if height result would be negative
    if (obj->_height + dh < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

void rectu32_resize(rectu32_t* obj, uint32_t dw, uint32_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow in width
    if (dw > obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would underflow");
        return;
    }

    // Check for potential underflow in height
    if (dh > obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would underflow");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

void recti32_resize(recti32_t* obj, int32_t dw, int32_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow in width
    if ((dw > 0 && obj->_width > INT32_MAX - dw) ||
        (dw < 0 && obj->_width < INT32_MIN - dw)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would overflow");
        return;
    }

    // Check if width result would be negative
    if (obj->_width + dw < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    // Check for potential overflow/underflow in height
    if ((dh > 0 && obj->_height > INT32_MAX - dh) ||
        (dh < 0 && obj->_height < INT32_MIN - dh)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would overflow");
        return;
    }

    // Check if height result would be negative
    if (obj->_height + dh < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

void rectu64_resize(rectu64_t* obj, uint64_t dw, uint64_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential underflow in width
    if (dw > obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would underflow");
        return;
    }

    // Check for potential underflow in height
    if (dh > obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would underflow");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

void recti64_resize(recti64_t* obj, int64_t dw, int64_t dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Check for potential overflow/underflow in width
    if ((dw > 0 && obj->_width > INT64_MAX - dw) ||
        (dw < 0 && obj->_width < INT64_MIN - dw)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Width would overflow");
        return;
    }

    // Check if width result would be negative
    if (obj->_width + dw < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    // Check for potential overflow/underflow in height
    if ((dh > 0 && obj->_height > INT64_MAX - dh) ||
        (dh < 0 && obj->_height < INT64_MIN - dh)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Height would overflow");
        return;
    }

    // Check if height result would be negative
    if (obj->_height + dh < 0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

void rectf_resize(rectf_t* obj, float dw, float dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point deltas
    if (isnan(dw) || isinf(dw) || isnan(dh) || isinf(dh)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot resize by NaN or infinity");
        return;
    }

    // Check if width result would be negative
    if (obj->_width + dw < 0.0f) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    // Check if height result would be negative
    if (obj->_height + dh < 0.0f) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

void rectd_resize(rectd_t* obj, double dw, double dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point deltas
    if (isnan(dw) || isinf(dw) || isnan(dh) || isinf(dh)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot resize by NaN or infinity");
        return;
    }

    // Check if width result would be negative
    if (obj->_width + dw < 0.0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    // Check if height result would be negative
    if (obj->_height + dh < 0.0) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

void rectld_resize(rectld_t* obj, long double dw, long double dh) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot modify NULL rectangle object");
        return;
    }

    // Validate floating-point deltas
    if (isnan(dw) || isinf(dw) || isnan(dh) || isinf(dh)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot resize by NaN or infinity");
        return;
    }

    // Check if width result would be negative
    if (obj->_width + dw < 0.0L) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Width cannot be negative");
        return;
    }

    // Check if height result would be negative
    if (obj->_height + dh < 0.0L) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Height cannot be negative");
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
}

// Geometry functions for getting the right side (X + width)
uint8_t rectu8_getSideX(const rectu8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_posx > UINT8_MAX - obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Right side calculation would overflow");
        return UINT8_MAX;
    }

    return obj->_posx + obj->_width;
}

int8_t recti8_getSideX(const recti8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_width > 0 && obj->_posx > INT8_MAX - obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Right side calculation would overflow");
        return INT8_MAX;
    }

    return obj->_posx + obj->_width;
}

uint16_t rectu16_getSideX(const rectu16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_posx > UINT16_MAX - obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Right side calculation would overflow");
        return UINT16_MAX;
    }

    return obj->_posx + obj->_width;
}

int16_t recti16_getSideX(const recti16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_width > 0 && obj->_posx > INT16_MAX - obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Right side calculation would overflow");
        return INT16_MAX;
    }

    return obj->_posx + obj->_width;
}

uint32_t rectu32_getSideX(const rectu32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_posx > UINT32_MAX - obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Right side calculation would overflow");
        return UINT32_MAX;
    }

    return obj->_posx + obj->_width;
}

int32_t recti32_getSideX(const recti32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_width > 0 && obj->_posx > INT32_MAX - obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Right side calculation would overflow");
        return INT32_MAX;
    }

    return obj->_posx + obj->_width;
}

uint64_t rectu64_getSideX(const rectu64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_posx > UINT64_MAX - obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Right side calculation would overflow");
        return UINT64_MAX;
    }

    return obj->_posx + obj->_width;
}

int64_t recti64_getSideX(const recti64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_width > 0 && obj->_posx > INT64_MAX - obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Right side calculation would overflow");
        return INT64_MAX;
    }

    return obj->_posx + obj->_width;
}

float rectf_getSideX(const rectf_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0f;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posx) || isnan(obj->_width) ||
        isinf(obj->_posx) || isinf(obj->_width)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate side with NaN or infinite values");
        return NAN;
    }

    return obj->_posx + obj->_width;
}

double rectd_getSideX(const rectd_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posx) || isnan(obj->_width) ||
        isinf(obj->_posx) || isinf(obj->_width)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate side with NaN or infinite values");
        return NAN;
    }

    return obj->_posx + obj->_width;
}

long double rectld_getSideX(const rectld_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0L;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posx) || isnan(obj->_width) ||
        isinf(obj->_posx) || isinf(obj->_width)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate side with NaN or infinite values");
        return NAN;
    }

    return obj->_posx + obj->_width;
}

// Geometry functions for getting the bottom side (Y + height)
uint8_t rectu8_getSideY(const rectu8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_posy > UINT8_MAX - obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Bottom side calculation would overflow");
        return UINT8_MAX;
    }

    return obj->_posy + obj->_height;
}

int8_t recti8_getSideY(const recti8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_height > 0 && obj->_posy > INT8_MAX - obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Bottom side calculation would overflow");
        return INT8_MAX;
    }

    return obj->_posy + obj->_height;
}

uint16_t rectu16_getSideY(const rectu16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_posy > UINT16_MAX - obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Bottom side calculation would overflow");
        return UINT16_MAX;
    }

    return obj->_posy + obj->_height;
}

int16_t recti16_getSideY(const recti16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_height > 0 && obj->_posy > INT16_MAX - obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Bottom side calculation would overflow");
        return INT16_MAX;
    }

    return obj->_posy + obj->_height;
}

uint32_t rectu32_getSideY(const rectu32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_posy > UINT32_MAX - obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Bottom side calculation would overflow");
        return UINT32_MAX;
    }

    return obj->_posy + obj->_height;
}

int32_t recti32_getSideY(const recti32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_height > 0 && obj->_posy > INT32_MAX - obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Bottom side calculation would overflow");
        return INT32_MAX;
    }

    return obj->_posy + obj->_height;
}

uint64_t rectu64_getSideY(const rectu64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_posy > UINT64_MAX - obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Bottom side calculation would overflow");
        return UINT64_MAX;
    }

    return obj->_posy + obj->_height;
}

int64_t recti64_getSideY(const recti64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_height > 0 && obj->_posy > INT64_MAX - obj->_height) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Bottom side calculation would overflow");
        return INT64_MAX;
    }

    return obj->_posy + obj->_height;
}

float rectf_getSideY(const rectf_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0f;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posy) || isnan(obj->_height) ||
        isinf(obj->_posy) || isinf(obj->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate side with NaN or infinite values");
        return NAN;
    }

    return obj->_posy + obj->_height;
}

double rectd_getSideY(const rectd_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posy) || isnan(obj->_height) ||
        isinf(obj->_posy) || isinf(obj->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate side with NaN or infinite values");
        return NAN;
    }

    return obj->_posy + obj->_height;
}

long double rectld_getSideY(const rectld_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0L;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posy) || isnan(obj->_height) ||
        isinf(obj->_posy) || isinf(obj->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate side with NaN or infinite values");
        return NAN;
    }

    return obj->_posy + obj->_height;
}

// Area calculation functions
uint8_t rectu8_area(const rectu8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_width > 0 && obj->_height > UINT8_MAX / obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Area calculation would overflow");
        return UINT8_MAX;
    }

    return obj->_width * obj->_height;
}

int8_t recti8_area(const recti8_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if ((obj->_width > 0 && obj->_height > INT8_MAX / obj->_width) ||
        (obj->_width < 0 && obj->_height < INT8_MIN / obj->_width)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Area calculation would overflow");
        return (obj->_width < 0 && obj->_height < 0) ? INT8_MAX : INT8_MAX;
    }

    return obj->_width * obj->_height;
}

uint16_t rectu16_area(const rectu16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_width > 0 && obj->_height > UINT16_MAX / obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Area calculation would overflow");
        return UINT16_MAX;
    }

    return obj->_width * obj->_height;
}

int16_t recti16_area(const recti16_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if ((obj->_width > 0 && obj->_height > INT16_MAX / obj->_width) ||
        (obj->_width < 0 && obj->_height < INT16_MIN / obj->_width)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Area calculation would overflow");
        return (obj->_width < 0 && obj->_height < 0) ? INT16_MAX : INT16_MAX;
    }

    return obj->_width * obj->_height;
}

uint32_t rectu32_area(const rectu32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_width > 0 && obj->_height > UINT32_MAX / obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Area calculation would overflow");
        return UINT32_MAX;
    }

    return obj->_width * obj->_height;
}

int32_t recti32_area(const recti32_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if ((obj->_width > 0 && obj->_height > INT32_MAX / obj->_width) ||
        (obj->_width < 0 && obj->_height < INT32_MIN / obj->_width)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Area calculation would overflow");
        return (obj->_width < 0 && obj->_height < 0) ? INT32_MAX : INT32_MAX;
    }

    return obj->_width * obj->_height;
}

uint64_t rectu64_area(const rectu64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if (obj->_width > 0 && obj->_height > UINT64_MAX / obj->_width) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Area calculation would overflow");
        return UINT64_MAX;
    }

    return obj->_width * obj->_height;
}

int64_t recti64_area(const recti64_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0;
    }

    // Check for potential overflow
    if ((obj->_width > 0 && obj->_height > INT64_MAX / obj->_width) ||
        (obj->_width < 0 && obj->_height < INT64_MIN / obj->_width)) {
        rect_last_error = RECT_ERROR_OVERFLOW;
        rect_set_error_string("Area calculation would overflow");
        return (obj->_width < 0 && obj->_height < 0) ? INT64_MAX : INT64_MAX;
    }

    return obj->_width * obj->_height;
}

float rectf_area(const rectf_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0f;
    }

    // Check for NaN or infinity
    if (isnan(obj->_width) || isnan(obj->_height) ||
        isinf(obj->_width) || isinf(obj->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate area with NaN or infinite values");
        return NAN;
    }

    return obj->_width * obj->_height;
}

double rectd_area(const rectd_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0;
    }

    // Check for NaN or infinity
    if (isnan(obj->_width) || isnan(obj->_height) ||
        isinf(obj->_width) || isinf(obj->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate area with NaN or infinite values");
        return NAN;
    }

    return obj->_width * obj->_height;
}

long double rectld_area(const rectld_t* obj) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot access NULL rectangle object");
        return 0.0L;
    }

    // Check for NaN or infinity
    if (isnan(obj->_width) || isnan(obj->_height) ||
        isinf(obj->_width) || isinf(obj->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate area with NaN or infinite values");
        return NAN;
    }

    return obj->_width * obj->_height;
}



#ifdef VEC2_DEFINED

//vec2 getPosVec2()
//YOU MUST FREE THIS MEMORY
vec2uint8_t * rectu8_getPosVec2(rectu8_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2U8(obj->_posx, obj->_posy);
}
vec2int8_t * recti8_getPosVec2(recti8_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2I8(obj->_posx, obj->_posy);
}
vec2uint16_t * rectu16_getPosVec2(rectu16_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2U16(obj->_posx, obj->_posy);
}
vec2int16_t * recti16_getPosVec2(recti16_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2I16(obj->_posx, obj->_posy);
}
vec2uint32_t * rectu32_getPosVec2(rectu32_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2U32(obj->_posx, obj->_posy);
}
vec2int32_t * recti32_getPosVec2(recti32_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2I32(obj->_posx, obj->_posy);
}
vec2uint64_t * rectu64_getPosVec2(rectu64_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2U64(obj->_posx, obj->_posy);
}
vec2int64_t * recti64_getPosVec2(recti64_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2I64(obj->_posx, obj->_posy);
}
vec2f_t * rectf_getPosVec2(recf_t * obj){
  if (obj == NULL) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot access NULL rectangle object");
      return NULL;
  }

  // Check for NaN or infinity
  if (isnan(obj->_posx) || isnan(obj->_posy) ||
      isinf(obj->_posx) || isinf(obj->_posy)) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot calculate area with NaN or infinite values");
      return NULL;
  }

  return allocVec2F(obj->_posx, obj->_posy);
}
vec2d_t * rectd_getPosVec2(rectd_t * obj){
  if (obj == NULL) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot access NULL rectangle object");
      return NULL;
  }

  // Check for NaN or infinity
  if (isnan(obj->_posx) || isnan(obj->_posy) ||
      isinf(obj->_posx) || isinf(obj->_posy)) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot calculate area with NaN or infinite values");
      return NULL;
  }

  return allocVec2D(obj->_posx, obj->_posy);
}
vec2ld_t * rectld_getPosVec2(rectld_t * obj){
  if (obj == NULL) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot access NULL rectangle object");
      return NULL;
  }

  // Check for NaN or infinity
  if (isnan(obj->_posx) || isnan(obj->_posy) ||
      isinf(obj->_posx) || isinf(obj->_posy)) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot calculate area with NaN or infinite values");
      return NULL;
  }

  return allocVec2LD(obj->_posx, obj->_posy);
}


//vec2 getSize()
//YOU MUST FREE THIS MEMORY
vec2uint8_t * rectu8_getSizeVec2(rectu8_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2U8(obj->_width, obj->_height);
}
vec2int8_t * recti8_getSizeVec2(recti8_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2I8(obj->_width, obj->_height);
}
vec2uint16_t * rectu16_getSizeVec2(rectu16_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2U16(obj->_width, obj->_height);
}
vec2int16_t * recti16_getSizeVec2(recti16_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2I16(obj->_width, obj->_height);
}
vec2uint32_t * rectu32_getSizeVec2(rectu32_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2U32(obj->_width, obj->_height);
}
vec2int32_t * recti32_getSizeVec2(recti32_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2I32(obj->_width, obj->_height);
}
vec2uint64_t * rectu64_getSizeVec2(rectu64_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2U64(obj->_width, obj->_height);
}
vec2int64_t * recti64_getSizeVec2(recti64_t * obj){
  if(obj == NULL){
    rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
    rect_set_error_string("Cannot access NULL rectangle object");
    return NULL;
  }
    return allocVec2I64(obj->_width, obj->_height);
}
vec2f_t * rectf_getSizeVec2(rectf_t * obj){
  if (obj == NULL) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot access NULL rectangle object");
      return NULL;
  }

  // Check for NaN or infinity
  if (isnan(obj->_width) || isnan(obj->_height) ||
      isinf(obj->_width) || isinf(obj->_height)) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot calculate area with NaN or infinite values");
      return NULL;
  }

  return allocVec2F(obj->_width, obj->_height);
}
vec2d_t * rectd_getSizeVec2(rectd_t * obj){
  if (obj == NULL) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot access NULL rectangle object");
      return NULL;
  }

  // Check for NaN or infinity
  if (isnan(obj->_width) || isnan(obj->_height) ||
      isinf(obj->_width) || isinf(obj->_height)) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot calculate area with NaN or infinite values");
      return NULL;
  }

  return allocVec2D(obj->_width, obj->_height);
}
vec2ld_t * rectld_getSizeVec2(rectld_t * obj){
  if (obj == NULL) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot access NULL rectangle object");
      return NULL;
  }

  // Check for NaN or infinity
  if (isnan(obj->_width) || isnan(obj->_height) ||
      isinf(obj->_width) || isinf(obj->_height)) {
      rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
      rect_set_error_string("Cannot calculate area with NaN or infinite values");
      return NULL;
  }

  return allocVec2LD(obj->_width, obj->_height);
}



//setSizeVec2()
void rectu8_setSizeVec2(rectu8_t * obj, const vec2uint8_t * size){
  rectu8_setSize(obj,vec2u8_X(size),vec2u8_Y(size));
}
void recti8_setSizeVec2(recti8_t * obj, const vec2int8_t * size){
  recti8_setSize(obj,vec2i8_X(size),vec2i8_Y(size));
}
void rectu16_setSizeVec2(rectu16_t * obj, const vec2uint16_t * size){
  rectu16_setSize(obj,vec2u16_X(size),vec2u16_Y(size));
}
void recti16_setSizeVec2(recti16_t * obj, const vec2int16_t * size){
  recti16_setSize(obj,vec2i16_X(size),vec2i16_Y(size));
}
void rectu32_setSizeVec2(rectu32_t * obj, const vec2uint32_t * size){
  recu32t_setSize(obj,vec2u32_X(size),vec2u32_Y(size));
}
void recti32_setSizeVec2(recti32_t * obj, const vec2int32_t * size){
  recti32_setSize(obj,vec2i32_X(size),vec2i32_Y(size));
}
void rectu64_setSizeVec2(rectu64_t * obj, const vec2uint64_t * size){
  rectu64_setSize(obj,vec2u64_X(size),vec2u64_Y(size));
}
void recti64_setSizeVec2(recti64_t * obj, const vec2int64_t * size){
  recti64_setSize(obj,vec2i64_X(size),vec2i64_Y(size));
}
void rectf_setSizeVec2(rectf_t * obj, const vec2f_t * size){
  rectf_setSize(obj,vecf_X(size),vecf_Y(size));
}
void rectd_setSizeVec2(rectd_t * obj, const vec2d_t * size){
  rectd_setSize(obj,vecd_X(size),vecd_Y(size));
}
void rectld_setSizeVec2(rectld_t * obj, const vec2ld_t * size){
  rectld_setSize(obj,vecld_X(size),vecld_Y(size));
}

//setPosVec2()
void rectu8_setPosVec2(rectu8_t * obj, const vec2uint8_t * pos){
  rectu8_setPos(obj,vec2u8_X(pos),vec2u8_Y(pos));
}
void recti8_setPosVec2(recti8_t * obj, const vec2int8_t * pos){
  recti8_setPos(obj,vec2i8_X(pos),vec2i8_Y(pos));
}
void rectu16_setPosVec2(rectu16_t * obj, const vec2uint16_t * pos){
  rectu16_setPos(obj,vec2u16_X(pos),vec2u16_Y(pos));
}
void recti16_setPosVec2(recti16_t * obj, const vec2int16_t * pos){
  recti16_setPos(obj,vec2i16_X(pos),vec2i16_Y(pos));
}
void rectu32_setPosVec2(rectu32_t * obj, const vec2uint32_t * pos){
  recu32t_setPos(obj,vec2u32_X(pos),vec2u32_Y(pos));
}
void recti32_setPosVec2(recti32_t * obj, const vec2int32_t * pos){
  recti32_setPos(obj,vec2i32_X(pos),vec2i32_Y(pos));
}
void rectu64_setPosVec2(rectu64_t * obj, const vec2uint64_t * pos){
  rectu64_setPos(obj,vec2u64_X(pos),vec2u64_Y(pos));
}
void recti64_setPosVec2(recti64_t * obj, const vec2int64_t * pos){
  recti64_setPos(obj,vec2i64_X(pos),vec2i64_Y(pos));
}
void rectf_setPosVec2(rectf_t * obj, const vec2f_t * pos){
  rectf_setPos(obj,vecf_X(pos),vecf_Y(pos));
}
void rectd_setPosVec2(rectd_t * obj, const vec2d_t * pos){
  rectd_setPos(obj,vecd_X(pos),vecd_Y(pos));
}
void rectld_setPosVec2(rectld_t * obj, const vec2ld_t * pos){
  rectld_setPos(obj,vecld_X(pos),vecld_Y(pos));
}

// moveVec2()
void rectu8_moveVec2(rectu8_t * obj, const vec2int8_t * delta){
  rectu8_move(obj,vec2u8_X(delta),vec2u8_Y(delta));
}
void recti8_moveVec2(recti8_t * obj, const vec2int8_t * delta){
  recti8_move(obj,vec2i8_X(delta),vec2i8_Y(delta));
}
void rectu16_moveVec2(rectu16_t * obj, const vec2int16_t * delta){
  rectu16_move(obj,vec2u16_X(delta),vec2u16_Y(delta));
}
void recti16_moveVec2(recti16_t * obj, const vec2int16_t * delta){
  recti16_move(obj,vec2i16_X(delta),vec2i16_Y(delta));
}
void rectu32_moveVec2(rectu32_t * obj, const vec2int32_t * delta){
  recu32t_move(obj,vec2u32_X(delta),vec2u32_Y(delta));
}
void recti32_moveVec2(recti32_t * obj, const vec2int32_t * delta){
  recti32_move(obj,vec2i32_X(delta),vec2i32_Y(delta));
}
void rectu64_moveVec2(rectu64_t * obj, const vec2int64_t * delta){
  rectu64_move(obj,vec2u64_X(delta),vec2u64_Y(delta));
}
void recti64_moveVec2(recti64_t * obj, const vec2int64_t * delta){
  recti64_move(obj,vec2i64_X(delta),vec2i64_Y(delta));
}
void rectf_moveVec2(rectf_t * obj, const vec2f_t * delta){
  rectf_move(obj,vecf_X(delta),vecf_Y(delta));
}
void rectd_moveVec2(rectd_t * obj, const vec2d_t * delta){
  rectd_move(obj,vecd_X(delta),vecd_Y(delta));
}
void rectld_moveVec2(rectld_t * obj, const vec2ld_t * delta){
  rectld_move(obj,vecld_X(delta),vecld_Y(delta));
}

// resizeVec2()
void rectu8_resizeVec2(rectu8_t * obj, const vec2uint8_t * delta){
  rectu8_resize(obj,vec2u8_X(delta),vec2u8_Y(delta));
}
void recti8_resizeVec2(recti8_t * obj, const vec2int8_t * delta){
  recti8_resize(obj,vec2i8_X(delta),vec2i8_Y(delta));
}
void rectu16_resizeVec2(rectu16_t * obj, const vec2uint16_t * delta){
  rectu16_resize(obj,vec2u16_X(delta),vec2u16_Y(delta));
}
void recti16_resizeVec2(recti16_t * obj, const vec2int16_t * delta){
  recti16_resize(obj,vec2i16_X(delta),vec2i16_Y(delta));
}
void rectu32_resizeVec2(rectu32_t * obj, const vec2uint32_t * delta){
  recu32t_resize(obj,vec2u32_X(delta),vec2u32_Y(delta));
}
void recti32_resizeVec2(recti32_t * obj, const vec2int32_t * delta){
  recti32_resize(obj,vec2i32_X(delta),vec2i32_Y(delta));
}
void rectu64_resizeVec2(rectu64_t * obj, const vec2uint64_t * delta){
  rectu64_resize(obj,vec2u64_X(delta),vec2u64_Y(delta));
}
void recti64_resizeVec2(recti64_t * obj, const vec2int64_t * delta){
  recti64_resize(obj,vec2i64_X(delta),vec2i64_Y(delta));
}
void rectf_resizeVec2(rectf_t * obj, const vec2f_t * delta){
  rectf_resize(obj,vecf_X(delta),vecf_Y(delta));
}
void rectd_resizeVec2(rectd_t * obj, const vec2d_t * delta){
  rectd_resize(obj,vecd_X(delta),vecd_Y(delta));
}
void rectld_resizeVec2(rectld_t * obj, const vec2ld_t * delta){
  rectld_resize(obj,vecld_X(delta),vecld_Y(delta));
}


#endif



// Collision detection functions
bool rectu8_collides(const rectu8_t* obj, const rectu8_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Calculate edges
    uint8_t obj_right = rectu8_getSideX(obj);
    uint8_t obj_bottom = rectu8_getSideY(obj);
    uint8_t other_right = rectu8_getSideX(other);
    uint8_t other_bottom = rectu8_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

bool recti8_collides(const recti8_t* obj, const recti8_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Calculate edges
    int8_t obj_right = recti8_getSideX(obj);
    int8_t obj_bottom = recti8_getSideY(obj);
    int8_t other_right = recti8_getSideX(other);
    int8_t other_bottom = recti8_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

bool rectu16_collides(const rectu16_t* obj, const rectu16_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Calculate edges
    uint16_t obj_right = rectu16_getSideX(obj);
    uint16_t obj_bottom = rectu16_getSideY(obj);
    uint16_t other_right = rectu16_getSideX(other);
    uint16_t other_bottom = rectu16_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

bool recti16_collides(const recti16_t* obj, const recti16_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Calculate edges
    int16_t obj_right = recti16_getSideX(obj);
    int16_t obj_bottom = recti16_getSideY(obj);
    int16_t other_right = recti16_getSideX(other);
    int16_t other_bottom = recti16_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

bool rectu32_collides(const rectu32_t* obj, const rectu32_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Calculate edges
    uint32_t obj_right = rectu32_getSideX(obj);
    uint32_t obj_bottom = rectu32_getSideY(obj);
    uint32_t other_right = rectu32_getSideX(other);
    uint32_t other_bottom = rectu32_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

bool recti32_collides(const recti32_t* obj, const recti32_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Calculate edges
    int32_t obj_right = recti32_getSideX(obj);
    int32_t obj_bottom = recti32_getSideY(obj);
    int32_t other_right = recti32_getSideX(other);
    int32_t other_bottom = recti32_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

bool rectu64_collides(const rectu64_t* obj, const rectu64_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Calculate edges
    uint64_t obj_right = rectu64_getSideX(obj);
    uint64_t obj_bottom = rectu64_getSideY(obj);
    uint64_t other_right = rectu64_getSideX(other);
    uint64_t other_bottom = rectu64_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

bool recti64_collides(const recti64_t* obj, const recti64_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Calculate edges
    int64_t obj_right = recti64_getSideX(obj);
    int64_t obj_bottom = recti64_getSideY(obj);
    int64_t other_right = recti64_getSideX(other);
    int64_t other_bottom = recti64_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

bool rectf_collides(const rectf_t* obj, const rectf_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(other->_posx) || isnan(other->_posy) || isnan(other->_width) || isnan(other->_height) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(other->_posx) || isinf(other->_posy) || isinf(other->_width) || isinf(other->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NaN or infinite values");
        return false;
    }

    // Calculate edges
    float obj_right = rectf_getSideX(obj);
    float obj_bottom = rectf_getSideY(obj);
    float other_right = rectf_getSideX(other);
    float other_bottom = rectf_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

bool rectd_collides(const rectd_t* obj, const rectd_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(other->_posx) || isnan(other->_posy) || isnan(other->_width) || isnan(other->_height) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(other->_posx) || isinf(other->_posy) || isinf(other->_width) || isinf(other->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NaN or infinite values");
        return false;
    }

    // Calculate edges
    double obj_right = rectd_getSideX(obj);
    double obj_bottom = rectd_getSideY(obj);
    double other_right = rectd_getSideX(other);
    double other_bottom = rectd_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

bool rectld_collides(const rectld_t* obj, const rectld_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NULL rectangle object");
        return false;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(other->_posx) || isnan(other->_posy) || isnan(other->_width) || isnan(other->_height) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(other->_posx) || isinf(other->_posy) || isinf(other->_width) || isinf(other->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check collision with NaN or infinite values");
        return false;
    }

    // Calculate edges
    long double obj_right = rectld_getSideX(obj);
    long double obj_bottom = rectld_getSideY(obj);
    long double other_right = rectld_getSideX(other);
    long double other_bottom = rectld_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check for collision
    bool collision = (obj->_posx < other_right &&
                     obj_right > other->_posx &&
                     obj->_posy < other_bottom &&
                     obj_bottom > other->_posy);

    return collision;
}

// Contains point functions
bool rectu8_contains_point(const rectu8_t* obj, uint8_t x, uint8_t y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Calculate edges
    uint8_t right = rectu8_getSideX(obj);
    uint8_t bottom = rectu8_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

bool recti8_contains_point(const recti8_t* obj, int8_t x, int8_t y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Calculate edges
    int8_t right = recti8_getSideX(obj);
    int8_t bottom = recti8_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

bool rectu16_contains_point(const rectu16_t* obj, uint16_t x, uint16_t y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Calculate edges
    uint16_t right = rectu16_getSideX(obj);
    uint16_t bottom = rectu16_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

bool recti16_contains_point(const recti16_t* obj, int16_t x, int16_t y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Calculate edges
    int16_t right = recti16_getSideX(obj);
    int16_t bottom = recti16_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

bool rectu32_contains_point(const rectu32_t* obj, uint32_t x, uint32_t y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Calculate edges
    uint32_t right = rectu32_getSideX(obj);
    uint32_t bottom = rectu32_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

bool recti32_contains_point(const recti32_t* obj, int32_t x, int32_t y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Calculate edges
    int32_t right = recti32_getSideX(obj);
    int32_t bottom = recti32_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

bool rectu64_contains_point(const rectu64_t* obj, uint64_t x, uint64_t y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Calculate edges
    uint64_t right = rectu64_getSideX(obj);
    uint64_t bottom = rectu64_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

bool recti64_contains_point(const recti64_t* obj, int64_t x, int64_t y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Calculate edges
    int64_t right = recti64_getSideX(obj);
    int64_t bottom = recti64_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

bool rectf_contains_point(const rectf_t* obj, float x, float y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Check for NaN or infinity in rectangle or point
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(x) || isnan(y) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(x) || isinf(y)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point with NaN or infinite values");
        return false;
    }

    // Calculate edges
    float right = rectf_getSideX(obj);
    float bottom = rectf_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

bool rectd_contains_point(const rectd_t* obj, double x, double y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Check for NaN or infinity in rectangle or point
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(x) || isnan(y) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(x) || isinf(y)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point with NaN or infinite values");
        return false;
    }

    // Calculate edges
    double right = rectd_getSideX(obj);
    double bottom = rectd_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

bool rectld_contains_point(const rectld_t* obj, long double x, long double y) {
    if (obj == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point in NULL rectangle object");
        return false;
    }

    // Check for NaN or infinity in rectangle or point
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(x) || isnan(y) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(x) || isinf(y)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check point with NaN or infinite values");
        return false;
    }

    // Calculate edges
    long double right = rectld_getSideX(obj);
    long double bottom = rectld_getSideY(obj);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if point is inside rectangle (inclusive of edges)
    bool contains = (x >= obj->_posx && x <= right &&
                    y >= obj->_posy && y <= bottom);

    return contains;
}

// Contains rectangle functions
bool rectu8_contains_rect(const rectu8_t* obj, const rectu8_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Calculate edges of both rectangles
    uint8_t obj_right = rectu8_getSideX(obj);
    uint8_t obj_bottom = rectu8_getSideY(obj);
    uint8_t other_right = rectu8_getSideX(other);
    uint8_t other_bottom = rectu8_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

bool recti8_contains_rect(const recti8_t* obj, const recti8_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Calculate edges of both rectangles
    int8_t obj_right = recti8_getSideX(obj);
    int8_t obj_bottom = recti8_getSideY(obj);
    int8_t other_right = recti8_getSideX(other);
    int8_t other_bottom = recti8_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

bool rectu16_contains_rect(const rectu16_t* obj, const rectu16_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Calculate edges of both rectangles
    uint16_t obj_right = rectu16_getSideX(obj);
    uint16_t obj_bottom = rectu16_getSideY(obj);
    uint16_t other_right = rectu16_getSideX(other);
    uint16_t other_bottom = rectu16_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

bool recti16_contains_rect(const recti16_t* obj, const recti16_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Calculate edges of both rectangles
    int16_t obj_right = recti16_getSideX(obj);
    int16_t obj_bottom = recti16_getSideY(obj);
    int16_t other_right = recti16_getSideX(other);
    int16_t other_bottom = recti16_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

bool rectu32_contains_rect(const rectu32_t* obj, const rectu32_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Calculate edges of both rectangles
    uint32_t obj_right = rectu32_getSideX(obj);
    uint32_t obj_bottom = rectu32_getSideY(obj);
    uint32_t other_right = rectu32_getSideX(other);
    uint32_t other_bottom = rectu32_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

bool recti32_contains_rect(const recti32_t* obj, const recti32_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Calculate edges of both rectangles
    int32_t obj_right = recti32_getSideX(obj);
    int32_t obj_bottom = recti32_getSideY(obj);
    int32_t other_right = recti32_getSideX(other);
    int32_t other_bottom = recti32_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

bool rectu64_contains_rect(const rectu64_t* obj, const rectu64_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Calculate edges of both rectangles
    uint64_t obj_right = rectu64_getSideX(obj);
    uint64_t obj_bottom = rectu64_getSideY(obj);
    uint64_t other_right = rectu64_getSideX(other);
    uint64_t other_bottom = rectu64_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

bool recti64_contains_rect(const recti64_t* obj, const recti64_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Calculate edges of both rectangles
    int64_t obj_right = recti64_getSideX(obj);
    int64_t obj_bottom = recti64_getSideY(obj);
    int64_t other_right = recti64_getSideX(other);
    int64_t other_bottom = recti64_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

bool rectf_contains_rect(const rectf_t* obj, const rectf_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(other->_posx) || isnan(other->_posy) || isnan(other->_width) || isnan(other->_height) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(other->_posx) || isinf(other->_posy) || isinf(other->_width) || isinf(other->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NaN or infinite values");
        return false;
    }

    // Calculate edges of both rectangles
    float obj_right = rectf_getSideX(obj);
    float obj_bottom = rectf_getSideY(obj);
    float other_right = rectf_getSideX(other);
    float other_bottom = rectf_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

bool rectd_contains_rect(const rectd_t* obj, const rectd_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(other->_posx) || isnan(other->_posy) || isnan(other->_width) || isnan(other->_height) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(other->_posx) || isinf(other->_posy) || isinf(other->_width) || isinf(other->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NaN or infinite values");
        return false;
    }

    // Calculate edges of both rectangles
    double obj_right = rectd_getSideX(obj);
    double obj_bottom = rectd_getSideY(obj);
    double other_right = rectd_getSideX(other);
    double other_bottom = rectd_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

bool rectld_contains_rect(const rectld_t* obj, const rectld_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NULL rectangle object");
        return false;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(other->_posx) || isnan(other->_posy) || isnan(other->_width) || isnan(other->_height) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(other->_posx) || isinf(other->_posy) || isinf(other->_width) || isinf(other->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot check containment with NaN or infinite values");
        return false;
    }

    // Calculate edges of both rectangles
    long double obj_right = rectld_getSideX(obj);
    long double obj_bottom = rectld_getSideY(obj);
    long double other_right = rectld_getSideX(other);
    long double other_bottom = rectld_getSideY(other);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Check if obj completely contains other
    bool contains = (other->_posx >= obj->_posx &&
                    other_right <= obj_right &&
                    other->_posy >= obj->_posy &&
                    other_bottom <= obj_bottom);

    return contains;
}

// Intersection functions
bool rectu8_intersection(const rectu8_t* left, const rectu8_t* right, rectu8_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Calculate edges
    uint8_t left_right = rectu8_getSideX(left);
    uint8_t left_bottom = rectu8_getSideY(left);
    uint8_t right_right = rectu8_getSideX(right);
    uint8_t right_bottom = rectu8_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    uint8_t inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    uint8_t inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    uint8_t inter_right = (left_right < right_right) ? left_right : right_right;
    uint8_t inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

bool recti8_intersection(const recti8_t* left, const recti8_t* right, recti8_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Calculate edges
    int8_t left_right = recti8_getSideX(left);
    int8_t left_bottom = recti8_getSideY(left);
    int8_t right_right = recti8_getSideX(right);
    int8_t right_bottom = recti8_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    int8_t inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    int8_t inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    int8_t inter_right = (left_right < right_right) ? left_right : right_right;
    int8_t inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

bool rectu16_intersection(const rectu16_t* left, const rectu16_t* right, rectu16_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Calculate edges
    uint16_t left_right = rectu16_getSideX(left);
    uint16_t left_bottom = rectu16_getSideY(left);
    uint16_t right_right = rectu16_getSideX(right);
    uint16_t right_bottom = rectu16_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    uint16_t inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    uint16_t inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    uint16_t inter_right = (left_right < right_right) ? left_right : right_right;
    uint16_t inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

bool recti16_intersection(const recti16_t* left, const recti16_t* right, recti16_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Calculate edges
    int16_t left_right = recti16_getSideX(left);
    int16_t left_bottom = recti16_getSideY(left);
    int16_t right_right = recti16_getSideX(right);
    int16_t right_bottom = recti16_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    int16_t inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    int16_t inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    int16_t inter_right = (left_right < right_right) ? left_right : right_right;
    int16_t inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

bool rectu32_intersection(const rectu32_t* left, const rectu32_t* right, rectu32_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Calculate edges
    uint32_t left_right = rectu32_getSideX(left);
    uint32_t left_bottom = rectu32_getSideY(left);
    uint32_t right_right = rectu32_getSideX(right);
    uint32_t right_bottom = rectu32_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    uint32_t inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    uint32_t inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    uint32_t inter_right = (left_right < right_right) ? left_right : right_right;
    uint32_t inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

bool recti32_intersection(const recti32_t* left, const recti32_t* right, recti32_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Calculate edges
    int32_t left_right = recti32_getSideX(left);
    int32_t left_bottom = recti32_getSideY(left);
    int32_t right_right = recti32_getSideX(right);
    int32_t right_bottom = recti32_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    int32_t inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    int32_t inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    int32_t inter_right = (left_right < right_right) ? left_right : right_right;
    int32_t inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

bool rectu64_intersection(const rectu64_t* left, const rectu64_t* right, rectu64_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Calculate edges
    uint64_t left_right = rectu64_getSideX(left);
    uint64_t left_bottom = rectu64_getSideY(left);
    uint64_t right_right = rectu64_getSideX(right);
    uint64_t right_bottom = rectu64_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    uint64_t inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    uint64_t inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    uint64_t inter_right = (left_right < right_right) ? left_right : right_right;
    uint64_t inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

bool recti64_intersection(const recti64_t* left, const recti64_t* right, recti64_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Calculate edges
    int64_t left_right = recti64_getSideX(left);
    int64_t left_bottom = recti64_getSideY(left);
    int64_t right_right = recti64_getSideX(right);
    int64_t right_bottom = recti64_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    int64_t inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    int64_t inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    int64_t inter_right = (left_right < right_right) ? left_right : right_right;
    int64_t inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

bool rectf_intersection(const rectf_t* left, const rectf_t* right, rectf_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(left->_posx) || isnan(left->_posy) || isnan(left->_width) || isnan(left->_height) ||
        isnan(right->_posx) || isnan(right->_posy) || isnan(right->_width) || isnan(right->_height) ||
        isinf(left->_posx) || isinf(left->_posy) || isinf(left->_width) || isinf(left->_height) ||
        isinf(right->_posx) || isinf(right->_posy) || isinf(right->_width) || isinf(right->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NaN or infinite values");
        return false;
    }

    // Calculate edges
    float left_right = rectf_getSideX(left);
    float left_bottom = rectf_getSideY(left);
    float right_right = rectf_getSideX(right);
    float right_bottom = rectf_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    float inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    float inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    float inter_right = (left_right < right_right) ? left_right : right_right;
    float inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

bool rectd_intersection(const rectd_t* left, const rectd_t* right, rectd_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(left->_posx) || isnan(left->_posy) || isnan(left->_width) || isnan(left->_height) ||
        isnan(right->_posx) || isnan(right->_posy) || isnan(right->_width) || isnan(right->_height) ||
        isinf(left->_posx) || isinf(left->_posy) || isinf(left->_width) || isinf(left->_height) ||
        isinf(right->_posx) || isinf(right->_posy) || isinf(right->_width) || isinf(right->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NaN or infinite values");
        return false;
    }

    // Calculate edges
    double left_right = rectd_getSideX(left);
    double left_bottom = rectd_getSideY(left);
    double right_right = rectd_getSideX(right);
    double right_bottom = rectd_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    double inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    double inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    double inter_right = (left_right < right_right) ? left_right : right_right;
    double inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

bool rectld_intersection(const rectld_t* left, const rectld_t* right, rectld_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NULL rectangle objects");
        return false;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(left->_posx) || isnan(left->_posy) || isnan(left->_width) || isnan(left->_height) ||
        isnan(right->_posx) || isnan(right->_posy) || isnan(right->_width) || isnan(right->_height) ||
        isinf(left->_posx) || isinf(left->_posy) || isinf(left->_width) || isinf(left->_height) ||
        isinf(right->_posx) || isinf(right->_posy) || isinf(right->_width) || isinf(right->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate intersection with NaN or infinite values");
        return false;
    }

    // Calculate edges
    long double left_right = rectld_getSideX(left);
    long double left_bottom = rectld_getSideY(left);
    long double right_right = rectld_getSideX(right);
    long double right_bottom = rectld_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return false;
    }

    // Calculate intersection
    long double inter_x = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    long double inter_y = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    long double inter_right = (left_right < right_right) ? left_right : right_right;
    long double inter_bottom = (left_bottom < right_bottom) ? left_bottom : right_bottom;

    // Check if intersection is valid
    if (inter_x >= inter_right || inter_y >= inter_bottom) {
        // No intersection
        return false;
    }

    // Set result
    result->_posx = inter_x;
    result->_posy = inter_y;
    result->_width = inter_right - inter_x;
    result->_height = inter_bottom - inter_y;

    return true;
}

// Union functions
void rectu8_union(const rectu8_t* left, const rectu8_t* right, rectu8_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Calculate edges
    uint8_t left_right = rectu8_getSideX(left);
    uint8_t left_bottom = rectu8_getSideY(left);
    uint8_t right_right = rectu8_getSideX(right);
    uint8_t right_bottom = rectu8_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    uint8_t union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    uint8_t union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    uint8_t union_right = (left_right > right_right) ? left_right : right_right;
    uint8_t union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

void recti8_union(const recti8_t* left, const recti8_t* right, recti8_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Calculate edges
    int8_t left_right = recti8_getSideX(left);
    int8_t left_bottom = recti8_getSideY(left);
    int8_t right_right = recti8_getSideX(right);
    int8_t right_bottom = recti8_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    int8_t union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    int8_t union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    int8_t union_right = (left_right > right_right) ? left_right : right_right;
    int8_t union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

void rectu16_union(const rectu16_t* left, const rectu16_t* right, rectu16_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Calculate edges
    uint16_t left_right = rectu16_getSideX(left);
    uint16_t left_bottom = rectu16_getSideY(left);
    uint16_t right_right = rectu16_getSideX(right);
    uint16_t right_bottom = rectu16_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    uint16_t union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    uint16_t union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    uint16_t union_right = (left_right > right_right) ? left_right : right_right;
    uint16_t union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

void recti16_union(const recti16_t* left, const recti16_t* right, recti16_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Calculate edges
    int16_t left_right = recti16_getSideX(left);
    int16_t left_bottom = recti16_getSideY(left);
    int16_t right_right = recti16_getSideX(right);
    int16_t right_bottom = recti16_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    int16_t union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    int16_t union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    int16_t union_right = (left_right > right_right) ? left_right : right_right;
    int16_t union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

void rectu32_union(const rectu32_t* left, const rectu32_t* right, rectu32_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Calculate edges
    uint32_t left_right = rectu32_getSideX(left);
    uint32_t left_bottom = rectu32_getSideY(left);
    uint32_t right_right = rectu32_getSideX(right);
    uint32_t right_bottom = rectu32_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    uint32_t union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    uint32_t union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    uint32_t union_right = (left_right > right_right) ? left_right : right_right;
    uint32_t union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

void recti32_union(const recti32_t* left, const recti32_t* right, recti32_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Calculate edges
    int32_t left_right = recti32_getSideX(left);
    int32_t left_bottom = recti32_getSideY(left);
    int32_t right_right = recti32_getSideX(right);
    int32_t right_bottom = recti32_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    int32_t union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    int32_t union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    int32_t union_right = (left_right > right_right) ? left_right : right_right;
    int32_t union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

void rectu64_union(const rectu64_t* left, const rectu64_t* right, rectu64_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Calculate edges
    uint64_t left_right = rectu64_getSideX(left);
    uint64_t left_bottom = rectu64_getSideY(left);
    uint64_t right_right = rectu64_getSideX(right);
    uint64_t right_bottom = rectu64_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    uint64_t union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    uint64_t union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    uint64_t union_right = (left_right > right_right) ? left_right : right_right;
    uint64_t union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

void recti64_union(const recti64_t* left, const recti64_t* right, recti64_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Calculate edges
    int64_t left_right = recti64_getSideX(left);
    int64_t left_bottom = recti64_getSideY(left);
    int64_t right_right = recti64_getSideX(right);
    int64_t right_bottom = recti64_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    int64_t union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    int64_t union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    int64_t union_right = (left_right > right_right) ? left_right : right_right;
    int64_t union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

void rectf_union(const rectf_t* left, const rectf_t* right, rectf_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(left->_posx) || isnan(left->_posy) || isnan(left->_width) || isnan(left->_height) ||
        isnan(right->_posx) || isnan(right->_posy) || isnan(right->_width) || isnan(right->_height) ||
        isinf(left->_posx) || isinf(left->_posy) || isinf(left->_width) || isinf(left->_height) ||
        isinf(right->_posx) || isinf(right->_posy) || isinf(right->_width) || isinf(right->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NaN or infinite values");
        return;
    }

    // Calculate edges
    float left_right = rectf_getSideX(left);
    float left_bottom = rectf_getSideY(left);
    float right_right = rectf_getSideX(right);
    float right_bottom = rectf_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    float union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    float union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    float union_right = (left_right > right_right) ? left_right : right_right;
    float union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

void rectd_union(const rectd_t* left, const rectd_t* right, rectd_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(left->_posx) || isnan(left->_posy) || isnan(left->_width) || isnan(left->_height) ||
        isnan(right->_posx) || isnan(right->_posy) || isnan(right->_width) || isnan(right->_height) ||
        isinf(left->_posx) || isinf(left->_posy) || isinf(left->_width) || isinf(left->_height) ||
        isinf(right->_posx) || isinf(right->_posy) || isinf(right->_width) || isinf(right->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NaN or infinite values");
        return;
    }

    // Calculate edges
    double left_right = rectd_getSideX(left);
    double left_bottom = rectd_getSideY(left);
    double right_right = rectd_getSideX(right);
    double right_bottom = rectd_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    double union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    double union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    double union_right = (left_right > right_right) ? left_right : right_right;
    double union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

void rectld_union(const rectld_t* left, const rectld_t* right, rectld_t* result) {
    if (left == NULL || right == NULL || result == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NULL rectangle objects");
        return;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(left->_posx) || isnan(left->_posy) || isnan(left->_width) || isnan(left->_height) ||
        isnan(right->_posx) || isnan(right->_posy) || isnan(right->_width) || isnan(right->_height) ||
        isinf(left->_posx) || isinf(left->_posy) || isinf(left->_width) || isinf(left->_height) ||
        isinf(right->_posx) || isinf(right->_posy) || isinf(right->_width) || isinf(right->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot calculate union with NaN or infinite values");
        return;
    }

    // Calculate edges
    long double left_right = rectld_getSideX(left);
    long double left_bottom = rectld_getSideY(left);
    long double right_right = rectld_getSideX(right);
    long double right_bottom = rectld_getSideY(right);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Calculate union (bounding box)
    long double union_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    long double union_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    long double union_right = (left_right > right_right) ? left_right : right_right;
    long double union_bottom = (left_bottom > right_bottom) ? left_bottom : right_bottom;

    // Set result
    result->_posx = union_x;
    result->_posy = union_y;
    result->_width = union_right - union_x;
    result->_height = union_bottom - union_y;
}

// Clamp functions
void rectu8_clamp(rectu8_t* obj, const rectu8_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Calculate edges
    uint8_t obj_right = rectu8_getSideX(obj);
    uint8_t obj_bottom = rectu8_getSideY(obj);
    uint8_t bounds_right = rectu8_getSideX(bounds);
    uint8_t bounds_bottom = rectu8_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

void recti8_clamp(recti8_t* obj, const recti8_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Calculate edges
    int8_t obj_right = recti8_getSideX(obj);
    int8_t obj_bottom = recti8_getSideY(obj);
    int8_t bounds_right = recti8_getSideX(bounds);
    int8_t bounds_bottom = recti8_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

void rectu16_clamp(rectu16_t* obj, const rectu16_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Calculate edges
    uint16_t obj_right = rectu16_getSideX(obj);
    uint16_t obj_bottom = rectu16_getSideY(obj);
    uint16_t bounds_right = rectu16_getSideX(bounds);
    uint16_t bounds_bottom = rectu16_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

void recti16_clamp(recti16_t* obj, const recti16_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Calculate edges
    int16_t obj_right = recti16_getSideX(obj);
    int16_t obj_bottom = recti16_getSideY(obj);
    int16_t bounds_right = recti16_getSideX(bounds);
    int16_t bounds_bottom = recti16_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

void rectu32_clamp(rectu32_t* obj, const rectu32_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Calculate edges
    uint32_t obj_right = rectu32_getSideX(obj);
    uint32_t obj_bottom = rectu32_getSideY(obj);
    uint32_t bounds_right = rectu32_getSideX(bounds);
    uint32_t bounds_bottom = rectu32_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

void recti32_clamp(recti32_t* obj, const recti32_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Calculate edges
    int32_t obj_right = recti32_getSideX(obj);
    int32_t obj_bottom = recti32_getSideY(obj);
    int32_t bounds_right = recti32_getSideX(bounds);
    int32_t bounds_bottom = recti32_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

void rectu64_clamp(rectu64_t* obj, const rectu64_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Calculate edges
    uint64_t obj_right = rectu64_getSideX(obj);
    uint64_t obj_bottom = rectu64_getSideY(obj);
    uint64_t bounds_right = rectu64_getSideX(bounds);
    uint64_t bounds_bottom = rectu64_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

void recti64_clamp(recti64_t* obj, const recti64_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Calculate edges
    int64_t obj_right = recti64_getSideX(obj);
    int64_t obj_bottom = recti64_getSideY(obj);
    int64_t bounds_right = recti64_getSideX(bounds);
    int64_t bounds_bottom = recti64_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

void rectf_clamp(rectf_t* obj, const rectf_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(bounds->_posx) || isnan(bounds->_posy) || isnan(bounds->_width) || isnan(bounds->_height) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(bounds->_posx) || isinf(bounds->_posy) || isinf(bounds->_width) || isinf(bounds->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NaN or infinite values");
        return;
    }

    // Calculate edges
    float obj_right = rectf_getSideX(obj);
    float obj_bottom = rectf_getSideY(obj);
    float bounds_right = rectf_getSideX(bounds);
    float bounds_bottom = rectf_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0.0f;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0.0f;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

void rectd_clamp(rectd_t* obj, const rectd_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(bounds->_posx) || isnan(bounds->_posy) || isnan(bounds->_width) || isnan(bounds->_height) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(bounds->_posx) || isinf(bounds->_posy) || isinf(bounds->_width) || isinf(bounds->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NaN or infinite values");
        return;
    }

    // Calculate edges
    double obj_right = rectd_getSideX(obj);
    double obj_bottom = rectd_getSideY(obj);
    double bounds_right = rectd_getSideX(bounds);
    double bounds_bottom = rectd_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0.0;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0.0;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

void rectld_clamp(rectld_t* obj, const rectld_t* bounds) {
    if (obj == NULL || bounds == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NULL rectangle objects");
        return;
    }

    // Check for NaN or infinity in either rectangle
    if (isnan(obj->_posx) || isnan(obj->_posy) || isnan(obj->_width) || isnan(obj->_height) ||
        isnan(bounds->_posx) || isnan(bounds->_posy) || isnan(bounds->_width) || isnan(bounds->_height) ||
        isinf(obj->_posx) || isinf(obj->_posy) || isinf(obj->_width) || isinf(obj->_height) ||
        isinf(bounds->_posx) || isinf(bounds->_posy) || isinf(bounds->_width) || isinf(bounds->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot clamp with NaN or infinite values");
        return;
    }

    // Calculate edges
    long double obj_right = rectld_getSideX(obj);
    long double obj_bottom = rectld_getSideY(obj);
    long double bounds_right = rectld_getSideX(bounds);
    long double bounds_bottom = rectld_getSideY(bounds);

    // Check if any error occurred during side calculations
    if (rect_get_error() != RECT_SUCCESS) {
        return;
    }

    // Clamp position to bounds
    if (obj->_posx < bounds->_posx) {
        obj->_posx = bounds->_posx;
    }
    if (obj->_posy < bounds->_posy) {
        obj->_posy = bounds->_posy;
    }

    // Clamp right and bottom edges to bounds
    if (obj_right > bounds_right) {
        if (bounds_right < obj->_posx) {
            // Rectangle is completely outside bounds on the right
            obj->_posx = bounds_right;
            obj->_width = 0.0L;
        } else {
            obj->_width = bounds_right - obj->_posx;
        }
    }
    if (obj_bottom > bounds_bottom) {
        if (bounds_bottom < obj->_posy) {
            // Rectangle is completely outside bounds on the bottom
            obj->_posy = bounds_bottom;
            obj->_height = 0.0L;
        } else {
            obj->_height = bounds_bottom - obj->_posy;
        }
    }
}

// Equality functions
bool rectu8_equals(const rectu8_t* obj, const rectu8_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_width == other->_width &&
            obj->_height == other->_height);
}

bool recti8_equals(const recti8_t* obj, const recti8_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_width == other->_width &&
            obj->_height == other->_height);
}

bool rectu16_equals(const rectu16_t* obj, const rectu16_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_width == other->_width &&
            obj->_height == other->_height);
}

bool recti16_equals(const recti16_t* obj, const recti16_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_width == other->_width &&
            obj->_height == other->_height);
}

bool rectu32_equals(const rectu32_t* obj, const rectu32_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_width == other->_width &&
            obj->_height == other->_height);
}

bool recti32_equals(const recti32_t* obj, const recti32_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_width == other->_width &&
            obj->_height == other->_height);
}

bool rectu64_equals(const rectu64_t* obj, const rectu64_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_width == other->_width &&
            obj->_height == other->_height);
}

bool recti64_equals(const recti64_t* obj, const recti64_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_width == other->_width &&
            obj->_height == other->_height);
}

bool rectf_equals(const rectf_t* obj, const rectf_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    // Check for NaN values - two NaN values should be considered equal
    bool obj_x_nan = isnan(obj->_posx);
    bool obj_y_nan = isnan(obj->_posy);
    bool obj_width_nan = isnan(obj->_width);
    bool obj_height_nan = isnan(obj->_height);

    bool other_x_nan = isnan(other->_posx);
    bool other_y_nan = isnan(other->_posy);
    bool other_width_nan = isnan(other->_width);
    bool other_height_nan = isnan(other->_height);

    // If both have NaN in the same field, consider them equal for that field
    bool x_equal = (obj_x_nan && other_x_nan) || (obj->_posx == other->_posx);
    bool y_equal = (obj_y_nan && other_y_nan) || (obj->_posy == other->_posy);
    bool width_equal = (obj_width_nan && other_width_nan) || (obj->_width == other->_width);
    bool height_equal = (obj_height_nan && other_height_nan) || (obj->_height == other->_height);

    return (x_equal && y_equal && width_equal && height_equal);
}

bool rectd_equals(const rectd_t* obj, const rectd_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    // Check for NaN values - two NaN values should be considered equal
    bool obj_x_nan = isnan(obj->_posx);
    bool obj_y_nan = isnan(obj->_posy);
    bool obj_width_nan = isnan(obj->_width);
    bool obj_height_nan = isnan(obj->_height);

    bool other_x_nan = isnan(other->_posx);
    bool other_y_nan = isnan(other->_posy);
    bool other_width_nan = isnan(other->_width);
    bool other_height_nan = isnan(other->_height);

    // If both have NaN in the same field, consider them equal for that field
    bool x_equal = (obj_x_nan && other_x_nan) || (obj->_posx == other->_posx);
    bool y_equal = (obj_y_nan && other_y_nan) || (obj->_posy == other->_posy);
    bool width_equal = (obj_width_nan && other_width_nan) || (obj->_width == other->_width);
    bool height_equal = (obj_height_nan && other_height_nan) || (obj->_height == other->_height);

    return (x_equal && y_equal && width_equal && height_equal);
}

bool rectld_equals(const rectld_t* obj, const rectld_t* other) {
    if (obj == NULL || other == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot compare NULL rectangle objects");
        return false;
    }

    // Check for NaN values - two NaN values should be considered equal
    bool obj_x_nan = isnan(obj->_posx);
    bool obj_y_nan = isnan(obj->_posy);
    bool obj_width_nan = isnan(obj->_width);
    bool obj_height_nan = isnan(obj->_height);

    bool other_x_nan = isnan(other->_posx);
    bool other_y_nan = isnan(other->_posy);
    bool other_width_nan = isnan(other->_width);
    bool other_height_nan = isnan(other->_height);

    // If both have NaN in the same field, consider them equal for that field
    bool x_equal = (obj_x_nan && other_x_nan) || (obj->_posx == other->_posx);
    bool y_equal = (obj_y_nan && other_y_nan) || (obj->_posy == other->_posy);
    bool width_equal = (obj_width_nan && other_width_nan) || (obj->_width == other->_width);
    bool height_equal = (obj_height_nan && other_height_nan) || (obj->_height == other->_height);

    return (x_equal && y_equal && width_equal && height_equal);
}

// Print functions
void rectu8_print(const rectu8_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %u, y: %u, width: %u, height: %u)\n",
           obj->_posx, obj->_posy, obj->_width, obj->_height);
}

void recti8_print(const recti8_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %d, y: %d, width: %d, height: %d)\n",
           obj->_posx, obj->_posy, obj->_width, obj->_height);
}

void rectu16_print(const rectu16_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %u, y: %u, width: %u, height: %u)\n",
           obj->_posx, obj->_posy, obj->_width, obj->_height);
}

void recti16_print(const recti16_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %d, y: %d, width: %d, height: %d)\n",
           obj->_posx, obj->_posy, obj->_width, obj->_height);
}

void rectu32_print(const rectu32_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %u, y: %u, width: %u, height: %u)\n",
           obj->_posx, obj->_posy, obj->_width, obj->_height);
}

void recti32_print(const recti32_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %d, y: %d, width: %d, height: %d)\n",
           obj->_posx, obj->_posy, obj->_width, obj->_height);
}

void rectu64_print(const rectu64_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %llu, y: %llu, width: %llu, height: %llu)\n",
           (unsigned long long)obj->_posx,
           (unsigned long long)obj->_posy,
           (unsigned long long)obj->_width,
           (unsigned long long)obj->_height);
}

void recti64_print(const recti64_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %lld, y: %lld, width: %lld, height: %lld)\n",
           (long long)obj->_posx,
           (long long)obj->_posy,
           (long long)obj->_width,
           (long long)obj->_height);
}

void rectf_print(const rectf_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %.6f, y: %.6f, width: %.6f, height: %.6f)\n",
           obj->_posx, obj->_posy, obj->_width, obj->_height);
}

void rectd_print(const rectd_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %.6f, y: %.6f, width: %.6f, height: %.6f)\n",
           obj->_posx, obj->_posy, obj->_width, obj->_height);
}

void rectld_print(const rectld_t* obj) {
    if (obj == NULL) {
        printf("Rect (NULL)\n");
        return;
    }
    printf("Rect (x: %.6Lf, y: %.6Lf, width: %.6Lf, height: %.6Lf)\n",
           obj->_posx, obj->_posy, obj->_width, obj->_height);
}


// getSize meta-function
size_t rectu8_size(void){
  return sizeof(rectu8_t);
}
size_t recti8_size(void){
  return sizeof(recti8_t);
}
size_t rectu16_size(void){
  return sizeof(rectu16_t);
}
size_t recti16_size(void){
  return sizeof(recti16_t);
}
size_t rectu32_size(void){
  return sizeof(rectu32_t);
}
size_t recti32_size(void){
  return sizeof(recti32_t);
}
size_t rectu64_size(void){
  return sizeof(rectu64_t);
}
size_t recti64_size(void){
  return sizeof(recti64_t);
}
size_t rectf_size(void){
  return sizeof(rectf_t);
}
size_t rectd_size(void){
  return sizeof(rectd_t);
}
size_t rectld_size(void){
  return sizeof(rectld_t);
}



// Serialization functions - convert rectangle to array
void rectu8_toArray(uint8_t* output, const rectu8_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

void recti8_toArray(int8_t* output, const recti8_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

void rectu16_toArray(uint16_t* output, const rectu16_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

void recti16_toArray(int16_t* output, const recti16_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

void rectu32_toArray(uint32_t* output, const rectu32_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

void recti32_toArray(int32_t* output, const recti32_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

void rectu64_toArray(uint64_t* output, const rectu64_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

void recti64_toArray(int64_t* output, const recti64_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

void rectf_toArray(float* output, const rectf_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    // Check for NaN or infinity in the source rectangle
    if (isnan(src->_posx) || isnan(src->_posy) || isnan(src->_width) || isnan(src->_height) ||
        isinf(src->_posx) || isinf(src->_posy) || isinf(src->_width) || isinf(src->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize rectangle with NaN or infinite values");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

void rectd_toArray(double* output, const rectd_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    // Check for NaN or infinity in the source rectangle
    if (isnan(src->_posx) || isnan(src->_posy) || isnan(src->_width) || isnan(src->_height) ||
        isinf(src->_posx) || isinf(src->_posy) || isinf(src->_width) || isinf(src->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize rectangle with NaN or infinite values");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

void rectld_toArray(long double* output, const rectld_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL rectangle or to NULL output");
        return;
    }

    // Check for NaN or infinity in the source rectangle
    if (isnan(src->_posx) || isnan(src->_posy) || isnan(src->_width) || isnan(src->_height) ||
        isinf(src->_posx) || isinf(src->_posy) || isinf(src->_width) || isinf(src->_height)) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize rectangle with NaN or infinite values");
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_width;
    output[3] = src->_height;
}

// Deserialization functions - convert array to rectangle
void rectu8_fromArray(rectu8_t* output, const uint8_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

void recti8_fromArray(recti8_t* output, const int8_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

void rectu16_fromArray(rectu16_t* output, const uint16_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

void recti16_fromArray(recti16_t* output, const int16_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

void rectu32_fromArray(rectu32_t* output, const uint32_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

void recti32_fromArray(recti32_t* output, const int32_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

void rectu64_fromArray(rectu64_t* output, const uint64_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

void recti64_fromArray(recti64_t* output, const int64_t* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

void rectf_fromArray(rectf_t* output, const float* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    // Check for NaN or infinity in the source array
    if (isnan(src[0]) || isnan(src[1]) || isnan(src[2]) || isnan(src[3]) ||
        isinf(src[0]) || isinf(src[1]) || isinf(src[2]) || isinf(src[3])) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize array with NaN or infinite values");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

void rectd_fromArray(rectd_t* output, const double* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    // Check for NaN or infinity in the source array
    if (isnan(src[0]) || isnan(src[1]) || isnan(src[2]) || isnan(src[3]) ||
        isinf(src[0]) || isinf(src[1]) || isinf(src[2]) || isinf(src[3])) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize array with NaN or infinite values");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

void rectld_fromArray(rectld_t* output, const long double* src) {
    if (output == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL array or to NULL rectangle");
        return;
    }

    // Check for NaN or infinity in the source array
    if (isnan(src[0]) || isnan(src[1]) || isnan(src[2]) || isnan(src[3]) ||
        isinf(src[0]) || isinf(src[1]) || isinf(src[2]) || isinf(src[3])) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize array with NaN or infinite values");
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_width = src[2];
    output->_height = src[3];
}

// Serialization functions for all rectangle types

// Native byte order (may vary by platform)
void rectu8_toBytes(const rectu8_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // For 8-bit types, native and LE are the same
    dst[0] = obj->_posx;
    dst[1] = obj->_posy;
    dst[2] = obj->_width;
    dst[3] = obj->_height;
}

void rectu8_toBytesLE(const rectu8_t* obj, uint8_t* dst) {
    rectu8_toBytes(obj, dst); // Same as native for 8-bit types
}

void recti8_toBytes(const recti8_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // For 8-bit types, native and LE are the same
    dst[0] = (uint8_t)obj->_posx;
    dst[1] = (uint8_t)obj->_posy;
    dst[2] = (uint8_t)obj->_width;
    dst[3] = (uint8_t)obj->_height;
}

void recti8_toBytesLE(const recti8_t* obj, uint8_t* dst) {
    recti8_toBytes(obj, dst); // Same as native for 8-bit types
}

// 16-bit types
void rectu16_toBytes(const rectu16_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(dst, &obj->_posx, sizeof(uint16_t));
    memcpy(dst + 2, &obj->_posy, sizeof(uint16_t));
    memcpy(dst + 4, &obj->_width, sizeof(uint16_t));
    memcpy(dst + 6, &obj->_height, sizeof(uint16_t));
}

void rectu16_toBytesLE(const rectu16_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Little-endian byte order
    dst[0] = (uint8_t)(obj->_posx & 0xFF);
    dst[1] = (uint8_t)((obj->_posx >> 8) & 0xFF);
    dst[2] = (uint8_t)(obj->_posy & 0xFF);
    dst[3] = (uint8_t)((obj->_posy >> 8) & 0xFF);
    dst[4] = (uint8_t)(obj->_width & 0xFF);
    dst[5] = (uint8_t)((obj->_width >> 8) & 0xFF);
    dst[6] = (uint8_t)(obj->_height & 0xFF);
    dst[7] = (uint8_t)((obj->_height >> 8) & 0xFF);
}

void recti16_toBytes(const recti16_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Convert to unsigned representation for consistent serialization
    uint16_t posx = (uint16_t)obj->_posx;
    uint16_t posy = (uint16_t)obj->_posy;
    uint16_t width = (uint16_t)obj->_width;
    uint16_t height = (uint16_t)obj->_height;

    // Native byte order (platform dependent)
    memcpy(dst, &posx, sizeof(uint16_t));
    memcpy(dst + 2, &posy, sizeof(uint16_t));
    memcpy(dst + 4, &width, sizeof(uint16_t));
    memcpy(dst + 6, &height, sizeof(uint16_t));
}

void recti16_toBytesLE(const recti16_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Convert to unsigned representation for consistent serialization
    uint16_t posx = (uint16_t)obj->_posx;
    uint16_t posy = (uint16_t)obj->_posy;
    uint16_t width = (uint16_t)obj->_width;
    uint16_t height = (uint16_t)obj->_height;

    // Little-endian byte order
    dst[0] = (uint8_t)(posx & 0xFF);
    dst[1] = (uint8_t)((posx >> 8) & 0xFF);
    dst[2] = (uint8_t)(posy & 0xFF);
    dst[3] = (uint8_t)((posy >> 8) & 0xFF);
    dst[4] = (uint8_t)(width & 0xFF);
    dst[5] = (uint8_t)((width >> 8) & 0xFF);
    dst[6] = (uint8_t)(height & 0xFF);
    dst[7] = (uint8_t)((height >> 8) & 0xFF);
}

// 32-bit types
void rectu32_toBytes(const rectu32_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(dst, &obj->_posx, sizeof(uint32_t));
    memcpy(dst + 4, &obj->_posy, sizeof(uint32_t));
    memcpy(dst + 8, &obj->_width, sizeof(uint32_t));
    memcpy(dst + 12, &obj->_height, sizeof(uint32_t));
}

void rectu32_toBytesLE(const rectu32_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Little-endian byte order
    for (int i = 0; i < 4; i++) {
        dst[i] = (uint8_t)((obj->_posx >> (i * 8)) & 0xFF);
        dst[i + 4] = (uint8_t)((obj->_posy >> (i * 8)) & 0xFF);
        dst[i + 8] = (uint8_t)((obj->_width >> (i * 8)) & 0xFF);
        dst[i + 12] = (uint8_t)((obj->_height >> (i * 8)) & 0xFF);
    }
}

void recti32_toBytes(const recti32_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Convert to unsigned representation for consistent serialization
    uint32_t posx = (uint32_t)obj->_posx;
    uint32_t posy = (uint32_t)obj->_posy;
    uint32_t width = (uint32_t)obj->_width;
    uint32_t height = (uint32_t)obj->_height;

    // Native byte order (platform dependent)
    memcpy(dst, &posx, sizeof(uint32_t));
    memcpy(dst + 4, &posy, sizeof(uint32_t));
    memcpy(dst + 8, &width, sizeof(uint32_t));
    memcpy(dst + 12, &height, sizeof(uint32_t));
}

void recti32_toBytesLE(const recti32_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Convert to unsigned representation for consistent serialization
    uint32_t posx = (uint32_t)obj->_posx;
    uint32_t posy = (uint32_t)obj->_posy;
    uint32_t width = (uint32_t)obj->_width;
    uint32_t height = (uint32_t)obj->_height;

    // Little-endian byte order
    for (int i = 0; i < 4; i++) {
        dst[i] = (uint8_t)((posx >> (i * 8)) & 0xFF);
        dst[i + 4] = (uint8_t)((posy >> (i * 8)) & 0xFF);
        dst[i + 8] = (uint8_t)((width >> (i * 8)) & 0xFF);
        dst[i + 12] = (uint8_t)((height >> (i * 8)) & 0xFF);
    }
}

// 64-bit types
void rectu64_toBytes(const rectu64_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(dst, &obj->_posx, sizeof(uint64_t));
    memcpy(dst + 8, &obj->_posy, sizeof(uint64_t));
    memcpy(dst + 16, &obj->_width, sizeof(uint64_t));
    memcpy(dst + 24, &obj->_height, sizeof(uint64_t));
}

void rectu64_toBytesLE(const rectu64_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Little-endian byte order
    for (int i = 0; i < 8; i++) {
        dst[i] = (uint8_t)((obj->_posx >> (i * 8)) & 0xFF);
        dst[i + 8] = (uint8_t)((obj->_posy >> (i * 8)) & 0xFF);
        dst[i + 16] = (uint8_t)((obj->_width >> (i * 8)) & 0xFF);
        dst[i + 24] = (uint8_t)((obj->_height >> (i * 8)) & 0xFF);
    }
}

void recti64_toBytes(const recti64_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Convert to unsigned representation for consistent serialization
    uint64_t posx = (uint64_t)obj->_posx;
    uint64_t posy = (uint64_t)obj->_posy;
    uint64_t width = (uint64_t)obj->_width;
    uint64_t height = (uint64_t)obj->_height;

    // Native byte order (platform dependent)
    memcpy(dst, &posx, sizeof(uint64_t));
    memcpy(dst + 8, &posy, sizeof(uint64_t));
    memcpy(dst + 16, &width, sizeof(uint64_t));
    memcpy(dst + 24, &height, sizeof(uint64_t));
}

void recti64_toBytesLE(const recti64_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Convert to unsigned representation for consistent serialization
    uint64_t posx = (uint64_t)obj->_posx;
    uint64_t posy = (uint64_t)obj->_posy;
    uint64_t width = (uint64_t)obj->_width;
    uint64_t height = (uint64_t)obj->_height;

    // Little-endian byte order
    for (int i = 0; i < 8; i++) {
        dst[i] = (uint8_t)((posx >> (i * 8)) & 0xFF);
        dst[i + 8] = (uint8_t)((posy >> (i * 8)) & 0xFF);
        dst[i + 16] = (uint8_t)((width >> (i * 8)) & 0xFF);
        dst[i + 24] = (uint8_t)((height >> (i * 8)) & 0xFF);
    }
}

// Floating-point types
void rectf_toBytes(const rectf_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(dst, &obj->_posx, sizeof(float));
    memcpy(dst + 4, &obj->_posy, sizeof(float));
    memcpy(dst + 8, &obj->_width, sizeof(float));
    memcpy(dst + 12, &obj->_height, sizeof(float));
}

void rectf_toBytesLE(const rectf_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Use union to access the binary representation of floats
    union {
        float f;
        uint32_t i;
    } converter;

    converter.f = obj->_posx;
    for (int i = 0; i < 4; i++) {
        dst[i] = (uint8_t)((converter.i >> (i * 8)) & 0xFF);
    }

    converter.f = obj->_posy;
    for (int i = 0; i < 4; i++) {
        dst[i + 4] = (uint8_t)((converter.i >> (i * 8)) & 0xFF);
    }

    converter.f = obj->_width;
    for (int i = 0; i < 4; i++) {
        dst[i + 8] = (uint8_t)((converter.i >> (i * 8)) & 0xFF);
    }

    converter.f = obj->_height;
    for (int i = 0; i < 4; i++) {
        dst[i + 12] = (uint8_t)((converter.i >> (i * 8)) & 0xFF);
    }
}

void rectd_toBytes(const rectd_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(dst, &obj->_posx, sizeof(double));
    memcpy(dst + 8, &obj->_posy, sizeof(double));
    memcpy(dst + 16, &obj->_width, sizeof(double));
    memcpy(dst + 24, &obj->_height, sizeof(double));
}

void rectd_toBytesLE(const rectd_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Use union to access the binary representation of doubles
    union {
        double d;
        uint64_t i;
    } converter;

    converter.d = obj->_posx;
    for (int i = 0; i < 8; i++) {
        dst[i] = (uint8_t)((converter.i >> (i * 8)) & 0xFF);
    }

    converter.d = obj->_posy;
    for (int i = 0; i < 8; i++) {
        dst[i + 8] = (uint8_t)((converter.i >> (i * 8)) & 0xFF);
    }

    converter.d = obj->_width;
    for (int i = 0; i < 8; i++) {
        dst[i + 16] = (uint8_t)((converter.i >> (i * 8)) & 0xFF);
    }

    converter.d = obj->_height;
    for (int i = 0; i < 8; i++) {
        dst[i + 24] = (uint8_t)((converter.i >> (i * 8)) & 0xFF);
    }
}

void rectld_toBytes(const rectld_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(dst, &obj->_posx, sizeof(long double));
    memcpy(dst + sizeof(long double), &obj->_posy, sizeof(long double));
    memcpy(dst + 2 * sizeof(long double), &obj->_width, sizeof(long double));
    memcpy(dst + 3 * sizeof(long double), &obj->_height, sizeof(long double));
}

void rectld_toBytesLE(const rectld_t* obj, uint8_t* dst) {
    if (obj == NULL || dst == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // For long double, we need to handle platform-dependent size
    // We'll serialize in little-endian order regardless of platform
    const uint8_t* posx_bytes = (const uint8_t*)&obj->_posx;
    const uint8_t* posy_bytes = (const uint8_t*)&obj->_posy;
    const uint8_t* width_bytes = (const uint8_t*)&obj->_width;
    const uint8_t* height_bytes = (const uint8_t*)&obj->_height;

    size_t ld_size = sizeof(long double);

    // Copy bytes in reverse order for little-endian
    for (size_t i = 0; i < ld_size; i++) {
        dst[i] = posx_bytes[ld_size - 1 - i];
        dst[i + ld_size] = posy_bytes[ld_size - 1 - i];
        dst[i + 2 * ld_size] = width_bytes[ld_size - 1 - i];
        dst[i + 3 * ld_size] = height_bytes[ld_size - 1 - i];
    }
}

// Deserialization functions for all rectangle types

// 8-bit types (native and LE are the same)
void rectu8_fromBytes(rectu8_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    obj->_posx = src[0];
    obj->_posy = src[1];
    obj->_width = src[2];
    obj->_height = src[3];
}

void rectu8_fromBytesLE(rectu8_t* obj, const uint8_t* src) {
    rectu8_fromBytes(obj, src); // Same as native for 8-bit types
}

void recti8_fromBytes(recti8_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    obj->_posx = (int8_t)src[0];
    obj->_posy = (int8_t)src[1];
    obj->_width = (int8_t)src[2];
    obj->_height = (int8_t)src[3];
}

void recti8_fromBytesLE(recti8_t* obj, const uint8_t* src) {
    recti8_fromBytes(obj, src); // Same as native for 8-bit types
}

// 16-bit types
void rectu16_fromBytes(rectu16_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(&obj->_posx, src, sizeof(uint16_t));
    memcpy(&obj->_posy, src + 2, sizeof(uint16_t));
    memcpy(&obj->_width, src + 4, sizeof(uint16_t));
    memcpy(&obj->_height, src + 6, sizeof(uint16_t));
}

void rectu16_fromBytesLE(rectu16_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Little-endian byte order
    obj->_posx = (uint16_t)src[0] | ((uint16_t)src[1] << 8);
    obj->_posy = (uint16_t)src[2] | ((uint16_t)src[3] << 8);
    obj->_width = (uint16_t)src[4] | ((uint16_t)src[5] << 8);
    obj->_height = (uint16_t)src[6] | ((uint16_t)src[7] << 8);
}

void recti16_fromBytes(recti16_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Read as unsigned first, then cast to signed
    uint16_t posx, posy, width, height;
    memcpy(&posx, src, sizeof(uint16_t));
    memcpy(&posy, src + 2, sizeof(uint16_t));
    memcpy(&width, src + 4, sizeof(uint16_t));
    memcpy(&height, src + 6, sizeof(uint16_t));

    obj->_posx = (int16_t)posx;
    obj->_posy = (int16_t)posy;
    obj->_width = (int16_t)width;
    obj->_height = (int16_t)height;
}

void recti16_fromBytesLE(recti16_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Little-endian byte order
    obj->_posx = (int16_t)((uint16_t)src[0] | ((uint16_t)src[1] << 8));
    obj->_posy = (int16_t)((uint16_t)src[2] | ((uint16_t)src[3] << 8));
    obj->_width = (int16_t)((uint16_t)src[4] | ((uint16_t)src[5] << 8));
    obj->_height = (int16_t)((uint16_t)src[6] | ((uint16_t)src[7] << 8));
}

// 32-bit types
void rectu32_fromBytes(rectu32_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(&obj->_posx, src, sizeof(uint32_t));
    memcpy(&obj->_posy, src + 4, sizeof(uint32_t));
    memcpy(&obj->_width, src + 8, sizeof(uint32_t));
    memcpy(&obj->_height, src + 12, sizeof(uint32_t));
}

void rectu32_fromBytesLE(rectu32_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Little-endian byte order
    obj->_posx = (uint32_t)src[0] |
                 ((uint32_t)src[1] << 8) |
                 ((uint32_t)src[2] << 16) |
                 ((uint32_t)src[3] << 24);

    obj->_posy = (uint32_t)src[4] |
                 ((uint32_t)src[5] << 8) |
                 ((uint32_t)src[6] << 16) |
                 ((uint32_t)src[7] << 24);

    obj->_width = (uint32_t)src[8] |
                  ((uint32_t)src[9] << 8) |
                  ((uint32_t)src[10] << 16) |
                  ((uint32_t)src[11] << 24);

    obj->_height = (uint32_t)src[12] |
                   ((uint32_t)src[13] << 8) |
                   ((uint32_t)src[14] << 16) |
                   ((uint32_t)src[15] << 24);
}

void recti32_fromBytes(recti32_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Read as unsigned first, then cast to signed
    uint32_t posx, posy, width, height;
    memcpy(&posx, src, sizeof(uint32_t));
    memcpy(&posy, src + 4, sizeof(uint32_t));
    memcpy(&width, src + 8, sizeof(uint32_t));
    memcpy(&height, src + 12, sizeof(uint32_t));

    obj->_posx = (int32_t)posx;
    obj->_posy = (int32_t)posy;
    obj->_width = (int32_t)width;
    obj->_height = (int32_t)height;
}

void recti32_fromBytesLE(recti32_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Little-endian byte order
    obj->_posx = (int32_t)((uint32_t)src[0] |
                           ((uint32_t)src[1] << 8) |
                           ((uint32_t)src[2] << 16) |
                           ((uint32_t)src[3] << 24));

    obj->_posy = (int32_t)((uint32_t)src[4] |
                           ((uint32_t)src[5] << 8) |
                           ((uint32_t)src[6] << 16) |
                           ((uint32_t)src[7] << 24));

    obj->_width = (int32_t)((uint32_t)src[8] |
                            ((uint32_t)src[9] << 8) |
                            ((uint32_t)src[10] << 16) |
                            ((uint32_t)src[11] << 24));

    obj->_height = (int32_t)((uint32_t)src[12] |
                             ((uint32_t)src[13] << 8) |
                             ((uint32_t)src[14] << 16) |
                             ((uint32_t)src[15] << 24));
}

// 64-bit types
void rectu64_fromBytes(rectu64_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(&obj->_posx, src, sizeof(uint64_t));
    memcpy(&obj->_posy, src + 8, sizeof(uint64_t));
    memcpy(&obj->_width, src + 16, sizeof(uint64_t));
    memcpy(&obj->_height, src + 24, sizeof(uint64_t));
}

void rectu64_fromBytesLE(rectu64_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Little-endian byte order
    obj->_posx = (uint64_t)src[0] |
                 ((uint64_t)src[1] << 8) |
                 ((uint64_t)src[2] << 16) |
                 ((uint64_t)src[3] << 24) |
                 ((uint64_t)src[4] << 32) |
                 ((uint64_t)src[5] << 40) |
                 ((uint64_t)src[6] << 48) |
                 ((uint64_t)src[7] << 56);

    obj->_posy = (uint64_t)src[8] |
                 ((uint64_t)src[9] << 8) |
                 ((uint64_t)src[10] << 16) |
                 ((uint64_t)src[11] << 24) |
                 ((uint64_t)src[12] << 32) |
                 ((uint64_t)src[13] << 40) |
                 ((uint64_t)src[14] << 48) |
                 ((uint64_t)src[15] << 56);

    obj->_width = (uint64_t)src[16] |
                  ((uint64_t)src[17] << 8) |
                  ((uint64_t)src[18] << 16) |
                  ((uint64_t)src[19] << 24) |
                  ((uint64_t)src[20] << 32) |
                  ((uint64_t)src[21] << 40) |
                  ((uint64_t)src[22] << 48) |
                  ((uint64_t)src[23] << 56);

    obj->_height = (uint64_t)src[24] |
                   ((uint64_t)src[25] << 8) |
                   ((uint64_t)src[26] << 16) |
                   ((uint64_t)src[27] << 24) |
                   ((uint64_t)src[28] << 32) |
                   ((uint64_t)src[29] << 40) |
                   ((uint64_t)src[30] << 48) |
                   ((uint64_t)src[31] << 56);
}

void recti64_fromBytes(recti64_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Read as unsigned first, then cast to signed
    uint64_t posx, posy, width, height;
    memcpy(&posx, src, sizeof(uint64_t));
    memcpy(&posy, src + 8, sizeof(uint64_t));
    memcpy(&width, src + 16, sizeof(uint64_t));
    memcpy(&height, src + 24, sizeof(uint64_t));

    obj->_posx = (int64_t)posx;
    obj->_posy = (int64_t)posy;
    obj->_width = (int64_t)width;
    obj->_height = (int64_t)height;
}

void recti64_fromBytesLE(recti64_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Little-endian byte order
    obj->_posx = (int64_t)((uint64_t)src[0] |
                           ((uint64_t)src[1] << 8) |
                           ((uint64_t)src[2] << 16) |
                           ((uint64_t)src[3] << 24) |
                           ((uint64_t)src[4] << 32) |
                           ((uint64_t)src[5] << 40) |
                           ((uint64_t)src[6] << 48) |
                           ((uint64_t)src[7] << 56));

    obj->_posy = (int64_t)((uint64_t)src[8] |
                           ((uint64_t)src[9] << 8) |
                           ((uint64_t)src[10] << 16) |
                           ((uint64_t)src[11] << 24) |
                           ((uint64_t)src[12] << 32) |
                           ((uint64_t)src[13] << 40) |
                           ((uint64_t)src[14] << 48) |
                           ((uint64_t)src[15] << 56));

    obj->_width = (int64_t)((uint64_t)src[16] |
                            ((uint64_t)src[17] << 8) |
                            ((uint64_t)src[18] << 16) |
                            ((uint64_t)src[19] << 24) |
                            ((uint64_t)src[20] << 32) |
                            ((uint64_t)src[21] << 40) |
                            ((uint64_t)src[22] << 48) |
                            ((uint64_t)src[23] << 56));

    obj->_height = (int64_t)((uint64_t)src[24] |
                             ((uint64_t)src[25] << 8) |
                             ((uint64_t)src[26] << 16) |
                             ((uint64_t)src[27] << 24) |
                             ((uint64_t)src[28] << 32) |
                             ((uint64_t)src[29] << 40) |
                             ((uint64_t)src[30] << 48) |
                             ((uint64_t)src[31] << 56));
}

// Floating-point types
void rectf_fromBytes(rectf_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(&obj->_posx, src, sizeof(float));
    memcpy(&obj->_posy, src + 4, sizeof(float));
    memcpy(&obj->_width, src + 8, sizeof(float));
    memcpy(&obj->_height, src + 12, sizeof(float));
}

void rectf_fromBytesLE(rectf_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Use union to reconstruct from little-endian bytes
    union {
        float f;
        uint32_t i;
    } converter;

    converter.i = (uint32_t)src[0] |
                  ((uint32_t)src[1] << 8) |
                  ((uint32_t)src[2] << 16) |
                  ((uint32_t)src[3] << 24);
    obj->_posx = converter.f;

    converter.i = (uint32_t)src[4] |
                  ((uint32_t)src[5] << 8) |
                  ((uint32_t)src[6] << 16) |
                  ((uint32_t)src[7] << 24);
    obj->_posy = converter.f;

    converter.i = (uint32_t)src[8] |
                  ((uint32_t)src[9] << 8) |
                  ((uint32_t)src[10] << 16) |
                  ((uint32_t)src[11] << 24);
    obj->_width = converter.f;

    converter.i = (uint32_t)src[12] |
                  ((uint32_t)src[13] << 8) |
                  ((uint32_t)src[14] << 16) |
                  ((uint32_t)src[15] << 24);
    obj->_height = converter.f;
}

void rectd_fromBytes(rectd_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(&obj->_posx, src, sizeof(double));
    memcpy(&obj->_posy, src + 8, sizeof(double));
    memcpy(&obj->_width, src + 16, sizeof(double));
    memcpy(&obj->_height, src + 24, sizeof(double));
}

void rectd_fromBytesLE(rectd_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Use union to reconstruct from little-endian bytes
    union {
        double d;
        uint64_t i;
    } converter;

    converter.i = (uint64_t)src[0] |
                  ((uint64_t)src[1] << 8) |
                  ((uint64_t)src[2] << 16) |
                  ((uint64_t)src[3] << 24) |
                  ((uint64_t)src[4] << 32) |
                  ((uint64_t)src[5] << 40) |
                  ((uint64_t)src[6] << 48) |
                  ((uint64_t)src[7] << 56);
    obj->_posx = converter.d;

    converter.i = (uint64_t)src[8] |
                  ((uint64_t)src[9] << 8) |
                  ((uint64_t)src[10] << 16) |
                  ((uint64_t)src[11] << 24) |
                  ((uint64_t)src[12] << 32) |
                  ((uint64_t)src[13] << 40) |
                  ((uint64_t)src[14] << 48) |
                  ((uint64_t)src[15] << 56);
    obj->_posy = converter.d;

    converter.i = (uint64_t)src[16] |
                  ((uint64_t)src[17] << 8) |
                  ((uint64_t)src[18] << 16) |
                  ((uint64_t)src[19] << 24) |
                  ((uint64_t)src[20] << 32) |
                  ((uint64_t)src[21] << 40) |
                  ((uint64_t)src[22] << 48) |
                  ((uint64_t)src[23] << 56);
    obj->_width = converter.d;

    converter.i = (uint64_t)src[24] |
                  ((uint64_t)src[25] << 8) |
                  ((uint64_t)src[26] << 16) |
                  ((uint64_t)src[27] << 24) |
                  ((uint64_t)src[28] << 32) |
                  ((uint64_t)src[29] << 40) |
                  ((uint64_t)src[30] << 48) |
                  ((uint64_t)src[31] << 56);
    obj->_height = converter.d;
}

void rectld_fromBytes(rectld_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Native byte order (platform dependent)
    memcpy(&obj->_posx, src, sizeof(long double));
    memcpy(&obj->_posy, src + sizeof(long double), sizeof(long double));
    memcpy(&obj->_width, src + 2 * sizeof(long double), sizeof(long double));
    memcpy(&obj->_height, src + 3 * sizeof(long double), sizeof(long double));
}

void rectld_fromBytesLE(rectld_t* obj, const uint8_t* src) {
    if (obj == NULL || src == NULL) {
        rect_last_error = RECT_ERROR_INVALID_DIMENSIONS;
        rect_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // For long double, we need to handle platform-dependent size
    // We'll deserialize from little-endian order regardless of platform
    uint8_t* posx_bytes = (uint8_t*)&obj->_posx;
    uint8_t* posy_bytes = (uint8_t*)&obj->_posy;
    uint8_t* width_bytes = (uint8_t*)&obj->_width;
    uint8_t* height_bytes = (uint8_t*)&obj->_height;

    size_t ld_size = sizeof(long double);

    // Copy bytes in reverse order for little-endian
    for (size_t i = 0; i < ld_size; i++) {
        posx_bytes[ld_size - 1 - i] = src[i];
        posy_bytes[ld_size - 1 - i] = src[i + ld_size];
        width_bytes[ld_size - 1 - i] = src[i + 2 * ld_size];
        height_bytes[ld_size - 1 - i] = src[i + 3 * ld_size];
    }
}
