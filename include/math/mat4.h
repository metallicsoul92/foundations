#ifndef FOUNDATIONS_MATH_MATRIX4_H
#define FOUNDATIONS_MATH_MATRIX4_H

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif


typedef struct matrix4float matrix4f_t;

  #ifndef VEC4F_DEFINED
  typedef struct vector4float vec4f_t;
  #define VEC4F_DEFINED 1
  #endif


//matrix4 functions

matrix4f_t * matrix4f_mallocFromArray(float data[16]);
matrix4f_t * matrix4f_copyFromOther(matrix4f_t * copy);
matrix4f_t * matrix4f_moveFromOther(matrix4f_t * move);
matrix4f_t * matrix4f_mallocFromString(const char * str);

void matrix4f_initFromArray(matrix4f_t * self, float data[16]);
void matrix4f_initFromString(matrix4f_t * self, const char * str);

void matrix4f_free(matrix4f_t * self);

void matrix4f_setElement(matrix4f_t * self, uint8_t index, float element);

float matrix4f_ElementAt(const matrix4f_t *self, uint8_t index);
float matrix4f_getElement(matrix4f_t * self, uint8_t index);

//Using matricies
void matrix4f_add(matrix4f_t * out, matrix4f_t * other);
void matrix4f_subtract(matrix4f_t * out, matrix4f_t * other);
void matrix4f_multiply(matrix4f_t * out, matrix4f_t * other);

//Using Vectors
void matrix4f_addFromVecRow(matrix4f_t * out, vec4f_t * other);
void matrix4f_subtractFromVecRow(matrix4f_t * out, vec4f_t * other);
void matrix4f_multiplyFromVecRow(matrix4f_t * out, vec4f_t * other);

void matrix4f_addFromVecColumn(matrix4f_t * out, vec4f_t * other);
void matrix4f_subtractFromVecColumn(matrix4f_t * out, vec4f_t * other);
void matrix4f_multiplyFromVecColumn(matrix4f_t * out, vec4f_t * other);

//Using Scalars
void matrix4f_addFromScalar(matrix4f_t * out, float scalar);
void matrix4f_subtractFromScalar(matrix4f_t * out, float scalar);
void matrix4f_multiplyFromScalar(matrix4f_t * out, float scalar);

void matrix4f_invert(matrix4f_t * self);

//RETURNABLE FUNCTIONS
//Using matricies
matrix4f_t *  matrix4f_add_r(matrix4f_t * out, matrix4f_t * other);
matrix4f_t *  matrix4f_subtract_r(matrix4f_t * out, matrix4f_t * other);
matrix4f_t *  matrix4f_multiply_r(matrix4f_t * out, matrix4f_t * other);


//Using Vectors
matrix4f_t *  matrix4f_addFromVecRow_r(matrix4f_t * out, vec4f_t * other);
matrix4f_t *  matrix4f_subtractFromVecRow_r(matrix4f_t * out, vec4f_t * other);
matrix4f_t *  matrix4f_multiplyFromVecRow_r(matrix4f_t * out, vec4f_t * other);


matrix4f_t *  matrix4f_addFromVecColumn_r(matrix4f_t * out, vec4f_t * other);
matrix4f_t *  matrix4f_subtractFromVecColumn_r(matrix4f_t * out, vec4f_t * other);
matrix4f_t *  matrix4f_multiplyFromVecColumn_r(matrix4f_t * out, vec4f_t * other);


//Using Scalars
matrix4f_t *  matrix4f_addFromScalar_r(matrix4f_t * out, float scalar);
matrix4f_t *  matrix4f_subtractFromScalar_r(matrix4f_t * out, float scalar);
matrix4f_t *  matrix4f_multiplyFromScalar_r(matrix4f_t * out, float scalar);

matrix4f_t * matrix4f_invert_r(matrix4f_t * self);

char * matrix4f_toString(matrix4f_t * self);

void matrix4f_setIdentityMatrix(matrix4f_t * out);
const matrix4f_t * matrix4f_IdentityMatrix();

size_t matrix4f_size();

#endif
