#ifndef FOUNDATIONS_MATH_VEC4_H
#define FOUNDATIONS_MATH_VEC4_H


#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
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

#ifndef VEC4_DEFINED

  #ifndef VEC4I8_DEFINED
  typedef struct vector4int8 vec4int8_t;
  #define VEC4I8_DEFINED 1
  #endif

  #ifndef VEC4U8_DEFINED
  typedef struct vector4uint8 vec4uint8_t;
  #define VEC4U8_DEFINED 1
  #endif

  #ifndef VEC4I16_DEFINED
  typedef struct vector4int16 vec4int16_t;
  #define VEC4I16_DEFINED 1
  #endif

  #ifndef VEC4U16_DEFINED
  typedef struct vector4uint16 vec4uint16_t;
  #define VEC4U16_DEFINED 1
  #endif

  #ifndef VEC4I32_DEFINED
  typedef struct vector4int32 vec4int32_t;
  #define VEC4I32_DEFINED 1
  #endif

  #ifndef VEC4U32_DEFINED
  typedef struct vector4uint32 vec4uint32_t;
  #define VEC4U32_DEFINED 1
  #endif

  #ifndef VEC4I64_DEFINED
  typedef struct vector4int64 vec4int64_t;
  #define VEC4I64_DEFINED 1
  #endif

  #ifndef VEC4U64_DEFINED
  typedef struct vector4uint64 vec4uint64_t;
  #define VEC4U64_DEFINED 1
  #endif

  #ifndef VEC4C_DEFINED
  typedef struct vector4char vec4char_t;
  #define VEC4C_DEFINED 1
  #endif

  #ifndef VEC4F_DEFINED
  typedef struct vector4float vec4f_t;
  #define VEC4F_DEFINED 1
  #endif

  #ifndef VEC4D_DEFINED
  typedef struct vector4double vec4d_t;
  #define VEC4D_DEFINED 1
  #endif

#define VEC4_DEFINED 1
#endif




//Initalize an already allocated vector.

void initvec4I8(vec4int8_t * out , int8_t x ,int8_t y, int8_t z, int8_t w);
void initvec4U8(vec4uint8_t * out , uint8_t x ,uint8_t y, uint8_t z, uint8_t w);
void initvec4I16(vec4int16_t * out , int16_t x ,int16_t y, int16_t z, int16_t w);
void initvec4U16(vec4uint16_t * out , uint16_t x ,uint16_t y, uint16_t z, uint16_t w);
void initvec4I32(vec4int32_t * out , int32_t x ,int32_t y, int32_t z, int32_t w);
void initvec4U32(vec4uint32_t * out , uint32_t x ,uint32_t y, uint32_t z, uint32_t w);
void initvec4I64(vec4int64_t * out , int64_t x ,int64_t y, int64_t z, int64_t w);
void initvec4U64(vec4uint64_t * out , uint64_t x ,uint64_t y, uint64_t z, int64_t w);
void initvec4C(vec4char_t * out , char x ,char y, char z, char w);
void initvec4F(vec4f_t * out , float x ,float y, float z,float w);
void initvec4D(vec4d_t * out, double x , double y, double z, double w);

//vec2 represents the x,y variables
void initvec4I8_fromVec2(vec4int8_t * out , vec2int8_t * xy , int8_t z, int8_t w);
void initvec4U8_fromVec2(vec4uint8_t * out , vec2uint8_t * xy ,uint8_t z, uint8_t w);
void initvec4I16_fromVec2(vec4int16_t * out , vec2int16_t * xy , int16_t z, int16_t w);
void initvec4U16_fromVec2(vec4uint16_t * out , vec2uint16_t * xy , uint16_t z, uint16_t w);
void initvec4I32_fromVec2(vec4int32_t * out , vec2int32_t * xy , int32_t z, int32_t w);
void initvec4U32_fromVec2(vec4uint32_t * out , vec2uint32_t * xy , uint32_t z, uint32_t w);
void initvec4I64_fromVec2(vec4int64_t * out , vec2int64_t * xy , int64_t z, int64_t w);
void initvec4U64_fromVec2(vec4uint64_t * out , vec2uint64_t * xy ,uint64_t z, uint64_t w);
void initvec4C_fromVec2(vec4char_t * out , vec2char_t * xy ,char z,char w);
void initvec4F_fromVec2(vec4f_t * out , vec2f_t * xy , float z,float w);
void initvec4D_fromVec2(vec4d_t * out, vec2d_t * xy , double z,double w);

//first vec2 represents the x,y variables, the second represents the zw
void initvec4I8_from2Vec2(vec4int8_t * out , vec2int8_t * xy, vec2int8_t *  zw);
void initvec4U8_from2Vec2(vec4uint8_t * out , vec2uint8_t * xy , vec2uint8_t  * zw);
void initvec4I16_from2Vec2(vec4int16_t * out , vec2int16_t * xy , vec2int16_t *  zw);
void initvec4U16_from2Vec2(vec4uint16_t * out , vec2uint16_t * xy , vec2uint16_t  * zw);
void initvec4I32_from2Vec2(vec4int32_t * out , vec2int32_t * xy , vec2int32_t *  zw);
void initvec4U32_from2Vec2(vec4uint32_t * out , vec2uint32_t * xy , vec2uint32_t  * zw);
void initvec4I64_from2Vec2(vec4int64_t * out , vec2int64_t * xy , vec2int64_t  * zw);
void initvec4U64_from2Vec2(vec4uint64_t * out , vec2uint64_t * xy ,vec2uint64_t  * zw);
void initvec4C_from2Vec2(vec4char_t * out , vec2char_t * xy ,vec2char_t  * zw);
void initvec4F_from2Vec2(vec4f_t * out , vec2f_t * xy , vec2f_t *  zw);
void initvec4D_from2Vec2(vec4d_t * out, vec2d_t * xy , vec2d_t * zw);

//vec3 represents the x,y, z variables
void initvec4I8_fromVec3(vec4int8_t * out , vec3int8_t * xyz, int8_t w);
void initvec4U8_fromVec3(vec4uint8_t * out , vec3uint8_t * xyz, uint8_t w);
void initvec4I16_fromVec3(vec4int16_t * out , vec3int16_t * xyz, int16_t w);
void initvec4U16_fromVec3(vec4uint16_t * out , vec3uint16_t * xyz, uint16_t w);
void initvec4I32_fromVec3(vec4int32_t * out , vec3int32_t * xyz, int32_t w);
void initvec4U32_fromVec3(vec4uint32_t * out , vec3uint32_t * xyz, uint32_t w);
void initvec4I64_fromVec3(vec4int64_t * out , vec3int64_t * xyz, int64_t w);
void initvec4U64_fromVec3(vec4uint64_t * out , vec3uint64_t * xyz, uint64_t w);
void initvec4C_fromVec3(vec4char_t * out , vec3char_t * xyz,char w);
void initvec4F_fromVec3(vec4f_t * out , vec3f_t * xyz,float w);
void initvec4D_fromVec3(vec4d_t * out, vec3d_t * xyz,double w);


//Allocate and initialize Vector
vec4int8_t * allocvec4I8(int8_t x, int8_t y, int8_t z, int8_t w);
vec4uint8_t * allocvec4U8(uint8_t x, uint8_t y, uint8_t z, uint8_t w);
vec4int16_t * allocvec4I16(int16_t x, int16_t y, int16_t z, int16_t w);
vec4uint16_t * allocvec4U16(uint16_t x, uint16_t y, uint16_t z, uint16_t w);
vec4int32_t * allocvec4I32(int32_t x, int32_t y, int32_t z, int32_t w);
vec4uint32_t * allocvec4U32(uint32_t x, uint32_t y, uint32_t z, uint32_t w);
vec4int64_t * allocvec4I64(int64_t x, int64_t y, int64_t z, int64_t w);
vec4uint64_t * allocvec4U64(uint64_t x, uint64_t y, uint64_t z, uint64_t w);
vec4char_t * allocvec4C(char x, char y, char z,char w);
vec4f_t * allocvec4F(float x, float y, float z,float w);
vec4d_t * allocvec4D(double x, double y, double z,double w);

//Allocate and initialize Vector from vec2
vec4int8_t * allocvec4I8_fromVec2(vec2int8_t * xy, int8_t z, int8_t w);
vec4uint8_t * allocvec4U8_fromVec2(vec2uint8_t * xy, uint8_t z, uint8_t w);
vec4int16_t * allocvec4I16_fromVec2(vec2int16_t * xy, int16_t z, int16_t w);
vec4uint16_t * allocvec4U16_fromVec2(vec2uint16_t * xy, uint16_t z, uint16_t w);
vec4int32_t * allocvec4I32_fromVec2(vec2int32_t * xy, int32_t z, int32_t w);
vec4uint32_t * allocvec4U32_fromVec2(vec2uint32_t * xy, uint32_t z, uint32_t w);
vec4int64_t * allocvec4I64_fromVec2(vec2int64_t * xy, int64_t z, int64_t w);
vec4uint64_t * allocvec4U64_fromVec2(vec2uint64_t * xy, uint64_t z, uint64_t w);
vec4char_t * allocvec4C_fromVec2(vec2char_t * xy, char z,char w);
vec4f_t * allocvec4F_fromVec2(vec2f_t * xy, float z,float w);
vec4d_t * allocvec4D_fromVec2(vec2d_t * xy, double z,double w);

//Allocate and initialize Vector from 2 vec2s
vec4int8_t * allocvec4I8_from2Vec2(vec2int8_t * xy, vec2int8_t * zw);
vec4uint8_t * allocvec4U8_from2Vec2(vec2uint8_t * xy, vec2uint8_t *  zw);
vec4int16_t * allocvec4I16_from2Vec2(vec2int16_t * xy, vec2int16_t *  zw);
vec4uint16_t * allocvec4U16_from2Vec2(vec2uint16_t * xy, vec2uint16_t  * zw);
vec4int32_t * allocvec4I32_from2Vec2(vec2int32_t * xy, vec2int32_t *  zw);
vec4uint32_t * allocvec4U32_from2Vec2(vec2uint32_t * xy, vec2uint32_t  * zw);
vec4int64_t * allocvec4I64_from2Vec2(vec2int64_t * xy, vec2int64_t  * zw);
vec4uint64_t * allocvec4U64_from2Vec2(vec2uint64_t * xy, vec2uint64_t *  zw);
vec4char_t * allocvec4C_from2Vec2(vec2char_t * xy, vec2char_t  * zw);
vec4f_t * allocvec4F_from2Vec2(vec2f_t * xy, vec2f_t  * zw);
vec4d_t * allocvec4D_from2Vec2(vec2d_t * xy, vec2d_t *  zw);

//Allocate and initialize Vector from vec3
vec4int8_t * allocvec4I8_fromVec3(vec3int8_t * xyz, int8_t w);
vec4uint8_t * allocvec4U8_fromVec3(vec3uint8_t * xyz, uint8_t w);
vec4int16_t * allocvec4I16_fromVec3(vec3int16_t * xyz, int16_t w);
vec4uint16_t * allocvec4U16_fromVec3(vec3uint16_t * xyz, uint16_t w);
vec4int32_t * allocvec4I32_fromVec3(vec3int32_t * xyz, int32_t w);
vec4uint32_t * allocvec4U32_fromVec3(vec3uint32_t * xyz, uint32_t w);
vec4int64_t * allocvec4I64_fromVec3(vec3int64_t * xyz, int64_t w);
vec4uint64_t * allocvec4U64_fromVec3(vec3uint64_t * xyz, uint64_t w);
vec4char_t * allocvec4C_fromVec3(vec3char_t * xyz,char w);
vec4f_t * allocvec4F_fromVec3(vec3f_t * xyz,float w);
vec4d_t * allocvec4D_fromVec3(vec3d_t * xyz,double w);


//Allocate and initialize Vector from string
vec4int8_t * allocvec4I8_fromString(const char * str);
vec4uint8_t * allocvec4U8_fromString(const char * str);
vec4int16_t * allocvec4I16_fromString(const char * str);
vec4uint16_t * allocvec4U16_fromString(const char * str);
vec4int32_t * allocvec4I32_fromString(const char * str);
vec4uint32_t * allocvec4U32_fromString(const char * str);
vec4int64_t * allocvec4I64_fromString(const char * str);
vec4uint64_t * allocvec4U64_fromString(const char * str);
vec4char_t * allocvec4C_fromString(const char * str);
vec4f_t * allocvec4F_fromString(const char * str);
vec4d_t * allocvec4D_fromString(const char * str);


//getters and setters
void vec4i8_setX(vec4int8_t * out, int8_t x);
void vec4i8_setY(vec4int8_t * out, int8_t y);
void vec4i8_setZ(vec4int8_t * out, int8_t z);
void vec4i8_setW(vec4int8_t * out, int8_t w);

int8_t vec4i8_X(vec4int8_t * out);
int8_t vec4i8_Y(vec4int8_t * out);
int8_t vec4i8_Z(vec4int8_t * out);
int8_t vec4i8_W(vec4int8_t * out);


void vec4u8_setX(vec4uint8_t * out, uint8_t x);
void vec4u8_setY(vec4uint8_t * out, uint8_t y);
void vec4u8_setZ(vec4uint8_t * out, uint8_t z);
void vec4u8_setW(vec4int8_t * out, uint8_t w);

uint8_t vec4u8_X(vec4uint8_t * out);
uint8_t vec4u8_Y(vec4uint8_t * out);
uint8_t vec4u8_Z(vec4uint8_t * out);
uint8_t vec4u8_W(vec4uint8_t * out);


void vec4i16_setX(vec4int16_t * out, int16_t x);
void vec4i16_setY(vec4int16_t * out, int16_t y);
void vec4i16_setZ(vec4int16_t * out, int16_t z);
void vec4i16_setW(vec4int16_t * out, int16_t w);

int16_t vec4i16_X(vec4int16_t * out);
int16_t vec4i16_Y(vec4int16_t * out);
int16_t vec4i16_Z(vec4int16_t * out);
int16_t vec4i16_W(vec4int16_t * out);

void vec4u16_setX(vec4uint16_t * out, uint16_t x);
void vec4u16_setY(vec4uint16_t * out, uint16_t y);
void vec4u16_setZ(vec4uint16_t * out, uint16_t z);
void vec4u16_setW(vec4uint16_t * out, uint16_t w);

uint16_t vec4u16_X(vec4uint16_t * out);
uint16_t vec4u16_Y(vec4uint16_t * out);
uint16_t vec4u16_Z(vec4uint16_t * out);
uint16_t vec4u16_W(vec4uint16_t * out);

void vec4i32_setX(vec4int32_t * out, int32_t x);
void vec4i32_setY(vec4int32_t * out, int32_t y);
void vec4i32_setZ(vec4int32_t * out, int32_t z);
void vec4i32_setW(vec4int32_t * out, int32_t w);

int32_t vec4i32_X(vec4int32_t * out);
int32_t vec4i32_Y(vec4int32_t * out);
int32_t vec4i32_Z(vec4int32_t * out);
int32_t vec4i32_W(vec4int32_t * out);

void vec4u32_setX(vec4uint32_t * out, uint32_t x);
void vec4u32_setY(vec4uint32_t * out, uint32_t y);
void vec4u32_setZ(vec4uint32_t * out, uint32_t z);
void vec4u32_setW(vec4uint32_t * out, uint32_t w);

uint32_t vec4u32_X(vec4uint32_t * out);
uint32_t vec4u32_Y(vec4uint32_t * out);
uint32_t vec4u32_Z(vec4uint32_t * out);
uint32_t vec4u32_W(vec4uint32_t * out);

void vec4i64_setX(vec4int64_t * out, int64_t x);
void vec4i64_setY(vec4int64_t * out, int64_t y);
void vec4i64_setZ(vec4int64_t * out, int64_t z);
void vec4i64_setW(vec4int64_t * out, int64_t w);

int64_t vec4i64_X(vec4int64_t * out);
int64_t vec4i64_Y(vec4int64_t * out);
int64_t vec4i64_Z(vec4int64_t * out);
int64_t vec4i64_W(vec4int64_t * out);


void vec4u64_setX(vec4uint64_t * out, uint64_t x);
void vec4u64_setY(vec4uint64_t * out, uint64_t y);
void vec4u64_setZ(vec4uint64_t * out, uint64_t z);
void vec4u64_setW(vec4uint64_t * out, uint64_t w);


uint64_t vec4u64_X(vec4uint64_t * out);
uint64_t vec4u64_Y(vec4uint64_t * out);
uint64_t vec4u64_Z(vec4uint64_t * out);
uint64_t vec4u64_W(vec4uint64_t * out);

void vec4char_setX(vec4char_t * out, char x);
void vec4char_setY(vec4char_t * out, char y);
void vec4char_setZ(vec4char_t * out, char z);
void vec4char_setW(vec4char_t * out, char w);


char vec4char_X(vec4char_t * out);
char vec4char_Y(vec4char_t * out);
char vec4char_Z(vec4char_t * out);
char vec4char_W(vec4char_t * out);


void vec4f_setX(vec4f_t * out, float x);
void vec4f_setY(vec4f_t * out, float y);
void vec4f_setZ(vec4f_t * out, float z);
void vec4f_setW(vec4f_t * out, float w);


float vec4f_X(vec4f_t * out);
float vec4f_Y(vec4f_t * out);
float vec4f_Z(vec4f_t * out);
float vec4f_W(vec4f_t * out);

void vec4d_setX(vec4d_t * out, double x);
void vec4d_setY(vec4d_t * out, double y);
void vec4d_setZ(vec4d_t * out, double z);
void vec4d_setW(vec4d_t * out, double w);

double vec4d_X(vec4d_t * out);
double vec4d_Y(vec4d_t * out);
double vec4d_Z(vec4d_t * out);
double vec4d_W(vec4d_t * out);

//asPOD. Gives data as a plain-old-data type
//note: in order for this to be threadsafe, i need to setup
//user-provided storage.

int8_t * vec4i8_asPOD(vec4int8_t * self,int8_t * out);
uint8_t * vec4u8_asPOD(vec4uint8_t * self,uint8_t * out);
int16_t * vec4i16_asPOD(vec4int16_t * self,int16_t * out);
uint16_t * vec4u16_asPOD(vec4uint16_t * self,uint16_t * out);
int32_t * vec4i32_asPOD(vec4int32_t * self,int32_t * out);
uint32_t * vec4u32_asPOD(vec4uint32_t * self,uint32_t * out);
int64_t * vec4i64_asPOD(vec4int64_t * self,int64_t * out);
uint64_t * vec4u64_asPOD(vec4uint64_t * self,uint64_t * out);
float * vec4f_asPOD(vec4f_t * self,float * out);
double * vec4d_asPOD(vec4d_t * self,double * out);
char * vec4c_asPOD(vec4char_t * self,char * out);




//addition
void vec4i8_add(vec4int8_t * out, vec4int8_t * other);
void vec4i8_addS(vec4int8_t * out , int8_t scalar);
vec4int8_t * vec4i8_add_r(vec4int8_t * out,vec4int8_t * other);
vec4int8_t * vec4i8_addS_r(vec4int8_t * out,int8_t scalar);

void vec4u8_add(vec4uint8_t * out, vec4uint8_t * other);
void vec4u8_addS(vec4int8_t * out , uint8_t scalar);
vec4uint8_t * vec4u8_add_r(vec4uint8_t * out,vec4uint8_t * other);
vec4uint8_t * vec4u8_addS_r(vec4uint8_t * out,uint8_t scalar);

void vec4i16_add(vec4int16_t * out, vec4int16_t * other);
void vec4i16_addS(vec4int16_t * out , int16_t scalar);
vec4int16_t * vec4i16_add_r(vec4int16_t * out,vec4int16_t * other);
vec4int16_t * vec4i16_addS_r(vec4int16_t * out,int16_t scalar);

void vec4u16_add(vec4uint16_t * out, vec4uint16_t * other);
void vec4u16_addS(vec4int16_t * out , uint16_t scalar);
vec4uint16_t * vec4u16_add_r(vec4uint16_t * out,vec4uint16_t * other);
vec4uint16_t * vec4u16_addS_r(vec4uint16_t * out,uint16_t scalar);

void vec4i32_add(vec4int32_t * out, vec4int32_t * other);
void vec4i32_addS(vec4int32_t * out , int32_t scalar);
vec4int32_t * vec4i32_add_r(vec4int32_t * out,vec4int32_t * other);
vec4int32_t * vec4i32_addS_r(vec4int32_t * out,int32_t scalar);

void vec4u32_add(vec4uint32_t * out, vec4uint32_t * other);
void vec4u32_addS(vec4int32_t * out , uint32_t scalar);
vec4uint32_t * vec4u32_add_r(vec4uint32_t * out,vec4uint32_t * other);
vec4uint32_t * vec4u32_addS_r(vec4uint32_t * out,uint32_t scalar);

void vec4i64_add(vec4int64_t * out, vec4int64_t * other);
void vec4i64_addS(vec4int64_t * out , int64_t scalar);
vec4int64_t * vec4i64_add_r(vec4int64_t * out,vec4int64_t * other);
vec4int64_t * vec4i64_addS_r(vec4int64_t * out,int64_t scalar);

void vec4u64_add(vec4uint64_t * out, vec4uint64_t * other);
void vec4u64_addS(vec4int64_t * out , uint64_t scalar);
vec4uint64_t * vec4u64_add_r(vec4uint64_t * out,vec4uint64_t * other);
vec4uint64_t * vec4u64_addS_r(vec4uint64_t * out,uint64_t scalar);

void vec4f_add(vec4f_t * out, vec4f_t * other);
void vec4f_addS(vec4f_t * out , float scalar);
vec4f_t * vec4f_add_r(vec4f_t * out,vec4f_t * other);
vec4f_t * vec4f_addS_r(vec4f_t * out, float scalar);

void vec4d_add(vec4d_t * out, vec4d_t * other);
void vec4d_addS(vec4d_t * out , double scalar);
vec4d_t * vec4d_add_r(vec4d_t * out,vec4d_t * other);
vec4d_t * vec4d_addS_r(vec4d_t * out,double scalar);

//subtraction
void vec4i8_sub(vec4int8_t * out, vec4int8_t * other);
void vec4i8_subS(vec4int8_t * out , int8_t scalar);
vec4int8_t * vec4i8_sub_r(vec4int8_t * out,vec4int8_t * other);
vec4int8_t * vec4i8_subS_r(vec4int8_t * out,int8_t scalar);

void vec4u8_sub(vec4uint8_t * out, vec4uint8_t * other);
void vec4u8_subS(vec4int8_t * out , uint8_t scalar);
vec4uint8_t * vec4u8_sub_r(vec4uint8_t * out,vec4uint8_t * other);
vec4uint8_t * vec4u8_subS_r(vec4uint8_t * out,uint8_t scalar);

void vec4i16_sub(vec4int16_t * out, vec4int16_t * other);
void vec4i16_subS(vec4int16_t * out , int16_t scalar);
vec4int16_t * vec4i16_sub_r(vec4int16_t * out,vec4int16_t * other);
vec4int16_t * vec4i16_subS_r(vec4int16_t * out,int16_t scalar);

void vec4u16_sub(vec4uint16_t * out, vec4uint16_t * other);
void vec4u16_subS(vec4int16_t * out , uint16_t scalar);
vec4uint16_t * vec4u16_sub_r(vec4uint16_t * out,vec4uint16_t * other);
vec4uint16_t * vec4u16_subS_r(vec4uint16_t * out,uint16_t scalar);

void vec4i32_sub(vec4int32_t * out, vec4int32_t * other);
void vec4i32_subS(vec4int32_t * out , int32_t scalar);
vec4int32_t * vec4i32_sub_r(vec4int32_t * out,vec4int32_t * other);
vec4int32_t * vec4i32_subS_r(vec4int32_t * out,int32_t scalar);

void vec4u32_sub(vec4uint32_t * out, vec4uint32_t * other);
void vec4u32_subS(vec4int32_t * out , uint32_t scalar);
vec4uint32_t * vec4u32_sub_r(vec4uint32_t * out,vec4uint32_t * other);
vec4uint32_t * vec4u32_subS_r(vec4uint32_t * out,uint32_t scalar);

void vec4i64_sub(vec4int64_t * out, vec4int64_t * other);
void vec4i64_subS(vec4int64_t * out , int64_t scalar);
vec4int64_t * vec4i64_sub_r(vec4int64_t * out,vec4int64_t * other);
vec4int64_t * vec4i64_subS_r(vec4int64_t * out,int64_t scalar);

void vec4u64_sub(vec4uint64_t * out, vec4uint64_t * other);
void vec4u64_subS(vec4int64_t * out , uint64_t scalar);
vec4uint64_t * vec4u64_sub_r(vec4uint64_t * out,vec4uint64_t * other);
vec4uint64_t * vec4u64_subS_r(vec4uint64_t * out,uint64_t scalar);

void vec4f_sub(vec4f_t * out, vec4f_t * other);
void vec4f_subS(vec4f_t * out , float scalar);
vec4f_t * vec4f_sub_r(vec4f_t * out,vec4f_t * other);
vec4f_t * vec4f_subS_r(vec4f_t * out, float scalar);

void vec4d_sub(vec4d_t * out, vec4d_t * other);
void vec4d_subS(vec4d_t * out , double scalar);
vec4d_t * vec4d_sub_r(vec4d_t * out,vec4d_t * other);
vec4d_t * vec4d_subS_r(vec4d_t * out,double scalar);


//Multiplication (only doing 16-bits+)
void vec4i16_mult(vec4int16_t * out, vec4int16_t * other);
void vec4i16_multS(vec4int16_t * out , int16_t scalar);
vec4int16_t * vec4i16_mult_r(vec4int16_t * out,vec4int16_t * other);
vec4int16_t * vec4i16_multS_r(vec4int16_t * out,int16_t scalar);

void vec4u16_mult(vec4uint16_t * out, vec4uint16_t * other);
void vec4u16_multS(vec4int16_t * out , uint16_t scalar);
vec4uint16_t * vec4u16_mult_r(vec4uint16_t * out,vec4uint16_t * other);
vec4uint16_t * vec4u16_multS_r(vec4uint16_t * out,uint16_t scalar);

void vec4i32_mult(vec4int32_t * out, vec4int32_t * other);
void vec4i32_multS(vec4int32_t * out , int32_t scalar);
vec4int32_t * vec4i32_mult_r(vec4int32_t * out,vec4int32_t * other);
vec4int32_t * vec4i32_multS_r(vec4int32_t * out,int32_t scalar);

void vec4u32_mult(vec4uint32_t * out, vec4uint32_t * other);
void vec4u32_multS(vec4int32_t * out , uint32_t scalar);
vec4uint32_t * vec4u32_mult_r(vec4uint32_t * out,vec4uint32_t * other);
vec4uint32_t * vec4u32_multS_r(vec4uint32_t * out,uint32_t scalar);

void vec4i64_mult(vec4int64_t * out, vec4int64_t * other);
void vec4i64_multS(vec4int64_t * out , int64_t scalar);
vec4int64_t * vec4i64_mult_r(vec4int64_t * out,vec4int64_t * other);
vec4int64_t * vec4i64_multS_r(vec4int64_t * out,int64_t scalar);

void vec4u64_mult(vec4uint64_t * out, vec4uint64_t * other);
void vec4u64_multS(vec4int64_t * out , uint64_t scalar);
vec4uint64_t * vec4u64_mult_r(vec4uint64_t * out,vec4uint64_t * other);
vec4uint64_t * vec4u64_multS_r(vec4uint64_t * out,uint64_t scalar);

void vec4f_mult(vec4f_t * out, vec4f_t * other);
void vec4f_multS(vec4f_t * out , float scalar);
vec4f_t * vec4f_mult_r(vec4f_t * out,vec4f_t * other);
vec4f_t * vec4f_multS_r(vec4f_t * out, float scalar);

void vec4d_mult(vec4d_t * out, vec4d_t * other);
void vec4d_multS(vec4d_t * out , double scalar);
vec4d_t * vec4d_mult_r(vec4d_t * out,vec4d_t * other);
vec4d_t * vec4d_multS_r(vec4d_t * out,double scalar);


//getSize because trying to get the size via sizeof() wont work .
size_t vec4i8_getSize();
size_t vec4u8_getSize();
size_t vec4i16_getSize();
size_t vec4u16_getSize();
size_t vec4i32_getSize();
size_t vec4u32_getSize();
size_t vec4i64_getSize();
size_t vec4u64_getSize();
size_t vec4c_getSize();
size_t vec4f_getSize();
size_t vec4d_getSize();


//toString (will need to be freed)
char * vec4i8_toString(vec4int8_t * self);
char * vec4u8_toString(vec4uint8_t * self);
char * vec4i16_toString(vec4int16_t * self);
char * vec4u16_toString(vec4uint16_t * self);
char * vec4i32_toString(vec4int32_t * self);
char * vec4u32_toString(vec4uint32_t * self);
char * vec4i64_toString(vec4int64_t * self);
char * vec4u64_toString(vec4uint64_t * self);
char * vec4c_toString(vec4char_t * self);
char * vec4f_toString(vec4f_t * self);
char * vec4d_toString(vec4d_t * self);




//printing
void printvec4i8(vec4int8_t * vec);
void printvec4u8(vec4uint8_t * vec);
void printvec4i16(vec4int16_t * vec);
void printvec4u16(vec4uint16_t * vec);
void printvec4i32(vec4int32_t * vec);
void printvec4u32(vec4uint32_t * vec);
void printvec4i64(vec4int64_t * vec);
void printvec4u64(vec4uint64_t * vec);
void printvec4c(vec4char_t * vec);
void printvec4f(vec4f_t * vec);
void printvec4d(vec4d_t * vec);




#endif
