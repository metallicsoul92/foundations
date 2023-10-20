#include "../../include/math/vec4.h"
#include "../../include/math/vec2.h"
#include "../../include/math/vec3.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DEFINE_ALL_VEC4
#include "../../include/math/priv/types.h"

//Initalize an already allocated vector.

void initvec4I8(vec4int8_t * out , int8_t x ,int8_t y, int8_t z, int8_t w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}
void initvec4U8(vec4uint8_t * out , uint8_t x ,uint8_t y, uint8_t z, uint8_t w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}
void initvec4I16(vec4int16_t * out , int16_t x ,int16_t y, int16_t z, int16_t w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}
void initvec4U16(vec4uint16_t * out , uint16_t x ,uint16_t y, uint16_t z, uint16_t w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}
void initvec4I32(vec4int32_t * out , int32_t x ,int32_t y, int32_t z, int32_t w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}
void initvec4U32(vec4uint32_t * out , uint32_t x ,uint32_t y, uint32_t z, uint32_t w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}
void initvec4I64(vec4int64_t * out , int64_t x ,int64_t y, int64_t z, int64_t w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}
void initvec4U64(vec4uint64_t * out , uint64_t x ,uint64_t y, uint64_t z, int64_t w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}
void initvec4C(vec4char_t * out , char x ,char y, char z, char w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}
void initvec4F(vec4f_t * out , float x ,float y, float z,float w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}
void initvec4D(vec4d_t * out, double x , double y, double z, double w){
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;
}

//vec2 represents the x,y variables
void initvec4I8_fromVec2(vec4int8_t * out , vec2int8_t * xy , int8_t z, int8_t w){
  out->_x = vec2i8_X(xy);
  out->_y = vec2i8_Y(xy);
  out->_z = z;
  out->_w = w;
}
void initvec4U8_fromVec2(vec4uint8_t * out , vec2uint8_t * xy ,uint8_t z, uint8_t w){
  out->_x = vec2u8_X(xy);
  out->_y = vec2u8_Y(xy);
  out->_z = z;
  out->_w = w;
}
void initvec4I16_fromVec2(vec4int16_t * out , vec2int16_t * xy , int16_t z, int16_t w){
  out->_x = vec2i16_X(xy);
  out->_y = vec2i16_Y(xy);
  out->_z = z;
  out->_w = w;
}
void initvec4U16_fromVec2(vec4uint16_t * out , vec2uint16_t * xy , uint16_t z, uint16_t w){
  out->_x = vec2u16_X(xy);
  out->_y = vec2u16_Y(xy);
  out->_z = z;
  out->_w = w;
}
void initvec4I32_fromVec2(vec4int32_t * out , vec2int32_t * xy , int32_t z, int32_t w){
  out->_x = vec2i32_X(xy);
  out->_y = vec2i32_Y(xy);
  out->_z = z;
  out->_w = w;
}
void initvec4U32_fromVec2(vec4uint32_t * out , vec2uint32_t * xy , uint32_t z, uint32_t w){
  out->_x = vec2u32_X(xy);
  out->_y = vec2u32_Y(xy);
  out->_z = z;
  out->_w = w;
}
void initvec4I64_fromVec2(vec4int64_t * out , vec2int64_t * xy , int64_t z, int64_t w){
  out->_x = vec2i64_X(xy);
  out->_y = vec2i64_Y(xy);
  out->_z = z;
  out->_w = w;
}
void initvec4U64_fromVec2(vec4uint64_t * out , vec2uint64_t * xy ,uint64_t z, uint64_t w){
  out->_x = vec2u64_X(xy);
  out->_y = vec2u64_Y(xy);
  out->_z = z;
  out->_w = w;
}
void initvec4C_fromVec2(vec4char_t * out , vec2char_t * xy ,char z,char w){
  out->_x = vec2char_X(xy);
  out->_y = vec2char_Y(xy);
  out->_z = z;
  out->_w = w;
}
void initvec4F_fromVec2(vec4f_t * out , vec2f_t * xy , float z,float w){
  out->_x = vec2f_X(xy);
  out->_y = vec2f_Y(xy);
  out->_z = z;
  out->_w = w;
}
void initvec4D_fromVec2(vec4d_t * out, vec2d_t * xy , double z,double w){
  out->_x = vec2d_X(xy);
  out->_y = vec2d_Y(xy);
  out->_z = z;
  out->_w = w;
}


//first vec2 represents the x,y variables, the second represents the zw
void initvec4I8_from2Vec2(vec4int8_t * out , vec2int8_t * xy, vec2int8_t *  zw){
  out->_x = vec2i8_X(xy);
  out->_y = vec2i8_Y(xy);
  out->_z = vec2i8_X(zw);
  out->_w = vec2i8_Y(zw);
}
void initvec4U8_from2Vec2(vec4uint8_t * out , vec2uint8_t * xy , vec2uint8_t  * zw){
  out->_x = vec2u8_X(xy);
  out->_y = vec2u8_Y(xy);
  out->_z = vec2u8_X(zw);
  out->_w = vec2u8_Y(zw);
}
void initvec4I16_from2Vec2(vec4int16_t * out , vec2int16_t * xy , vec2int16_t *  zw){
  out->_x = vec2i16_X(xy);
  out->_y = vec2i16_Y(xy);
  out->_z = vec2i16_X(zw);
  out->_w = vec2i16_Y(zw);
}
void initvec4U16_from2Vec2(vec4uint16_t * out , vec2uint16_t * xy , vec2uint16_t  * zw){
  out->_x = vec2u16_X(xy);
  out->_y = vec2u16_Y(xy);
  out->_z = vec2u16_X(zw);
  out->_w = vec2u16_Y(zw);
}
void initvec4I32_from2Vec2(vec4int32_t * out , vec2int32_t * xy , vec2int32_t *  zw){
  out->_x = vec2i32_X(xy);
  out->_y = vec2i32_Y(xy);
  out->_z = vec2i32_X(zw);
  out->_w = vec2i32_Y(zw);
}
void initvec4U32_from2Vec2(vec4uint32_t * out , vec2uint32_t * xy , vec2uint32_t  * zw){
  out->_x = vec2u32_X(xy);
  out->_y = vec2u32_Y(xy);
  out->_z = vec2u32_X(zw);
  out->_w = vec2u32_Y(zw);
}
void initvec4I64_from2Vec2(vec4int64_t * out , vec2int64_t * xy , vec2int64_t  * zw){
  out->_x = vec2i64_X(xy);
  out->_y = vec2i64_Y(xy);
  out->_z = vec2i64_X(zw);
  out->_w = vec2i64_Y(zw);
}
void initvec4U64_from2Vec2(vec4uint64_t * out , vec2uint64_t * xy ,vec2uint64_t  * zw){
  out->_x = vec2u64_X(xy);
  out->_y = vec2u64_Y(xy);
  out->_z = vec2u64_X(zw);
  out->_w = vec2u64_Y(zw);
}
void initvec4C_from2Vec2(vec4char_t * out , vec2char_t * xy ,vec2char_t  * zw){
  out->_x = vec2char_X(xy);
  out->_y = vec2char_Y(xy);
  out->_z = vec2char_X(zw);
  out->_w = vec2char_Y(zw);
}
void initvec4F_from2Vec2(vec4f_t * out , vec2f_t * xy , vec2f_t *  zw){
  out->_x = vec2f_X(xy);
  out->_y = vec2f_Y(xy);
  out->_z = vec2f_X(zw);
  out->_w = vec2f_Y(zw);
}
void initvec4D_from2Vec2(vec4d_t * out, vec2d_t * xy , vec2d_t * zw){
  out->_x = vec2d_X(xy);
  out->_y = vec2d_Y(xy);
  out->_z = vec2d_X(zw);
  out->_w = vec2d_Y(zw);
}

//vec3 represents the x,y, z variables
void initvec4I8_fromVec3(vec4int8_t * out , vec3int8_t * xyz, int8_t w){
  out->_x = vec3i8_X(xyz);
  out->_y = vec3i8_Y(xyz);
  out->_z = vec3i8_Z(xyz);
  out->_w = w;
}
void initvec4U8_fromVec3(vec4uint8_t * out , vec3uint8_t * xyz, uint8_t w){
  out->_x = vec3u8_X(xyz);
  out->_y = vec3u8_Y(xyz);
  out->_z = vec3u8_Z(xyz);
  out->_w = w;
}
void initvec4I16_fromVec3(vec4int16_t * out , vec3int16_t * xyz, int16_t w){
  out->_x = vec3i16_X(xyz);
  out->_y = vec3i16_Y(xyz);
  out->_z = vec3i16_Z(xyz);
  out->_w = w;
}
void initvec4U16_fromVec3(vec4uint16_t * out , vec3uint16_t * xyz, uint16_t w){
  out->_x = vec3u16_X(xyz);
  out->_y = vec3u16_Y(xyz);
  out->_z = vec3u16_Z(xyz);
  out->_w = w;
}
void initvec4I32_fromVec3(vec4int32_t * out , vec3int32_t * xyz, int32_t w){
  out->_x = vec3i32_X(xyz);
  out->_y = vec3i32_Y(xyz);
  out->_z = vec3i32_Z(xyz);
  out->_w = w;
}
void initvec4U32_fromVec3(vec4uint32_t * out , vec3uint32_t * xyz, uint32_t w){
  out->_x = vec3u32_X(xyz);
  out->_y = vec3u32_Y(xyz);
  out->_z = vec3u32_Z(xyz);
  out->_w = w;
}
void initvec4I64_fromVec3(vec4int64_t * out , vec3int64_t * xyz, int64_t w){
  out->_x = vec3i64_X(xyz);
  out->_y = vec3i64_Y(xyz);
  out->_z = vec3i64_Z(xyz);
  out->_w = w;
}
void initvec4U64_fromVec3(vec4uint64_t * out , vec3uint64_t * xyz, uint64_t w){
  out->_x = vec3u64_X(xyz);
  out->_y = vec3u64_Y(xyz);
  out->_z = vec3u64_Z(xyz);
  out->_w = w;
}
void initvec4C_fromVec3(vec4char_t * out , vec3char_t * xyz,char w){
  out->_x = vec3char_X(xyz);
  out->_y = vec3char_Y(xyz);
  out->_z = vec3char_Z(xyz);
  out->_w = w;
}
void initvec4F_fromVec3(vec4f_t * out , vec3f_t * xyz,float w){
  out->_x = vec3f_X(xyz);
  out->_y = vec3f_Y(xyz);
  out->_z = vec3f_Z(xyz);
  out->_w = w;
}
void initvec4D_fromVec3(vec4d_t * out, vec3d_t * xyz,double w){
  out->_x = vec3d_X(xyz);
  out->_y = vec3d_Y(xyz);
  out->_z = vec3d_Z(xyz);
  out->_w = w;
}


//Allocate and initialize Vector
vec4int8_t * allocvec4I8(int8_t x, int8_t y, int8_t z, int8_t w){
  vec4int8_t * out = malloc(sizeof(vec4int8_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}
vec4uint8_t * allocvec4U8(uint8_t x, uint8_t y, uint8_t z, uint8_t w){
  vec4uint8_t * out = malloc(sizeof(vec4uint8_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}
vec4int16_t * allocvec4I16(int16_t x, int16_t y, int16_t z, int16_t w){
  vec4int16_t * out = malloc(sizeof(vec4int16_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}
vec4uint16_t * allocvec4U16(uint16_t x, uint16_t y, uint16_t z, uint16_t w){
  vec4uint16_t * out = malloc(sizeof(vec4uint16_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}
vec4int32_t * allocvec4I32(int32_t x, int32_t y, int32_t z, int32_t w){
  vec4int32_t * out = malloc(sizeof(vec4int32_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}
vec4uint32_t * allocvec4U32(uint32_t x, uint32_t y, uint32_t z, uint32_t w){
  vec4uint32_t * out = malloc(sizeof(vec4uint32_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}
vec4int64_t * allocvec4I64(int64_t x, int64_t y, int64_t z, int64_t w){
  vec4int64_t * out = malloc(sizeof(vec4int64_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}
vec4uint64_t * allocvec4U64(uint64_t x, uint64_t y, uint64_t z, uint64_t w){
  vec4uint64_t * out = malloc(sizeof(vec4uint64_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}
vec4char_t * allocvec4C(char x, char y, char z,char w){
  vec4char_t * out = malloc(sizeof(vec4char_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}
vec4f_t * allocvec4F(float x, float y, float z,float w){
  vec4f_t * out = malloc(sizeof(vec4f_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}
vec4d_t * allocvec4D(double x, double y, double z,double w){
  vec4d_t * out = malloc(sizeof(vec4d_t));
  out->_x = x;
  out->_y = y;
  out->_z = z;
  out->_w = w;

  return out;
}

//Allocate and initialize Vector from vec2
vec4int8_t * allocvec4I8_fromVec2(vec2int8_t * xy, int8_t z, int8_t w){
    return allocvec4I8(vec2i8_X(xy),vec2i8_Y(xy),z,w);
}
vec4uint8_t * allocvec4U8_fromVec2(vec2uint8_t * xy, uint8_t z, uint8_t w){
    return allocvec4U8(vec2u8_X(xy),vec2u8_Y(xy),z,w);
}
vec4int16_t * allocvec4I16_fromVec2(vec2int16_t * xy, int16_t z, int16_t w){
    return allocvec4I16(vec2i16_X(xy),vec2i16_Y(xy),z,w);
}
vec4uint16_t * allocvec4U16_fromVec2(vec2uint16_t * xy, uint16_t z, uint16_t w){
    return allocvec4U16(vec2u16_X(xy),vec2u16_Y(xy),z,w);
}
vec4int32_t * allocvec4I32_fromVec2(vec2int32_t * xy, int32_t z, int32_t w){
    return allocvec4I32(vec2i32_X(xy),vec2i32_Y(xy),z,w);
}
vec4uint32_t * allocvec4U32_fromVec2(vec2uint32_t * xy, uint32_t z, uint32_t w){
    return allocvec4U32(vec2u32_X(xy),vec2u32_Y(xy),z,w);
}
vec4int64_t * allocvec4I64_fromVec2(vec2int64_t * xy, int64_t z, int64_t w){
    return allocvec4I64(vec2i64_X(xy),vec2i64_Y(xy),z,w);
}
vec4uint64_t * allocvec4U64_fromVec2(vec2uint64_t * xy, uint64_t z, uint64_t w){
    return allocvec4U64(vec2u64_X(xy),vec2u64_Y(xy),z,w);
}
vec4char_t * allocvec4C_fromVec2(vec2char_t * xy, char z,char w){
    return allocvec4C(vec2char_X(xy),vec2char_Y(xy),z,w);
}
vec4f_t * allocvec4F_fromVec2(vec2f_t * xy, float z,float w){
    return allocvec4F(vec2f_X(xy),vec2f_Y(xy),z,w);
}
vec4d_t * allocvec4D_fromVec2(vec2d_t * xy, double z,double w){
    return allocvec4D(vec2d_X(xy),vec2d_Y(xy),z,w);
}

//Allocate and initialize Vector from 2 vec2s
vec4int8_t * allocvec4I8_from2Vec2(vec2int8_t * xy, vec2int8_t * zw){
    return allocvec4I8(vec2i8_X(xy),vec2i8_Y(xy),vec2i8_X(zw),vec2i8_Y(zw));
}
vec4uint8_t * allocvec4U8_from2Vec2(vec2uint8_t * xy, vec2uint8_t *  zw){
    return allocvec4U8(vec2u8_X(xy),vec2u8_Y(xy),vec2u8_X(zw),vec2u8_Y(zw));
}
vec4int16_t * allocvec4I16_from2Vec2(vec2int16_t * xy, vec2int16_t *  zw){
    return allocvec4I16(vec2i16_X(xy),vec2i16_Y(xy),vec2i16_X(zw),vec2i16_Y(zw));
}
vec4uint16_t * allocvec4U16_from2Vec2(vec2uint16_t * xy, vec2uint16_t  * zw){
    return allocvec4U16(vec2u16_X(xy),vec2u16_Y(xy),vec2u16_X(zw),vec2u16_Y(zw));
}
vec4int32_t * allocvec4I32_from2Vec2(vec2int32_t * xy, vec2int32_t *  zw){
    return allocvec4I32(vec2i32_X(xy),vec2i32_Y(xy),vec2i32_X(zw),vec2i32_Y(zw));
}
vec4uint32_t * allocvec4U32_from2Vec2(vec2uint32_t * xy, vec2uint32_t  * zw){
    return allocvec4U32(vec2u32_X(xy),vec2u32_Y(xy),vec2u32_X(zw),vec2u32_Y(zw));
}
vec4int64_t * allocvec4I64_from2Vec2(vec2int64_t * xy, vec2int64_t  * zw){
    return allocvec4I64(vec2i64_X(xy),vec2i64_Y(xy),vec2i64_X(zw),vec2i64_Y(zw));
}
vec4uint64_t * allocvec4U64_from2Vec2(vec2uint64_t * xy, vec2uint64_t *  zw){
    return allocvec4U64(vec2u64_X(xy),vec2u64_Y(xy),vec2u64_X(zw),vec2u64_Y(zw));
}
vec4char_t * allocvec4C_from2Vec2(vec2char_t * xy, vec2char_t  * zw){
    return allocvec4C(vec2char_X(xy),vec2char_Y(xy),vec2char_X(zw),vec2char_Y(zw));
}
vec4f_t * allocvec4F_from2Vec2(vec2f_t * xy, vec2f_t  * zw){
    return allocvec4F(vec2f_X(xy),vec2f_Y(xy),vec2f_X(zw),vec2f_Y(zw));
}
vec4d_t * allocvec4D_from2Vec2(vec2d_t * xy, vec2d_t *  zw){
    return allocvec4D(vec2d_X(xy),vec2d_Y(xy),vec2d_X(zw),vec2d_Y(zw));
}

//Allocate and initialize Vector from vec3
vec4int8_t * allocvec4I8_fromVec3(vec3int8_t * xyz, int8_t w){
  return allocvec4I8(vec3i8_X(xyz),vec3i8_Y(xyz),vec3i8_Z(xyz),w);
}
vec4uint8_t * allocvec4U8_fromVec3(vec3uint8_t * xyz, uint8_t w){
  return allocvec4U8(vec3u8_X(xyz),vec3u8_Y(xyz),vec3u8_Z(xyz),w);
}
vec4int16_t * allocvec4I16_fromVec3(vec3int16_t * xyz, int16_t w){
  return allocvec4I16(vec3i16_X(xyz),vec3i16_Y(xyz),vec3i16_Z(xyz),w);
}
vec4uint16_t * allocvec4U16_fromVec3(vec3uint16_t * xyz, uint16_t w){
  return allocvec4U16(vec3u16_X(xyz),vec3u16_Y(xyz),vec3u16_Z(xyz),w);
}
vec4int32_t * allocvec4I32_fromVec3(vec3int32_t * xyz, int32_t w){
  return allocvec4I32(vec3i32_X(xyz),vec3i32_Y(xyz),vec3i32_Z(xyz),w);
}
vec4uint32_t * allocvec4U32_fromVec3(vec3uint32_t * xyz, uint32_t w){
  return allocvec4U32(vec3u32_X(xyz),vec3u32_Y(xyz),vec3u32_Z(xyz),w);
}
vec4int64_t * allocvec4I64_fromVec3(vec3int64_t * xyz, int64_t w){
  return allocvec4I64(vec3i64_X(xyz),vec3i64_Y(xyz),vec3i64_Z(xyz),w);
}
vec4uint64_t * allocvec4U64_fromVec3(vec3uint64_t * xyz, uint64_t w){
  return allocvec4U64(vec3u64_X(xyz),vec3u64_Y(xyz),vec3u64_Z(xyz),w);
}
vec4char_t * allocvec4C_fromVec3(vec3char_t * xyz,char w){
  return allocvec4C(vec3char_X(xyz),vec3char_Y(xyz),vec3char_Z(xyz),w);
}
vec4f_t * allocvec4F_fromVec3(vec3f_t * xyz,float w){
  return allocvec4F(vec3f_X(xyz),vec3f_Y(xyz),vec3f_Z(xyz),w);
}
vec4d_t * allocvec4D_fromVec3(vec3d_t * xyz,double w){
  return allocvec4D(vec3d_X(xyz),vec3d_Y(xyz),vec3d_Z(xyz),w);
}


//Allocate and initialize Vector from string
vec4int8_t * allocvec4I8_fromString(const char * str){
  int8_t x,y,z,w;
  vec4int8_t * out = malloc(sizeof(vec4int8_t));
  sscanf(str,"%hhd , %hhd , %hhd , %hhd \n",&x , &y , &z , &w);
  initvec4I8(out,x,y,z,w);
  return out;
}
vec4uint8_t * allocvec4U8_fromString(const char * str){
  uint8_t x,y,z,w;
  vec4uint8_t * out = malloc(sizeof(vec4uint8_t));
  sscanf(str,"%hhu , %hhu , %hhu , %hhu \n",&x , &y , &z , &w);
  initvec4U8(out,x,y,z,w);
  return out;
}
vec4int16_t * allocvec4I16_fromString(const char * str){
  int16_t x,y,z,w;
  vec4int16_t * out = malloc(sizeof(vec4int16_t));
  sscanf(str,"%hd , %hd , %hd , %hd \n",&x , &y , &z , &w);
  initvec4I16(out,x,y,z,w);
  return out;
}
vec4uint16_t * allocvec4U16_fromString(const char * str){
  uint16_t x,y,z,w;
  vec4uint16_t * out = malloc(sizeof(vec4uint16_t));
  sscanf(str,"%hu , %hu , %hu , %hu \n",&x , &y , &z , &w);
  initvec4U16(out,x,y,z,w);
  return out;
}
vec4int32_t * allocvec4I32_fromString(const char * str){
  int32_t x,y,z,w;
  vec4int32_t * out = malloc(sizeof(vec4int32_t));
  sscanf(str,"%d , %d , %d , %d \n",&x , &y , &z , &w);
  initvec4I32(out,x,y,z,w);
  return out;
}
vec4uint32_t * allocvec4U32_fromString(const char * str){
  uint32_t x,y,z,w;
  vec4uint32_t * out = malloc(sizeof(vec4uint32_t));
  sscanf(str,"%u , %u , %u , %u \n",&x , &y , &z , &w);
  initvec4U32(out,x,y,z,w);
  return out;
}
vec4int64_t * allocvec4I64_fromString(const char * str){
  int64_t x,y,z,w;
  vec4int64_t * out = malloc(sizeof(vec4int64_t));
  sscanf(str,"%ld , %ld , %ld , %ld \n",&x , &y , &z , &w);
  initvec4I64(out,x,y,z,w);
  return out;
}
vec4uint64_t * allocvec4U64_fromString(const char * str){
  uint64_t x,y,z,w;
  vec4uint64_t * out = malloc(sizeof(vec4uint64_t));
  sscanf(str,"%lu , %lu , %lu , %lu \n",&x , &y , &z , &w);
  initvec4U64(out,x,y,z,w);
  return out;
}
vec4char_t * allocvec4C_fromString(const char * str){
  char x,y,z,w;
  vec4char_t * out = malloc(sizeof(vec4char_t));
  sscanf(str,"%c , %c , %c , %c \n",&x , &y , &z , &w);
  initvec4C(out,x,y,z,w);
  return out;
}
vec4f_t * allocvec4F_fromString(const char * str){
  float x,y,z,w;
  vec4f_t * out = malloc(sizeof(vec4f_t));
  sscanf(str,"%f , %f , %f , %f \n",&x , &y , &z , &w);
  initvec4F(out,x,y,z,w);
  return out;
}
vec4d_t * allocvec4D_fromString(const char * str){
  double x,y,z,w;
  vec4d_t * out = malloc(sizeof(vec4d_t));
  sscanf(str,"%lf , %lf , %lf , %lf \n",&x , &y , &z , &w);
  initvec4D(out,x,y,z,w);
  return out;
}



//getters and setters
void vec4i8_setX(vec4int8_t * out, int8_t x){
  out->_x = x;
}
void vec4i8_setY(vec4int8_t * out, int8_t y){
  out->_y = y;
}
void vec4i8_setZ(vec4int8_t * out, int8_t z){
  out->_z = z;
}
void vec4i8_setW(vec4int8_t * out, int8_t w){
  out->_w = w;
}

int8_t vec4i8_X(vec4int8_t * out){
  return out->_x;
}
int8_t vec4i8_Y(vec4int8_t * out){
  return out->_y;
}
int8_t vec4i8_Z(vec4int8_t * out){
  return out->_z;
}
int8_t vec4i8_W(vec4int8_t * out){
  return out->_w;
}


void vec4u8_setX(vec4uint8_t * out, uint8_t x){
  out->_x = x;
}
void vec4u8_setY(vec4uint8_t * out, uint8_t y){
  out->_y = y;
}
void vec4u8_setZ(vec4uint8_t * out, uint8_t z){
  out->_z = z;
}
void vec4u8_setW(vec4int8_t * out, uint8_t w){
  out->_w = w;
}

uint8_t vec4u8_X(vec4uint8_t * out){
  return out->_x;
}
uint8_t vec4u8_Y(vec4uint8_t * out){
  return out->_y;
}
uint8_t vec4u8_Z(vec4uint8_t * out){
  return out->_z;
}
uint8_t vec4u8_W(vec4uint8_t * out){
  return out->_w;
}


void vec4i16_setX(vec4int16_t * out, int16_t x){
  out->_x = x;
}
void vec4i16_setY(vec4int16_t * out, int16_t y){
  out->_y = y;
}
void vec4i16_setZ(vec4int16_t * out, int16_t z){
  out->_z = z;
}
void vec4i16_setW(vec4int16_t * out, int16_t w){
  out->_w = w;
}

int16_t vec4i16_X(vec4int16_t * out){
  return out->_x;
}
int16_t vec4i16_Y(vec4int16_t * out){
  return out->_y;
}
int16_t vec4i16_Z(vec4int16_t * out){
  return out->_z;
}
int16_t vec4i16_W(vec4int16_t * out){
  return out->_w;
}

void vec4u16_setX(vec4uint16_t * out, uint16_t x){
  out->_x = x;
}
void vec4u16_setY(vec4uint16_t * out, uint16_t y){
  out->_y = y;
}
void vec4u16_setZ(vec4uint16_t * out, uint16_t z){
  out->_z = z;
}
void vec4u16_setW(vec4uint16_t * out, uint16_t w){
  out->_w = w;
}

uint16_t vec4u16_X(vec4uint16_t * out){
  return out->_x;
}
uint16_t vec4u16_Y(vec4uint16_t * out){
  return out->_y;
}
uint16_t vec4u16_Z(vec4uint16_t * out){
  return out->_z;
}
uint16_t vec4u16_W(vec4uint16_t * out){
  return out->_w;
}

void vec4i32_setX(vec4int32_t * out, int32_t x){
  out->_x = x;
}
void vec4i32_setY(vec4int32_t * out, int32_t y){
  out->_y = y;
}
void vec4i32_setZ(vec4int32_t * out, int32_t z){
  out->_z = z;
}
void vec4i32_setW(vec4int32_t * out, int32_t w){
  out->_w = w;
}

int32_t vec4i32_X(vec4int32_t * out){
  return out->_x;
}
int32_t vec4i32_Y(vec4int32_t * out){
  return out->_y;
}
int32_t vec4i32_Z(vec4int32_t * out){
  return out->_z;
}
int32_t vec4i32_W(vec4int32_t * out){
  return out->_w;
}

void vec4u32_setX(vec4uint32_t * out, uint32_t x){
  out->_x = x;
}
void vec4u32_setY(vec4uint32_t * out, uint32_t y){
  out->_y = y;
}
void vec4u32_setZ(vec4uint32_t * out, uint32_t z){
  out->_z = z;
}
void vec4u32_setW(vec4uint32_t * out, uint32_t w){
  out->_w = w;
}

uint32_t vec4u32_X(vec4uint32_t * out){
  return out->_x;
}
uint32_t vec4u32_Y(vec4uint32_t * out){
  return out->_y;
}
uint32_t vec4u32_Z(vec4uint32_t * out){
  return out->_z;
}
uint32_t vec4u32_W(vec4uint32_t * out){
  return out->_w;
}

void vec4i64_setX(vec4int64_t * out, int64_t x){
  out->_x = x;
}
void vec4i64_setY(vec4int64_t * out, int64_t y){
  out->_y = y;
}
void vec4i64_setZ(vec4int64_t * out, int64_t z){
  out->_z = z;
}
void vec4i64_setW(vec4int64_t * out, int64_t w){
  out->_w = w;
}

int64_t vec4i64_X(vec4int64_t * out){
  return out->_x;
}
int64_t vec4i64_Y(vec4int64_t * out){
  return out->_y;
}
int64_t vec4i64_Z(vec4int64_t * out){
  return out->_z;
}
int64_t vec4i64_W(vec4int64_t * out){
  return out->_w;
}


void vec4u64_setX(vec4uint64_t * out, uint64_t x){
  out->_x = x;
}
void vec4u64_setY(vec4uint64_t * out, uint64_t y){
  out->_y = y;
}
void vec4u64_setZ(vec4uint64_t * out, uint64_t z){
  out->_z = z;
}
void vec4u64_setW(vec4uint64_t * out, uint64_t w){
  out->_w = w;
}


uint64_t vec4u64_X(vec4uint64_t * out){
  return out->_x;
}
uint64_t vec4u64_Y(vec4uint64_t * out){
  return out->_y;
}
uint64_t vec4u64_Z(vec4uint64_t * out){
  return out->_z;
}
uint64_t vec4u64_W(vec4uint64_t * out){
  return out->_w;
}

void vec4char_setX(vec4char_t * out, char x){
  out->_x = x;
}
void vec4char_setY(vec4char_t * out, char y){
  out->_y = y;
}
void vec4char_setZ(vec4char_t * out, char z){
  out->_z = z;
}
void vec4char_setW(vec4char_t * out, char w){
  out->_w = w;
}


char vec4char_X(vec4char_t * out){
  return out->_x;
}
char vec4char_Y(vec4char_t * out){
  return out->_y;
}
char vec4char_Z(vec4char_t * out){
  return out->_z;
}
char vec4char_W(vec4char_t * out){
  return out->_w;
}


void vec4f_setX(vec4f_t * out, float x){
  out->_x = x;
}
void vec4f_setY(vec4f_t * out, float y){
  out->_y = y;
}
void vec4f_setZ(vec4f_t * out, float z){
  out->_z = z;
}
void vec4f_setW(vec4f_t * out, float w){
  out->_w = w;
}


float vec4f_X(vec4f_t * out){
  return out->_x;
}
float vec4f_Y(vec4f_t * out){
  return out->_y;
}
float vec4f_Z(vec4f_t * out){
  return out->_z;
}
float vec4f_W(vec4f_t * out){
  return out->_w;
}

void vec4d_setX(vec4d_t * out, double x){
  out->_x = x;
}
void vec4d_setY(vec4d_t * out, double y){
  out->_y = y;
}
void vec4d_setZ(vec4d_t * out, double z){
  out->_z = z;
}
void vec4d_setW(vec4d_t * out, double w){
  out->_w = w;
}

double vec4d_X(vec4d_t * out){
  return out->_x;
}
double vec4d_Y(vec4d_t * out){
  return out->_y;
}
double vec4d_Z(vec4d_t * out){
  return out->_z;
}
double vec4d_W(vec4d_t * out){
  return out->_w;
}

int8_t * vec4i8_asPOD(vec4int8_t * self,int8_t * out){
  out[0] = vec4i8_X(self);
  out[1] = vec4i8_Y(self);
  out[2] = vec4i8_Z(self);
  out[3] = vec4i8_W(self);
  return out;
}
uint8_t * vec4u8_asPOD(vec4uint8_t * self,uint8_t * out){
  out[0] = vec4u8_X(self);
  out[1] = vec4u8_Y(self);
  out[2] = vec4u8_Z(self);
  out[3] = vec4u8_W(self);
  return out;
}
int16_t * vec4i16_asPOD(vec4int16_t * self,int16_t * out){
  out[0] = vec4i16_X(self);
  out[1] = vec4i16_Y(self);
  out[2] = vec4i16_Z(self);
  out[3] = vec4i16_W(self);
  return out;
}
uint16_t * vec4u16_asPOD(vec4uint16_t * self,uint16_t * out){
  out[0] = vec4u16_X(self);
  out[1] = vec4u16_Y(self);
  out[2] = vec4u16_Z(self);
  out[3] = vec4u16_W(self);
  return out;
}
int32_t * vec4i32_asPOD(vec4int32_t * self,int32_t * out){
  out[0] = vec4i32_X(self);
  out[1] = vec4i32_Y(self);
  out[2] = vec4i32_Z(self);
  out[3] = vec4i32_W(self);
  return out;
}
uint32_t * vec4u32_asPOD(vec4uint32_t * self,uint32_t * out){
  out[0] = vec4u32_X(self);
  out[1] = vec4u32_Y(self);
  out[2] = vec4u32_Z(self);
  out[3] = vec4u32_W(self);
  return out;
}
int64_t * vec4i64_asPOD(vec4int64_t * self,int64_t * out){
  out[0] = vec4i64_X(self);
  out[1] = vec4i64_Y(self);
  out[2] = vec4i64_Z(self);
  out[3] = vec4i64_W(self);
  return out;
}
uint64_t * vec4u64_asPOD(vec4uint64_t * self,uint64_t * out){
  out[0] = vec4u64_X(self);
  out[1] = vec4u64_Y(self);
  out[2] = vec4u64_Z(self);
  out[3] = vec4u64_W(self);

  return out;
}
float * vec4f_asPOD(vec4f_t * self,float * out){
  out[0] = vec4f_X(self);
  out[1] = vec4f_Y(self);
  out[2] = vec4f_Z(self);
  out[3] = vec4f_W(self);
  return out;
}
double * vec4d_asPOD(vec4d_t * self,double * out){
  out[0] = vec4d_X(self);
  out[1] = vec4d_Y(self);
  out[2] = vec4d_Z(self);
  out[3] = vec4d_W(self);
  return out;
}
char * vec4c_asPOD(vec4char_t * self,char * out){
  out[0] = vec4char_X(self);
  out[1] = vec4char_Y(self);
  out[2] = vec4char_Z(self);
  out[3] = vec4char_W(self);
  return out;
}




//addition
void vec4i8_add(vec4int8_t * out, vec4int8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
}
void vec4i8_addS(vec4int8_t * out , int8_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
}
vec4int8_t * vec4i8_add_r(vec4int8_t * out,vec4int8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
  return out;
}
vec4int8_t * vec4i8_addS_r(vec4int8_t * out,int8_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
  return out;
}

void vec4u8_add(vec4uint8_t * out, vec4uint8_t * other){

  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
}
void vec4u8_addS(vec4uint8_t * out , uint8_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
}
vec4uint8_t * vec4u8_add_r(vec4uint8_t * out,vec4uint8_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
  return out;
}
vec4uint8_t * vec4u8_addS_r(vec4uint8_t * out,uint8_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
  return out;
}

void vec4i16_add(vec4int16_t * out, vec4int16_t * other){

  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
}
void vec4i16_addS(vec4int16_t * out , int16_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
}
vec4int16_t * vec4i16_add_r(vec4int16_t * out,vec4int16_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
  return out;
}
vec4int16_t * vec4i16_addS_r(vec4int16_t * out,int16_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
  return out;
}

void vec4u16_add(vec4uint16_t * out, vec4uint16_t * other){

  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
}
void vec4u16_addS(vec4uint16_t * out , uint16_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
}
vec4uint16_t * vec4u16_add_r(vec4uint16_t * out,vec4uint16_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
  return out;
}
vec4uint16_t * vec4u16_addS_r(vec4uint16_t * out,uint16_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
  return out;
}

void vec4i32_add(vec4int32_t * out, vec4int32_t * other){

  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
}
void vec4i32_addS(vec4int32_t * out , int32_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
}
vec4int32_t * vec4i32_add_r(vec4int32_t * out,vec4int32_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
  return out;
}
vec4int32_t * vec4i32_addS_r(vec4int32_t * out,int32_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
  return out;
}

void vec4u32_add(vec4uint32_t * out, vec4uint32_t * other){

  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
}
void vec4u32_addS(vec4uint32_t * out , uint32_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
}
vec4uint32_t * vec4u32_add_r(vec4uint32_t * out,vec4uint32_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
  return out;
}
vec4uint32_t * vec4u32_addS_r(vec4uint32_t * out,uint32_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
  return out;
}

void vec4i64_add(vec4int64_t * out, vec4int64_t * other){

  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
}
void vec4i64_addS(vec4int64_t * out , int64_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
}
vec4int64_t * vec4i64_add_r(vec4int64_t * out,vec4int64_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
  return out;
}
vec4int64_t * vec4i64_addS_r(vec4int64_t * out,int64_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
  return out;
}

void vec4u64_add(vec4uint64_t * out, vec4uint64_t * other){

  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
}
void vec4u64_addS(vec4uint64_t * out , uint64_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
}
vec4uint64_t * vec4u64_add_r(vec4uint64_t * out,vec4uint64_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
  return out;
}
vec4uint64_t * vec4u64_addS_r(vec4uint64_t * out,uint64_t scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
  return out;
}

void vec4f_add(vec4f_t * out, vec4f_t * other){

  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
}
void vec4f_addS(vec4f_t * out , float scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
}
vec4f_t * vec4f_add_r(vec4f_t * out,vec4f_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
  return out;
}
vec4f_t * vec4f_addS_r(vec4f_t * out, float scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
  return out;
}

void vec4d_add(vec4d_t * out, vec4d_t * other){

  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
}
void vec4d_addS(vec4d_t * out , double scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
}
vec4d_t * vec4d_add_r(vec4d_t * out,vec4d_t * other){
  out->_x += other->_x;
  out->_y += other->_y;
  out->_z += other->_z;
  out->_w += other->_w;
  return out;
}
vec4d_t * vec4d_addS_r(vec4d_t * out,double scalar){
  out->_x += scalar;
  out->_y += scalar;
  out->_z += scalar;
  out->_w += scalar;
  return out;
}

//subtraction
void vec4i8_sub(vec4int8_t * out, vec4int8_t * other){

  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
}
void vec4i8_subS(vec4int8_t * out , int8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
}
vec4int8_t * vec4i8_sub_r(vec4int8_t * out,vec4int8_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
  return out;
}
vec4int8_t * vec4i8_subS_r(vec4int8_t * out,int8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
  return out;
}

void vec4u8_sub(vec4uint8_t * out, vec4uint8_t * other){

  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
}
void vec4u8_subS(vec4int8_t * out , uint8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
}
vec4uint8_t * vec4u8_sub_r(vec4uint8_t * out,vec4uint8_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
  return out;
}
vec4uint8_t * vec4u8_subS_r(vec4uint8_t * out,uint8_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
  return out;
}

void vec4i16_sub(vec4int16_t * out, vec4int16_t * other){

  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
}
void vec4i16_subS(vec4int16_t * out , int16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
}
vec4int16_t * vec4i16_sub_r(vec4int16_t * out,vec4int16_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
  return out;
}
vec4int16_t * vec4i16_subS_r(vec4int16_t * out,int16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
  return out;
}

void vec4u16_sub(vec4uint16_t * out, vec4uint16_t * other){

  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
}
void vec4u16_subS(vec4int16_t * out , uint16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
}
vec4uint16_t * vec4u16_sub_r(vec4uint16_t * out,vec4uint16_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
  return out;
}
vec4uint16_t * vec4u16_subS_r(vec4uint16_t * out,uint16_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
  return out;
}

void vec4i32_sub(vec4int32_t * out, vec4int32_t * other){

  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
}
void vec4i32_subS(vec4int32_t * out , int32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
}
vec4int32_t * vec4i32_sub_r(vec4int32_t * out,vec4int32_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
  return out;
}
vec4int32_t * vec4i32_subS_r(vec4int32_t * out,int32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
  return out;
}

void vec4u32_sub(vec4uint32_t * out, vec4uint32_t * other){

  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
}
void vec4u32_subS(vec4int32_t * out , uint32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
}
vec4uint32_t * vec4u32_sub_r(vec4uint32_t * out,vec4uint32_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
  return out;
}
vec4uint32_t * vec4u32_subS_r(vec4uint32_t * out,uint32_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
  return out;
}

void vec4i64_sub(vec4int64_t * out, vec4int64_t * other){

  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
}
void vec4i64_subS(vec4int64_t * out , int64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
}
vec4int64_t * vec4i64_sub_r(vec4int64_t * out,vec4int64_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
  return out;
}
vec4int64_t * vec4i64_subS_r(vec4int64_t * out,int64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
  return out;
}

void vec4u64_sub(vec4uint64_t * out, vec4uint64_t * other){

  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
}
void vec4u64_subS(vec4int64_t * out , uint64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
}
vec4uint64_t * vec4u64_sub_r(vec4uint64_t * out,vec4uint64_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
  return out;
}
vec4uint64_t * vec4u64_subS_r(vec4uint64_t * out,uint64_t scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
  return out;
}

void vec4f_sub(vec4f_t * out, vec4f_t * other){

  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
}
void vec4f_subS(vec4f_t * out , float scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
}
vec4f_t * vec4f_sub_r(vec4f_t * out,vec4f_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
  return out;
}
vec4f_t * vec4f_subS_r(vec4f_t * out, float scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
  return out;
}

void vec4d_sub(vec4d_t * out, vec4d_t * other){

  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
}
void vec4d_subS(vec4d_t * out , double scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
}
vec4d_t * vec4d_sub_r(vec4d_t * out,vec4d_t * other){
  out->_x -= other->_x;
  out->_y -= other->_y;
  out->_z -= other->_z;
  out->_w -= other->_w;
  return out;
}
vec4d_t * vec4d_subS_r(vec4d_t * out,double scalar){
  out->_x -= scalar;
  out->_y -= scalar;
  out->_z -= scalar;
  out->_w -= scalar;
  return out;
}


//Multiplication (only doing 16-bits+)
void vec4i16_mult(vec4int16_t * out, vec4int16_t * other){

  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
}
void vec4i16_multS(vec4int16_t * out , int16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
}
vec4int16_t * vec4i16_mult_r(vec4int16_t * out,vec4int16_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
  return out;
}
vec4int16_t * vec4i16_multS_r(vec4int16_t * out,int16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
  return out;
}

void vec4u16_mult(vec4uint16_t * out, vec4uint16_t * other){

  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
}
void vec4u16_multS(vec4int16_t * out , uint16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
}
vec4uint16_t * vec4u16_mult_r(vec4uint16_t * out,vec4uint16_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
  return out;
}
vec4uint16_t * vec4u16_multS_r(vec4uint16_t * out,uint16_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
  return out;
}

void vec4i32_mult(vec4int32_t * out, vec4int32_t * other){

  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
}
void vec4i32_multS(vec4int32_t * out , int32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
}
vec4int32_t * vec4i32_mult_r(vec4int32_t * out,vec4int32_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
  return out;
}
vec4int32_t * vec4i32_multS_r(vec4int32_t * out,int32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
  return out;
}

void vec4u32_mult(vec4uint32_t * out, vec4uint32_t * other){

  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
}
void vec4u32_multS(vec4int32_t * out , uint32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
}
vec4uint32_t * vec4u32_mult_r(vec4uint32_t * out,vec4uint32_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
  return out;
}
vec4uint32_t * vec4u32_multS_r(vec4uint32_t * out,uint32_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
  return out;
}

void vec4i64_mult(vec4int64_t * out, vec4int64_t * other){

  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
}
void vec4i64_multS(vec4int64_t * out , int64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
}
vec4int64_t * vec4i64_mult_r(vec4int64_t * out,vec4int64_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
  return out;
}
vec4int64_t * vec4i64_multS_r(vec4int64_t * out,int64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
  return out;
}

void vec4u64_mult(vec4uint64_t * out, vec4uint64_t * other){

  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
}
void vec4u64_multS(vec4int64_t * out , uint64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
}
vec4uint64_t * vec4u64_mult_r(vec4uint64_t * out,vec4uint64_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
  return out;
}
vec4uint64_t * vec4u64_multS_r(vec4uint64_t * out,uint64_t scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
  return out;
}

void vec4f_mult(vec4f_t * out, vec4f_t * other){

  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
}
void vec4f_multS(vec4f_t * out , float scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
}
vec4f_t * vec4f_mult_r(vec4f_t * out,vec4f_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
  return out;
}
vec4f_t * vec4f_multS_r(vec4f_t * out, float scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
  return out;
}

void vec4d_mult(vec4d_t * out, vec4d_t * other){

  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
}
void vec4d_multS(vec4d_t * out , double scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
}
vec4d_t * vec4d_mult_r(vec4d_t * out,vec4d_t * other){
  out->_x *= other->_x;
  out->_y *= other->_y;
  out->_z *= other->_z;
  out->_w *= other->_w;
  return out;
}
vec4d_t * vec4d_multS_r(vec4d_t * out,double scalar){
  out->_x *= scalar;
  out->_y *= scalar;
  out->_z *= scalar;
  out->_w *= scalar;
  return out;
}

//getSize
size_t vec4i8_getSize(){
  return sizeof(vec4int8_t);
}
size_t vec4u8_getSize(){
  return sizeof(vec4uint8_t);
}
size_t vec4i16_getSize(){
  return sizeof(vec4int16_t);
}
size_t vec4u16_getSize(){
  return sizeof(vec4uint16_t);
}
size_t vec4i32_getSize(){
  return sizeof(vec4int32_t);
}
size_t vec4u32_getSize(){
  return sizeof(vec4uint32_t);
}
size_t vec4i64_getSize(){
  return sizeof(vec4int64_t);
}
size_t vec4u64_getSize(){
  return sizeof(vec4uint64_t);
}
size_t vec4c_getSize(){
  return sizeof(vec4char_t);
}
size_t vec4f_getSize(){
  return sizeof(vec4f_t);
}
size_t vec4d_getSize(){
  return sizeof(vec4d_t);
}


//toString (will need to be freed)
char * vec4i8_toString(vec4int8_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%d , %d , %d , %d  \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}
char * vec4u8_toString(vec4uint8_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%u , %u , %u , %u  \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}
char * vec4i16_toString(vec4int16_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%d , %d , %d , %d  \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}
char * vec4u16_toString(vec4uint16_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%u , %u , %u , %u  \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}
char * vec4i32_toString(vec4int32_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%d , %d , %d , %d  \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}
char * vec4u32_toString(vec4uint32_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%u , %u , %u , %u  \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}
char * vec4i64_toString(vec4int64_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%ld , %ld , %ld, %ld \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}
char * vec4u64_toString(vec4uint64_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%lu , %lu, %lu , %lu \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}
char * vec4c_toString(vec4char_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%c , %c , %c , %c \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}
char * vec4f_toString(vec4f_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%f , %f , %f , %f \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}
char * vec4d_toString(vec4d_t * self){
  char * buffer = malloc(sizeof(char) * 64);
  sprintf(buffer, "%lf , %lf , %lf , %lf \n",self->_x,self->_y,self->_z,self->_w);
  return buffer;
}





//printing
void printvec4i8(vec4int8_t * vec){
  printf("%d,%d,%d,%d\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
void printvec4u8(vec4uint8_t * vec){
  printf("%u,%u,%u,%u\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
void printvec4i16(vec4int16_t * vec){
  printf("%d,%d,%d,%d\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
void printvec4u16(vec4uint16_t * vec){
  printf("%u,%u,%u,%u\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
void printvec4i32(vec4int32_t * vec){
  printf("%d,%d,%d,%d\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
void printvec4u32(vec4uint32_t * vec){
  printf("%u,%u,%u,%u\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
void printvec4i64(vec4int64_t * vec){
  printf("%ld,%ld,%ld,%ld\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
void printvec4u64(vec4uint64_t * vec){
  printf("%lu,%lu,%lu,%lu\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
void printvec4c(vec4char_t * vec){
  printf("%c,%c,%c,%c\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
void printvec4f(vec4f_t * vec){
  printf("%f,%f,%f,%f\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
void printvec4d(vec4d_t * vec){
  printf("%lf,%lf,%lf,%lf\n",vec->_x,vec->_y,vec->_z,vec->_w);
}
