#include "../../include/math/vec2.h"
#include "../../include/math/vec3.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DEFINE_ALL_VEC3
#include "../../include/math/priv/types.h"


//Initalize an already allocated vector.

void initvec3I8(vec3int8_t * out , int8_t x ,int8_t y, int8_t z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}
void initvec3U8(vec3uint8_t * out , uint8_t x ,uint8_t y, uint8_t z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}
void initvec3I16(vec3int16_t * out , int16_t x ,int16_t y, int16_t z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}
void initvec3U16(vec3uint16_t * out , uint16_t x ,uint16_t y, uint16_t z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}
void initvec3I32(vec3int32_t * out , int32_t x ,int32_t y, int32_t z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}
void initvec3U32(vec3uint32_t * out , uint32_t x ,uint32_t y, uint32_t z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}
void initvec3I64(vec3int64_t * out , int64_t x ,int64_t y, int64_t z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}
void initvec3U64(vec3uint64_t * out , uint64_t x ,uint64_t y, uint64_t z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}
void initvec3C(vec3char_t * out , char x ,char y, char z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}
void initvec3F(vec3f_t * out , float x ,float y, float z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}
void initvec3D(vec3d_t * out, double x , double y, double z){
  out->_x = x;
  out->_y = y;
  out->_z = z;
}

//vec2 represents the x,y variables
void initvec3I8_fromVec2(vec3int8_t * out , vec2int8_t * xy , int8_t z){
  out->_x = vec2i8_X(xy);
  out->_y = vec2i8_Y(xy);
  out->_z = z;
}
void initvec3U8_fromVec2(vec3uint8_t * out , vec2uint8_t * xy ,uint8_t z){
  out->_x = vec2u8_X(xy);
  out->_y = vec2u8_Y(xy);
  out->_z = z;
}
void initvec3I16_fromVec2(vec3int16_t * out , vec2int16_t * xy , int16_t z){
  out->_x = vec2i16_X(xy);
  out->_y = vec2i16_Y(xy);
  out->_z = z;
}
void initvec3U16_fromVec2(vec3uint16_t * out , vec2uint16_t * xy , uint16_t z){
  out->_x = vec2u16_X(xy);
  out->_y = vec2u16_Y(xy);
  out->_z = z;
}
void initvec3I32_fromVec2(vec3int32_t * out , vec2int32_t * xy , int32_t z){
  out->_x = vec2i32_X(xy);
  out->_y = vec2i32_Y(xy);
  out->_z = z;
}
void initvec3U32_fromVec2(vec3uint32_t * out , vec2uint32_t * xy , uint32_t z){
  out->_x = vec2u32_X(xy);
  out->_y = vec2u32_Y(xy);
  out->_z = z;
}
void initvec3I64_fromVec2(vec3int64_t * out , vec2int64_t * xy , int64_t z){
  out->_x = vec2i64_X(xy);
  out->_y = vec2i64_Y(xy);
  out->_z = z;
}
void initvec3U64_fromVec2(vec3uint64_t * out , vec2uint64_t * xy ,uint64_t z){
  out->_x = vec2u64_X(xy);
  out->_y = vec2u64_Y(xy);
  out->_z = z;
}
void initvec3C_fromVec2(vec3char_t * out , vec2char_t * xy ,char z){
  out->_x = vec2char_X(xy);
  out->_y = vec2char_Y(xy);
  out->_z = z;
}
void initvec3F_fromVec2(vec3f_t * out , vec2f_t * xy , float z){
  out->_x = vec2f_X(xy);
  out->_y = vec2f_Y(xy);
  out->_z = z;
}
void initvec3D_fromVec2(vec3d_t * out, vec2d_t * xy , double z){
  out->_x = vec2d_X(xy);
  out->_y = vec2d_Y(xy);
  out->_z = z;
}

//Allocate and initialize Vector
vec3int8_t * allocvec3I8(int8_t x, int8_t y, int8_t z){
  vec3int8_t * out;
  out = malloc(sizeof(vec3int8_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}
vec3uint8_t * allocvec3U8(uint8_t x, uint8_t y, uint8_t z){
  vec3uint8_t * out;
  out = malloc(sizeof(vec3uint8_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}
vec3int16_t * allocvec3I16(int16_t x, int16_t y, int16_t z ){
  vec3int16_t * out;
  out = malloc(sizeof(vec3int16_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}
vec3uint16_t * allocvec3U16(uint16_t x, uint16_t y, uint16_t z){
  vec3uint16_t * out;
  out = malloc(sizeof(vec3uint16_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}
vec3int32_t * allocvec3I32(int32_t x, int32_t y, int32_t z){
  vec3int32_t * out;
  out = malloc(sizeof(vec3int32_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}
vec3uint32_t * allocvec3U32(uint32_t x, uint32_t y, uint32_t z){
  vec3uint32_t * out;
  out = malloc(sizeof(vec3uint32_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}
vec3int64_t * allocvec3I64(int64_t x, int64_t y, int64_t z){
  vec3int64_t * out;
  out = malloc(sizeof(vec3int64_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}
vec3uint64_t * allocvec3U64(uint64_t x, uint64_t y, uint64_t z){
  vec3uint64_t * out;
  out = malloc(sizeof(vec3uint64_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}
vec3char_t * allocvec3C(char x, char y, char z){
  vec3char_t * out;
  out = malloc(sizeof(vec3char_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}
vec3f_t * allocvec3F(float x, float y, float z){
  vec3f_t * out;
  out = malloc(sizeof(vec3f_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}
vec3d_t * allocvec3D(double x, double y, double z){
  vec3d_t * out;
  out = malloc(sizeof(vec3d_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  return out;
}

//Allocate and initialize Vector from vec2
vec3int8_t * allocvec3I8_fromVec2(vec2int8_t * xy, int8_t z){
  vec3int8_t * out;
  out = malloc(sizeof(vec3int8_t));
  out->_x = vec2i8_X(xy);
  out->_y = vec2i8_Y(xy);
  out->_z = z;
  return out;
}
vec3uint8_t * allocvec3U8_fromVec2(vec2uint8_t * xy, uint8_t z){
  vec3uint8_t * out;
  out = malloc(sizeof(vec3uint8_t));
  out->_x = vec2u8_X(xy);
  out->_y = vec2u8_Y(xy);
  out->_z = z;
  return out;
}
vec3int16_t * allocvec3I16_fromVec2(vec2int16_t * xy, int16_t z ){
  vec3int16_t * out;
  out = malloc(sizeof(vec3int16_t));
  out->_x = vec2i16_X(xy);
  out->_y = vec2i16_Y(xy);
  out->_z = z;
  return out;
}
vec3uint16_t * allocvec3U16_fromVec2(vec2uint16_t * xy, uint16_t z){
  vec3uint16_t * out;
  out = malloc(sizeof(vec3uint16_t));
  out->_x = vec2u16_X(xy);
  out->_y = vec2u16_Y(xy);
  out->_z = z;
  return out;
}
vec3int32_t * allocvec3I32_fromVec2(vec2int32_t * xy, int32_t z){
  vec3int32_t * out;
  out = malloc(sizeof(vec3int32_t));
  out->_x = vec2i32_X(xy);
  out->_y = vec2i32_Y(xy);
  out->_z = z;
  return out;
}
vec3uint32_t * allocvec3U32_fromVec2(vec2uint32_t * xy, uint32_t z){
  vec3uint32_t * out;
  out = malloc(sizeof(vec3uint32_t));
  out->_x = vec2u32_X(xy);
  out->_y = vec2u32_Y(xy);
  out->_z = z;
  return out;
}
vec3int64_t * allocvec3I64_fromVec2(vec2int64_t * xy, int64_t z){
  vec3int64_t * out;
  out = malloc(sizeof(vec3int64_t));
  out->_x = vec2i64_X(xy);
  out->_y = vec2i64_Y(xy);
  out->_z = z;
  return out;
}
vec3uint64_t * allocvec3U64_fromVec2(vec2uint64_t * xy, uint64_t z){
  vec3uint64_t * out;
  out = malloc(sizeof(vec3uint64_t));
  out->_x = vec2u64_X(xy);
  out->_y = vec2u64_Y(xy);
  out->_z = z;
  return out;
}
vec3char_t * allocvec3C_fromVec2(vec2char_t * xy, char z){
  vec3char_t * out;
  out = malloc(sizeof(vec3char_t));
  out->_x = vec2char_X(xy);
  out->_y = vec2char_Y(xy);
  out->_z = z;
  return out;
}
vec3f_t * allocvec3F_fromVec2(vec2f_t * xy, float z){
  vec3f_t * out;
  out = malloc(sizeof(vec3f_t));
  out->_x = vec2f_X(xy);
  out->_y = vec2f_Y(xy);
  out->_z = z;
  return out;
}
vec3d_t * allocvec3D_fromVec2(vec2d_t * xy, double z){
  vec3d_t * out;
  out = malloc(sizeof(vec3d_t));
  out->_x = vec2d_X(xy);
  out->_y = vec2d_Y(xy);
  out->_z = z;
  return out;
}


//Allocate and initialize Vector from string
vec3int8_t * allocvec3I8_fromString(const char * str){
  int8_t x,y,z;
  vec3int8_t * out = malloc(sizeof(vec3int8_t));
  sscanf(str,"%hhd , %hhd , %hhd \n",&x , &y , &z);
  initvec3I8(out,x,y,z);
  return out;
}
vec3uint8_t * allocvec3U8_fromString(const char * str){
  uint8_t x,y,z;
  vec3uint8_t * out = malloc(sizeof(vec3uint8_t));
  sscanf(str,"%hhu , %hhu , %hhu \n",&x , &y , &z);
  initvec3U8(out,x,y,z);
  return out;
}
vec3int16_t * allocvec3I16_fromString(const char * str){
  int16_t x,y,z;
  vec3int16_t * out = malloc(sizeof(vec3int16_t));
  sscanf(str,"%hd , %hd , %hd \n",&x , &y , &z);
  initvec3I16(out,x,y,z);
  return out;
}
vec3uint16_t * allocvec3U16_fromString(const char * str){
  uint16_t x,y,z;
  vec3uint16_t * out = malloc(sizeof(vec3uint16_t));
  sscanf(str,"%hu , %hu , %hu \n",&x , &y , &z);
  initvec3U16(out,x,y,z);
  return out;
}
vec3int32_t * allocvec3I32_fromString(const char * str){
  int32_t x,y,z;
  vec3int32_t * out = malloc(sizeof(vec3int32_t));
  sscanf(str,"%d , %d , %d \n",&x , &y , &z);
  initvec3I32(out,x,y,z);
  return out;
}
vec3uint32_t * allocvec3U32_fromString(const char * str){
  uint32_t x,y,z;
  vec3uint32_t * out = malloc(sizeof(vec3uint32_t));
  sscanf(str,"%u , %u , %u \n",&x , &y , &z);
  initvec3U32(out,x,y,z);
  return out;
}
vec3int64_t * allocvec3I64_fromString(const char * str){
  int64_t x,y,z;
  vec3int64_t * out = malloc(sizeof(vec3int64_t));
  sscanf(str,"%ld , %ld , %ld \n",&x , &y , &z);
  initvec3I64(out,x,y,z);
  return out;
}
vec3uint64_t * allocvec3U64_fromString(const char * str){
  uint64_t x,y,z;
  vec3uint64_t * out = malloc(sizeof(vec3uint64_t));
  sscanf(str,"%lu , %lu , %lu \n",&x , &y , &z);
  initvec3U64(out,x,y,z);
  return out;
}
vec3char_t * allocvec3C_fromString(const char * str){
  char x,y,z;
  vec3char_t * out = malloc(sizeof(vec3char_t));
  sscanf(str,"%c , %c , %c \n",&x , &y , &z);
  initvec3C(out,x,y,z);
  return out;
}
vec3f_t * allocvec3F_fromString(const char * str){
  float x,y,z;
  vec3f_t * out = malloc(sizeof(vec3f_t));
  sscanf(str,"%f , %f , %f \n",&x , &y , &z);
  initvec3F(out,x,y,z);
  return out;
}
vec3d_t * allocvec3D_fromString(const char * str){
  double x,y,z;
  vec3d_t * out = malloc(sizeof(vec3d_t));
  sscanf(str,"%lf , %lf , %lf \n",&x , &y , &z);
  initvec3D(out,x,y,z);
  return out;
}







//getters and setters
void vec3i8_setX(vec3int8_t * out, int8_t x){
  out->_x = x;
}
void vec3i8_setY(vec3int8_t * out, int8_t y){
  out->_y = y;
}
void vec3i8_setZ(vec3int8_t * out, int8_t z){
  out->_z = z;
}

int8_t vec3i8_X(vec3int8_t * out){
  return out->_x;
}
int8_t vec3i8_Y(vec3int8_t * out){
  return out->_y;
}
int8_t vec3i8_Z(vec3int8_t * out){
  return out->_z;
}

void vec3u8_setX(vec3uint8_t * out, uint8_t x){
  out->_x = x;
}
void vec3u8_setY(vec3uint8_t * out, uint8_t y){
  out->_y = y;
}
void vec3u8_setZ(vec3uint8_t * out, uint8_t z){
  out->_z = z;
}

uint8_t vec3u8_X(vec3uint8_t * out){
  return out->_x;
}
uint8_t vec3u8_Y(vec3uint8_t * out){
  return out->_y;
}
uint8_t vec3u8_Z(vec3uint8_t * out){
  return out->_z;
}

void vec3i16_setX(vec3int16_t * out, int16_t x){
  out->_x = x;
}
void vec3i16_setY(vec3int16_t * out, int16_t y){
  out->_y = y;
}
void vec3i16_setZ(vec3int16_t * out, int16_t z){
  out->_z = z;
}

int16_t vec3i16_X(vec3int16_t * out){
  return out->_x;
}
int16_t vec3i16_Y(vec3int16_t * out){
  return out->_y;
}
int16_t vec3i16_Z(vec3int16_t * out){
  return out->_z;
}

void vec3u16_setX(vec3uint16_t * out, uint16_t x){
  out->_x = x;
}
void vec3u16_setY(vec3uint16_t * out, uint16_t y){
  out->_y = y;
}
void vec3u16_setZ(vec3uint16_t * out, uint16_t z){
  out->_z = z;
}

uint16_t vec3u16_X(vec3uint16_t * out){
  return out->_x;
}
uint16_t vec3u16_Y(vec3uint16_t * out){
  return out->_y;
}
uint16_t vec3u16_Z(vec3uint16_t * out){
  return out->_z;
}

void vec3i32_setX(vec3int32_t * out, int32_t x){
  out->_x = x;
}
void vec3i32_setY(vec3int32_t * out, int32_t y){
  out->_y = y;
}
void vec3i32_setZ(vec3int32_t * out, int32_t z){
  out->_z = z;
}

int32_t vec3i32_X(vec3int32_t * out){
  return out->_x;
}
int32_t vec3i32_Y(vec3int32_t * out){
  return out->_y;
}
int32_t vec3i32_Z(vec3int32_t * out){
  return out->_z;
}

void vec3u32_setX(vec3uint32_t * out, uint32_t x){
  out->_x = x;
}
void vec3u32_setY(vec3uint32_t * out, uint32_t y){
  out->_y = y;
}
void vec3u32_setZ(vec3uint32_t * out, uint32_t z){
  out->_z = z;
}


uint32_t vec3u32_X(vec3uint32_t * out){
  return out->_x;
}
uint32_t vec3u32_Y(vec3uint32_t * out){
  return out->_y;
}
uint32_t vec3u32_Z(vec3uint32_t * out){
  return out->_z;
}

void vec3i64_setX(vec3int64_t * out, int64_t x){
  out->_x = x;
}
void vec3i64_setY(vec3int64_t * out, int64_t y){
  out->_y = y;
}
void vec3i64_setZ(vec3int64_t * out, int64_t z){
  out->_z = z;
}


int64_t vec3i64_X(vec3int64_t * out){
  return out->_x;
}
int64_t vec3i64_Y(vec3int64_t * out){
  return out->_y;
}
int64_t vec3i64_Z(vec3int64_t * out){
  return out->_z;
}

void vec3u64_setX(vec3uint64_t * out, uint64_t x){
  out->_x = x;
}
void vec3u64_setY(vec3uint64_t * out, uint64_t y){
  out->_y = y;
}
void vec3u64_setZ(vec3uint64_t * out, uint64_t z){
  out->_z = z;
}

uint64_t vec3u64_X(vec3uint64_t * out){
  return out->_x;
}
uint64_t vec3u64_Y(vec3uint64_t * out){
  return out->_y;
}
uint64_t vec3u64_Z(vec3uint64_t * out){
  return out->_z;
}

void vec3char_setX(vec3char_t * out, char x){
  out->_x = x;
}
void vec3char_setY(vec3char_t * out, char y){
  out->_y = y;
}
void vec3char_setZ(vec3char_t * out, char z){
  out->_z = z;
}

char vec3char_X(vec3char_t * out){
  return out->_x;
}
char vec3char_Y(vec3char_t * out){
  return out->_y;
}
char vec3char_Z(vec3char_t * out){
  return out->_z;
}

void vec3f_setX(vec3f_t * out, float x){
  out->_x = x;
}
void vec3f_setY(vec3f_t * out, float y){
  out->_y = y;
}
void vec3f_setZ(vec3f_t * out, float z){
  out->_z = z;
}

float vec3f_X(vec3f_t * out){
  return out->_x;
}
float vec3f_Y(vec3f_t * out){
  return out->_y;
}
float vec3f_Z(vec3f_t * out){
  return out->_z;
}

void vec3d_setX(vec3d_t * out, double x){
  out->_x = x;
}
void vec3d_setY(vec3d_t * out, double y){
  out->_y = y;
}
void vec3d_setZ(vec3d_t * out, double z){
  out->_z = z;
}

double vec3d_X(vec3d_t * out){
  return out->_x;
}
double vec3d_Y(vec3d_t * out){
  return out->_y;
}
double vec3d_Z(vec3d_t * out){
  return out->_z;
}

int8_t * vec3i8_asPOD(vec3int8_t * self,int8_t * out){
  out[0] = vec3i8_X(self);
  out[1] = vec3i8_Y(self);
  out[2] = vec3i8_Z(self);
  return out;
}
uint8_t * vec3u8_asPOD(vec3uint8_t * self,uint8_t * out){
  out[0] = vec3u8_X(self);
  out[1] = vec3u8_Y(self);
  out[2] = vec3u8_Z(self);
  return out;
}
int16_t * vec3i16_asPOD(vec3int16_t * self,int16_t * out){
  out[0] = vec3i16_X(self);
  out[1] = vec3i16_Y(self);
  out[2] = vec3i16_Z(self);
  return out;
}
uint16_t * vec3u16_asPOD(vec3uint16_t * self,uint16_t * out){
  out[0] = vec3u16_X(self);
  out[1] = vec3u16_Y(self);
  out[2] = vec3u16_Z(self);
  return out;
}
int32_t * vec3i32_asPOD(vec3int32_t * self,int32_t * out){
  out[0] = vec3i32_X(self);
  out[1] = vec3i32_Y(self);
  out[2] = vec3i32_Z(self);
  return out;
}
uint32_t * vec3u32_asPOD(vec3uint32_t * self,uint32_t * out){
  out[0] = vec3u32_X(self);
  out[1] = vec3u32_Y(self);
  out[2] = vec3u32_Z(self);
  return out;
}
int64_t * vec3i64_asPOD(vec3int64_t * self,int64_t * out){
  out[0] = vec3i64_X(self);
  out[1] = vec3i64_Y(self);
  out[2] = vec3i64_Z(self);
  return out;
}
uint64_t * vec3u64_asPOD(vec3uint64_t * self,uint64_t * out){
  out[0] = vec3u64_X(self);
  out[1] = vec3u64_Y(self);
  out[2] = vec3u64_Z(self);
  return out;
}
float * vec3f_asPOD(vec3f_t * self,float * out){
  out[0] = vec3f_X(self);
  out[1] = vec3f_Y(self);
  out[2] = vec3f_Z(self);
  return out;
}
double * vec3d_asPOD(vec3d_t * self,double * out){
  out[0] = vec3d_X(self);
  out[1] = vec3d_Y(self);
  out[2] = vec3d_Z(self);
  return out;
}
char * vec3c_asPOD(vec3char_t * self,char * out){
  out[0] = vec3char_X(self);
  out[1] = vec3char_Y(self);
  out[2] = vec3char_Z(self);
  return out;
}




//addition
void vec3i8_add(vec3int8_t * out, vec3int8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
}
void vec3i8_addS(vec3int8_t * out , int8_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
}
vec3int8_t * vec3i8_add_r(vec3int8_t * out,vec3int8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  return out;
}
vec3int8_t * vec3i8_addS_r(vec3int8_t * out,int8_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  return out;
}

void vec3u8_add(vec3uint8_t * out, vec3uint8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
}
void vec3u8_addS(vec3int8_t * out , uint8_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
}
vec3uint8_t * vec3u8_add_r(vec3uint8_t * out,vec3uint8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  return out;
}
vec3uint8_t * vec3u8_addS_r(vec3uint8_t * out,uint8_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  return out;
}

void vec3i16_add(vec3int16_t * out, vec3int16_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
}
void vec3i16_addS(vec3int16_t * out , int16_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
}
vec3int16_t * vec3i16_add_r(vec3int16_t * out,vec3int16_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  return out;
}
vec3int16_t * vec3i16_addS_r(vec3int16_t * out,int16_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  return out;
}

void vec3u16_add(vec3uint16_t * out, vec3uint16_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
}
void vec3u16_addS(vec3int16_t * out , uint16_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
}
vec3uint16_t * vec3u16_add_r(vec3uint16_t * out,vec3uint16_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  return out;
}
vec3uint16_t * vec3u16_addS_r(vec3uint16_t * out,uint16_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  return out;
}

void vec3i32_add(vec3int32_t * out, vec3int32_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
}
void vec3i32_addS(vec3int32_t * out , int32_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
}
vec3int32_t * vec3i32_add_r(vec3int32_t * out,vec3int32_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  return out;
}
vec3int32_t * vec3i32_addS_r(vec3int32_t * out,int32_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  return out;
}

void vec3u32_add(vec3uint32_t * out, vec3uint32_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
}
void vec3u32_addS(vec3int32_t * out , uint32_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
}
vec3uint32_t * vec3u32_add_r(vec3uint32_t * out,vec3uint32_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  return out;
}
vec3uint32_t * vec3u32_addS_r(vec3uint32_t * out,uint32_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  return out;
}

void vec3i64_add(vec3int64_t * out, vec3int64_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
}
void vec3i64_addS(vec3int64_t * out , int64_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
}
vec3int64_t * vec3i64_add_r(vec3int64_t * out,vec3int64_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  return out;
}
vec3int64_t * vec3i64_addS_r(vec3int64_t * out,int64_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  return out;
}

void vec3u64_add(vec3uint64_t * out, vec3uint64_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
}
void vec3u64_addS(vec3int64_t * out , uint64_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
}
vec3uint64_t * vec3u64_add_r(vec3uint64_t * out,vec3uint64_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  return out;
}
vec3uint64_t * vec3u64_addS_r(vec3uint64_t * out,uint64_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  return out;
}

void vec3f_add(vec3f_t * out, vec3f_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
}
void vec3f_addS(vec3f_t * out , float scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
}
vec3f_t * vec3f_add_r(vec3f_t * out,vec3f_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  return out;
}
vec3f_t * vec3f_addS_r(vec3f_t * out, float scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  return out;
}

void vec3d_add(vec3d_t * out, vec3d_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
}
void vec3d_addS(vec3d_t * out , double scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
}
vec3d_t * vec3d_add_r(vec3d_t * out,vec3d_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  return out;
}
vec3d_t * vec3d_addS_r(vec3d_t * out,double scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  return out;
}

//subtraction
void vec3i8_sub(vec3int8_t * out, vec3int8_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
}
void vec3i8_subS(vec3int8_t * out , int8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
}
vec3int8_t * vec3i8_sub_r(vec3int8_t * out,vec3int8_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  return out;
}
vec3int8_t * vec3i8_subS_r(vec3int8_t * out,int8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  return out;
}

void vec3u8_sub(vec3uint8_t * out, vec3uint8_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
}
void vec3u8_subS(vec3int8_t * out , uint8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
}
vec3uint8_t * vec3u8_sub_r(vec3uint8_t * out,vec3uint8_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  return out;
}
vec3uint8_t * vec3u8_subS_r(vec3uint8_t * out,uint8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  return out;
}

void vec3i16_sub(vec3int16_t * out, vec3int16_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
}
void vec3i16_subS(vec3int16_t * out , int16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
}
vec3int16_t * vec3i16_sub_r(vec3int16_t * out,vec3int16_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  return out;
}
vec3int16_t * vec3i16_subS_r(vec3int16_t * out,int16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  return out;
}

void vec3u16_sub(vec3uint16_t * out, vec3uint16_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
}
void vec3u16_subS(vec3int16_t * out , uint16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
}
vec3uint16_t * vec3u16_sub_r(vec3uint16_t * out,vec3uint16_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  return out;
}
vec3uint16_t * vec3u16_subS_r(vec3uint16_t * out,uint16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  return out;
}

void vec3i32_sub(vec3int32_t * out, vec3int32_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
}
void vec3i32_subS(vec3int32_t * out , int32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
}
vec3int32_t * vec3i32_sub_r(vec3int32_t * out,vec3int32_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  return out;
}
vec3int32_t * vec3i32_subS_r(vec3int32_t * out,int32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  return out;
}

void vec3u32_sub(vec3uint32_t * out, vec3uint32_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
}
void vec3u32_subS(vec3uint32_t * out , uint32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
}
vec3uint32_t * vec3u32_sub_r(vec3uint32_t * out,vec3uint32_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  return out;
}
vec3uint32_t * vec3u32_subS_r(vec3uint32_t * out,uint32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  return out;
}

void vec3i64_sub(vec3int64_t * out, vec3int64_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
}
void vec3i64_subS(vec3int64_t * out , int64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
}
vec3int64_t * vec3i64_sub_r(vec3int64_t * out,vec3int64_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  return out;
}
vec3int64_t * vec3i64_subS_r(vec3int64_t * out,int64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  return out;
}

void vec3u64_sub(vec3uint64_t * out, vec3uint64_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
}
void vec3u64_subS(vec3uint64_t * out , uint64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
}
vec3uint64_t * vec3u64_sub_r(vec3uint64_t * out,vec3uint64_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  return out;
}
vec3uint64_t * vec3u64_subS_r(vec3uint64_t * out,uint64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  return out;
}

void vec3f_sub(vec3f_t * out, vec3f_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
}
void vec3f_subS(vec3f_t * out , float scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
}
vec3f_t * vec3f_sub_r(vec3f_t * out,vec3f_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  return out;
}
vec3f_t * vec3f_subS_r(vec3f_t * out, float scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  return out;
}

void vec3d_sub(vec3d_t * out, vec3d_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
}
void vec3d_subS(vec3d_t * out , double scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
}
vec3d_t * vec3d_sub_r(vec3d_t * out,vec3d_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  return out;
}
vec3d_t * vec3d_subS_r(vec3d_t * out,double scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  return out;
}


//Multiplication (only doing 16-bits+)
void vec3i16_mult(vec3int16_t * out, vec3int16_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
}
void vec3i16_multS(vec3int16_t * out , int16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
}
vec3int16_t * vec3i16_mult_r(vec3int16_t * out,vec3int16_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  return out;
}
vec3int16_t * vec3i16_multS_r(vec3int16_t * out,int16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  return out;
}

void vec3u16_mult(vec3uint16_t * out, vec3uint16_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
}
void vec3u16_multS(vec3uint16_t * out , uint16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
}
vec3uint16_t * vec3u16_mult_r(vec3uint16_t * out,vec3uint16_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  return out;
}
vec3uint16_t * vec3u16_multS_r(vec3uint16_t * out,uint16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  return out;
}

void vec3i32_mult(vec3int32_t * out, vec3int32_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
}
void vec3i32_multS(vec3int32_t * out , int32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
}
vec3int32_t * vec3i32_mult_r(vec3int32_t * out,vec3int32_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  return out;
}
vec3int32_t * vec3i32_multS_r(vec3int32_t * out,int32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  return out;
}

void vec3u32_mult(vec3uint32_t * out, vec3uint32_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
}
void vec3u32_multS(vec3uint32_t * out , uint32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
}
vec3uint32_t * vec3u32_mult_r(vec3uint32_t * out,vec3uint32_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  return out;
}
vec3uint32_t * vec3u32_multS_r(vec3uint32_t * out,uint32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  return out;
}

void vec3i64_mult(vec3int64_t * out, vec3int64_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
}
void vec3i64_multS(vec3int64_t * out , int64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
}
vec3int64_t * vec3i64_mult_r(vec3int64_t * out,vec3int64_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  return out;
}
vec3int64_t * vec3i64_multS_r(vec3int64_t * out,int64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  return out;
}

void vec3u64_mult(vec3uint64_t * out, vec3uint64_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
}
void vec3u64_multS(vec3uint64_t * out , uint64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
}
vec3uint64_t * vec3u64_mult_r(vec3uint64_t * out,vec3uint64_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  return out;
}
vec3uint64_t * vec3u64_multS_r(vec3uint64_t * out,uint64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  return out;
}

void vec3f_mult(vec3f_t * out, vec3f_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
}
void vec3f_multS(vec3f_t * out , float scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
}
vec3f_t * vec3f_mult_r(vec3f_t * out,vec3f_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  return out;
}
vec3f_t * vec3f_multS_r(vec3f_t * out, float scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  return out;
}

void vec3d_mult(vec3d_t * out, vec3d_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
}
void vec3d_multS(vec3d_t * out , double scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
}
vec3d_t * vec3d_mult_r(vec3d_t * out,vec3d_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  return out;
}
vec3d_t * vec3d_multS_r(vec3d_t * out,double scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  return out;
}

//Divison (TO BE IMPLEMENTED)


//length
float vec3i8_length(vec3int8_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}
float vec3u8_length(vec3uint8_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}
float vec3i16_length(vec3int16_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}
float vec3u16_length(vec3uint16_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}
float vec3i32_length(vec3int32_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}
float vec3u32_length(vec3uint32_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}
float vec3i64_length(vec3int64_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}
float vec3u64_length(vec3uint64_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}
float vec3c_length(vec3char_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}
float vec3f_length(vec3f_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}
float vec3d_length(vec3d_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y) + (self->_z * self->_z));
}

//dot
float vec3i8_dot(vec3int8_t * left,vec3int8_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}
float vec3u8_dot(vec3uint8_t * left,vec3uint8_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}
float vec3i16_dot(vec3int16_t * left,vec3int16_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}
float vec3u16_dot(vec3uint16_t * left,vec3uint16_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}
float vec3i32_dot(vec3int32_t * left,vec3int32_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}
float vec3u32_dot(vec3uint32_t * left,vec3uint32_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}
float vec3i64_dot(vec3int64_t * left,vec3int64_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}
float vec3u64_dot(vec3uint64_t * left,vec3uint64_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}
float vec3c_dot(vec3char_t * left,vec3char_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}
float vec3f_dot(vec3f_t * left,vec3f_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}
float vec3d_dot(vec3d_t * left,vec3d_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y)  + (left->_z * right->_z));
}


//cross ( out as parameter)
void vec3i8_cross(vec3int8_t * out, vec3int8_t * left, vec3int8_t * right){
	vec3i8_setX(out, (left->_y * right->_z ) - (left->_z * right->_y));
	vec3i8_setY(out, (left->_z * right->_x ) - (left->_x * right->_z));
	vec3i8_setZ(out, (left->_x * right->_y ) - (left->_y * right->_x));
}
void vec3u8_cross(vec3uint8_t * out, vec3uint8_t * left, vec3uint8_t * right){
	vec3u8_setX(out, (left->_y * right->_z ) - (left->_z * right->_y));
	vec3u8_setY(out, (left->_z * right->_x ) - (left->_x * right->_z));
	vec3u8_setZ(out, (left->_x * right->_y ) - (left->_y * right->_x));
}
void vec3i16_cross(vec3int16_t * out, vec3int16_t * left, vec3int16_t * right){
	vec3i16_setX(out, (left->_y * right->_z ) - (left->_z * right->_y));
	vec3i16_setY(out, (left->_z * right->_x ) - (left->_x * right->_z));
	vec3i16_setZ(out, (left->_x * right->_y ) - (left->_y * right->_x));
}
void vec3u16_cross(vec3uint16_t * out, vec3uint16_t * left, vec3uint16_t * right){
	vec3u16_setX(out, (left->_y * right->_z ) - (left->_z * right->_y));
	vec3u16_setY(out, (left->_z * right->_x ) - (left->_x * right->_z));
	vec3u16_setZ(out, (left->_x * right->_y ) - (left->_y * right->_x));
}
void vec3i32_cross(vec3int32_t * out, vec3int32_t * left, vec3int32_t * right){
	vec3i32_setX(out, (left->_y * right->_z ) - (left->_z * right->_y));
	vec3i32_setY(out, (left->_z * right->_x ) - (left->_x * right->_z));
	vec3i32_setZ(out, (left->_x * right->_y ) - (left->_y * right->_x));
}
void vec3u32_cross(vec3uint32_t * out, vec3uint32_t * left, vec3uint32_t * right){
	vec3u32_setX(out, (left->_y * right->_z ) - (left->_z * right->_y));
	vec3u32_setY(out, (left->_z * right->_x ) - (left->_x * right->_z));
	vec3u32_setZ(out, (left->_x * right->_y ) - (left->_y * right->_x));
}
void vec3i64_cross(vec3int64_t * out, vec3int64_t * left, vec3int64_t * right){
	vec3i64_setX(out, (left->_y * right->_z ) - (left->_z * right->_y));
	vec3i64_setY(out, (left->_z * right->_x ) - (left->_x * right->_z));
	vec3i64_setZ(out, (left->_x * right->_y ) - (left->_y * right->_x));
}
void vec3u64_cross(vec3uint64_t * out, vec3uint64_t * left, vec3uint64_t * right){
	vec3u64_setX(out, (left->_y * right->_z ) - (left->_z * right->_y));
	vec3u64_setY(out, (left->_z * right->_x ) - (left->_x * right->_z));
	vec3u64_setZ(out, (left->_x * right->_y ) - (left->_y * right->_x));
}
void vec3f_cross(vec3f_t * out, vec3f_t * left, vec3f_t * right){
	vec3f_setX(out, (left->_y * right->_z ) - (left->_z * right->_y));
	vec3f_setY(out, (left->_z * right->_x ) - (left->_x * right->_z));
	vec3f_setZ(out, (left->_x * right->_y ) - (left->_y * right->_x));
}
void vec3d_cross(vec3d_t * out, vec3d_t * left, vec3d_t * right){
	vec3d_setX(out, (left->_y * right->_z ) - (left->_z * right->_y));
	vec3d_setY(out, (left->_z * right->_x ) - (left->_x * right->_z));
	vec3d_setZ(out, (left->_x * right->_y ) - (left->_y * right->_x));
}

//cross (out returned)
vec3int8_t * vec3i8_cross_r(vec3int8_t * out, vec3int8_t * left, vec3int8_t * right){
	vec3i8_cross(out,left,right);
	return out;
}
vec3uint8_t * vec3u8_cross_r(vec3uint8_t * out, vec3uint8_t * left, vec3uint8_t * right){
	vec3u8_cross(out,left,right);
	return out;
}
vec3int16_t * vec3i16_cross_r(vec3int16_t * out, vec3int16_t * left, vec3int16_t * right){
	vec3i16_cross(out,left,right);
	return out;
}
vec3uint16_t * vec3u16_cross_r(vec3uint16_t * out, vec3uint16_t * left, vec3uint16_t * right){
	vec3u16_cross(out,left,right);
	return out;
}
vec3int32_t * vec3i32_cross_r(vec3int32_t * out, vec3int32_t * left, vec3int32_t * right){
	vec3i32_cross(out,left,right);
	return out;
}
vec3uint32_t * vec3u32_cross_r(vec3uint32_t * out, vec3uint32_t * left, vec3uint32_t * right){
	vec3u32_cross(out,left,right);
	return out;
}
vec3int64_t * vec3i64_cross_r(vec3int64_t * out, vec3int64_t * left, vec3int64_t * right){
	vec3i64_cross(out,left,right);
	return out;
}
vec3uint64_t * vec3u64_cross_r(vec3uint64_t * out, vec3uint64_t * left, vec3uint64_t * right){
	vec3u64_cross(out,left,right);
	return out;
}
vec3f_t * vec3f_cross_r(vec3f_t * out, vec3f_t * left, vec3f_t * right){
	vec3f_cross(out,left,right);
	return out;
}
vec3d_t * vec3d_cross_r(vec3d_t * out, vec3d_t * left, vec3d_t * right){
	vec3d_cross(out,left,right);
	return out;
}

//Misc Functions
void vec3f_normalize(vec3f_t * out, vec3f_t * self){
	out->_x = self->_x;
	out->_y = self->_y;
	out->_z = self->_z;
	float squared = (self->_x * self->_x ) + (self->_y * self->_y ) + (self->_z * self->_z );
	vec3f_multS(out, (1.0f/sqrt(squared) ) );
}
void vec3f_lerp(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage){
	vec3f_t temp;
	temp._x = end->_x - start->_x;
	temp._y = end->_y - start->_y;
	temp._z = end->_z - start->_z;
	vec3f_multS(&temp,percentage);
	out->_x = temp._x;
	out->_y = temp._y;
	out->_z = temp._z;

}
void vec3f_slerp(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage){

	vec3f_t temp;
	float dotSE = vec3f_dot(start,end);
	float clamp;
	if(dotSE > 1.0f){
		clamp = 1.0f;
	}else if(dotSE < -1.0f){
		clamp = -1.0f;
	}else
		clamp = dotSE;

	temp._x = (end->_x - start->_x ) * clamp;
	temp._y = (end->_y - start->_y) * clamp;
	temp._z = (end->_z - start->_z) * clamp;
	float theta = acos(clamp) * percentage;

	//normalize relative vec
	vec3f_normalize(&temp,&temp);
	out->_x = (start->_x * cos(theta)) - (temp._x * sin(theta));
	out->_x = (start->_x * cos(theta)) - (temp._x * sin(theta));
	out->_z = (start->_z * cos(theta)) - (temp._z * sin(theta));
}


void vec3f_nlerp(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage){
	vec3f_lerp(out,start,end,percentage);
	vec3f_normalize(out,out);
}

void vec3d_normalize(vec3d_t * out, vec3d_t * self){
	out->_x = self->_x;
	out->_y = self->_y;
	out->_z = self->_z;
	float squared = (self->_x * self->_x ) + (self->_y * self->_y ) + (self->_z * self->_z );
	vec3d_multS(out, ( 1.0f/sqrt(squared) ) );
}
void vec3d_lerp(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage){
	vec3d_t temp;
	temp._x = end->_x - start->_x;
	temp._y = end->_y - start->_y;
	temp._z = end->_z - start->_z;
	vec3d_multS(&temp,percentage);
	out->_x = temp._x;
	out->_y = temp._y;
	out->_z = temp._z;

}
void vec3d_slerp(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage){

	vec3d_t temp;
	double dotSE = vec3d_dot(start,end);
	double clamp;
	if(dotSE > 1.0f){
		clamp = 1.0f;
	}else if(dotSE < -1.0f){
		clamp = -1.0f;
	}else
		clamp = dotSE;

	temp._x = (end->_x - start->_x ) * clamp;
	temp._y = (end->_y - start->_y) * clamp;
	temp._z = (end->_z - start->_z) * clamp;
	double theta = acos(clamp) * percentage;

	//normalize relative vec
	vec3d_normalize(&temp,&temp);
	out->_x = (start->_x * cos(theta)) - (temp._x * sin(theta));
	out->_x = (start->_x * cos(theta)) - (temp._x * sin(theta));
	out->_z = (start->_z * cos(theta)) - (temp._z * sin(theta));
}

void vec3d_nlerp(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage){
	vec3d_lerp(out,start,end,percentage);
	vec3d_normalize(out,out);
}

//Returned Misc Functions
vec3f_t * vec3f_normalize_r(vec3f_t * out, vec3f_t * self){
	vec3f_normalize(out,self);
	return out;
}

vec3f_t * vec3f_lerp_r(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage){
	vec3f_lerp(out,start,end,percentage);
	return out;
}
vec3f_t * vec3f_slerp_r(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage){
	vec3f_slerp(out,start,end,percentage);
	return out;
}
vec3f_t * vec3f_nlerp_r(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage){
	vec3f_nlerp(out,start,end,percentage);
	return out;
}

vec3d_t * vec3d_normalize_r(vec3d_t * out, vec3d_t * self){
	vec3d_normalize(out,self);
	return out;
}
vec3d_t * vec3d_lerp_r(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage){
	vec3d_lerp(out,start,end,percentage);
	return out;
}
vec3d_t * vec3d_slerp_r(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage){
	vec3d_slerp(out,start,end,percentage);
	return out;
}
vec3d_t * vec3d_nlerp_r(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage){
	vec3d_nlerp(out,start,end,percentage);
	return out;
}



//getSize
size_t vec3i8_getSize(){
  return sizeof(vec3int8_t);
}
size_t vec3u8_getSize(){
  return sizeof(vec3uint8_t);
}
size_t vec3i16_getSize(){
  return sizeof(vec3int16_t);
}
size_t vec3u16_getSize(){
  return sizeof(vec3uint16_t);
}
size_t vec3i32_getSize(){
  return sizeof(vec3int32_t);
}
size_t vec3u32_getSize(){
  return sizeof(vec3uint32_t);
}
size_t vec3i64_getSize(){
  return sizeof(vec3int64_t);
}
size_t vec3u64_getSize(){
  return sizeof(vec3uint64_t);
}
size_t vec3c_getSize(){
  return sizeof(vec3char_t);
}
size_t vec3f_getSize(){
  return sizeof(vec3f_t);
}
size_t vec3d_getSize(){
  return sizeof(vec3d_t);
}




//toString (will need to be freed)
char * vec3i8_toString(vec3int8_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%hhd , %hhd , %hhd \n",self->_x,self->_y,self->_z);
  return buffer;
}
char * vec3u8_toString(vec3uint8_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%hhu , %hhu , %hhu \n",self->_x,self->_y,self->_z);
  return buffer;
}
char * vec3i16_toString(vec3int16_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%hd , %hd , %hd \n",self->_x,self->_y,self->_z);
  return buffer;
}
char * vec3u16_toString(vec3uint16_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%hu , %hu , %hu \n",self->_x,self->_y,self->_z);
  return buffer;
}
char * vec3i32_toString(vec3int32_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%d , %d , %d \n",self->_x,self->_y,self->_z);
  return buffer;
}
char * vec3u32_toString(vec3uint32_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%u , %u , %u \n",self->_x,self->_y,self->_z);
  return buffer;
}
char * vec3i64_toString(vec3int64_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%ld , %ld , %ld \n",self->_x,self->_y,self->_z);
  return buffer;
}
char * vec3u64_toString(vec3uint64_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%lu , %lu , %lu \n",self->_x,self->_y,self->_z);
  return buffer;
}
char * vec3c_toString(vec3char_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%c , %c , %c \n",self->_x,self->_y,self->_z);
  return buffer;
}
char * vec3f_toString(vec3f_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%f , %f , %f \n",self->_x,self->_y,self->_z);
  return buffer;
}
char * vec3d_toString(vec3d_t * self){
  char * buffer = malloc(sizeof(char) * 48);
  sprintf(buffer, "%lf , %lf , %lf \n",self->_x,self->_y,self->_z);
  return buffer;
}

//printing
void printvec3i8(vec3int8_t * vec){
  printf("%hhd , %hhd , %hhd \n",vec->_x,vec->_y,vec->_z);
}
void printvec3u8(vec3uint8_t * vec){
  printf("%hhu , %hhu , %hhu \n",vec->_x,vec->_y,vec->_z);
}
void printvec3i16(vec3int16_t * vec){
  printf("%hd , %hd , %hd \n",vec->_x,vec->_y,vec->_z);
}
void printvec3u16(vec3uint16_t * vec){
  printf("%hu , %hu , %hu \n",vec->_x,vec->_y,vec->_z);
}
void printvec3i32(vec3int32_t * vec){
  printf("%d , %d , %d \n",vec->_x,vec->_y,vec->_z);
}
void printvec3u32(vec3uint32_t * vec){
  printf("%u , %u , %u \n",vec->_x,vec->_y,vec->_z);
}
void printvec3i64(vec3int64_t * vec){
  printf("%ld , %ld , %ld \n",vec->_x,vec->_y,vec->_z);
}
void printvec3u64(vec3uint64_t * vec){
  printf("%lu , %lu , %lu \n",vec->_x,vec->_y,vec->_z);
}
void printvec3c(vec3char_t * vec){
  printf("%c , %c , %c \n",vec->_x,vec->_y,vec->_z);
}
void printvec3f(vec3f_t * vec){
  printf("%f , %f , %f \n",vec->_x,vec->_y,vec->_z);
}
void printvec3d(vec3d_t * vec){
  printf(" %lf , %lf , %lf \n",vec->_x,vec->_y,vec->_z);
}
