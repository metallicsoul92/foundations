#ifndef FOUNDATIONS_MATH_VEC2_H_
#define FOUNDATIONS_MATH_VEC2_H_ 1



#include <stdint.h>

#ifndef VEC2_FOWARDED
//forward
typedef struct vector2int8 vec2int8_t;
typedef struct vector2uint8 vec2uint8_t;
typedef struct vector2int16 vec2int16_t;
typedef struct vector2uint16 vec2uint16_t;
typedef struct vector2int32 vec2int32_t;
typedef struct vector2uint32 vec2uint32_t;
typedef struct vector2int64 vec2int64_t;
typedef struct vector2uint64 vec2uint64_t;
typedef struct vector2char vec2char_t;
typedef struct vector2float vec2f_t;
typedef struct vector2double vec2d_t;
#define VEC2_FOWARDED 1
#endif

/**
Convention Discussion:

void function(type * out, ...etc);
type * function_r(...etc);

**/

//Initalize an already allocated vector.

void initVec2I8(vec2int8_t * out , int8_t x ,int8_t y);
void initVec2U8(vec2uint8_t * out , uint8_t x ,uint8_t y);
void initVec2I16(vec2int16_t * out , int16_t x ,int16_t y);
void initVec2U16(vec2uint16_t * out , uint16_t x ,uint16_t y);
void initVec2I32(vec2int32_t * out , int32_t x ,int32_t y);
void initVec2U32(vec2uint32_t * out , uint32_t x ,uint32_t y);
void initVec2I64(vec2int64_t * out , int64_t x ,int64_t y);
void initVec2U64(vec2uint64_t * out , uint64_t x ,uint64_t y);
void initVec2C(vec2char_t * out , char x ,char y);
void initVec2F(vec2f_t * out , float x ,float y);
void initVec2D(vec2d_t * out, double x , double y);

//Allocate and initialize Vector
vec2int8_t * allocVec2I8(int8_t x, int8_t y);
vec2uint8_t * allocVec2U8(uint8_t x, uint8_t y);
vec2int16_t * allocVec2I16(int16_t x, int16_t y);
vec2uint16_t * allocVec2U16(uint16_t x, uint16_t y);
vec2int32_t * allocVec2I32(int32_t x, int32_t y);
vec2uint32_t * allocVec2U32(uint32_t x, uint32_t y);
vec2int64_t * allocVec2I64(int64_t x, int64_t y);
vec2uint64_t * allocVec2U64(uint64_t x, uint64_t y);
vec2char_t * allocVec2C(char x, char y);
vec2f_t * allocVec2F(float x, float y);
vec2d_t * allocVec2D(double x, double y);

//getters and setters
void vec2i8_setX(vec2int8_t * out, int8_t x);
void vec2i8_setY(vec2int8_t * out, int8_t y);
int8_t vec2i8_X(vec2int8_t * out);
int8_t vec2i8_Y(vec2int8_t * out);
void vec2u8_setX(vec2uint8_t * out, uint8_t x);
void vec2u8_setY(vec2uint8_t * out, uint8_t y);
uint8_t vec2u8_X(vec2uint8_t * out);
uint8_t vec2u8_Y(vec2uint8_t * out);

void vec2i16_setX(vec2int16_t * out, int16_t x);
void vec2i16_setY(vec2int16_t * out, int16_t y);
int16_t vec2i16_X(vec2int16_t * out);
int16_t vec2i16_Y(vec2int16_t * out);
void vec2u16_setX(vec2uint16_t * out, uint16_t x);
void vec2u16_setY(vec2uint16_t * out, uint16_t y);
uint16_t vec2u16_X(vec2uint16_t * out);
uint16_t vec2u16_Y(vec2uint16_t * out);

void vec2i32_setX(vec2int32_t * out, int32_t x);
void vec2i32_setY(vec2int32_t * out, int32_t y);
int32_t vec2i32_X(vec2int32_t * out);
int32_t vec2i32_Y(vec2int32_t * out);
void vec2u32_setX(vec2uint32_t * out, uint32_t x);
void vec2u32_setY(vec2uint32_t * out, uint32_t y);
uint32_t vec2u32_X(vec2uint32_t * out);
uint32_t vec2u32_Y(vec2uint32_t * out);

void vec2i64_setX(vec2int64_t * out, int64_t x);
void vec2i64_setY(vec2int64_t * out, int64_t y);
int64_t vec2i64_X(vec2int64_t * out);
int64_t vec2i64_Y(vec2int64_t * out);
void vec2u64_setX(vec2uint64_t * out, uint64_t x);
void vec2u64_setY(vec2uint64_t * out, uint64_t y);
uint64_t vec2u64_X(vec2uint64_t * out);
uint64_t vec2u64_Y(vec2uint64_t * out);

void vec2char_setX(vec2char_t * out, char x);
void vec2char_setY(vec2char_t * out, char y);
char vec2char_X(vec2char_t * out);
char vec2char_Y(vec2char_t * out);

void vec2f_setX(vec2f_t * out, float x);
void vec2f_setY(vec2f_t * out, float y);
float vec2f_X(vec2f_t * out);
float vec2f_Y(vec2f_t * out);

void vec2d_setX(vec2d_t * out, double x);
void vec2d_setY(vec2d_t * out, double y);
double vec2d_X(vec2d_t * out);
double vec2d_Y(vec2d_t * out);

//addition
void vec2i8_add(vec2int8_t * out, vec2int8_t * other);
void vec2i8_addS(vec2int8_t * out , int8_t scalar);
vec2int8_t * vec2i8_add_r(vec2int8_t * out,vec2int8_t * other);
vec2int8_t * vec2i8_addS_r(vec2int8_t * out,int8_t scalar);

void vec2u8_add(vec2uint8_t * out, vec2uint8_t * other);
void vec2u8_addS(vec2int8_t * out , uint8_t scalar);
vec2uint8_t * vec2u8_add_r(vec2uint8_t * out,vec2uint8_t * other);
vec2uint8_t * vec2u8_addS_r(vec2uint8_t * out,uint8_t scalar);

void vec2i16_add(vec2int16_t * out, vec2int16_t * other);
void vec2i16_addS(vec2int16_t * out , int16_t scalar);
vec2int16_t * vec2i16_add_r(vec2int16_t * out,vec2int16_t * other);
vec2int16_t * vec2i16_addS_r(vec2int16_t * out,int16_t scalar);

void vec2u16_add(vec2uint16_t * out, vec2uint16_t * other);
void vec2u16_addS(vec2int16_t * out , uint16_t scalar);
vec2uint16_t * vec2u16_add_r(vec2uint16_t * out,vec2uint16_t * other);
vec2uint16_t * vec2u16_addS_r(vec2uint16_t * out,uint16_t scalar);

void vec2i32_add(vec2int32_t * out, vec2int32_t * other);
void vec2i32_addS(vec2int32_t * out , int32_t scalar);
vec2int32_t * vec2i32_add_r(vec2int32_t * out,vec2int32_t * other);
vec2int32_t * vec2i32_addS_r(vec2int32_t * out,int32_t scalar);

void vec2u32_add(vec2uint32_t * out, vec2uint32_t * other);
void vec2u32_addS(vec2int32_t * out , uint32_t scalar);
vec2uint32_t * vec2u32_add_r(vec2uint32_t * out,vec2uint32_t * other);
vec2uint32_t * vec2u32_addS_r(vec2uint32_t * out,uint32_t scalar);

void vec2i64_add(vec2int64_t * out, vec2int64_t * other);
void vec2i64_addS(vec2int64_t * out , int64_t scalar);
vec2int64_t * vec2i64_add_r(vec2int64_t * out,vec2int64_t * other);
vec2int64_t * vec2i64_addS_r(vec2int64_t * out,int64_t scalar);

void vec2u64_add(vec2uint64_t * out, vec2uint64_t * other);
void vec2u64_addS(vec2int64_t * out , uint64_t scalar);
vec2uint64_t * vec2u64_add_r(vec2uint64_t * out,vec2uint64_t * other);
vec2uint64_t * vec2u64_addS_r(vec2uint64_t * out,uint64_t scalar);

void vec2f_add(vec2f_t * out, vec2f_t * other);
void vec2f_addS(vec2f_t * out , float scalar);
vec2f_t * vec2f_add_r(vec2f_t * out,vec2f_t * other);
vec2f_t * vec2f_addS_r(vec2f_t * out, float scalar);

void vec2d_add(vec2d_t * out, vec2d_t * other);
void vec2d_addS(vec2d_t * out , double scalar);
vec2d_t * vec2d_add_r(vec2d_t * out,vec2d_t * other);
vec2d_t * vec2d_addS_r(vec2d_t * out,double scalar);

//subtraction
void vec2i8_sub(vec2int8_t * out, vec2int8_t * other);
void vec2i8_subS(vec2int8_t * out , int8_t scalar);
vec2int8_t * vec2i8_sub_r(vec2int8_t * out,vec2int8_t * other);
vec2int8_t * vec2i8_subS_r(vec2int8_t * out,int8_t scalar);

void vec2u8_sub(vec2uint8_t * out, vec2uint8_t * other);
void vec2u8_subS(vec2int8_t * out , uint8_t scalar);
vec2uint8_t * vec2u8_sub_r(vec2uint8_t * out,vec2uint8_t * other);
vec2uint8_t * vec2u8_subS_r(vec2uint8_t * out,uint8_t scalar);

void vec2i16_sub(vec2int16_t * out, vec2int16_t * other);
void vec2i16_subS(vec2int16_t * out , int16_t scalar);
vec2int16_t * vec2i16_sub_r(vec2int16_t * out,vec2int16_t * other);
vec2int16_t * vec2i16_subS_r(vec2int16_t * out,int16_t scalar);

void vec2u16_sub(vec2uint16_t * out, vec2uint16_t * other);
void vec2u16_subS(vec2int16_t * out , uint16_t scalar);
vec2uint16_t * vec2u16_sub_r(vec2uint16_t * out,vec2uint16_t * other);
vec2uint16_t * vec2u16_subS_r(vec2uint16_t * out,uint16_t scalar);

void vec2i32_sub(vec2int32_t * out, vec2int32_t * other);
void vec2i32_subS(vec2int32_t * out , int32_t scalar);
vec2int32_t * vec2i32_sub_r(vec2int32_t * out,vec2int32_t * other);
vec2int32_t * vec2i32_subS_r(vec2int32_t * out,int32_t scalar);

void vec2u32_sub(vec2uint32_t * out, vec2uint32_t * other);
void vec2u32_subS(vec2int32_t * out , uint32_t scalar);
vec2uint32_t * vec2u32_sub_r(vec2uint32_t * out,vec2uint32_t * other);
vec2uint32_t * vec2u32_subS_r(vec2uint32_t * out,uint32_t scalar);

void vec2i64_sub(vec2int64_t * out, vec2int64_t * other);
void vec2i64_subS(vec2int64_t * out , int64_t scalar);
vec2int64_t * vec2i64_sub_r(vec2int64_t * out,vec2int64_t * other);
vec2int64_t * vec2i64_subS_r(vec2int64_t * out,int64_t scalar);

void vec2u64_sub(vec2uint64_t * out, vec2uint64_t * other);
void vec2u64_subS(vec2int64_t * out , uint64_t scalar);
vec2uint64_t * vec2u64_sub_r(vec2uint64_t * out,vec2uint64_t * other);
vec2uint64_t * vec2u64_subS_r(vec2uint64_t * out,uint64_t scalar);

void vec2f_sub(vec2f_t * out, vec2f_t * other);
void vec2f_subS(vec2f_t * out , float scalar);
vec2f_t * vec2f_sub_r(vec2f_t * out,vec2f_t * other);
vec2f_t * vec2f_subS_r(vec2f_t * out, float scalar);

void vec2d_sub(vec2d_t * out, vec2d_t * other);
void vec2d_subS(vec2d_t * out , double scalar);
vec2d_t * vec2d_sub_r(vec2d_t * out,vec2d_t * other);
vec2d_t * vec2d_subS_r(vec2d_t * out,double scalar);


//Multiplication (only doing 16-bits+)
void vec2i16_mult(vec2int16_t * out, vec2int16_t * other);
void vec2i16_multS(vec2int16_t * out , int16_t scalar);
vec2int16_t * vec2i16_mult_r(vec2int16_t * out,vec2int16_t * other);
vec2int16_t * vec2i16_multS_r(vec2int16_t * out,int16_t scalar);

void vec2u16_mult(vec2uint16_t * out, vec2uint16_t * other);
void vec2u16_multS(vec2int16_t * out , uint16_t scalar);
vec2uint16_t * vec2u16_mult_r(vec2uint16_t * out,vec2uint16_t * other);
vec2uint16_t * vec2u16_multS_r(vec2uint16_t * out,uint16_t scalar);

void vec2i32_mult(vec2int32_t * out, vec2int32_t * other);
void vec2i32_multS(vec2int32_t * out , int32_t scalar);
vec2int32_t * vec2i32_mult_r(vec2int32_t * out,vec2int32_t * other);
vec2int32_t * vec2i32_multS_r(vec2int32_t * out,int32_t scalar);

void vec2u32_mult(vec2uint32_t * out, vec2uint32_t * other);
void vec2u32_multS(vec2int32_t * out , uint32_t scalar);
vec2uint32_t * vec2u32_mult_r(vec2uint32_t * out,vec2uint32_t * other);
vec2uint32_t * vec2u32_multS_r(vec2uint32_t * out,uint32_t scalar);

void vec2i64_mult(vec2int64_t * out, vec2int64_t * other);
void vec2i64_multS(vec2int64_t * out , int64_t scalar);
vec2int64_t * vec2i64_mult_r(vec2int64_t * out,vec2int64_t * other);
vec2int64_t * vec2i64_multS_r(vec2int64_t * out,int64_t scalar);

void vec2u64_mult(vec2uint64_t * out, vec2uint64_t * other);
void vec2u64_multS(vec2int64_t * out , uint64_t scalar);
vec2uint64_t * vec2u64_mult_r(vec2uint64_t * out,vec2uint64_t * other);
vec2uint64_t * vec2u64_multS_r(vec2uint64_t * out,uint64_t scalar);

void vec2f_mult(vec2f_t * out, vec2f_t * other);
void vec2f_multS(vec2f_t * out , float scalar);
vec2f_t * vec2f_mult_r(vec2f_t * out,vec2f_t * other);
vec2f_t * vec2f_multS_r(vec2f_t * out, float scalar);

void vec2d_mult(vec2d_t * out, vec2d_t * other);
void vec2d_multS(vec2d_t * out , double scalar);
vec2d_t * vec2d_mult_r(vec2d_t * out,vec2d_t * other);
vec2d_t * vec2d_multS_r(vec2d_t * out,double scalar);

//Divison (TO BE IMPLEMENTED)

//printing
void printVec2i8(vec2int8_t * vec);
void printVec2u8(vec2uint8_t * vec);
void printVec2i16(vec2int16_t * vec);
void printVec2u16(vec2uint16_t * vec);
void printVec2i32(vec2int32_t * vec);
void printVec2u32(vec2uint32_t * vec);
void printVec2i64(vec2int64_t * vec);
void printVec2u64(vec2uint64_t * vec);
void printVec2c(vec2char_t * vec);
void printVec2f(vec2f_t * vec);
void printVec2d(vec2d_t * vec);




#endif //VEC2_H_
