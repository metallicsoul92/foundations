#include "../../include/math/mat4.h"
#include "../../include/math/vec4.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct matrix4float{
	float _data[16];
};

//Constant structures
const matrix4f_t identity = {{1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f}};


//matrix3 functions

//allocation
matrix4f_t * matrix4f_mallocFromArray(float data[16]){
	matrix4f_t * out = malloc(sizeof(matrix4f_t));
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] = data[i];
}
	return out;
}
matrix4f_t * matrix4f_copyFromOther(matrix4f_t * copy){
	matrix4f_t * out = malloc(sizeof(matrix4f_t));
	memcpy(out->_data,copy->_data,sizeof(float) * 16);
	return out;
}

matrix4f_t * matrix4f_moveFromOther(matrix4f_t * move){
	matrix4f_t * out = malloc(sizeof(matrix4f_t));
	memmove(out->_data,move->_data,sizeof(float) * 16);
	return out;
}

matrix4f_t * matrix4f_mallocFromString(const char * str){
	matrix4f_t * out = malloc(sizeof(matrix4f_t));
	if(out !=NULL){
	sscanf(str,"[ %f , %f , %f , %f]\n[ %f , %f , %f , %f]\n[ %f , %f , %f , %f]\n[ %f , %f , %f , %f]\n" ,
				  &out->_data[0] ,&out->_data[1],&out->_data[2] ,&out->_data[3], &out->_data[4],
				 &out->_data[5] ,&out->_data[6],&out->_data[7] ,&out->_data[8],&out->_data[9] ,
				  &out->_data[10], &out->_data[11],&out->_data[12] ,&out->_data[13],&out->_data[14] ,&out->_data[15]);
					}
	return out;
}

//initializing
void matrix4f_initFromArray(matrix4f_t * self, float data[16]){
	for(uint8_t i = 0; i < 16; i++){
		self->_data[i] = data[i];
}
}

void matrix4f_initFromString(matrix4f_t * self, const char * str){
	sscanf(str,"[ %f , %f , %f , %f]\n[ %f , %f , %f , %f]\n[ %f , %f , %f , %f]\n[ %f , %f , %f , %f]\n" ,
				  &self->_data[0] ,&self->_data[1],&self->_data[2] ,&self->_data[3], &self->_data[4],
				  &self->_data[5] ,&self->_data[6],&self->_data[7] ,&self->_data[8],&self->_data[9] ,
				  &self->_data[10], &self->_data[11],&self->_data[12] ,&self->_data[13],&self->_data[14] ,&self->_data[15]);
}

//destroying
void matrix4f_free(matrix4f_t * self){
	free(self);
}

//Setting elements
void matrix4f_setElement(matrix4f_t * self, uint8_t index, float element){
	if(index < 16){
	self->_data[index] = element;
	}
}

//maybe overthinking, but const compatible? or atleast
//used like a const.
const float matrix4f_ElementAt(const matrix4f_t *self, uint8_t index){
	if(index < 16){
	return self->_data[index];
	}
	else
		return (const float)NAN;
}

float matrix4f_getElement(matrix4f_t * self, uint8_t index){
	if(index < 16){
	return self->_data[index];
	}else
		return NAN;
}


//Using matricies
void matrix4f_add(matrix4f_t * out, matrix4f_t * other){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] += other->_data[i];
}
}
void matrix4f_subtract(matrix4f_t * out, matrix4f_t * other){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] -= other->_data[i];
}
}
void matrix4f_multiply(matrix4f_t * out, matrix4f_t * other){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] *= other->_data[i];
}
}


//Using Vectors
void matrix4f_addFromVecRow(matrix4f_t * out, vec4f_t * other){
	out->_data[0] += vec4f_X(other);
	out->_data[1] += vec4f_Y(other);
	out->_data[2] += vec4f_Z(other);
	out->_data[3] += vec4f_W(other);
	out->_data[4] += vec4f_X(other);
	out->_data[5] += vec4f_Y(other);
	out->_data[6] += vec4f_Z(other);
	out->_data[7] += vec4f_W(other);
	out->_data[8] += vec4f_X(other);
	out->_data[9] += vec4f_Y(other);
	out->_data[10] += vec4f_Z(other);
	out->_data[11] += vec4f_W(other);
	out->_data[12] += vec4f_X(other);
	out->_data[13] += vec4f_Y(other);
	out->_data[14] += vec4f_Z(other);
	out->_data[15] += vec4f_W(other);
}
void matrix4f_subtractFromVecRow(matrix4f_t * out, vec4f_t * other){
	out->_data[0] -= vec4f_X(other);
	out->_data[1] -= vec4f_Y(other);
	out->_data[2] -= vec4f_Z(other);
	out->_data[3] -= vec4f_W(other);
	out->_data[4] -= vec4f_X(other);
	out->_data[5] -= vec4f_Y(other);
	out->_data[6] -= vec4f_Z(other);
	out->_data[7] -= vec4f_W(other);
	out->_data[8] -= vec4f_X(other);
	out->_data[9] -= vec4f_Y(other);
	out->_data[10] -= vec4f_Z(other);
	out->_data[11] -= vec4f_W(other);
	out->_data[12] -= vec4f_X(other);
	out->_data[13] -= vec4f_Y(other);
	out->_data[14] -= vec4f_Z(other);
	out->_data[15] -= vec4f_W(other);

}
void matrix4f_multiplyFromVecRow(matrix4f_t * out, vec4f_t * other){
	out->_data[0] *= vec4f_X(other);
	out->_data[1] *= vec4f_Y(other);
	out->_data[2] *= vec4f_Z(other);
	out->_data[3] *= vec4f_W(other);
	out->_data[4] *= vec4f_X(other);
	out->_data[5] *= vec4f_Y(other);
	out->_data[6] *= vec4f_Z(other);
	out->_data[7] *= vec4f_W(other);
	out->_data[8] *= vec4f_X(other);
	out->_data[9] *= vec4f_Y(other);
	out->_data[10] *= vec4f_Z(other);
	out->_data[11] *= vec4f_W(other);
	out->_data[12] *= vec4f_X(other);
	out->_data[13] *= vec4f_Y(other);
	out->_data[14] *= vec4f_Z(other);
	out->_data[15] *= vec4f_W(other);

}

void matrix4f_addFromVecColumn(matrix4f_t * out, vec4f_t * other){
	out->_data[0] += vec4f_X(other);
	out->_data[1] += vec4f_X(other);
	out->_data[2] += vec4f_X(other);
	out->_data[3] += vec4f_X(other);
	out->_data[4] += vec4f_Y(other);
	out->_data[5] += vec4f_Y(other);
	out->_data[6] += vec4f_Y(other);
	out->_data[7] += vec4f_Y(other);
	out->_data[8] += vec4f_Z(other);
	out->_data[9] += vec4f_Z(other);
	out->_data[10] += vec4f_Z(other);
	out->_data[11] += vec4f_Z(other);
	out->_data[12] += vec4f_W(other);
	out->_data[13] += vec4f_W(other);
	out->_data[14] += vec4f_W(other);
	out->_data[15] += vec4f_W(other);
}
void matrix4f_subtractFromVecColumn(matrix4f_t * out, vec4f_t * other){
	out->_data[0] -= vec4f_X(other);
	out->_data[1] -= vec4f_X(other);
	out->_data[2] -= vec4f_X(other);
	out->_data[3] -= vec4f_X(other);
	out->_data[4] -= vec4f_Y(other);
	out->_data[5] -= vec4f_Y(other);
	out->_data[6] -= vec4f_Y(other);
	out->_data[7] -= vec4f_Y(other);
	out->_data[8] -= vec4f_Z(other);
	out->_data[9] -= vec4f_Z(other);
	out->_data[10] -= vec4f_Z(other);
	out->_data[11] -= vec4f_Z(other);
	out->_data[12] -= vec4f_W(other);
	out->_data[13] -= vec4f_W(other);
	out->_data[14] -= vec4f_W(other);
	out->_data[15] -= vec4f_W(other);
}
void matrix4f_multiplyFromVecColumn(matrix4f_t * out, vec4f_t * other){
	out->_data[0] *= vec4f_X(other);
	out->_data[1] *= vec4f_X(other);
	out->_data[2] *= vec4f_X(other);
	out->_data[3] *= vec4f_X(other);
	out->_data[4] *= vec4f_Y(other);
	out->_data[5] *= vec4f_Y(other);
	out->_data[6] *= vec4f_Y(other);
	out->_data[7] *= vec4f_Y(other);
	out->_data[8] *= vec4f_Z(other);
	out->_data[9] *= vec4f_Z(other);
	out->_data[10] *= vec4f_Z(other);
	out->_data[11] *= vec4f_Z(other);
	out->_data[12] *= vec4f_W(other);
	out->_data[13] *= vec4f_W(other);
	out->_data[14] *= vec4f_W(other);
	out->_data[15] *= vec4f_W(other);
}

//Using Scalars
void matrix4f_addFromScalar(matrix4f_t * out, float scalar){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] += scalar;
}
}
void matrix4f_subtractFromScalar(matrix4f_t * out, float scalar){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] -= scalar;
}
}
void matrix4f_multiplyFromScalar(matrix4f_t * out, float scalar){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] *= scalar;
}
}


// Implement LU decomposition
void matrix4f_LU_decomposition(matrix4f_t * A, matrix4f_t * L, matrix4f_t * U) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // Calculate L and U elements for row i and column j
            if (i <= j) {
                // U elements
                float sum = 0.0;
                for (int k = 0; k < i; k++) {
                    sum += L->_data[i * 4 + k] * U->_data[k * 4 + j];
                }
                U->_data[i * 4 + j] = A->_data[i * 4 + j] - sum;
            } else {
                // L elements
                float sum = 0.0;
                for (int k = 0; k < j; k++) {
                    sum += L->_data[i * 4 + k] * U->_data[k * 4 + j];
                }
                L->_data[i * 4 + j] = (A->_data[i * 4 + j] - sum) / U->_data[j * 4 + j];
            }
        }
    }
}

// Implement back-substitution to calculate the inverse
void matrix4f_back_substitution(matrix4f_t * L, matrix4f_t * U, matrix4f_t * I) {
    // Initialize the identity matrix I as the inverse
    for (int i = 0; i < 16; i++) {
        I->_data[i] = 0.0f;
    }
    for (int i = 0; i < 4; i++) {
        I->_data[i * 5] = 1.0f;  // Set the diagonal elements to 1
    }

    // Solve for the inverse by back-substitution
    for (int col = 0; col < 4; col++) {
        // Forward substitution to solve Ly = Iy
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < i; j++) {
                I->_data[i * 4 + col] -= L->_data[i * 4 + j] * I->_data[j * 4 + col];
            }
        }

        // Backward substitution to solve Ux = y
        for (int i = 3; i >= 0; i--) {
            for (int j = i + 1; j < 4; j++) {
                I->_data[i * 4 + col] -= U->_data[i * 4 + j] * I->_data[j * 4 + col];
            }
            I->_data[i * 4 + col] /= U->_data[i * 4 + i];
        }
    }
}


// Function to invert a 4x4 matrix
void matrix4f_invert(matrix4f_t * self) {
    matrix4f_t L, U, I;

    // Perform LU decomposition
    matrix4f_LU_decomposition(self, &L, &U);

    // Perform back-substitution to calculate the inverse
    matrix4f_back_substitution(&L, &U, &I);

    // Copy the inverse matrix I back to the original matrix self
    memcpy(self->_data, I._data, sizeof(float) * 16);
}



//RETURNABLE FUNCTIONS
//Using matricies
matrix4f_t *  matrix4f_add_r(matrix4f_t * out, matrix4f_t * other){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] += other->_data[i];
}
	return out;
}
matrix4f_t *  matrix4f_subtract_r(matrix4f_t * out, matrix4f_t * other){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] -= other->_data[i];
}
	return out;
}
matrix4f_t *  matrix4f_multiply_r(matrix4f_t * out, matrix4f_t * other){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] *= other->_data[i];
}
	return out;
}


//Using Vectors
matrix4f_t * matrix4f_addFromVecRow_r(matrix4f_t * out, vec4f_t * other){
	out->_data[0] += vec4f_X(other);
	out->_data[1] += vec4f_Y(other);
	out->_data[2] += vec4f_Z(other);
	out->_data[3] += vec4f_W(other);
	out->_data[4] += vec4f_X(other);
	out->_data[5] += vec4f_Y(other);
	out->_data[6] += vec4f_Z(other);
	out->_data[7] += vec4f_W(other);
	out->_data[8] += vec4f_X(other);
	out->_data[9] += vec4f_Y(other);
	out->_data[10] += vec4f_Z(other);
	out->_data[11] += vec4f_W(other);
	out->_data[12] += vec4f_X(other);
	out->_data[13] += vec4f_Y(other);
	out->_data[14] += vec4f_Z(other);
	out->_data[15] += vec4f_W(other);
	return out;
}
matrix4f_t * matrix4f_subtractFromVecRow_r(matrix4f_t * out, vec4f_t * other){
	out->_data[0] -= vec4f_X(other);
	out->_data[1] -= vec4f_Y(other);
	out->_data[2] -= vec4f_Z(other);
	out->_data[3] -= vec4f_W(other);
	out->_data[4] -= vec4f_X(other);
	out->_data[5] -= vec4f_Y(other);
	out->_data[6] -= vec4f_Z(other);
	out->_data[7] -= vec4f_W(other);
	out->_data[8] -= vec4f_X(other);
	out->_data[9] -= vec4f_Y(other);
	out->_data[10] -= vec4f_Z(other);
	out->_data[11] -= vec4f_W(other);
	out->_data[12] -= vec4f_X(other);
	out->_data[13] -= vec4f_Y(other);
	out->_data[14] -= vec4f_Z(other);
	out->_data[15] -= vec4f_W(other);
	return out;
}
matrix4f_t * matrix4f_multiplyFromVecRow_r(matrix4f_t * out, vec4f_t * other){
	out->_data[0] *= vec4f_X(other);
	out->_data[1] *= vec4f_Y(other);
	out->_data[2] *= vec4f_Z(other);
	out->_data[3] *= vec4f_W(other);
	out->_data[4] *= vec4f_X(other);
	out->_data[5] *= vec4f_Y(other);
	out->_data[6] *= vec4f_Z(other);
	out->_data[7] *= vec4f_W(other);
	out->_data[8] *= vec4f_X(other);
	out->_data[9] *= vec4f_Y(other);
	out->_data[10] *= vec4f_Z(other);
	out->_data[11] *= vec4f_W(other);
	out->_data[12] *= vec4f_X(other);
	out->_data[13] *= vec4f_Y(other);
	out->_data[14] *= vec4f_Z(other);
	out->_data[15] *= vec4f_W(other);
	return out;
}

matrix4f_t * matrix4f_addFromVecColumn_r(matrix4f_t * out, vec4f_t * other){
	out->_data[0] += vec4f_X(other);
	out->_data[1] += vec4f_X(other);
	out->_data[2] += vec4f_X(other);
	out->_data[3] += vec4f_X(other);
	out->_data[4] += vec4f_Y(other);
	out->_data[5] += vec4f_Y(other);
	out->_data[6] += vec4f_Y(other);
	out->_data[7] += vec4f_Y(other);
	out->_data[8] += vec4f_Z(other);
	out->_data[9] += vec4f_Z(other);
	out->_data[10] += vec4f_Z(other);
	out->_data[11] += vec4f_Z(other);
	out->_data[12] += vec4f_W(other);
	out->_data[13] += vec4f_W(other);
	out->_data[14] += vec4f_W(other);
	out->_data[15] += vec4f_W(other);
	return out;
}
matrix4f_t * matrix4f_subtractFromVecColumn_r(matrix4f_t * out, vec4f_t * other){
	out->_data[0] -= vec4f_X(other);
	out->_data[1] -= vec4f_X(other);
	out->_data[2] -= vec4f_X(other);
	out->_data[3] -= vec4f_X(other);
	out->_data[4] -= vec4f_Y(other);
	out->_data[5] -= vec4f_Y(other);
	out->_data[6] -= vec4f_Y(other);
	out->_data[7] -= vec4f_Y(other);
	out->_data[8] -= vec4f_Z(other);
	out->_data[9] -= vec4f_Z(other);
	out->_data[10] -= vec4f_Z(other);
	out->_data[11] -= vec4f_Z(other);
	out->_data[12] -= vec4f_W(other);
	out->_data[13] -= vec4f_W(other);
	out->_data[14] -= vec4f_W(other);
	out->_data[15] -= vec4f_W(other);
	return out;
}
matrix4f_t * matrix4f_multiplyFromVecColumn_r(matrix4f_t * out, vec4f_t * other){
	out->_data[0] *= vec4f_X(other);
	out->_data[1] *= vec4f_X(other);
	out->_data[2] *= vec4f_X(other);
	out->_data[3] *= vec4f_X(other);
	out->_data[4] *= vec4f_Y(other);
	out->_data[5] *= vec4f_Y(other);
	out->_data[6] *= vec4f_Y(other);
	out->_data[7] *= vec4f_Y(other);
	out->_data[8] *= vec4f_Z(other);
	out->_data[9] *= vec4f_Z(other);
	out->_data[10] *= vec4f_Z(other);
	out->_data[11] *= vec4f_Z(other);
	out->_data[12] *= vec4f_W(other);
	out->_data[13] *= vec4f_W(other);
	out->_data[14] *= vec4f_W(other);
	out->_data[15] *= vec4f_W(other);
	return out;
}

//Using Scalars
matrix4f_t *  matrix4f_addFromScalar_r(matrix4f_t * out, float scalar){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] += scalar;
}
	return out;
}
matrix4f_t *  matrix4f_subtractFromScalar_r(matrix4f_t * out, float scalar){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] -= scalar;
}
	return out;
}
matrix4f_t *  matrix4f_multiplyFromScalar_r(matrix4f_t * out, float scalar){
	for(uint8_t i = 0; i < 16; i++){
		out->_data[i] *= scalar;
}
	return out;
}

matrix4f_t * matrix4f_invert_r(matrix4f_t * self){
	matrix4f_invert(self);
	return self;
}


char * matrix4f_toString(matrix4f_t * self){
  char * buffer = malloc(sizeof(char) * 128);
  sprintf(buffer,"[ %f , %f , %f , %f]\n[ %f , %f , %f , %f]\n[ %f , %f , %f , %f]\n[ %f , %f , %f , %f]\n" ,
				  self->_data[0] ,self->_data[1],self->_data[2] ,self->_data[3], self->_data[4],
				  self->_data[5] ,self->_data[6],self->_data[7] ,self->_data[8],self->_data[9] ,
				  self->_data[10], self->_data[11],self->_data[12] ,self->_data[13],self->_data[14] ,self->_data[15]);
  return buffer;
}


void matrix4f_setIdentityMatrix(matrix4f_t * out){
	out->_data[0] = 1.0f;
	out->_data[1] = 0.0f;
	out->_data[2] = 0.0f;
	out->_data[3] = 0.0f;
	out->_data[4] = 0.0f;
	out->_data[5] = 1.0f;
	out->_data[6] = 0.0f;
	out->_data[7] = 0.0f;
	out->_data[8] = 0.0f;
	out->_data[9] = 0.0f;
	out->_data[10] = 1.0f;
	out->_data[11] = 0.0f;
	out->_data[12] = 0.0f;
	out->_data[13] = 0.0f;
	out->_data[14] = 0.0f;
	out->_data[15] = 1.0f;
}

const matrix4f_t * matrix4f_IdentityMatrix(){
	return &identity;
}

size_t matrix4f_size(){
	return sizeof(matrix4f_t);
}
