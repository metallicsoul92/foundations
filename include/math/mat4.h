#ifndef FOUNDATIONS_MATH_MATRIX4_H
#define FOUNDATIONS_MATH_MATRIX4_H

// Include necessary standard headers and forward declarations.

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

// Define a structure to represent a 4x4 matrix of floating-point numbers.
typedef struct matrix4float matrix4f_t;

// Define a structure to represent a 4D vector of floating-point numbers.
#ifndef VEC4F_DEFINED
typedef struct vector4float vec4f_t;
#define VEC4F_DEFINED 1
#endif

// Function declarations

// Memory allocation and management functions

// Allocate and initialize a matrix4f_t from an array of 16 floats.
matrix4f_t *matrix4f_mallocFromArray(float data[16]);

// Create a new matrix4f_t by copying the contents of another matrix4f_t.
matrix4f_t *matrix4f_copyFromOther(matrix4f_t *copy);

// Move the contents of one matrix4f_t to create a new one.
matrix4f_t *matrix4f_moveFromOther(matrix4f_t *move);

// Allocate and initialize a matrix4f_t from a string representation.
matrix4f_t *matrix4f_mallocFromString(const char *str);

// Initialization functions

// Initialize a matrix4f_t from an array of 16 floats.
void matrix4f_initFromArray(matrix4f_t *self, float data[16]);

// Initialize a matrix4f_t from a string representation.
void matrix4f_initFromString(matrix4f_t *self, const char *str);

// Release memory allocated for a matrix4f_t.
void matrix4f_free(matrix4f_t *self);

// Element access and manipulation functions

// Set the value of an element in the matrix by index.
void matrix4f_setElement(matrix4f_t *self, uint8_t index, float element);

// Get the value of an element in the matrix by index.
float matrix4f_getElement(matrix4f_t *self, uint8_t index);

// Operations on matrices

// Add another matrix to the current matrix.
void matrix4f_add(matrix4f_t *out, matrix4f_t *other);

// Subtract another matrix from the current matrix.
void matrix4f_subtract(matrix4f_t *out, matrix4f_t *other);

// Multiply the current matrix by another matrix.
void matrix4f_multiply(matrix4f_t *out, matrix4f_t *other);

// Operations with 4D vectors

// Add a 4D vector to the current matrix row-wise.
void matrix4f_addFromVecRow(matrix4f_t *out, vec4f_t *other);

// Subtract a 4D vector from the current matrix row-wise.
void matrix4f_subtractFromVecRow(matrix4f_t *out, vec4f_t *other);

// Multiply the current matrix row-wise by a 4D vector.
void matrix4f_multiplyFromVecRow(matrix4f_t *out, vec4f_t *other);

// Add a 4D vector to the current matrix column-wise.
void matrix4f_addFromVecColumn(matrix4f_t *out, vec4f_t *other);

// Subtract a 4D vector from the current matrix column-wise.
void matrix4f_subtractFromVecColumn(matrix4f_t *out, vec4f_t *other);

// Multiply the current matrix column-wise by a 4D vector.
void matrix4f_multiplyFromVecColumn(matrix4f_t *out, vec4f_t *other);

// Operations with scalar values

// Add a scalar value to all elements of the current matrix.
void matrix4f_addFromScalar(matrix4f_t *out, float scalar);

// Subtract a scalar value from all elements of the current matrix.
void matrix4f_subtractFromScalar(matrix4f_t *out, float scalar);

// Multiply all elements of the current matrix by a scalar value.
void matrix4f_multiplyFromScalar(matrix4f_t *out, float scalar);

// Invert the current matrix in-place.
void matrix4f_invert(matrix4f_t *self);

// Returnable functions

// Operations on matrices (returning a result matrix)

// Add two matrices and return the result as a new matrix.
matrix4f_t *matrix4f_add_r(matrix4f_t *out, matrix4f_t *other);

// Subtract one matrix from another and return the result as a new matrix.
matrix4f_t *matrix4f_subtract_r(matrix4f_t *out, matrix4f_t *other);

// Multiply two matrices and return the result as a new matrix.
matrix4f_t *matrix4f_multiply_r(matrix4f_t *out, matrix4f_t *other);

// Operations with 4D vectors (returning a result matrix)

// Add a 4D vector to the current matrix row-wise and return the result as a new matrix.
matrix4f_t *matrix4f_addFromVecRow_r(matrix4f_t *out, vec4f_t *other);

// Subtract a 4D vector from the current matrix row-wise and return the result as a new matrix.
matrix4f_t *matrix4f_subtractFromVecRow_r(matrix4f_t *out, vec4f_t *other);

// Multiply the current matrix row-wise by a 4D vector and return the result as a new matrix.
matrix4f_t *matrix4f_multiplyFromVecRow_r(matrix4f_t *out, vec4f_t *other);

// Add a 4D vector to the current matrix column-wise and return the result as a new matrix.
matrix4f_t *matrix4f_addFromVecColumn_r(matrix4f_t *out, vec4f_t *other);

// Subtract a 4D vector from the current matrix column-wise and return the result as a new matrix.
matrix4f_t *matrix4f_subtractFromVecColumn_r(matrix4f_t *out, vec4f_t *other);

// Multiply the current matrix column-wise by a 4D vector and return the result as a new matrix.
matrix4f_t *matrix4f_multiplyFromVecColumn_r(matrix4f_t *out, vec4f_t *other);

// Operations with scalar values (returning a result matrix)

// Add a scalar value to all elements of the current matrix and return the result as a new matrix.
matrix4f_t *matrix4f_addFromScalar_r(matrix4f_t *out, float scalar);

// Subtract a scalar value from all elements of the current matrix and return the result as a new matrix.
matrix4f_t *matrix4f_subtractFromScalar_r(matrix4f_t *out, float scalar);

// Multiply all elements of the current matrix by a scalar value and return the result as a new matrix.
matrix4f_t *matrix4f_multiplyFromScalar_r(matrix4f_t *out, float scalar);

// Invert the current matrix and return the result as a new matrix.
matrix4f_t *matrix4f_invert_r(matrix4f_t *self);

// Convert a matrix to a string representation.
char *matrix4f_toString(matrix4f_t *self);

// Set the current matrix to an identity matrix (ones on the diagonal, zeros elsewhere).
void matrix4f_setIdentityMatrix(matrix4f_t *out);

// Return a pointer to a constant identity matrix (read-only).
const matrix4f_t *matrix4f_IdentityMatrix();

// Get the size of the matrix4f_t structure (likely the number of bytes it occupies).
size_t matrix4f_size();

#endif
