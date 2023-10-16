#ifndef FOUNDATIONS_MATH_VEC3_H
#define FOUNDATIONS_MATH_VEC3_H

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

#ifndef VEC2_DEFINED

  #ifndef VEC2I8_DEFINED
  typedef struct vector2int8 vec2int8_t;
  #define VEC2I8_DEFINED 1
  #endif

  #ifndef VEC2U8_DEFINED
  typedef struct vector2uint8 vec2uint8_t;
  #define VEC2U8_DEFINED 1
  #endif

  #ifndef VEC2I16_DEFINED
  typedef struct vector2int16 vec2int16_t;
  #define VEC2I16_DEFINED 1
  #endif

  #ifndef VEC2U16_DEFINED
  typedef struct vector2uint16 vec2uint16_t;
  #define VEC2U16_DEFINED 1
  #endif

  #ifndef VEC2I32_DEFINED
  typedef struct vector2int32 vec2int32_t;
  #define VEC2I32_DEFINED 1
  #endif

  #ifndef VEC2U32_DEFINED
  typedef struct vector2uint32 vec2uint32_t;
  #define VEC2U32_DEFINED 1
  #endif

  #ifndef VEC2I64_DEFINED
  typedef struct vector2int64 vec2int64_t;
  #define VEC2I64_DEFINED 1
  #endif

  #ifndef VEC2U64_DEFINED
  typedef struct vector2uint64 vec2uint64_t;
  #define VEC2U64_DEFINED 1
  #endif

  #ifndef VEC2C_DEFINED
  typedef struct vector2char vec2char_t;
  #define VEC2C_DEFINED 1
  #endif

  #ifndef VEC2F_DEFINED
  typedef struct vector2float vec2f_t;
  #define VEC2F_DEFINED 1
  #endif

  #ifndef VEC2D_DEFINED
  typedef struct vector2double vec2d_t;
  #define VEC2D_DEFINED 1
  #endif

#define VEC2_DEFINED 1
#endif

#ifndef VEC3_DEFINED

  #ifndef VEC3I8_DEFINED
  typedef struct vector3int8 vec3int8_t;
  #define VEC3I8_DEFINED 1
  #endif

  #ifndef VEC3U8_DEFINED
  typedef struct vector3uint8 vec3uint8_t;
  #define VEC3U8_DEFINED 1
  #endif

  #ifndef VEC3I16_DEFINED
  typedef struct vector3int16 vec3int16_t;
  #define VEC3I16_DEFINED 1
  #endif

  #ifndef VEC3U16_DEFINED
  typedef struct vector3uint16 vec3uint16_t;
  #define VEC3U16_DEFINED 1
  #endif

  #ifndef VEC3I32_DEFINED
  typedef struct vector3int32 vec3int32_t;
  #define VEC3I32_DEFINED 1
  #endif

  #ifndef VEC3U32_DEFINED
  typedef struct vector3uint32 vec3uint32_t;
  #define VEC3U32_DEFINED 1
  #endif

  #ifndef VEC3I64_DEFINED
  typedef struct vector3int64 vec3int64_t;
  #define VEC3I64_DEFINED 1
  #endif

  #ifndef VEC3U64_DEFINED
  typedef struct vector3uint64 vec3uint64_t;
  #define VEC3U64_DEFINED 1
  #endif

  #ifndef VEC3C_DEFINED
  typedef struct vector3char vec3char_t;
  #define VEC3C_DEFINED 1
  #endif

  #ifndef VEC3F_DEFINED
  typedef struct vector3float vec3f_t;
  #define VEC3F_DEFINED 1
  #endif

  #ifndef VEC3D_DEFINED
  typedef struct vector3double vec3d_t;
  #define VEC3D_DEFINED 1
  #endif

#define VEC3_DEFINED 1
#endif



/**
Convention Discussion:

void function(type * out, ...etc);
type * function_r(...etc);

**/

//Initalize an already allocated vector.

void initvec3I8(vec3int8_t * out , int8_t x ,int8_t y, int8_t z);
void initvec3U8(vec3uint8_t * out , uint8_t x ,uint8_t y, uint8_t z);
void initvec3I16(vec3int16_t * out , int16_t x ,int16_t y, int16_t z);
void initvec3U16(vec3uint16_t * out , uint16_t x ,uint16_t y, uint16_t z);
void initvec3I32(vec3int32_t * out , int32_t x ,int32_t y, int32_t z);
void initvec3U32(vec3uint32_t * out , uint32_t x ,uint32_t y, uint32_t z);
void initvec3I64(vec3int64_t * out , int64_t x ,int64_t y, int64_t z);
void initvec3U64(vec3uint64_t * out , uint64_t x ,uint64_t y, uint64_t z);
void initvec3C(vec3char_t * out , char x ,char y, char z);
void initvec3F(vec3f_t * out , float x ,float y, float z);
void initvec3D(vec3d_t * out, double x , double y, double z);

//vec2 represents the x,y variables
void initvec3I8_fromVec2(vec3int8_t * out , vec2int8_t * xy , int8_t z);
void initvec3U8_fromVec2(vec3uint8_t * out , vec2uint8_t * xy ,uint8_t z);
void initvec3I16_fromVec2(vec3int16_t * out , vec2int16_t * xy , int16_t z);
void initvec3U16_fromVec2(vec3uint16_t * out , vec2uint16_t * xy , uint16_t z);
void initvec3I32_fromVec2(vec3int32_t * out , vec2int32_t * xy , int32_t z);
void initvec3U32_fromVec2(vec3uint32_t * out , vec2uint32_t * xy , uint32_t z);
void initvec3I64_fromVec2(vec3int64_t * out , vec2int64_t * xy , int64_t z);
void initvec3U64_fromVec2(vec3uint64_t * out , vec2uint64_t * xy ,uint64_t z);
void initvec3C_fromVec2(vec3char_t * out , vec2char_t * xy ,char z);
void initvec3F_fromVec2(vec3f_t * out , vec2f_t * xy , float z);
void initvec3D_fromVec2(vec3d_t * out, vec2d_t * xy , double z);

//Allocate and initialize Vector
vec3int8_t * allocvec3I8(int8_t x, int8_t y, int8_t z);
vec3uint8_t * allocvec3U8(uint8_t x, uint8_t y, uint8_t z);
vec3int16_t * allocvec3I16(int16_t x, int16_t y, int16_t z );
vec3uint16_t * allocvec3U16(uint16_t x, uint16_t y, uint16_t z);
vec3int32_t * allocvec3I32(int32_t x, int32_t y, int32_t z);
vec3uint32_t * allocvec3U32(uint32_t x, uint32_t y, uint32_t z);
vec3int64_t * allocvec3I64(int64_t x, int64_t y, int64_t z);
vec3uint64_t * allocvec3U64(uint64_t x, uint64_t y, uint64_t z);
vec3char_t * allocvec3C(char x, char y, char z);
vec3f_t * allocvec3F(float x, float y, float z);
vec3d_t * allocvec3D(double x, double y, double z);

//Allocate and initialize Vector from vec2
vec3int8_t * allocvec3I8_fromVec2(vec2int8_t * xy, int8_t z);
vec3uint8_t * allocvec3U8_fromVec2(vec2uint8_t * xy, uint8_t z);
vec3int16_t * allocvec3I16_fromVec2(vec2int16_t * xy, int16_t z );
vec3uint16_t * allocvec3U16_fromVec2(vec2uint16_t * xy, uint16_t z);
vec3int32_t * allocvec3I32_fromVec2(vec2int32_t * xy, int32_t z);
vec3uint32_t * allocvec3U32_fromVec2(vec2uint32_t * xy, uint32_t z);
vec3int64_t * allocvec3I64_fromVec2(vec2int64_t * xy, int64_t z);
vec3uint64_t * allocvec3U64_fromVec2(vec2uint64_t * xy, uint64_t z);
vec3char_t * allocvec3C_fromVec2(vec2char_t * xy, char z);
vec3f_t * allocvec3F_fromVec2(vec2f_t * xy, float z);
vec3d_t * allocvec3D_fromVec2(vec2d_t * xy, double z);

//Allocate and initialize Vector from string
vec3int8_t * allocvec3I8_fromString(const char * str);
vec3uint8_t * allocvec3U8_fromString(const char * str);
vec3int16_t * allocvec3I16_fromString(const char * str);
vec3uint16_t * allocvec3U16_fromString(const char * str);
vec3int32_t * allocvec3I32_fromString(const char * str);
vec3uint32_t * allocvec3U32_fromString(const char * str);
vec3int64_t * allocvec3I64_fromString(const char * str);
vec3uint64_t * allocvec3U64_fromString(const char * str);
vec3char_t * allocvec3C_fromString(const char * str);
vec3f_t * allocvec3F_fromString(const char * str);
vec3d_t * allocvec3D_fromString(const char * str);


//getters and setters
void vec3i8_setX(vec3int8_t * out, int8_t x);
void vec3i8_setY(vec3int8_t * out, int8_t y);
void vec3i8_setZ(vec3int8_t * out, int8_t z);

int8_t vec3i8_X(vec3int8_t * out);
int8_t vec3i8_Y(vec3int8_t * out);
int8_t vec3i8_Z(vec3int8_t * out);

void vec3u8_setX(vec3uint8_t * out, uint8_t x);
void vec3u8_setY(vec3uint8_t * out, uint8_t y);
void vec3u8_setZ(vec3uint8_t * out, uint8_t z);

uint8_t vec3u8_X(vec3uint8_t * out);
uint8_t vec3u8_Y(vec3uint8_t * out);
uint8_t vec3u8_Z(vec3uint8_t * out);

void vec3i16_setX(vec3int16_t * out, int16_t x);
void vec3i16_setY(vec3int16_t * out, int16_t y);
void vec3i16_setZ(vec3int16_t * out, int16_t z);

int16_t vec3i16_X(vec3int16_t * out);
int16_t vec3i16_Y(vec3int16_t * out);
int16_t vec3i16_Z(vec3int16_t * out);

void vec3u16_setX(vec3uint16_t * out, uint16_t x);
void vec3u16_setY(vec3uint16_t * out, uint16_t y);
void vec3u16_setZ(vec3uint16_t * out, uint16_t z);


uint16_t vec3u16_X(vec3uint16_t * out);
uint16_t vec3u16_Y(vec3uint16_t * out);
uint16_t vec3u16_Z(vec3uint16_t * out);

void vec3i32_setX(vec3int32_t * out, int32_t x);
void vec3i32_setY(vec3int32_t * out, int32_t y);
void vec3i32_setZ(vec3int32_t * out, int32_t z);

int32_t vec3i32_X(vec3int32_t * out);
int32_t vec3i32_Y(vec3int32_t * out);
int32_t vec3i32_Z(vec3int32_t * out);

void vec3u32_setX(vec3uint32_t * out, uint32_t x);
void vec3u32_setY(vec3uint32_t * out, uint32_t y);
void vec3u32_setZ(vec3uint32_t * out, uint32_t z);

uint32_t vec3u32_X(vec3uint32_t * out);
uint32_t vec3u32_Y(vec3uint32_t * out);
uint32_t vec3u32_Z(vec3uint32_t * out);

void vec3i64_setX(vec3int64_t * out, int64_t x);
void vec3i64_setY(vec3int64_t * out, int64_t y);
void vec3i64_setZ(vec3int64_t * out, int64_t z);

int64_t vec3i64_X(vec3int64_t * out);
int64_t vec3i64_Y(vec3int64_t * out);
int64_t vec3i64_Z(vec3int64_t * out);

void vec3u64_setX(vec3uint64_t * out, uint64_t x);
void vec3u64_setY(vec3uint64_t * out, uint64_t y);
void vec3u64_setZ(vec3uint64_t * out, uint64_t z);

uint64_t vec3u64_X(vec3uint64_t * out);
uint64_t vec3u64_Y(vec3uint64_t * out);
uint64_t vec3u64_Z(vec3uint64_t * out);

void vec3char_setX(vec3char_t * out, char x);
void vec3char_setY(vec3char_t * out, char y);
void vec3char_setZ(vec3char_t * out, char z);


char vec3char_X(vec3char_t * out);
char vec3char_Y(vec3char_t * out);
char vec3char_Z(vec3char_t * out);


void vec3f_setX(vec3f_t * out, float x);
void vec3f_setY(vec3f_t * out, float y);
void vec3f_setZ(vec3f_t * out, float z);

float vec3f_X(vec3f_t * out);
float vec3f_Y(vec3f_t * out);
float vec3f_Z(vec3f_t * out);


void vec3d_setX(vec3d_t * out, double x);
void vec3d_setY(vec3d_t * out, double y);
void vec3d_setZ(vec3d_t * out, double z);

double vec3d_X(vec3d_t * out);
double vec3d_Y(vec3d_t * out);
double vec3d_Z(vec3d_t * out);


//asPOD. Gives data as a plain-old-data type
//note: in order for this to be threadsafe, i need to setup
//user-provided storage.

int8_t * vec3i8_asPOD(vec3int8_t * self,int8_t * out);
uint8_t * vec3u8_asPOD(vec3uint8_t * self,uint8_t * out);
int16_t * vec3i16_asPOD(vec3int16_t * self,int16_t * out);
uint16_t * vec3u16_asPOD(vec3uint16_t * self,uint16_t * out);
int32_t * vec3i32_asPOD(vec3int32_t * self,int32_t * out);
uint32_t * vec3u32_asPOD(vec3uint32_t * self,uint32_t * out);
int64_t * vec3i64_asPOD(vec3int64_t * self,int64_t * out);
uint64_t * vec3u64_asPOD(vec3uint64_t * self,uint64_t * out);
float * vec3f_asPOD(vec3f_t * self,float * out);
double * vec3d_asPOD(vec3d_t * self,double * out);
char * vec3c_asPOD(vec3char_t * self,char * out);



//addition
void vec3i8_add(vec3int8_t * out, vec3int8_t * other);
void vec3i8_addS(vec3int8_t * out , int8_t scalar);
vec3int8_t * vec3i8_add_r(vec3int8_t * out,vec3int8_t * other);
vec3int8_t * vec3i8_addS_r(vec3int8_t * out,int8_t scalar);

void vec3u8_add(vec3uint8_t * out, vec3uint8_t * other);
void vec3u8_addS(vec3int8_t * out , uint8_t scalar);
vec3uint8_t * vec3u8_add_r(vec3uint8_t * out,vec3uint8_t * other);
vec3uint8_t * vec3u8_addS_r(vec3uint8_t * out,uint8_t scalar);

void vec3i16_add(vec3int16_t * out, vec3int16_t * other);
void vec3i16_addS(vec3int16_t * out , int16_t scalar);
vec3int16_t * vec3i16_add_r(vec3int16_t * out,vec3int16_t * other);
vec3int16_t * vec3i16_addS_r(vec3int16_t * out,int16_t scalar);

void vec3u16_add(vec3uint16_t * out, vec3uint16_t * other);
void vec3u16_addS(vec3int16_t * out , uint16_t scalar);
vec3uint16_t * vec3u16_add_r(vec3uint16_t * out,vec3uint16_t * other);
vec3uint16_t * vec3u16_addS_r(vec3uint16_t * out,uint16_t scalar);

void vec3i32_add(vec3int32_t * out, vec3int32_t * other);
void vec3i32_addS(vec3int32_t * out , int32_t scalar);
vec3int32_t * vec3i32_add_r(vec3int32_t * out,vec3int32_t * other);
vec3int32_t * vec3i32_addS_r(vec3int32_t * out,int32_t scalar);

void vec3u32_add(vec3uint32_t * out, vec3uint32_t * other);
void vec3u32_addS(vec3int32_t * out , uint32_t scalar);
vec3uint32_t * vec3u32_add_r(vec3uint32_t * out,vec3uint32_t * other);
vec3uint32_t * vec3u32_addS_r(vec3uint32_t * out,uint32_t scalar);

void vec3i64_add(vec3int64_t * out, vec3int64_t * other);
void vec3i64_addS(vec3int64_t * out , int64_t scalar);
vec3int64_t * vec3i64_add_r(vec3int64_t * out,vec3int64_t * other);
vec3int64_t * vec3i64_addS_r(vec3int64_t * out,int64_t scalar);

void vec3u64_add(vec3uint64_t * out, vec3uint64_t * other);
void vec3u64_addS(vec3int64_t * out , uint64_t scalar);
vec3uint64_t * vec3u64_add_r(vec3uint64_t * out,vec3uint64_t * other);
vec3uint64_t * vec3u64_addS_r(vec3uint64_t * out,uint64_t scalar);

void vec3f_add(vec3f_t * out, vec3f_t * other);
void vec3f_addS(vec3f_t * out , float scalar);
vec3f_t * vec3f_add_r(vec3f_t * out,vec3f_t * other);
vec3f_t * vec3f_addS_r(vec3f_t * out, float scalar);

void vec3d_add(vec3d_t * out, vec3d_t * other);
void vec3d_addS(vec3d_t * out , double scalar);
vec3d_t * vec3d_add_r(vec3d_t * out,vec3d_t * other);
vec3d_t * vec3d_addS_r(vec3d_t * out,double scalar);

//subtraction
void vec3i8_sub(vec3int8_t * out, vec3int8_t * other);
void vec3i8_subS(vec3int8_t * out , int8_t scalar);
vec3int8_t * vec3i8_sub_r(vec3int8_t * out,vec3int8_t * other);
vec3int8_t * vec3i8_subS_r(vec3int8_t * out,int8_t scalar);

void vec3u8_sub(vec3uint8_t * out, vec3uint8_t * other);
void vec3u8_subS(vec3int8_t * out , uint8_t scalar);
vec3uint8_t * vec3u8_sub_r(vec3uint8_t * out,vec3uint8_t * other);
vec3uint8_t * vec3u8_subS_r(vec3uint8_t * out,uint8_t scalar);

void vec3i16_sub(vec3int16_t * out, vec3int16_t * other);
void vec3i16_subS(vec3int16_t * out , int16_t scalar);
vec3int16_t * vec3i16_sub_r(vec3int16_t * out,vec3int16_t * other);
vec3int16_t * vec3i16_subS_r(vec3int16_t * out,int16_t scalar);

void vec3u16_sub(vec3uint16_t * out, vec3uint16_t * other);
void vec3u16_subS(vec3int16_t * out , uint16_t scalar);
vec3uint16_t * vec3u16_sub_r(vec3uint16_t * out,vec3uint16_t * other);
vec3uint16_t * vec3u16_subS_r(vec3uint16_t * out,uint16_t scalar);

void vec3i32_sub(vec3int32_t * out, vec3int32_t * other);
void vec3i32_subS(vec3int32_t * out , int32_t scalar);
vec3int32_t * vec3i32_sub_r(vec3int32_t * out,vec3int32_t * other);
vec3int32_t * vec3i32_subS_r(vec3int32_t * out,int32_t scalar);

void vec3u32_sub(vec3uint32_t * out, vec3uint32_t * other);
void vec3u32_subS(vec3int32_t * out , uint32_t scalar);
vec3uint32_t * vec3u32_sub_r(vec3uint32_t * out,vec3uint32_t * other);
vec3uint32_t * vec3u32_subS_r(vec3uint32_t * out,uint32_t scalar);

void vec3i64_sub(vec3int64_t * out, vec3int64_t * other);
void vec3i64_subS(vec3int64_t * out , int64_t scalar);
vec3int64_t * vec3i64_sub_r(vec3int64_t * out,vec3int64_t * other);
vec3int64_t * vec3i64_subS_r(vec3int64_t * out,int64_t scalar);

void vec3u64_sub(vec3uint64_t * out, vec3uint64_t * other);
void vec3u64_subS(vec3int64_t * out , uint64_t scalar);
vec3uint64_t * vec3u64_sub_r(vec3uint64_t * out,vec3uint64_t * other);
vec3uint64_t * vec3u64_subS_r(vec3uint64_t * out,uint64_t scalar);

void vec3f_sub(vec3f_t * out, vec3f_t * other);
void vec3f_subS(vec3f_t * out , float scalar);
vec3f_t * vec3f_sub_r(vec3f_t * out,vec3f_t * other);
vec3f_t * vec3f_subS_r(vec3f_t * out, float scalar);

void vec3d_sub(vec3d_t * out, vec3d_t * other);
void vec3d_subS(vec3d_t * out , double scalar);
vec3d_t * vec3d_sub_r(vec3d_t * out,vec3d_t * other);
vec3d_t * vec3d_subS_r(vec3d_t * out,double scalar);


//Multiplication (only doing 16-bits+)
void vec3i16_mult(vec3int16_t * out, vec3int16_t * other);
void vec3i16_multS(vec3int16_t * out , int16_t scalar);
vec3int16_t * vec3i16_mult_r(vec3int16_t * out,vec3int16_t * other);
vec3int16_t * vec3i16_multS_r(vec3int16_t * out,int16_t scalar);

void vec3u16_mult(vec3uint16_t * out, vec3uint16_t * other);
void vec3u16_multS(vec3int16_t * out , uint16_t scalar);
vec3uint16_t * vec3u16_mult_r(vec3uint16_t * out,vec3uint16_t * other);
vec3uint16_t * vec3u16_multS_r(vec3uint16_t * out,uint16_t scalar);

void vec3i32_mult(vec3int32_t * out, vec3int32_t * other);
void vec3i32_multS(vec3int32_t * out , int32_t scalar);
vec3int32_t * vec3i32_mult_r(vec3int32_t * out,vec3int32_t * other);
vec3int32_t * vec3i32_multS_r(vec3int32_t * out,int32_t scalar);

void vec3u32_mult(vec3uint32_t * out, vec3uint32_t * other);
void vec3u32_multS(vec3int32_t * out , uint32_t scalar);
vec3uint32_t * vec3u32_mult_r(vec3uint32_t * out,vec3uint32_t * other);
vec3uint32_t * vec3u32_multS_r(vec3uint32_t * out,uint32_t scalar);

void vec3i64_mult(vec3int64_t * out, vec3int64_t * other);
void vec3i64_multS(vec3int64_t * out , int64_t scalar);
vec3int64_t * vec3i64_mult_r(vec3int64_t * out,vec3int64_t * other);
vec3int64_t * vec3i64_multS_r(vec3int64_t * out,int64_t scalar);

void vec3u64_mult(vec3uint64_t * out, vec3uint64_t * other);
void vec3u64_multS(vec3int64_t * out , uint64_t scalar);
vec3uint64_t * vec3u64_mult_r(vec3uint64_t * out,vec3uint64_t * other);
vec3uint64_t * vec3u64_multS_r(vec3uint64_t * out,uint64_t scalar);

void vec3f_mult(vec3f_t * out, vec3f_t * other);
void vec3f_multS(vec3f_t * out , float scalar);
vec3f_t * vec3f_mult_r(vec3f_t * out,vec3f_t * other);
vec3f_t * vec3f_multS_r(vec3f_t * out, float scalar);

void vec3d_mult(vec3d_t * out, vec3d_t * other);
void vec3d_multS(vec3d_t * out , double scalar);
vec3d_t * vec3d_mult_r(vec3d_t * out,vec3d_t * other);
vec3d_t * vec3d_multS_r(vec3d_t * out,double scalar);

//Divison (TO BE IMPLEMENTED)



//length
float vec3i8_length(vec3int8_t * self);
float vec3u8_length(vec3uint8_t * self);
float vec3i16_length(vec3int16_t * self);
float vec3u16_length(vec3uint16_t * self);
float vec3i32_length(vec3int32_t * self);
float vec3u32_length(vec3uint32_t * self);
float vec3i64_length(vec3int64_t * self);
float vec3u64_length(vec3uint64_t * self);
float vec3c_length(vec3char_t * self);
float vec3f_length(vec3f_t * self);
float vec3d_length(vec3d_t * self);

//dot
float vec3i8_dot(vec3int8_t * left,vec3int8_t * right);
float vec3u8_dot(vec3uint8_t * left,vec3uint8_t * right);
float vec3i16_dot(vec3int16_t * left,vec3int16_t * right);
float vec3u16_dot(vec3uint16_t * left,vec3uint16_t * right);
float vec3i32_dot(vec3int32_t * left,vec3int32_t * right);
float vec3u32_dot(vec3uint32_t * left,vec3uint32_t * right);
float vec3i64_dot(vec3int64_t * left,vec3int64_t * right);
float vec3u64_dot(vec3uint64_t * left,vec3uint64_t * right);
float vec3c_dot(vec3char_t * left,vec3char_t * right);
float vec3f_dot(vec3f_t * left,vec3f_t * right);
float vec3d_dot(vec3d_t * left,vec3d_t * right);


//cross ( out as parameter)
void vec3i8_cross(vec3int8_t * out, vec3int8_t * left, vec3int8_t * right);
void vec3u8_cross(vec3uint8_t * out, vec3uint8_t * left, vec3uint8_t * right);
void vec3i16_cross(vec3int16_t * out, vec3int16_t * left, vec3int16_t * right);
void vec3u16_cross(vec3uint16_t * out, vec3uint16_t * left, vec3uint16_t * right);
void vec3i32_cross(vec3int32_t * out, vec3int32_t * left, vec3int32_t * right);
void vec3u32_cross(vec3uint32_t * out, vec3uint32_t * left, vec3uint32_t * right);
void vec3i64_cross(vec3int64_t * out, vec3int64_t * left, vec3int64_t * right);
void vec3u64_cross(vec3uint64_t * out, vec3uint64_t * left, vec3uint64_t * right);
void vec3f_cross(vec3f_t * out, vec3f_t * left, vec3f_t * right);
void vec3d_cross(vec3d_t * out, vec3d_t * left, vec3d_t * right);

//cross (out returned)
vec3int8_t * vec3i8_cross_r(vec3int8_t * out, vec3int8_t * left, vec3int8_t * right);
vec3uint8_t * vec3u8_cross_r(vec3uint8_t * out, vec3uint8_t * left, vec3uint8_t * right);
vec3int16_t * vec3i16_cross_r(vec3int16_t * out, vec3int16_t * left, vec3int16_t * right);
vec3uint16_t * vec3u16_cross_r(vec3uint16_t * out, vec3uint16_t * left, vec3uint16_t * right);
vec3int32_t * vec3i32_cross_r(vec3int32_t * out, vec3int32_t * left, vec3int32_t * right);
vec3uint32_t * vec3u32_cross_r(vec3uint32_t * out, vec3uint32_t * left, vec3uint32_t * right);
vec3int64_t * vec3i64_cross_r(vec3int64_t * out, vec3int64_t * left, vec3int64_t * right);
vec3uint64_t * vec3u64_cross_r(vec3uint64_t * out, vec3uint64_t * left, vec3uint64_t * right);
vec3f_t * vec3f_cross_r(vec3f_t * out, vec3f_t * left, vec3f_t * right);
vec3d_t * vec3d_cross_r(vec3d_t * out, vec3d_t * left, vec3d_t * right);


//Misc Functions
void vec3f_normalize(vec3f_t * out, vec3f_t * self);
void vec3f_lerp(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage);
void vec3f_slerp(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage);
void vec3f_nlerp(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage);

void vec3d_normalize(vec3d_t * out, vec3d_t * self);
void vec3d_lerp(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage);
void vec3d_slerp(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage);
void vec3d_nlerp(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage);

//Returned Misc Functions
vec3f_t * vec3f_normalize_r(vec3f_t * out, vec3f_t * self);
vec3f_t * vec3f_lerp_r(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage);
vec3f_t * vec3f_slerp_r(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage);
vec3f_t * vec3f_nlerp_r(vec3f_t * out, vec3f_t * start , vec3f_t * end, float percentage);

vec3d_t * vec3d_normalize_r(vec3d_t * out, vec3d_t * self);
vec3d_t * vec3d_lerp_r(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage);
vec3d_t * vec3d_slerp_r(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage);
vec3d_t * vec3d_nlerp_r(vec3d_t * out, vec3d_t * start , vec3d_t * end, float percentage);

//getSize because trying to get the size via sizeof() wont work .
size_t vec3i8_getSize();
size_t vec3u8_getSize();
size_t vec3i16_getSize();
size_t vec3u16_getSize();
size_t vec3i32_getSize();
size_t vec3u32_getSize();
size_t vec3i64_getSize();
size_t vec3u64_getSize();
size_t vec3c_getSize();
size_t vec3f_getSize();
size_t vec3d_getSize();

//toString (will need to be freed)
char * vec3i8_toString(vec3int8_t * self);
char * vec3u8_toString(vec3uint8_t * self);
char * vec3i16_toString(vec3int16_t * self);
char * vec3u16_toString(vec3uint16_t * self);
char * vec3i32_toString(vec3int32_t * self);
char * vec3u32_toString(vec3uint32_t * self);
char * vec3i64_toString(vec3int64_t * self);
char * vec3u64_toString(vec3uint64_t * self);
char * vec3c_toString(vec3char_t * self);
char * vec3f_toString(vec3f_t * self);
char * vec3d_toString(vec3d_t * self);



//printing
void printvec3i8(vec3int8_t * vec);
void printvec3u8(vec3uint8_t * vec);
void printvec3i16(vec3int16_t * vec);
void printvec3u16(vec3uint16_t * vec);
void printvec3i32(vec3int32_t * vec);
void printvec3u32(vec3uint32_t * vec);
void printvec3i64(vec3int64_t * vec);
void printvec3u64(vec3uint64_t * vec);
void printvec3c(vec3char_t * vec);
void printvec3f(vec3f_t * vec);
void printvec3d(vec3d_t * vec);


#endif
