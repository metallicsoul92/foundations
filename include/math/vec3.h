#ifndef FOUNDATIONS_MATH_VEC3_H
#define FOUNDATIONS_MATH_VEC3_H

// Include necessary standard headers and forward declarations.

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

// Standard header for fixed-size integer types
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

#ifndef VEC2_DEFINED

// Forward declaration for a 2D vector of int8_t (8-bit signed integers).
  #ifndef VEC2I8_DEFINED
  typedef struct vector2int8 vec2int8_t;
  #define VEC2I8_DEFINED 1
  #endif

// Forward declaration for a 2D vector of uint8_t (8-bit unsigned integers).
  #ifndef VEC2U8_DEFINED
  typedef struct vector2uint8 vec2uint8_t;
  #define VEC2U8_DEFINED 1
  #endif

// Forward declaration for a 2D vector of int16_t (16-bit signed integers).
  #ifndef VEC2I16_DEFINED
  typedef struct vector2int16 vec2int16_t;
  #define VEC2I16_DEFINED 1
  #endif

// Forward declaration for a 2D vector of uint16_t (16-bit unsigned integers).
  #ifndef VEC2U16_DEFINED
  typedef struct vector2uint16 vec2uint16_t;
  #define VEC2U16_DEFINED 1
  #endif
// Forward declaration for a 2D vector of int32_t (32-bit signed integers).
  #ifndef VEC2I32_DEFINED
  typedef struct vector2int32 vec2int32_t;
  #define VEC2I32_DEFINED 1
  #endif

// Forward declaration for a 2D vector of uint32_t (32-bit unsigned integers).
  #ifndef VEC2U32_DEFINED
  typedef struct vector2uint32 vec2uint32_t;
  #define VEC2U32_DEFINED 1
  #endif

// Forward declaration for a 2D vector of int64_t (64-bit signed integers).
  #ifndef VEC2I64_DEFINED
  typedef struct vector2int64 vec2int64_t;
  #define VEC2I64_DEFINED 1
  #endif

// Forward declaration for a 2D vector of uint64_t (64-bit unsigned integers).
  #ifndef VEC2U64_DEFINED
  typedef struct vector2uint64 vec2uint64_t;
  #define VEC2U64_DEFINED 1
  #endif

// Forward declaration for a 2D vector of char.
  #ifndef VEC2C_DEFINED
  typedef struct vector2char vec2char_t;
  #define VEC2C_DEFINED 1
  #endif

// Forward declaration for a 2D vector of float.
  #ifndef VEC2F_DEFINED
  typedef struct vector2float vec2f_t;
  #define VEC2F_DEFINED 1
  #endif

// Forward declaration for a 2D vector of double.
  #ifndef VEC2D_DEFINED
  typedef struct vector2double vec2d_t;
  #define VEC2D_DEFINED 1
  #endif

#define VEC2_DEFINED 1
#endif

#ifndef VEC3_DEFINED

  // Define a 3D vector structure for 8-bit signed integers if not defined
  #ifndef VEC3I8_DEFINED
  typedef struct vector3int8 vec3int8_t;
  #define VEC3I8_DEFINED 1
  #endif

  // Define a 3D vector structure for 8-bit unsigned integers if not defined
  #ifndef VEC3U8_DEFINED
  typedef struct vector3uint8 vec3uint8_t;
  #define VEC3U8_DEFINED 1
  #endif

  // Define a 3D vector structure for 16-bit signed integers if not defined
  #ifndef VEC3I16_DEFINED
  typedef struct vector3int16 vec3int16_t;
  #define VEC3I16_DEFINED 1
  #endif

  // Define a 3D vector structure for 16-bit unsigned integers if not defined
  #ifndef VEC3U16_DEFINED
  typedef struct vector3uint16 vec3uint16_t;
  #define VEC3U16_DEFINED 1
  #endif

  // Define a 3D vector structure for 32-bit signed integers if not defined
  #ifndef VEC3I32_DEFINED
  typedef struct vector3int32 vec3int32_t;
  #define VEC3I32_DEFINED 1
  #endif

  // Define a 3D vector structure for 32-bit unsigned integers if not defined
  #ifndef VEC3U32_DEFINED
  typedef struct vector3uint32 vec3uint32_t;
  #define VEC3U32_DEFINED 1
  #endif

  // Define a 3D vector structure for 64-bit signed integers if not defined
  #ifndef VEC3I64_DEFINED
  typedef struct vector3int64 vec3int64_t;
  #define VEC3I64_DEFINED 1
  #endif

  // Define a 3D vector structure for 64-bit unsigned integers if not defined
  #ifndef VEC3U64_DEFINED
  typedef struct vector3uint64 vec3uint64_t;
  #define VEC3U64_DEFINED 1
  #endif

  // Define a 3D vector structure for characters if not defined
  #ifndef VEC3C_DEFINED
  typedef struct vector3char vec3char_t;
  #define VEC3C_DEFINED 1
  #endif

  // Define a 3D vector structure for single-precision floating-point numbers if not defined
  #ifndef VEC3F_DEFINED
  typedef struct vector3float vec3f_t;
  #define VEC3F_DEFINED 1
  #endif

  // Define a 3D vector structure for double-precision floating-point numbers if not defined
  #ifndef VEC3D_DEFINED
  typedef struct vector3double vec3d_t;
  #define VEC3D_DEFINED 1
  #endif

// Define VEC3_DEFINED to indicate that the 3D vector types have been defined
#define VEC3_DEFINED 1
#endif




/**
Convention Discussion:

void function(type * out, ...etc);
type * function_r(...etc);

**/

//Initalize an already allocated vector.

// Initialize a 3D vector of 8-bit signed integers
void initvec3I8(vec3int8_t *out, int8_t x, int8_t y, int8_t z);

// Initialize a 3D vector of 8-bit unsigned integers
void initvec3U8(vec3uint8_t *out, uint8_t x, uint8_t y, uint8_t z);

// Initialize a 3D vector of 16-bit signed integers
void initvec3I16(vec3int16_t *out, int16_t x, int16_t y, int16_t z);

// Initialize a 3D vector of 16-bit unsigned integers
void initvec3U16(vec3uint16_t *out, uint16_t x, uint16_t y, uint16_t z);

// Initialize a 3D vector of 32-bit signed integers
void initvec3I32(vec3int32_t *out, int32_t x, int32_t y, int32_t z);

// Initialize a 3D vector of 32-bit unsigned integers
void initvec3U32(vec3uint32_t *out, uint32_t x, uint32_t y, uint32_t z);

// Initialize a 3D vector of 64-bit signed integers
void initvec3I64(vec3int64_t *out, int64_t x, int64_t y, int64_t z);

// Initialize a 3D vector of 64-bit unsigned integers
void initvec3U64(vec3uint64_t *out, uint64_t x, uint64_t y, uint64_t z);

// Initialize a 3D vector of characters
void initvec3C(vec3char_t *out, char x, char y, char z);

// Initialize a 3D vector of single-precision floating-point numbers
void initvec3F(vec3f_t *out, float x, float y, float z);

// Initialize a 3D vector of double-precision floating-point numbers
void initvec3D(vec3d_t *out, double x, double y, double z);


// Initialize a 3D vector of 8-bit signed integers from a 2D vector and an additional 8-bit value
void initvec3I8_fromVec2(vec3int8_t *out, vec2int8_t *xy, int8_t z);

// Initialize a 3D vector of 8-bit unsigned integers from a 2D vector and an additional 8-bit value
void initvec3U8_fromVec2(vec3uint8_t *out, vec2uint8_t *xy, uint8_t z);

// Initialize a 3D vector of 16-bit signed integers from a 2D vector and an additional 16-bit value
void initvec3I16_fromVec2(vec3int16_t *out, vec2int16_t *xy, int16_t z);

// Initialize a 3D vector of 16-bit unsigned integers from a 2D vector and an additional 16-bit value
void initvec3U16_fromVec2(vec3uint16_t *out, vec2uint16_t *xy, uint16_t z);

// Initialize a 3D vector of 32-bit signed integers from a 2D vector and an additional 32-bit value
void initvec3I32_fromVec2(vec3int32_t *out, vec2int32_t *xy, int32_t z);

// Initialize a 3D vector of 32-bit unsigned integers from a 2D vector and an additional 32-bit value
void initvec3U32_fromVec2(vec3uint32_t *out, vec2uint32_t *xy, uint32_t z);

// Initialize a 3D vector of 64-bit signed integers from a 2D vector and an additional 64-bit value
void initvec3I64_fromVec2(vec3int64_t *out, vec2int64_t *xy, int64_t z);

// Initialize a 3D vector of 64-bit unsigned integers from a 2D vector and an additional 64-bit value
void initvec3U64_fromVec2(vec3uint64_t *out, vec2uint64_t *xy, uint64_t z);

// Initialize a 3D vector of characters from a 2D vector and an additional character
void initvec3C_fromVec2(vec3char_t *out, vec2char_t *xy, char z);

// Initialize a 3D vector of single-precision floating-point numbers from a 2D vector and an additional float
void initvec3F_fromVec2(vec3f_t *out, vec2f_t *xy, float z);

// Initialize a 3D vector of double-precision floating-point numbers from a 2D vector and an additional double
void initvec3D_fromVec2(vec3d_t *out, vec2d_t *xy, double z);


// Allocate and initialize a 3D vector of 8-bit signed integers with the provided values
vec3int8_t *allocvec3I8(int8_t x, int8_t y, int8_t z);

// Allocate and initialize a 3D vector of 8-bit unsigned integers with the provided values
vec3uint8_t *allocvec3U8(uint8_t x, uint8_t y, uint8_t z);

// Allocate and initialize a 3D vector of 16-bit signed integers with the provided values
vec3int16_t *allocvec3I16(int16_t x, int16_t y, int16_t z);

// Allocate and initialize a 3D vector of 16-bit unsigned integers with the provided values
vec3uint16_t *allocvec3U16(uint16_t x, uint16_t y, uint16_t z);

// Allocate and initialize a 3D vector of 32-bit signed integers with the provided values
vec3int32_t *allocvec3I32(int32_t x, int32_t y, int32_t z);

// Allocate and initialize a 3D vector of 32-bit unsigned integers with the provided values
vec3uint32_t *allocvec3U32(uint32_t x, uint32_t y, uint32_t z);

// Allocate and initialize a 3D vector of 64-bit signed integers with the provided values
vec3int64_t *allocvec3I64(int64_t x, int64_t y, int64_t z);

// Allocate and initialize a 3D vector of 64-bit unsigned integers with the provided values
vec3uint64_t *allocvec3U64(uint64_t x, uint64_t y, uint64_t z);

// Allocate and initialize a 3D vector of characters with the provided values
vec3char_t *allocvec3C(char x, char y, char z);

// Allocate and initialize a 3D vector of single-precision floating-point numbers with the provided values
vec3f_t *allocvec3F(float x, float y, float z);

// Allocate and initialize a 3D vector of double-precision floating-point numbers with the provided values
vec3d_t *allocvec3D(double x, double y, double z);


// Allocate and initialize a 3D vector of 8-bit signed integers from a vec2int8_t and an 8-bit integer
vec3int8_t *allocvec3I8_fromVec2(vec2int8_t *xy, int8_t z);

// Allocate and initialize a 3D vector of 8-bit unsigned integers from a vec2uint8_t and an 8-bit unsigned integer
vec3uint8_t *allocvec3U8_fromVec2(vec2uint8_t *xy, uint8_t z);

// Allocate and initialize a 3D vector of 16-bit signed integers from a vec2int16_t and a 16-bit integer
vec3int16_t *allocvec3I16_fromVec2(vec2int16_t *xy, int16_t z);

// Allocate and initialize a 3D vector of 16-bit unsigned integers from a vec2uint16_t and a 16-bit unsigned integer
vec3uint16_t *allocvec3U16_fromVec2(vec2uint16_t *xy, uint16_t z);

// Allocate and initialize a 3D vector of 32-bit signed integers from a vec2int32_t and a 32-bit integer
vec3int32_t *allocvec3I32_fromVec2(vec2int32_t *xy, int32_t z);

// Allocate and initialize a 3D vector of 32-bit unsigned integers from a vec2uint32_t and a 32-bit unsigned integer
vec3uint32_t *allocvec3U32_fromVec2(vec2uint32_t *xy, uint32_t z);

// Allocate and initialize a 3D vector of 64-bit signed integers from a vec2int64_t and a 64-bit integer
vec3int64_t *allocvec3I64_fromVec2(vec2int64_t *xy, int64_t z);

// Allocate and initialize a 3D vector of 64-bit unsigned integers from a vec2uint64_t and a 64-bit unsigned integer
vec3uint64_t *allocvec3U64_fromVec2(vec2uint64_t *xy, uint64_t z);

// Allocate and initialize a 3D vector of characters from a vec2char_t and a character
vec3char_t *allocvec3C_fromVec2(vec2char_t *xy, char z);

// Allocate and initialize a 3D vector of single-precision floating-point numbers from a vec2f_t and a float
vec3f_t *allocvec3F_fromVec2(vec2f_t *xy, float z);

// Allocate and initialize a 3D vector of double-precision floating-point numbers from a vec2d_t and a double
vec3d_t *allocvec3D_fromVec2(vec2d_t *xy, double z);


// Allocate and initialize a 3D vector of 8-bit signed integers from a string
vec3int8_t *allocvec3I8_fromString(const char *str);

// Allocate and initialize a 3D vector of 8-bit unsigned integers from a string
vec3uint8_t *allocvec3U8_fromString(const char *str);

// Allocate and initialize a 3D vector of 16-bit signed integers from a string
vec3int16_t *allocvec3I16_fromString(const char *str);

// Allocate and initialize a 3D vector of 16-bit unsigned integers from a string
vec3uint16_t *allocvec3U16_fromString(const char *str);

// Allocate and initialize a 3D vector of 32-bit signed integers from a string
vec3int32_t *allocvec3I32_fromString(const char *str);

// Allocate and initialize a 3D vector of 32-bit unsigned integers from a string
vec3uint32_t *allocvec3U32_fromString(const char *str);

// Allocate and initialize a 3D vector of 64-bit signed integers from a string
vec3int64_t *allocvec3I64_fromString(const char *str);

// Allocate and initialize a 3D vector of 64-bit unsigned integers from a string
vec3uint64_t *allocvec3U64_fromString(const char *str);

// Allocate and initialize a 3D vector of characters from a string
vec3char_t *allocvec3C_fromString(const char *str);

// Allocate and initialize a 3D vector of single-precision floating-point numbers from a string
vec3f_t *allocvec3F_fromString(const char *str);

// Allocate and initialize a 3D vector of double-precision floating-point numbers from a string
vec3d_t *allocvec3D_fromString(const char *str);



//getters and setters
// Set the X component of a 3D vector of 8-bit signed integers
void vec3i8_setX(vec3int8_t *out, int8_t x);

// Set the Y component of a 3D vector of 8-bit signed integers
void vec3i8_setY(vec3int8_t *out, int8_t y);

// Set the Z component of a 3D vector of 8-bit signed integers
void vec3i8_setZ(vec3int8_t *out, int8_t z);

// Get the X component of a 3D vector of 8-bit signed integers
int8_t vec3i8_X(vec3int8_t *out);

// Get the Y component of a 3D vector of 8-bit signed integers
int8_t vec3i8_Y(vec3int8_t *out);

// Get the Z component of a 3D vector of 8-bit signed integers
int8_t vec3i8_Z(vec3int8_t *out);;


// Set the X component of a 3D vector of 8-bit unsigned integers
void vec3u8_setX(vec3uint8_t *out, uint8_t x);

// Set the Y component of a 3D vector of 8-bit unsigned integers
void vec3u8_setY(vec3uint8_t *out, uint8_t y);

// Set the Z component of a 3D vector of 8-bit unsigned integers
void vec3u8_setZ(vec3uint8_t *out, uint8_t z);


// Get the X component of a 3D vector of 8-bit unsigned integers
uint8_t vec3u8_X(vec3uint8_t *out);

// Get the Y component of a 3D vector of 8-bit unsigned integers
uint8_t vec3u8_Y(vec3uint8_t *out);

// Get the Z component of a 3D vector of 8-bit unsigned integers
uint8_t vec3u8_Z(vec3uint8_t *out);








// Set the X component of a 3D vector of 16-bit signed integers
void vec3i16_setX(vec3int16_t *out, int16_t x);

// Set the Y component of a 3D vector of 16-bit signed integers
void vec3i16_setY(vec3int16_t *out, int16_t y);

// Set the Z component of a 3D vector of 16-bit signed integers
void vec3i16_setZ(vec3int16_t *out, int16_t z);

// Get the X component of a 3D vector of 16-bit signed integers
int16_t vec3i16_X(vec3int16_t *out);

// Get the Y component of a 3D vector of 16-bit signed integers
int16_t vec3i16_Y(vec3int16_t *out);

// Get the Z component of a 3D vector of 16-bit signed integers
int16_t vec3i16_Z(vec3int16_t *out);


// Set the X component of a 3D vector of 16-bit unsigned integers
void vec3u16_setX(vec3uint16_t *out, uint16_t x);

// Set the Y component of a 3D vector of 16-bit unsigned integers
void vec3u16_setY(vec3uint16_t *out, uint16_t y);

// Set the Z component of a 3D vector of 16-bit unsigned integers
void vec3u16_setZ(vec3uint16_t *out, uint16_t z);

// Get the X component of a 3D vector of 16-bit unsigned integers
uint16_t vec3u16_X(vec3uint16_t *out);

// Get the Y component of a 3D vector of 16-bit unsigned integers
uint16_t vec3u16_Y(vec3uint16_t *out);

// Get the Z component of a 3D vector of 16-bit unsigned integers
uint16_t vec3u16_Z(vec3uint16_t *out);


// Set the X component of a 3D vector of 32-bit signed integers
void vec3i32_setX(vec3int32_t *out, int32_t x);

// Set the Y component of a 3D vector of 32-bit signed integers
void vec3i32_setY(vec3int32_t *out, int32_t y);

// Set the Z component of a 3D vector of 32-bit signed integers
void vec3i32_setZ(vec3int32_t *out, int32_t z);

// Get the X component of a 3D vector of 32-bit signed integers
int32_t vec3i32_X(vec3int32_t *out);

// Get the Y component of a 3D vector of 32-bit signed integers
int32_t vec3i32_Y(vec3int32_t *out);

// Get the Z component of a 3D vector of 32-bit signed integers
int32_t vec3i32_Z(vec3int32_t *out);


// Set the X component of a 3D vector of 32-bit unsigned integers
void vec3u32_setX(vec3uint32_t *out, uint32_t x);

// Set the Y component of a 3D vector of 32-bit unsigned integers
void vec3u32_setY(vec3uint32_t *out, uint32_t y);

// Set the Z component of a 3D vector of 32-bit unsigned integers
void vec3u32_setZ(vec3uint32_t *out, uint32_t z);

// Get the X component of a 3D vector of 32-bit unsigned integers
uint32_t vec3u32_X(vec3uint32_t *out);

// Get the Y component of a 3D vector of 32-bit unsigned integers
uint32_t vec3u32_Y(vec3uint32_t *out);

// Get the Z component of a 3D vector of 32-bit unsigned integers
uint32_t vec3u32_Z(vec3uint32_t *out);


// Set the X component of a 3D vector of 64-bit signed integers
void vec3i64_setX(vec3int64_t *out, int64_t x);

// Set the Y component of a 3D vector of 64-bit signed integers
void vec3i64_setY(vec3int64_t *out, int64_t y);

// Set the Z component of a 3D vector of 64-bit signed integers
void vec3i64_setZ(vec3int64_t *out, int64_t z);

// Get the X component of a 3D vector of 64-bit signed integers
int64_t vec3i64_X(vec3int64_t *out);

// Get the Y component of a 3D vector of 64-bit signed integers
int64_t vec3i64_Y(vec3int64_t *out);

// Get the Z component of a 3D vector of 64-bit signed integers
int64_t vec3i64_Z(vec3int64_t *out);


// Set the X component of a 3D vector of 64-bit unsigned integers
void vec3u64_setX(vec3uint64_t *out, uint64_t x);

// Set the Y component of a 3D vector of 64-bit unsigned integers
void vec3u64_setY(vec3uint64_t *out, uint64_t y);

// Set the Z component of a 3D vector of 64-bit unsigned integers
void vec3u64_setZ(vec3uint64_t *out, uint64_t z);

// Get the X component of a 3D vector of 64-bit unsigned integers
uint64_t vec3u64_X(vec3uint64_t *out);

// Get the Y component of a 3D vector of 64-bit unsigned integers
uint64_t vec3u64_Y(vec3uint64_t *out);

// Get the Z component of a 3D vector of 64-bit unsigned integers
uint64_t vec3u64_Z(vec3uint64_t *out);


// Set the X component of a 3D vector of characters (char)
void vec3char_setX(vec3char_t *out, char x);

// Set the Y component of a 3D vector of characters (char)
void vec3char_setY(vec3char_t *out, char y);

// Set the Z component of a 3D vector of characters (char)
void vec3char_setZ(vec3char_t *out, char z);

// Get the X component of a 3D vector of characters (char)
char vec3char_X(vec3char_t *out);

// Get the Y component of a 3D vector of characters (char)
char vec3char_Y(vec3char_t *out);

// Get the Z component of a 3D vector of characters (char)
char vec3char_Z(vec3char_t *out);



// Set the X component of a 3D vector of floats (float)
void vec3f_setX(vec3f_t *out, float x);

// Set the Y component of a 3D vector of floats (float)
void vec3f_setY(vec3f_t *out, float y);

// Set the Z component of a 3D vector of floats (float)
void vec3f_setZ(vec3f_t *out, float z);

// Get the X component of a 3D vector of floats (float)
float vec3f_X(vec3f_t *out);

// Get the Y component of a 3D vector of floats (float)
float vec3f_Y(vec3f_t *out);

// Get the Z component of a 3D vector of floats (float)
float vec3f_Z(vec3f_t *out);



// Set the X component of a 3D vector of doubles (double)
void vec3d_setX(vec3d_t *out, double x);

// Set the Y component of a 3D vector of doubles (double)
void vec3d_setY(vec3d_t *out, double y);

// Set the Z component of a 3D vector of doubles (double)
void vec3d_setZ(vec3d_t *out, double z);

// Get the X component of a 3D vector of doubles (double)
double vec3d_X(vec3d_t *out);

// Get the Y component of a 3D vector of doubles (double)
double vec3d_Y(vec3d_t *out);

// Get the Z component of a 3D vector of doubles (double)
double vec3d_Z(vec3d_t *out);



// Get the data of a 3D vector of int8_t as a plain-old-data (POD) int8_t array
// Note: For thread safety, user-provided storage should be set up.
int8_t *vec3i8_asPOD(vec3int8_t *self, int8_t *out);

// Get the data of a 3D vector of uint8_t as a plain-old-data (POD) uint8_t array
// Note: For thread safety, user-provided storage should be set up.
uint8_t *vec3u8_asPOD(vec3uint8_t *self, uint8_t *out);

// Get the data of a 3D vector of int16_t as a plain-old-data (POD) int16_t array
// Note: For thread safety, user-provided storage should be set up.
int16_t *vec3i16_asPOD(vec3int16_t *self, int16_t *out);

// Get the data of a 3D vector of uint16_t as a plain-old-data (POD) uint16_t array
// Note: For thread safety, user-provided storage should be set up.
uint16_t *vec3u16_asPOD(vec3uint16_t *self, uint16_t *out);

// Get the data of a 3D vector of int32_t as a plain-old-data (POD) int32_t array
// Note: For thread safety, user-provided storage should be set up.
int32_t *vec3i32_asPOD(vec3int32_t *self, int32_t *out);

// Get the data of a 3D vector of uint32_t as a plain-old-data (POD) uint32_t array
// Note: For thread safety, user-provided storage should be set up.
uint32_t *vec3u32_asPOD(vec3uint32_t *self, uint32_t *out);

// Get the data of a 3D vector of int64_t as a plain-old-data (POD) int64_t array
// Note: For thread safety, user-provided storage should be set up.
int64_t *vec3i64_asPOD(vec3int64_t *self, int64_t *out);

// Get the data of a 3D vector of uint64_t as a plain-old-data (POD) uint64_t array
// Note: For thread safety, user-provided storage should be set up.
uint64_t *vec3u64_asPOD(vec3uint64_t *self, uint64_t *out);

// Get the data of a 3D vector of float as a plain-old-data (POD) float array
// Note: For thread safety, user-provided storage should be set up.
float *vec3f_asPOD(vec3f_t *self, float *out);

// Get the data of a 3D vector of double as a plain-old-data (POD) double array
// Note: For thread safety, user-provided storage should be set up.
double *vec3d_asPOD(vec3d_t *self, double *out);

// Get the data of a 3D vector of char as a plain-old-data (POD) char array
// Note: For thread safety, user-provided storage should be set up.
char *vec3c_asPOD(vec3char_t *self, char *out);




// Addition of two 3D int8 vectors 'other' and 'out' element-wise.
void vec3i8_add(vec3int8_t * out, vec3int8_t * other);

// Add a scalar 'scalar' to the 3D int8 vector 'out'.
void vec3i8_addS(vec3int8_t * out, int8_t scalar);

// Addition of two 3D int8 vectors 'other' and 'out' element-wise and return the result as a new vector.
vec3int8_t * vec3i8_add_r(vec3int8_t * out, vec3int8_t * other);

// Add a scalar 'scalar' to the 3D int8 vector 'out' and return the result as a new vector.
vec3int8_t * vec3i8_addS_r(vec3int8_t * out, int8_t scalar);


// Addition of two 3D uint8 vectors 'other' and 'out' element-wise.
void vec3u8_add(vec3uint8_t * out, vec3uint8_t * other);

// Add a scalar 'scalar' to the 3D uint8 vector 'out'.
void vec3u8_addS(vec3uint8_t * out, uint8_t scalar);

// Addition of two 3D uint8 vectors 'other' and 'out' element-wise and return the result as a new vector.
vec3uint8_t * vec3u8_add_r(vec3uint8_t * out, vec3uint8_t * other);

// Add a scalar 'scalar' to the 3D uint8 vector 'out' and return the result as a new vector.
vec3uint8_t * vec3u8_addS_r(vec3uint8_t * out, uint8_t scalar);


// Addition of two 3D int16 vectors 'other' and 'out' element-wise.
void vec3i16_add(vec3int16_t * out, vec3int16_t * other);

// Add a scalar 'scalar' to the 3D int16 vector 'out'.
void vec3i16_addS(vec3int16_t * out, int16_t scalar);

// Addition of two 3D int16 vectors 'other' and 'out' element-wise and return the result as a new vector.
vec3int16_t * vec3i16_add_r(vec3int16_t * out, vec3int16_t * other);

// Add a scalar 'scalar' to the 3D int16 vector 'out' and return the result as a new vector.
vec3int16_t * vec3i16_addS_r(vec3int16_t * out, int16_t scalar);


// Addition of two 3D uint16 vectors 'other' and 'out' element-wise.
void vec3u16_add(vec3uint16_t * out, vec3uint16_t * other);

// Add a scalar 'scalar' to the 3D uint16 vector 'out'.
void vec3u16_addS(vec3uint16_t * out, uint16_t scalar);

// Addition of two 3D uint16 vectors 'other' and 'out' element-wise and return the result as a new vector.
vec3uint16_t * vec3u16_add_r(vec3uint16_t * out, vec3uint16_t * other);

// Add a scalar 'scalar' to the 3D uint16 vector 'out' and return the result as a new vector.
vec3uint16_t * vec3u16_addS_r(vec3uint16_t * out, uint16_t scalar);


// Addition of two 3D int32 vectors 'other' and 'out' element-wise.
void vec3i32_add(vec3int32_t * out, vec3int32_t * other);

// Add a scalar 'scalar' to the 3D int32 vector 'out'.
void vec3i32_addS(vec3int32_t * out, int32_t scalar);

// Addition of two 3D int32 vectors 'other' and 'out' element-wise and return the result as a new vector.
vec3int32_t * vec3i32_add_r(vec3int32_t * out, vec3int32_t * other);

// Add a scalar 'scalar' to the 3D int32 vector 'out' and return the result as a new vector.
vec3int32_t * vec3i32_addS_r(vec3int32_t * out, int32_t scalar);

// Addition of two 3D uint32 vectors 'other' and 'out' element-wise.
void vec3u32_add(vec3uint32_t * out, vec3uint32_t * other);

// Add a scalar 'scalar' to the 3D uint32 vector 'out'.
void vec3u32_addS(vec3uint32_t * out, uint32_t scalar);

// Addition of two 3D uint32 vectors 'other' and 'out' element-wise and return the result as a new vector.
vec3uint32_t * vec3u32_add_r(vec3uint32_t * out, vec3uint32_t * other);

// Add a scalar 'scalar' to the 3D uint32 vector 'out' and return the result as a new vector.
vec3uint32_t * vec3u32_addS_r(vec3uint32_t * out, uint32_t scalar);


// Addition of two 3D int64 vectors 'other' and 'out' element-wise.
void vec3i64_add(vec3int64_t * out, vec3int64_t * other);

// Add a scalar 'scalar' to the 3D int64 vector 'out'.
void vec3i64_addS(vec3int64_t * out, int64_t scalar);

// Addition of two 3D int64 vectors 'other' and 'out' element-wise and return the result as a new vector.
vec3int64_t * vec3i64_add_r(vec3int64_t * out, vec3int64_t * other);

// Add a scalar 'scalar' to the 3D int64 vector 'out' and return the result as a new vector.
vec3int64_t * vec3i64_addS_r(vec3int64_t * out, int64_t scalar);


// Addition of two 3D uint64 vectors 'other' and 'out' element-wise.
void vec3u64_add(vec3uint64_t * out, vec3uint64_t * other);

// Add a scalar 'scalar' to the 3D uint64 vector 'out'.
void vec3u64_addS(vec3uint64_t * out, uint64_t scalar);

// Addition of two 3D uint64 vectors 'other' and 'out' element-wise and return the result as a new vector.
vec3uint64_t * vec3u64_add_r(vec3uint64_t * out, vec3uint64_t * other);

// Add a scalar 'scalar' to the 3D uint64 vector 'out' and return the result as a new vector.
vec3uint64_t * vec3u64_addS_r(vec3uint64_t * out, uint64_t scalar);

// Addition of two 3D float vectors 'other' and 'out' element-wise.
void vec3f_add(vec3f_t * out, vec3f_t * other);

// Add a scalar 'scalar' to the 3D float vector 'out'.
void vec3f_addS(vec3f_t * out, float scalar);

// Addition of two 3D float vectors 'other' and 'out' element-wise and return the result as a new vector.
vec3f_t * vec3f_add_r(vec3f_t * out, vec3f_t * other);

// Add a scalar 'scalar' to the 3D float vector 'out' and return the result as a new vector.
vec3f_t * vec3f_addS_r(vec3f_t * out, float scalar);

// Addition of two 3D double vectors 'other' and 'out' element-wise.
void vec3d_add(vec3d_t * out, vec3d_t * other);

// Add a scalar 'scalar' to the 3D double vector 'out'.
void vec3d_addS(vec3d_t * out, double scalar);

// Addition of two 3D double vectors 'other' and 'out' element-wise and return the result as a new vector.
vec3d_t * vec3d_add_r(vec3d_t * out, vec3d_t * other);

// Add a scalar 'scalar' to the 3D double vector 'out' and return the result as a new vector.
vec3d_t * vec3d_addS_r(vec3d_t * out, double scalar);


// Subtract the 3D int8 vector 'other' from the 3D int8 vector 'out' element-wise.
void vec3i8_sub(vec3int8_t * out, vec3int8_t * other);

// Subtract a scalar 'scalar' from the 3D int8 vector 'out'.
void vec3i8_subS(vec3int8_t * out, int8_t scalar);

// Subtract the 3D int8 vector 'other' from the 3D int8 vector 'out' element-wise and return the result as a new vector.
vec3int8_t * vec3i8_sub_r(vec3int8_t * out, vec3int8_t * other);

// Subtract a scalar 'scalar' from the 3D int8 vector 'out' and return the result as a new vector.
vec3int8_t * vec3i8_subS_r(vec3int8_t * out, int8_t scalar);


// Subtract the 3D uint8 vector 'other' from the 3D uint8 vector 'out' element-wise.
void vec3u8_sub(vec3uint8_t * out, vec3uint8_t * other);

// Subtract a scalar 'scalar' from the 3D uint8 vector 'out'.
void vec3u8_subS(vec3uint8_t * out, uint8_t scalar);

// Subtract the 3D uint8 vector 'other' from the 3D uint8 vector 'out' element-wise and return the result as a new vector.
vec3uint8_t * vec3u8_sub_r(vec3uint8_t * out, vec3uint8_t * other);

// Subtract a scalar 'scalar' from the 3D uint8 vector 'out' and return the result as a new vector.
vec3uint8_t * vec3u8_subS_r(vec3uint8_t * out, uint8_t scalar);

// Subtract the 3D int16 vector 'other' from the 3D int16 vector 'out' element-wise.
void vec3i16_sub(vec3int16_t * out, vec3int16_t * other);

// Subtract a scalar 'scalar' from the 3D int16 vector 'out'.
void vec3i16_subS(vec3int16_t * out, int16_t scalar);

// Subtract the 3D int16 vector 'other' from the 3D int16 vector 'out' element-wise and return the result as a new vector.
vec3int16_t * vec3i16_sub_r(vec3int16_t * out, vec3int16_t * other);

// Subtract a scalar 'scalar' from the 3D int16 vector 'out' and return the result as a new vector.
vec3int16_t * vec3i16_subS_r(vec3int16_t * out, int16_t scalar);

// Subtract the 3D uint16 vector 'other' from the 3D uint16 vector 'out' element-wise.
void vec3u16_sub(vec3uint16_t * out, vec3uint16_t * other);

// Subtract a scalar 'scalar' from the 3D uint16 vector 'out'.
void vec3u16_subS(vec3uint16_t * out, uint16_t scalar);

// Subtract the 3D uint16 vector 'other' from the 3D uint16 vector 'out' element-wise and return the result as a new vector.
vec3uint16_t * vec3u16_sub_r(vec3uint16_t * out, vec3uint16_t * other);

// Subtract a scalar 'scalar' from the 3D uint16 vector 'out' and return the result as a new vector.
vec3uint16_t * vec3u16_subS_r(vec3uint16_t * out, uint16_t scalar);


// Subtract the 3D int32 vector 'other' from the 3D int32 vector 'out' element-wise.
void vec3i32_sub(vec3int32_t * out, vec3int32_t * other);

// Subtract a scalar 'scalar' from the 3D int32 vector 'out'.
void vec3i32_subS(vec3int32_t * out, int32_t scalar);

// Subtract the 3D int32 vector 'other' from the 3D int32 vector 'out' element-wise and return the result as a new vector.
vec3int32_t * vec3i32_sub_r(vec3int32_t * out, vec3int32_t * other);

// Subtract a scalar 'scalar' from the 3D int32 vector 'out' and return the result as a new vector.
vec3int32_t * vec3i32_subS_r(vec3int32_t * out, int32_t scalar);

// Subtract the 3D uint32 vector 'other' from the 3D uint32 vector 'out' element-wise.
void vec3u32_sub(vec3uint32_t * out, vec3uint32_t * other);

// Subtract a scalar 'scalar' from the 3D uint32 vector 'out'.
void vec3u32_subS(vec3uint32_t * out, uint32_t scalar);

// Subtract the 3D uint32 vector 'other' from the 3D uint32 vector 'out' element-wise and return the result as a new vector.
vec3uint32_t * vec3u32_sub_r(vec3uint32_t * out, vec3uint32_t * other);

// Subtract a scalar 'scalar' from the 3D uint32 vector 'out' and return the result as a new vector.
vec3uint32_t * vec3u32_subS_r(vec3uint32_t * out, uint32_t scalar);

// Subtract the 3D int64 vector 'other' from the 3D int64 vector 'out' element-wise.
void vec3i64_sub(vec3int64_t * out, vec3int64_t * other);

// Subtract a scalar 'scalar' from the 3D int64 vector 'out'.
void vec3i64_subS(vec3int64_t * out, int64_t scalar);

// Subtract the 3D int64 vector 'other' from the 3D int64 vector 'out' element-wise and return the result as a new vector.
vec3int64_t * vec3i64_sub_r(vec3int64_t * out, vec3int64_t * other);

// Subtract a scalar 'scalar' from the 3D int64 vector 'out' and return the result as a new vector.
vec3int64_t * vec3i64_subS_r(vec3int64_t * out, int64_t scalar);


// Subtract the 3D uint64 vector 'other' from the 3D uint64 vector 'out' element-wise.
void vec3u64_sub(vec3uint64_t * out, vec3uint64_t * other);

// Subtract a scalar 'scalar' from the 3D uint64 vector 'out'.
void vec3u64_subS(vec3uint64_t * out, uint64_t scalar);

// Subtract the 3D uint64 vector 'other' from the 3D uint64 vector 'out' element-wise and return the result as a new vector.
vec3uint64_t * vec3u64_sub_r(vec3uint64_t * out, vec3uint64_t * other);

// Subtract a scalar 'scalar' from the 3D uint64 vector 'out' and return the result as a new vector.
vec3uint64_t * vec3u64_subS_r(vec3uint64_t * out, uint64_t scalar);

// Subtract the 3D float vector 'other' from the 3D float vector 'out' element-wise.
void vec3f_sub(vec3f_t * out, vec3f_t * other);

// Subtract a scalar 'scalar' from the 3D float vector 'out'.
void vec3f_subS(vec3f_t * out, float scalar);

// Subtract the 3D float vector 'other' from the 3D float vector 'out' element-wise and return the result as a new vector.
vec3f_t * vec3f_sub_r(vec3f_t * out, vec3f_t * other);

// Subtract a scalar 'scalar' from the 3D float vector 'out' and return the result as a new vector.
vec3f_t * vec3f_subS_r(vec3f_t * out, float scalar);

// Subtract the 3D double vector 'other' from the 3D double vector 'out' element-wise.
void vec3d_sub(vec3d_t * out, vec3d_t * other);

// Subtract a scalar 'scalar' from the 3D double vector 'out'.
void vec3d_subS(vec3d_t * out, double scalar);

// Subtract the 3D double vector 'other' from the 3D double vector 'out' element-wise and return the result as a new vector.
vec3d_t * vec3d_sub_r(vec3d_t * out, vec3d_t * other);

// Subtract a scalar 'scalar' from the 3D double vector 'out' and return the result as a new vector.
vec3d_t * vec3d_subS_r(vec3d_t * out, double scalar);


//Multiplication (only doing 16-bits+)
// Multiply the 3D int16 vector 'out' element-wise with another 3D int16 vector 'other'.
void vec3i16_mult(vec3int16_t * out, vec3int16_t * other);

// Multiply the 3D int16 vector 'out' by a scalar 'scalar'.
void vec3i16_multS(vec3int16_t * out, int16_t scalar);

// Multiply the 3D int16 vector 'out' element-wise with another 3D int16 vector 'other' and return the result as a new vector.
vec3int16_t * vec3i16_mult_r(vec3int16_t * out, vec3int16_t * other);

// Multiply the 3D int16 vector 'out' by a scalar 'scalar' and return the result as a new vector.
vec3int16_t * vec3i16_multS_r(vec3int16_t * out, int16_t scalar);

// Multiply the 3D uint16 vector 'out' element-wise with another 3D uint16 vector 'other'.
void vec3u16_mult(vec3uint16_t * out, vec3uint16_t * other);

// Multiply the 3D uint16 vector 'out' by a scalar 'scalar'.
void vec3u16_multS(vec3uint16_t * out, uint16_t scalar);

// Multiply the 3D uint16 vector 'out' element-wise with another 3D uint16 vector 'other' and return the result as a new vector.
vec3uint16_t * vec3u16_mult_r(vec3uint16_t * out, vec3uint16_t * other);

// Multiply the 3D uint16 vector 'out' by a scalar 'scalar' and return the result as a new vector.
vec3uint16_t * vec3u16_multS_r(vec3uint16_t * out, uint16_t scalar);


// Multiply the 3D int32 vector 'out' element-wise with another 3D int32 vector 'other'.
void vec3i32_mult(vec3int32_t * out, vec3int32_t * other);

// Multiply the 3D int32 vector 'out' by a scalar 'scalar'.
void vec3i32_multS(vec3int32_t * out, int32_t scalar);

// Multiply the 3D int32 vector 'out' element-wise with another 3D int32 vector 'other' and return the result as a new vector.
vec3int32_t * vec3i32_mult_r(vec3int32_t * out, vec3int32_t * other);

// Multiply the 3D int32 vector 'out' by a scalar 'scalar' and return the result as a new vector.
vec3int32_t * vec3i32_multS_r(vec3int32_t * out, int32_t scalar);

// Multiply the 3D uint32 vector 'out' element-wise with another 3D uint32 vector 'other'.
void vec3u32_mult(vec3uint32_t * out, vec3uint32_t * other);

// Multiply the 3D uint32 vector 'out' by a scalar 'scalar'.
void vec3u32_multS(vec3uint32_t * out, uint32_t scalar);

// Multiply the 3D uint32 vector 'out' element-wise with another 3D uint32 vector 'other' and return the result as a new vector.
vec3uint32_t * vec3u32_mult_r(vec3uint32_t * out, vec3uint32_t * other);

// Multiply the 3D uint32 vector 'out' by a scalar 'scalar' and return the result as a new vector.
vec3uint32_t * vec3u32_multS_r(vec3uint32_t * out, uint32_t scalar);


// Multiply the 3D int64 vector 'out' element-wise with another 3D int64 vector 'other'.
void vec3i64_mult(vec3int64_t * out, vec3int64_t * other);

// Multiply the 3D int64 vector 'out' by a scalar 'scalar'.
void vec3i64_multS(vec3int64_t * out, int64_t scalar);

// Multiply the 3D int64 vector 'out' element-wise with another 3D int64 vector 'other' and return the result as a new vector.
vec3int64_t * vec3i64_mult_r(vec3int64_t * out, vec3int64_t * other);

// Multiply the 3D int64 vector 'out' by a scalar 'scalar' and return the result as a new vector.
vec3int64_t * vec3i64_multS_r(vec3int64_t * out, int64_t scalar);

// Multiply the 3D uint64 vector 'out' element-wise with another 3D uint64 vector 'other'.
void vec3u64_mult(vec3uint64_t * out, vec3uint64_t * other);

// Multiply the 3D uint64 vector 'out' by a scalar 'scalar'.
void vec3u64_multS(vec3uint64_t * out, uint64_t scalar);

// Multiply the 3D uint64 vector 'out' element-wise with another 3D uint64 vector 'other' and return the result as a new vector.
vec3uint64_t * vec3u64_mult_r(vec3uint64_t * out, vec3uint64_t * other);

// Multiply the 3D uint64 vector 'out' by a scalar 'scalar' and return the result as a new vector.
vec3uint64_t * vec3u64_multS_r(vec3uint64_t * out, uint64_t scalar);


// Multiply the 3D float vector 'out' element-wise with another 3D float vector 'other'.
void vec3f_mult(vec3f_t * out, vec3f_t * other);

// Multiply the 3D float vector 'out' by a scalar 'scalar'.
void vec3f_multS(vec3f_t * out, float scalar);

// Multiply the 3D float vector 'out' element-wise with another 3D float vector 'other' and return the result as a new vector.
vec3f_t * vec3f_mult_r(vec3f_t * out, vec3f_t * other);

// Multiply the 3D float vector 'out' by a scalar 'scalar' and return the result as a new vector.
vec3f_t * vec3f_multS_r(vec3f_t * out, float scalar);

// Multiply the 3D double vector 'out' element-wise with another 3D double vector 'other'.
void vec3d_mult(vec3d_t * out, vec3d_t * other);

// Multiply the 3D double vector 'out' by a scalar 'scalar'.
void vec3d_multS(vec3d_t * out, double scalar);

// Multiply the 3D double vector 'out' element-wise with another 3D double vector 'other' and return the result as a new vector.
vec3d_t * vec3d_mult_r(vec3d_t * out, vec3d_t * other);

// Multiply the 3D double vector 'out' by a scalar 'scalar' and return the result as a new vector.
vec3d_t * vec3d_multS_r(vec3d_t * out, double scalar);

//Divison (TO BE IMPLEMENTED)



// Calculate the Euclidean length (magnitude) of the 3D int8 vector 'self' and return the result as a float.
float vec3i8_length(vec3int8_t * self);

// Calculate the Euclidean length (magnitude) of the 3D uint8 vector 'self' and return the result as a float.
float vec3u8_length(vec3uint8_t * self);

// Calculate the Euclidean length (magnitude) of the 3D int16 vector 'self' and return the result as a float.
float vec3i16_length(vec3int16_t * self);

// Calculate the Euclidean length (magnitude) of the 3D uint16 vector 'self' and return the result as a float.
float vec3u16_length(vec3uint16_t * self);

// Calculate the Euclidean length (magnitude) of the 3D int32 vector 'self' and return the result as a float.
float vec3i32_length(vec3int32_t * self);

// Calculate the Euclidean length (magnitude) of the 3D uint32 vector 'self' and return the result as a float.
float vec3u32_length(vec3uint32_t * self);

// Calculate the Euclidean length (magnitude) of the 3D int64 vector 'self' and return the result as a float.
float vec3i64_length(vec3int64_t * self);

// Calculate the Euclidean length (magnitude) of the 3D uint64 vector 'self' and return the result as a float.
float vec3u64_length(vec3uint64_t * self);

// Calculate the Euclidean length (magnitude) of the 3D char vector 'self' and return the result as a float.
float vec3c_length(vec3char_t * self);

// Calculate the Euclidean length (magnitude) of the 3D float vector 'self' and return the result as a float.
float vec3f_length(vec3f_t * self);

// Calculate the Euclidean length (magnitude) of the 3D double vector 'self' and return the result as a float.
float vec3d_length(vec3d_t * self);


// Calculate the dot product of two 3D int8 vectors 'left' and 'right' and return the result as a float.
float vec3i8_dot(vec3int8_t * left, vec3int8_t * right);

// Calculate the dot product of two 3D uint8 vectors 'left' and 'right' and return the result as a float.
float vec3u8_dot(vec3uint8_t * left, vec3uint8_t * right);

// Calculate the dot product of two 3D int16 vectors 'left' and 'right' and return the result as a float.
float vec3i16_dot(vec3int16_t * left, vec3int16_t * right);

// Calculate the dot product of two 3D uint16 vectors 'left' and 'right' and return the result as a float.
float vec3u16_dot(vec3uint16_t * left, vec3uint16_t * right);

// Calculate the dot product of two 3D int32 vectors 'left' and 'right' and return the result as a float.
float vec3i32_dot(vec3int32_t * left, vec3int32_t * right);

// Calculate the dot product of two 3D uint32 vectors 'left' and 'right' and return the result as a float.
float vec3u32_dot(vec3uint32_t * left, vec3uint32_t * right);

// Calculate the dot product of two 3D int64 vectors 'left' and 'right' and return the result as a float.
float vec3i64_dot(vec3int64_t * left, vec3int64_t * right);

// Calculate the dot product of two 3D uint64 vectors 'left' and 'right' and return the result as a float.
float vec3u64_dot(vec3uint64_t * left, vec3uint64_t * right);

// Calculate the dot product of two 3D char vectors 'left' and 'right' and return the result as a float.
float vec3c_dot(vec3char_t * left, vec3char_t * right);

// Calculate the dot product of two 3D float vectors 'left' and 'right' and return the result as a float.
float vec3f_dot(vec3f_t * left, vec3f_t * right);

// Calculate the dot product of two 3D double vectors 'left' and 'right' and return the result as a float.
float vec3d_dot(vec3d_t * left, vec3d_t * right);



// Calculate the cross product of two 3D int8 vectors 'left' and 'right' and store the result in 'out'.
void vec3i8_cross(vec3int8_t * out, vec3int8_t * left, vec3int8_t * right);

// Calculate the cross product of two 3D uint8 vectors 'left' and 'right' and store the result in 'out'.
void vec3u8_cross(vec3uint8_t * out, vec3uint8_t * left, vec3uint8_t * right);

// Calculate the cross product of two 3D int16 vectors 'left' and 'right' and store the result in 'out'.
void vec3i16_cross(vec3int16_t * out, vec3int16_t * left, vec3int16_t * right);

// Calculate the cross product of two 3D uint16 vectors 'left' and 'right' and store the result in 'out'.
void vec3u16_cross(vec3uint16_t * out, vec3uint16_t * left, vec3uint16_t * right);

// Calculate the cross product of two 3D int32 vectors 'left' and 'right' and store the result in 'out'.
void vec3i32_cross(vec3int32_t * out, vec3int32_t * left, vec3int32_t * right);

// Calculate the cross product of two 3D uint32 vectors 'left' and 'right' and store the result in 'out'.
void vec3u32_cross(vec3uint32_t * out, vec3uint32_t * left, vec3uint32_t * right);

// Calculate the cross product of two 3D int64 vectors 'left' and 'right' and store the result in 'out'.
void vec3i64_cross(vec3int64_t * out, vec3int64_t * left, vec3int64_t * right);

// Calculate the cross product of two 3D uint64 vectors 'left' and 'right' and store the result in 'out'.
void vec3u64_cross(vec3uint64_t * out, vec3uint64_t * left, vec3uint64_t * right);

// Calculate the cross product of two 3D float vectors 'left' and 'right' and store the result in 'out'.
void vec3f_cross(vec3f_t * out, vec3f_t * left, vec3f_t * right);

// Calculate the cross product of two 3D double vectors 'left' and 'right' and store the result in 'out'.
void vec3d_cross(vec3d_t * out, vec3d_t * left, vec3d_t * right);


// Returned version: Calculate the cross product of two 3D int8 vectors 'left' and 'right' and store the result in 'out'.
vec3int8_t * vec3i8_cross_r(vec3int8_t * out, vec3int8_t * left, vec3int8_t * right);

// Returned version: Calculate the cross product of two 3D uint8 vectors 'left' and 'right' and store the result in 'out'.
vec3uint8_t * vec3u8_cross_r(vec3uint8_t * out, vec3uint8_t * left, vec3uint8_t * right);

// Returned version: Calculate the cross product of two 3D int16 vectors 'left' and 'right' and store the result in 'out'.
vec3int16_t * vec3i16_cross_r(vec3int16_t * out, vec3int16_t * left, vec3int16_t * right);

// Returned version: Calculate the cross product of two 3D uint16 vectors 'left' and 'right' and store the result in 'out'.
vec3uint16_t * vec3u16_cross_r(vec3uint16_t * out, vec3uint16_t * left, vec3uint16_t * right);

// Returned version: Calculate the cross product of two 3D int32 vectors 'left' and 'right' and store the result in 'out'.
vec3int32_t * vec3i32_cross_r(vec3int32_t * out, vec3int32_t * left, vec3int32_t * right);

// Returned version: Calculate the cross product of two 3D uint32 vectors 'left' and 'right' and store the result in 'out'.
vec3uint32_t * vec3u32_cross_r(vec3uint32_t * out, vec3uint32_t * left, vec3uint32_t * right);

// Returned version: Calculate the cross product of two 3D int64 vectors 'left' and 'right' and store the result in 'out'.
vec3int64_t * vec3i64_cross_r(vec3int64_t * out, vec3int64_t * left, vec3int64_t * right);

// Returned version: Calculate the cross product of two 3D uint64 vectors 'left' and 'right' and store the result in 'out'.
vec3uint64_t * vec3u64_cross_r(vec3uint64_t * out, vec3uint64_t * left, vec3uint64_t * right);

// Returned version: Calculate the cross product of two 3D float vectors 'left' and 'right' and store the result in 'out'.
vec3f_t * vec3f_cross_r(vec3f_t * out, vec3f_t * left, vec3f_t * right);

// Returned version: Calculate the cross product of two 3D double vectors 'left' and 'right' and store the result in 'out'.
vec3d_t * vec3d_cross_r(vec3d_t * out, vec3d_t * left, vec3d_t * right);



// Normalize a 3D float vector 'self' and store the result in 'out'.
void vec3f_normalize(vec3f_t * out, vec3f_t * self);

// Interpolate between two 3D float vectors 'start' and 'end' with a given 'percentage' and store the result in 'out'.
void vec3f_lerp(vec3f_t * out, vec3f_t * start, vec3f_t * end, float percentage);

// Perform spherical linear interpolation (SLERP) between two 3D float vectors 'start' and 'end' with a given 'percentage' and store the result in 'out'.
void vec3f_slerp(vec3f_t * out, vec3f_t * start, vec3f_t * end, float percentage);

// Perform normalized linear interpolation (NLERP) between two 3D float vectors 'start' and 'end' with a given 'percentage' and store the result in 'out'.
void vec3f_nlerp(vec3f_t * out, vec3f_t * start, vec3f_t * end, float percentage);

// Normalize a 3D double vector 'self' and store the result in 'out'.
void vec3d_normalize(vec3d_t * out, vec3d_t * self);

// Interpolate between two 3D double vectors 'start' and 'end' with a given 'percentage' and store the result in 'out'.
void vec3d_lerp(vec3d_t * out, vec3d_t * start, vec3d_t * end, float percentage);

// Perform spherical linear interpolation (SLERP) between two 3D double vectors 'start' and 'end' with a given 'percentage' and store the result in 'out'.
void vec3d_slerp(vec3d_t * out, vec3d_t * start, vec3d_t * end, float percentage);

// Perform normalized linear interpolation (NLERP) between two 3D double vectors 'start' and 'end' with a given 'percentage' and store the result in 'out'.
void vec3d_nlerp(vec3d_t * out, vec3d_t * start, vec3d_t * end, float percentage);


// Returned version: Normalize a 3D float vector 'self' and return the normalized vector.
vec3f_t * vec3f_normalize_r(vec3f_t * out, vec3f_t * self);

// Returned version: Interpolate between two 3D float vectors 'start' and 'end' with a given 'percentage' and return the interpolated vector.
vec3f_t * vec3f_lerp_r(vec3f_t * out, vec3f_t * start, vec3f_t * end, float percentage);

// Returned version: Perform spherical linear interpolation (SLERP) between two 3D float vectors 'start' and 'end' with a given 'percentage' and return the interpolated vector.
vec3f_t * vec3f_slerp_r(vec3f_t * out, vec3f_t * start, vec3f_t * end, float percentage);

// Returned version: Perform normalized linear interpolation (NLERP) between two 3D float vectors 'start' and 'end' with a given 'percentage' and return the interpolated vector.
vec3f_t * vec3f_nlerp_r(vec3f_t * out, vec3f_t * start, vec3f_t * end, float percentage);

// Returned version: Normalize a 3D double vector 'self' and return the normalized vector.
vec3d_t * vec3d_normalize_r(vec3d_t * out, vec3d_t * self);

// Returned version: Interpolate between two 3D double vectors 'start' and 'end' with a given 'percentage' and return the interpolated vector.
vec3d_t * vec3d_lerp_r(vec3d_t * out, vec3d_t * start, vec3d_t * end, float percentage);

// Returned version: Perform spherical linear interpolation (SLERP) between two 3D double vectors 'start' and 'end' with a given 'percentage' and return the interpolated vector.
vec3d_t * vec3d_slerp_r(vec3d_t * out, vec3d_t * start, vec3d_t * end, float percentage);

// Returned version: Perform normalized linear interpolation (NLERP) between two 3D double vectors 'start' and 'end' with a given 'percentage' and return the interpolated vector.
vec3d_t * vec3d_nlerp_r(vec3d_t * out, vec3d_t * start, vec3d_t * end, float percentage);


// Get the size (in bytes) of a 3D vector of int8_t
size_t vec3i8_getSize();

// Get the size (in bytes) of a 3D vector of uint8_t
size_t vec3u8_getSize();

// Get the size (in bytes) of a 3D vector of int16_t
size_t vec3i16_getSize();

// Get the size (in bytes) of a 3D vector of uint16_t
size_t vec3u16_getSize();

// Get the size (in bytes) of a 3D vector of int32_t
size_t vec3i32_getSize();

// Get the size (in bytes) of a 3D vector of uint32_t
size_t vec3u32_getSize();

// Get the size (in bytes) of a 3D vector of int64_t
size_t vec3i64_getSize();

// Get the size (in bytes) of a 3D vector of uint64_t
size_t vec3u64_getSize();

// Get the size (in bytes) of a 3D vector of char
size_t vec3c_getSize();

// Get the size (in bytes) of a 3D vector of float
size_t vec3f_getSize();

// Get the size (in bytes) of a 3D vector of double
size_t vec3d_getSize();


// Convert a 3D vector of int8_t to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3i8_toString(vec3int8_t *self);

// Convert a 3D vector of uint8_t to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3u8_toString(vec3uint8_t *self);

// Convert a 3D vector of int16_t to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3i16_toString(vec3int16_t *self);

// Convert a 3D vector of uint16_t to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3u16_toString(vec3uint16_t *self);

// Convert a 3D vector of int32_t to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3i32_toString(vec3int32_t *self);

// Convert a 3D vector of uint32_t to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3u32_toString(vec3uint32_t *self);

// Convert a 3D vector of int64_t to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3i64_toString(vec3int64_t *self);

// Convert a 3D vector of uint64_t to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3u64_toString(vec3uint64_t *self);

// Convert a 3D vector of char to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3c_toString(vec3char_t *self);

// Convert a 3D vector of float to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3f_toString(vec3f_t *self);

// Convert a 3D vector of double to a dynamically allocated string
// The returned string must be freed when no longer needed.
char *vec3d_toString(vec3d_t *self);




// Print the values of a 3D vector of int8_t to the standard output
void printvec3i8(vec3int8_t *vec);

// Print the values of a 3D vector of uint8_t to the standard output
void printvec3u8(vec3uint8_t *vec);

// Print the values of a 3D vector of int16_t to the standard output
void printvec3i16(vec3int16_t *vec);

// Print the values of a 3D vector of uint16_t to the standard output
void printvec3u16(vec3uint16_t *vec);

// Print the values of a 3D vector of int32_t to the standard output
void printvec3i32(vec3int32_t *vec);

// Print the values of a 3D vector of uint32_t to the standard output
void printvec3u32(vec3uint32_t *vec);

// Print the values of a 3D vector of int64_t to the standard output
void printvec3i64(vec3int64_t *vec);

// Print the values of a 3D vector of uint64_t to the standard output
void printvec3u64(vec3uint64_t *vec);

// Print the values of a 3D vector of char to the standard output
void printvec3c(vec3char_t *vec);

// Print the values of a 3D vector of float to the standard output
void printvec3f(vec3f_t *vec);

// Print the values of a 3D vector of double to the standard output
void printvec3d(vec3d_t *vec);



#endif
