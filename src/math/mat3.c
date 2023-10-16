#include "../../include/math/mat3.h"
#include "../../include/math/vec3.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct matrix3float{
	float _data[9];
};

//private API:
float mat_int_determinant(float a, float b , float c , float d){
	float ad = a * d;
	float bc = b * c;
	float det = ad - bc;
	return det;
}

//Constant structures
const matrix3f_t identity = {{1.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,1.0f}};


//matrix3 functions

//allocation
matrix3f_t * matrix3f_mallocFromArray(float data[9]){
	matrix3f_t * out = malloc(sizeof(matrix3f_t));
	for(uint8_t i = 0; i < 9; i++){
		out->_data[i] = data[i];
}
	return out;
}
matrix3f_t * matrix3f_copyFromOther(matrix3f_t * copy){
	matrix3f_t * out = malloc(sizeof(matrix3f_t));
	memcpy(out->_data,copy->_data,sizeof(float) * 9);
	return out;
}

matrix3f_t * matrix3f_moveFromOther(matrix3f_t * move){
	matrix3f_t * out = malloc(sizeof(matrix3f_t));
	memmove(out->_data,move->_data,sizeof(float) * 9);
	return out;
}

matrix3f_t * matrix3f_mallocFromString(const char * str){
	matrix3f_t * out = malloc(sizeof(matrix3f_t));
	sscanf(str,"[ %f , %f , %f ]\n[ %f , %f , %f ]\n[ %f , %f , %f ]\n" ,
				  &out->_data[0] ,&out->_data[1],&out->_data[2] ,&out->_data[3], &out->_data[4],
				  &out->_data[5] ,&out->_data[6],&out->_data[7] ,&out->_data[8]);
	return out;
}

//initializing
void matrix3f_initFromArray(matrix3f_t * self, float data[9]){
	for(uint8_t i = 0; i < 9; i++){
		self->_data[i] = data[i];
}
}

void matrix3f_initFromString(matrix3f_t * self, const char * str){
	sscanf(str,"[ %f , %f , %f ]\n[ %f , %f , %f ]\n[ %f , %f , %f ]\n" ,
				  &self->_data[0] ,&self->_data[1],&self->_data[2] ,&self->_data[3], &self->_data[4],
				  &self->_data[5] ,&self->_data[6],&self->_data[7] ,&self->_data[8]);
}

//destroying
void matrix3f_free(matrix3f_t * self){
	free(self);
}

//Setting elements
void matrix3f_setElement(matrix3f_t * self, uint8_t index, float element){
	if(index < 9){
	self->_data[index] = element;
}
}

//maybe overthinking, but const compatible? or atleast
//used like a const.
const float matrix3f_ElementAt(const matrix3f_t *self, uint8_t index){
	if(index < 9){
	return (const float)self->_data[index];
	}else
		return (const float)NAN;
}

float matrix3f_getElement(matrix3f_t * self, uint8_t index){
	if(index < 9){
	return self->_data[index];
	}else
		return NAN;
}


//Using matricies
void matrix3f_add(matrix3f_t * out, matrix3f_t * other){
	for(uint8_t i = 0; i < 9; i++){
		out->_data[i] += other->_data[i];
}
}
void matrix3f_subtract(matrix3f_t * out, matrix3f_t * other){
	for(uint8_t i = 0; i < 9; i++){
		out->_data[i] -= other->_data[i];
}
}
void matrix3f_multiply(matrix3f_t * out, matrix3f_t * other){
	for(uint8_t i = 0; i < 9; i++){
		out->_data[i] *= other->_data[i];
}
}


//Using Vectors
void matrix3f_addFromVecRow(matrix3f_t * out, vec3f_t * other){
	out->_data[0] += vec3f_X(other);
	out->_data[1] += vec3f_Y(other);
	out->_data[2] += vec3f_Z(other);
	out->_data[3] += vec3f_X(other);
	out->_data[4] += vec3f_Y(other);
	out->_data[5] += vec3f_Z(other);
	out->_data[6] += vec3f_X(other);
	out->_data[7] += vec3f_Y(other);
	out->_data[8] += vec3f_Z(other);
}
void matrix3f_subtractFromVecRow(matrix3f_t * out, vec3f_t * other){
	out->_data[0] -= vec3f_X(other);
	out->_data[1] -= vec3f_Y(other);
	out->_data[2] -= vec3f_Z(other);
	out->_data[3] -= vec3f_X(other);
	out->_data[4] -= vec3f_Y(other);
	out->_data[5] -= vec3f_Z(other);
	out->_data[6] -= vec3f_X(other);
	out->_data[7] -= vec3f_Y(other);
	out->_data[8] -= vec3f_Z(other);
}
void matrix3f_multiplyFromVecRow(matrix3f_t * out, vec3f_t * other){
	out->_data[0] *= vec3f_X(other);
	out->_data[1] *= vec3f_Y(other);
	out->_data[2] *= vec3f_Z(other);
	out->_data[3] *= vec3f_X(other);
	out->_data[4] *= vec3f_Y(other);
	out->_data[5] *= vec3f_Z(other);
	out->_data[6] *= vec3f_X(other);
	out->_data[7] *= vec3f_Y(other);
	out->_data[8] *= vec3f_Z(other);
}

void matrix3f_addFromVecColumn(matrix3f_t * out, vec3f_t * other){
	out->_data[0] += vec3f_X(other);
	out->_data[1] += vec3f_X(other);
	out->_data[2] += vec3f_X(other);
	out->_data[3] += vec3f_Y(other);
	out->_data[4] += vec3f_Y(other);
	out->_data[5] += vec3f_Y(other);
	out->_data[6] += vec3f_Z(other);
	out->_data[7] += vec3f_Z(other);
	out->_data[8] += vec3f_Z(other);
}
void matrix3f_subtractFromVecColumn(matrix3f_t * out, vec3f_t * other){
	out->_data[0] -= vec3f_X(other);
	out->_data[1] -= vec3f_X(other);
	out->_data[2] -= vec3f_X(other);
	out->_data[3] -= vec3f_Y(other);
	out->_data[4] -= vec3f_Y(other);
	out->_data[5] -= vec3f_Y(other);
	out->_data[6] -= vec3f_Z(other);
	out->_data[7] -= vec3f_Z(other);
	out->_data[8] -= vec3f_Z(other);
}
void matrix3f_multiplyFromVecColumn(matrix3f_t * out, vec3f_t * other){
	out->_data[0] *= vec3f_X(other);
	out->_data[1] *= vec3f_X(other);
	out->_data[2] *= vec3f_X(other);
	out->_data[3] *= vec3f_Y(other);
	out->_data[4] *= vec3f_Y(other);
	out->_data[5] *= vec3f_Y(other);
	out->_data[6] *= vec3f_Z(other);
	out->_data[7] *= vec3f_Z(other);
	out->_data[8] *= vec3f_Z(other);
}

//Using Scalars
void matrix3f_addFromScalar(matrix3f_t * out, float scalar){
	for(uint8_t i = 0; i < 9; i++){
		out->_data[i] += scalar;
}
}
void matrix3f_subtractFromScalar(matrix3f_t * out, float scalar){
	for(uint8_t i = 0; i < 9; i++){
		out->_data[i] -= scalar;
}
}
void matrix3f_multiplyFromScalar(matrix3f_t * out, float scalar){
	for(uint8_t i = 0; i < 9; i++){
		out->_data[i] *= scalar;
}
}

void matrix3f_invert(matrix3f_t * self){
	//this is fucking disgusting. You should be fucking ashamed of yourself.
	float buff[12];
	//determinant of first 2x2
	buff[0] = self->_data[4] * self->_data[8];
	buff[1] = self->_data[5] * self->_data[7];
	buff[2] = buff[0] - buff[1];
	buff[3] = self->_data[0] * buff[2];
	//determinant of second 2x2
	buff[4] = self->_data[3] * self->_data[8];
	buff[5] = self->_data[5] * self->_data[6];
	buff[6] = buff[4] - buff[5];
	buff[7] = self->_data[1] * buff[6];
	//determinant of third 2x2
	buff[8] = self->_data[3] * self->_data[7];
	buff[9] = self->_data[4] * self->_data[6];
	buff[10]= buff[8] - buff[9];
	buff[11] = self->_data[2] * buff[10];
	// one step at a time so the compiler doesnt optimize this incorrectly.
	float det = buff[3] - buff[7];
	det += buff[11];

	//minor determinants
	float minDet[9];
	minDet[0] = mat_int_determinant(self->_data[4],self->_data[5],self->_data[7],self->_data[8]);
	minDet[1] = mat_int_determinant(self->_data[3],self->_data[5],self->_data[6],self->_data[8]);
	minDet[2] = mat_int_determinant(self->_data[3],self->_data[4],self->_data[6],self->_data[7]);
	minDet[3] = mat_int_determinant(self->_data[1],self->_data[2],self->_data[7],self->_data[8]);
	minDet[4] = mat_int_determinant(self->_data[0],self->_data[2],self->_data[6],self->_data[8]);
	minDet[5] = mat_int_determinant(self->_data[0],self->_data[1],self->_data[6],self->_data[7]);
	minDet[6] = mat_int_determinant(self->_data[1],self->_data[2],self->_data[4],self->_data[5]);
	minDet[7] = mat_int_determinant(self->_data[0],self->_data[2],self->_data[3],self->_data[5]);
	minDet[8] = mat_int_determinant(self->_data[0],self->_data[1],self->_data[3],self->_data[4]);

	minDet[1] *= -1.0f;
	minDet[3] *= -1.0f;
	minDet[5] *= -1.0f;
	minDet[7] *= -1.0f;

	float temp;
	temp = minDet[1];
	minDet[1] = minDet[3];
	minDet[3] = temp;
	temp = minDet[2];
	minDet[2] = minDet[6];
	minDet[6] = temp;
	temp = minDet[5];
	minDet[5] = minDet[7];
	minDet[7] = temp;

	for(int i = 0; i < 9 ; i++){
		self->_data[i] = minDet[i];
	}
    //fully inverted
	float invDet = 1.0f / det;
	//multiply each element by the above equation.
	matrix3f_multiplyFromScalar(self, invDet);
}


//RETURNABLE FUNCTIONS
//Using matricies
matrix3f_t *  matrix3f_add_r(matrix3f_t * out, matrix3f_t * other){
	for(uint8_t i = 0; i < 9; i++){
		out->_data[i] += other->_data[i];
}
	return out;
}
matrix3f_t *  matrix3f_subtract_r(matrix3f_t * out, matrix3f_t * other){
	for(uint8_t i = 0; i < 9; i++){
		out->_data[i] -= other->_data[i];
}
	return out;
}
matrix3f_t *  matrix3f_multiply_r(matrix3f_t * out, matrix3f_t * other){
	for(uint8_t i = 0; i < 9; i++){
		out->_data[i] *= other->_data[i];
}
	return out;
}


//Using Vectors
matrix3f_t * matrix3f_addFromVecRow_r(matrix3f_t * out, vec3f_t * other){
	out->_data[0] += vec3f_X(other);
	out->_data[1] += vec3f_Y(other);
	out->_data[2] += vec3f_Z(other);
	out->_data[3] += vec3f_X(other);
	out->_data[4] += vec3f_Y(other);
	out->_data[5] += vec3f_Z(other);
	out->_data[6] += vec3f_X(other);
	out->_data[7] += vec3f_Y(other);
	out->_data[8] += vec3f_Z(other);
	return out;
}
matrix3f_t * matrix3f_subtractFromVecRow_r(matrix3f_t * out, vec3f_t * other){
	out->_data[0] -= vec3f_X(other);
	out->_data[1] -= vec3f_Y(other);
	out->_data[2] -= vec3f_Z(other);
	out->_data[3] -= vec3f_X(other);
	out->_data[4] -= vec3f_Y(other);
	out->_data[5] -= vec3f_Z(other);
	out->_data[6] -= vec3f_X(other);
	out->_data[7] -= vec3f_Y(other);
	out->_data[8] -= vec3f_Z(other);
	return out;
}
matrix3f_t * matrix3f_multiplyFromVecRow_r(matrix3f_t * out, vec3f_t * other){
	out->_data[0] *= vec3f_X(other);
	out->_data[1] *= vec3f_Y(other);
	out->_data[2] *= vec3f_Z(other);
	out->_data[3] *= vec3f_X(other);
	out->_data[4] *= vec3f_Y(other);
	out->_data[5] *= vec3f_Z(other);
	out->_data[6] *= vec3f_X(other);
	out->_data[7] *= vec3f_Y(other);
	out->_data[8] *= vec3f_Z(other);
	return out;
}

matrix3f_t * matrix3f_addFromVecColumn_r(matrix3f_t * out, vec3f_t * other){
	out->_data[0] += vec3f_X(other);
	out->_data[1] += vec3f_X(other);
	out->_data[2] += vec3f_X(other);
	out->_data[3] += vec3f_Y(other);
	out->_data[4] += vec3f_Y(other);
	out->_data[5] += vec3f_Y(other);
	out->_data[6] += vec3f_Z(other);
	out->_data[7] += vec3f_Z(other);
	out->_data[8] += vec3f_Z(other);
	return out;
}
matrix3f_t * matrix3f_subtractFromVecColumn_r(matrix3f_t * out, vec3f_t * other){
	out->_data[0] -= vec3f_X(other);
	out->_data[1] -= vec3f_X(other);
	out->_data[2] -= vec3f_X(other);
	out->_data[3] -= vec3f_Y(other);
	out->_data[4] -= vec3f_Y(other);
	out->_data[5] -= vec3f_Y(other);
	out->_data[6] -= vec3f_Z(other);
	out->_data[7] -= vec3f_Z(other);
	out->_data[8] -= vec3f_Z(other);
	return out;
}
matrix3f_t * matrix3f_multiplyFromVecColumn_r(matrix3f_t * out, vec3f_t * other){
	out->_data[0] *= vec3f_X(other);
	out->_data[1] *= vec3f_X(other);
	out->_data[2] *= vec3f_X(other);
	out->_data[3] *= vec3f_Y(other);
	out->_data[4] *= vec3f_Y(other);
	out->_data[5] *= vec3f_Y(other);
	out->_data[6] *= vec3f_Z(other);
	out->_data[7] *= vec3f_Z(other);
	out->_data[8] *= vec3f_Z(other);
	return out;
}

//Using Scalars
matrix3f_t *  matrix3f_addFromScalar_r(matrix3f_t * out, float scalar){
	out->_data[0] += scalar;
	out->_data[1] += scalar;
	out->_data[2] += scalar;
	out->_data[3] += scalar;
	out->_data[4] += scalar;
	out->_data[5] += scalar;
	out->_data[6] += scalar;
	out->_data[7] += scalar;
	out->_data[8] += scalar;
	return out;
}
matrix3f_t *  matrix3f_subtractFromScalar_r(matrix3f_t * out, float scalar){
	out->_data[0] -= scalar;
	out->_data[1] -= scalar;
	out->_data[2] -= scalar;
	out->_data[3] -= scalar;
	out->_data[4] -= scalar;
	out->_data[5] -= scalar;
	out->_data[6] -= scalar;
	out->_data[7] -= scalar;
	out->_data[8] -= scalar;
	return out;
}
matrix3f_t *  matrix3f_multiplyFromScalar_r(matrix3f_t * out, float scalar){
	out->_data[0] *= scalar;
	out->_data[1] *= scalar;
	out->_data[2] *= scalar;
	out->_data[3] *= scalar;
	out->_data[4] *= scalar;
	out->_data[5] *= scalar;
	out->_data[6] *= scalar;
	out->_data[7] *= scalar;
	out->_data[8] *= scalar;
	return out;
}


matrix3f_t *  matrix3f_invert_r(matrix3f_t * self){
	matrix3f_invert(self);
	return self;
}

char * matrix3f_toString(matrix3f_t * self){
  char * buffer = malloc(sizeof(char) * 96);
  sprintf(buffer,"[ %f , %f , %f ]\n[ %f , %f , %f ]\n[ %f , %f , %f ]\n" ,
				  self->_data[0] ,self->_data[1],self->_data[2] ,self->_data[3], self->_data[4],
				  self->_data[5] ,self->_data[6],self->_data[7] ,self->_data[8]);
  return buffer;
}


void matrix3f_setIdentityMatrix(matrix3f_t * out){
	out->_data[0] = 1.0f;
	out->_data[1] = 0.0f;
	out->_data[2] = 0.0f;
	out->_data[3] = 0.0f;
	out->_data[4] = 1.0f;
	out->_data[5] = 0.0f;
	out->_data[6] = 0.0f;
	out->_data[7] = 0.0f;
	out->_data[8] = 1.0f;
}

const matrix3f_t * matrix3f_IdentityMatrix(){
	return &identity;
}

size_t matrix3f_size(){
	return sizeof(matrix3f_t);
}
