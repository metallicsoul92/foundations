#ifndef FOUNDATIONS_MATH_MATRIX3_H
#define FOUNDATIONS_MATH_MATRIX3_H

// Include necessary standard headers and forward declarations.

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

// Define a structure to represent a 3x3 matrix of floating-point numbers.
typedef struct matrix3float matrix3f_t;

// Define a structure to represent a 3D vector of floating-point numbers.
#ifndef VEC3F_DEFINED
typedef struct vector3float vec3f_t;
#define VEC3F_DEFINED 1
#endif

// Function declarations

// Memory allocation and management functions

// Allocate and initialize a matrix3f_t from an array of 9 floats.
matrix3f_t *matrix3f_mallocFromArray(float data[9]);

// Create a new matrix3f_t by copying the contents of another matrix3f_t.
matrix3f_t *matrix3f_copyFromOther(matrix3f_t *copy);

// Move the contents of one matrix3f_t to create a new one.
matrix3f_t *matrix3f_moveFromOther(matrix3f_t *move);

// Allocate and initialize a matrix3f_t from a string representation.
matrix3f_t *matrix3f_mallocFromString(const char *str);

// Initialization functions

// Initialize a matrix3f_t from an array of 9 floats.
void matrix3f_initFromArray(matrix3f_t *self, float data[9]);

// Initialize a matrix3f_t from a string representation.
void matrix3f_initFromString(matrix3f_t *self, const char *str);

// Release memory allocated for a matrix3f_t.
void matrix3f_free(matrix3f_t *self);

// Element access and manipulation functions

// Set the value of an element in the matrix by index.
void matrix3f_setElement(matrix3f_t *self, uint8_t index, float element);

// Get the value of an element in the matrix by index.
float matrix3f_getElement(matrix3f_t *self, uint8_t index);

// Operations on matrices

// Add another matrix to the current matrix.
void matrix3f_add(matrix3f_t *out, matrix3f_t *other);

// Subtract another matrix from the current matrix.
void matrix3f_subtract(matrix3f_t *out, matrix3f_t *other);

// Multiply the current matrix by another matrix.
void matrix3f_multiply(matrix3f_t *out, matrix3f_t *other);

// Operations with 3D vectors

// Add a 3D vector to the current matrix row-wise.
void matrix3f_addFromVecRow(matrix3f_t *out, vec3f_t *other);

// Subtract a 3D vector from the current matrix row-wise.
void matrix3f_subtractFromVecRow(matrix3f_t *out, vec3f_t *other);

// Multiply the current matrix row-wise by a 3D vector.
void matrix3f_multiplyFromVecRow(matrix3f_t *out, vec3f_t *other);

// Add a 3D vector to the current matrix column-wise.
void matrix3f_addFromVecColumn(matrix3f_t *out, vec3f_t *other);

// Subtract a 3D vector from the current matrix column-wise.
void matrix3f_subtractFromVecColumn(matrix3f_t *out, vec3f_t *other);

// Multiply the current matrix column-wise by a 3D vector.
void matrix3f_multiplyFromVecColumn(matrix3f_t *out, vec3f_t *other);

// Operations with scalar values

// Add a scalar value to all elements of the current matrix.
void matrix3f_addFromScalar(matrix3f_t *out, float scalar);

// Subtract a scalar value from all elements of the current matrix.
void matrix3f_subtractFromScalar(matrix3f_t *out, float scalar);

// Multiply all elements of the current matrix by a scalar value.
void matrix3f_multiplyFromScalar(matrix3f_t *out, float scalar);

// Invert the current matrix in-place.
void matrix3f_invert(matrix3f_t *self);

// Returnable functions

// Operations on matrices (returning a result matrix)

// Add two matrices and return the result as a new matrix.
matrix3f_t *matrix3f_add_r(matrix3f_t *out, matrix3f_t *other);

// Subtract one matrix from another and return the result as a new matrix.
matrix3f_t *matrix3f_subtract_r(matrix3f_t *out, matrix3f_t *other);

// Multiply two matrices and return the result as a new matrix.
matrix3f_t *matrix3f_multiply_r(matrix3f_t *out, matrix3f_t *other);

// Operations with 3D vectors (returning a result matrix)

// Add a 3D vector to the current matrix row-wise and return the result as a new matrix.
matrix3f_t *matrix3f_addFromVecRow_r(matrix3f_t *out, vec3f_t *other);

// Subtract a 3D vector from the current matrix row-wise and return the result as a new matrix.
matrix3f_t *matrix3f_subtractFromVecRow_r(matrix3f_t *out, vec3f_t *other);

// Multiply the current matrix row-wise by a 3D vector and return the result as a new matrix.
matrix3f_t *matrix3f_multiplyFromVecRow_r(matrix3f_t *out, vec3f_t *other);

// Add a 3D vector to the current matrix column-wise and return the result as a new matrix.
matrix3f_t *matrix3f_addFromVecColumn_r(matrix3f_t *out, vec3f_t *other);

// Subtract a 3D vector from the current matrix column-wise and return the result as a new matrix.
matrix3f_t *matrix3f_subtractFromVecColumn_r(matrix3f_t *out, vec3f_t *other);

// Multiply the current matrix column-wise by a 3D vector and return the result as a new matrix.
matrix3f_t *matrix3f_multiplyFromVecColumn_r(matrix3f_t *out, vec3f_t *other);

// Operations with scalar values (returning a result matrix)

// Add a scalar value to all elements of the current matrix and return the result as a new matrix.
matrix3f_t *matrix3f_addFromScalar_r(matrix3f_t *out, float scalar);

// Subtract a scalar value from all elements of the current matrix and return the result as a new matrix.
matrix3f_t *matrix3f_subtractFromScalar_r(matrix3f_t *out, float scalar);

// Multiply all elements of the current matrix by a scalar value and return the result as a new matrix.
matrix3f_t *matrix3f_multiplyFromScalar_r(matrix3f_t *out, float scalar);

// Invert the current matrix and return the result as a new matrix.
matrix3f_t *matrix3f_invert_r(matrix3f_t *self);

// Convert a matrix to a string representation.
char *matrix3f_toString(matrix3f_t *self);

// Set the current matrix to an identity matrix (ones on the diagonal, zeros elsewhere).
void matrix3f_setIdentityMatrix(matrix3f_t *out);

// Return a pointer to a constant identity matrix (read-only).
const matrix3f_t *matrix3f_IdentityMatrix();

// Get the size of the matrix3f_t structure (likely the number of bytes it occupies).
size_t matrix3f_size();

#endif
