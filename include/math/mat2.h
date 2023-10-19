#ifndef FOUNDATIONS_MATH_MATRIX2_H
#define FOUNDATIONS_MATH_MATRIX2_H

// Standard header for size_t
#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

// Standard header for fixed-size integer types
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

// Define a structure to represent a 2x2 matrix of floating-point numbers.
typedef struct matrix2float matrix2f_t;

// Define a structure to represent a 2D vector of floating-point numbers.
typedef struct vector2float vec2f_t;

// Function declarations

// Memory allocation and management functions

// Allocate and initialize a matrix2f_t from an array of 4 floats.
matrix2f_t *matrix2f_mallocFromArray(float data[4]);

// Create a new matrix2f_t by copying the contents of another matrix2f_t.
matrix2f_t *matrix2f_copyFromOther(matrix2f_t *copy);

// Move the contents of one matrix2f_t to create a new one.
matrix2f_t *matrix2f_moveFromOther(matrix2f_t *move);

// Allocate and initialize a matrix2f_t from a string representation.
matrix2f_t *matrix2f_mallocFromString(const char *str);

// Initialization functions

// Initialize a matrix2f_t from an array of 4 floats.
void matrix2f_initFromArray(matrix2f_t *self, float data[4]);

// Initialize a matrix2f_t from a string representation.
void matrix2f_initFromString(matrix2f_t *self, const char *str);

// Release memory allocated for a matrix2f_t.
void matrix2f_free(matrix2f_t *self);

// Element access and manipulation functions

// Set the value of an element in the matrix by index.
void matrix2f_setElement(matrix2f_t *self, uint8_t index, float element);

// Get the value of an element in the matrix by index.
float matrix2f_getElement(matrix2f_t *self, uint8_t index);

// Operations on matrices

// Add another matrix to the current matrix.
void matrix2f_add(matrix2f_t *out, matrix2f_t *other);

// Subtract another matrix from the current matrix.
void matrix2f_subtract(matrix2f_t *out, matrix2f_t *other);

// Multiply the current matrix by another matrix.
void matrix2f_multiply(matrix2f_t *out, matrix2f_t *other);

// Divide the current matrix by another matrix.
void matrix2f_divide(matrix2f_t *out, matrix2f_t *other);

// Operations with 2D vectors

// Add a 2D vector to the current matrix row-wise.
void matrix2f_addFromVecRow(matrix2f_t *out, vec2f_t *other);

// Subtract a 2D vector from the current matrix row-wise.
void matrix2f_subtractFromVecRow(matrix2f_t *out, vec2f_t *other);

// Multiply the current matrix row-wise by a 2D vector.
void matrix2f_multiplyFromVecRow(matrix2f_t *out, vec2f_t *other);

// Add a 2D vector to the current matrix column-wise.
void matrix2f_addFromVecColumn(matrix2f_t *out, vec2f_t *other);

// Subtract a 2D vector from the current matrix column-wise.
void matrix2f_subtractFromVecColumn(matrix2f_t *out, vec2f_t *other);

// Multiply the current matrix column-wise by a 2D vector.
void matrix2f_multiplyFromVecColumn(matrix2f_t *out, vec2f_t *other);

// Operations with scalar values

// Add a scalar value to all elements of the current matrix.
void matrix2f_addFromScalar(matrix2f_t *out, float scalar);

// Subtract a scalar value from all elements of the current matrix.
void matrix2f_subtractFromScalar(matrix2f_t *out, float scalar);

// Multiply all elements of the current matrix by a scalar value.
void matrix2f_multiplyFromScalar(matrix2f_t *out, float scalar);

// Divide all elements of the current matrix by a scalar value.
void matrix2f_divideFromScalar(matrix2f_t *out, float scalar);

// Invert the current matrix in-place.
void matrix2f_invert(matrix2f_t *self);

// Returnable functions

// Operations on matrices (returning a result matrix)

// Add two matrices and return the result as a new matrix.
matrix2f_t *matrix2f_add_r(matrix2f_t *out, matrix2f_t *other);

// Subtract one matrix from another and return the result as a new matrix.
matrix2f_t *matrix2f_subtract_r(matrix2f_t *out, matrix2f_t *other);

// Multiply two matrices and return the result as a new matrix.
matrix2f_t *matrix2f_multiply_r(matrix2f_t *out, matrix2f_t *other);

// Operations with 2D vectors (returning a result matrix)

// Add a 2D vector to the current matrix row-wise and return the result as a new matrix.
matrix2f_t *matrix2f_addFromVecRow_r(matrix2f_t *out, vec2f_t *other);

// Subtract a 2D vector from the current matrix row-wise and return the result as a new matrix.
matrix2f_t *matrix2f_subtractFromVecRow_r(matrix2f_t *out, vec2f_t *other);

// Multiply the current matrix row-wise by a 2D vector and return the result as a new matrix.
matrix2f_t *matrix2f_multiplyFromVecRow_r(matrix2f_t *out, vec2f_t *other);

// Add a 2D vector to the current matrix column-wise and return the result as a new matrix.
matrix2f_t *matrix2f_addFromVecColumn_r(matrix2f_t *out, vec2f_t *other);

// Subtract a 2D vector from the current matrix column-wise and return the result as a new matrix.
matrix2f_t *matrix2f_subtractFromVecColumn_r(matrix2f_t *out, vec2f_t *other);

// Multiply the current matrix column-wise by a 2D vector and return the result as a new matrix.
matrix2f_t *matrix2f_multiplyFromVecColumn_r(matrix2f_t *out, vec2f_t *other);

// Operations with scalar values (returning a result matrix)

// Add a scalar value to all elements of the current matrix and return the result as a new matrix.
matrix2f_t *matrix2f_addFromScalar_r(matrix2f_t *out, float scalar);

// Subtract a scalar value from all elements of the current matrix and return the result as a new matrix.
matrix2f_t *matrix2f_subtractFromScalar_r(matrix2f_t *out, float scalar);

// Multiply all elements of the current matrix by a scalar value and return the result as a new matrix.
matrix2f_t *matrix2f_multiplyFromScalar_r(matrix2f_t *out, float scalar);

// Invert the current matrix and return the result as a new matrix.
matrix2f_t *matrix2f_invert_r(matrix2f_t *self);

// Convert a matrix to a string representation.
char *matrix2f_toString(matrix2f_t *self);

// Set the current matrix to an identity matrix (ones on the diagonal, zeros elsewhere).
void matrix2f_setIdentityMatrix(matrix2f_t *out);

// Return a pointer to a constant identity matrix (read-only).
const matrix2f_t *matrix2f_IdentityMatrix();

// Get the size of the matrix2f_t structure (likely the number of bytes it occupies).
size_t matrix2f_size();

#endif
