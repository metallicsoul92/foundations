#include "../../include/math/mat2.h"
#include "../../include/math/vec2.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct matrix2float{
	float _data[4];
};


//Constant structures
const matrix2f_t identity = {{1.0f,0.0f,0.0f,1.0f}};


//matrix2 functions

//allocation
matrix2f_t * matrix2f_mallocFromArray(float data[4]){
	matrix2f_t * out = malloc(sizeof(matrix2f_t));
	out->_data[0] = data[0];
	out->_data[1] = data[1];
	out->_data[2] = data[2];
	out->_data[3] = data[3];
	return out;
}
matrix2f_t * matrix2f_copyFromOther(matrix2f_t * copy){
	matrix2f_t * out = malloc(sizeof(matrix2f_t));
	memcpy(out->_data,copy->_data,sizeof(float) * 4);
	return out;
}

matrix2f_t * matrix2f_moveFromOther(matrix2f_t * move){
	matrix2f_t * out = malloc(sizeof(matrix2f_t));
	memmove(out->_data,move->_data,sizeof(float) * 4);
	return out;
}

matrix2f_t * matrix2f_mallocFromString(const char * str){
	matrix2f_t * out = malloc(sizeof(matrix2f_t));
	sscanf(str,"[ %f , %f ]\n[ %f , %f ]\n" , &out->_data[0] ,&out->_data[1],
												&out->_data[2] ,&out->_data[3]);
	return out;
}

//initializing
void matrix2f_initFromArray(matrix2f_t * self, float data[4]){
	self->_data[0] = data[0];
	self->_data[1] = data[1];
	self->_data[2] = data[2];
	self->_data[3] = data[3];
}

void matrix2f_initFromString(matrix2f_t * self, const char * str){
	sscanf(str,"[ %f , %f ]\n[ %f , %f ]\n",&self->_data[0] , &self->_data[1],
												&self->_data[2] , &self->_data[3]);
}

//destroying
void matrix2f_free(matrix2f_t * self){
	free(self);
}

//Setting elements
void matrix2f_setElement(matrix2f_t * self, uint8_t index, float element){
	if(index < 4){
	self->_data[index] = element;
	}
}

//maybe overthinking, but const compatible? or atleast
//used like a const.
float matrix2f_ElementAt(const matrix2f_t *self, uint8_t index){
	if(index < 4){
	return (const float)self->_data[index];
	}else
		return (const float)NAN;
}

float matrix2f_getElement(matrix2f_t * self, uint8_t index){
	if(index < 4){
	return self->_data[index];
	}else
		return NAN;
}


//Using matricies
void matrix2f_add(matrix2f_t * out, matrix2f_t * other){
	out->_data[0] += other->_data[0];
	out->_data[1] += other->_data[1];
	out->_data[2] += other->_data[2];
	out->_data[3] += other->_data[3];
}
void matrix2f_subtract(matrix2f_t * out, matrix2f_t * other){
	out->_data[0] -= other->_data[0];
	out->_data[1] -= other->_data[1];
	out->_data[2] -= other->_data[2];
	out->_data[3] -= other->_data[3];
}
void matrix2f_multiply(matrix2f_t * out, matrix2f_t * other){
	out->_data[0] *= other->_data[0];
	out->_data[1] *= other->_data[1];
	out->_data[2] *= other->_data[2];
	out->_data[3] *= other->_data[3];
}


//Using Vectors
void matrix2f_addFromVecRow(matrix2f_t * out, vec2f_t * other){
	out->_data[0] += vec2f_X(other);
	out->_data[1] += vec2f_Y(other);
	out->_data[2] += vec2f_X(other);
	out->_data[3] += vec2f_Y(other);
}
void matrix2f_subtractFromVecRow(matrix2f_t * out, vec2f_t * other){
	out->_data[0] -= vec2f_X(other);
	out->_data[1] -= vec2f_Y(other);
	out->_data[2] -= vec2f_X(other);
	out->_data[3] -= vec2f_Y(other);
}
void matrix2f_multiplyFromVecRow(matrix2f_t * out, vec2f_t * other){
	out->_data[0] *= vec2f_X(other);
	out->_data[1] *= vec2f_Y(other);
	out->_data[2] *= vec2f_X(other);
	out->_data[3] *= vec2f_Y(other);
}

void matrix2f_addFromVecColumn(matrix2f_t * out, vec2f_t * other){
	out->_data[0] += vec2f_X(other);
	out->_data[1] += vec2f_X(other);
	out->_data[2] += vec2f_Y(other);
	out->_data[3] += vec2f_Y(other);
}
void matrix2f_subtractFromVecColumn(matrix2f_t * out, vec2f_t * other){
	out->_data[0] -= vec2f_X(other);
	out->_data[1] -= vec2f_X(other);
	out->_data[2] -= vec2f_Y(other);
	out->_data[3] -= vec2f_Y(other);
}
void matrix2f_multiplyFromVecColumn(matrix2f_t * out, vec2f_t * other){
	out->_data[0] *= vec2f_X(other);
	out->_data[1] *= vec2f_X(other);
	out->_data[2] *= vec2f_Y(other);
	out->_data[3] *= vec2f_Y(other);
}

//Using Scalars
void matrix2f_addFromScalar(matrix2f_t * out, float scalar){
	out->_data[0] += scalar;
	out->_data[1] += scalar;
	out->_data[2] += scalar;
	out->_data[3] += scalar;
}
void matrix2f_subtractFromScalar(matrix2f_t * out, float scalar){
	out->_data[0] -= scalar;
	out->_data[1] -= scalar;
	out->_data[2] -= scalar;
	out->_data[3] -= scalar;
}
void matrix2f_multiplyFromScalar(matrix2f_t * out, float scalar){
	out->_data[0] *= scalar;
	out->_data[1] *= scalar;
	out->_data[2] *= scalar;
	out->_data[3] *= scalar;
}

/*
	[ 0 , 1 ]     [ a , b ]
	[ 2 , 3 ] 	  [ c , d ]

*/

void matrix2f_invert(matrix2f_t * self){
	float ad = self->_data[0] * self->_data[3];
	float bc = self->_data[1] * self->_data[2];
	if(ad - bc != 0){
	float determinant = 1.0f / ad - bc;
	matrix2f_multiplyFromScalar(self, determinant);
	}else
		//TODO: LOG?
		printf("Error when attempting to invert\n");
}


//RETURNABLE FUNCTIONS
//Using matricies
matrix2f_t *  matrix2f_add_r(matrix2f_t * out, matrix2f_t * other){
	out->_data[0] += other->_data[0];
	out->_data[1] += other->_data[1];
	out->_data[2] += other->_data[2];
	out->_data[3] += other->_data[3];
	return out;
}
matrix2f_t *  matrix2f_subtract_r(matrix2f_t * out, matrix2f_t * other){
	out->_data[0] -= other->_data[0];
	out->_data[1] -= other->_data[1];
	out->_data[2] -= other->_data[2];
	out->_data[3] -= other->_data[3];
	return out;
}
matrix2f_t *  matrix2f_multiply_r(matrix2f_t * out, matrix2f_t * other){
	out->_data[0] *= other->_data[0];
	out->_data[1] *= other->_data[1];
	out->_data[2] *= other->_data[2];
	out->_data[3] *= other->_data[3];
	return out;
}


//Using Vectors
matrix2f_t * matrix2f_addFromVecRow_r(matrix2f_t * out, vec2f_t * other){
	out->_data[0] += vec2f_X(other);
	out->_data[1] += vec2f_Y(other);
	out->_data[2] += vec2f_X(other);
	out->_data[3] += vec2f_Y(other);
	return out;
}
matrix2f_t * matrix2f_subtractFromVecRow_r(matrix2f_t * out, vec2f_t * other){
	out->_data[0] -= vec2f_X(other);
	out->_data[1] -= vec2f_Y(other);
	out->_data[2] -= vec2f_X(other);
	out->_data[3] -= vec2f_Y(other);
	return out;
}
matrix2f_t * matrix2f_multiplyFromVecRow_r(matrix2f_t * out, vec2f_t * other){
	out->_data[0] *= vec2f_X(other);
	out->_data[1] *= vec2f_Y(other);
	out->_data[2] *= vec2f_X(other);
	out->_data[3] *= vec2f_Y(other);
	return out;
}

matrix2f_t * matrix2f_addFromVecColumn_r(matrix2f_t * out, vec2f_t * other){
	out->_data[0] += vec2f_X(other);
	out->_data[1] += vec2f_X(other);
	out->_data[2] += vec2f_Y(other);
	out->_data[3] += vec2f_Y(other);
	return out;
}
matrix2f_t * matrix2f_subtractFromVecColumn_r(matrix2f_t * out, vec2f_t * other){
	out->_data[0] -= vec2f_X(other);
	out->_data[1] -= vec2f_X(other);
	out->_data[2] -= vec2f_Y(other);
	out->_data[3] -= vec2f_Y(other);
	return out;
}
matrix2f_t * matrix2f_multiplyFromVecColumn_r(matrix2f_t * out, vec2f_t * other){
	out->_data[0] *= vec2f_X(other);
	out->_data[1] *= vec2f_X(other);
	out->_data[2] *= vec2f_Y(other);
	out->_data[3] *= vec2f_Y(other);
	return out;
}

//Using Scalars
matrix2f_t *  matrix2f_addFromScalar_r(matrix2f_t * out, float scalar){
	out->_data[0] += scalar;
	out->_data[1] += scalar;
	out->_data[2] += scalar;
	out->_data[3] += scalar;
	return out;
}
matrix2f_t *  matrix2f_subtractFromScalar_r(matrix2f_t * out, float scalar){
	out->_data[0] -= scalar;
	out->_data[1] -= scalar;
	out->_data[2] -= scalar;
	out->_data[3] -= scalar;
	return out;
}
matrix2f_t *  matrix2f_multiplyFromScalar_r(matrix2f_t * out, float scalar){
	out->_data[0] *= scalar;
	out->_data[1] *= scalar;
	out->_data[2] *= scalar;
	out->_data[3] *= scalar;
	return out;
}

matrix2f_t * matrix2f_invert_r(matrix2f_t * self){
	float ad = self->_data[0] * self->_data[3];
	float bc = self->_data[1] * self->_data[2];
	if(ad - bc != 0){
	float determinant = 1.0f / ad - bc;
	matrix2f_multiplyFromScalar(self, determinant);
	}else{
		//TODO: LOG?
		printf("Error when attempting to invert\n");
	}

	return self;
}



char * matrix2f_toString(matrix2f_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "[ %f , %f ]\n[ %f , %f ]\n",self->_data[0],self->_data[1],self->_data[2],self->_data[3]);
  return buffer;
}


void matrix2f_setIdentityMatrix(matrix2f_t * out){
	out->_data[0] = 1.0f;
	out->_data[1] = 0.0f;
	out->_data[2] = 0.0f;
	out->_data[3] = 1.0f;
}

const matrix2f_t * matrix2f_IdentityMatrix(){
	return &identity;
}

size_t matrix2f_size(){
	return sizeof(matrix2f_t);
}
