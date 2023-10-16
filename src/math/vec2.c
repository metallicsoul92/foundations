#include "../../include/math/vec2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define DEFINE_ALL_VEC2
#include "../../include/math/priv/types.h"

void initvec2I8(vec2int8_t * out , int8_t x ,int8_t y){
  out->_x = x;
  out->_y = y;
}
void initvec2U8(vec2uint8_t * out , uint8_t x ,uint8_t y){
  out->_x = x;
  out->_y = y;
}
void initvec2I16(vec2int16_t * out , int16_t x ,int16_t y){
  out->_x = x;
  out->_y = y;
}
void initvec2U16(vec2uint16_t * out , uint16_t x ,uint16_t y){
  out->_x = x;
  out->_y = y;
}
void initvec2I32(vec2int32_t * out , int32_t x ,int32_t y){
  out->_x = x;
  out->_y = y;
}
void initvec2U32(vec2uint32_t * out , uint32_t x ,uint32_t y){
  out->_x = x;
  out->_y = y;
}
void initvec2I64(vec2int64_t * out , int64_t x ,int64_t y){
  out->_x = x;
  out->_y = y;
}
void initvec2U64(vec2uint64_t * out , uint64_t x ,uint64_t y){
  out->_x = x;
  out->_y = y;
}
void initvec2C(vec2char_t * out , char x ,char y){
  out->_x = x;
  out->_y = y;
}
void initvec2F(vec2f_t * out , float x ,float y){
  out->_x = x;
  out->_y = y;
}
void initvec2D(vec2d_t * out, double x , double y){
  out->_x = x;
  out->_y = y;
}

vec2int8_t * allocvec2I8(int8_t x, int8_t y){
  vec2int8_t * out;
  out = malloc(sizeof(vec2int8_t));
  out->_x = x;
  out->_y = y;
  return out;
}
vec2uint8_t * allocvec2U8(uint8_t x, uint8_t y){
  vec2uint8_t * out;
  out = malloc(sizeof(vec2uint8_t));
  out->_x = x;
  out->_y = y;
  return out;
}
vec2int16_t * allocvec2I16(int16_t x, int16_t y){
  vec2int16_t * out;
  out = malloc(sizeof(vec2int16_t));
  out->_x = x;
  out->_y = y;
  return out;
}
vec2uint16_t * allocvec2U16(uint16_t x, uint16_t y){
  vec2uint16_t * out;
  out = malloc(sizeof(vec2uint16_t));
  out->_x = x;
  out->_y = y;
  return out;
}
vec2int32_t * allocvec2I32(int32_t x, int32_t y){
  vec2int32_t * out;
  out = malloc(sizeof(vec2int32_t));
  out->_x = x;
  out->_y = y;
  return out;
}
vec2uint32_t * allocvec2U32(uint32_t x, uint32_t y){
  vec2uint32_t * out;
  out = malloc(sizeof(vec2uint32_t));
  out->_x = x;
  out->_y = y;
  return out;
}
vec2int64_t * allocvec2I64(int64_t x, int64_t y){
  vec2int64_t * out;
  out = malloc(sizeof(vec2int64_t));
  out->_x = x;
  out->_y = y;
  return out;
}
vec2uint64_t * allocvec2U64(uint64_t x, uint64_t y){
  vec2uint64_t * out;
  out = malloc(sizeof(vec2uint64_t));
  out->_x = x;
  out->_y = y;
  return out;
}
vec2char_t * allocvec2C(char x, char y){
  vec2char_t * out;
  out = malloc(sizeof(vec2char_t));
  out->_x = x;
  out->_y = y;
  return out;
}
vec2f_t * allocvec2F(float x, float y){
  vec2f_t * out;
  out = malloc(sizeof(vec2f_t));
  out->_x = x;
  out->_y = y;
  return out;
}
vec2d_t * allocvec2D(double x, double y){
  vec2d_t * out;
  out = malloc(sizeof(vec2d_t));
  out->_x = x;
  out->_y = y;
  return out;
}

//Allocate and initialize Vector from string
vec2int8_t * allocvec2I8_fromString(const char * str){
  int8_t x,y;
  vec2int8_t * out = malloc(sizeof(vec2int8_t));
  sscanf(str,"%hhd , %hhd \n",&x , &y);
  initvec2I8(out,x,y);
  return out;
}
vec2uint8_t * allocvec2U8_fromString(const char * str){
  uint8_t x,y;
  vec2uint8_t * out = malloc(sizeof(vec2uint8_t));
  sscanf(str,"%hhu , %hhu \n",&x , &y);
  initvec2U8(out,x,y);
  return out;
}
vec2int16_t * allocvec2I16_fromString(const char * str){
  int16_t x,y;
  vec2int16_t * out = malloc(sizeof(vec2int16_t));
  sscanf(str,"%hd , %hd \n",&x , &y);
  initvec2I16(out,x,y);
  return out;
}
vec2uint16_t * allocvec2U16_fromString(const char * str){
  uint16_t x,y;
  vec2uint16_t * out = malloc(sizeof(vec2uint16_t));
  sscanf(str,"%hu , %hu \n",&x , &y);
  initvec2U16(out,x,y);
  return out;
}
vec2int32_t * allocvec2I32_fromString(const char * str){
  int32_t x,y;
  vec2int32_t * out = malloc(sizeof(vec2int32_t));
  sscanf(str,"%d , %d \n",&x , &y);
  initvec2I32(out,x,y);
  return out;
}
vec2uint32_t * allocvec2U32_fromString(const char * str){
  uint32_t x,y;
  vec2uint32_t * out = malloc(sizeof(vec2uint32_t));
  sscanf(str,"%u , %u \n",&x , &y);
  initvec2U32(out,x,y);
  return out;
}
vec2int64_t * allocvec2I64_fromString(const char * str){
  int64_t x,y;
  vec2int64_t * out = malloc(sizeof(vec2int64_t));
  sscanf(str,"%ld , %ld \n",&x , &y);
  initvec2I64(out,x,y);
  return out;
}
vec2uint64_t * allocvec2U64_fromString(const char * str){
  uint64_t x,y;
  vec2uint64_t * out = malloc(sizeof(vec2uint64_t));
  sscanf(str,"%lu , %lu \n",&x , &y);
  initvec2U64(out,x,y);
  return out;
}
vec2char_t * allocvec2C_fromString(const char * str){
  char x,y;
  vec2char_t * out = malloc(sizeof(vec2char_t));
  sscanf(str,"%c , %c \n",&x , &y);
  initvec2C(out,x,y);
  return out;
}
vec2f_t * allocvec2F_fromString(const char * str){
  float x,y;
  vec2f_t * out = malloc(sizeof(vec2f_t));
  sscanf(str,"%f , %f \n",&x , &y);
  initvec2F(out,x,y);
  return out;
}
vec2d_t * allocvec2D_fromString(const char * str){
  double x,y;
  vec2d_t * out = malloc(sizeof(vec2d_t));
  sscanf(str,"%lf , %lf \n",&x , &y);
  initvec2D(out,x,y);
  return out;
}






void vec2i8_setX(vec2int8_t * out, int8_t x){
  out->_x = x;
}
void vec2i8_setY(vec2int8_t * out, int8_t y){
  out->_y = y;
}
int8_t vec2i8_X(vec2int8_t * out){
  return out->_x;
}
int8_t vec2i8_Y(vec2int8_t * out){
  return out->_y;
}

void vec2u8_setX(vec2uint8_t * out, uint8_t x){
  out->_x = x;
}
void vec2u8_setY(vec2uint8_t * out, uint8_t y){
  out->_y = y;
}
uint8_t vec2u8_X(vec2uint8_t * out){
  return out->_x;
}
uint8_t vec2u8_Y(vec2uint8_t * out){
  return out->_y;
}

void vec2i16_setX(vec2int16_t * out, int16_t x){
  out->_x = x;
}
void vec2i16_setY(vec2int16_t * out, int16_t y){
  out->_y = y;
}
int16_t vec2i16_X(vec2int16_t * out){
  return out->_x;
}
int16_t vec2i16_Y(vec2int16_t * out){
  return out->_y;
}

void vec2u16_setX(vec2uint16_t * out, uint16_t x){
  out->_x = x;
}
void vec2u16_setY(vec2uint16_t * out, uint16_t y){
  out->_y = y;
}
uint16_t vec2u16_X(vec2uint16_t * out){
  return out->_x;
}
uint16_t vec2u16_Y(vec2uint16_t * out){
  return out->_y;
}

void vec2i32_setX(vec2int32_t * out, int32_t x){
  out->_x = x;
}
void vec2i32_setY(vec2int32_t * out, int32_t y){
  out->_y = y;
}
int32_t vec2i32_X(vec2int32_t * out){
  return out->_x;
}
int32_t vec2i32_Y(vec2int32_t * out){
  return out->_y;
}

void vec2u32_setX(vec2uint32_t * out, uint32_t x){
  out->_x = x;
}
void vec2u32_setY(vec2uint32_t * out, uint32_t y){
  out->_y = y;
}
uint32_t vec2u32_X(vec2uint32_t * out){
  return out->_x;
}
uint32_t vec2u32_Y(vec2uint32_t * out){
  return out->_y;
}

void vec2i64_setX(vec2int64_t * out, int64_t x){
  out->_x = x;
}
void vec2i64_setY(vec2int64_t * out, int64_t y){
  out->_y = y;
}
int64_t vec2i64_X(vec2int64_t * out){
  return out->_x;
}
int64_t vec2i64_Y(vec2int64_t * out){
  return out->_y;
}

void vec2u64_setX(vec2uint64_t * out, uint64_t x){
  out->_x = x;
}
void vec2u64_setY(vec2uint64_t * out, uint64_t y){
  out->_y = y;
}
uint64_t vec2u64_X(vec2uint64_t * out){
  return out->_x;
}
uint64_t vec2u64_Y(vec2uint64_t * out){
  return out->_y;
}

void vec2char_setX(vec2char_t * out, char x){
  out->_x = x;
}
void vec2char_setY(vec2char_t * out, char y){
  out->_y = y;
}
char vec2char_X(vec2char_t * out){
  return out->_x;
}
char vec2char_Y(vec2char_t * out){
  return out->_y;
}

void vec2f_setX(vec2f_t * out, float x){
  out->_x = x;
}
void vec2f_setY(vec2f_t * out, float y){
  out->_y = y;
}
float vec2f_X(vec2f_t * out){
  return out->_x;
}
float vec2f_Y(vec2f_t * out){
  return out->_y;
}

void vec2d_setX(vec2d_t * out, double x){
  out->_x = x;
}
void vec2d_setY(vec2d_t * out, double y){
  out->_y = y;
}
double vec2d_X(vec2d_t * out){
  return out->_x;
}
double vec2d_Y(vec2d_t * out){
  return out->_y;
}

int8_t * vec2i8_asPOD(vec2int8_t * self,int8_t * out){
  out[0] = vec2i8_X(self);
  out[1] = vec2i8_Y(self);
  return out;
}
uint8_t * vec2u8_asPOD(vec2uint8_t * self,uint8_t * out){
  out[0] = vec2u8_X(self);
  out[1] = vec2u8_Y(self);
  return out;
}
int16_t * vec2i16_asPOD(vec2int16_t * self,int16_t * out){
  out[0] = vec2i16_X(self);
  out[1] = vec2i16_Y(self);
  return out;
}
uint16_t * vec2u16_asPOD(vec2uint16_t * self,uint16_t * out){
  out[0] = vec2u16_X(self);
  out[1] = vec2u16_Y(self);
  return out;
}
int32_t * vec2i32_asPOD(vec2int32_t * self,int32_t * out){
  out[0] = vec2i32_X(self);
  out[1] = vec2i32_Y(self);
  return out;
}
uint32_t * vec2u32_asPOD(vec2uint32_t * self,uint32_t * out){
  out[0] = vec2u32_X(self);
  out[1] = vec2u32_Y(self);
  return out;
}
int64_t * vec2i64_asPOD(vec2int64_t * self,int64_t * out){
  out[0] = vec2i64_X(self);
  out[1] = vec2i64_Y(self);
  return out;
}
uint64_t * vec2u64_asPOD(vec2uint64_t * self,uint64_t * out){
  out[0] = vec2u64_X(self);
  out[1] = vec2u64_Y(self);
  return out;
}
float * vec2f_asPOD(vec2f_t * self,float * out){
  out[0] = vec2f_X(self);
  out[1] = vec2f_Y(self);
  return out;
}
double * vec2d_asPOD(vec2d_t * self,double * out){
  out[0] = vec2d_X(self);
  out[1] = vec2d_Y(self);
  return out;
}
char * vec2c_asPOD(vec2char_t * self,char * out){
  out[0] = vec2char_X(self);
  out[1] = vec2char_Y(self);
  return out;
}




//addition
void vec2i8_add(vec2int8_t * out, vec2int8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
}
void vec2i8_addS(vec2int8_t * out , int8_t scalar){
  out->_x += scalar;
  out->_y += scalar;
}
vec2int8_t * vec2i8_add_r(vec2int8_t * out,vec2int8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;

  return out;
}
vec2int8_t * vec2i8_addS_r(vec2int8_t * out,int8_t scalar){
  out->_x += scalar;
  out->_y += scalar;

  return out;
}

void vec2u8_add(vec2uint8_t * out, vec2uint8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
}
void vec2u8_addS(vec2int8_t * out , uint8_t scalar){
  out->_x += scalar;
  out->_y += scalar;
}
vec2uint8_t * vec2u8_add_r(vec2uint8_t * out,vec2uint8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;

  return out;
}
vec2uint8_t * vec2u8_addS_r(vec2uint8_t * out,uint8_t scalar){
  out->_x += scalar;
  out->_y += scalar;

  return out;
}

void vec2i16_add(vec2int16_t * out, vec2int16_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
}
void vec2i16_addS(vec2int16_t * out , int16_t scalar){
  out->_x += scalar;
  out->_y += scalar;
}
vec2int16_t * vec2i16_add_r(vec2int16_t * out,vec2int16_t * other){
  out->_x += other->_x;
  out->_y += other->_y;

  return out;
}
vec2int16_t * vec2i16_addS_r(vec2int16_t * out,int16_t scalar){
  out->_x += scalar;
  out->_y += scalar;

  return out;
}

void vec2u16_add(vec2uint16_t * out, vec2uint16_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
}
void vec2u16_addS(vec2int16_t * out , uint16_t scalar){
  out->_x += scalar;
  out->_y += scalar;
}
vec2uint16_t * vec2u16_add_r(vec2uint16_t * out,vec2uint16_t * other){
  out->_x += other->_x;
  out->_y += other->_y;

  return out;
}
vec2uint16_t * vec2u16_addS_r(vec2uint16_t * out,uint16_t scalar){
  out->_x += scalar;
  out->_y += scalar;

  return out;
}

void vec2i32_add(vec2int32_t * out, vec2int32_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
}
void vec2i32_addS(vec2int32_t * out , int32_t scalar){
  out->_x += scalar;
  out->_y += scalar;
}
vec2int32_t * vec2i32_add_r(vec2int32_t * out,vec2int32_t * other){
  out->_x += other->_x;
  out->_y += other->_y;

  return out;
}
vec2int32_t * vec2i32_addS_r(vec2int32_t * out,int32_t scalar){
  out->_x += scalar;
  out->_y += scalar;

  return out;
}

void vec2u32_add(vec2uint32_t * out, vec2uint32_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
}
void vec2u32_addS(vec2int32_t * out , uint32_t scalar){
  out->_x += scalar;
  out->_y += scalar;
}
vec2uint32_t * vec2u32_add_r(vec2uint32_t * out,vec2uint32_t * other){
  out->_x += other->_x;
  out->_y += other->_y;

  return out;
}
vec2uint32_t * vec2u32_addS_r(vec2uint32_t * out,uint32_t scalar){
  out->_x += scalar;
  out->_y += scalar;

  return out;
}

void vec2i64_add(vec2int64_t * out, vec2int64_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
}
void vec2i64_addS(vec2int64_t * out , int64_t scalar){
  out->_x += scalar;
  out->_y += scalar;
}
vec2int64_t * vec2i64_add_r(vec2int64_t * out,vec2int64_t * other){
  out->_x += other->_x;
  out->_y += other->_y;

  return out;
}
vec2int64_t * vec2i64_addS_r(vec2int64_t * out,int64_t scalar){
  out->_x += scalar;
  out->_y += scalar;

  return out;
}

void vec2u64_add(vec2uint64_t * out, vec2uint64_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
}
void vec2u64_addS(vec2int64_t * out , uint64_t scalar){
  out->_x += scalar;
  out->_y += scalar;
}
vec2uint64_t * vec2u64_add_r(vec2uint64_t * out,vec2uint64_t * other){
  out->_x += other->_x;
  out->_y += other->_y;

  return out;
}
vec2uint64_t * vec2u64_addS_r(vec2uint64_t * out,uint64_t scalar){
  out->_x += scalar;
  out->_y += scalar;

  return out;
}

void vec2f_add(vec2f_t * out, vec2f_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
}
void vec2f_addS(vec2f_t * out , float scalar){
  out->_x += scalar;
  out->_y += scalar;
}
vec2f_t * vec2f_add_r(vec2f_t * out,vec2f_t * other){
  out->_x += other->_x;
  out->_y += other->_y;

  return out;
}
vec2f_t * vec2f_addS_r(vec2f_t * out,float scalar){
  out->_x += scalar;
  out->_y += scalar;

  return out;
}

void vec2d_add(vec2d_t * out, vec2d_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
}
void vec2d_addS(vec2d_t * out , double scalar){
  out->_x += scalar;
  out->_y += scalar;
}
vec2d_t * vec2d_add_r(vec2d_t * out,vec2d_t * other){
  out->_x += other->_x;
  out->_y += other->_y;

  return out;
}
vec2d_t * vec2d_addS_r(vec2d_t * out,double scalar){
  out->_x += scalar;
  out->_y += scalar;

  return out;
}

//subtraction
void vec2i8_sub(vec2int8_t * out, vec2int8_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
}
void vec2i8_subS(vec2int8_t * out , int8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
}
vec2int8_t * vec2i8_sub_r(vec2int8_t * out,vec2int8_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;

  return out;
}
vec2int8_t * vec2i8_subS_r(vec2int8_t * out,int8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;

  return out;
}

void vec2u8_sub(vec2uint8_t * out, vec2uint8_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
}
void vec2u8_subS(vec2int8_t * out , uint8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
}
vec2uint8_t * vec2u8_sub_r(vec2uint8_t * out,vec2uint8_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;

  return out;
}
vec2uint8_t * vec2u8_subS_r(vec2uint8_t * out,uint8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;

  return out;
}

void vec2i16_sub(vec2int16_t * out, vec2int16_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
}
void vec2i16_subS(vec2int16_t * out , int16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
}
vec2int16_t * vec2i16_sub_r(vec2int16_t * out,vec2int16_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;

  return out;
}
vec2int16_t * vec2i16_subS_r(vec2int16_t * out,int16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;

  return out;
}

void vec2u16_sub(vec2uint16_t * out, vec2uint16_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
}
void vec2u16_subS(vec2int16_t * out , uint16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
}
vec2uint16_t * vec2u16_sub_r(vec2uint16_t * out,vec2uint16_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;

  return out;
}
vec2uint16_t * vec2u16_subS_r(vec2uint16_t * out,uint16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;

  return out;
}

void vec2i32_sub(vec2int32_t * out, vec2int32_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
}
void vec2i32_subS(vec2int32_t * out , int32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
}
vec2int32_t * vec2i32_sub_r(vec2int32_t * out,vec2int32_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;

  return out;
}
vec2int32_t * vec2i32_subS_r(vec2int32_t * out,int32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;

  return out;
}

void vec2u32_sub(vec2uint32_t * out, vec2uint32_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
}
void vec2u32_subS(vec2int32_t * out , uint32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
}
vec2uint32_t * vec2u32_sub_r(vec2uint32_t * out,vec2uint32_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;

  return out;
}
vec2uint32_t * vec2u32_subS_r(vec2uint32_t * out,uint32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;

  return out;
}

void vec2i64_sub(vec2int64_t * out, vec2int64_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
}
void vec2i64_subS(vec2int64_t * out , int64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
}
vec2int64_t * vec2i64_sub_r(vec2int64_t * out,vec2int64_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;

  return out;
}
vec2int64_t * vec2i64_subS_r(vec2int64_t * out,int64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;

  return out;
}

void vec2u64_sub(vec2uint64_t * out, vec2uint64_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
}
void vec2u64_subS(vec2int64_t * out , uint64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
}
vec2uint64_t * vec2u64_sub_r(vec2uint64_t * out,vec2uint64_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;

  return out;
}
vec2uint64_t * vec2u64_subS_r(vec2uint64_t * out,uint64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;

  return out;
}

void vec2f_sub(vec2f_t * out, vec2f_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
}
void vec2f_subS(vec2f_t * out , float scalar){
  out->_x -= scalar;
  out->_y -= scalar;
}
vec2f_t * vec2f_sub_r(vec2f_t * out,vec2f_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;

  return out;
}
vec2f_t * vec2f_subS_r(vec2f_t * out,float scalar){
  out->_x -= scalar;
  out->_y -= scalar;

  return out;
}

void vec2d_sub(vec2d_t * out, vec2d_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
}
void vec2d_subS(vec2d_t * out , double scalar){
  out->_x -= scalar;
  out->_y -= scalar;
}
vec2d_t * vec2d_sub_r(vec2d_t * out,vec2d_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;

  return out;
}
vec2d_t * vec2d_subS_r(vec2d_t * out,double scalar){
  out->_x -= scalar;
  out->_y -= scalar;

  return out;
}

//Multiplication
void vec2i8_mult(vec2int8_t * out, vec2int8_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
}
void vec2i8_multS(vec2int8_t * out , int8_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
}
vec2int8_t * vec2i8_mult_r(vec2int8_t * out,vec2int8_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;

  return out;
}
vec2int8_t * vec2i8_multS_r(vec2int8_t * out,int8_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;

  return out;
}

void vec2u8_mult(vec2uint8_t * out, vec2uint8_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
}
void vec2u8_multS(vec2int8_t * out , uint8_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
}
vec2uint8_t * vec2u8_mult_r(vec2uint8_t * out,vec2uint8_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;

  return out;
}
vec2uint8_t * vec2u8_multS_r(vec2uint8_t * out,uint8_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;

  return out;
}

void vec2i16_mult(vec2int16_t * out, vec2int16_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
}
void vec2i16_multS(vec2int16_t * out , int16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
}
vec2int16_t * vec2i16_mult_r(vec2int16_t * out,vec2int16_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;

  return out;
}
vec2int16_t * vec2i16_multS_r(vec2int16_t * out,int16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;

  return out;
}

void vec2u16_mult(vec2uint16_t * out, vec2uint16_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
}
void vec2u16_multS(vec2int16_t * out , uint16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
}
vec2uint16_t * vec2u16_mult_r(vec2uint16_t * out,vec2uint16_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;

  return out;
}
vec2uint16_t * vec2u16_multS_r(vec2uint16_t * out,uint16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;

  return out;
}

void vec2i32_mult(vec2int32_t * out, vec2int32_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
}
void vec2i32_multS(vec2int32_t * out , int32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
}
vec2int32_t * vec2i32_mult_r(vec2int32_t * out,vec2int32_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;

  return out;
}
vec2int32_t * vec2i32_multS_r(vec2int32_t * out,int32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;

  return out;
}

void vec2u32_mult(vec2uint32_t * out, vec2uint32_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
}
void vec2u32_multS(vec2int32_t * out , uint32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
}
vec2uint32_t * vec2u32_mult_r(vec2uint32_t * out,vec2uint32_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;

  return out;
}
vec2uint32_t * vec2u32_multS_r(vec2uint32_t * out,uint32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;

  return out;
}

void vec2i64_mult(vec2int64_t * out, vec2int64_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
}
void vec2i64_multS(vec2int64_t * out , int64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
}
vec2int64_t * vec2i64_mult_r(vec2int64_t * out,vec2int64_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;

  return out;
}
vec2int64_t * vec2i64_multS_r(vec2int64_t * out,int64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;

  return out;
}

void vec2u64_mult(vec2uint64_t * out, vec2uint64_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
}
void vec2u64_multS(vec2int64_t * out , uint64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
}
vec2uint64_t * vec2u64_mult_r(vec2uint64_t * out,vec2uint64_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;

  return out;
}
vec2uint64_t * vec2u64_multS_r(vec2uint64_t * out,uint64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;

  return out;
}

void vec2f_mult(vec2f_t * out, vec2f_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
}
void vec2f_multS(vec2f_t * out , float scalar){
  out->_x *= scalar;
  out->_y *= scalar;
}
vec2f_t * vec2f_mult_r(vec2f_t * out,vec2f_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;

  return out;
}
vec2f_t * vec2f_multS_r(vec2f_t * out,float scalar){
  out->_x *= scalar;
  out->_y *= scalar;

  return out;
}

void vec2d_mult(vec2d_t * out, vec2d_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
}
void vec2d_multS(vec2d_t * out , double scalar){
  out->_x *= scalar;
  out->_y *= scalar;
}
vec2d_t * vec2d_mult_r(vec2d_t * out,vec2d_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;

  return out;
}
vec2d_t * vec2d_multS_r(vec2d_t * out,double scalar){
  out->_x *= scalar;
  out->_y *= scalar;

  return out;
}

//division (TO BE IMPLEMENTED)




//length
float vec2i8_length(vec2int8_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}
float vec2u8_length(vec2uint8_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}
float vec2i16_length(vec2int16_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}
float vec2u16_length(vec2uint16_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}
float vec2i32_length(vec2int32_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}
float vec2u32_length(vec2uint32_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}
float vec2i64_length(vec2int64_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}
float vec2u64_length(vec2uint64_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}
float vec2c_length(vec2char_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}
float vec2f_length(vec2f_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}
float vec2d_length(vec2d_t * self){
	return sqrt((self->_x * self->_x) + (self->_y * self->_y));
}

//dot
float vec2i8_dot(vec2int8_t * left,vec2int8_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}
float vec2u8_dot(vec2uint8_t * left,vec2uint8_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}
float vec2i16_dot(vec2int16_t * left,vec2int16_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}
float vec2u16_dot(vec2uint16_t * left,vec2uint16_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}
float vec2i32_dot(vec2int32_t * left,vec2int32_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}
float vec2u32_dot(vec2uint32_t * left,vec2uint32_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}
float vec2i64_dot(vec2int64_t * left,vec2int64_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}
float vec2u64_dot(vec2uint64_t * left,vec2uint64_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}
float vec2c_dot(vec2char_t * left,vec2char_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}
float vec2f_dot(vec2f_t * left,vec2f_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}
float vec2d_dot(vec2d_t * left,vec2d_t * right){
	return sqrt((left->_x * right->_x) + (left->_y * right->_y));
}

//getSize
size_t vec2i8_getSize(){
  return sizeof(vec2int8_t);
}
size_t vec2u8_getSize(){
  return sizeof(vec2uint8_t);
}
size_t vec2i16_getSize(){
  return sizeof(vec2int16_t);
}
size_t vec2u16_getSize(){
  return sizeof(vec2uint16_t);
}
size_t vec2i32_getSize(){
  return sizeof(vec2int32_t);
}
size_t vec2u32_getSize(){
  return sizeof(vec2uint32_t);
}
size_t vec2i64_getSize(){
  return sizeof(vec2int64_t);
}
size_t vec2u64_getSize(){
  return sizeof(vec2uint64_t);
}
size_t vec2c_getSize(){
  return sizeof(vec2char_t);
}
size_t vec2f_getSize(){
  return sizeof(vec2f_t);
}
size_t vec2d_getSize(){
  return sizeof(vec2d_t);
}


//toString (will need to be freed)
char * vec2i8_toString(vec2int8_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%hhd , %hhd \n",self->_x,self->_y);
  return buffer;
}
char * vec2u8_toString(vec2uint8_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%hhu , %hhu \n",self->_x,self->_y);
  return buffer;
}
char * vec2i16_toString(vec2int16_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%hd , %hd \n",self->_x,self->_y);
  return buffer;
}
char * vec2u16_toString(vec2uint16_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%hu , %hu \n",self->_x,self->_y);
  return buffer;
}
char * vec2i32_toString(vec2int32_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%d , %d \n",self->_x,self->_y);
  return buffer;
}
char * vec2u32_toString(vec2uint32_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%u , %u \n",self->_x,self->_y);
  return buffer;
}
char * vec2i64_toString(vec2int64_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%ld , %ld \n",self->_x,self->_y);
  return buffer;
}
char * vec2u64_toString(vec2uint64_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%lu , %lu \n",self->_x,self->_y);
  return buffer;
}
char * vec2c_toString(vec2char_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%c , %c \n",self->_x,self->_y);
  return buffer;
}
char * vec2f_toString(vec2f_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%f , %f \n",self->_x,self->_y);
  return buffer;
}
char * vec2d_toString(vec2d_t * self){
  char * buffer = malloc(sizeof(char) * 32);
  sprintf(buffer, "%lf , %lf \n",self->_x,self->_y);
  return buffer;
}







//printing
void printVec2i8(vec2int8_t * vec){
  printf("%hhd , %hhd\n",vec->_x,vec->_y);
}
void printVec2u8(vec2uint8_t * vec){
  printf("%hhu , %hhu\n",vec->_x,vec->_y);
}
void printVec2i16(vec2int16_t * vec){
  printf("%hd , %hd\n",vec->_x,vec->_y);
}
void printVec2u16(vec2uint16_t * vec){
  printf("%hu , %hu\n",vec->_x,vec->_y);
}
void printVec2i32(vec2int32_t * vec){
  printf("%d , %d\n",vec->_x,vec->_y);
}
void printVec2u32(vec2uint32_t * vec){
  printf("%u , %u\n",vec->_x,vec->_y);
}
void printVec2i64(vec2int64_t * vec){
  printf("%ld , %ld\n",vec->_x,vec->_y);
}
void printVec2u64(vec2uint64_t * vec){
  printf("%lu , %lu\n",vec->_x,vec->_y);
}
void printVec2c(vec2char_t * vec){
  printf("%c , %c\n",vec->_x,vec->_y);
}
void printVec2f(vec2f_t * vec){
  printf("%f , %f\n",vec->_x,vec->_y);
}
void printVec2d(vec2d_t * vec){
  printf("%lf , %lf\n",vec->_x,vec->_y);
}
