#ifndef FOUNDATIONS_MATH_VEC2_H_
#define FOUNDATIONS_MATH_VEC2_H_ 1

// Standard header for fixed-size integer types
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

#ifndef VEC2_FOWARDED
// Forward Declarations for 2D Vector Types
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

// Define VEC2_FOWARDED to indicate that these forward declarations have been made.
#define VEC2_FOWARDED 1
#endif


/**
Convention Discussion:

void function(type * out, ...etc);
type * function_r(...etc);

**/

//Initalize an already allocated vector.
// Initialize a 2D vector of int8_t (8-bit signed integers) with given x and y values.
void initVec2I8(vec2int8_t *out, int8_t x, int8_t y);

// Initialize a 2D vector of uint8_t (8-bit unsigned integers) with given x and y values.
void initVec2U8(vec2uint8_t *out, uint8_t x, uint8_t y);

// Initialize a 2D vector of int16_t (16-bit signed integers) with given x and y values.
void initVec2I16(vec2int16_t *out, int16_t x, int16_t y);

// Initialize a 2D vector of uint16_t (16-bit unsigned integers) with given x and y values.
void initVec2U16(vec2uint16_t *out, uint16_t x, uint16_t y);

// Initialize a 2D vector of int32_t (32-bit signed integers) with given x and y values.
void initVec2I32(vec2int32_t *out, int32_t x, int32_t y);

// Initialize a 2D vector of uint32_t (32-bit unsigned integers) with given x and y values.
void initVec2U32(vec2uint32_t *out, uint32_t x, uint32_t y);

// Initialize a 2D vector of int64_t (64-bit signed integers) with given x and y values.
void initVec2I64(vec2int64_t *out, int64_t x, int64_t y);

// Initialize a 2D vector of uint64_t (64-bit unsigned integers) with given x and y values.
void initVec2U64(vec2uint64_t *out, uint64_t x, uint64_t y);

// Initialize a 2D vector of char with given x and y values.
void initVec2C(vec2char_t *out, char x, char y);

// Initialize a 2D vector of float with given x and y values.
void initVec2F(vec2f_t *out, float x, float y);

// Initialize a 2D vector of double with given x and y values.
void initVec2D(vec2d_t *out, double x, double y);

// Allocate and Initialize 2D Vectors

// Allocate and initialize a 2D vector of int8_t with the specified values.
vec2int8_t * allocVec2I8(int8_t x, int8_t y);

// Allocate and initialize a 2D vector of uint8_t with the specified values.
vec2uint8_t * allocVec2U8(uint8_t x, uint8_t y);

// Allocate and initialize a 2D vector of int16_t with the specified values.
vec2int16_t * allocVec2I16(int16_t x, int16_t y);

// Allocate and initialize a 2D vector of uint16_t with the specified values.
vec2uint16_t * allocVec2U16(uint16_t x, uint16_t y);

// Allocate and initialize a 2D vector of int32_t with the specified values.
vec2int32_t * allocVec2I32(int32_t x, int32_t y);

// Allocate and initialize a 2D vector of uint32_t with the specified values.
vec2uint32_t * allocVec2U32(uint32_t x, uint32_t y);

// Allocate and initialize a 2D vector of int64_t with the specified values.
vec2int64_t * allocVec2I64(int64_t x, int64_t y);

// Allocate and initialize a 2D vector of uint64_t with the specified values.
vec2uint64_t * allocVec2U64(uint64_t x, uint64_t y);

// Allocate and initialize a 2D vector of char with the specified values.
vec2char_t * allocVec2C(char x, char y);

// Allocate and initialize a 2D vector of float with the specified values.
vec2f_t * allocVec2F(float x, float y);

// Allocate and initialize a 2D vector of double with the specified values.
vec2d_t * allocVec2D(double x, double y);

//getters and setters
// Set the x component of a 2D vector of int8_t (8-bit signed integers).
void vec2i8_setX(vec2int8_t *out, int8_t x);

// Set the y component of a 2D vector of int8_t (8-bit signed integers).
void vec2i8_setY(vec2int8_t *out, int8_t y);

// Get the x component of a 2D vector of int8_t (8-bit signed integers).
int8_t vec2i8_X(vec2int8_t *out);

// Get the y component of a 2D vector of int8_t (8-bit signed integers).
int8_t vec2i8_Y(vec2int8_t *out);

// Set the x component of a 2D vector of uint8_t (8-bit unsigned integers).
void vec2u8_setX(vec2uint8_t *out, uint8_t x);

// Set the y component of a 2D vector of uint8_t (8-bit unsigned integers).
void vec2u8_setY(vec2uint8_t *out, uint8_t y);

// Get the x component of a 2D vector of uint8_t (8-bit unsigned integers).
uint8_t vec2u8_X(vec2uint8_t *out);

// Get the y component of a 2D vector of uint8_t (8-bit unsigned integers).
uint8_t vec2u8_Y(vec2uint8_t *out);

// Set the x component of a 2D vector of int16_t (16-bit signed integers).
void vec2i16_setX(vec2int16_t *out, int16_t x);

// Set the y component of a 2D vector of int16_t (16-bit signed integers).
void vec2i16_setY(vec2int16_t *out, int16_t y);

// Get the x component of a 2D vector of int16_t (16-bit signed integers).
int16_t vec2i16_X(vec2int16_t *out);

// Get the y component of a 2D vector of int16_t (16-bit signed integers).
int16_t vec2i16_Y(vec2int16_t *out);

// Set the x component of a 2D vector of uint16_t (16-bit unsigned integers).
void vec2u16_setX(vec2uint16_t *out, uint16_t x);

// Set the y component of a 2D vector of uint16_t (16-bit unsigned integers).
void vec2u16_setY(vec2uint16_t *out, uint16_t y);

// Get the x component of a 2D vector of uint16_t (16-bit unsigned integers).
uint16_t vec2u16_X(vec2uint16_t *out);

// Get the y component of a 2D vector of uint16_t (16-bit unsigned integers).
uint16_t vec2u16_Y(vec2uint16_t *out);


// Set the X-component of a 2D vector of int32_t.
void vec2i32_setX(vec2int32_t * out, int32_t x);

// Set the Y-component of a 2D vector of int32_t.
void vec2i32_setY(vec2int32_t * out, int32_t y);

// Get the X-component of a 2D vector of int32_t.
int32_t vec2i32_X(vec2int32_t * out);

// Get the Y-component of a 2D vector of int32_t.
int32_t vec2i32_Y(vec2int32_t * out);

// Set the X-component of a 2D vector of uint32_t.
void vec2u32_setX(vec2uint32_t * out, uint32_t x);

// Set the Y-component of a 2D vector of uint32_t.
void vec2u32_setY(vec2uint32_t * out, uint32_t y);

// Get the X-component of a 2D vector of uint32_t.
uint32_t vec2u32_X(vec2uint32_t * out);

// Get the Y-component of a 2D vector of uint32_t.
uint32_t vec2u32_Y(vec2uint32_t * out);

// Set the X-component of a 2D vector of char.
void vec2char_setX(vec2char_t * out, char x);

// Set the Y-component of a 2D vector of char.
void vec2char_setY(vec2char_t * out, char y);

// Get the X-component of a 2D vector of char.
char vec2char_X(vec2char_t * out);

// Get the Y-component of a 2D vector of char.
char vec2char_Y(vec2char_t * out);

// Set the X-component of a 2D vector of float.
void vec2f_setX(vec2f_t * out, float x);

// Set the Y-component of a 2D vector of float.
void vec2f_setY(vec2f_t * out, float y);

// Get the X-component of a 2D vector of float.
float vec2f_X(vec2f_t * out);

// Get the Y-component of a 2D vector of float.
float vec2f_Y(vec2f_t * out);

// Set the X-component of a 2D vector of double.
void vec2d_setX(vec2d_t * out, double x);

// Set the Y-component of a 2D vector of double.
void vec2d_setY(vec2d_t * out, double y);

// Get the X-component of a 2D vector of double.
double vec2d_X(vec2d_t * out);

// Get the Y-component of a 2D vector of double.
double vec2d_Y(vec2d_t * out);


//addition
/**
 * @brief Performs element-wise addition between two vec2int8_t vectors.
 *
 * @param out A pointer to the destination vec2int8_t vector where the result will be stored.
 * @param other A pointer to the source vec2int8_t vector to be added.
 */
void vec2i8_add(vec2int8_t *out, vec2int8_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2int8_t vector.
 *
 * @param out A pointer to the destination vec2int8_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 */
void vec2i8_addS(vec2int8_t *out, int8_t scalar);

/**
 * @brief Performs element-wise addition between two vec2int8_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2int8_t vector where the result will be stored.
 * @param other A pointer to the source vec2int8_t vector to be added.
 *
 * @return A pointer to a newly allocated vec2int8_t vector containing the result of the addition.
 */
vec2int8_t *vec2i8_add_r(vec2int8_t *out, vec2int8_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2int8_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2int8_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 *
 * @return A pointer to a newly allocated vec2int8_t vector containing the result of the addition.
 */
vec2int8_t *vec2i8_addS_r(vec2int8_t *out, int8_t scalar);

/**
 * @brief Performs element-wise addition between two vec2uint8_t vectors.
 *
 * @param out A pointer to the destination vec2uint8_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint8_t vector to be added.
 */
void vec2u8_add(vec2uint8_t *out, vec2uint8_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2uint8_t vector.
 *
 * @param out A pointer to the destination vec2uint8_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 */
void vec2u8_addS(vec2int8_t *out, uint8_t scalar);

/**
 * @brief Performs element-wise addition between two vec2uint8_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint8_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint8_t vector to be added.
 *
 * @return A pointer to a newly allocated vec2uint8_t vector containing the result of the addition.
 */
vec2uint8_t *vec2u8_add_r(vec2uint8_t *out, vec2uint8_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2uint8_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint8_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 *
 * @return A pointer to a newly allocated vec2uint8_t vector containing the result of the addition.
 */
vec2uint8_t *vec2u8_addS_r(vec2uint8_t *out, uint8_t scalar);

/**
 * @brief Performs element-wise addition between two vec2int16_t vectors.
 *
 * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
 * @param other A pointer to the source vec2int16_t vector to be added.
 */
void vec2i16_add(vec2int16_t *out, vec2int16_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2int16_t vector.
 *
 * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 */
void vec2i16_addS(vec2int16_t *out, int16_t scalar);

/**
 * @brief Performs element-wise addition between two vec2int16_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
 * @param other A pointer to the source vec2int16_t vector to be added.
 *
 * @return A pointer to a newly allocated vec2int16_t vector containing the result of the addition.
 */
vec2int16_t *vec2i16_add_r(vec2int16_t *out, vec2int16_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2int16_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 *
 * @return A pointer to a newly allocated vec2int16_t vector containing the result of the addition.
 */
vec2int16_t *vec2i16_addS_r(vec2int16_t *out, int16_t scalar);

/**
 * @brief Performs element-wise addition between two vec2uint16_t vectors.
 *
 * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint16_t vector to be added.
 */
void vec2u16_add(vec2uint16_t *out, vec2uint16_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2uint16_t vector.
 *
 * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 */
void vec2u16_addS(vec2int16_t *out, uint16_t scalar);

/**
 * @brief Performs element-wise addition between two vec2uint16_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint16_t vector to be added.
 *
 * @return A pointer to a newly allocated vec2uint16_t vector containing the result of the addition.
 */
vec2uint16_t *vec2u16_add_r(vec2uint16_t *out, vec2uint16_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2uint16_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 *
 * @return A pointer to a newly allocated vec2uint16_t vector containing the result of the addition.
 */
vec2uint16_t *vec2u16_addS_r(vec2uint16_t *out, uint16_t scalar);


/**
 * @brief Performs element-wise addition between two vec2int32_t vectors.
 *
 * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
 * @param other A pointer to the source vec2int32_t vector to be added.
 */
void vec2i32_add(vec2int32_t *out, vec2int32_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2int32_t vector.
 *
 * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 */
void vec2i32_addS(vec2int32_t *out, int32_t scalar);

/**
 * @brief Performs element-wise addition between two vec2int32_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
 * @param other A pointer to the source vec2int32_t vector to be added.
 *
 * @return A pointer to a newly allocated vec2int32_t vector containing the result of the addition.
 */
vec2int32_t *vec2i32_add_r(vec2int32_t *out, vec2int32_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2int32_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 *
 * @return A pointer to a newly allocated vec2int32_t vector containing the result of the addition.
 */
vec2int32_t *vec2i32_addS_r(vec2int32_t *out, int32_t scalar);

/**
 * @brief Performs element-wise addition between two vec2uint32_t vectors.
 *
 * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint32_t vector to be added.
 */
void vec2u32_add(vec2uint32_t *out, vec2uint32_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2uint32_t vector.
 *
 * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 */
void vec2u32_addS(vec2int32_t *out, uint32_t scalar);

/**
 * @brief Performs element-wise addition between two vec2uint32_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint32_t vector to be added.
 *
 * @return A pointer to a newly allocated vec2uint32_t vector containing the result of the addition.
 */
vec2uint32_t *vec2u32_add_r(vec2uint32_t *out, vec2uint32_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2uint32_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 *
 * @return A pointer to a newly allocated vec2uint32_t vector containing the result of the addition.
 */
vec2uint32_t *vec2u32_addS_r(vec2uint32_t *out, uint32_t scalar);


/**
 * @brief Performs element-wise addition between two vec2int64_t vectors.
 *
 * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
 * @param other A pointer to the source vec2int64_t vector to be added.
 */
void vec2i64_add(vec2int64_t *out, vec2int64_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2int64_t vector.
 *
 * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 */
void vec2i64_addS(vec2int64_t *out, int64_t scalar);

/**
 * @brief Performs element-wise addition between two vec2int64_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
 * @param other A pointer to the source vec2int64_t vector to be added.
 *
 * @return A pointer to a newly allocated vec2int64_t vector containing the result of the addition.
 */
vec2int64_t *vec2i64_add_r(vec2int64_t *out, vec2int64_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2int64_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 *
 * @return A pointer to a newly allocated vec2int64_t vector containing the result of the addition.
 */
vec2int64_t *vec2i64_addS_r(vec2int64_t *out, int64_t scalar);

/**
 * @brief Performs element-wise addition between two vec2uint64_t vectors.
 *
 * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint64_t vector to be added.
 */
void vec2u64_add(vec2uint64_t *out, vec2uint64_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2uint64_t vector.
 *
 * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 */
void vec2u64_addS(vec2int64_t *out, uint64_t scalar);

/**
 * @brief Performs element-wise addition between two vec2uint64_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint64_t vector to be added.
 *
 * @return A pointer to a newly allocated vec2uint64_t vector containing the result of the addition.
 */
vec2uint64_t *vec2u64_add_r(vec2uint64_t *out, vec2uint64_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2uint64_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 *
 * @return A pointer to a newly allocated vec2uint64_t vector containing the result of the addition.
 */
vec2uint64_t *vec2u64_addS_r(vec2uint64_t *out, uint64_t scalar);


/**
 * @brief Performs element-wise addition between two vec2f_t vectors.
 *
 * @param out A pointer to the destination vec2f_t vector where the result will be stored.
 * @param other A pointer to the source vec2f_t vector to be added.
 */
void vec2f_add(vec2f_t *out, vec2f_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2f_t vector.
 *
 * @param out A pointer to the destination vec2f_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 */
void vec2f_addS(vec2f_t *out, float scalar);

/**
 * @brief Performs element-wise addition between two vec2f_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2f_t vector where the result will be stored.
 * @param other A pointer to the source vec2f_t vector to be added.
 *
 * @return A pointer to a newly allocated vec2f_t vector containing the result of the addition.
 */
vec2f_t *vec2f_add_r(vec2f_t *out, vec2f_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2f_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2f_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 *
 * @return A pointer to a newly allocated vec2f_t vector containing the result of the addition.
 */
vec2f_t *vec2f_addS_r(vec2f_t *out, float scalar);

/**
 * @brief Performs element-wise addition between two vec2d_t vectors.
 *
 * @param out A pointer to the destination vec2d_t vector where the result will be stored.
 * @param other A pointer to the source vec2d_t vector to be added.
 */
void vec2d_add(vec2d_t *out, vec2d_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2d_t vector.
 *
 * @param out A pointer to the destination vec2d_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 */
void vec2d_addS(vec2d_t *out, double scalar);

/**
 * @brief Performs element-wise addition between two vec2d_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2d_t vector where the result will be stored.
 * @param other A pointer to the source vec2d_t vector to be added.
 *
 * @return A pointer to a newly allocated vec2d_t vector containing the result of the addition.
 */
vec2d_t *vec2d_add_r(vec2d_t *out, vec2d_t *other);

/**
 * @brief Performs scalar addition to each element of a vec2d_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2d_t vector where the result will be stored.
 * @param scalar The scalar value to be added to each element of the vector.
 *
 * @return A pointer to a newly allocated vec2d_t vector containing the result of the addition.
 */
vec2d_t *vec2d_addS_r(vec2d_t *out, double scalar);


/**
 * @brief Performs element-wise subtraction between two vec2int8_t vectors.
 *
 * @param out A pointer to the destination vec2int8_t vector where the result will be stored.
 * @param other A pointer to the source vec2int8_t vector to be subtracted.
 */
void vec2i8_sub(vec2int8_t *out, vec2int8_t *other);

/**
 * @brief Subtracts a scalar value from each element of a vec2int8_t vector.
 *
 * @param out A pointer to the destination vec2int8_t vector where the result will be stored.
 * @param scalar The scalar value to be subtracted from each element of the vector.
 */
void vec2i8_subS(vec2int8_t *out, int8_t scalar);

/**
 * @brief Performs element-wise subtraction between two vec2int8_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2int8_t vector where the result will be stored.
 * @param other A pointer to the source vec2int8_t vector to be subtracted.
 *
 * @return A pointer to a newly allocated vec2int8_t vector containing the result of the subtraction.
 */
vec2int8_t *vec2i8_sub_r(vec2int8_t *out, vec2int8_t *other);

/**
 * @brief Subtracts a scalar value from each element of a vec2int8_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2int8_t vector where the result will be stored.
 * @param scalar The scalar value to be subtracted from each element of the vector.
 *
 * @return A pointer to a newly allocated vec2int8_t vector containing the result of the subtraction.
 */
vec2int8_t *vec2i8_subS_r(vec2int8_t *out, int8_t scalar);

/**
 * @brief Performs element-wise subtraction between two vec2uint8_t vectors.
 *
 * @param out A pointer to the destination vec2uint8_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint8_t vector to be subtracted.
 */
void vec2u8_sub(vec2uint8_t *out, vec2uint8_t *other);

/**
 * @brief Subtracts a scalar value from each element of a vec2uint8_t vector.
 *
 * @param out A pointer to the destination vec2uint8_t vector where the result will be stored.
 * @param scalar The scalar value to be subtracted from each element of the vector.
 */
void vec2u8_subS(vec2uint8_t *out, uint8_t scalar);

/**
 * @brief Performs element-wise subtraction between two vec2uint8_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint8_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint8_t vector to be subtracted.
 *
 * @return A pointer to a newly allocated vec2uint8_t vector containing the result of the subtraction.
 */
vec2uint8_t *vec2u8_sub_r(vec2uint8_t *out, vec2uint8_t *other);

/**
 * @brief Subtracts a scalar value from each element of a vec2uint8_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint8_t vector where the result will be stored.
 * @param scalar The scalar value to be subtracted from each element of the vector.
 *
 * @return A pointer to a newly allocated vec2uint8_t vector containing the result of the subtraction.
 */
vec2uint8_t *vec2u8_subS_r(vec2uint8_t *out, uint8_t scalar);

/**
 * @brief Performs element-wise subtraction between two vec2int16_t vectors.
 *
 * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
 * @param other A pointer to the source vec2int16_t vector to be subtracted.
 */
void vec2i16_sub(vec2int16_t *out, vec2int16_t *other);

/**
 * @brief Subtracts a scalar value from each element of a vec2int16_t vector.
 *
 * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
 * @param scalar The scalar value to be subtracted from each element of the vector.
 */
void vec2i16_subS(vec2int16_t *out, int16_t scalar);

/**
 * @brief Performs element-wise subtraction between two vec2int16_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
 * @param other A pointer to the source vec2int16_t vector to be subtracted.
 *
 * @return A pointer to a newly allocated vec2int16_t vector containing the result of the subtraction.
 */
vec2int16_t *vec2i16_sub_r(vec2int16_t *out, vec2int16_t *other);

/**
 * @brief Subtracts a scalar value from each element of a vec2int16_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
 * @param scalar The scalar value to be subtracted from each element of the vector.
 *
 * @return A pointer to a newly allocated vec2int16_t vector containing the result of the subtraction.
 */
vec2int16_t *vec2i16_subS_r(vec2int16_t *out, int16_t scalar);

/**
 * @brief Performs element-wise subtraction between two vec2uint16_t vectors.
 *
 * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint16_t vector to be subtracted.
 */
void vec2u16_sub(vec2uint16_t *out, vec2uint16_t *other);

/**
 * @brief Subtracts a scalar value from each element of a vec2uint16_t vector.
 *
 * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
 * @param scalar The scalar value to be subtracted from each element of the vector.
 */
void vec2u16_subS(vec2uint16_t *out, uint16_t scalar);

/**
 * @brief Performs element-wise subtraction between two vec2uint16_t vectors and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
 * @param other A pointer to the source vec2uint16_t vector to be subtracted.
 *
 * @return A pointer to a newly allocated vec2uint16_t vector containing the result of the subtraction.
 */
vec2uint16_t *vec2u16_sub_r(vec2uint16_t *out, vec2uint16_t *other);

/**
 * @brief Subtracts a scalar value from each element of a vec2uint16_t vector and returns a new vector.
 *
 * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
 * @param scalar The scalar value to be subtracted from each element of the vector.
 *
 * @return A pointer to a newly allocated vec2uint16_t vector containing the result of the subtraction.
 */
 /**
  * @brief Performs element-wise subtraction between two vec2uint16_t vectors.
  *
  * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint16_t vector to be subtracted.
  *
  * @return A pointer to a newly allocated vec2uint16_t vector containing the result of the subtraction.
  */
 vec2uint16_t *vec2u16_sub_r(vec2uint16_t *out, vec2uint16_t *other);

 /**
  * @brief Subtracts a scalar value from each element of a vec2int32_t vector.
  *
  * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
  * @param other A pointer to the source vec2int32_t vector to be subtracted.
  */
 void vec2i32_sub(vec2int32_t *out, vec2int32_t *other);

 /**
  * @brief Subtracts a scalar value from each element of a vec2int32_t vector.
  *
  * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  */
 void vec2i32_subS(vec2int32_t *out, int32_t scalar);

 /**
  * @brief Performs element-wise subtraction between two vec2int32_t vectors and returns a new vector.
  *
  * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
  * @param other A pointer to the source vec2int32_t vector to be subtracted.
  *
  * @return A pointer to a newly allocated vec2int32_t vector containing the result of the subtraction.
  */
 vec2int32_t *vec2i32_sub_r(vec2int32_t *out, vec2int32_t *other);

 /**
  * @brief Subtracts a scalar value from each element of a vec2int32_t vector and returns a new vector.
  *
  * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  *
  * @return A pointer to a newly allocated vec2int32_t vector containing the result of the subtraction.
  */
 vec2int32_t *vec2i32_subS_r(vec2int32_t *out, int32_t scalar);

 /**
  * @brief Performs element-wise subtraction between two vec2uint32_t vectors.
  *
  * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint32_t vector to be subtracted.
  *
  * @return A pointer to a newly allocated vec2uint32_t vector containing the result of the subtraction.
  */
 vec2uint32_t *vec2u32_sub_r(vec2uint32_t *out, vec2uint32_t *other);

 /**
  * @brief Subtracts a scalar value from each element of a vec2int32_t vector.
  *
  * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  */
 void vec2u32_subS(vec2int32_t *out, uint32_t scalar);

 /**
  * @brief Subtracts a scalar value from each element of a vec2uint32_t vector.
  *
  * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  */
 void vec2u32_subS(vec2int32_t *out, uint32_t scalar);

 /**
  * @brief Performs element-wise subtraction between two vec2uint32_t vectors and returns a new vector.
  *
  * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint32_t vector to be subtracted.
  *
  * @return A pointer to a newly allocated vec2uint32_t vector containing the result of the subtraction.
  */
 vec2uint32_t *vec2u32_sub_r(vec2uint32_t *out, vec2uint32_t *other);

 /**
  * @brief Subtracts a scalar value from each element of a vec2uint32_t vector and returns a new vector.
  *
  * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  *
  * @return A pointer to a newly allocated vec2uint32_t vector containing the result of the subtraction.
  */
 vec2uint32_t *vec2u32_subS_r(vec2uint32_t *out, uint32_t scalar);

 /**
  * @brief Subtracts a scalar value from each element of a vec2int64_t vector.
  *
  * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  */
 void vec2i64_subS(vec2int64_t *out, int64_t scalar);

 /**
  * @brief Subtracts a scalar value from each element of a vec2int64_t vector and returns a new vector.
  *
  * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  *
  * @return A pointer to a newly allocated vec2int64_t vector containing the result of the subtraction.
  */
 vec2int64_t *vec2i64_subS_r(vec2int64_t *out, int64_t scalar);

 /**
  * @brief Performs element-wise subtraction between two vec2uint64_t vectors.
  *
  * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint64_t vector to be subtracted.
  *
  * @return A pointer to a newly allocated vec2uint64_t vector containing the result of the subtraction.
  */
 vec2uint64_t *vec2u64_sub_r(vec2uint64_t *out, vec2uint64_t *other);

 /**
  * @brief Subtracts a scalar value from each element of a vec2int64_t vector.
  *
  * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  */
 void vec2u64_subS(vec2int64_t *out, uint64_t scalar);

 /**
  * @brief Subtracts a scalar value from each element of a vec2uint64_t vector.
  *
  * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  */
 void vec2u64_subS(vec2int64_t *out, uint64_t scalar);

 /**
  * @brief Performs element-wise subtraction between two vec2uint64_t vectors and returns a new vector.
  *
  * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint64_t vector to be subtracted.
  *
  * @return A pointer to a newly allocated vec2uint64_t vector containing the result of the subtraction.
  */
 vec2uint64_t *vec2u64_sub_r(vec2uint64_t *out, vec2uint64_t *other);

 /**
  * @brief Performs element-wise subtraction between two vec2f_t vectors.
  *
  * @param out A pointer to the destination vec2f_t vector where the result will be stored.
  * @param other A pointer to the source vec2f_t vector to be subtracted.
  */
 void vec2f_sub(vec2f_t *out, vec2f_t *other);

 /**
  * @brief Subtracts a scalar value from each element of a vec2f_t vector.
  *
  * @param out A pointer to the destination vec2f_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  */
 void vec2f_subS(vec2f_t *out, float scalar);

 /**
  * @brief Performs element-wise subtraction between two vec2f_t vectors and returns a new vector.
  *
  * @param out A pointer to the destination vec2f_t vector where the result will be stored.
  * @param other A pointer to the source vec2f_t vector to be subtracted.
  *
  * @return A pointer to a newly allocated vec2f_t vector containing the result of the subtraction.
  */
 vec2f_t *vec2f_sub_r(vec2f_t *out, vec2f_t *other);

 /**
  * @brief Subtracts a scalar value from each element of a vec2f_t vector and returns a new vector.
  *
  * @param out A pointer to the destination vec2f_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  *
  * @return A pointer to a newly allocated vec2f_t vector containing the result of the subtraction.
  */
 vec2f_t *vec2f_subS_r(vec2f_t *out, float scalar);

 /**
  * @brief Performs element-wise subtraction between two vec2d_t vectors.
  *
  * @param out A pointer to the destination vec2d_t vector where the result will be stored.
  * @param other A pointer to the source vec2d_t vector to be subtracted.
  */
 void vec2d_sub(vec2d_t *out, vec2d_t *other);

 /**
  * @brief Subtracts a scalar value from each element of a vec2d_t vector.
  *
  * @param out A pointer to the destination vec2d_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  */
 void vec2d_subS(vec2d_t *out, double scalar);

 /**
  * @brief Performs element-wise subtraction between two vec2d_t vectors and returns a new vector.
  *
  * @param out A pointer to the destination vec2d_t vector where the result will be stored.
  * @param other A pointer to the source vec2d_t vector to be subtracted.
  *
  * @return A pointer to a newly allocated vec2d_t vector containing the result of the subtraction.
  */
 vec2d_t *vec2d_sub_r(vec2d_t *out, vec2d_t *other);

 /**
  * @brief Subtracts a scalar value from each element of a vec2d_t vector and returns a new vector.
  *
  * @param out A pointer to the destination vec2d_t vector where the result will be stored.
  * @param scalar The scalar value to be subtracted from each element of the vector.
  *
  * @return A pointer to a newly allocated vec2d_t vector containing the result of the subtraction.
  */
 vec2d_t *vec2d_subS_r(vec2d_t *out, double scalar);



 /**
  * @brief Performs element-wise multiplication between two vec2int16_t vectors.
  *
  * This function multiplies each element of the 'out' vector by the corresponding
  * element of the 'other' vector and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
  * @param other A pointer to the source vec2int16_t vector to be multiplied with 'out'.
  */
 void vec2i16_mult(vec2int16_t *out, vec2int16_t *other);

 /**
  * @brief Multiplies each element of a vec2int16_t vector by a scalar value.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar'
  * value and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  */
 void vec2i16_multS(vec2int16_t *out, int16_t scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2int16_t vectors and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the corresponding element
  * of the 'other' vector and stores the result in a newly allocated vec2int16_t vector.
  *
  * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
  * @param other A pointer to the source vec2int16_t vector to be multiplied with 'out'.
  *
  * @return A pointer to a newly allocated vec2int16_t vector containing the result of the multiplication.
  */
 vec2int16_t *vec2i16_mult_r(vec2int16_t *out, vec2int16_t *other);

 /**
  * @brief Multiplies each element of a vec2int16_t vector by a scalar value and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar' value
  * and stores the result in a newly allocated vec2int16_t vector.
  *
  * @param out A pointer to the destination vec2int16_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  *
  * @return A pointer to a newly allocated vec2int16_t vector containing the result of the multiplication.
  */
 vec2int16_t *vec2i16_multS_r(vec2int16_t *out, int16_t scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2uint16_t vectors.
  *
  * This function multiplies each element of the 'out' vector by the corresponding
  * element of the 'other' vector and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint16_t vector to be multiplied with 'out'.
  */
 void vec2u16_mult(vec2uint16_t *out, vec2uint16_t *other);

 /**
  * @brief Multiplies each element of a vec2uint16_t vector by a scalar value.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar'
  * value and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  */
 void vec2u16_multS(vec2uint16_t *out, uint16_t scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2uint16_t vectors and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the corresponding element
  * of the 'other' vector and stores the result in a newly allocated vec2uint16_t vector.
  *
  * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint16_t vector to be multiplied with 'out'.
  *
  * @return A pointer to a newly allocated vec2uint16_t vector containing the result of the multiplication.
  */
 vec2uint16_t *vec2u16_mult_r(vec2uint16_t *out, vec2uint16_t *other);

 /**
  * @brief Multiplies each element of a vec2uint16_t vector by a scalar value and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar' value
  * and stores the result in a newly allocated vec2uint16_t vector.
  *
  * @param out A pointer to the destination vec2uint16_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  *
  * @return A pointer to a newly allocated vec2uint16_t vector containing the result of the multiplication.
  */
 vec2uint16_t *vec2u16_multS_r(vec2uint16_t *out, uint16_t scalar);


 /**
  * @brief Performs element-wise multiplication between two vec2int32_t vectors.
  *
  * This function multiplies each element of the 'out' vector by the corresponding
  * element of the 'other' vector and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
  * @param other A pointer to the source vec2int32_t vector to be multiplied with 'out'.
  */
 void vec2i32_mult(vec2int32_t *out, vec2int32_t *other);

 /**
  * @brief Multiplies each element of a vec2int32_t vector by a scalar value.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar'
  * value and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  */
 void vec2i32_multS(vec2int32_t *out, int32_t scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2int32_t vectors and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the corresponding element
  * of the 'other' vector and stores the result in a newly allocated vec2int32_t vector.
  *
  * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
  * @param other A pointer to the source vec2int32_t vector to be multiplied with 'out'.
  *
  * @return A pointer to a newly allocated vec2int32_t vector containing the result of the multiplication.
  */
 vec2int32_t *vec2i32_mult_r(vec2int32_t *out, vec2int32_t *other);

 /**
  * @brief Multiplies each element of a vec2int32_t vector by a scalar value and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar' value
  * and stores the result in a newly allocated vec2int32_t vector.
  *
  * @param out A pointer to the destination vec2int32_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  *
  * @return A pointer to a newly allocated vec2int32_t vector containing the result of the multiplication.
  */
 vec2int32_t *vec2i32_multS_r(vec2int32_t *out, int32_t scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2uint32_t vectors.
  *
  * This function multiplies each element of the 'out' vector by the corresponding
  * element of the 'other' vector and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint32_t vector to be multiplied with 'out'.
  */
 void vec2u32_mult(vec2uint32_t *out, vec2uint32_t *other);

 /**
  * @brief Multiplies each element of a vec2uint32_t vector by a scalar value.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar'
  * value and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  */
 void vec2u32_multS(vec2uint32_t *out, uint32_t scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2uint32_t vectors and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the corresponding element
  * of the 'other' vector and stores the result in a newly allocated vec2uint32_t vector.
  *
  * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint32_t vector to be multiplied with 'out'.
  *
  * @return A pointer to a newly allocated vec2uint32_t vector containing the result of the multiplication.
  */
 vec2uint32_t *vec2u32_mult_r(vec2uint32_t *out, vec2uint32_t *other);

 /**
  * @brief Multiplies each element of a vec2uint32_t vector by a scalar value and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar' value
  * and stores the result in a newly allocated vec2uint32_t vector.
  *
  * @param out A pointer to the destination vec2uint32_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  *
  * @return A pointer to a newly allocated vec2uint32_t vector containing the result of the multiplication.
  */
 vec2uint32_t *vec2u32_multS_r(vec2uint32_t *out, uint32_t scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2int64_t vectors.
  *
  * This function multiplies each element of the 'out' vector by the corresponding
  * element of the 'other' vector and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
  * @param other A pointer to the source vec2int64_t vector to be multiplied with 'out'.
  */
 void vec2i64_mult(vec2int64_t *out, vec2int64_t *other);

 /**
  * @brief Multiplies each element of a vec2int64_t vector by a scalar value.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar'
  * value and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  */
 void vec2i64_multS(vec2int64_t *out, int64_t scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2int64_t vectors and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the corresponding element
  * of the 'other' vector and stores the result in a newly allocated vec2int64_t vector.
  *
  * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
  * @param other A pointer to the source vec2int64_t vector to be multiplied with 'out'.
  *
  * @return A pointer to a newly allocated vec2int64_t vector containing the result of the multiplication.
  */
 vec2int64_t *vec2i64_mult_r(vec2int64_t *out, vec2int64_t *other);

 /**
  * @brief Multiplies each element of a vec2int64_t vector by a scalar value and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar' value
  * and stores the result in a newly allocated vec2int64_t vector.
  *
  * @param out A pointer to the destination vec2int64_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  *
  * @return A pointer to a newly allocated vec2int64_t vector containing the result of the multiplication.
  */
 vec2int64_t *vec2i64_multS_r(vec2int64_t *out, int64_t scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2uint64_t vectors.
  *
  * This function multiplies each element of the 'out' vector by the corresponding
  * element of the 'other' vector and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint64_t vector to be multiplied with 'out'.
  */
 void vec2u64_mult(vec2uint64_t *out, vec2uint64_t *other);

 /**
  * @brief Multiplies each element of a vec2uint64_t vector by a scalar value.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar'
  * value and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  */
 void vec2u64_multS(vec2uint64_t *out, uint64_t scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2uint64_t vectors and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the corresponding element
  * of the 'other' vector and stores the result in a newly allocated vec2uint64_t vector.
  *
  * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
  * @param other A pointer to the source vec2uint64_t vector to be multiplied with 'out'.
  *
  * @return A pointer to a newly allocated vec2uint64_t vector containing the result of the multiplication.
  */
 vec2uint64_t *vec2u64_mult_r(vec2uint64_t *out, vec2uint64_t *other);

 /**
  * @brief Multiplies each element of a vec2uint64_t vector by a scalar value and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar' value
  * and stores the result in a newly allocated vec2uint64_t vector.
  *
  * @param out A pointer to the destination vec2uint64_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  *
  * @return A pointer to a newly allocated vec2uint64_t vector containing the result of the multiplication.
  */
 vec2uint64_t *vec2u64_multS_r(vec2uint64_t *out, uint64_t scalar);


 /**
  * @brief Performs element-wise multiplication between two vec2f_t vectors.
  *
  * This function multiplies each element of the 'out' vector by the corresponding
  * element of the 'other' vector and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2f_t vector where the result will be stored.
  * @param other A pointer to the source vec2f_t vector to be multiplied with 'out'.
  */
 void vec2f_mult(vec2f_t *out, vec2f_t *other);

 /**
  * @brief Multiplies each element of a vec2f_t vector by a scalar value.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar'
  * value and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2f_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  */
 void vec2f_multS(vec2f_t *out, float scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2f_t vectors and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the corresponding element
  * of the 'other' vector and stores the result in a newly allocated vec2f_t vector.
  *
  * @param out A pointer to the destination vec2f_t vector where the result will be stored.
  * @param other A pointer to the source vec2f_t vector to be multiplied with 'out'.
  *
  * @return A pointer to a newly allocated vec2f_t vector containing the result of the multiplication.
  */
 vec2f_t *vec2f_mult_r(vec2f_t *out, vec2f_t *other);

 /**
  * @brief Multiplies each element of a vec2f_t vector by a scalar value and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar' value
  * and stores the result in a newly allocated vec2f_t vector.
  *
  * @param out A pointer to the destination vec2f_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  *
  * @return A pointer to a newly allocated vec2f_t vector containing the result of the multiplication.
  */
 vec2f_t *vec2f_multS_r(vec2f_t *out, float scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2d_t vectors.
  *
  * This function multiplies each element of the 'out' vector by the corresponding
  * element of the 'other' vector and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2d_t vector where the result will be stored.
  * @param other A pointer to the source vec2d_t vector to be multiplied with 'out'.
  */
 void vec2d_mult(vec2d_t *out, vec2d_t *other);

 /**
  * @brief Multiplies each element of a vec2d_t vector by a scalar value.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar'
  * value and stores the result in the 'out' vector.
  *
  * @param out A pointer to the destination vec2d_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  */
 void vec2d_multS(vec2d_t *out, double scalar);

 /**
  * @brief Performs element-wise multiplication between two vec2d_t vectors and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the corresponding element
  * of the 'other' vector and stores the result in a newly allocated vec2d_t vector.
  *
  * @param out A pointer to the destination vec2d_t vector where the result will be stored.
  * @param other A pointer to the source vec2d_t vector to be multiplied with 'out'.
  *
  * @return A pointer to a newly allocated vec2d_t vector containing the result of the multiplication.
  */
 vec2d_t *vec2d_mult_r(vec2d_t *out, vec2d_t *other);

 /**
  * @brief Multiplies each element of a vec2d_t vector by a scalar value and returns a new vector.
  *
  * This function multiplies each element of the 'out' vector by the provided 'scalar' value
  * and stores the result in a newly allocated vec2d_t vector.
  *
  * @param out A pointer to the destination vec2d_t vector where the result will be stored.
  * @param scalar The scalar value to multiply each element of the 'out' vector by.
  *
  * @return A pointer to a newly allocated vec2d_t vector containing the result of the multiplication.
  */
 vec2d_t *vec2d_multS_r(vec2d_t *out, double scalar);


//Divison (TO BE IMPLEMENTED)

// Printing a 2D vector of int8_t.
void printVec2i8(vec2int8_t *vec);

// Printing a 2D vector of uint8_t.
void printVec2u8(vec2uint8_t *vec);

// Printing a 2D vector of int16_t.
void printVec2i16(vec2int16_t *vec);

// Printing a 2D vector of uint16_t.
void printVec2u16(vec2uint16_t *vec);

// Printing a 2D vector of int32_t.
void printVec2i32(vec2int32_t *vec);

// Printing a 2D vector of uint32_t.
void printVec2u32(vec2uint32_t *vec);

// Printing a 2D vector of int64_t.
void printVec2i64(vec2int64_t *vec);

// Printing a 2D vector of uint64_t.
void printVec2u64(vec2uint64_t *vec);

// Printing a 2D vector of char.
void printVec2c(vec2char_t *vec);

// Printing a 2D vector of float.
void printVec2f(vec2f_t *vec);

// Printing a 2D vector of double.
void printVec2d(vec2d_t *vec);




#endif //VEC2_H_
