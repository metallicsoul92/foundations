#ifndef FOUNDATIONS_MATH_VEC4_H
#define FOUNDATIONS_MATH_VEC4_H

// Include necessary standard headers and forward declarations.

// Standard header for fixed-size integer types
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
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



#ifndef VEC4_DEFINED
  // Check if the 4D vector types haven't been defined yet.

  #ifndef VEC4I8_DEFINED
  // Check if the 4D vector of int8_t hasn't been defined.
  typedef struct vector4int8 vec4int8_t;
  #define VEC4I8_DEFINED 1
  #endif

  #ifndef VEC4U8_DEFINED
  // Check if the 4D vector of uint8_t hasn't been defined.
  typedef struct vector4uint8 vec4uint8_t;
  #define VEC4U8_DEFINED 1
  #endif

  #ifndef VEC4I16_DEFINED
  // Check if the 4D vector of int16_t hasn't been defined.
  typedef struct vector4int16 vec4int16_t;
  #define VEC4I16_DEFINED 1
  #endif

  #ifndef VEC4U16_DEFINED
  // Check if the 4D vector of uint16_t hasn't been defined.
  typedef struct vector4uint16 vec4uint16_t;
  #define VEC4U16_DEFINED 1
  #endif

  #ifndef VEC4I32_DEFINED
  // Check if the 4D vector of int32_t hasn't been defined.
  typedef struct vector4int32 vec4int32_t;
  #define VEC4I32_DEFINED 1
  #endif

  #ifndef VEC4U32_DEFINED
  // Check if the 4D vector of uint32_t hasn't been defined.
  typedef struct vector4uint32 vec4uint32_t;
  #define VEC4U32_DEFINED 1
  #endif

  #ifndef VEC4I64_DEFINED
  // Check if the 4D vector of int64_t hasn't been defined.
  typedef struct vector4int64 vec4int64_t;
  #define VEC4I64_DEFINED 1
  #endif

  #ifndef VEC4U64_DEFINED
  // Check if the 4D vector of uint64_t hasn't been defined.
  typedef struct vector4uint64 vec4uint64_t;
  #define VEC4U64_DEFINED 1
  #endif

  #ifndef VEC4C_DEFINED
  // Check if the 4D vector of char hasn't been defined.
  typedef struct vector4char vec4char_t;
  #define VEC4C_DEFINED 1
  #endif

  #ifndef VEC4F_DEFINED
  // Check if the 4D vector of float hasn't been defined.
  typedef struct vector4float vec4f_t;
  #define VEC4F_DEFINED 1
  #endif

  #ifndef VEC4D_DEFINED
  // Check if the 4D vector of double hasn't been defined.
  typedef struct vector4double vec4d_t;
  #define VEC4D_DEFINED 1
  #endif

  #define VEC4_DEFINED 1
  // Now that all the 4D vector types are defined, mark the 4D vector as defined.
#endif





/**
 * Initializes a 4D int8 vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4I8(vec4int8_t * out, int8_t x, int8_t y, int8_t z, int8_t w);

/**
 * Initializes a 4D uint8 vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4U8(vec4uint8_t * out, uint8_t x, uint8_t y, uint8_t z, uint8_t w);

/**
 * Initializes a 4D int16 vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4I16(vec4int16_t * out, int16_t x, int16_t y, int16_t z, int16_t w);

/**
 * Initializes a 4D uint16 vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4U16(vec4uint16_t * out, uint16_t x, uint16_t y, uint16_t z, uint16_t w);

/**
 * Initializes a 4D int32 vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4I32(vec4int32_t * out, int32_t x, int32_t y, int32_t z, int32_t w);

/**
 * Initializes a 4D uint32 vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4U32(vec4uint32_t * out, uint32_t x, uint32_t y, uint32_t z, uint32_t w);

/**
 * Initializes a 4D int64 vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4I64(vec4int64_t * out, int64_t x, int64_t y, int64_t z, int64_t w);

/**
 * Initializes a 4D uint64 vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4U64(vec4uint64_t * out, uint64_t x, uint64_t y, uint64_t z, uint64_t w);

/**
 * Initializes a 4D char vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4C(vec4char_t * out, char x, char y, char z, char w);

/**
 * Initializes a 4D float vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4F(vec4f_t * out, float x, float y, float z, float w);

/**
 * Initializes a 4D double vector 'out' with the provided values.
 *
 * @param out - The vector to be initialized.
 * @param x   - The value for the x component.
 * @param y   - The value for the y component.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4D(vec4d_t * out, double x, double y, double z, double w);


/**
 * Initializes a 4D int8 vector 'out' with values from a 2D int8 vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4I8_fromVec2(vec4int8_t * out, vec2int8_t * xy, int8_t z, int8_t w);

/**
 * Initializes a 4D uint8 vector 'out' with values from a 2D uint8 vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4U8_fromVec2(vec4uint8_t * out, vec2uint8_t * xy, uint8_t z, uint8_t w);

/**
 * Initializes a 4D int16 vector 'out' with values from a 2D int16 vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4I16_fromVec2(vec4int16_t * out, vec2int16_t * xy, int16_t z, int16_t w);

/**
 * Initializes a 4D uint16 vector 'out' with values from a 2D uint16 vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4U16_fromVec2(vec4uint16_t * out, vec2uint16_t * xy, uint16_t z, uint16_t w);

/**
 * Initializes a 4D int32 vector 'out' with values from a 2D int32 vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4I32_fromVec2(vec4int32_t * out, vec2int32_t * xy, int32_t z, int32_t w);

/**
 * Initializes a 4D uint32 vector 'out' with values from a 2D uint32 vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4U32_fromVec2(vec4uint32_t * out, vec2uint32_t * xy, uint32_t z, uint32_t w);

/**
 * Initializes a 4D int64 vector 'out' with values from a 2D int64 vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4I64_fromVec2(vec4int64_t * out, vec2int64_t * xy, int64_t z, int64_t w);

/**
 * Initializes a 4D uint64 vector 'out' with values from a 2D uint64 vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4U64_fromVec2(vec4uint64_t * out, vec2uint64_t * xy, uint64_t z, uint64_t w);

/**
 * Initializes a 4D char vector 'out' with values from a 2D char vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4C_fromVec2(vec4char_t * out, vec2char_t * xy, char z, char w);

/**
 * Initializes a 4D float vector 'out' with values from a 2D float vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4F_fromVec2(vec4f_t * out, vec2f_t * xy, float z, float w);

/**
 * Initializes a 4D double vector 'out' with values from a 2D double vector 'xy',
 * and additional values 'z' and 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The 2D vector containing x and y values.
 * @param z   - The value for the z component.
 * @param w   - The value for the w component.
 */
void initvec4D_fromVec2(vec4d_t * out, vec2d_t * xy, double z, double w);


/**
 * Initializes a 4D int8 vector 'out' with values from two 2D int8 vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4I8_from2Vec2(vec4int8_t * out, vec2int8_t * xy, vec2int8_t * zw);

/**
 * Initializes a 4D uint8 vector 'out' with values from two 2D uint8 vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4U8_from2Vec2(vec4uint8_t * out, vec2uint8_t * xy, vec2uint8_t * zw);

/**
 * Initializes a 4D int16 vector 'out' with values from two 2D int16 vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4I16_from2Vec2(vec4int16_t * out, vec2int16_t * xy, vec2int16_t * zw);

/**
 * Initializes a 4D uint16 vector 'out' with values from two 2D uint16 vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4U16_from2Vec2(vec4uint16_t * out, vec2uint16_t * xy, vec2uint16_t * zw);

/**
 * Initializes a 4D int32 vector 'out' with values from two 2D int32 vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4I32_from2Vec2(vec4int32_t * out, vec2int32_t * xy, vec2int32_t * zw);

/**
 * Initializes a 4D uint32 vector 'out' with values from two 2D uint32 vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4U32_from2Vec2(vec4uint32_t * out, vec2uint32_t * xy, vec2uint32_t * zw);

/**
 * Initializes a 4D int64 vector 'out' with values from two 2D int64 vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4I64_from2Vec2(vec4int64_t * out, vec2int64_t * xy, vec2int64_t * zw);

/**
 * Initializes a 4D uint64 vector 'out' with values from two 2D uint64 vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4U64_from2Vec2(vec4uint64_t * out, vec2uint64_t * xy, vec2uint64_t * zw);

/**
 * Initializes a 4D char vector 'out' with values from two 2D char vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4C_from2Vec2(vec4char_t * out, vec2char_t * xy, vec2char_t * zw);

/**
 * Initializes a 4D float vector 'out' with values from two 2D float vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4F_from2Vec2(vec4f_t * out, vec2f_t * xy, vec2f_t * zw);

/**
 * Initializes a 4D double vector 'out' with values from two 2D double vectors 'xy' and 'zw'.
 *
 * @param out - The vector to be initialized.
 * @param xy  - The first 2D vector representing x and y values.
 * @param zw  - The second 2D vector representing z and w values.
 */
void initvec4D_from2Vec2(vec4d_t * out, vec2d_t * xy, vec2d_t * zw);


/**
 * Initializes a 4D int8 vector 'out' with values from a 3D int8 vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4I8_fromVec3(vec4int8_t * out, vec3int8_t * xyz, int8_t w);

/**
 * Initializes a 4D uint8 vector 'out' with values from a 3D uint8 vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4U8_fromVec3(vec4uint8_t * out, vec3uint8_t * xyz, uint8_t w);

/**
 * Initializes a 4D int16 vector 'out' with values from a 3D int16 vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4I16_fromVec3(vec4int16_t * out, vec3int16_t * xyz, int16_t w);

/**
 * Initializes a 4D uint16 vector 'out' with values from a 3D uint16 vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4U16_fromVec3(vec4uint16_t * out, vec3uint16_t * xyz, uint16_t w);

/**
 * Initializes a 4D int32 vector 'out' with values from a 3D int32 vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4I32_fromVec3(vec4int32_t * out, vec3int32_t * xyz, int32_t w);

/**
 * Initializes a 4D uint32 vector 'out' with values from a 3D uint32 vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4U32_fromVec3(vec4uint32_t * out, vec3uint32_t * xyz, uint32_t w);

/**
 * Initializes a 4D int64 vector 'out' with values from a 3D int64 vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4I64_fromVec3(vec4int64_t * out, vec3int64_t * xyz, int64_t w);

/**
 * Initializes a 4D uint64 vector 'out' with values from a 3D uint64 vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4U64_fromVec3(vec4uint64_t * out, vec3uint64_t * xyz, uint64_t w);

/**
 * Initializes a 4D char vector 'out' with values from a 3D char vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4C_fromVec3(vec4char_t * out, vec3char_t * xyz, char w);

/**
 * Initializes a 4D float vector 'out' with values from a 3D float vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4F_fromVec3(vec4f_t * out, vec3f_t * xyz, float w);

/**
 * Initializes a 4D double vector 'out' with values from a 3D double vector 'xyz' and a scalar 'w'.
 *
 * @param out - The vector to be initialized.
 * @param xyz - The 3D vector representing x, y, and z values.
 * @param w   - The scalar value for the w component.
 */
void initvec4D_fromVec3(vec4d_t * out, vec3d_t * xyz, double w);



/**
 * Allocates and initializes a 4D int8 vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D int8 vector.
 */
vec4int8_t * allocvec4I8(int8_t x, int8_t y, int8_t z, int8_t w);

/**
 * Allocates and initializes a 4D uint8 vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D uint8 vector.
 */
vec4uint8_t * allocvec4U8(uint8_t x, uint8_t y, uint8_t z, uint8_t w);

/**
 * Allocates and initializes a 4D int16 vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D int16 vector.
 */
vec4int16_t * allocvec4I16(int16_t x, int16_t y, int16_t z, int16_t w);

/**
 * Allocates and initializes a 4D uint16 vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D uint16 vector.
 */
vec4uint16_t * allocvec4U16(uint16_t x, uint16_t y, uint16_t z, uint16_t w);

/**
 * Allocates and initializes a 4D int32 vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D int32 vector.
 */
vec4int32_t * allocvec4I32(int32_t x, int32_t y, int32_t z, int32_t w);

/**
 * Allocates and initializes a 4D uint32 vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D uint32 vector.
 */
vec4uint32_t * allocvec4U32(uint32_t x, uint32_t y, uint32_t z, uint32_t w);

/**
 * Allocates and initializes a 4D int64 vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D int64 vector.
 */
vec4int64_t * allocvec4I64(int64_t x, int64_t y, int64_t z, int64_t w);

/**
 * Allocates and initializes a 4D uint64 vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D uint64 vector.
 */
vec4uint64_t * allocvec4U64(uint64_t x, uint64_t y, uint64_t z, uint64_t w);

/**
 * Allocates and initializes a 4D char vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D char vector.
 */
vec4char_t * allocvec4C(char x, char y, char z, char w);

/**
 * Allocates and initializes a 4D float vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D float vector.
 */
vec4f_t * allocvec4F(float x, float y, float z, float w);

/**
 * Allocates and initializes a 4D double vector with the given values.
 *
 * @param x - The value for the x component.
 * @param y - The value for the y component.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D double vector.
 */
vec4d_t * allocvec4D(double x, double y, double z, double w);


/**
 * Allocates and initializes a 4D int8 vector from a 2D int8 vector and additional components.
 *
 * @param xy - The 2D int8 vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D int8 vector.
 */
vec4int8_t * allocvec4I8_fromVec2(vec2int8_t * xy, int8_t z, int8_t w);

/**
 * Allocates and initializes a 4D uint8 vector from a 2D uint8 vector and additional components.
 *
 * @param xy - The 2D uint8 vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D uint8 vector.
 */
vec4uint8_t * allocvec4U8_fromVec2(vec2uint8_t * xy, uint8_t z, uint8_t w);

/**
 * Allocates and initializes a 4D int16 vector from a 2D int16 vector and additional components.
 *
 * @param xy - The 2D int16 vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D int16 vector.
 */
vec4int16_t * allocvec4I16_fromVec2(vec2int16_t * xy, int16_t z, int16_t w);

/**
 * Allocates and initializes a 4D uint16 vector from a 2D uint16 vector and additional components.
 *
 * @param xy - The 2D uint16 vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D uint16 vector.
 */
vec4uint16_t * allocvec4U16_fromVec2(vec2uint16_t * xy, uint16_t z, uint16_t w);

/**
 * Allocates and initializes a 4D int32 vector from a 2D int32 vector and additional components.
 *
 * @param xy - The 2D int32 vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D int32 vector.
 */
vec4int32_t * allocvec4I32_fromVec2(vec2int32_t * xy, int32_t z, int32_t w);

/**
 * Allocates and initializes a 4D uint32 vector from a 2D uint32 vector and additional components.
 *
 * @param xy - The 2D uint32 vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D uint32 vector.
 */
vec4uint32_t * allocvec4U32_fromVec2(vec2uint32_t * xy, uint32_t z, uint32_t w);

/**
 * Allocates and initializes a 4D int64 vector from a 2D int64 vector and additional components.
 *
 * @param xy - The 2D int64 vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D int64 vector.
 */
vec4int64_t * allocvec4I64_fromVec2(vec2int64_t * xy, int64_t z, int64_t w);

/**
 * Allocates and initializes a 4D uint64 vector from a 2D uint64 vector and additional components.
 *
 * @param xy - The 2D uint64 vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D uint64 vector.
 */
vec4uint64_t * allocvec4U64_fromVec2(vec2uint64_t * xy, uint64_t z, uint64_t w);

/**
 * Allocates and initializes a 4D char vector from a 2D char vector and additional components.
 *
 * @param xy - The 2D char vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D char vector.
 */
vec4char_t * allocvec4C_fromVec2(vec2char_t * xy, char z, char w);

/**
 * Allocates and initializes a 4D float vector from a 2D float vector and additional components.
 *
 * @param xy - The 2D float vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D float vector.
 */
vec4f_t * allocvec4F_fromVec2(vec2f_t * xy, float z, float w);

/**
 * Allocates and initializes a 4D double vector from a 2D double vector and additional components.
 *
 * @param xy - The 2D double vector representing the x and y components.
 * @param z - The value for the z component.
 * @param w - The value for the w component.
 * @return A pointer to the initialized 4D double vector.
 */
vec4d_t * allocvec4D_fromVec2(vec2d_t * xy, double z, double w);


/**
 * Allocates and initializes a 4D int8 vector from two 2D int8 vectors and additional components.
 *
 * @param xy - The first 2D int8 vector representing the x and y components.
 * @param zw - The second 2D int8 vector representing the z and w components.
 * @return A pointer to the initialized 4D int8 vector.
 */
vec4int8_t * allocvec4I8_from2Vec2(vec2int8_t * xy, vec2int8_t * zw);

/**
 * Allocates and initializes a 4D uint8 vector from two 2D uint8 vectors and additional components.
 *
 * @param xy - The first 2D uint8 vector representing the x and y components.
 * @param zw - The second 2D uint8 vector representing the z and w components.
 * @return A pointer to the initialized 4D uint8 vector.
 */
vec4uint8_t * allocvec4U8_from2Vec2(vec2uint8_t * xy, vec2uint8_t * zw);

/**
 * Allocates and initializes a 4D int16 vector from two 2D int16 vectors and additional components.
 *
 * @param xy - The first 2D int16 vector representing the x and y components.
 * @param zw - The second 2D int16 vector representing the z and w components.
 * @return A pointer to the initialized 4D int16 vector.
 */
vec4int16_t * allocvec4I16_from2Vec2(vec2int16_t * xy, vec2int16_t * zw);

/**
 * Allocates and initializes a 4D uint16 vector from two 2D uint16 vectors and additional components.
 *
 * @param xy - The first 2D uint16 vector representing the x and y components.
 * @param zw - The second 2D uint16 vector representing the z and w components.
 * @return A pointer to the initialized 4D uint16 vector.
 */
vec4uint16_t * allocvec4U16_from2Vec2(vec2uint16_t * xy, vec2uint16_t * zw);

/**
 * Allocates and initializes a 4D int32 vector from two 2D int32 vectors and additional components.
 *
 * @param xy - The first 2D int32 vector representing the x and y components.
 * @param zw - The second 2D int32 vector representing the z and w components.
 * @return A pointer to the initialized 4D int32 vector.
 */
vec4int32_t * allocvec4I32_from2Vec2(vec2int32_t * xy, vec2int32_t * zw);

/**
 * Allocates and initializes a 4D uint32 vector from two 2D uint32 vectors and additional components.
 *
 * @param xy - The first 2D uint32 vector representing the x and y components.
 * @param zw - The second 2D uint32 vector representing the z and w components.
 * @return A pointer to the initialized 4D uint32 vector.
 */
vec4uint32_t * allocvec4U32_from2Vec2(vec2uint32_t * xy, vec2uint32_t * zw);

/**
 * Allocates and initializes a 4D int64 vector from two 2D int64 vectors and additional components.
 *
 * @param xy - The first 2D int64 vector representing the x and y components.
 * @param zw - The second 2D int64 vector representing the z and w components.
 * @return A pointer to the initialized 4D int64 vector.
 */
vec4int64_t * allocvec4I64_from2Vec2(vec2int64_t * xy, vec2int64_t * zw);

/**
 * Allocates and initializes a 4D uint64 vector from two 2D uint64 vectors and additional components.
 *
 * @param xy - The first 2D uint64 vector representing the x and y components.
 * @param zw - The second 2D uint64 vector representing the z and w components.
 * @return A pointer to the initialized 4D uint64 vector.
 */
vec4uint64_t * allocvec4U64_from2Vec2(vec2uint64_t * xy, vec2uint64_t * zw);

/**
 * Allocates and initializes a 4D char vector from two 2D char vectors and additional components.
 *
 * @param xy - The first 2D char vector representing the x and y components.
 * @param zw - The second 2D char vector representing the z and w components.
 * @return A pointer to the initialized 4D char vector.
 */
vec4char_t * allocvec4C_from2Vec2(vec2char_t * xy, vec2char_t * zw);

/**
 * Allocates and initializes a 4D float vector from two 2D float vectors and additional components.
 *
 * @param xy - The first 2D float vector representing the x and y components.
 * @param zw - The second 2D float vector representing the z and w components.
 * @return A pointer to the initialized 4D float vector.
 */
vec4f_t * allocvec4F_from2Vec2(vec2f_t * xy, vec2f_t * zw);

/**
 * Allocates and initializes a 4D double vector from two 2D double vectors and additional components.
 *
 * @param xy - The first 2D double vector representing the x and y components.
 * @param zw - The second 2D double vector representing the z and w components.
 * @return A pointer to the initialized 4D double vector.
 */
vec4d_t * allocvec4D_from2Vec2(vec2d_t * xy, vec2d_t * zw);


/**
 * Allocates and initializes a 4D int8 vector from a 3D int8 vector and an additional component.
 *
 * @param xyz - The 3D int8 vector representing the x, y, and z components.
 * @param w - The additional int8 component for the w dimension.
 * @return A pointer to the initialized 4D int8 vector.
 */
vec4int8_t * allocvec4I8_fromVec3(vec3int8_t * xyz, int8_t w);

/**
 * Allocates and initializes a 4D uint8 vector from a 3D uint8 vector and an additional component.
 *
 * @param xyz - The 3D uint8 vector representing the x, y, and z components.
 * @param w - The additional uint8 component for the w dimension.
 * @return A pointer to the initialized 4D uint8 vector.
 */
vec4uint8_t * allocvec4U8_fromVec3(vec3uint8_t * xyz, uint8_t w);

/**
 * Allocates and initializes a 4D int16 vector from a 3D int16 vector and an additional component.
 *
 * @param xyz - The 3D int16 vector representing the x, y, and z components.
 * @param w - The additional int16 component for the w dimension.
 * @return A pointer to the initialized 4D int16 vector.
 */
vec4int16_t * allocvec4I16_fromVec3(vec3int16_t * xyz, int16_t w);

/**
 * Allocates and initializes a 4D uint16 vector from a 3D uint16 vector and an additional component.
 *
 * @param xyz - The 3D uint16 vector representing the x, y, and z components.
 * @param w - The additional uint16 component for the w dimension.
 * @return A pointer to the initialized 4D uint16 vector.
 */
vec4uint16_t * allocvec4U16_fromVec3(vec3uint16_t * xyz, uint16_t w);

/**
 * Allocates and initializes a 4D int32 vector from a 3D int32 vector and an additional component.
 *
 * @param xyz - The 3D int32 vector representing the x, y, and z components.
 * @param w - The additional int32 component for the w dimension.
 * @return A pointer to the initialized 4D int32 vector.
 */
vec4int32_t * allocvec4I32_fromVec3(vec3int32_t * xyz, int32_t w);

/**
 * Allocates and initializes a 4D uint32 vector from a 3D uint32 vector and an additional component.
 *
 * @param xyz - The 3D uint32 vector representing the x, y, and z components.
 * @param w - The additional uint32 component for the w dimension.
 * @return A pointer to the initialized 4D uint32 vector.
 */
vec4uint32_t * allocvec4U32_fromVec3(vec3uint32_t * xyz, uint32_t w);

/**
 * Allocates and initializes a 4D int64 vector from a 3D int64 vector and an additional component.
 *
 * @param xyz - The 3D int64 vector representing the x, y, and z components.
 * @param w - The additional int64 component for the w dimension.
 * @return A pointer to the initialized 4D int64 vector.
 */
vec4int64_t * allocvec4I64_fromVec3(vec3int64_t * xyz, int64_t w);

/**
 * Allocates and initializes a 4D uint64 vector from a 3D uint64 vector and an additional component.
 *
 * @param xyz - The 3D uint64 vector representing the x, y, and z components.
 * @param w - The additional uint64 component for the w dimension.
 * @return A pointer to the initialized 4D uint64 vector.
 */
vec4uint64_t * allocvec4U64_fromVec3(vec3uint64_t * xyz, uint64_t w);

/**
 * Allocates and initializes a 4D char vector from a 3D char vector and an additional component.
 *
 * @param xyz - The 3D char vector representing the x, y, and z components.
 * @param w - The additional char component for the w dimension.
 * @return A pointer to the initialized 4D char vector.
 */
vec4char_t * allocvec4C_fromVec3(vec3char_t * xyz, char w);

/**
 * Allocates and initializes a 4D float vector from a 3D float vector and an additional component.
 *
 * @param xyz - The 3D float vector representing the x, y, and z components.
 * @param w - The additional float component for the w dimension.
 * @return A pointer to the initialized 4D float vector.
 */
vec4f_t * allocvec4F_fromVec3(vec3f_t * xyz, float w);

/**
 * Allocates and initializes a 4D double vector from a 3D double vector and an additional component.
 *
 * @param xyz - The 3D double vector representing the x, y, and z components.
 * @param w - The additional double component for the w dimension.
 * @return A pointer to the initialized 4D double vector.
 */
vec4d_t * allocvec4D_fromVec3(vec3d_t * xyz, double w);



/**
 * Allocates and initializes a 4D int8 vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D int8 vector.
 * @return A pointer to the initialized 4D int8 vector.
 */
vec4int8_t * allocvec4I8_fromString(const char * str);

/**
 * Allocates and initializes a 4D uint8 vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D uint8 vector.
 * @return A pointer to the initialized 4D uint8 vector.
 */
vec4uint8_t * allocvec4U8_fromString(const char * str);

/**
 * Allocates and initializes a 4D int16 vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D int16 vector.
 * @return A pointer to the initialized 4D int16 vector.
 */
vec4int16_t * allocvec4I16_fromString(const char * str);

/**
 * Allocates and initializes a 4D uint16 vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D uint16 vector.
 * @return A pointer to the initialized 4D uint16 vector.
 */
vec4uint16_t * allocvec4U16_fromString(const char * str);

/**
 * Allocates and initializes a 4D int32 vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D int32 vector.
 * @return A pointer to the initialized 4D int32 vector.
 */
vec4int32_t * allocvec4I32_fromString(const char * str);

/**
 * Allocates and initializes a 4D uint32 vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D uint32 vector.
 * @return A pointer to the initialized 4D uint32 vector.
 */
vec4uint32_t * allocvec4U32_fromString(const char * str);

/**
 * Allocates and initializes a 4D int64 vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D int64 vector.
 * @return A pointer to the initialized 4D int64 vector.
 */
vec4int64_t * allocvec4I64_fromString(const char * str);

/**
 * Allocates and initializes a 4D uint64 vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D uint64 vector.
 * @return A pointer to the initialized 4D uint64 vector.
 */
vec4uint64_t * allocvec4U64_fromString(const char * str);

/**
 * Allocates and initializes a 4D char vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D char vector.
 * @return A pointer to the initialized 4D char vector.
 */
vec4char_t * allocvec4C_fromString(const char * str);

/**
 * Allocates and initializes a 4D float vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D float vector.
 * @return A pointer to the initialized 4D float vector.
 */
vec4f_t * allocvec4F_fromString(const char * str);

/**
 * Allocates and initializes a 4D double vector from a string representation.
 *
 * @param str - The string containing comma-separated values for the 4D double vector.
 * @return A pointer to the initialized 4D double vector.
 */
vec4d_t * allocvec4D_fromString(const char * str);



/**
 * Sets the 'x' component of a 4D int8 vector.
 *
 * @param out - A pointer to the 4D int8 vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4i8_setX(vec4int8_t * out, int8_t x);

/**
 * Sets the 'y' component of a 4D int8 vector.
 *
 * @param out - A pointer to the 4D int8 vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4i8_setY(vec4int8_t * out, int8_t y);

/**
 * Sets the 'z' component of a 4D int8 vector.
 *
 * @param out - A pointer to the 4D int8 vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4i8_setZ(vec4int8_t * out, int8_t z);

/**
 * Sets the 'w' component of a 4D int8 vector.
 *
 * @param out - A pointer to the 4D int8 vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4i8_setW(vec4int8_t * out, int8_t w);


/**
 * Gets the 'x' component of a 4D int8 vector.
 *
 * @param out - A pointer to the 4D int8 vector.
 * @return The 'x' component of the vector.
 */
int8_t vec4i8_X(vec4int8_t * out);

/**
 * Gets the 'y' component of a 4D int8 vector.
 *
 * @param out - A pointer to the 4D int8 vector.
 * @return The 'y' component of the vector.
 */
int8_t vec4i8_Y(vec4int8_t * out);

/**
 * Gets the 'z' component of a 4D int8 vector.
 *
 * @param out - A pointer to the 4D int8 vector.
 * @return The 'z' component of the vector.
 */
int8_t vec4i8_Z(vec4int8_t * out);

/**
 * Gets the 'w' component of a 4D int8 vector.
 *
 * @param out - A pointer to the 4D int8 vector.
 * @return The 'w' component of the vector.
 */
int8_t vec4i8_W(vec4int8_t * out);



/**
 * Sets the 'x' component of a 4D uint8 vector.
 *
 * @param out - A pointer to the 4D uint8 vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4u8_setX(vec4uint8_t * out, uint8_t x);

/**
 * Sets the 'y' component of a 4D uint8 vector.
 *
 * @param out - A pointer to the 4D uint8 vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4u8_setY(vec4uint8_t * out, uint8_t y);

/**
 * Sets the 'z' component of a 4D uint8 vector.
 *
 * @param out - A pointer to the 4D uint8 vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4u8_setZ(vec4uint8_t * out, uint8_t z);

/**
 * Sets the 'w' component of a 4D uint8 vector.
 *
 * @param out - A pointer to the 4D uint8 vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4u8_setW(vec4int8_t * out, uint8_t w);

/**
 * Gets the 'x' component of a 4D uint8 vector.
 *
 * @param out - A pointer to the 4D uint8 vector.
 * @return The 'x' component of the vector.
 */
uint8_t vec4u8_X(vec4uint8_t * out);

/**
 * Gets the 'y' component of a 4D uint8 vector.
 *
 * @param out - A pointer to the 4D uint8 vector.
 * @return The 'y' component of the vector.
 */
uint8_t vec4u8_Y(vec4uint8_t * out);

/**
 * Gets the 'z' component of a 4D uint8 vector.
 *
 * @param out - A pointer to the 4D uint8 vector.
 * @return The 'z' component of the vector.
 */
uint8_t vec4u8_Z(vec4uint8_t * out);

/**
 * Gets the 'w' component of a 4D uint8 vector.
 *
 * @param out - A pointer to the 4D uint8 vector.
 * @return The 'w' component of the vector.
 */
uint8_t vec4u8_W(vec4uint8_t * out);



/**
 * Sets the 'x' component of a 4D int16 vector.
 *
 * @param out - A pointer to the 4D int16 vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4i16_setX(vec4int16_t * out, int16_t x);

/**
 * Sets the 'y' component of a 4D int16 vector.
 *
 * @param out - A pointer to the 4D int16 vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4i16_setY(vec4int16_t * out, int16_t y);

/**
 * Sets the 'z' component of a 4D int16 vector.
 *
 * @param out - A pointer to the 4D int16 vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4i16_setZ(vec4int16_t * out, int16_t z);

/**
 * Sets the 'w' component of a 4D int16 vector.
 *
 * @param out - A pointer to the 4D int16 vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4i16_setW(vec4int16_t * out, int16_t w);


/**
 * Gets the 'x' component of a 4D int16 vector.
 *
 * @param out - A pointer to the 4D int16 vector.
 * @return The 'x' component of the vector.
 */
int16_t vec4i16_X(vec4int16_t * out);

/**
 * Gets the 'y' component of a 4D int16 vector.
 *
 * @param out - A pointer to the 4D int16 vector.
 * @return The 'y' component of the vector.
 */
int16_t vec4i16_Y(vec4int16_t * out);

/**
 * Gets the 'z' component of a 4D int16 vector.
 *
 * @param out - A pointer to the 4D int16 vector.
 * @return The 'z' component of the vector.
 */
int16_t vec4i16_Z(vec4int16_t * out);

/**
 * Gets the 'w' component of a 4D int16 vector.
 *
 * @param out - A pointer to the 4D int16 vector.
 * @return The 'w' component of the vector.
 */
int16_t vec4i16_W(vec4int16_t * out);


/**
 * Sets the 'x' component of a 4D uint16 vector.
 *
 * @param out - A pointer to the 4D uint16 vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4u16_setX(vec4uint16_t * out, uint16_t x);

/**
 * Sets the 'y' component of a 4D uint16 vector.
 *
 * @param out - A pointer to the 4D uint16 vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4u16_setY(vec4uint16_t * out, uint16_t y);

/**
 * Sets the 'z' component of a 4D uint16 vector.
 *
 * @param out - A pointer to the 4D uint16 vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4u16_setZ(vec4uint16_t * out, uint16_t z);

/**
 * Sets the 'w' component of a 4D uint16 vector.
 *
 * @param out - A pointer to the 4D uint16 vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4u16_setW(vec4uint16_t * out, uint16_t w);


/**
 * Gets the 'x' component of a 4D uint16 vector.
 *
 * @param out - A pointer to the 4D uint16 vector.
 * @return The 'x' component of the vector.
 */
uint16_t vec4u16_X(vec4uint16_t * out);

/**
 * Gets the 'y' component of a 4D uint16 vector.
 *
 * @param out - A pointer to the 4D uint16 vector.
 * @return The 'y' component of the vector.
 */
uint16_t vec4u16_Y(vec4uint16_t * out);

/**
 * Gets the 'z' component of a 4D uint16 vector.
 *
 * @param out - A pointer to the 4D uint16 vector.
 * @return The 'z' component of the vector.
 */
uint16_t vec4u16_Z(vec4uint16_t * out);

/**
 * Gets the 'w' component of a 4D uint16 vector.
 *
 * @param out - A pointer to the 4D uint16 vector.
 * @return The 'w' component of the vector.
 */
uint16_t vec4u16_W(vec4uint16_t * out);


/**
 * Sets the 'x' component of a 4D int32 vector.
 *
 * @param out - A pointer to the 4D int32 vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4i32_setX(vec4int32_t * out, int32_t x);

/**
 * Sets the 'y' component of a 4D int32 vector.
 *
 * @param out - A pointer to the 4D int32 vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4i32_setY(vec4int32_t * out, int32_t y);

/**
 * Sets the 'z' component of a 4D int32 vector.
 *
 * @param out - A pointer to the 4D int32 vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4i32_setZ(vec4int32_t * out, int32_t z);

/**
 * Sets the 'w' component of a 4D int32 vector.
 *
 * @param out - A pointer to the 4D int32 vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4i32_setW(vec4int32_t * out, int32_t w);


/**
 * Gets the 'x' component of a 4D int32 vector.
 *
 * @param out - A pointer to the 4D int32 vector.
 * @return The 'x' component of the vector.
 */
int32_t vec4i32_X(vec4int32_t * out);

/**
 * Gets the 'y' component of a 4D int32 vector.
 *
 * @param out - A pointer to the 4D int32 vector.
 * @return The 'y' component of the vector.
 */
int32_t vec4i32_Y(vec4int32_t * out);

/**
 * Gets the 'z' component of a 4D int32 vector.
 *
 * @param out - A pointer to the 4D int32 vector.
 * @return The 'z' component of the vector.
 */
int32_t vec4i32_Z(vec4int32_t * out);

/**
 * Gets the 'w' component of a 4D int32 vector.
 *
 * @param out - A pointer to the 4D int32 vector.
 * @return The 'w' component of the vector.
 */
int32_t vec4i32_W(vec4int32_t * out);

/**
 * Sets the 'x' component of a 4D uint32 vector.
 *
 * @param out - A pointer to the 4D uint32 vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4u32_setX(vec4uint32_t * out, uint32_t x);

/**
 * Sets the 'y' component of a 4D uint32 vector.
 *
 * @param out - A pointer to the 4D uint32 vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4u32_setY(vec4uint32_t * out, uint32_t y);

/**
 * Sets the 'z' component of a 4D uint32 vector.
 *
 * @param out - A pointer to the 4D uint32 vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4u32_setZ(vec4uint32_t * out, uint32_t z);

/**
 * Sets the 'w' component of a 4D uint32 vector.
 *
 * @param out - A pointer to the 4D uint32 vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4u32_setW(vec4uint32_t * out, uint32_t w);

/**
 * Gets the 'x' component of a 4D uint32 vector.
 *
 * @param out - A pointer to the 4D uint32 vector.
 * @return The 'x' component of the vector.
 */
uint32_t vec4u32_X(vec4uint32_t * out);

/**
 * Gets the 'y' component of a 4D uint32 vector.
 *
 * @param out - A pointer to the 4D uint32 vector.
 * @return The 'y' component of the vector.
 */
uint32_t vec4u32_Y(vec4uint32_t * out);

/**
 * Gets the 'z' component of a 4D uint32 vector.
 *
 * @param out - A pointer to the 4D uint32 vector.
 * @return The 'z' component of the vector.
 */
uint32_t vec4u32_Z(vec4uint32_t * out);

/**
 * Gets the 'w' component of a 4D uint32 vector.
 *
 * @param out - A pointer to the 4D uint32 vector.
 * @return The 'w' component of the vector.
 */
uint32_t vec4u32_W(vec4uint32_t * out);

/**
 * Sets the 'x' component of a 4D int64 vector.
 *
 * @param out - A pointer to the 4D int64 vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4i64_setX(vec4int64_t * out, int64_t x);

/**
 * Sets the 'y' component of a 4D int64 vector.
 *
 * @param out - A pointer to the 4D int64 vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4i64_setY(vec4int64_t * out, int64_t y);

/**
 * Sets the 'z' component of a 4D int64 vector.
 *
 * @param out - A pointer to the 4D int64 vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4i64_setZ(vec4int64_t * out, int64_t z);

/**
 * Sets the 'w' component of a 4D int64 vector.
 *
 * @param out - A pointer to the 4D int64 vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4i64_setW(vec4int64_t * out, int64_t w);

/**
 * Gets the 'x' component of a 4D int64 vector.
 *
 * @param out - A pointer to the 4D int64 vector.
 * @return The 'x' component of the vector.
 */
int64_t vec4i64_X(vec4int64_t * out);

/**
 * Gets the 'y' component of a 4D int64 vector.
 *
 * @param out - A pointer to the 4D int64 vector.
 * @return The 'y' component of the vector.
 */
int64_t vec4i64_Y(vec4int64_t * out);

/**
 * Gets the 'z' component of a 4D int64 vector.
 *
 * @param out - A pointer to the 4D int64 vector.
 * @return The 'z' component of the vector.
 */
int64_t vec4i64_Z(vec4int64_t * out);

/**
 * Gets the 'w' component of a 4D int64 vector.
 *
 * @param out - A pointer to the 4D int64 vector.
 * @return The 'w' component of the vector.
 */
int64_t vec4i64_W(vec4int64_t * out);


/**
 * Sets the 'x' component of a 4D uint64 vector.
 *
 * @param out - A pointer to the 4D uint64 vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4u64_setX(vec4uint64_t * out, uint64_t x);

/**
 * Sets the 'y' component of a 4D uint64 vector.
 *
 * @param out - A pointer to the 4D uint64 vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4u64_setY(vec4uint64_t * out, uint64_t y);

/**
 * Sets the 'z' component of a 4D uint64 vector.
 *
 * @param out - A pointer to the 4D uint64 vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4u64_setZ(vec4uint64_t * out, uint64_t z);

/**
 * Sets the 'w' component of a 4D uint64 vector.
 *
 * @param out - A pointer to the 4D uint64 vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4u64_setW(vec4uint64_t * out, uint64_t w);

/**
 * Gets the 'x' component of a 4D uint64 vector.
 *
 * @param out - A pointer to the 4D uint64 vector.
 * @return The 'x' component of the vector.
 */
uint64_t vec4u64_X(vec4uint64_t * out);

/**
 * Gets the 'y' component of a 4D uint64 vector.
 *
 * @param out - A pointer to the 4D uint64 vector.
 * @return The 'y' component of the vector.
 */
uint64_t vec4u64_Y(vec4uint64_t * out);

/**
 * Gets the 'z' component of a 4D uint64 vector.
 *
 * @param out - A pointer to the 4D uint64 vector.
 * @return The 'z' component of the vector.
 */
uint64_t vec4u64_Z(vec4uint64_t * out);

/**
 * Gets the 'w' component of a 4D uint64 vector.
 *
 * @param out - A pointer to the 4D uint64 vector.
 * @return The 'w' component of the vector.
 */
uint64_t vec4u64_W(vec4uint64_t * out);

/**
 * Sets the 'x' component of a 4D char vector.
 *
 * @param out - A pointer to the 4D char vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4char_setX(vec4char_t * out, char x);

/**
 * Sets the 'y' component of a 4D char vector.
 *
 * @param out - A pointer to the 4D char vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4char_setY(vec4char_t * out, char y);

/**
 * Sets the 'z' component of a 4D char vector.
 *
 * @param out - A pointer to the 4D char vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4char_setZ(vec4char_t * out, char z);

/**
 * Sets the 'w' component of a 4D char vector.
 *
 * @param out - A pointer to the 4D char vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4char_setW(vec4char_t * out, char w);

/**
 * Gets the 'x' component of a 4D char vector.
 *
 * @param out - A pointer to the 4D char vector.
 * @return The 'x' component of the vector.
 */
char vec4char_X(vec4char_t * out);

/**
 * Gets the 'y' component of a 4D char vector.
 *
 * @param out - A pointer to the 4D char vector.
 * @return The 'y' component of the vector.
 */
char vec4char_Y(vec4char_t * out);

/**
 * Gets the 'z' component of a 4D char vector.
 *
 * @param out - A pointer to the 4D char vector.
 * @return The 'z' component of the vector.
 */
char vec4char_Z(vec4char_t * out);

/**
 * Gets the 'w' component of a 4D char vector.
 *
 * @param out - A pointer to the 4D char vector.
 * @return The 'w' component of the vector.
 */
char vec4char_W(vec4char_t * out);

/**
 * Sets the 'x' component of a 4D float vector.
 *
 * @param out - A pointer to the 4D float vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4f_setX(vec4f_t * out, float x);

/**
 * Sets the 'y' component of a 4D float vector.
 *
 * @param out - A pointer to the 4D float vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4f_setY(vec4f_t * out, float y);

/**
 * Sets the 'z' component of a 4D float vector.
 *
 * @param out - A pointer to the 4D float vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4f_setZ(vec4f_t * out, float z);

/**
 * Sets the 'w' component of a 4D float vector.
 *
 * @param out - A pointer to the 4D float vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4f_setW(vec4f_t * out, float w);

/**
 * Gets the 'x' component of a 4D float vector.
 *
 * @param out - A pointer to the 4D float vector.
 * @return The 'x' component of the vector.
 */
float vec4f_X(vec4f_t * out);

/**
 * Gets the 'y' component of a 4D float vector.
 *
 * @param out - A pointer to the 4D float vector.
 * @return The 'y' component of the vector.
 */
float vec4f_Y(vec4f_t * out);

/**
 * Gets the 'z' component of a 4D float vector.
 *
 * @param out - A pointer to the 4D float vector.
 * @return The 'z' component of the vector.
 */
float vec4f_Z(vec4f_t * out);

/**
 * Gets the 'w' component of a 4D float vector.
 *
 * @param out - A pointer to the 4D float vector.
 * @return The 'w' component of the vector.
 */
float vec4f_W(vec4f_t * out);

/**
 * Sets the 'x' component of a 4D double vector.
 *
 * @param out - A pointer to the 4D double vector to modify.
 * @param x - The value to set as the new 'x' component.
 */
void vec4d_setX(vec4d_t * out, double x);

/**
 * Sets the 'y' component of a 4D double vector.
 *
 * @param out - A pointer to the 4D double vector to modify.
 * @param y - The value to set as the new 'y' component.
 */
void vec4d_setY(vec4d_t * out, double y);

/**
 * Sets the 'z' component of a 4D double vector.
 *
 * @param out - A pointer to the 4D double vector to modify.
 * @param z - The value to set as the new 'z' component.
 */
void vec4d_setZ(vec4d_t * out, double z);

/**
 * Sets the 'w' component of a 4D double vector.
 *
 * @param out - A pointer to the 4D double vector to modify.
 * @param w - The value to set as the new 'w' component.
 */
void vec4d_setW(vec4d_t * out, double w);

/**
 * Gets the 'x' component of a 4D double vector.
 *
 * @param out - A pointer to the 4D double vector.
 * @return The 'x' component of the vector.
 */
double vec4d_X(vec4d_t * out);

/**
 * Gets the 'y' component of a 4D double vector.
 *
 * @param out - A pointer to the 4D double vector.
 * @return The 'y' component of the vector.
 */
double vec4d_Y(vec4d_t * out);

/**
 * Gets the 'z' component of a 4D double vector.
 *
 * @param out - A pointer to the 4D double vector.
 * @return The 'z' component of the vector.
 */
double vec4d_Z(vec4d_t * out);

/**
 * Gets the 'w' component of a 4D double vector.
 *
 * @param out - A pointer to the 4D double vector.
 * @return The 'w' component of the vector.
 */
double vec4d_W(vec4d_t * out);


/**
 * Converts a 4D int8 vector to a Plain-Old-Data (POD) int8 array.
 *
 * @param self - A pointer to the source 4D int8 vector.
 * @param out - A pointer to the user-provided int8 array to store the data.
 * @return A pointer to the int8 array containing the data.
 */
int8_t * vec4i8_asPOD(vec4int8_t * self, int8_t * out);

/**
 * Converts a 4D uint8 vector to a Plain-Old-Data (POD) uint8 array.
 *
 * @param self - A pointer to the source 4D uint8 vector.
 * @param out - A pointer to the user-provided uint8 array to store the data.
 * @return A pointer to the uint8 array containing the data.
 */
uint8_t * vec4u8_asPOD(vec4uint8_t * self, uint8_t * out);

/**
 * Converts a 4D int16 vector to a Plain-Old-Data (POD) int16 array.
 *
 * @param self - A pointer to the source 4D int16 vector.
 * @param out - A pointer to the user-provided int16 array to store the data.
 * @return A pointer to the int16 array containing the data.
 */
int16_t * vec4i16_asPOD(vec4int16_t * self, int16_t * out);

/**
 * Converts a 4D uint16 vector to a Plain-Old-Data (POD) uint16 array.
 *
 * @param self - A pointer to the source 4D uint16 vector.
 * @param out - A pointer to the user-provided uint16 array to store the data.
 * @return A pointer to the uint16 array containing the data.
 */
uint16_t * vec4u16_asPOD(vec4uint16_t * self, uint16_t * out);

/**
 * Converts a 4D int32 vector to a Plain-Old-Data (POD) int32 array.
 *
 * @param self - A pointer to the source 4D int32 vector.
 * @param out - A pointer to the user-provided int32 array to store the data.
 * @return A pointer to the int32 array containing the data.
 */
int32_t * vec4i32_asPOD(vec4int32_t * self, int32_t * out);

/**
 * Converts a 4D uint32 vector to a Plain-Old-Data (POD) uint32 array.
 *
 * @param self - A pointer to the source 4D uint32 vector.
 * @param out - A pointer to the user-provided uint32 array to store the data.
 * @return A pointer to the uint32 array containing the data.
 */
uint32_t * vec4u32_asPOD(vec4uint32_t * self, uint32_t * out);

/**
 * Converts a 4D int64 vector to a Plain-Old-Data (POD) int64 array.
 *
 * @param self - A pointer to the source 4D int64 vector.
 * @param out - A pointer to the user-provided int64 array to store the data.
 * @return A pointer to the int64 array containing the data.
 */
int64_t * vec4i64_asPOD(vec4int64_t * self, int64_t * out);

/**
 * Converts a 4D uint64 vector to a Plain-Old-Data (POD) uint64 array.
 *
 * @param self - A pointer to the source 4D uint64 vector.
 * @param out - A pointer to the user-provided uint64 array to store the data.
 * @return A pointer to the uint64 array containing the data.
 */
uint64_t * vec4u64_asPOD(vec4uint64_t * self, uint64_t * out);

/**
 * Converts a 4D float vector to a Plain-Old-Data (POD) float array.
 *
 * @param self - A pointer to the source 4D float vector.
 * @param out - A pointer to the user-provided float array to store the data.
 * @return A pointer to the float array containing the data.
 */
float * vec4f_asPOD(vec4f_t * self, float * out);

/**
 * Converts a 4D double vector to a Plain-Old-Data (POD) double array.
 *
 * @param self - A pointer to the source 4D double vector.
 * @param out - A pointer to the user-provided double array to store the data.
 * @return A pointer to the double array containing the data.
 */
double * vec4d_asPOD(vec4d_t * self, double * out);

/**
 * Converts a 4D char vector to a Plain-Old-Data (POD) char array.
 *
 * @param self - A pointer to the source 4D char vector.
 * @param out - A pointer to the user-provided char array to store the data.
 * @return A pointer to the char array containing the data.
 */
char * vec4c_asPOD(vec4char_t * self, char * out);





/**
 * Adds two 4D int8 vectors and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D int8 vector.
 * @param other - A pointer to the second input 4D int8 vector.
 */
void vec4i8_add(vec4int8_t * out, vec4int8_t * other);

/**
 * Adds a scalar value to each component of a 4D int8 vector and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D int8 vector.
 * @param scalar - The scalar value to add to each component of the vector.
 */
void vec4i8_addS(vec4int8_t * out, int8_t scalar);

/**
 * Adds two 4D int8 vectors and returns the result as a new 4D int8 vector.
 *
 * @param out - A pointer to the output 4D int8 vector to store the result.
 * @param other - A pointer to the second input 4D int8 vector.
 * @return A pointer to the new 4D int8 vector containing the result.
 */
vec4int8_t * vec4i8_add_r(vec4int8_t * out, vec4int8_t * other);

/**
 * Adds a scalar value to each component of a 4D int8 vector and returns the result as a new 4D int8 vector.
 *
 * @param out - A pointer to the output 4D int8 vector to store the result.
 * @param scalar - The scalar value to add to each component of the vector.
 * @return A pointer to the new 4D int8 vector containing the result.
 */
vec4int8_t * vec4i8_addS_r(vec4int8_t * out, int8_t scalar);

/**
 * Adds two 4D uint8 vectors and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D uint8 vector.
 * @param other - A pointer to the second input 4D uint8 vector.
 */
void vec4u8_add(vec4uint8_t * out, vec4uint8_t * other);

/**
 * Adds a scalar value to each component of a 4D uint8 vector and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D uint8 vector.
 * @param scalar - The scalar value to add to each component of the vector.
 */
void vec4u8_addS(vec4uint8_t * out, uint8_t scalar);

/**
 * Adds two 4D uint8 vectors and returns the result as a new 4D uint8 vector.
 *
 * @param out - A pointer to the output 4D uint8 vector to store the result.
 * @param other - A pointer to the second input 4D uint8 vector.
 * @return A pointer to the new 4D uint8 vector containing the result.
 */
vec4uint8_t * vec4u8_add_r(vec4uint8_t * out, vec4uint8_t * other);

/**
 * Adds a scalar value to each component of a 4D uint8 vector and returns the result as a new 4D uint8 vector.
 *
 * @param out - A pointer to the output 4D uint8 vector to store the result.
 * @param scalar - The scalar value to add to each component of the vector.
 * @return A pointer to the new 4D uint8 vector containing the result.
 */
vec4uint8_t * vec4u8_addS_r(vec4uint8_t * out, uint8_t scalar);


/**
 * Adds two 4D int16 vectors and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D int16 vector.
 * @param other - A pointer to the second input 4D int16 vector.
 */
void vec4i16_add(vec4int16_t * out, vec4int16_t * other);

/**
 * Adds a scalar value to each component of a 4D int16 vector and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D int16 vector.
 * @param scalar - The scalar value to add to each component of the vector.
 */
void vec4i16_addS(vec4int16_t * out, int16_t scalar);

/**
 * Adds two 4D int16 vectors and returns the result as a new 4D int16 vector.
 *
 * @param out - A pointer to the output 4D int16 vector to store the result.
 * @param other - A pointer to the second input 4D int16 vector.
 * @return A pointer to the new 4D int16 vector containing the result.
 */
vec4int16_t * vec4i16_add_r(vec4int16_t * out, vec4int16_t * other);

/**
 * Adds a scalar value to each component of a 4D int16 vector and returns the result as a new 4D int16 vector.
 *
 * @param out - A pointer to the output 4D int16 vector to store the result.
 * @param scalar - The scalar value to add to each component of the vector.
 * @return A pointer to the new 4D int16 vector containing the result.
 */
vec4int16_t * vec4i16_addS_r(vec4int16_t * out, int16_t scalar);

/**
 * Adds two 4D uint16 vectors and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D uint16 vector.
 * @param other - A pointer to the second input 4D uint16 vector.
 */
void vec4u16_add(vec4uint16_t * out, vec4uint16_t * other);

/**
 * Adds a scalar value to each component of a 4D uint16 vector and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D uint16 vector.
 * @param scalar - The scalar value to add to each component of the vector.
 */
void vec4u16_addS(vec4uint16_t * out, uint16_t scalar);

/**
 * Adds two 4D uint16 vectors and returns the result as a new 4D uint16 vector.
 *
 * @param out - A pointer to the output 4D uint16 vector to store the result.
 * @param other - A pointer to the second input 4D uint16 vector.
 * @return A pointer to the new 4D uint16 vector containing the result.
 */
vec4uint16_t * vec4u16_add_r(vec4uint16_t * out, vec4uint16_t * other);

/**
 * Adds a scalar value to each component of a 4D uint16 vector and returns the result as a new 4D uint16 vector.
 *
 * @param out - A pointer to the output 4D uint16 vector to store the result.
 * @param scalar - The scalar value to add to each component of the vector.
 * @return A pointer to the new 4D uint16 vector containing the result.
 */
vec4uint16_t * vec4u16_addS_r(vec4uint16_t * out, uint16_t scalar);

/**
 * Adds two 4D int32 vectors and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D int32 vector.
 * @param other - A pointer to the second input 4D int32 vector.
 */
void vec4i32_add(vec4int32_t * out, vec4int32_t * other);

/**
 * Adds a scalar value to each component of a 4D int32 vector and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D int32 vector.
 * @param scalar - The scalar value to add to each component of the vector.
 */
void vec4i32_addS(vec4int32_t * out, int32_t scalar);

/**
 * Adds two 4D int32 vectors and returns the result as a new 4D int32 vector.
 *
 * @param out - A pointer to the output 4D int32 vector to store the result.
 * @param other - A pointer to the second input 4D int32 vector.
 * @return A pointer to the new 4D int32 vector containing the result.
 */
vec4int32_t * vec4i32_add_r(vec4int32_t * out, vec4int32_t * other);

/**
 * Adds a scalar value to each component of a 4D int32 vector and returns the result as a new 4D int32 vector.
 *
 * @param out - A pointer to the output 4D int32 vector to store the result.
 * @param scalar - The scalar value to add to each component of the vector.
 * @return A pointer to the new 4D int32 vector containing the result.
 */
vec4int32_t * vec4i32_addS_r(vec4int32_t * out, int32_t scalar);

/**
 * Adds two 4D uint32 vectors and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D uint32 vector.
 * @param other - A pointer to the second input 4D uint32 vector.
 */
void vec4u32_add(vec4uint32_t * out, vec4uint32_t * other);

/**
 * Adds a scalar value to each component of a 4D int32 vector and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D uint32 vector.
 * @param scalar - The scalar value to add to each component of the vector.
 */
void vec4u32_addS(vec4uint32_t * out, uint32_t scalar);

/**
 * Adds two 4D uint32 vectors and returns the result as a new 4D uint32 vector.
 *
 * @param out - A pointer to the output 4D uint32 vector to store the result.
 * @param other - A pointer to the second input 4D uint32 vector.
 * @return A pointer to the new 4D uint32 vector containing the result.
 */
vec4uint32_t * vec4u32_add_r(vec4uint32_t * out, vec4uint32_t * other);

/**
 * Adds a scalar value to each component of a 4D int32 vector and returns the result as a new 4D uint32 vector.
 *
 * @param out - A pointer to the output 4D uint32 vector to store the result.
 * @param scalar - The scalar value to add to each component of the vector.
 * @return A pointer to the new 4D uint32 vector containing the result.
 */
vec4uint32_t * vec4u32_addS_r(vec4uint32_t * out, uint32_t scalar);

/**
 * Adds two 4D int64 vectors and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D int64 vector.
 * @param other - A pointer to the second input 4D int64 vector.
 */
void vec4i64_add(vec4int64_t * out, vec4int64_t * other);

/**
 * Adds a scalar value to each component of a 4D int64 vector and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D int64 vector.
 * @param scalar - The scalar value to add to each component of the vector.
 */
void vec4i64_addS(vec4int64_t * out, int64_t scalar);

/**
 * Adds two 4D int64 vectors and returns the result as a new 4D int64 vector.
 *
 * @param out - A pointer to the output 4D int64 vector to store the result.
 * @param other - A pointer to the second input 4D int64 vector.
 * @return A pointer to the new 4D int64 vector containing the result.
 */
vec4int64_t * vec4i64_add_r(vec4int64_t * out, vec4int64_t * other);

/**
 * Adds a scalar value to each component of a 4D int64 vector and returns the result as a new 4D int64 vector.
 *
 * @param out - A pointer to the output 4D int64 vector to store the result.
 * @param scalar - The scalar value to add to each component of the vector.
 * @return A pointer to the new 4D int64 vector containing the result.
 */
vec4int64_t * vec4i64_addS_r(vec4int64_t * out, int64_t scalar);

/**
 * Adds two 4D uint64 vectors and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D uint64 vector.
 * @param other - A pointer to the second input 4D uint64 vector.
 */
void vec4u64_add(vec4uint64_t * out, vec4uint64_t * other);

/**
 * Adds a scalar value to each component of a 4D int64 vector and stores the result in the 'out' vector.
 *
 * @param out - A pointer to the output 4D uint64 vector.
 * @param scalar - The scalar value to add to each component of the vector.
 */
void vec4u64_addS(vec4uint64_t * out, uint64_t scalar);

/**
 * Adds two 4D uint64 vectors and returns the result as a new 4D uint64 vector.
 *
 * @param out - A pointer to the output 4D uint64 vector to store the result.
 * @param other - A pointer to the second input 4D uint64 vector.
 * @return A pointer to the new 4D uint64 vector containing the result.
 */
vec4uint64_t * vec4u64_add_r(vec4uint64_t * out, vec4uint64_t * other);

/**
 * Adds a scalar value to each component of a 4D int64 vector and returns the result as a new 4D uint64 vector.
 *
 * @param out - A pointer to the output 4D uint64 vector to store the result.
 * @param scalar - The scalar value to add to each component of the vector.
 * @return A pointer to the new 4D uint64 vector containing the result.
 */
vec4uint64_t * vec4u64_addS_r(vec4uint64_t * out, uint64_t scalar);


// Add two 4D float vectors 'other' to 'out' and store the result in 'out'.
void vec4f_add(vec4f_t *out, vec4f_t *other);

// Add a scalar 'scalar' to each element of the 4D float vector 'out' and store the result in 'out'.
void vec4f_addS(vec4f_t *out, float scalar);

// Add two 4D float vectors and return a new vector as the result.
vec4f_t *vec4f_add_r(vec4f_t *out, vec4f_t *other);

// Add a scalar 'scalar' to each element of the 4D float vector 'out' and return a new vector as the result.
vec4f_t *vec4f_addS_r(vec4f_t *out, float scalar);


/**
 * Adds two 4D double vectors 'other' and 'out' and stores the result in 'out'.
 *
 * @param out   - The destination vector for the addition result.
 * @param other - The source vector to add to 'out'.
 */
void vec4d_add(vec4d_t * out, vec4d_t * other);

/**
 * Adds a scalar 'scalar' to each element of the 4D double vector 'out' and stores the result in 'out'.
 *
 * @param out    - The destination vector for the addition result.
 * @param scalar - The scalar value to add to each element of 'out'.
 */
void vec4d_addS(vec4d_t * out, double scalar);

/**
 * Adds two 4D double vectors and returns a new vector as the result. The original vectors remain unchanged.
 *
 * @param out   - The destination vector for the addition result.
 * @param other - The source vector to add to 'out'.
 * @return      - A new 4D double vector containing the result of the addition.
 */
vec4d_t * vec4d_add_r(vec4d_t * out, vec4d_t * other);

/**
 * Adds a scalar 'scalar' to each element of the 4D double vector 'out' and returns a new vector as the result.
 * The original vector remains unchanged.
 *
 * @param out    - The destination vector for the addition result.
 * @param scalar - The scalar value to add to each element of 'out'.
 * @return       - A new 4D double vector containing the result of the addition.
 */
vec4d_t * vec4d_addS_r(vec4d_t * out, double scalar);


/**
 * Subtracts each element of 4D int8 vectors 'other' from 'out' and stores the result in 'out'.
 *
 * @param out   - The destination vector for the subtraction result.
 * @param other - The source vector to subtract from 'out'.
 */
void vec4i8_sub(vec4int8_t * out, vec4int8_t * other);

/**
 * Subtracts a scalar 'scalar' from each element of the 4D int8 vector 'out' and stores the result in 'out'.
 *
 * @param out    - The destination vector for the subtraction result.
 * @param scalar - The scalar value to subtract from each element of 'out'.
 */
void vec4i8_subS(vec4int8_t * out, int8_t scalar);

/**
 * Subtracts each element of 4D int8 vectors 'other' from 'out' and returns a new vector as the result.
 * The original vectors remain unchanged.
 *
 * @param out   - The destination vector for the subtraction result.
 * @param other - The source vector to subtract from 'out'.
 * @return      - A new 4D int8 vector containing the result of the subtraction.
 */
vec4int8_t * vec4i8_sub_r(vec4int8_t * out, vec4int8_t * other);

/**
 * Subtracts a scalar 'scalar' from each element of the 4D int8 vector 'out' and returns a new vector as the result.
 * The original vector remains unchanged.
 *
 * @param out    - The destination vector for the subtraction result.
 * @param scalar - The scalar value to subtract from each element of 'out'.
 * @return       - A new 4D int8 vector containing the result of the subtraction.
 */
vec4int8_t * vec4i8_subS_r(vec4int8_t * out, int8_t scalar);


/**
 * Subtracts each element of 4D uint8 vectors 'other' from 'out' and stores the result in 'out'.
 *
 * @param out   - The destination vector for the subtraction result.
 * @param other - The source vector to subtract from 'out'.
 */
void vec4u8_sub(vec4uint8_t * out, vec4uint8_t * other);

/**
 * Subtracts a scalar 'scalar' from each element of the 4D uint8 vector 'out' and stores the result in 'out'.
 *
 * @param out    - The destination vector for the subtraction result.
 * @param scalar - The scalar value to subtract from each element of 'out'.
 */
void vec4u8_subS(vec4int8_t * out, uint8_t scalar);

/**
 * Subtracts each element of 4D uint8 vectors 'other' from 'out' and returns a new vector as the result.
 * The original vectors remain unchanged.
 *
 * @param out   - The destination vector for the subtraction result.
 * @param other - The source vector to subtract from 'out'.
 * @return      - A new 4D uint8 vector containing the result of the subtraction.
 */
vec4uint8_t * vec4u8_sub_r(vec4uint8_t * out, vec4uint8_t * other);

/**
 * Subtracts a scalar 'scalar' from each element of the 4D uint8 vector 'out' and returns a new vector as the result.
 * The original vector remains unchanged.
 *
 * @param out    - The destination vector for the subtraction result.
 * @param scalar - The scalar value to subtract from each element of 'out'.
 * @return       - A new 4D uint8 vector containing the result of the subtraction.
 */
vec4uint8_t * vec4u8_subS_r(vec4uint8_t * out, uint8_t scalar);


// Subtract two 4D int16_t vectors 'other' from 'out' and store the result in 'out'.
void vec4i16_sub(vec4int16_t *out, vec4int16_t *other);

// Subtract a scalar 'scalar' from each element of the 4D int16_t vector 'out' and store the result in 'out'.
void vec4i16_subS(vec4int16_t *out, int16_t scalar);

// Subtract two 4D int16_t vectors and return a new vector as the result.
vec4int16_t *vec4i16_sub_r(vec4int16_t *out, vec4int16_t *other);

// Subtract a scalar 'scalar' from each element of the 4D int16_t vector 'out' and return a new vector as the result.
vec4int16_t *vec4i16_subS_r(vec4int16_t *out, int16_t scalar);


// Subtract two 4D uint16_t vectors 'other' from 'out' and store the result in 'out'.
void vec4u16_sub(vec4uint16_t *out, vec4uint16_t *other);

// Subtract a scalar 'scalar' from each element of the 4D uint16_t vector 'out' and store the result in 'out'.
void vec4u16_subS(vec4int16_t *out, uint16_t scalar);

// Subtract two 4D uint16_t vectors and return a new vector as the result.
vec4uint16_t *vec4u16_sub_r(vec4uint16_t *out, vec4uint16_t *other);

// Subtract a scalar 'scalar' from each element of the 4D uint16_t vector 'out' and return a new vector as the result.
vec4uint16_t *vec4u16_subS_r(vec4uint16_t *out, uint16_t scalar);

// Subtract two 4D int32_t vectors 'other' from 'out' and store the result in 'out'.
void vec4i32_sub(vec4int32_t *out, vec4int32_t *other);

// Subtract a scalar 'scalar' from each element of the 4D int32_t vector 'out' and store the result in 'out'.
void vec4i32_subS(vec4int32_t *out, int32_t scalar);

// Subtract two 4D int32_t vectors and return a new vector as the result.
vec4int32_t *vec4i32_sub_r(vec4int32_t *out, vec4int32_t *other);

// Subtract a scalar 'scalar' from each element of the 4D int32_t vector 'out' and return a new vector as the result.
vec4int32_t *vec4i32_subS_r(vec4int32_t *out, int32_t scalar);


// Subtract two 4D uint32_t vectors 'other' from 'out' and store the result in 'out'.
void vec4u32_sub(vec4uint32_t *out, vec4uint32_t *other);

// Subtract a scalar 'scalar' from each element of the 4D uint32_t vector 'out' and store the result in 'out'.
void vec4u32_subS(vec4int32_t *out, uint32_t scalar);

// Subtract two 4D uint32_t vectors and return a new vector as the result.
vec4uint32_t *vec4u32_sub_r(vec4uint32_t *out, vec4uint32_t *other);

// Subtract a scalar 'scalar' from each element of the 4D uint32_t vector 'out' and return a new vector as the result.
vec4uint32_t *vec4u32_subS_r(vec4uint32_t *out, uint32_t scalar);


// Subtract two 4D int64_t vectors 'other' from 'out' and store the result in 'out'.
void vec4i64_sub(vec4int64_t *out, vec4int64_t *other);

// Subtract a scalar 'scalar' from each element of the 4D int64_t vector 'out' and store the result in 'out'.
void vec4i64_subS(vec4int64_t *out, int64_t scalar);

// Subtract two 4D int64_t vectors and return a new vector as the result.
vec4int64_t *vec4i64_sub_r(vec4int64_t *out, vec4int64_t *other);

// Subtract a scalar 'scalar' from each element of the 4D int64_t vector 'out' and return a new vector as the result.
vec4int64_t *vec4i64_subS_r(vec4int64_t *out, int64_t scalar);


// Subtract two 4D uint64_t vectors 'other' from 'out' and store the result in 'out'.
void vec4u64_sub(vec4uint64_t *out, vec4uint64_t *other);

// Subtract a scalar 'scalar' from each element of the 4D uint64_t vector 'out' and store the result in 'out'.
void vec4u64_subS(vec4int64_t *out, uint64_t scalar);

// Subtract two 4D uint64_t vectors and return a new vector as the result.
vec4uint64_t *vec4u64_sub_r(vec4uint64_t *out, vec4uint64_t *other);

// Subtract a scalar 'scalar' from each element of the 4D uint64_t vector 'out' and return a new vector as the result.
vec4uint64_t *vec4u64_subS_r(vec4uint64_t *out, uint64_t scalar);


// Subtract two 4D float vectors 'other' from 'out' and store the result in 'out'.
void vec4f_sub(vec4f_t *out, vec4f_t *other);

// Subtract a scalar 'scalar' from each element of the 4D float vector 'out' and store the result in 'out'.
void vec4f_subS(vec4f_t *out, float scalar);

// Subtract two 4D float vectors and return a new vector as the result.
vec4f_t *vec4f_sub_r(vec4f_t *out, vec4f_t *other);

// Subtract a scalar 'scalar' from each element of the 4D float vector 'out' and return a new vector as the result.
vec4f_t *vec4f_subS_r(vec4f_t *out, float scalar);


// Subtract two 4D double vectors 'other' from 'out' and store the result in 'out'.
void vec4d_sub(vec4d_t *out, vec4d_t *other);

// Subtract a scalar 'scalar' from each element of the 4D double vector 'out' and store the result in 'out'.
void vec4d_subS(vec4d_t *out, double scalar);

// Subtract two 4D double vectors and return a new vector as the result.
vec4d_t *vec4d_sub_r(vec4d_t *out, vec4d_t *other);

// Subtract a scalar 'scalar' from each element of the 4D double vector 'out' and return a new vector as the result.
vec4d_t *vec4d_subS_r(vec4d_t *out, double scalar);



// Multiply two 4D int16_t vectors 'out' and 'other' and store the result in 'out'.
void vec4i16_mult(vec4int16_t *out, vec4int16_t *other);

// Multiply a 4D int16_t vector 'out' by a scalar 'scalar' and store the result in 'out'.
void vec4i16_multS(vec4int16_t *out, int16_t scalar);

// Multiply two 4D int16_t vectors and return a new vector as the result.
vec4int16_t *vec4i16_mult_r(vec4int16_t *out, vec4int16_t *other);

// Multiply a 4D int16_t vector 'out' by a scalar 'scalar' and return a new vector as the result.
vec4int16_t *vec4i16_multS_r(vec4int16_t *out, int16_t scalar);


// Multiply two 4D uint16_t vectors 'out' and 'other' and store the result in 'out'.
void vec4u16_mult(vec4uint16_t *out, vec4uint16_t *other);

// Multiply a 4D int16_t vector 'out' by a scalar 'scalar' and store the result in 'out'.
void vec4u16_multS(vec4int16_t *out, uint16_t scalar);

// Multiply two 4D uint16_t vectors and return a new vector as the result.
vec4uint16_t *vec4u16_mult_r(vec4uint16_t *out, vec4uint16_t *other);

// Multiply a 4D uint16_t vector 'out' by a scalar 'scalar' and return a new vector as the result.
vec4uint16_t *vec4u16_multS_r(vec4uint16_t *out, uint16_t scalar);


// Multiply two 4D int32_t vectors 'out' and 'other' and store the result in 'out'.
void vec4i32_mult(vec4int32_t *out, vec4int32_t *other);

// Multiply a 4D int32_t vector 'out' by a scalar 'scalar' and store the result in 'out'.
void vec4i32_multS(vec4int32_t *out, int32_t scalar);

// Multiply two 4D int32_t vectors and return a new vector as the result.
vec4int32_t *vec4i32_mult_r(vec4int32_t *out, vec4int32_t *other);

// Multiply a 4D int32_t vector 'out' by a scalar 'scalar' and return a new vector as the result.
vec4int32_t *vec4i32_multS_r(vec4int32_t *out, int32_t scalar);


// Multiply two 4D uint32_t vectors 'out' and 'other' and store the result in 'out'.
void vec4u32_mult(vec4uint32_t *out, vec4uint32_t *other);

// Multiply a 4D int32_t vector 'out' by a scalar 'scalar' and store the result in 'out'.
void vec4u32_multS(vec4int32_t *out, uint32_t scalar);

// Multiply two 4D uint32_t vectors and return a new vector as the result.
vec4uint32_t *vec4u32_mult_r(vec4uint32_t *out, vec4uint32_t *other);

// Multiply a 4D uint32_t vector 'out' by a scalar 'scalar' and return a new vector as the result.
vec4uint32_t *vec4u32_multS_r(vec4uint32_t *out, uint32_t scalar);


// Multiply two 4D int64_t vectors 'out' and 'other' and store the result in 'out'.
void vec4i64_mult(vec4int64_t *out, vec4int64_t *other);

// Multiply a 4D int64_t vector 'out' by a scalar 'scalar' and store the result in 'out'.
void vec4i64_multS(vec4int64_t *out, int64_t scalar);

// Multiply two 4D int64_t vectors and return a new vector as the result.
vec4int64_t *vec4i64_mult_r(vec4int64_t *out, vec4int64_t *other);

// Multiply a 4D int64_t vector 'out' by a scalar 'scalar' and return a new vector as the result.
vec4int64_t *vec4i64_multS_r(vec4int64_t *out, int64_t scalar);


// Multiply two 4D uint64_t vectors 'out' and 'other' and store the result in 'out'.
void vec4u64_mult(vec4uint64_t *out, vec4uint64_t *other);

// Multiply a 4D int64_t vector 'out' by a scalar 'scalar' and store the result in 'out'.
void vec4u64_multS(vec4int64_t *out, uint64_t scalar);

// Multiply two 4D uint64_t vectors and return a new vector as the result.
vec4uint64_t *vec4u64_mult_r(vec4uint64_t *out, vec4uint64_t *other);

// Multiply a 4D uint64_t vector 'out' by a scalar 'scalar' and return a new vector as the result.
vec4uint64_t *vec4u64_multS_r(vec4uint64_t *out, uint64_t scalar);


// Multiply two 4D float vectors and store the result in 'out'.
void vec4f_mult(vec4f_t *out, vec4f_t *other);

// Multiply a 4D float vector 'out' by a scalar 'scalar' and store the result in 'out'.
void vec4f_multS(vec4f_t *out, float scalar);

// Multiply two 4D float vectors and return a new vector as the result.
vec4f_t *vec4f_mult_r(vec4f_t *out, vec4f_t *other);

// Multiply a 4D float vector 'out' by a scalar 'scalar' and return a new vector as the result.
vec4f_t *vec4f_multS_r(vec4f_t *out, float scalar);


// Multiply two 4D double vectors and store the result in 'out'.
void vec4d_mult(vec4d_t *out, vec4d_t *other);

// Multiply a 4D double vector 'out' by a scalar 'scalar' and store the result in 'out'.
void vec4d_multS(vec4d_t *out, double scalar);

// Multiply two 4D double vectors and return a new vector as the result.
vec4d_t *vec4d_mult_r(vec4d_t *out, vec4d_t *other);

// Multiply a 4D double vector 'out' by a scalar 'scalar' and return a new vector as the result.
vec4d_t *vec4d_multS_r(vec4d_t *out, double scalar);



// Get the size of a 4D vector of int8_t.
size_t vec4i8_getSize();

// Get the size of a 4D vector of uint8_t.
size_t vec4u8_getSize();

// Get the size of a 4D vector of int16_t.
size_t vec4i16_getSize();

// Get the size of a 4D vector of uint16_t.
size_t vec4u16_getSize();

// Get the size of a 4D vector of int32_t.
size_t vec4i32_getSize();

// Get the size of a 4D vector of uint32_t.
size_t vec4u32_getSize();

// Get the size of a 4D vector of int64_t.
size_t vec4i64_getSize();

// Get the size of a 4D vector of uint64_t.
size_t vec4u64_getSize();

// Get the size of a 4D vector of char.
size_t vec4c_getSize();

// Get the size of a 4D vector of float.
size_t vec4f_getSize();

// Get the size of a 4D vector of double.
size_t vec4d_getSize();



// Convert a 4D vector of int8_t to a string (the string needs to be freed).
char * vec4i8_toString(vec4int8_t * self);

// Convert a 4D vector of uint8_t to a string (the string needs to be freed).
char * vec4u8_toString(vec4uint8_t * self);

// Convert a 4D vector of int16_t to a string (the string needs to be freed).
char * vec4i16_toString(vec4int16_t * self);

// Convert a 4D vector of uint16_t to a string (the string needs to be freed).
char * vec4u16_toString(vec4uint16_t * self);

// Convert a 4D vector of int32_t to a string (the string needs to be freed).
char * vec4i32_toString(vec4int32_t * self);

// Convert a 4D vector of uint32_t to a string (the string needs to be freed).
char * vec4u32_toString(vec4uint32_t * self);

// Convert a 4D vector of int64_t to a string (the string needs to be freed).
char * vec4i64_toString(vec4int64_t * self);

// Convert a 4D vector of uint64_t to a string (the string needs to be freed).
char * vec4u64_toString(vec4uint64_t * self);

// Convert a 4D vector of char to a string (the string needs to be freed).
char * vec4c_toString(vec4char_t * self);

// Convert a 4D vector of float to a string (the string needs to be freed).
char * vec4f_toString(vec4f_t * self);

// Convert a 4D vector of double to a string (the string needs to be freed).
char * vec4d_toString(vec4d_t * self);





// Print a 4D vector of int8_t.
void printvec4i8(vec4int8_t * vec);

// Print a 4D vector of uint8_t.
void printvec4u8(vec4uint8_t * vec);

// Print a 4D vector of int16_t.
void printvec4i16(vec4int16_t * vec);

// Print a 4D vector of uint16_t.
void printvec4u16(vec4uint16_t * vec);

// Print a 4D vector of int32_t.
void printvec4i32(vec4int32_t * vec);

// Print a 4D vector of uint32_t.
void printvec4u32(vec4uint32_t * vec);

// Print a 4D vector of int64_t.
void printvec4i64(vec4int64_t * vec);

// Print a 4D vector of uint64_t.
void printvec4u64(vec4uint64_t * vec);

// Print a 4D vector of char.
void printvec4c(vec4char_t * vec);

// Print a 4D vector of float.
void printvec4f(vec4f_t * vec);

// Print a 4D vector of double.
void printvec4d(vec4d_t * vec);




#endif
