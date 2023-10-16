#ifndef FOUNDATIONS_MATH_MATRIX2_H
#define FOUNDATIONS_MATH_MATRIX2_H

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

typedef struct matrix2float matrix2f_t;

  #ifndef VEC2F_DEFINED
  typedef struct vector2float vec2f_t;
  #define VEC2F_DEFINED 1
  #endif


//matrix2 functions

//allocation
matrix2f_t * matrix2f_mallocFromArray(float data[4]);
matrix2f_t * matrix2f_copyFromOther(matrix2f_t * copy);
matrix2f_t * matrix2f_moveFromOther(matrix2f_t * move);
matrix2f_t * matrix2f_mallocFromString(const char * str);

//initializing
void matrix2f_initFromArray(matrix2f_t * self, float data[4]);
void matrix2f_initFromString(matrix2f_t * self, const char * str);
//destroying
void matrix2f_free(matrix2f_t * self);

//Setting elements
void matrix2f_setElement(matrix2f_t * self, uint8_t index, float element);

//maybe overthinking, but const compatible? or atleast
//used like a const.
const float matrix2f_ElementAt(const matrix2f_t *self, uint8_t index);

float matrix2f_getElement(matrix2f_t * self, uint8_t index);

//Using matricies
void matrix2f_add(matrix2f_t * out, matrix2f_t * other);
void matrix2f_subtract(matrix2f_t * out, matrix2f_t * other);
void matrix2f_multiply(matrix2f_t * out, matrix2f_t * other);
void matrix2f_divide(matrix2f_t * out, matrix2f_t * other);

//Using Vectors
void matrix2f_addFromVecRow(matrix2f_t * out, vec2f_t * other);
void matrix2f_subtractFromVecRow(matrix2f_t * out, vec2f_t * other);
void matrix2f_multiplyFromVecRow(matrix2f_t * out, vec2f_t * other);

void matrix2f_addFromVecColumn(matrix2f_t * out, vec2f_t * other);
void matrix2f_subtractFromVecColumn(matrix2f_t * out, vec2f_t * other);
void matrix2f_multiplyFromVecColumn(matrix2f_t * out, vec2f_t * other);
//Using Scalars
void matrix2f_addFromScalar(matrix2f_t * out, float scalar);
void matrix2f_subtractFromScalar(matrix2f_t * out, float scalar);
void matrix2f_multiplyFromScalar(matrix2f_t * out, float scalar);
void matrix2f_divideFromScalar(matrix2f_t * out, float scalar);

void matrix2f_invert(matrix2f_t * self);


//RETURNABLE FUNCTIONS
//Using matricies
matrix2f_t *  matrix2f_add_r(matrix2f_t * out, matrix2f_t * other);
matrix2f_t *  matrix2f_subtract_r(matrix2f_t * out, matrix2f_t * other);
matrix2f_t *  matrix2f_multiply_r(matrix2f_t * out, matrix2f_t * other);


//Using Vectors
matrix2f_t * matrix2f_addFromVecRow_r(matrix2f_t * out, vec2f_t * other);
matrix2f_t * matrix2f_subtractFromVecRow_r(matrix2f_t * out, vec2f_t * other);
matrix2f_t * matrix2f_multiplyFromVecRow_r(matrix2f_t * out, vec2f_t * other);

matrix2f_t * matrix2f_addFromVecColumn_r(matrix2f_t * out, vec2f_t * other);
matrix2f_t * matrix2f_subtractFromVecColumn_r(matrix2f_t * out, vec2f_t * other);
matrix2f_t * matrix2f_multiplyFromVecColumn_r(matrix2f_t * out, vec2f_t * other);

//Using Scalars
matrix2f_t *  matrix2f_addFromScalar_r(matrix2f_t * out, float scalar);
matrix2f_t *  matrix2f_subtractFromScalar_r(matrix2f_t * out, float scalar);
matrix2f_t *  matrix2f_multiplyFromScalar_r(matrix2f_t * out, float scalar);

matrix2f_t * matrix2f_invert_r(matrix2f_t * self);

char * matrix2f_toString(matrix2f_t * self);


void matrix2f_setIdentityMatrix(matrix2f_t * out);

const matrix2f_t * matrix2f_IdentityMatrix();

size_t matrix2f_size();

#endif
