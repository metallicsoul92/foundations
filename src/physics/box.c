#include "../../include/physics/box.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Ensure error state is clear
#define BOX_MALLOC_CLEAR_ERROR() \
    do { box_clear_error(); } while (0)

// Helper macros for dimension validation
#define VALIDATE_INT_DIMENSIONS(b) (\
    (b)->_width >= 0 && (b)->_height >= 0 && (b)->_depth >= 0\
)

#define VALIDATE_FLOAT_DIMENSIONS(b) (\
    !isnan((b)->_width) && !isnan((b)->_height) && !isnan((b)->_depth) &&\
    !isinf((b)->_width) && !isinf((b)->_height) && !isinf((b)->_depth) &&\
    (b)->_width >= 0 && (b)->_height >= 0 && (b)->_depth >= 0\
)

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

/*
  Error Handling
*/
// Common error codes for all box types
typedef enum {
    BOX_SUCCESS = 0,
    BOX_ERROR_MALLOC_FAILED,
    BOX_ERROR_OVERFLOW,
    BOX_ERROR_INVALID_DIMENSIONS,
    BOX_ERROR_UNKNOWN
} box_error_t;

// Global error state for all box types
static box_error_t box_last_error = BOX_SUCCESS;
static const char* box_error_string = NULL;

// Error strings
static const char* BOX_ERROR_STRINGS[] = {
    "Success",
    "Memory allocation failed",
    "Box would cause coordinate overflow",
    "Invalid dimensions provided",
    "Unknown error"
};

// Function to get the last error code
box_error_t box_get_error(void) {
    return box_last_error;
}

// Function to get the last error string
const char* box_get_error_string(void) {
    if (box_error_string != NULL) {
        return box_error_string;
    }
    return BOX_ERROR_STRINGS[box_last_error];
}

// Function to set a custom error string
void box_set_error_string(const char* custom_error) {
    box_error_string = custom_error;
}

// Function to clear error state
void box_clear_error(void) {
    box_last_error = BOX_SUCCESS;
    box_error_string = NULL;
}

/*
  Structure Definitions
*/

struct _boxu8_t{
  uint8_t _posx;
  uint8_t _posy;
  uint8_t _posz;
  uint8_t _width;
  uint8_t _height;
  uint8_t _depth;
};

struct _boxi8_t{
  int8_t _posx;
  int8_t _posy;
  int8_t _posz;
  int8_t _width;
  int8_t _height;
  int8_t _depth;
};

struct _boxu16_t{
  uint16_t _posx;
  uint16_t _posy;
  uint16_t _posz;
  uint16_t _width;
  uint16_t _height;
  uint16_t _depth;
};

struct _boxi16_t{
  int16_t _posx;
  int16_t _posy;
  int16_t _posz;
  int16_t _width;
  int16_t _height;
  int16_t _depth;
};

struct _boxu32_t{
  uint32_t _posx;
  uint32_t _posy;
  uint32_t _posz;
  uint32_t _width;
  uint32_t _height;
  uint32_t _depth;
};

struct _boxi32_t{
  int32_t _posx;
  int32_t _posy;
  int32_t _posz;
  int32_t _width;
  int32_t _height;
  int32_t _depth;
};

struct _boxu64_t{
  uint64_t _posx;
  uint64_t _posy;
  uint64_t _posz;
  uint64_t _width;
  uint64_t _height;
  uint64_t _depth;
};

struct _boxi64_t{
  int64_t _posx;
  int64_t _posy;
  int64_t _posz;
  int64_t _width;
  int64_t _height;
  int64_t _depth;
};

struct _boxf_t{
  float _posx;
  float _posy;
  float _posz;
  float _width;
  float _height;
  float _depth;
};

struct _boxd_t{
  double _posx;
  double _posy;
  double _posz;
  double _width;
  double _height;
  double _depth;
};

struct _boxld_t{
  long double _posx;
  long double _posy;
  long double _posz;
  long double _width;
  long double _height;
  long double _depth;
};

// ---- Malloc From Parameters ----

boxu8_t* boxu8_malloc(uint8_t x, uint8_t y, uint8_t z, uint8_t w, uint8_t h, uint8_t d) {
    BOX_MALLOC_CLEAR_ERROR();
    if ((w > 0 && x > UINT8_MAX - w) || (w < 0 && x < -UINT8_MAX - w) ||
        (h > 0 && y > UINT8_MAX - h) || (h < 0 && y < -UINT8_MAX - h) ||
        (d > 0 && z > UINT8_MAX - d) || (d < 0 && z < -UINT8_MAX - d)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxu8_t* box = malloc(sizeof(boxu8_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}

boxi8_t* boxi8_malloc(int8_t x, int8_t y, int8_t z, int8_t w, int8_t h, int8_t d) {
    BOX_MALLOC_CLEAR_ERROR();
    if ((w > 0 && x > INT8_MAX - w) || (w < 0 && x < -INT8_MAX - w) ||
        (h > 0 && y > INT8_MAX - h) || (h < 0 && y < -INT8_MAX - h) ||
        (d > 0 && z > INT8_MAX - d) || (d < 0 && z < -INT8_MAX - d)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxi8_t* box = malloc(sizeof(boxi8_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}

boxu16_t* boxu16_malloc(uint16_t x, uint16_t y, uint16_t z, uint16_t w, uint16_t h, uint16_t d) {
    BOX_MALLOC_CLEAR_ERROR();
    if ((w > 0 && x > UINT16_MAX - w) || (w < 0 && x < -UINT16_MAX - w) ||
        (h > 0 && y > UINT16_MAX - h) || (h < 0 && y < -UINT16_MAX - h) ||
        (d > 0 && z > UINT16_MAX - d) || (d < 0 && z < -UINT16_MAX - d)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxu16_t* box = malloc(sizeof(boxu16_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}

boxi16_t* boxi16_malloc(int16_t x, int16_t y, int16_t z, int16_t w, int16_t h, int16_t d) {
    BOX_MALLOC_CLEAR_ERROR();
    if ((w > 0 && x > INT16_MAX - w) || (w < 0 && x < -INT16_MAX - w) ||
        (h > 0 && y > INT16_MAX - h) || (h < 0 && y < -INT16_MAX - h) ||
        (d > 0 && z > INT16_MAX - d) || (d < 0 && z < -INT16_MAX - d)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxi16_t* box = malloc(sizeof(boxi16_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}

boxu32_t* boxu32_malloc(uint32_t x, uint32_t y, uint32_t z, uint32_t w, uint32_t h, uint32_t d) {
    BOX_MALLOC_CLEAR_ERROR();
    if ((w > 0 && x > UINT32_MAX - w) || (w < 0 && x < -UINT32_MAX - w) ||
        (h > 0 && y > UINT32_MAX - h) || (h < 0 && y < -UINT32_MAX - h) ||
        (d > 0 && z > UINT32_MAX - d) || (d < 0 && z < -UINT32_MAX - d)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxu32_t* box = malloc(sizeof(boxu32_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}

boxi32_t* boxi32_malloc(int32_t x, int32_t y, int32_t z, int32_t w, int32_t h, int32_t d) {
    BOX_MALLOC_CLEAR_ERROR();
    if ((w > 0 && x > INT32_MAX - w) || (w < 0 && x < -INT32_MAX - w) ||
        (h > 0 && y > INT32_MAX - h) || (h < 0 && y < -INT32_MAX - h) ||
        (d > 0 && z > INT32_MAX - d) || (d < 0 && z < -INT32_MAX - d)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxi32_t* box = malloc(sizeof(boxi32_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}

boxu64_t* boxu64_malloc(uint64_t x, uint64_t y, uint64_t z, uint64_t w, uint64_t h, uint64_t d) {
    BOX_MALLOC_CLEAR_ERROR();
    if ((w > 0 && x > UINT64_MAX - w) || (w < 0 && x < -UINT64_MAX - w) ||
        (h > 0 && y > UINT64_MAX - h) || (h < 0 && y < -UINT64_MAX - h) ||
        (d > 0 && z > UINT64_MAX - d) || (d < 0 && z < -UINT64_MAX - d)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxu64_t* box = malloc(sizeof(boxu64_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}

boxi64_t* boxi64_malloc(int64_t x, int64_t y, int64_t z, int64_t w, int64_t h, int64_t d) {
    BOX_MALLOC_CLEAR_ERROR();
    if ((w > 0 && x > INT64_MAX - w) || (w < 0 && x < -INT64_MAX - w) ||
        (h > 0 && y > INT64_MAX - h) || (h < 0 && y < -INT64_MAX - h) ||
        (d > 0 && z > INT64_MAX - d) || (d < 0 && z < -INT64_MAX - d)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxi64_t* box = malloc(sizeof(boxi64_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}

boxf_t* boxf_malloc(float x, float y, float z, float w, float h, float d) {
    BOX_MALLOC_CLEAR_ERROR();
    if (isnan(x) || isnan(y) || isnan(z) || isnan(w) || isnan(h) || isnan(d) ||
        isinf(x) || isinf(y) || isinf(z) || isinf(w) || isinf(h) || isinf(d)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    boxf_t* box = malloc(sizeof(boxf_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}

boxd_t* boxd_malloc(double x, double y, double z, double w, double h, double d) {
    BOX_MALLOC_CLEAR_ERROR();
    boxd_t* box = malloc(sizeof(boxd_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}

boxld_t* boxld_malloc(long double x, long double y, long double z, long double w, long double h, long double d) {
    BOX_MALLOC_CLEAR_ERROR();
    boxld_t* box = malloc(sizeof(boxld_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    box->_posx = x; box->_posy = y; box->_posz = z;
    box->_width = w; box->_height = h; box->_depth = d;
    return box;
}


// ---- Malloc Empty ----

boxu8_t* boxu8_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxu8_t* box = malloc(sizeof(boxu8_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxu8_t));
    return box;
}

boxi8_t* boxi8_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxi8_t* box = malloc(sizeof(boxi8_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxi8_t));
    return box;
}

boxu16_t* boxu16_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxu16_t* box = malloc(sizeof(boxu16_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxu16_t));
    return box;
}

boxi16_t* boxi16_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxi16_t* box = malloc(sizeof(boxi16_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxi16_t));
    return box;
}

boxu32_t* boxu32_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxu32_t* box = malloc(sizeof(boxu32_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxu32_t));
    return box;
}

boxi32_t* boxi32_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxi32_t* box = malloc(sizeof(boxi32_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxi32_t));
    return box;
}

boxu64_t* boxu64_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxu64_t* box = malloc(sizeof(boxu64_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxu64_t));
    return box;
}

boxi64_t* boxi64_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxi64_t* box = malloc(sizeof(boxi64_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxi64_t));
    return box;
}

boxf_t* boxf_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxf_t* box = malloc(sizeof(boxf_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxf_t));
    return box;
}

boxd_t* boxd_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxd_t* box = malloc(sizeof(boxd_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxd_t));
    return box;
}

boxld_t* boxld_mallocEmpty(void) {
    BOX_MALLOC_CLEAR_ERROR();
    boxld_t* box = malloc(sizeof(boxld_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memset(box, 0, sizeof(boxld_t));
    return box;
}


// ---- Malloc Copy ----

boxu8_t* boxu8_copy(const boxu8_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    if ((copy->_width > 0 && copy->_posx > UINT8_MAX - copy->_width) ||
        (copy->_width < 0 && copy->_posx < -UINT8_MAX - copy->_width) ||
        (copy->_height > 0 && copy->_posy > UINT8_MAX - copy->_height) ||
        (copy->_height < 0 && copy->_posy < -UINT8_MAX - copy->_height) ||
        (copy->_depth > 0 && copy->_posz > UINT8_MAX - copy->_depth) ||
        (copy->_depth < 0 && copy->_posz < -UINT8_MAX - copy->_depth)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxu8_t* box = malloc(sizeof(boxu8_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxu8_t));
    return box;
}

boxi8_t* boxi8_copy(const boxi8_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    if ((copy->_width > 0 && copy->_posx > INT8_MAX - copy->_width) ||
        (copy->_width < 0 && copy->_posx < -INT8_MAX - copy->_width) ||
        (copy->_height > 0 && copy->_posy > INT8_MAX - copy->_height) ||
        (copy->_height < 0 && copy->_posy < -INT8_MAX - copy->_height) ||
        (copy->_depth > 0 && copy->_posz > INT8_MAX - copy->_depth) ||
        (copy->_depth < 0 && copy->_posz < -INT8_MAX - copy->_depth)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxi8_t* box = malloc(sizeof(boxi8_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxi8_t));
    return box;
}

boxu16_t* boxu16_copy(const boxu16_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    if ((copy->_width > 0 && copy->_posx > UINT16_MAX - copy->_width) ||
        (copy->_width < 0 && copy->_posx < -UINT16_MAX - copy->_width) ||
        (copy->_height > 0 && copy->_posy > UINT16_MAX - copy->_height) ||
        (copy->_height < 0 && copy->_posy < -UINT16_MAX - copy->_height) ||
        (copy->_depth > 0 && copy->_posz > UINT16_MAX - copy->_depth) ||
        (copy->_depth < 0 && copy->_posz < -UINT16_MAX - copy->_depth)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxu16_t* box = malloc(sizeof(boxu16_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxu16_t));
    return box;
}

boxi16_t* boxi16_copy(const boxi16_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    if ((copy->_width > 0 && copy->_posx > INT16_MAX - copy->_width) ||
        (copy->_width < 0 && copy->_posx < -INT16_MAX - copy->_width) ||
        (copy->_height > 0 && copy->_posy > INT16_MAX - copy->_height) ||
        (copy->_height < 0 && copy->_posy < -INT16_MAX - copy->_height) ||
        (copy->_depth > 0 && copy->_posz > INT16_MAX - copy->_depth) ||
        (copy->_depth < 0 && copy->_posz < -INT16_MAX - copy->_depth)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxi16_t* box = malloc(sizeof(boxi16_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxi16_t));
    return box;
}

boxu32_t* boxu32_copy(const boxu32_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    if ((copy->_width > 0 && copy->_posx > UINT32_MAX - copy->_width) ||
        (copy->_width < 0 && copy->_posx < -UINT32_MAX - copy->_width) ||
        (copy->_height > 0 && copy->_posy > UINT32_MAX - copy->_height) ||
        (copy->_height < 0 && copy->_posy < -UINT32_MAX - copy->_height) ||
        (copy->_depth > 0 && copy->_posz > UINT32_MAX - copy->_depth) ||
        (copy->_depth < 0 && copy->_posz < -UINT32_MAX - copy->_depth)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxu32_t* box = malloc(sizeof(boxu32_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxu32_t));
    return box;
}

boxi32_t* boxi32_copy(const boxi32_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    if ((copy->_width > 0 && copy->_posx > INT32_MAX - copy->_width) ||
        (copy->_width < 0 && copy->_posx < -INT32_MAX - copy->_width) ||
        (copy->_height > 0 && copy->_posy > INT32_MAX - copy->_height) ||
        (copy->_height < 0 && copy->_posy < -INT32_MAX - copy->_height) ||
        (copy->_depth > 0 && copy->_posz > INT32_MAX - copy->_depth) ||
        (copy->_depth < 0 && copy->_posz < -INT32_MAX - copy->_depth)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxi32_t* box = malloc(sizeof(boxi32_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxi32_t));
    return box;
}

boxu64_t* boxu64_copy(const boxu64_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    if ((copy->_width > 0 && copy->_posx > UINT64_MAX - copy->_width) ||
        (copy->_width < 0 && copy->_posx < -UINT64_MAX - copy->_width) ||
        (copy->_height > 0 && copy->_posy > UINT64_MAX - copy->_height) ||
        (copy->_height < 0 && copy->_posy < -UINT64_MAX - copy->_height) ||
        (copy->_depth > 0 && copy->_posz > UINT64_MAX - copy->_depth) ||
        (copy->_depth < 0 && copy->_posz < -UINT64_MAX - copy->_depth)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxu64_t* box = malloc(sizeof(boxu64_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxu64_t));
    return box;
}

boxi64_t* boxi64_copy(const boxi64_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    if ((copy->_width > 0 && copy->_posx > INT64_MAX - copy->_width) ||
        (copy->_width < 0 && copy->_posx < -INT64_MAX - copy->_width) ||
        (copy->_height > 0 && copy->_posy > INT64_MAX - copy->_height) ||
        (copy->_height < 0 && copy->_posy < -INT64_MAX - copy->_height) ||
        (copy->_depth > 0 && copy->_posz > INT64_MAX - copy->_depth) ||
        (copy->_depth < 0 && copy->_posz < -INT64_MAX - copy->_depth)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return NULL;
    }
    boxi64_t* box = malloc(sizeof(boxi64_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxi64_t));
    return box;
}

boxf_t* boxf_copy(const boxf_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    if (isnan(copy->_posx) || isnan(copy->_posy) || isnan(copy->_posz) ||
        isnan(copy->_width) || isnan(copy->_height) || isnan(copy->_depth) ||
        isinf(copy->_posx) || isinf(copy->_posy) || isinf(copy->_posz) ||
        isinf(copy->_width) || isinf(copy->_height) || isinf(copy->_depth)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    boxf_t* box = malloc(sizeof(boxf_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxf_t));
    return box;
}

boxd_t* boxd_copy(const boxd_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    boxd_t* box = malloc(sizeof(boxd_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxd_t));
    return box;
}

boxld_t* boxld_copy(const boxld_t* copy) {
    BOX_MALLOC_CLEAR_ERROR();
    if (!copy) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot copy from NULL pointer");
        return NULL;
    }
    boxld_t* box = malloc(sizeof(boxld_t));
    if (!box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }
    memcpy(box, copy, sizeof(boxld_t));
    return box;
}

// Move via other
boxu8_t* boxu8_memmove(boxu8_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxu8_t* new_box = malloc(sizeof(boxu8_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    // Copy the data
    memcpy(new_box, *move, sizeof(boxu8_t));

    // Free the original and set to NULL
    free(*move);
    *move = NULL;

    return new_box;
}

boxi8_t* boxi8_memmove(boxi8_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxi8_t* new_box = malloc(sizeof(boxi8_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    memcpy(new_box, *move, sizeof(boxi8_t));
    free(*move);
    *move = NULL;

    return new_box;
}

boxu16_t* boxu16_memmove(boxu16_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxu16_t* new_box = malloc(sizeof(boxu16_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    memcpy(new_box, *move, sizeof(boxu16_t));
    free(*move);
    *move = NULL;

    return new_box;
}

boxi16_t* boxi16_memmove(boxi16_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxi16_t* new_box = malloc(sizeof(boxi16_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    memcpy(new_box, *move, sizeof(boxi16_t));
    free(*move);
    *move = NULL;

    return new_box;
}

boxu32_t* boxu32_memmove(boxu32_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxu32_t* new_box = malloc(sizeof(boxu32_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    memcpy(new_box, *move, sizeof(boxu32_t));
    free(*move);
    *move = NULL;

    return new_box;
}

boxi32_t* boxi32_memmove(boxi32_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxi32_t* new_box = malloc(sizeof(boxi32_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    memcpy(new_box, *move, sizeof(boxi32_t));
    free(*move);
    *move = NULL;

    return new_box;
}

boxu64_t* boxu64_memmove(boxu64_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxu64_t* new_box = malloc(sizeof(boxu64_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    memcpy(new_box, *move, sizeof(boxu64_t));
    free(*move);
    *move = NULL;

    return new_box;
}

boxi64_t* boxi64_memmove(boxi64_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxi64_t* new_box = malloc(sizeof(boxi64_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    memcpy(new_box, *move, sizeof(boxi64_t));
    free(*move);
    *move = NULL;

    return new_box;
}

boxf_t* boxf_memmove(boxf_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxf_t* new_box = malloc(sizeof(boxf_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    memcpy(new_box, *move, sizeof(boxf_t));
    free(*move);
    *move = NULL;

    return new_box;
}

boxd_t* boxd_memmove(boxd_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxd_t* new_box = malloc(sizeof(boxd_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    memcpy(new_box, *move, sizeof(boxd_t));
    free(*move);
    *move = NULL;

    return new_box;
}

boxld_t* boxld_memmove(boxld_t** move) {
    if (!move || !*move) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }

    boxld_t* new_box = malloc(sizeof(boxld_t));
    if (!new_box) {
        box_last_error = BOX_ERROR_MALLOC_FAILED;
        return NULL;
    }

    memcpy(new_box, *move, sizeof(boxld_t));
    free(*move);
    *move = NULL;

    return new_box;
}

// Free functions for all box types
void boxu8_free(boxu8_t* obj) {
    if (obj) {
        free(obj);
    }
}

void boxi8_free(boxi8_t* obj) {
    if (obj) {
        free(obj);
    }
}

void boxu16_free(boxu16_t* obj) {
    if (obj) {
        free(obj);
    }
}

void boxi16_free(boxi16_t* obj) {
    if (obj) {
        free(obj);
    }
}

void boxu32_free(boxu32_t* obj) {
    if (obj) {
        free(obj);
    }
}

void boxi32_free(boxi32_t* obj) {
    if (obj) {
        free(obj);
    }
}

void boxu64_free(boxu64_t* obj) {
    if (obj) {
        free(obj);
    }
}

void boxi64_free(boxi64_t* obj) {
    if (obj) {
        free(obj);
    }
}

void boxf_free(boxf_t* obj) {
    if (obj) {
        free(obj);
    }
}

void boxd_free(boxd_t* obj) {
    if (obj) {
        free(obj);
    }
}

void boxld_free(boxld_t* obj) {
    if (obj) {
        free(obj);
    }
}

//Accessors
// Get X-coordinate functions for all box types
uint8_t boxu8_getX(const boxu8_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posx;
}

int8_t boxi8_getX(const boxi8_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posx;
}

uint16_t boxu16_getX(const boxu16_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posx;
}

int16_t boxi16_getX(const boxi16_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posx;
}

uint32_t boxu32_getX(const boxu32_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posx;
}

int32_t boxi32_getX(const boxi32_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posx;
}

uint64_t boxu64_getX(const boxu64_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posx;
}

int64_t boxi64_getX(const boxi64_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posx;
}

float boxf_getX(const boxf_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0f;
    }
    return obj->_posx;
}

double boxd_getX(const boxd_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0;
    }
    return obj->_posx;
}

long double boxld_getX(const boxld_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0L;
    }
    return obj->_posx;
}

// Get Y-coordinate functions for all box types
uint8_t boxu8_getY(const boxu8_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posy;
}

int8_t boxi8_getY(const boxi8_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posy;
}

uint16_t boxu16_getY(const boxu16_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posy;
}

int16_t boxi16_getY(const boxi16_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posy;
}

uint32_t boxu32_getY(const boxu32_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posy;
}

int32_t boxi32_getY(const boxi32_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posy;
}

uint64_t boxu64_getY(const boxu64_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posy;
}

int64_t boxi64_getY(const boxi64_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posy;
}

float boxf_getY(const boxf_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0f;
    }
    return obj->_posy;
}

double boxd_getY(const boxd_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0;
    }
    return obj->_posy;
}

long double boxld_getY(const boxld_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0L;
    }
    return obj->_posy;
}

// Get Z-coordinate functions for all box types
uint8_t boxu8_getZ(const boxu8_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posz;
}

int8_t boxi8_getZ(const boxi8_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posz;
}

uint16_t boxu16_getZ(const boxu16_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posz;
}

int16_t boxi16_getZ(const boxi16_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posz;
}

uint32_t boxu32_getZ(const boxu32_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posz;
}

int32_t boxi32_getZ(const boxi32_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posz;
}

uint64_t boxu64_getZ(const boxu64_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posz;
}

int64_t boxi64_getZ(const boxi64_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_posz;
}

float boxf_getZ(const boxf_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0f;
    }
    return obj->_posz;
}

double boxd_getZ(const boxd_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0;
    }
    return obj->_posz;
}

long double boxld_getZ(const boxld_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0L;
    }
    return obj->_posz;
}

// Get Width functions for all box types
uint8_t boxu8_getWidth(const boxu8_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_width;
}

int8_t boxi8_getWidth(const boxi8_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_width;
}

uint16_t boxu16_getWidth(const boxu16_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_width;
}

int16_t boxi16_getWidth(const boxi16_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_width;
}

uint32_t boxu32_getWidth(const boxu32_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_width;
}

int32_t boxi32_getWidth(const boxi32_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_width;
}

uint64_t boxu64_getWidth(const boxu64_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_width;
}

int64_t boxi64_getWidth(const boxi64_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_width;
}

float boxf_getWidth(const boxf_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0f;
    }
    return obj->_width;
}

double boxd_getWidth(const boxd_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0;
    }
    return obj->_width;
}

long double boxld_getWidth(const boxld_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0L;
    }
    return obj->_width;
}

// Get Height functions for all box types
uint8_t boxu8_getHeight(const boxu8_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_height;
}

int8_t boxi8_getHeight(const boxi8_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_height;
}

uint16_t boxu16_getHeight(const boxu16_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_height;
}

int16_t boxi16_getHeight(const boxi16_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_height;
}

uint32_t boxu32_getHeight(const boxu32_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_height;
}

int32_t boxi32_getHeight(const boxi32_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_height;
}

uint64_t boxu64_getHeight(const boxu64_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_height;
}

int64_t boxi64_getHeight(const boxi64_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_height;
}

float boxf_getHeight(const boxf_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0f;
    }
    return obj->_height;
}

double boxd_getHeight(const boxd_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0;
    }
    return obj->_height;
}

long double boxld_getHeight(const boxld_t* obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0L;
    }
    return obj->_height;
}

// Get Depth functions
uint8_t boxu8_getDepth(const boxu8_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_depth;
}

int8_t boxi8_getDepth(const boxi8_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_depth;
}

uint16_t boxu16_getDepth(const boxu16_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_depth;
}

int16_t boxi16_getDepth(const boxi16_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_depth;
}

uint32_t boxu32_getDepth(const boxu32_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_depth;
}

int32_t boxi32_getDepth(const boxi32_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_depth;
}

uint64_t boxu64_getDepth(const boxu64_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_depth;
}

int64_t boxi64_getDepth(const boxi64_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }
    return obj->_depth;
}

float boxf_getDepth(const boxf_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0f;
    }
    return obj->_depth;
}

double boxd_getDepth(const boxd_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0;
    }
    return obj->_depth;
}

long double boxld_getDepth(const boxld_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0L;
    }
    return obj->_depth;
}

// Set Position X functions
void boxu8_setPosX(boxu8_t *obj, uint8_t posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

void boxi8_setPosX(boxi8_t *obj, int8_t posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

void boxu16_setPosX(boxu16_t *obj, uint16_t posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

void boxi16_setPosX(boxi16_t *obj, int16_t posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

void boxu32_setPosX(boxu32_t *obj, uint32_t posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

void boxi32_setPosX(boxi32_t *obj, int32_t posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

void boxu64_setPosX(boxu64_t *obj, uint64_t posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

void boxi64_setPosX(boxi64_t *obj, int64_t posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

void boxf_setPosX(boxf_t *obj, float posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

void boxd_setPosX(boxd_t *obj, double posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

void boxld_setPosX(boxld_t *obj, long double posX) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
}

// Set Position Y functions
void boxu8_setPosY(boxu8_t *obj, uint8_t posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

void boxi8_setPosY(boxi8_t *obj, int8_t posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

void boxu16_setPosY(boxu16_t *obj, uint16_t posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

void boxi16_setPosY(boxi16_t *obj, int16_t posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

void boxu32_setPosY(boxu32_t *obj, uint32_t posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

void boxi32_setPosY(boxi32_t *obj, int32_t posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

void boxu64_setPosY(boxu64_t *obj, uint64_t posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

void boxi64_setPosY(boxi64_t *obj, int64_t posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

void boxf_setPosY(boxf_t *obj, float posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

void boxd_setPosY(boxd_t *obj, double posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

void boxld_setPosY(boxld_t *obj, long double posY) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy = posY;
}

// Set Position Z functions
void boxu8_setPosZ(boxu8_t *obj, uint8_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

void boxi8_setPosZ(boxi8_t *obj, int8_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

void boxu16_setPosZ(boxu16_t *obj, uint16_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

void boxi16_setPosZ(boxi16_t *obj, int16_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

void boxu32_setPosZ(boxu32_t *obj, uint32_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

void boxi32_setPosZ(boxi32_t *obj, int32_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

void boxu64_setPosZ(boxu64_t *obj, uint64_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

void boxi64_setPosZ(boxi64_t *obj, int64_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

void boxf_setPosZ(boxf_t *obj, float posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

void boxd_setPosZ(boxd_t *obj, double posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

void boxld_setPosZ(boxld_t *obj, long double posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz = posZ;
}

// Set Position (X, Y, Z) functions
void boxu8_setPos(boxu8_t *obj, uint8_t posX, uint8_t posY, uint8_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

void boxi8_setPos(boxi8_t *obj, int8_t posX, int8_t posY, int8_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

void boxu16_setPos(boxu16_t *obj, uint16_t posX, uint16_t posY, uint16_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

void boxi16_setPos(boxi16_t *obj, int16_t posX, int16_t posY, int16_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

void boxu32_setPos(boxu32_t *obj, uint32_t posX, uint32_t posY, uint32_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

void boxi32_setPos(boxi32_t *obj, int32_t posX, int32_t posY, int32_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

void boxu64_setPos(boxu64_t *obj, uint64_t posX, uint64_t posY, uint64_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

void boxi64_setPos(boxi64_t *obj, int64_t posX, int64_t posY, int64_t posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

void boxf_setPos(boxf_t *obj, float posX, float posY, float posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

void boxd_setPos(boxd_t *obj, double posX, double posY, double posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

void boxld_setPos(boxld_t *obj, long double posX, long double posY, long double posZ) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx = posX;
    obj->_posy = posY;
    obj->_posz = posZ;
}

// Set Width functions
void boxu8_setWidth(boxu8_t *obj, uint8_t width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

void boxi8_setWidth(boxi8_t *obj, int8_t width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

void boxu16_setWidth(boxu16_t *obj, uint16_t width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

void boxi16_setWidth(boxi16_t *obj, int16_t width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

void boxu32_setWidth(boxu32_t *obj, uint32_t width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

void boxi32_setWidth(boxi32_t *obj, int32_t width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

void boxu64_setWidth(boxu64_t *obj, uint64_t width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

void boxi64_setWidth(boxi64_t *obj, int64_t width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

void boxf_setWidth(boxf_t *obj, float width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

void boxd_setWidth(boxd_t *obj, double width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

void boxld_setWidth(boxld_t *obj, long double width) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
}

// Set Height functions
void boxu8_setHeight(boxu8_t *obj, uint8_t height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

void boxi8_setHeight(boxi8_t *obj, int8_t height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

void boxu16_setHeight(boxu16_t *obj, uint16_t height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

void boxi16_setHeight(boxi16_t *obj, int16_t height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

void boxu32_setHeight(boxu32_t *obj, uint32_t height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

void boxi32_setHeight(boxi32_t *obj, int32_t height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

void boxu64_setHeight(boxu64_t *obj, uint64_t height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

void boxi64_setHeight(boxi64_t *obj, int64_t height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

void boxf_setHeight(boxf_t *obj, float height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

void boxd_setHeight(boxd_t *obj, double height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

void boxld_setHeight(boxld_t *obj, long double height) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height = height;
}

// Set Depth functions
void boxu8_setDepth(boxu8_t *obj, uint8_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

void boxi8_setDepth(boxi8_t *obj, int8_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

void boxu16_setDepth(boxu16_t *obj, uint16_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

void boxi16_setDepth(boxi16_t *obj, int16_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

void boxu32_setDepth(boxu32_t *obj, uint32_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

void boxi32_setDepth(boxi32_t *obj, int32_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

void boxu64_setDepth(boxu64_t *obj, uint64_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

void boxi64_setDepth(boxi64_t *obj, int64_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

void boxf_setDepth(boxf_t *obj, float depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

void boxd_setDepth(boxd_t *obj, double depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

void boxld_setDepth(boxld_t *obj, long double depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth = depth;
}

// Set Size (width, height, depth) functions
void boxu8_setSize(boxu8_t *obj, uint8_t width, uint8_t height, uint8_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

void boxi8_setSize(boxi8_t *obj, int8_t width, int8_t height, int8_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

void boxu16_setSize(boxu16_t *obj, uint16_t width, uint16_t height, uint16_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

void boxi16_setSize(boxi16_t *obj, int16_t width, int16_t height, int16_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

void boxu32_setSize(boxu32_t *obj, uint32_t width, uint32_t height, uint32_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

void boxi32_setSize(boxi32_t *obj, int32_t width, int32_t height, int32_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

void boxu64_setSize(boxu64_t *obj, uint64_t width, uint64_t height, uint64_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

void boxi64_setSize(boxi64_t *obj, int64_t width, int64_t height, int64_t depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

void boxf_setSize(boxf_t *obj, float width, float height, float depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

void boxd_setSize(boxd_t *obj, double width, double height, double depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

void boxld_setSize(boxld_t *obj, long double width, long double height, long double depth) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width = width;
    obj->_height = height;
    obj->_depth = depth;
}

// Move X functions
void boxu8_moveX(boxu8_t *obj, uint8_t dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow
    if (obj->_posx > UINT8_MAX - dx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posx += dx;
}

void boxi8_moveX(boxi8_t *obj, int8_t dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow/underflow
    if ((dx > 0 && obj->_posx > INT8_MAX - dx) ||
        (dx < 0 && obj->_posx < INT8_MIN - dx)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posx += dx;
}

void boxu16_moveX(boxu16_t *obj, uint16_t dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_posx > UINT16_MAX - dx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posx += dx;
}

void boxi16_moveX(boxi16_t *obj, int16_t dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dx > 0 && obj->_posx > INT16_MAX - dx) ||
        (dx < 0 && obj->_posx < INT16_MIN - dx)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posx += dx;
}

void boxu32_moveX(boxu32_t *obj, uint32_t dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_posx > UINT32_MAX - dx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posx += dx;
}

void boxi32_moveX(boxi32_t *obj, int32_t dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dx > 0 && obj->_posx > INT32_MAX - dx) ||
        (dx < 0 && obj->_posx < INT32_MIN - dx)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posx += dx;
}

void boxu64_moveX(boxu64_t *obj, uint64_t dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_posx > UINT64_MAX - dx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posx += dx;
}

void boxi64_moveX(boxi64_t *obj, int64_t dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dx > 0 && obj->_posx > INT64_MAX - dx) ||
        (dx < 0 && obj->_posx < INT64_MIN - dx)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posx += dx;
}

void boxf_moveX(boxf_t *obj, float dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx += dx;
}

void boxd_moveX(boxd_t *obj, double dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx += dx;
}

void boxld_moveX(boxld_t *obj, long double dx) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posx += dx;
}

// Move Y functions
void boxu8_moveY(boxu8_t *obj, uint8_t dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow
    if (obj->_posy > UINT8_MAX - dy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posy += dy;
}

void boxi8_moveY(boxi8_t *obj, int8_t dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow/underflow
    if ((dy > 0 && obj->_posy > INT8_MAX - dy) ||
        (dy < 0 && obj->_posy < INT8_MIN - dy)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posy += dy;
}

void boxu16_moveY(boxu16_t *obj, uint16_t dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_posy > UINT16_MAX - dy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posy += dy;
}

void boxi16_moveY(boxi16_t *obj, int16_t dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dy > 0 && obj->_posy > INT16_MAX - dy) ||
        (dy < 0 && obj->_posy < INT16_MIN - dy)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posy += dy;
}

void boxu32_moveY(boxu32_t *obj, uint32_t dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_posy > UINT32_MAX - dy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posy += dy;
}

void boxi32_moveY(boxi32_t *obj, int32_t dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dy > 0 && obj->_posy > INT32_MAX - dy) ||
        (dy < 0 && obj->_posy < INT32_MIN - dy)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posy += dy;
}

void boxu64_moveY(boxu64_t *obj, uint64_t dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_posy > UINT64_MAX - dy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posy += dy;
}

void boxi64_moveY(boxi64_t *obj, int64_t dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dy > 0 && obj->_posy > INT64_MAX - dy) ||
        (dy < 0 && obj->_posy < INT64_MIN - dy)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posy += dy;
}

void boxf_moveY(boxf_t *obj, float dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy += dy;
}

void boxd_moveY(boxd_t *obj, double dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy += dy;
}

void boxld_moveY(boxld_t *obj, long double dy) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posy += dy;
}

// Move Z functions
void boxu8_moveZ(boxu8_t *obj, uint8_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow
    if (obj->_posz > UINT8_MAX - dz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posz += dz;
}

void boxi8_moveZ(boxi8_t *obj, int8_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow/underflow
    if ((dz > 0 && obj->_posz > INT8_MAX - dz) ||
        (dz < 0 && obj->_posz < INT8_MIN - dz)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posz += dz;
}

void boxu16_moveZ(boxu16_t *obj, uint16_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_posz > UINT16_MAX - dz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posz += dz;
}

void boxi16_moveZ(boxi16_t *obj, int16_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dz > 0 && obj->_posz > INT16_MAX - dz) ||
        (dz < 0 && obj->_posz < INT16_MIN - dz)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posz += dz;
}

void boxu32_moveZ(boxu32_t *obj, uint32_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_posz > UINT32_MAX - dz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posz += dz;
}

void boxi32_moveZ(boxi32_t *obj, int32_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dz > 0 && obj->_posz > INT32_MAX - dz) ||
        (dz < 0 && obj->_posz < INT32_MIN - dz)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posz += dz;
}

void boxu64_moveZ(boxu64_t *obj, uint64_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_posz > UINT64_MAX - dz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posz += dz;
}

void boxi64_moveZ(boxi64_t *obj, int64_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dz > 0 && obj->_posz > INT64_MAX - dz) ||
        (dz < 0 && obj->_posz < INT64_MIN - dz)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_posz += dz;
}

void boxf_moveZ(boxf_t *obj, float dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz += dz;
}

void boxd_moveZ(boxd_t *obj, double dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz += dz;
}

void boxld_moveZ(boxld_t *obj, long double dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_posz += dz;
}

// Move (dx, dy, dz) functions
void boxu8_move(boxu8_t *obj, uint8_t dx, uint8_t dy, uint8_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Check for potential overflow in X
    if (obj->_posx > UINT8_MAX - dx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    // Check for potential overflow in Y
    if (obj->_posy > UINT8_MAX - dy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    // Check for potential overflow in Z
    if (obj->_posz > UINT8_MAX - dz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

void boxi8_move(boxi8_t *obj, int8_t dx, int8_t dy, int8_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Check for potential overflow/underflow in X
    if ((dx > 0 && obj->_posx > INT8_MAX - dx) ||
        (dx < 0 && obj->_posx < INT8_MIN - dx)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    // Check for potential overflow/underflow in Y
    if ((dy > 0 && obj->_posy > INT8_MAX - dy) ||
        (dy < 0 && obj->_posy < INT8_MIN - dy)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    // Check for potential overflow/underflow in Z
    if ((dz > 0 && obj->_posz > INT8_MAX - dz) ||
        (dz < 0 && obj->_posz < INT8_MIN - dz)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

void boxu16_move(boxu16_t *obj, uint16_t dx, uint16_t dy, uint16_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if (obj->_posx > UINT16_MAX - dx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_posy > UINT16_MAX - dy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_posz > UINT16_MAX - dz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

void boxi16_move(boxi16_t *obj, int16_t dx, int16_t dy, int16_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if ((dx > 0 && obj->_posx > INT16_MAX - dx) ||
        (dx < 0 && obj->_posx < INT16_MIN - dx)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dy > 0 && obj->_posy > INT16_MAX - dy) ||
        (dy < 0 && obj->_posy < INT16_MIN - dy)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dz > 0 && obj->_posz > INT16_MAX - dz) ||
        (dz < 0 && obj->_posz < INT16_MIN - dz)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

void boxu32_move(boxu32_t *obj, uint32_t dx, uint32_t dy, uint32_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if (obj->_posx > UINT32_MAX - dx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_posy > UINT32_MAX - dy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_posz > UINT32_MAX - dz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

void boxi32_move(boxi32_t *obj, int32_t dx, int32_t dy, int32_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if ((dx > 0 && obj->_posx > INT32_MAX - dx) ||
        (dx < 0 && obj->_posx < INT32_MIN - dx)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dy > 0 && obj->_posy > INT32_MAX - dy) ||
        (dy < 0 && obj->_posy < INT32_MIN - dy)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dz > 0 && obj->_posz > INT32_MAX - dz) ||
        (dz < 0 && obj->_posz < INT32_MIN - dz)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

void boxu64_move(boxu64_t *obj, uint64_t dx, uint64_t dy, uint64_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if (obj->_posx > UINT64_MAX - dx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_posy > UINT64_MAX - dy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_posz > UINT64_MAX - dz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

void boxi64_move(boxi64_t *obj, int64_t dx, int64_t dy, int64_t dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if ((dx > 0 && obj->_posx > INT64_MAX - dx) ||
        (dx < 0 && obj->_posx < INT64_MIN - dx)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dy > 0 && obj->_posy > INT64_MAX - dy) ||
        (dy < 0 && obj->_posy < INT64_MIN - dy)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dz > 0 && obj->_posz > INT64_MAX - dz) ||
        (dz < 0 && obj->_posz < INT64_MIN - dz)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

void boxf_move(boxf_t *obj, float dx, float dy, float dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

void boxd_move(boxd_t *obj, double dx, double dy, double dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

void boxld_move(boxld_t *obj, long double dx, long double dy, long double dz) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    obj->_posx += dx;
    obj->_posy += dy;
    obj->_posz += dz;
}

// Resize Width functions
void boxu8_resizeWidth(boxu8_t *obj, uint8_t dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow
    if (obj->_width > UINT8_MAX - dw) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_width += dw;
}

void boxi8_resizeWidth(boxi8_t *obj, int8_t dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow/underflow
    if ((dw > 0 && obj->_width > INT8_MAX - dw) ||
        (dw < 0 && obj->_width < INT8_MIN - dw)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_width += dw;
}

void boxu16_resizeWidth(boxu16_t *obj, uint16_t dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_width > UINT16_MAX - dw) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_width += dw;
}

void boxi16_resizeWidth(boxi16_t *obj, int16_t dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dw > 0 && obj->_width > INT16_MAX - dw) ||
        (dw < 0 && obj->_width < INT16_MIN - dw)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_width += dw;
}

void boxu32_resizeWidth(boxu32_t *obj, uint32_t dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_width > UINT32_MAX - dw) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_width += dw;
}

void boxi32_resizeWidth(boxi32_t *obj, int32_t dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dw > 0 && obj->_width > INT32_MAX - dw) ||
        (dw < 0 && obj->_width < INT32_MIN - dw)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_width += dw;
}

void boxu64_resizeWidth(boxu64_t *obj, uint64_t dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_width > UINT64_MAX - dw) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_width += dw;
}

void boxi64_resizeWidth(boxi64_t *obj, int64_t dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dw > 0 && obj->_width > INT64_MAX - dw) ||
        (dw < 0 && obj->_width < INT64_MIN - dw)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_width += dw;
}

void boxf_resizeWidth(boxf_t *obj, float dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width += dw;
}

void boxd_resizeWidth(boxd_t *obj, double dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width += dw;
}

void boxld_resizeWidth(boxld_t *obj, long double dw) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_width += dw;
}

// Resize Height functions
void boxu8_resizeHeight(boxu8_t *obj, uint8_t dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow
    if (obj->_height > UINT8_MAX - dh) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_height += dh;
}

void boxi8_resizeHeight(boxi8_t *obj, int8_t dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow/underflow
    if ((dh > 0 && obj->_height > INT8_MAX - dh) ||
        (dh < 0 && obj->_height < INT8_MIN - dh)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_height += dh;
}

void boxu16_resizeHeight(boxu16_t *obj, uint16_t dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_height > UINT16_MAX - dh) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_height += dh;
}

void boxi16_resizeHeight(boxi16_t *obj, int16_t dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dh > 0 && obj->_height > INT16_MAX - dh) ||
        (dh < 0 && obj->_height < INT16_MIN - dh)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_height += dh;
}

void boxu32_resizeHeight(boxu32_t *obj, uint32_t dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_height > UINT32_MAX - dh) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_height += dh;
}

void boxi32_resizeHeight(boxi32_t *obj, int32_t dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dh > 0 && obj->_height > INT32_MAX - dh) ||
        (dh < 0 && obj->_height < INT32_MIN - dh)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_height += dh;
}

void boxu64_resizeHeight(boxu64_t *obj, uint64_t dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_height > UINT64_MAX - dh) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_height += dh;
}

void boxi64_resizeHeight(boxi64_t *obj, int64_t dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dh > 0 && obj->_height > INT64_MAX - dh) ||
        (dh < 0 && obj->_height < INT64_MIN - dh)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_height += dh;
}

void boxf_resizeHeight(boxf_t *obj, float dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height += dh;
}

void boxd_resizeHeight(boxd_t *obj, double dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height += dh;
}

void boxld_resizeHeight(boxld_t *obj, long double dh) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_height += dh;
}

// Resize Depth functions
void boxu8_resizeDepth(boxu8_t *obj, uint8_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow
    if (obj->_depth > UINT8_MAX - dd) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_depth += dd;
}

void boxi8_resizeDepth(boxi8_t *obj, int8_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    // Check for potential overflow/underflow
    if ((dd > 0 && obj->_depth > INT8_MAX - dd) ||
        (dd < 0 && obj->_depth < INT8_MIN - dd)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_depth += dd;
}

void boxu16_resizeDepth(boxu16_t *obj, uint16_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_depth > UINT16_MAX - dd) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_depth += dd;
}

void boxi16_resizeDepth(boxi16_t *obj, int16_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dd > 0 && obj->_depth > INT16_MAX - dd) ||
        (dd < 0 && obj->_depth < INT16_MIN - dd)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_depth += dd;
}

void boxu32_resizeDepth(boxu32_t *obj, uint32_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_depth > UINT32_MAX - dd) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_depth += dd;
}

void boxi32_resizeDepth(boxi32_t *obj, int32_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dd > 0 && obj->_depth > INT32_MAX - dd) ||
        (dd < 0 && obj->_depth < INT32_MIN - dd)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_depth += dd;
}

void boxu64_resizeDepth(boxu64_t *obj, uint64_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if (obj->_depth > UINT64_MAX - dd) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_depth += dd;
}

void boxi64_resizeDepth(boxi64_t *obj, int64_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    if ((dd > 0 && obj->_depth > INT64_MAX - dd) ||
        (dd < 0 && obj->_depth < INT64_MIN - dd)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }
    obj->_depth += dd;
}

void boxf_resizeDepth(boxf_t *obj, float dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth += dd;
}

void boxd_resizeDepth(boxd_t *obj, double dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth += dd;
}

void boxld_resizeDepth(boxld_t *obj, long double dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }
    obj->_depth += dd;
}

// Resize (dw, dh, dd) functions
void boxu8_resize(boxu8_t *obj, uint8_t dw, uint8_t dh, uint8_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Check for potential overflow in width
    if (obj->_width > UINT8_MAX - dw) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    // Check for potential overflow in height
    if (obj->_height > UINT8_MAX - dh) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    // Check for potential overflow in depth
    if (obj->_depth > UINT8_MAX - dd) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}

void boxi8_resize(boxi8_t *obj, int8_t dw, int8_t dh, int8_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Check for potential overflow/underflow in width
    if ((dw > 0 && obj->_width > INT8_MAX - dw) ||
        (dw < 0 && obj->_width < INT8_MIN - dw)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    // Check for potential overflow/underflow in height
    if ((dh > 0 && obj->_height > INT8_MAX - dh) ||
        (dh < 0 && obj->_height < INT8_MIN - dh)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    // Check for potential overflow/underflow in depth
    if ((dd > 0 && obj->_depth > INT8_MAX - dd) ||
        (dd < 0 && obj->_depth < INT8_MIN - dd)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}

void boxu16_resize(boxu16_t *obj, uint16_t dw, uint16_t dh, uint16_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if (obj->_width > UINT16_MAX - dw) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_height > UINT16_MAX - dh) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_depth > UINT16_MAX - dd) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}

void boxi16_resize(boxi16_t *obj, int16_t dw, int16_t dh, int16_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if ((dw > 0 && obj->_width > INT16_MAX - dw) ||
        (dw < 0 && obj->_width < INT16_MIN - dw)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dh > 0 && obj->_height > INT16_MAX - dh) ||
        (dh < 0 && obj->_height < INT16_MIN - dh)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dd > 0 && obj->_depth > INT16_MAX - dd) ||
        (dd < 0 && obj->_depth < INT16_MIN - dd)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}

void boxu32_resize(boxu32_t *obj, uint32_t dw, uint32_t dh, uint32_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if (obj->_width > UINT32_MAX - dw) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_height > UINT32_MAX - dh) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_depth > UINT32_MAX - dd) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}

void boxi32_resize(boxi32_t *obj, int32_t dw, int32_t dh, int32_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if ((dw > 0 && obj->_width > INT32_MAX - dw) ||
        (dw < 0 && obj->_width < INT32_MIN - dw)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dh > 0 && obj->_height > INT32_MAX - dh) ||
        (dh < 0 && obj->_height < INT32_MIN - dh)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dd > 0 && obj->_depth > INT32_MAX - dd) ||
        (dd < 0 && obj->_depth < INT32_MIN - dd)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}

void boxu64_resize(boxu64_t *obj, uint64_t dw, uint64_t dh, uint64_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if (obj->_width > UINT64_MAX - dw) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_height > UINT64_MAX - dh) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if (obj->_depth > UINT64_MAX - dd) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}

void boxi64_resize(boxi64_t *obj, int64_t dw, int64_t dh, int64_t dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    if ((dw > 0 && obj->_width > INT64_MAX - dw) ||
        (dw < 0 && obj->_width < INT64_MIN - dw)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dh > 0 && obj->_height > INT64_MAX - dh) ||
        (dh < 0 && obj->_height < INT64_MIN - dh)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    if ((dd > 0 && obj->_depth > INT64_MAX - dd) ||
        (dd < 0 && obj->_depth < INT64_MIN - dd)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}

void boxf_resize(boxf_t *obj, float dw, float dh, float dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}

void boxd_resize(boxd_t *obj, double dw, double dh, double dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}

void boxld_resize(boxld_t *obj, long double dw, long double dh, long double dd) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    obj->_width += dw;
    obj->_height += dh;
    obj->_depth += dd;
}



//Vector Extensions
#ifdef VEC3_DEFINED
//vec3 getPosition()
//YOU MUST FREE THIS MEMORY
vec3uint8_t * boxu8_getPosVec3(boxu8_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3U8(obj->_posx, obj->_posy, obj->_posz);
}
vec3int8_t * boxi8_getPosVec3(boxi8_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3I8(obj->_posx, obj->_posy, obj->_posz);
}
vec3uint16_t * boxu16_getPosVec3(boxu16_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3U16(obj->_posx, obj->_posy, obj->_posz);
}
vec3int16_t * boxi16_getPosVec3(boxi16_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3I16(obj->_posx, obj->_posy, obj->_posz);
}
vec3uint32_t * boxu32_getPosVec3(boxu32_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3U32(obj->_posx, obj->_posy, obj->_posz);
}
vec3int32_t * boxi32_getPosVec3(boxi32_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3I32(obj->_posx, obj->_posy, obj->_posz);
}
vec3uint64_t * boxu64_getPosVec3(boxu64_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3U64(obj->_posx, obj->_posy, obj->_posz);
}
vec3int64_t * boxi64_getPosVec3(boxi64_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3I64(obj->_posx, obj->_posy, obj->_posz);
}
vec3f_t * boxf_getPosVec3(boxf_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  // Check for NaN or infinity
  if (isnan(obj->_posx) || isnan(obj->_posy) ||
      isinf(obj->_posx) || isinf(obj->_posy) ||
      isnan(obj->_posz) || isinf(obj->_posz)) {
      box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
      return NULL;
  }

  return allocVec3F(obj->_posx, obj->_posy, obj->_posz);
}
vec3d_t * boxd_getPosVec3(boxd_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }

  // Check for NaN or infinity
  if (isnan(obj->_posx) || isnan(obj->_posy) ||
      isinf(obj->_posx) || isinf(obj->_posy) ||
      isnan(obj->_posz) || isinf(obj->_posz)) {
      box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
      return NULL;
  }

  return allocVec3D(obj->_posx, obj->_posy, obj->_posz);
}
vec3ld_t * boxld_getPosVec3(boxld_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  // Check for NaN or infinity
  if (isnan(obj->_posx) || isnan(obj->_posy) ||
      isinf(obj->_posx) || isinf(obj->_posy) ||
      isnan(obj->_posz) || isinf(obj->_posz)) {
      box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
      return NULL;
  }


  return allocVec3LD(obj->_posx, obj->_posy, obj->_posz);
}


//vec3 getSize()
//YOU MUST FREE THIS MEMORY
vec3uint8_t * boxu8_getSizeVec3(boxu8_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3U8(obj->_width, obj->_height, obj->_depth);
}
vec3int8_t * boxi8_getSizeVec3(boxi8_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3I8(obj->_width, obj->_height, obj->_depth);
}
vec3uint16_t * boxu16_getSizeVec3(boxu16_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3U16(obj->_width, obj->_height, obj->_depth);
}
vec3int16_t * boxi16_getSizeVec3(boxi16_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3I16(obj->_width, obj->_height, obj->_depth);
}
vec3uint32_t * boxu32_getSizeVec3(boxu32_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3U32(obj->_width, obj->_height, obj->_depth);
}
vec3int32_t * boxi32_getSizeVec3(boxi32_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3I32(obj->_width, obj->_height, obj->_depth);
}
vec3uint64_t * boxu64_getSizeVec3(boxu64_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3U64(obj->_width, obj->_height, obj->_depth);
}
vec3int64_t * boxi64_getSizeVec3(boxi64_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  return allocVec3I64(obj->_width, obj->_height, obj->_depth);
}
vec3f8_t * boxf_getSizeVec3(recf_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }
  // Check for NaN or infinity
  if (isnan(obj->_width) || isnan(obj->_height) ||
      isinf(obj->_width) || isinf(obj->_height) ||
      isinf(obj->_depth) || isnan(obj->_depth)){
      box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
      return NULL;
  }

  return allocVec3F(obj->_width, obj->_height, obj->_depth);
}
vec3f8_t * boxf_getSizeVec3(recf_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }

  // Check for NaN or infinity
  if (isnan(obj->_width) || isnan(obj->_height) ||
      isinf(obj->_width) || isinf(obj->_height) ||
      isinf(obj->_depth) || isnan(obj->_depth)){
      box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
      return NULL;
  }

  return allocVec3D(obj->_width, obj->_height, obj->_depth);
}
vec3ld_t * boxld_getSizeVec3(boxld_t * obj){
  if(obj == NULL){
    box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
    return NULL;
  }

  // Check for NaN or infinity
  if (isnan(obj->_width) || isnan(obj->_height) ||
      isinf(obj->_width) || isinf(obj->_height) ||
      isinf(obj->_depth) || isnan(obj->_depth)){
      box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
      return NULL;
  }

  return allocVec3LD(obj->_width, obj->_height, obj->_depth);
}

//setSizeVec3()
void boxu8_setSizeVec3(boxu8_t * obj, const vec3uint8_t * size){
  boxu8_setSize(obj,vec3u8_X(size),vec3u8_Y(size),vec3u8_Z(size));
}
void boxi8_setSizeVec3(boxi8_t * obj, const vec3int8_t * size){
  boxi8_setSize(obj,vec3i8_X(size),vec3i8_Y(size),vec3i8_Z(size));
}
void boxu16_setSizeVec3(boxu16_t * obj, const vec3uint16_t * size){
  boxu16_setSize(obj,vec3u16_X(size),vec3u16_Y(size),vec3u16_Z(size));
}
void boxi16_setSizeVec3(boxi16_t * obj, const vec3int16_t * size){
  boxi16_setSize(obj,vec3i16_X(size),vec3i16_Y(size),vec3i16_Z(size));
}
void boxu32_setSizeVec3(boxu32_t * obj, const vec3uint32_t * size){
  recu32t_setSize(obj,vec3u32_X(size),vec3u32_Y(size),vec3u32_Z(size));
}
void boxi32_setSizeVec3(boxi32_t * obj, const vec3int32_t * size){
  boxi32_setSize(obj,vec3i32_X(size),vec3i32_Y(size),vec3i32_Z(size));
}
void boxu64_setSizeVec3(boxu64_t * obj, const vec3uint64_t * size){
  boxu64_setSize(obj,vec3u64_X(size),vec3u64_Y(size),vec3u64_Z(size));
}
void boxi64_setSizeVec3(boxi64_t * obj, const vec3int64_t * size){
  boxi64_setSize(obj,vec3i64_X(size),vec3i64_Y(size),vec3i64_Z(size));
}
void boxf_setSizeVec3(boxf_t * obj, const vec3f_t * size){
  boxf_setSize(obj,vecf_X(size),vecf_Y(size),vecf_Z(size));
}
void boxd_setSizeVec3(boxd_t * obj, const vec3d_t * size){
  boxd_setSize(obj,vecd_X(size),vecd_Y(size),vecd_Z(size));
}
void boxld_setSizeVec3(boxld_t * obj, const vec3ld_t * size){
  boxld_setSize(obj,vecld_X(size),vecld_Y(size),vecld_Z(size));
}

//setPosVec3()
void boxu8_setPosVec3(boxu8_t * obj, const vec3uint8_t * pos){
  boxu8_setPos(obj,vec3u8_X(pos),vec3u8_Y(pos),vec3u8_Z(pos));
}
void boxi8_setPosVec3(boxi8_t * obj, const vec3int8_t * pos){
  boxi8_setPos(obj,vec3i8_X(pos),vec3i8_Y(pos),vec3i8_Z(pos));
}
void boxu16_setPosVec3(boxu16_t * obj, const vec3uint16_t * pos){
  boxu16_setPos(obj,vec3u16_X(pos),vec3u16_Y(pos),vec3u16_Z(pos));
}
void boxi16_setPosVec3(boxi16_t * obj, const vec3int16_t * pos){
  boxi16_setPos(obj,vec3i16_X(pos),vec3i16_Y(pos),vec3i16_Z(pos));
}
void boxu32_setPosVec3(boxu32_t * obj, const vec3uint32_t * pos){
  recu32t_setPos(obj,vec3u32_X(pos),vec3u32_Y(pos),vec3u32_Z(pos));
}
void boxi32_setPosVec3(boxi32_t * obj, const vec3int32_t * pos){
  boxi32_setPos(obj,vec3i32_X(pos),vec3i32_Y(pos),vec3i32_Z(pos));
}
void boxu64_setPosVec3(boxu64_t * obj, const vec3uint64_t * pos){
  boxu64_setPos(obj,vec3u64_X(pos),vec3u64_Y(pos),vec3u64_Z(pos));
}
void boxi64_setPosVec3(boxi64_t * obj, const vec3int64_t * pos){
  boxi64_setPos(obj,vec3i64_X(pos),vec3i64_Y(pos),vec3i64_Z(pos));
}
void boxf_setPosVec3(boxf_t * obj, const vec3f_t * pos){
  boxf_setPos(obj,vecf_X(pos),vecf_Y(pos),vecf_Z(pos));
}
void boxd_setPosVec3(boxd_t * obj, const vec3d_t * pos){
  boxd_setPos(obj,vecd_X(pos),vecd_Y(pos),vecd_Z(pos));
}
void boxld_setPosVec3(boxld_t * obj, const vec3ld_t * pos){
  boxld_setPos(obj,vecld_X(pos),vecld_Y(pos),vecld_Z(pos));
}

// moveVec3()
void boxu8_moveVec3(boxu8_t * obj, const vec3int8_t * delta){
  boxu8_move(obj,vec3u8_X(delta),vec3u8_Y(delta),vec3u8_Z(delta));
}
void boxi8_moveVec3(boxi8_t * obj, const vec3int8_t * delta){
  boxi8_move(obj,vec3i8_X(delta),vec3i8_Y(delta),vec3i8_Z(delta));
}
void boxu16_moveVec3(boxu16_t * obj, const vec3int16_t * delta){
  boxu16_move(obj,vec3u16_X(delta),vec3u16_Y(delta),vec3u16_Z(delta));
}
void boxi16_moveVec3(boxi16_t * obj, const vec3int16_t * delta){
  boxi16_move(obj,vec3i16_X(delta),vec3i16_Y(delta),vec3i16_Z(delta));
}
void boxu32_moveVec3(boxu32_t * obj, const vec3int32_t * delta){
  recu32t_move(obj,vec3u32_X(delta),vec3u32_Y(delta),vec3u32_Z(delta));
}
void boxi32_moveVec3(boxi32_t * obj, const vec3int32_t * delta){
  boxi32_move(obj,vec3i32_X(delta),vec3i32_Y(delta),vec3i32_Z(delta));
}
void boxu64_moveVec3(boxu64_t * obj, const vec3int64_t * delta){
  boxu64_move(obj,vec3u64_X(delta),vec3u64_Y(delta),vec3u64_Z(delta));
}
void boxi64_moveVec3(boxi64_t * obj, const vec3int64_t * delta){
  boxi64_move(obj,vec3i64_X(delta),vec3i64_Y(delta),vec3i64_Z(delta));
}
void boxf_moveVec3(boxf_t * obj, const vec3f_t * delta){
  boxf_move(obj,vecf_X(delta),vecf_Y(delta),vecf_Z(delta));
}
void boxd_moveVec3(boxd_t * obj, const vec3d_t * delta){
  boxd_move(obj,vecd_X(delta),vecd_Y(delta),vecd_Z(delta));
}
void boxld_moveVec3(boxld_t * obj, const vec3ld_t * delta){
  boxld_move(obj,vecld_X(delta),vecld_Y(delta),vecld_Z(delta));
}

// resizeVec3()
void boxu8_resizeVec3(boxu8_t * obj, const vec3uint8_t * delta){
  boxu8_resize(obj,vec3u8_X(delta),vec3u8_Y(delta),vec3u8_Z(delta));
}
void boxi8_resizeVec3(boxi8_t * obj, const vec3int8_t * delta){
  boxi8_resize(obj,vec3i8_X(delta),vec3i8_Y(delta),vec3i8_Z(delta));
}
void boxu16_resizeVec3(boxu16_t * obj, const vec3uint16_t * delta){
  boxu16_resize(obj,vec3u16_X(delta),vec3u16_Y(delta),vec3u16_Z(delta));
}
void boxi16_resizeVec3(boxi16_t * obj, const vec3int16_t * delta){
  boxi16_resize(obj,vec3i16_X(delta),vec3i16_Y(delta),vec3i16_Z(delta));
}
void boxu32_resizeVec3(boxu32_t * obj, const vec3uint32_t * delta){
  recu32t_resize(obj,vec3u32_X(delta),vec3u32_Y(delta),vec3u32_Z(delta));
}
void boxi32_resizeVec3(boxi32_t * obj, const vec3int32_t * delta){
  boxi32_resize(obj,vec3i32_X(delta),vec3i32_Y(delta),vec3i32_Z(delta));
}
void boxu64_resizeVec3(boxu64_t * obj, const vec3uint64_t * delta){
  boxu64_resize(obj,vec3u64_X(delta),vec3u64_Y(delta),vec3u64_Z(delta));
}
void boxi64_resizeVec3(boxi64_t * obj, const vec3int64_t * delta){
  boxi64_resize(obj,vec3i64_X(delta),vec3i64_Y(delta),vec3i64_Z(delta));
}
void boxf_resizeVec3(boxf_t * obj, const vec3f_t * delta){
  boxf_resize(obj,vecf_X(delta),vecf_Y(delta),vecf_Z(delta));
}
void boxd_resizeVec3(boxd_t * obj, const vec3d_t * delta){
  boxd_resize(obj,vecd_X(delta),vecd_Y(delta),vecd_Z(delta));
}
void boxld_resizeVec3(boxld_t * obj, const vec3ld_t * delta){
  boxld_resize(obj,vecld_X(delta),vecld_Y(delta),vecld_Z(delta));
}

#endif


// Helper function to check for overflow in unsigned addition
static bool check_unsigned_overflow(uintmax_t a, uintmax_t b, uintmax_t max) {
    return a > max - b;
}

// Helper function to check for overflow in signed addition
static bool check_signed_overflow(intmax_t a, intmax_t b, intmax_t min, intmax_t max) {
    if (b > 0) {
        return a > max - b;
    } else if (b < 0) {
        return a < min - b;
    }
    return false;
}

// getSideX()
uint8_t boxu8_getSideX(const boxu8_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posx, obj->_width, UINT8_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0;
    }

    return obj->_posx + obj->_width;
}
int8_t boxi8_getSideX(const boxi8_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_width < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Width cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posx, obj->_width, INT8_MIN, INT8_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0;
    }

    return obj->_posx + obj->_width;
}
uint16_t boxu16_getSideX(const boxu16_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posx, obj->_width, UINT16_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0;
    }

    return obj->_posx + obj->_width;
}
int16_t boxi16_getSideX(const boxi16_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_width < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Width cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posx, obj->_width, INT16_MIN, INT16_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0;
    }

    return obj->_posx + obj->_width;
}
uint32_t boxu32_getSideX(const boxu32_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posx, obj->_width, UINT32_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0;
    }

    return obj->_posx + obj->_width;
}
int32_t boxi32_getSideX(const boxi32_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_width < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Width cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posx, obj->_width, INT32_MIN, INT32_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0;
    }

    return obj->_posx + obj->_width;
}

uint64_t boxu64_getSideX(const boxu64_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posx, obj->_width, UINT64_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0;
    }

    return obj->_posx + obj->_width;
}

int64_t boxi64_getSideX(const boxi64_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_width < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Width cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posx, obj->_width, INT64_MIN, INT64_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0;
    }

    return obj->_posx + obj->_width;
}

float boxf_getSideX(const boxf_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0.0f;
    }

    // Check for negative dimensions
    if (obj->_width < 0.0f) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Width cannot be negative");
        return 0.0f;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posx) || isnan(obj->_width)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or width is NaN");
        return 0.0f;
    }

    if (isinf(obj->_posx) || isinf(obj->_width)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or width is infinite");
        return 0.0f;
    }

    // Check for overflow
    if (obj->_posx > 0 && obj->_width > FLT_MAX - obj->_posx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0.0f;
    }

    return obj->_posx + obj->_width;
}
double boxd_getSideX(const boxd_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0.0;
    }

    // Check for negative dimensions
    if (obj->_width < 0.0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Width cannot be negative");
        return 0.0;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posx) || isnan(obj->_width)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or width is NaN");
        return 0.0;
    }

    if (isinf(obj->_posx) || isinf(obj->_width)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or width is infinite");
        return 0.0;
    }

    // Check for overflow
    if (obj->_posx > 0 && obj->_width > DBL_MAX - obj->_posx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0.0;
    }

    return obj->_posx + obj->_width;
}
long double boxld_getSideX(const boxld_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0.0L;
    }

    // Check for negative dimensions
    if (obj->_width < 0.0L) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Width cannot be negative");
        return 0.0L;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posx) || isnan(obj->_width)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or width is NaN");
        return 0.0L;
    }

    if (isinf(obj->_posx) || isinf(obj->_width)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or width is infinite");
        return 0.0L;
    }

    // Check for overflow
    if (obj->_posx > 0 && obj->_width > LDBL_MAX - obj->_posx) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + width would cause overflow");
        return 0.0L;
    }

    return obj->_posx + obj->_width;
}

// Get Side Y (opposite Y-side position) functions
uint8_t boxu8_getSideY(const boxu8_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posy, obj->_height, UINT8_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0;
    }

    return obj->_posy + obj->_height;
}

int8_t boxi8_getSideY(const boxi8_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_height < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Height cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posy, obj->_height, INT8_MIN, INT8_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0;
    }

    return obj->_posy + obj->_height;
}

uint16_t boxu16_getSideY(const boxu16_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posy, obj->_height, UINT16_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0;
    }

    return obj->_posy + obj->_height;
}

int16_t boxi16_getSideY(const boxi16_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_height < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Height cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posy, obj->_height, INT16_MIN, INT16_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0;
    }

    return obj->_posy + obj->_height;
}

uint32_t boxu32_getSideY(const boxu32_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posy, obj->_height, UINT32_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0;
    }

    return obj->_posy + obj->_height;
}

int32_t boxi32_getSideY(const boxi32_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_height < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Height cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posy, obj->_height, INT32_MIN, INT32_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0;
    }

    return obj->_posy + obj->_height;
}

uint64_t boxu64_getSideY(const boxu64_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posy, obj->_height, UINT64_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0;
    }

    return obj->_posy + obj->_height;
}

int64_t boxi64_getSideY(const boxi64_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_height < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Height cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posy, obj->_height, INT64_MIN, INT64_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0;
    }

    return obj->_posy + obj->_height;
}

float boxf_getSideY(const boxf_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0.0f;
    }

    // Check for negative dimensions
    if (obj->_height < 0.0f) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Height cannot be negative");
        return 0.0f;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posy) || isnan(obj->_height)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or height is NaN");
        return 0.0f;
    }

    if (isinf(obj->_posy) || isinf(obj->_height)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or height is infinite");
        return 0.0f;
    }

    // Check for overflow
    if (obj->_posy > 0 && obj->_height > FLT_MAX - obj->_posy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0.0f;
    }

    return obj->_posy + obj->_height;
}

double boxd_getSideY(const boxd_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0.0;
    }

    // Check for negative dimensions
    if (obj->_height < 0.0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Height cannot be negative");
        return 0.0;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posy) || isnan(obj->_height)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or height is NaN");
        return 0.0;
    }

    if (isinf(obj->_posy) || isinf(obj->_height)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or height is infinite");
        return 0.0;
    }

    // Check for overflow
    if (obj->_posy > 0 && obj->_height > DBL_MAX - obj->_posy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0.0;
    }

    return obj->_posy + obj->_height;
}

long double boxld_getSideY(const boxld_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0.0L;
    }

    // Check for negative dimensions
    if (obj->_height < 0.0L) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Height cannot be negative");
        return 0.0L;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posy) || isnan(obj->_height)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or height is NaN");
        return 0.0L;
    }

    if (isinf(obj->_posy) || isinf(obj->_height)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or height is infinite");
        return 0.0L;
    }

    // Check for overflow
    if (obj->_posy > 0 && obj->_height > LDBL_MAX - obj->_posy) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + height would cause overflow");
        return 0.0L;
    }

    return obj->_posy + obj->_height;
}
// Get Side Z (opposite Z-side position) functions
uint8_t boxu8_getSideZ(const boxu8_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posz, obj->_depth, UINT8_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0;
    }

    return obj->_posz + obj->_depth;
}

int8_t boxi8_getSideZ(const boxi8_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_depth < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Depth cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posz, obj->_depth, INT8_MIN, INT8_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0;
    }

    return obj->_posz + obj->_depth;
}

uint16_t boxu16_getSideZ(const boxu16_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posz, obj->_depth, UINT16_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0;
    }

    return obj->_posz + obj->_depth;
}

int16_t boxi16_getSideZ(const boxi16_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_depth < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Depth cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posz, obj->_depth, INT16_MIN, INT16_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0;
    }

    return obj->_posz + obj->_depth;
}

uint32_t boxu32_getSideZ(const boxu32_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posz, obj->_depth, UINT32_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0;
    }

    return obj->_posz + obj->_depth;
}

int32_t boxi32_getSideZ(const boxi32_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_depth < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Depth cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posz, obj->_depth, INT32_MIN, INT32_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0;
    }

    return obj->_posz + obj->_depth;
}

uint64_t boxu64_getSideZ(const boxu64_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for overflow
    if (check_unsigned_overflow(obj->_posz, obj->_depth, UINT64_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0;
    }

    return obj->_posz + obj->_depth;
}

int64_t boxi64_getSideZ(const boxi64_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0;
    }

    // Check for negative dimensions
    if (obj->_depth < 0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Depth cannot be negative");
        return 0;
    }

    // Check for overflow
    if (check_signed_overflow(obj->_posz, obj->_depth, INT64_MIN, INT64_MAX)) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0;
    }

    return obj->_posz + obj->_depth;
}

float boxf_getSideZ(const boxf_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0.0f;
    }

    // Check for negative dimensions
    if (obj->_depth < 0.0f) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Depth cannot be negative");
        return 0.0f;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posz) || isnan(obj->_depth)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or depth is NaN");
        return 0.0f;
    }

    if (isinf(obj->_posz) || isinf(obj->_depth)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or depth is infinite");
        return 0.0f;
    }

    // Check for overflow
    if (obj->_posz > 0 && obj->_depth > FLT_MAX - obj->_posz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0.0f;
    }

    return obj->_posz + obj->_depth;
}

double boxd_getSideZ(const boxd_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0.0;
    }

    // Check for negative dimensions
    if (obj->_depth < 0.0) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Depth cannot be negative");
        return 0.0;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posz) || isnan(obj->_depth)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or depth is NaN");
        return 0.0;
    }

    if (isinf(obj->_posz) || isinf(obj->_depth)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or depth is infinite");
        return 0.0;
    }

    // Check for overflow
    if (obj->_posz > 0 && obj->_depth > DBL_MAX - obj->_posz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0.0;
    }

    return obj->_posz + obj->_depth;
}

long double boxld_getSideZ(const boxld_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot get side from NULL object");
        return 0.0L;
    }

    // Check for negative dimensions
    if (obj->_depth < 0.0L) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Depth cannot be negative");
        return 0.0L;
    }

    // Check for NaN or infinity
    if (isnan(obj->_posz) || isnan(obj->_depth)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or depth is NaN");
        return 0.0L;
    }

    if (isinf(obj->_posz) || isinf(obj->_depth)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Position or depth is infinite");
        return 0.0L;
    }

    // Check for overflow
    if (obj->_posz > 0 && obj->_depth > LDBL_MAX - obj->_posz) {
        box_last_error = BOX_ERROR_OVERFLOW;
        box_set_error_string("Position + depth would cause overflow");
        return 0.0L;
    }

    return obj->_posz + obj->_depth;
}

// Volume functions
uint8_t boxu8_volume(const boxu8_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }

    // Check for potential overflow
    uint16_t volume = (uint16_t)obj->_width * (uint16_t)obj->_height * (uint16_t)obj->_depth;
    if (volume > UINT8_MAX) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return 0;
    }

    return (uint8_t)volume;
}

int8_t boxi8_volume(const boxi8_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }

    // Check for potential overflow/underflow
    int16_t volume = (int16_t)obj->_width * (int16_t)obj->_height * (int16_t)obj->_depth;
    if (volume > INT8_MAX || volume < INT8_MIN) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return 0;
    }

    return (int8_t)volume;
}

uint16_t boxu16_volume(const boxu16_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }

    // Check for potential overflow
    uint32_t volume = (uint32_t)obj->_width * (uint32_t)obj->_height * (uint32_t)obj->_depth;
    if (volume > UINT16_MAX) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return 0;
    }

    return (uint16_t)volume;
}

int16_t boxi16_volume(const boxi16_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }

    // Check for potential overflow/underflow
    int32_t volume = (int32_t)obj->_width * (int32_t)obj->_height * (int32_t)obj->_depth;
    if (volume > INT16_MAX || volume < INT16_MIN) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return 0;
    }

    return (int16_t)volume;
}

uint32_t boxu32_volume(const boxu32_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }

    // Check for potential overflow
    uint64_t volume = (uint64_t)obj->_width * (uint64_t)obj->_height * (uint64_t)obj->_depth;
    if (volume > UINT32_MAX) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return 0;
    }

    return (uint32_t)volume;
}

int32_t boxi32_volume(const boxi32_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }

    // Check for potential overflow/underflow
    int64_t volume = (int64_t)obj->_width * (int64_t)obj->_height * (int64_t)obj->_depth;
    if (volume > INT32_MAX || volume < INT32_MIN) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return 0;
    }

    return (int32_t)volume;
}

uint64_t boxu64_volume(const boxu64_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }

    // For 64-bit, we need to check for overflow carefully
    // We'll use a temporary variable and check for overflow during multiplication
    uint64_t volume = obj->_width;

    // Check first multiplication
    if (obj->_height > 0 && volume > UINT64_MAX / obj->_height) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return 0;
    }
    volume *= obj->_height;

    // Check second multiplication
    if (obj->_depth > 0 && volume > UINT64_MAX / obj->_depth) {
        box_last_error = BOX_ERROR_OVERFLOW;
        return 0;
    }
    volume *= obj->_depth;

    return volume;
}

int64_t boxi64_volume(const boxi64_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0;
    }

    // For 64-bit signed, we need to check for overflow carefully
    int64_t volume = obj->_width;

    // Check first multiplication
    if (volume > 0) {
        if (obj->_height > 0 && volume > INT64_MAX / obj->_height) {
            box_last_error = BOX_ERROR_OVERFLOW;
            return 0;
        }
        if (obj->_height < 0 && volume > INT64_MIN / obj->_height) {
            box_last_error = BOX_ERROR_OVERFLOW;
            return 0;
        }
    } else if (volume < 0) {
        if (obj->_height > 0 && volume < INT64_MIN / obj->_height) {
            box_last_error = BOX_ERROR_OVERFLOW;
            return 0;
        }
        if (obj->_height < 0 && volume < INT64_MAX / obj->_height) {
            box_last_error = BOX_ERROR_OVERFLOW;
            return 0;
        }
    }
    volume *= obj->_height;

    // Check second multiplication
    if (volume > 0) {
        if (obj->_depth > 0 && volume > INT64_MAX / obj->_depth) {
            box_last_error = BOX_ERROR_OVERFLOW;
            return 0;
        }
        if (obj->_depth < 0 && volume > INT64_MIN / obj->_depth) {
            box_last_error = BOX_ERROR_OVERFLOW;
            return 0;
        }
    } else if (volume < 0) {
        if (obj->_depth > 0 && volume < INT64_MIN / obj->_depth) {
            box_last_error = BOX_ERROR_OVERFLOW;
            return 0;
        }
        if (obj->_depth < 0 && volume < INT64_MAX / obj->_depth) {
            box_last_error = BOX_ERROR_OVERFLOW;
            return 0;
        }
    }
    volume *= obj->_depth;

    return volume;
}

float boxf_volume(const boxf_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0f;
    }
    return obj->_width * obj->_height * obj->_depth;
}

double boxd_volume(const boxd_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0;
    }
    return obj->_width * obj->_height * obj->_depth;
}

long double boxld_volume(const boxld_t *obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return 0.0L;
    }
    return obj->_width * obj->_height * obj->_depth;
}

#ifdef HAS_RECT

// frontRect() functions
rectu8_t * boxu8_frontRect(boxu8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu8_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

recti8_t * boxi8_frontRect(boxi8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti8_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectu16_t * boxu16_frontRect(boxu16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu16_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

recti16_t * boxi16_frontRect(boxi16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti16_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectu32_t * boxu32_frontRect(boxu32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu32_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

recti32_t * boxi32_frontRect(boxi32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti32_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectu64_t * boxu64_frontRect(boxu64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu64_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

recti64_t * boxi64_frontRect(boxi64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti64_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectf_t * boxf_frontRect(boxf_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectf_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectd_t * boxd_frontRect(boxd_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectd_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectld_t * boxld_frontRect(boxld_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectld_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

// backRect() functions
rectu8_t * boxu8_backRect(boxu8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu8_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

recti8_t * boxi8_backRect(boxi8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti8_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectu16_t * boxu16_backRect(boxu16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu16_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

recti16_t * boxi16_backRect(boxi16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti16_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectu32_t * boxu32_backRect(boxu32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu32_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

recti32_t * boxi32_backRect(boxi32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti32_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectu64_t * boxu64_backRect(boxu64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu64_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

recti64_t * boxi64_backRect(boxi64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti64_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectf_t * boxf_backRect(boxf_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectf_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectd_t * boxd_backRect(boxd_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectd_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

rectld_t * boxld_backRect(boxld_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectld_malloc(obj->_posx, obj->_posy, obj->_width, obj->_height);
}

// leftRect() functions
rectu8_t * boxu8_leftRect(boxu8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu8_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

recti8_t * boxi8_leftRect(boxi8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti8_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectu16_t * boxu16_leftRect(boxu16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu16_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

recti16_t * boxi16_leftRect(boxi16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti16_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectu32_t * boxu32_leftRect(boxu32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu32_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

recti32_t * boxi32_leftRect(boxi32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti32_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectu64_t * boxu64_leftRect(boxu64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu64_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

recti64_t * boxi64_leftRect(boxi64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti64_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectf_t * boxf_leftRect(boxf_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectf_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectd_t * boxd_leftRect(boxd_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectd_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectld_t * boxld_leftRect(boxld_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectld_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

// rightRect() functions
rectu8_t * boxu8_rightRect(boxu8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu8_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

recti8_t * boxi8_rightRect(boxi8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti8_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectu16_t * boxu16_rightRect(boxu16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu16_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

recti16_t * boxi16_rightRect(boxi16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti16_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectu32_t * boxu32_rightRect(boxu32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu32_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

recti32_t * boxi32_rightRect(boxi32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti32_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectu64_t * boxu64_rightRect(boxu64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu64_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

recti64_t * boxi64_rightRect(boxi64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti64_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectf_t * boxf_rightRect(boxf_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectf_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectd_t * boxd_rightRect(boxd_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectd_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

rectld_t * boxld_rightRect(boxld_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectld_malloc(obj->_posz, obj->_posy, obj->_depth, obj->_height);
}

// topRect() functions
rectu8_t * boxu8_topRect(boxu8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu8_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

recti8_t * boxi8_topRect(boxi8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti8_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectu16_t * boxu16_topRect(boxu16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu16_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

recti16_t * boxi16_topRect(boxi16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti16_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectu32_t * boxu32_topRect(boxu32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu32_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

recti32_t * boxi32_topRect(boxi32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti32_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectu64_t * boxu64_topRect(boxu64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu64_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

recti64_t * boxi64_topRect(boxi64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti64_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectf_t * boxf_topRect(boxf_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectf_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectd_t * boxd_topRect(boxd_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectd_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectld_t * boxld_topRect(boxld_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectld_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

// bottomRect() functions
rectu8_t * boxu8_bottomRect(boxu8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu8_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

recti8_t * boxi8_bottomRect(boxi8_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti8_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectu16_t * boxu16_bottomRect(boxu16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu16_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

recti16_t * boxi16_bottomRect(boxi16_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti16_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectu32_t * boxu32_bottomRect(boxu32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu32_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

recti32_t * boxi32_bottomRect(boxi32_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti32_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectu64_t * boxu64_bottomRect(boxu64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectu64_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

recti64_t * boxi64_bottomRect(boxi64_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return recti64_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectf_t * boxf_bottomRect(boxf_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectf_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectd_t * boxd_bottomRect(boxd_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectd_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

rectld_t * boxld_bottomRect(boxld_t * obj) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return NULL;
    }
    return rectld_malloc(obj->_posx, obj->_posz, obj->_width, obj->_depth);
}

#endif // HAS_RECT

// collides() functions
bool boxu8_collides(const boxu8_t *obj, const boxu8_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    // Check if boxes overlap in all three dimensions
    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

bool boxi8_collides(const boxi8_t *obj, const boxi8_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

bool boxu16_collides(const boxu16_t *obj, const boxu16_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

bool boxi16_collides(const boxi16_t *obj, const boxi16_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

bool boxu32_collides(const boxu32_t *obj, const boxu32_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

bool boxi32_collides(const boxi32_t *obj, const boxi32_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

bool boxu64_collides(const boxu64_t *obj, const boxu64_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

bool boxi64_collides(const boxi64_t *obj, const boxi64_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

bool boxf_collides(const boxf_t *obj, const boxf_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

bool boxd_collides(const boxd_t *obj, const boxd_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

bool boxld_collides(const boxld_t *obj, const boxld_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (obj->_posx < other->_posx + other->_width &&
            obj->_posx + obj->_width > other->_posx &&
            obj->_posy < other->_posy + other->_height &&
            obj->_posy + obj->_height > other->_posy &&
            obj->_posz < other->_posz + other->_depth &&
            obj->_posz + obj->_depth > other->_posz);
}

// contains_point() functions
bool boxu8_contains_point(const boxu8_t *obj, uint8_t x, uint8_t y, uint8_t z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

bool boxi8_contains_point(const boxi8_t *obj, int8_t x, int8_t y, int8_t z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

bool boxu16_contains_point(const boxu16_t *obj, uint16_t x, uint16_t y, uint16_t z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

bool boxi16_contains_point(const boxi16_t *obj, int16_t x, int16_t y, int16_t z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

bool boxu32_contains_point(const boxu32_t *obj, uint32_t x, uint32_t y, uint32_t z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

bool boxi32_contains_point(const boxi32_t *obj, int32_t x, int32_t y, int32_t z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

bool boxu64_contains_point(const boxu64_t *obj, uint64_t x, uint64_t y, uint64_t z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

bool boxi64_contains_point(const boxi64_t *obj, int64_t x, int64_t y, int64_t z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

bool boxf_contains_point(const boxf_t *obj, float x, float y, float z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

bool boxd_contains_point(const boxd_t *obj, double x, double y, double z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

bool boxld_contains_point(const boxld_t *obj, long double x, long double y, long double z) {
    if (!obj) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (x >= obj->_posx && x <= obj->_posx + obj->_width &&
            y >= obj->_posy && y <= obj->_posy + obj->_height &&
            z >= obj->_posz && z <= obj->_posz + obj->_depth);
}

// contains_box() functions
bool boxu8_contains_box(const boxu8_t *obj, const boxu8_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

bool boxi8_contains_box(const boxi8_t *obj, const boxi8_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

bool boxu16_contains_box(const boxu16_t *obj, const boxu16_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

bool boxi16_contains_box(const boxi16_t *obj, const boxi16_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

bool boxu32_contains_box(const boxu32_t *obj, const boxu32_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

bool boxi32_contains_box(const boxi32_t *obj, const boxi32_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

bool boxu64_contains_box(const boxu64_t *obj, const boxu64_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

bool boxi64_contains_box(const boxi64_t *obj, const boxi64_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

bool boxf_contains_box(const boxf_t *obj, const boxf_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

bool boxd_contains_box(const boxd_t *obj, const boxd_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

bool boxld_contains_box(const boxld_t *obj, const boxld_t *other) {
    if (!obj || !other) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return false;
    }

    return (other->_posx >= obj->_posx &&
            other->_posy >= obj->_posy &&
            other->_posz >= obj->_posz &&
            other->_posx + other->_width <= obj->_posx + obj->_width &&
            other->_posy + other->_height <= obj->_posy + obj->_height &&
            other->_posz + other->_depth <= obj->_posz + obj->_depth);
}

// Helper function to check for NULL pointers and set error
static int box_intersection_check_null(const void* left, const void* right, const void* result) {
    if (!left || !right || !result) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot calculate intersection with NULL box objects");
        return 0;
    }
    return 1;
}

// 8-bit unsigned version
bool boxu8_intersection(const boxu8_t* left, const boxu8_t* right, boxu8_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    uint8_t x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    uint8_t y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    uint8_t z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    uint8_t x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
                left->_posx + left->_width : right->_posx + right->_width;
    uint8_t y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
                left->_posy + left->_height : right->_posy + right->_height;
    uint8_t z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
                left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0;
        result->_posy = 0;
        result->_posz = 0;
        result->_width = 0;
        result->_height = 0;
        result->_depth = 0;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}

bool boxi8_intersection(const boxi8_t* left, const boxi8_t* right, boxi8_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    int8_t x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    int8_t y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    int8_t z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    int8_t x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
               left->_posx + left->_width : right->_posx + right->_width;
    int8_t y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
               left->_posy + left->_height : right->_posy + right->_height;
    int8_t z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
               left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0;
        result->_posy = 0;
        result->_posz = 0;
        result->_width = 0;
        result->_height = 0;
        result->_depth = 0;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}

bool boxu16_intersection(const boxu16_t* left, const boxu16_t* right, boxu16_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    uint16_t x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    uint16_t y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    uint16_t z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    uint16_t x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
                 left->_posx + left->_width : right->_posx + right->_width;
    uint16_t y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
                 left->_posy + left->_height : right->_posy + right->_height;
    uint16_t z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
                 left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0;
        result->_posy = 0;
        result->_posz = 0;
        result->_width = 0;
        result->_height = 0;
        result->_depth = 0;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}

bool boxi16_intersection(const boxi16_t* left, const boxi16_t* right, boxi16_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    int16_t x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    int16_t y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    int16_t z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    int16_t x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
                left->_posx + left->_width : right->_posx + right->_width;
    int16_t y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
                left->_posy + left->_height : right->_posy + right->_height;
    int16_t z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
                left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0;
        result->_posy = 0;
        result->_posz = 0;
        result->_width = 0;
        result->_height = 0;
        result->_depth = 0;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}

bool boxu32_intersection(const boxu32_t* left, const boxu32_t* right, boxu32_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    uint32_t x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    uint32_t y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    uint32_t z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    uint32_t x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
                 left->_posx + left->_width : right->_posx + right->_width;
    uint32_t y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
                 left->_posy + left->_height : right->_posy + right->_height;
    uint32_t z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
                 left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0;
        result->_posy = 0;
        result->_posz = 0;
        result->_width = 0;
        result->_height = 0;
        result->_depth = 0;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}

bool boxi32_intersection(const boxi32_t* left, const boxi32_t* right, boxi32_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    int32_t x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    int32_t y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    int32_t z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    int32_t x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
                left->_posx + left->_width : right->_posx + right->_width;
    int32_t y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
                left->_posy + left->_height : right->_posy + right->_height;
    int32_t z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
                left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0;
        result->_posy = 0;
        result->_posz = 0;
        result->_width = 0;
        result->_height = 0;
        result->_depth = 0;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}

bool boxu64_intersection(const boxu64_t* left, const boxu64_t* right, boxu64_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    uint64_t x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    uint64_t y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    uint64_t z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    uint64_t x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
                 left->_posx + left->_width : right->_posx + right->_width;
    uint64_t y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
                 left->_posy + left->_height : right->_posy + right->_height;
    uint64_t z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
                 left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0;
        result->_posy = 0;
        result->_posz = 0;
        result->_width = 0;
        result->_height = 0;
        result->_depth = 0;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}

bool boxi64_intersection(const boxi64_t* left, const boxi64_t* right, boxi64_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    int64_t x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    int64_t y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    int64_t z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    int64_t x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
                left->_posx + left->_width : right->_posx + right->_width;
    int64_t y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
                left->_posy + left->_height : right->_posy + right->_height;
    int64_t z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
                left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0;
        result->_posy = 0;
        result->_posz = 0;
        result->_width = 0;
        result->_height = 0;
        result->_depth = 0;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}

bool boxf_intersection(const boxf_t* left, const boxf_t* right, boxf_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    float x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    float y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    float z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    float x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
              left->_posx + left->_width : right->_posx + right->_width;
    float y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
              left->_posy + left->_height : right->_posy + right->_height;
    float z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
              left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0.0f;
        result->_posy = 0.0f;
        result->_posz = 0.0f;
        result->_width = 0.0f;
        result->_height = 0.0f;
        result->_depth = 0.0f;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}


bool boxd_intersection(const boxd_t* left, const boxd_t* right, boxd_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    double x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    double y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    double z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    double x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
               left->_posx + left->_width : right->_posx + right->_width;
    double y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
               left->_posy + left->_height : right->_posy + right->_height;
    double z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
               left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0.0;
        result->_posy = 0.0;
        result->_posz = 0.0;
        result->_width = 0.0;
        result->_height = 0.0;
        result->_depth = 0.0;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}


bool boxld_intersection(const boxld_t* left, const boxld_t* right, boxld_t* result) {
    if (!box_intersection_check_null(left, right, result)) return false;

    long double x1 = (left->_posx > right->_posx) ? left->_posx : right->_posx;
    long double y1 = (left->_posy > right->_posy) ? left->_posy : right->_posy;
    long double z1 = (left->_posz > right->_posz) ? left->_posz : right->_posz;

    long double x2 = (left->_posx + left->_width < right->_posx + right->_width) ?
                   left->_posx + left->_width : right->_posx + right->_width;
    long double y2 = (left->_posy + left->_height < right->_posy + right->_height) ?
                   left->_posy + left->_height : right->_posy + right->_height;
    long double z2 = (left->_posz + left->_depth < right->_posz + right->_depth) ?
                   left->_posz + left->_depth : right->_posz + right->_depth;

    // Check if intersection is valid
    if (x1 >= x2 || y1 >= y2 || z1 >= z2) {
        // No intersection
        result->_posx = 0.0L;
        result->_posy = 0.0L;
        result->_posz = 0.0L;
        result->_width = 0.0L;
        result->_height = 0.0L;
        result->_depth = 0.0L;
        return false;
    }

    result->_posx = x1;
    result->_posy = y1;
    result->_posz = z1;
    result->_width = x2 - x1;
    result->_height = y2 - y1;
    result->_depth = z2 - z1;

    return true;
}


//Union Helper function to check for NULL pointers and set error
static int box_union_check_null(const void* left, const void* right, const void* result) {
    if (!left || !right || !result) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot calculate union with NULL box objects");
        return 0;
    }
    return 1;
}

//union()
void boxu8_union(const boxu8_t* left, const boxu8_t* right, boxu8_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    uint8_t min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    uint8_t min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    uint8_t min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    uint8_t max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                   left->_posx + left->_width : right->_posx + right->_width;
    uint8_t max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                   left->_posy + left->_height : right->_posy + right->_height;
    uint8_t max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                   left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

void boxi8_union(const boxi8_t* left, const boxi8_t* right, boxi8_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    int8_t min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    int8_t min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    int8_t min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    int8_t max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                  left->_posx + left->_width : right->_posx + right->_width;
    int8_t max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                  left->_posy + left->_height : right->_posy + right->_height;
    int8_t max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                  left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

void boxu16_union(const boxu16_t* left, const boxu16_t* right, boxu16_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    uint16_t min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    uint16_t min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    uint16_t min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    uint16_t max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                    left->_posx + left->_width : right->_posx + right->_width;
    uint16_t max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                    left->_posy + left->_height : right->_posy + right->_height;
    uint16_t max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                    left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

void boxi16_union(const boxi16_t* left, const boxi16_t* right, boxi16_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    int16_t min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    int16_t min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    int16_t min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    int16_t max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                   left->_posx + left->_width : right->_posx + right->_width;
    int16_t max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                   left->_posy + left->_height : right->_posy + right->_height;
    int16_t max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                   left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

void boxu32_union(const boxu32_t* left, const boxu32_t* right, boxu32_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    uint32_t min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    uint32_t min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    uint32_t min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    uint32_t max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                    left->_posx + left->_width : right->_posx + right->_width;
    uint32_t max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                    left->_posy + left->_height : right->_posy + right->_height;
    uint32_t max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                    left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

void boxi32_union(const boxi32_t* left, const boxi32_t* right, boxi32_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    int32_t min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    int32_t min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    int32_t min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    int32_t max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                   left->_posx + left->_width : right->_posx + right->_width;
    int32_t max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                   left->_posy + left->_height : right->_posy + right->_height;
    int32_t max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                   left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

void boxu64_union(const boxu64_t* left, const boxu64_t* right, boxu64_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    uint64_t min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    uint64_t min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    uint64_t min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    uint64_t max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                    left->_posx + left->_width : right->_posx + right->_width;
    uint64_t max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                    left->_posy + left->_height : right->_posy + right->_height;
    uint64_t max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                    left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

void boxi64_union(const boxi64_t* left, const boxi64_t* right, boxi64_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    int64_t min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    int64_t min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    int64_t min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    int64_t max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                   left->_posx + left->_width : right->_posx + right->_width;
    int64_t max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                   left->_posy + left->_height : right->_posy + right->_height;
    int64_t max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                   left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

void boxf_union(const boxf_t* left, const boxf_t* right, boxf_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    float min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    float min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    float min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    float max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                 left->_posx + left->_width : right->_posx + right->_width;
    float max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                 left->_posy + left->_height : right->_posy + right->_height;
    float max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                 left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

void boxd_union(const boxd_t* left, const boxd_t* right, boxd_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    double min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    double min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    double min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    double max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                  left->_posx + left->_width : right->_posx + right->_width;
    double max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                  left->_posy + left->_height : right->_posy + right->_height;
    double max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                  left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

void boxld_union(const boxld_t* left, const boxld_t* right, boxld_t* result) {
    if (!box_union_check_null(left, right, result)) return;

    long double min_x = (left->_posx < right->_posx) ? left->_posx : right->_posx;
    long double min_y = (left->_posy < right->_posy) ? left->_posy : right->_posy;
    long double min_z = (left->_posz < right->_posz) ? left->_posz : right->_posz;

    long double max_x = (left->_posx + left->_width > right->_posx + right->_width) ?
                      left->_posx + left->_width : right->_posx + right->_width;
    long double max_y = (left->_posy + left->_height > right->_posy + right->_height) ?
                      left->_posy + left->_height : right->_posy + right->_height;
    long double max_z = (left->_posz + left->_depth > right->_posz + right->_depth) ?
                      left->_posz + left->_depth : right->_posz + right->_depth;

    result->_posx = min_x;
    result->_posy = min_y;
    result->_posz = min_z;
    result->_width = max_x - min_x;
    result->_height = max_y - min_y;
    result->_depth = max_z - min_z;
}

//clamp()
void boxu8_clamp(boxu8_t* obj, const boxu8_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // For unsigned types, dimensions are always non-negative
    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        uint8_t* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        uint8_t* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const uint8_t bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const uint8_t bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        // Calculate bounds
        const uint8_t bounds_min = bounds_pos;
        const uint8_t bounds_max = bounds_pos + bounds_size;

        // Clamp position
        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0;
        }

        // Clamp size
        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}

void boxi8_clamp(boxi8_t* obj, const boxi8_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // Validate dimensions
    if (!VALIDATE_INT_DIMENSIONS(bounds) || !VALIDATE_INT_DIMENSIONS(obj)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        int8_t* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        int8_t* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const int8_t bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const int8_t bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        const int8_t bounds_min = bounds_pos;
        const int8_t bounds_max = bounds_pos + bounds_size;

        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0;
        }

        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}

void boxu16_clamp(boxu16_t* obj, const boxu16_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // For unsigned types, dimensions are always non-negative
    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        uint16_t* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        uint16_t* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const uint16_t bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const uint16_t bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        const uint16_t bounds_min = bounds_pos;
        const uint16_t bounds_max = bounds_pos + bounds_size;

        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0;
        }

        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}

void boxi16_clamp(boxi16_t* obj, const boxi16_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // Validate dimensions
    if (!VALIDATE_INT_DIMENSIONS(bounds) || !VALIDATE_INT_DIMENSIONS(obj)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        int16_t* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        int16_t* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const int16_t bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const int16_t bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        const int16_t bounds_min = bounds_pos;
        const int16_t bounds_max = bounds_pos + bounds_size;

        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0;
        }

        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}

void boxu32_clamp(boxu32_t* obj, const boxu32_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // For unsigned types, dimensions are always non-negative
    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        uint32_t* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        uint32_t* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const uint32_t bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const uint32_t bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        const uint32_t bounds_min = bounds_pos;
        const uint32_t bounds_max = bounds_pos + bounds_size;

        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0;
        }

        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}

void boxi32_clamp(boxi32_t* obj, const boxi32_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // Validate dimensions
    if (!VALIDATE_INT_DIMENSIONS(bounds) || !VALIDATE_INT_DIMENSIONS(obj)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        int32_t* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        int32_t* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const int32_t bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const int32_t bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        const int32_t bounds_min = bounds_pos;
        const int32_t bounds_max = bounds_pos + bounds_size;

        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0;
        }

        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}

void boxu64_clamp(boxu64_t* obj, const boxu64_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // For unsigned types, dimensions are always non-negative
    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        uint64_t* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        uint64_t* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const uint64_t bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const uint64_t bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        const uint64_t bounds_min = bounds_pos;
        const uint64_t bounds_max = bounds_pos + bounds_size;

        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0;
        }

        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}

void boxi64_clamp(boxi64_t* obj, const boxi64_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // Validate dimensions
    if (!VALIDATE_INT_DIMENSIONS(bounds) || !VALIDATE_INT_DIMENSIONS(obj)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        int64_t* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        int64_t* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const int64_t bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const int64_t bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        const int64_t bounds_min = bounds_pos;
        const int64_t bounds_max = bounds_pos + bounds_size;

        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0;
        }

        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}

void boxf_clamp(boxf_t* obj, const boxf_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // Validate dimensions
    if (!VALIDATE_FLOAT_DIMENSIONS(bounds) || !VALIDATE_FLOAT_DIMENSIONS(obj)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        float* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        float* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const float bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const float bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        const float bounds_min = bounds_pos;
        const float bounds_max = bounds_pos + bounds_size;

        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0.0f;
        }

        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}

void boxd_clamp(boxd_t* obj, const boxd_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // Validate dimensions
    if (!VALIDATE_FLOAT_DIMENSIONS(bounds) || !VALIDATE_FLOAT_DIMENSIONS(obj)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        double* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        double* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const double bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const double bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        const double bounds_min = bounds_pos;
        const double bounds_max = bounds_pos + bounds_size;

        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0.0;
        }

        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}

void boxld_clamp(boxld_t* obj, const boxld_t* bounds) {
    box_clear_error();

    if (!obj || !bounds) {
        box_last_error = BOX_ERROR_UNKNOWN;
        box_set_error_string("Null pointer argument");
        return;
    }

    // Validate dimensions
    if (!VALIDATE_FLOAT_DIMENSIONS(bounds) || !VALIDATE_FLOAT_DIMENSIONS(obj)) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Clamp each axis
    for (int i = 0; i < 3; i++) {
        long double* pos = i == 0 ? &obj->_posx : i == 1 ? &obj->_posy : &obj->_posz;
        long double* size = i == 0 ? &obj->_width : i == 1 ? &obj->_height : &obj->_depth;
        const long double bounds_pos = i == 0 ? bounds->_posx : i == 1 ? bounds->_posy : bounds->_posz;
        const long double bounds_size = i == 0 ? bounds->_width : i == 1 ? bounds->_height : bounds->_depth;

        const long double bounds_min = bounds_pos;
        const long double bounds_max = bounds_pos + bounds_size;

        if (*pos < bounds_min) {
            *pos = bounds_min;
        }
        if (*pos > bounds_max) {
            *pos = bounds_max;
            *size = 0.0L;
        }

        if (*pos + *size > bounds_max) {
            *size = bounds_max - *pos;
        }
    }
}


// equals() functions
bool boxu8_equals(const boxu8_t *obj, const boxu8_t *other) {
    if (!obj || !other) {
        return obj == other; // Both NULL -> equal, one NULL -> not equal
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

bool boxi8_equals(const boxi8_t *obj, const boxi8_t *other) {
    if (!obj || !other) {
        return obj == other;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

bool boxu16_equals(const boxu16_t *obj, const boxu16_t *other) {
    if (!obj || !other) {
        return obj == other;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

bool boxi16_equals(const boxi16_t *obj, const boxi16_t *other) {
    if (!obj || !other) {
        return obj == other;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

bool boxu32_equals(const boxu32_t *obj, const boxu32_t *other) {
    if (!obj || !other) {
        return obj == other;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

bool boxi32_equals(const boxi32_t *obj, const boxi32_t *other) {
    if (!obj || !other) {
        return obj == other;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

bool boxu64_equals(const boxu64_t *obj, const boxu64_t *other) {
    if (!obj || !other) {
        return obj == other;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

bool boxi64_equals(const boxi64_t *obj, const boxi64_t *other) {
    if (!obj || !other) {
        return obj == other;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

bool boxf_equals(const boxf_t *obj, const boxf_t *other) {
    if (!obj || !other) {
        return obj == other;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

bool boxd_equals(const boxd_t *obj, const boxd_t *other) {
    if (!obj || !other) {
        return obj == other;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

bool boxld_equals(const boxld_t *obj, const boxld_t *other) {
    if (!obj || !other) {
        return obj == other;
    }

    return (obj->_posx == other->_posx &&
            obj->_posy == other->_posy &&
            obj->_posz == other->_posz &&
            obj->_width == other->_width &&
            obj->_height == other->_height &&
            obj->_depth == other->_depth);
}

// print() functions
void boxu8_print(const boxu8_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %u, y: %u, z: %u, width: %u, height: %u, depth: %u)\n",
           obj->_posx, obj->_posy, obj->_posz,
           obj->_width, obj->_height, obj->_depth);
}

void boxi8_print(const boxi8_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %d, y: %d, z: %d, width: %d, height: %d, depth: %d)\n",
           obj->_posx, obj->_posy, obj->_posz,
           obj->_width, obj->_height, obj->_depth);
}

void boxu16_print(const boxu16_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %u, y: %u, z: %u, width: %u, height: %u, depth: %u)\n",
           obj->_posx, obj->_posy, obj->_posz,
           obj->_width, obj->_height, obj->_depth);
}

void boxi16_print(const boxi16_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %d, y: %d, z: %d, width: %d, height: %d, depth: %d)\n",
           obj->_posx, obj->_posy, obj->_posz,
           obj->_width, obj->_height, obj->_depth);
}

void boxu32_print(const boxu32_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %u, y: %u, z: %u, width: %u, height: %u, depth: %u)\n",
           obj->_posx, obj->_posy, obj->_posz,
           obj->_width, obj->_height, obj->_depth);
}

void boxi32_print(const boxi32_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %d, y: %d, z: %d, width: %d, height: %d, depth: %d)\n",
           obj->_posx, obj->_posy, obj->_posz,
           obj->_width, obj->_height, obj->_depth);
}

void boxu64_print(const boxu64_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %llu, y: %llu, z: %llu, width: %llu, height: %llu, depth: %llu)\n",
           (unsigned long long)obj->_posx, (unsigned long long)obj->_posy, (unsigned long long)obj->_posz,
           (unsigned long long)obj->_width, (unsigned long long)obj->_height, (unsigned long long)obj->_depth);
}

void boxi64_print(const boxi64_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %lld, y: %lld, z: %lld, width: %lld, height: %lld, depth: %lld)\n",
           (long long)obj->_posx, (long long)obj->_posy, (long long)obj->_posz,
           (long long)obj->_width, (long long)obj->_height, (long long)obj->_depth);
}

void boxf_print(const boxf_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %.6f, y: %.6f, z: %.6f, width: %.6f, height: %.6f, depth: %.6f)\n",
           obj->_posx, obj->_posy, obj->_posz,
           obj->_width, obj->_height, obj->_depth);
}

void boxd_print(const boxd_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %.6f, y: %.6f, z: %.6f, width: %.6f, height: %.6f, depth: %.6f)\n",
           obj->_posx, obj->_posy, obj->_posz,
           obj->_width, obj->_height, obj->_depth);
}

void boxld_print(const boxld_t *obj) {
    if (!obj) {
        printf("Box (NULL)\n");
        return;
    }
    printf("Box (x: %.6Lf, y: %.6Lf, z: %.6Lf, width: %.6Lf, height: %.6Lf, depth: %.6Lf)\n",
           obj->_posx, obj->_posy, obj->_posz,
           obj->_width, obj->_height, obj->_depth);
}


// getSize meta-function
size_t boxu8_size(void){
  return sizeof(boxu8_t);
}
size_t boxi8_size(void){
  return sizeof(boxi8_t);
}
size_t boxu16_size(void){
  return sizeof(boxu16_t);
}
size_t boxi16_size(void){
  return sizeof(boxi16_t);
}
size_t boxu32_size(void){
  return sizeof(boxu32_t);
}
size_t boxi32_size(void){
  return sizeof(boxi32_t);
}
size_t boxu64_size(void){
  return sizeof(boxu64_t);
}
size_t boxi64_size(void){
  return sizeof(boxi64_t);
}
size_t boxf_size(void){
  return sizeof(boxf_t);
}
size_t boxd_size(void){
  return sizeof(boxd_t);
}
size_t boxld_size(void){
  return sizeof(boxld_t);
}

// toArray() functions
void boxu8_toArray(uint8_t *output, const boxu8_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

void boxi8_toArray(int8_t *output, const boxi8_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

void boxu16_toArray(uint16_t *output, const boxu16_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

void boxi16_toArray(int16_t *output, const boxi16_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

void boxu32_toArray(uint32_t *output, const boxu32_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

void boxi32_toArray(int32_t *output, const boxi32_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

void boxu64_toArray(uint64_t *output, const boxu64_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

void boxi64_toArray(int64_t *output, const boxi64_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

void boxf_toArray(float *output, const boxf_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

void boxd_toArray(double *output, const boxd_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

void boxld_toArray(long double *output, const boxld_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output[0] = src->_posx;
    output[1] = src->_posy;
    output[2] = src->_posz;
    output[3] = src->_width;
    output[4] = src->_height;
    output[5] = src->_depth;
}

// fromArray() functions
void boxu8_fromArray(boxu8_t *output, const uint8_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

void boxi8_fromArray(boxi8_t *output, const int8_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

void boxu16_fromArray(boxu16_t *output, const uint16_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

void boxi16_fromArray(boxi16_t *output, const int16_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

void boxu32_fromArray(boxu32_t *output, const uint32_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

void boxi32_fromArray(boxi32_t *output, const int32_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

void boxu64_fromArray(boxu64_t *output, const uint64_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

void boxi64_fromArray(boxi64_t *output, const int64_t *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

void boxf_fromArray(boxf_t *output, const float *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

void boxd_fromArray(boxd_t *output, const double *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

void boxld_fromArray(boxld_t *output, const long double *src) {
    if (!output || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    output->_posx = src[0];
    output->_posy = src[1];
    output->_posz = src[2];
    output->_width = src[3];
    output->_height = src[4];
    output->_depth = src[5];
}

// 8-bit unsigned version
void boxu8_toBytes(const boxu8_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    dst[0] = obj->_posx;
    dst[1] = obj->_posy;
    dst[2] = obj->_posz;
    dst[3] = obj->_width;
    dst[4] = obj->_height;
    dst[5] = obj->_depth;
}

// 8-bit signed version
void boxi8_toBytes(const boxi8_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    dst[0] = (uint8_t)obj->_posx;
    dst[1] = (uint8_t)obj->_posy;
    dst[2] = (uint8_t)obj->_posz;
    dst[3] = (uint8_t)obj->_width;
    dst[4] = (uint8_t)obj->_height;
    dst[5] = (uint8_t)obj->_depth;
}

// 16-bit unsigned version
void boxu16_toBytes(const boxu16_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    uint16_t* fields = (uint16_t*)dst;
    fields[0] = U16_TO_NATIVE(obj->_posx);
    fields[1] = U16_TO_NATIVE(obj->_posy);
    fields[2] = U16_TO_NATIVE(obj->_posz);
    fields[3] = U16_TO_NATIVE(obj->_width);
    fields[4] = U16_TO_NATIVE(obj->_height);
    fields[5] = U16_TO_NATIVE(obj->_depth);
}

// 16-bit signed version
void boxi16_toBytes(const boxi16_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Convert to unsigned representation for consistent serialization
    uint16_t posx = (uint16_t)obj->_posx;
    uint16_t posy = (uint16_t)obj->_posy;
    uint16_t posz = (uint16_t)obj->_posz;
    uint16_t width = (uint16_t)obj->_width;
    uint16_t height = (uint16_t)obj->_height;
    uint16_t depth = (uint16_t)obj->_depth;

    uint16_t* fields = (uint16_t*)dst;
    fields[0] = U16_TO_NATIVE(posx);
    fields[1] = U16_TO_NATIVE(posy);
    fields[2] = U16_TO_NATIVE(posz);
    fields[3] = U16_TO_NATIVE(width);
    fields[4] = U16_TO_NATIVE(height);
    fields[5] = U16_TO_NATIVE(depth);
}

// 32-bit unsigned version
void boxu32_toBytes(const boxu32_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    uint32_t* fields = (uint32_t*)dst;
    fields[0] = U32_TO_NATIVE(obj->_posx);
    fields[1] = U32_TO_NATIVE(obj->_posy);
    fields[2] = U32_TO_NATIVE(obj->_posz);
    fields[3] = U32_TO_NATIVE(obj->_width);
    fields[4] = U32_TO_NATIVE(obj->_height);
    fields[5] = U32_TO_NATIVE(obj->_depth);
}

// 32-bit signed version
void boxi32_toBytes(const boxi32_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Convert to unsigned representation for consistent serialization
    uint32_t posx = (uint32_t)obj->_posx;
    uint32_t posy = (uint32_t)obj->_posy;
    uint32_t posz = (uint32_t)obj->_posz;
    uint32_t width = (uint32_t)obj->_width;
    uint32_t height = (uint32_t)obj->_height;
    uint32_t depth = (uint32_t)obj->_depth;

    uint32_t* fields = (uint32_t*)dst;
    fields[0] = U32_TO_NATIVE(posx);
    fields[1] = U32_TO_NATIVE(posy);
    fields[2] = U32_TO_NATIVE(posz);
    fields[3] = U32_TO_NATIVE(width);
    fields[4] = U32_TO_NATIVE(height);
    fields[5] = U32_TO_NATIVE(depth);
}

// 64-bit unsigned version
void boxu64_toBytes(const boxu64_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    uint64_t* fields = (uint64_t*)dst;
    fields[0] = U64_TO_NATIVE(obj->_posx);
    fields[1] = U64_TO_NATIVE(obj->_posy);
    fields[2] = U64_TO_NATIVE(obj->_posz);
    fields[3] = U64_TO_NATIVE(obj->_width);
    fields[4] = U64_TO_NATIVE(obj->_height);
    fields[5] = U64_TO_NATIVE(obj->_depth);
}

// 64-bit signed version
void boxi64_toBytes(const boxi64_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Convert to unsigned representation for consistent serialization
    uint64_t posx = (uint64_t)obj->_posx;
    uint64_t posy = (uint64_t)obj->_posy;
    uint64_t posz = (uint64_t)obj->_posz;
    uint64_t width = (uint64_t)obj->_width;
    uint64_t height = (uint64_t)obj->_height;
    uint64_t depth = (uint64_t)obj->_depth;

    uint64_t* fields = (uint64_t*)dst;
    fields[0] = U64_TO_NATIVE(posx);
    fields[1] = U64_TO_NATIVE(posy);
    fields[2] = U64_TO_NATIVE(posz);
    fields[3] = U64_TO_NATIVE(width);
    fields[4] = U64_TO_NATIVE(height);
    fields[5] = U64_TO_NATIVE(depth);
}

// Float version
void boxf_toBytes(const boxf_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Use memcpy to ensure bit-pattern preservation
    memcpy(dst, &obj->_posx, sizeof(float));
    memcpy(dst + sizeof(float), &obj->_posy, sizeof(float));
    memcpy(dst + 2 * sizeof(float), &obj->_posz, sizeof(float));
    memcpy(dst + 3 * sizeof(float), &obj->_width, sizeof(float));
    memcpy(dst + 4 * sizeof(float), &obj->_height, sizeof(float));
    memcpy(dst + 5 * sizeof(float), &obj->_depth, sizeof(float));
}

// Double version
void boxd_toBytes(const boxd_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    // Use memcpy to ensure bit-pattern preservation
    memcpy(dst, &obj->_posx, sizeof(double));
    memcpy(dst + sizeof(double), &obj->_posy, sizeof(double));
    memcpy(dst + 2 * sizeof(double), &obj->_posz, sizeof(double));
    memcpy(dst + 3 * sizeof(double), &obj->_width, sizeof(double));
    memcpy(dst + 4 * sizeof(double), &obj->_height, sizeof(double));
    memcpy(dst + 5 * sizeof(double), &obj->_depth, sizeof(double));
}

// Long double version
void boxld_toBytes(const boxld_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot serialize NULL object or destination");
        return;
    }

    size_t ld_size = sizeof(long double);

    // Use memcpy to ensure bit-pattern preservation
    memcpy(dst, &obj->_posx, ld_size);
    memcpy(dst + ld_size, &obj->_posy, ld_size);
    memcpy(dst + 2 * ld_size, &obj->_posz, ld_size);
    memcpy(dst + 3 * ld_size, &obj->_width, ld_size);
    memcpy(dst + 4 * ld_size, &obj->_height, ld_size);
    memcpy(dst + 5 * ld_size, &obj->_depth, ld_size);
}
// fromBytes() functions with field-by-field copying
void boxu8_fromBytes(boxu8_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    memcpy(&obj->_posx, src, sizeof(uint8_t));
    memcpy(&obj->_posy, src + 1, sizeof(uint8_t));
    memcpy(&obj->_posz, src + 2, sizeof(uint8_t));
    memcpy(&obj->_width, src + 3, sizeof(uint8_t));
    memcpy(&obj->_height, src + 4, sizeof(uint8_t));
    memcpy(&obj->_depth, src + 5, sizeof(uint8_t));
}

void boxi8_fromBytes(boxi8_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    memcpy(&obj->_posx, src, sizeof(int8_t));
    memcpy(&obj->_posy, src + 1, sizeof(int8_t));
    memcpy(&obj->_posz, src + 2, sizeof(int8_t));
    memcpy(&obj->_width, src + 3, sizeof(int8_t));
    memcpy(&obj->_height, src + 4, sizeof(int8_t));
    memcpy(&obj->_depth, src + 5, sizeof(int8_t));
}

void boxu16_fromBytes(boxu16_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    memcpy(&obj->_posx, src, sizeof(uint16_t));
    memcpy(&obj->_posy, src + 2, sizeof(uint16_t));
    memcpy(&obj->_posz, src + 4, sizeof(uint16_t));
    memcpy(&obj->_width, src + 6, sizeof(uint16_t));
    memcpy(&obj->_height, src + 8, sizeof(uint16_t));
    memcpy(&obj->_depth, src + 10, sizeof(uint16_t));
}

void boxi16_fromBytes(boxi16_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    memcpy(&obj->_posx, src, sizeof(int16_t));
    memcpy(&obj->_posy, src + 2, sizeof(int16_t));
    memcpy(&obj->_posz, src + 4, sizeof(int16_t));
    memcpy(&obj->_width, src + 6, sizeof(int16_t));
    memcpy(&obj->_height, src + 8, sizeof(int16_t));
    memcpy(&obj->_depth, src + 10, sizeof(int16_t));
}

void boxu32_fromBytes(boxu32_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    memcpy(&obj->_posx, src, sizeof(uint32_t));
    memcpy(&obj->_posy, src + 4, sizeof(uint32_t));
    memcpy(&obj->_posz, src + 8, sizeof(uint32_t));
    memcpy(&obj->_width, src + 12, sizeof(uint32_t));
    memcpy(&obj->_height, src + 16, sizeof(uint32_t));
    memcpy(&obj->_depth, src + 20, sizeof(uint32_t));
}

void boxi32_fromBytes(boxi32_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    memcpy(&obj->_posx, src, sizeof(int32_t));
    memcpy(&obj->_posy, src + 4, sizeof(int32_t));
    memcpy(&obj->_posz, src + 8, sizeof(int32_t));
    memcpy(&obj->_width, src + 12, sizeof(int32_t));
    memcpy(&obj->_height, src + 16, sizeof(int32_t));
    memcpy(&obj->_depth, src + 20, sizeof(int32_t));
}

void boxu64_fromBytes(boxu64_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    memcpy(&obj->_posx, src, sizeof(uint64_t));
    memcpy(&obj->_posy, src + 8, sizeof(uint64_t));
    memcpy(&obj->_posz, src + 16, sizeof(uint64_t));
    memcpy(&obj->_width, src + 24, sizeof(uint64_t));
    memcpy(&obj->_height, src + 32, sizeof(uint64_t));
    memcpy(&obj->_depth, src + 40, sizeof(uint64_t));
}

void boxi64_fromBytes(boxi64_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    memcpy(&obj->_posx, src, sizeof(int64_t));
    memcpy(&obj->_posy, src + 8, sizeof(int64_t));
    memcpy(&obj->_posz, src + 16, sizeof(int64_t));
    memcpy(&obj->_width, src + 24, sizeof(int64_t));
    memcpy(&obj->_height, src + 32, sizeof(int64_t));
    memcpy(&obj->_depth, src + 40, sizeof(int64_t));
}

void boxf_fromBytes(boxf_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    memcpy(&obj->_posx, src, sizeof(float));
    memcpy(&obj->_posy, src + 4, sizeof(float));
    memcpy(&obj->_posz, src + 8, sizeof(float));
    memcpy(&obj->_width, src + 12, sizeof(float));
    memcpy(&obj->_height, src + 16, sizeof(float));
    memcpy(&obj->_depth, src + 20, sizeof(float));
}

void boxd_fromBytes(boxd_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    memcpy(&obj->_posx, src, sizeof(double));
    memcpy(&obj->_posy, src + 8, sizeof(double));
    memcpy(&obj->_posz, src + 16, sizeof(double));
    memcpy(&obj->_width, src + 24, sizeof(double));
    memcpy(&obj->_height, src + 32, sizeof(double));
    memcpy(&obj->_depth, src + 40, sizeof(double));
}

void boxld_fromBytes(boxld_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    size_t ld_size = sizeof(long double);
    memcpy(&obj->_posx, src, ld_size);
    memcpy(&obj->_posy, src + ld_size, ld_size);
    memcpy(&obj->_posz, src + 2 * ld_size, ld_size);
    memcpy(&obj->_width, src + 3 * ld_size, ld_size);
    memcpy(&obj->_height, src + 4 * ld_size, ld_size);
    memcpy(&obj->_depth, src + 5 * ld_size, ld_size);
}

// toBytesLE() functions - Convert to Little Endian byte order
void boxu8_toBytesLE(const boxu8_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // For 8-bit types, endianness doesn't matter
    memcpy(dst, obj, sizeof(boxu8_t));
}

void boxi8_toBytesLE(const boxi8_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // For 8-bit types, endianness doesn't matter
    memcpy(dst, obj, sizeof(boxi8_t));
}

void boxu16_toBytesLE(const boxu16_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Convert each 16-bit field to little-endian
    uint16_t* fields = (uint16_t*)obj;
    for (int i = 0; i < 6; i++) {
        dst[i*2] = (uint8_t)(fields[i] & 0xFF);
        dst[i*2 + 1] = (uint8_t)((fields[i] >> 8) & 0xFF);
    }
}

void boxi16_toBytesLE(const boxi16_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Convert each 16-bit field to little-endian
    int16_t* fields = (int16_t*)obj;
    for (int i = 0; i < 6; i++) {
        dst[i*2] = (uint8_t)(fields[i] & 0xFF);
        dst[i*2 + 1] = (uint8_t)((fields[i] >> 8) & 0xFF);
    }
}

void boxu32_toBytesLE(const boxu32_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Convert each 32-bit field to little-endian
    uint32_t* fields = (uint32_t*)obj;
    for (int i = 0; i < 6; i++) {
        dst[i*4] = (uint8_t)(fields[i] & 0xFF);
        dst[i*4 + 1] = (uint8_t)((fields[i] >> 8) & 0xFF);
        dst[i*4 + 2] = (uint8_t)((fields[i] >> 16) & 0xFF);
        dst[i*4 + 3] = (uint8_t)((fields[i] >> 24) & 0xFF);
    }
}

void boxi32_toBytesLE(const boxi32_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Convert each 32-bit field to little-endian
    int32_t* fields = (int32_t*)obj;
    for (int i = 0; i < 6; i++) {
        dst[i*4] = (uint8_t)(fields[i] & 0xFF);
        dst[i*4 + 1] = (uint8_t)((fields[i] >> 8) & 0xFF);
        dst[i*4 + 2] = (uint8_t)((fields[i] >> 16) & 0xFF);
        dst[i*4 + 3] = (uint8_t)((fields[i] >> 24) & 0xFF);
    }
}

void boxu64_toBytesLE(const boxu64_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Convert each 64-bit field to little-endian
    uint64_t* fields = (uint64_t*)obj;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            dst[i*8 + j] = (uint8_t)((fields[i] >> (j * 8)) & 0xFF);
        }
    }
}

void boxi64_toBytesLE(const boxi64_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Convert each 64-bit field to little-endian
    int64_t* fields = (int64_t*)obj;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            dst[i*8 + j] = (uint8_t)((fields[i] >> (j * 8)) & 0xFF);
        }
    }
}

void boxf_toBytesLE(const boxf_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Convert each float field to little-endian bytes
    uint32_t* fields = (uint32_t*)obj;
    for (int i = 0; i < 6; i++) {
        dst[i*4] = (uint8_t)(fields[i] & 0xFF);
        dst[i*4 + 1] = (uint8_t)((fields[i] >> 8) & 0xFF);
        dst[i*4 + 2] = (uint8_t)((fields[i] >> 16) & 0xFF);
        dst[i*4 + 3] = (uint8_t)((fields[i] >> 24) & 0xFF);
    }
}

void boxd_toBytesLE(const boxd_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Convert each double field to little-endian bytes
    uint64_t* fields = (uint64_t*)obj;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            dst[i*8 + j] = (uint8_t)((fields[i] >> (j * 8)) & 0xFF);
        }
    }
}

void boxld_toBytesLE(const boxld_t* obj, uint8_t* dst) {
    if (!obj || !dst) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        return;
    }

    // Convert each long double field to little-endian bytes
    // Note: This implementation assumes long double has the same representation as double
    // For platforms with different long double representations, this may need adjustment
    uint64_t* fields = (uint64_t*)obj;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            dst[i*8 + j] = (uint8_t)((fields[i] >> (j * 8)) & 0xFF);
        }
    }
}



// 8-bit unsigned version
void boxu8_fromBytesLE(boxu8_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    obj->_posx = src[0];
    obj->_posy = src[1];
    obj->_posz = src[2];
    obj->_width = src[3];
    obj->_height = src[4];
    obj->_depth = src[5];
}

// 8-bit signed version
void boxi8_fromBytesLE(boxi8_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    obj->_posx = (int8_t)src[0];
    obj->_posy = (int8_t)src[1];
    obj->_posz = (int8_t)src[2];
    obj->_width = (int8_t)src[3];
    obj->_height = (int8_t)src[4];
    obj->_depth = (int8_t)src[5];
}

// 16-bit unsigned version
void boxu16_fromBytesLE(boxu16_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    obj->_posx = U16_FROM_LE(src);
    obj->_posy = U16_FROM_LE(src + 2);
    obj->_posz = U16_FROM_LE(src + 4);
    obj->_width = U16_FROM_LE(src + 6);
    obj->_height = U16_FROM_LE(src + 8);
    obj->_depth = U16_FROM_LE(src + 10);
}

// 16-bit signed version
void boxi16_fromBytesLE(boxi16_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    obj->_posx = (int16_t)U16_FROM_LE(src);
    obj->_posy = (int16_t)U16_FROM_LE(src + 2);
    obj->_posz = (int16_t)U16_FROM_LE(src + 4);
    obj->_width = (int16_t)U16_FROM_LE(src + 6);
    obj->_height = (int16_t)U16_FROM_LE(src + 8);
    obj->_depth = (int16_t)U16_FROM_LE(src + 10);
}

// 32-bit unsigned version
void boxu32_fromBytesLE(boxu32_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    obj->_posx = U32_FROM_LE(src);
    obj->_posy = U32_FROM_LE(src + 4);
    obj->_posz = U32_FROM_LE(src + 8);
    obj->_width = U32_FROM_LE(src + 12);
    obj->_height = U32_FROM_LE(src + 16);
    obj->_depth = U32_FROM_LE(src + 20);
}

// 32-bit signed version
void boxi32_fromBytesLE(boxi32_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    obj->_posx = (int32_t)U32_FROM_LE(src);
    obj->_posy = (int32_t)U32_FROM_LE(src + 4);
    obj->_posz = (int32_t)U32_FROM_LE(src + 8);
    obj->_width = (int32_t)U32_FROM_LE(src + 12);
    obj->_height = (int32_t)U32_FROM_LE(src + 16);
    obj->_depth = (int32_t)U32_FROM_LE(src + 20);
}

// 64-bit unsigned version
void boxu64_fromBytesLE(boxu64_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    obj->_posx = U64_FROM_LE(src);
    obj->_posy = U64_FROM_LE(src + 8);
    obj->_posz = U64_FROM_LE(src + 16);
    obj->_width = U64_FROM_LE(src + 24);
    obj->_height = U64_FROM_LE(src + 32);
    obj->_depth = U64_FROM_LE(src + 40);
}

// 64-bit signed version
void boxi64_fromBytesLE(boxi64_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    obj->_posx = (int64_t)U64_FROM_LE(src);
    obj->_posy = (int64_t)U64_FROM_LE(src + 8);
    obj->_posz = (int64_t)U64_FROM_LE(src + 16);
    obj->_width = (int64_t)U64_FROM_LE(src + 24);
    obj->_height = (int64_t)U64_FROM_LE(src + 32);
    obj->_depth = (int64_t)U64_FROM_LE(src + 40);
}

// Float version (already provided, but with improved error handling)
void boxf_fromBytesLE(boxf_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Convert each float field from little-endian bytes
    uint32_t* fields = (uint32_t*)obj;
    for (int i = 0; i < 6; i++) {
        fields[i] = (uint32_t)src[i*4] |
                   ((uint32_t)src[i*4 + 1] << 8) |
                   ((uint32_t)src[i*4 + 2] << 16) |
                   ((uint32_t)src[i*4 + 3] << 24);
    }
}

// Double version
void boxd_fromBytesLE(boxd_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // Use union to reconstruct from little-endian bytes
    union {
        double d;
        uint64_t i;
    } converter;

    converter.i = U64_FROM_LE(src);
    obj->_posx = converter.d;

    converter.i = U64_FROM_LE(src + 8);
    obj->_posy = converter.d;

    converter.i = U64_FROM_LE(src + 16);
    obj->_posz = converter.d;

    converter.i = U64_FROM_LE(src + 24);
    obj->_width = converter.d;

    converter.i = U64_FROM_LE(src + 32);
    obj->_height = converter.d;

    converter.i = U64_FROM_LE(src + 40);
    obj->_depth = converter.d;
}

// Long double version
void boxld_fromBytesLE(boxld_t* obj, const uint8_t* src) {
    if (!obj || !src) {
        box_last_error = BOX_ERROR_INVALID_DIMENSIONS;
        box_set_error_string("Cannot deserialize NULL object or source");
        return;
    }

    // For long double, we need to handle platform-dependent size
    // We'll use memcpy with byte reversal if needed
    uint8_t* dest = (uint8_t*)obj;
    size_t ld_size = sizeof(long double);

    for (int i = 0; i < 6; i++) {
        // Copy bytes in reverse order (little-endian to native)
        for (size_t j = 0; j < ld_size; j++) {
            dest[i * ld_size + j] = src[i * ld_size + j];
        }
    }
}
