#ifndef FOUNDATIONS_PHYSICS_CIRCLE_H
#define FOUNDATIONS_PHYSICS_CIRCLE_H

#ifndef HAS_STDINT_H_
#include <stdint.h>
#define HAS_STDINT_H_
#endif

#ifndef HAS_STDBOOL_H_
#include <stdbool.h>
#define HAS_STDBOOL_H_
#endif

typedef struct _circleu8_t circleu8_t;
typedef struct _circlei8_t circlei8_t;

typedef struct _circleu16_t circleu16_t;
typedef struct _circlei16_t circlei16_t;

typedef struct _circleu32_t circleu32_t;
typedef struct _circlei32_t circlei32_t;

typedef struct _circleu64_t circleu64_t;
typedef struct _circlei64_t circlei64_t;

typedef struct _circlef_t circlef_t;
typedef struct _circled_t circled_t;
typedef struct _circleld_t circleld_t;

//error hendling
circle_error_t circle_get_error(void)


//Memory functions
//Malloc
circleu8_t * circleu8_malloc( uint8_t x,uint8_t y,uint8_t radius);
circlei8_t * circlei8_malloc( int8_t x,int8_t y,int8_t radius);
circleu16_t * circleu16_malloc( uint16_t x,uint16_t y,uint16_t radius);
circlei16_t * circlei16_malloc( int16_t x,int16_t y,int16_t radius);
circleu32_t * circleu32_malloc( uint32_t x,uint32_t y,uint32_t radius);
circlei32_t * circlei32_malloc( int32_t x,int32_t y,int32_t radius);
circleu64_t * circleu64_malloc( uint64_t x,uin64t_t y,uint64_t radius);
circlei64_t * circlei64_malloc( int64_t x,in64t_t y,int64_t radius);
circlef_t * circlef_malloc( float x,float y,float radius);
circled_t * circled_malloc( double x,double y,double radius);
circleld_t * circleld_malloc( long double x,long double y,long double radius);

//copy
circleu8_t * circleu8_copy(const circleu8_t * copy);
circlei8_t * circlei8_copy(const circlei8_t * copy);
circleu16_t * circleu16_copy(const circleu16_t * copy);
circlei16_t * circlei16_copy(const circlei16_t * copy);
circleu32_t * circleu32_copy(const circleu32_t * copy);
circlei32_t * circlei32_copy(const circlei32_t * copy);
circleu64_t * circleu64_copy(const circleu64_t * copy);
circlei64_t * circlei64_copy(const circlei64_t * copy);
circlef_t * circlef_copy(const circlef_t * copy);
circled_t * circled_copy(const circled_t * copy);
circleld_t * circleld_copy(const circleld_t * copy);

//Memmove
circleu8_t * circleu8_memmove(circleu8_t ** move);
circlei8_t * circlei8_memmove(circlei8_t ** move);
circleu16_t * circleu16_memmove(circleu16_t ** move);
circlei16_t * circlei16_memmove(circlei16_t ** move);
circleu32_t * circleu32_memmove(circleu32_t ** move);
circlei32_t * circlei32_memmove(circlei32_t ** move);
circleu64_t * circleu64_memmove(circleu64_t ** move);
circlei64_t * circlei64_memmove(circlei64_t ** move);
circlef_t * circlef_memmove(circlef_t ** move);
circled_t * circled_memmove(circled_t ** move);
circleld_t * circleld_memmove(circleld_t ** move);

void circleu8_free(circleu8_t * obj);
void circlei8_free(circlei8_t * obj);
void circleu16_free(circleu16_t * obj);
void circlei16_free(circlei16_t * obj);
void circleu32_free(circleu32_t * obj);
void circlei32_free(circlei32_t * obj);
void circleu64_free(circleu64_t * obj);
void circlei64_free(circlei64_t * obj);
void circlef_free(circlef_t * obj);
void circled_free(circled_t * obj);
void circleld_free(circleld_t * obj);


//getters
//getX()
uint8_t circleu8_getX(const circleu8_t * obj);
int8_t circlei8_getX(const circlei8_t * obj);
uint16_t circleu16_getX(const circleu16_t * obj);
int16_t circlei16_getX(const circlei16_t * obj);
uint32_t circleu32_getX(const circleu32_t * obj);
int32_t circlei32_getX(const circlei32_t * obj);
uint64_t circleu64_getX(const circleu64_t * obj);
int64_t circlei64_getX(const circlei64_t * obj);
float circlef_getX(const circlef_t * obj);
double circled_getX(const circled_t * obj);
long double circleld_getX(const circleld_t * obj);

//getY()
uint8_t circleu8_getY(const circleu8_t * obj);
int8_t circlei8_getY(const circlei8_t * obj);
uint16_t circleu16_getY(const circleu16_t * obj);
int16_t circlei16_getY(const circlei16_t * obj);
uint32_t circleu32_getY(const circleu32_t * obj);
int32_t circlei32_getY(const circlei32_t * obj);
uint64_t circleu64_getY(const circleu64_t * obj);
int64_t circlei64_getY(const circlei64_t * obj);
float circlef_getY(const circlef_t * obj);
double circled_getY(const circled_t * obj);
long double circleld_getY(const circleld_t * obj);

//getRadius()
uint8_t circleu8_getRadius(const circleu8_t * obj);
int8_t circlei8_getRadius(const circlei8_t * obj);
uint16_t circleu16_getRadius(const circleu16_t * obj);
int16_t circlei16_getRadius(const circlei16_t * obj);
uint32_t circleu32_getRadius(const circleu32_t * obj);
int32_t circlei32_getRadius(const circlei32_t * obj);
uint64_t circleu64_getRadius(const circleu64_t * obj);
int64_t circlei64_getRadius(const circlei64_t * obj);
float circlef_getRadius(const circlef_t * obj);
double circled_getRadius(const circled_t * obj);
long double circleld_getRadius(const circleld_t * obj);

//setters
//setX()
void circleu8_setX(circleu8_t * obj, uint8_t x);
void circlei8_setX(circlei8_t * obj, int8_t x);
void circleu16_setX(circleu16_t * obj, uint16_t x);
void circlei16_setX(circlei16_t * obj, int16_t x);
void circleu32_setX(circleu32_t * obj, uint32_t x);
void circlei32_setX(circlei32_t * obj, int32_t x);
void circleu64_setX(circleu64_t * obj, uint64_t x);
void circlei64_setX(circlei64_t * obj, int64_t x);
void circlef_setX(circlef_t * obj, float x);
void circled_setX(circled_t * obj, double x);
void circleld_setX(circleld_t * obj, long double x);

//setY()
void circleu8_setY(circleu8_t * obj, uint8_t y);
void circlei8_setY(circlei8_t * obj, int8_t y);
void circleu16_setY(circleu16_t * obj, uint16_t y);
void circlei16_setY(circlei16_t * obj, int16_t y);
void circleu32_setY(circleu32_t * obj, uint32_t y);
void circlei32_setY(circlei32_t * obj, int32_t y);
void circleu64_setY(circleu64_t * obj, uint64_t y);
void circlei64_setY(circlei64_t * obj, int64_t y);
void circlef_setY(circlef_t * obj, float y);
void circled_setY(circled_t * obj, double y);
void circleld_setY(circleld_t * obj, long double y);

//setRadius()
void circleu8_setRadius(circleu8_t * obj, uint8_t radius);
void circlei8_setRadius(circlei8_t * obj, int8_t radius);
void circleu16_setRadius(circleu16_t * obj, uint16_t radius);
void circlei16_setRadius(circlei16_t * obj, int16_t radius);
void circleu32_setRadius(circleu32_t * obj, uint32_t radius);
void circlei32_setRadius(circlei32_t * obj, int32_t radius);
void circleu64_setRadius(circleu64_t * obj, uint64_t radius);
void circlei64_setRadius(circlei64_t * obj, int64_t radius);
void circlef_setRadius(circlef_t * obj, float radius);
void circled_setRadius(circled_t * obj, double radius);
void circleld_setRadius(circleld_t * obj, long double radius);

//Manipulation Functions

//moveX()
void circleu8_moveX(circleu8_t * obj, uint8_t x);
void circlei8_moveX(circlei8_t * obj, int8_t x);
void circleu16_moveX(circleu16_t * obj, uint16_t x);
void circlei16_moveX(circlei16_t * obj, int16_t x);
void circleu32_moveX(circleu32_t * obj, uint32_t x);
void circlei32_moveX(circlei32_t * obj, int32_t x);
void circleu64_moveX(circleu64_t * obj, uint64_t x);
void circlei64_moveX(circlei64_t * obj, int64_t x);
void circlef_moveX(circlef_t * obj, float x);
void circled_moveX(circled_t * obj, double x);
void circleld_moveX(circleld_t * obj, long double x);

//moveY()
void circleu8_moveY(circleu8_t * obj, uint8_t y);
void circlei8_moveY(circlei8_t * obj, int8_t y);
void circleu16_moveY(circleu16_t * obj, uint16_t y);
void circlei16_moveY(circlei16_t * obj, int16_t y);
void circleu32_moveY(circleu32_t * obj, uint32_t y);
void circlei32_moveY(circlei32_t * obj, int32_t y);
void circleu64_moveY(circleu64_t * obj, uint64_t y);
void circlei64_moveY(circlei64_t * obj, int64_t y);
void circlef_moveY(circlef_t * obj, float y);
void circled_moveY(circled_t * obj, double y);
void circleld_moveY(circleld_t * obj, long double y);

//move()
void circleu8_move(circleu8_t * obj, uint8_t x, uint8_t y);
void circlei8_move(circlei8_t * obj, int8_t x, int8_t y);
void circleu16_move(circleu16_t * obj, uint16_t x, uint16_t y);
void circlei16_move(circlei16_t * obj, int16_t x, int16_t y);
void circleu32_move(circleu32_t * obj, uint32_t x, uint32_t y);
void circlei32_move(circlei32_t * obj, int32_t x, int32_t y);
void circleu64_move(circleu64_t * obj, uint64_t x, uint64_t y);
void circlei64_move(circlei64_t * obj, int64_t x, int64_t y);
void circlef_move(circlef_t * obj, float x, float y);
void circled_move(circled_t * obj, double x, double y);
void circleld_move(circleld_t * obj, long double x, long double y);

//grow()
void circleu8_grow(circleu8_t * obj, uint8_t radius);
void circlei8_grow(circlei8_t * obj, int8_t radius);
void circleu16_grow(circleu16_t * obj, uint16_t radius);
void circlei16_grow(circlei16_t * obj, int16_t radius);
void circleu32_grow(circleu32_t * obj, uint32_t radius);
void circlei32_grow(circlei32_t * obj, int32_t radius);
void circleu64_grow(circleu64_t * obj, uint64_t radius);
void circlei64_grow(circlei64_t * obj, int64_t radius);
void circlef_grow(circlef_t * obj, float radius);
void circled_grow(circled_t * obj, double radius);
void circleld_grow(circleld_t * obj, long double radius);

//shrink()
void circleu8_shrink(circleu8_t * obj, uint8_t radius);
void circlei8_shrink(circlei8_t * obj, int8_t radius);
void circleu16_shrink(circleu16_t * obj, uint16_t radius);
void circlei16_shrink(circlei16_t * obj, int16_t radius);
void circleu32_shrink(circleu32_t * obj, uint32_t radius);
void circlei32_shrink(circlei32_t * obj, int32_t radius);
void circleu64_shrink(circleu64_t * obj, uint64_t radius);
void circlei64_shrink(circlei64_t * obj, int64_t radius);
void circlef_shrink(circlef_t * obj, float radius);
void circled_shrink(circled_t * obj, double radius);
void circleld_shrink(circleld_t * obj, long double radius);


//Relationships
//collides()
bool circleu8_collides(const circleu8_t * obj, const circleu8_t * other);
bool circlei8_collides(const circlei8_t * obj, const circlei8_t * other);
bool circleu16_collides(const circleu16_t * obj, const circleu16_t * other);
bool circlei16_collides(const circlei16_t * obj, const circlei16_t * other);
bool circleu32_collides(const circleu32_t * obj, const circleu32_t * other);
bool circlei32_collides(const circlei32_t * obj, const circlei32_t * other);
bool circleu64_collides(const circleu64_t * obj, const circleu64_t * other);
bool circlei64_collides(const circlei64_t * obj, const circlei64_t * other);
bool circlef_collides(const circlef_t * obj, const circlef_t * other);
bool circled_collides(const circled_t * obj, const circled_t * other);
bool circleld_collides(const circleld_t * obj, const circleld_t * other);

//contains_point()
bool circleu8_contains_point(const circleu8_t * obj, uint8_t x, uint8_t y);
bool circlei8_contains_point(const circlei8_t * obj, int8_t x, int8_t y);
bool circleu16_contains_point(const circleu16_t * obj, uint16_t x, uint16_t y);
bool circlei16_contains_point(const circlei16_t * obj, int16_t x, int16_t y);
bool circleu32_contains_point(const circleu32_t * obj, uint32_t x, uint32_t y);
bool circlei32_contains_point(const circlei32_t * obj, int32_t x, int32_t y);
bool circleu64_contains_point(const circleu64_t * obj, uint64_t x, uint64_t y);
bool circlei64_contains_point(const circlei64_t * obj, int64_t x, int64_t y);
bool circlef_contains_point(const circlef_t * obj, float x ,float y);
bool circled_contains_point(const circled_t * obj, double x, double y);
bool circleld_contains_point(const circleld_t * obj, long double x, long double y);


//Utilities
//equals()
bool circleu8_equals(const circleu8_t * obj, const circleu8_t * other);
bool circlei8_equals(const circlei8_t * obj, const circlei8_t * other);
bool circleu16_equals(const circleu16_t * obj, const circleu16_t * other);
bool circlei16_equals(const circlei16_t * obj, const circlei16_t * other);
bool circleu32_equals(const circleu32_t * obj, const circleu32_t * other);
bool circlei32_equals(const circlei32_t * obj, const circlei32_t * other);
bool circleu64_equals(const circleu64_t * obj, const circleu64_t * other);
bool circlei64_equals(const circlei64_t * obj, const circlei64_t * other);
bool circlef_equals(const circlef_t * obj, const circlef_t * other);
bool circled_equals(const circled_t * obj, const circled_t * other);
bool circleld_equals(const circleld_t * obj, const circleld_t * other);

//print()
void circleu8_print(const circleu8_t * obj);
void circlei8_print(const circlei8_t * obj);
void circleu16_print(const circleu16_t * obj);
void circlei16_print(const circlei16_t * obj);
void circleu32_print(const circleu32_t * obj);
void circlei32_print(const circlei32_t * obj);
void circleu64_print(const circleu64_t * obj);
void circlei64_print(const circlei64_t * obj);
void circlef_print(const circlef_t * obj);
void circled_print(const circled_t * obj);
void circleld_print(const circleld_t * obj);

// getSize meta-function
size_t circleu8_size(void);
size_t circlei8_size(void);
size_t circleu16_size(void);
size_t circlei16_size(void);
size_t circleu32_size(void);
size_t circlei32_size(void);
size_t circleu64_size(void);
size_t circlei64_size(void);
size_t circlef_size(void);
size_t circled_size(void);
size_t circleld_size(void);


//Serialization
//toArray()
void circleu8_toArray(uint8_t * output , const circleu8_t * src);
void circlei8_toArray(int8_t * output , const circlei8_t * src);
void circleu16_toArray(uint16_t * output , const circleu16_t * src);
void circlei16_toArray(int16_t * output , const circlei16_t * src);
void circleu32_toArray(uint32_t * output , const circleu32_t * src);
void circlei32_toArray(int32_t * output , const circlei32_t * src);
void circleu64_toArray(uint64_t * output , const circleu64_t * src);
void circlei64_toArray(int64_t * output , const circlei64_t * src);
void circlef_toArray(float * output , const circlef_t * src);
void circled_toArray(double * output , const circled_t * src);
void circleld_toArray(long double * output , const circleld_t * src);

//fromArray()
void circleu8_fromArray(circleu8_t * output, const uint8_t * src);
void circlei8_fromArray(circlei8_t * output, const int8_t * src);
void circleu16_fromArray(circleu16_t * output, const uint16_t * src);
void circlei16_fromArray(circlei16_t * output, const int16_t * src);
void circleu32_fromArray(circleu32_t * output, const uint32_t * src);
void circlei32_fromArray(circlei32_t * output, const int32_t * src);
void circleu64_fromArray(circleu64_t * output, const uint64_t * src);
void circlei64_fromArray(circlei64_t * output, const int64_t * src);
void circlef_fromArray(circlef_t * output, const float * src);
void circled_fromArray(circled_t * output, const double * src);
void circleld_fromArray(circleld_t * output, const long double * src);

// toBytes()
void circleu8_toBytes(const circleu8_t* obj, uint8_t* dst);
void circlei8_toBytes(const circlei8_t* obj, uint8_t* dst);
void circleu16_toBytes(const circleu16_t* obj, uint8_t* dst);
void circlei16_toBytes(const circlei16_t* obj, uint8_t* dst);
void circleu32_toBytes(const circleu32_t* obj, uint8_t* dst);
void circlei32_toBytes(const circlei32_t* obj, uint8_t* dst);
void circleu64_toBytes(const circleu64_t* obj, uint8_t* dst);
void circlei64_toBytes(const circlei64_t* obj, uint8_t* dst);
void circlef_toBytes(const circlef_t* obj, uint8_t* dst);
void circled_toBytes(const circled_t* obj, uint8_t* dst);
void circleld_toBytes(const circleld_t* obj, uint8_t* dst);

// fromBytes()
void circleu8_fromBytes(circleu8_t* obj, const uint8_t* src);
void circlei8_fromBytes(circlei8_t* obj, const uint8_t* src);
void circleu16_fromBytes(circleu16_t* obj, const uint8_t* src);
void circlei16_fromBytes(circlei16_t* obj, const uint8_t* src);
void circleu32_fromBytes(circleu32_t* obj, const uint8_t* src);
void circlei32_fromBytes(circlei32_t* obj, const uint8_t* src);
void circleu64_fromBytes(circleu64_t* obj, const uint8_t* src);
void circlei64_fromBytes(circlei64_t* obj, const uint8_t* src);
void circlef_fromBytes(circlef_t* obj, const uint8_t* src);
void circled_fromBytes(circled_t* obj, const uint8_t* src);
void circleld_fromBytes(circleld_t* obj, const uint8_t* src);

// toBytesLE()
void circleu8_toBytesLE(const circleu8_t* obj, uint8_t* dst);
void circlei8_toBytesLE(const circlei8_t* obj, uint8_t* dst);
void circleu16_toBytesLE(const circleu16_t* obj, uint8_t* dst);
void circlei16_toBytesLE(const circlei16_t* obj, uint8_t* dst);
void circleu32_toBytesLE(const circleu32_t* obj, uint8_t* dst);
void circlei32_toBytesLE(const circlei32_t* obj, uint8_t* dst);
void circleu64_toBytesLE(const circleu64_t* obj, uint8_t* dst);
void circlei64_toBytesLE(const circlei64_t* obj, uint8_t* dst);
void circlef_toBytesLE(const circlef_t* obj, uint8_t* dst);
void circled_toBytesLE(const circled_t* obj, uint8_t* dst);
void circleld_toBytesLE(const circleld_t* obj, uint8_t* dst);

// fromBytesLE()
void circleu8_fromBytesLE(circleu8_t* obj, const uint8_t* src);
void circlei8_fromBytesLE(circlei8_t* obj, const uint8_t* src);
void circleu16_fromBytesLE(circleu16_t* obj, const uint8_t* src);
void circlei16_fromBytesLE(circlei16_t* obj, const uint8_t* src);
void circleu32_fromBytesLE(circleu32_t* obj, const uint8_t* src);
void circlei32_fromBytesLE(circlei32_t* obj, const uint8_t* src);
void circleu64_fromBytesLE(circleu64_t* obj, const uint8_t* src);
void circlei64_fromBytesLE(circlei64_t* obj, const uint8_t* src);
void circlef_fromBytesLE(circlef_t* obj, const uint8_t* src);
void circled_fromBytesLE(circled_t* obj, const uint8_t* src);
void circleld_fromBytesLE(circleld_t* obj, const uint8_t* src);




#endif
