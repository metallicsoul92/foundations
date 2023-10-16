#ifndef FOUNDATIONS_MATH_MATRIX3_H
#define FOUNDATIONS_MATH_MATRIX3_H

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif


typedef struct matrix3float matrix3f_t;



  #ifndef VEC3F_DEFINED
  typedef struct vector3float vec3f_t;
  #define VEC3F_DEFINED 1
  #endif

//matrix3 functions

matrix3f_t * matrix3f_mallocFromArray(float data[9]);
matrix3f_t * matrix3f_copyFromOther(matrix3f_t * copy);
matrix3f_t * matrix3f_moveFromOther(matrix3f_t * move);
matrix3f_t * matrix3f_mallocFromString(const char * str);

void matrix3f_initFromArray(matrix3f_t * self, float data[9]);
void matrix3f_initFromString(matrix3f_t * self, const char * str);


void matrix3f_free(matrix3f_t * self);


void matrix3f_setElement(matrix3f_t * self, uint8_t index, float element);


float matrix3f_ElementAt(const matrix3f_t *self, uint8_t index);

float matrix3f_getElement(matrix3f_t * self, uint8_t index);

//Using matricies
void matrix3f_add(matrix3f_t * out, matrix3f_t * other);
void matrix3f_subtract(matrix3f_t * out, matrix3f_t * other);
void matrix3f_multiply(matrix3f_t * out, matrix3f_t * other);

//Using Vectors
void matrix3f_addFromVecRow(matrix3f_t * out, vec3f_t * other);
void matrix3f_subtractFromVecRow(matrix3f_t * out, vec3f_t * other);
void matrix3f_multiplyFromVecRow(matrix3f_t * out, vec3f_t * other);

void matrix3f_addFromVecColumn(matrix3f_t * out, vec3f_t * other);
void matrix3f_subtractFromVecColumn(matrix3f_t * out, vec3f_t * other);
void matrix3f_multiplyFromVecColumn(matrix3f_t * out, vec3f_t * other);

//Using Scalars
void matrix3f_addFromScalar(matrix3f_t * out, float scalar);
void matrix3f_subtractFromScalar(matrix3f_t * out, float scalar);
void matrix3f_multiplyFromScalar(matrix3f_t * out, float scalar);

void matrix3f_invert(matrix3f_t * self);

//RETURNABLE FUNCTIONS
//Using matricies
matrix3f_t *  matrix3f_add_r(matrix3f_t * out, matrix3f_t * other);
matrix3f_t *  matrix3f_subtract_r(matrix3f_t * out, matrix3f_t * other);
matrix3f_t *  matrix3f_multiply_r(matrix3f_t * out, matrix3f_t * other);


//Using Vectors
matrix3f_t *  matrix3f_addFromVecRow_r(matrix3f_t * out, vec3f_t * other);
matrix3f_t *  matrix3f_subtractFromVecRow_r(matrix3f_t * out, vec3f_t * other);
matrix3f_t *  matrix3f_multiplyFromVecRow_r(matrix3f_t * out, vec3f_t * other);


matrix3f_t *  matrix3f_addFromVecColumn_r(matrix3f_t * out, vec3f_t * other);
matrix3f_t *  matrix3f_subtractFromVecColumn_r(matrix3f_t * out, vec3f_t * other);
matrix3f_t *  matrix3f_multiplyFromVecColumn_r(matrix3f_t * out, vec3f_t * other);


//Using Scalars
matrix3f_t *  matrix3f_addFromScalar_r(matrix3f_t * out, float scalar);
matrix3f_t *  matrix3f_subtractFromScalar_r(matrix3f_t * out, float scalar);
matrix3f_t *  matrix3f_multiplyFromScalar_r(matrix3f_t * out, float scalar);

matrix3f_t *  matrix3f_invert_r(matrix3f_t * self);

char * matrix3f_toString(matrix3f_t * self);

void matrix3f_setIdentityMatrix(matrix3f_t * out);

const matrix3f_t * matrix3f_IdentityMatrix();

size_t matrix3f_size();


#endif
