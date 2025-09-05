#ifndef FOUNDATIONS_PHYSICS_BOX_H
#define FOUNDATIONS_PHYSICS_BOX_H

#ifndef HAS_STDINT_H_
#include <stdint.h>
#define HAS_STDINT_H_
#endif

#ifndef HAS_STDBOOL_H_
#include <stdbool.h>
#define HAS_STDBOOL_H_
#endif

typedef struct _boxu8_t boxu8_t;
typedef struct _boxi8_t boxi8_t;

typedef struct _boxu16_t boxu16_t;
typedef struct _boxi16_t boxi16_t;

typedef struct _boxu32_t boxu32_t;
typedef struct _boxi32_t boxi32_t;

typedef struct _boxu64_t boxu64_t;
typedef struct _boxi64_t boxi64_t;

typedef struct _boxf_t boxf_t;
typedef struct _boxd_t boxd_t;
typedef struct _boxld_t boxld_t;

//error handling
const char* box_get_error_string(void);

//Memory Allocation
//malloc from parameters
boxu8_t * boxu8_malloc(uint8_t posx,uint8_t posy,uint8_t posz,uint8_t width,uint8_t height,uint8_t depth);
boxi8_t * boxi8_malloc(int8_t posx,int8_t posy,int8_t posz,int8_t width,int8_t height,int8_t depth);
boxu16_t * boxu16_malloc(uint16_t posx,uint16_t posy,uint16_t posz,uint16_t width,uint16_t height,uint16_t depth);
boxi16_t * boxi16_malloc(int16_t posx,int16_t posy,int16_t posz,int16_t width,int16_t height,int16_t depth);
boxu32_t * boxu32_malloc(uint32_t posx,uint32_t posy,uint32_t posz,uint32_t width,uint32_t height,uint32_t depth);
boxi32_t * boxi32_malloc(int32_t posx,int32_t posy,int32_t posz,int32_t width,int32_t height,int32_t depth);
boxu64_t * boxu64_malloc(uint64_t posx,uint64_t posy,uint64_t posz,uint64_t width,uint64_t height,uint64_t depth);
boxi64_t * boxi64_malloc(int64_t posx,int64_t posy,int64_t posz,int64_t width,int64_t height,int64_t depth);
boxf_t * boxf_malloc(float posx,float posy,float posz,float width,float height,float depth);
boxd_t * boxd_malloc(double posx,double posy,double posz,double width,double height,double depth);
boxld_t * boxld_malloc(long double posx,long double posy,long double posz,long double width,long double height,long double depth);

//malloc empty
boxu8_t * boxu8_mallocEmpty();
boxi8_t * boxi8_mallocEmpty();
boxu16_t * boxu16_mallocEmpty();
boxi16_t * boxi16_mallocEmpty();
boxu32_t * boxu32_mallocEmpty();
boxi32_t * boxi32_mallocEmpty();
boxu64_t * boxu64_mallocEmpty();
boxi64_t * boxi64_mallocEmpty();
boxf_t * boxf_mallocEmpty();
boxd_t * boxd_mallocEmpty();
boxld_t * boxld_mallocEmpty();

//malloc via copy from other
boxu8_t * boxu8_copy(const boxu8_t * copy);
boxi8_t * boxi8_copy(const boxi8_t * copy);
boxu16_t * boxu16_copy(const boxu16_t * copy);
boxi16_t * boxi16_copy(const boxi16_t * copy);
boxu32_t * boxu32_copy(const boxu32_t * copy);
boxi32_t * boxi32_copy(const boxi32_t * copy);
boxu64_t * boxu64_copy(const boxu64_t * copy);
boxi64_t * boxi64_copy(const boxi64_t * copy);
boxf_t * boxf_copy(const boxf_t * copy);
boxd_t * boxd_copy(const boxd_t * copy);
boxld_t * boxld_copy(const boxld_t * copy);

//Move via other
boxu8_t * boxu8_memmove(boxu8_t ** move);
boxi8_t * boxi8_memmove(boxi8_t ** move);
boxu16_t * boxu16_memmove(boxu16_t ** move);
boxi16_t * boxi16_memmove(boxi16_t ** move);
boxu32_t * boxu32_memmove(boxu32_t ** move);
boxi32_t * boxi32_memmove(boxi32_t ** move);
boxu64_t * boxu64_memmove(boxu64_t ** move);
boxi64_t * boxi64_memmove(boxi64_t ** move);
boxf_t * boxf_memmove(boxf_t ** move);
boxd_t * boxd_memmove(boxd_t ** move);
boxld_t * boxld_memmove(boxld_t ** move);

//free
void boxu8_free(boxu8_t * obj);
void boxi8_free(boxi8_t * obj);
void boxu16_free(boxu16_t * obj);
void boxi16_free(boxi16_t * obj);
void boxu32_free(boxu32_t * obj);
void boxi32_free(boxi32_t * obj);
void boxu64_free(boxu64_t * obj);
void boxi64_free(boxi64_t * obj);
void boxf_free(boxf_t * obj);
void boxd_free(boxd_t * obj);
void boxld_free(boxld_t * obj);

//Accessors
//getX()
uint8_t boxu8_getX(const boxu8_t * obj);
int8_t boxi8_getX(const boxi8_t * obj);
uint16_t boxu16_getX(const boxu16_t * obj);
int16_t boxi16_getX(const boxi16_t * obj);
uint32_t boxu32_getX(const boxu32_t * obj);
int32_t boxi32_getX(const boxi32_t * obj);
uint64_t boxu64_getX(const boxu64_t * obj);
int64_t boxi64_getX(const boxi64_t * obj);
float boxf_getX(const boxf_t * obj);
double boxd_getX(const boxd_t * obj);
long double boxld_getX(const boxld_t * obj);

//getY()
uint8_t boxu8_getY(const boxu8_t * obj);
int8_t boxi8_getY(const boxi8_t * obj);
uint16_t boxu16_getY(const boxu16_t * obj);
int16_t boxi16_getY(const boxi16_t * obj);
uint32_t boxu32_getY(const boxu32_t * obj);
int32_t boxi32_getY(const boxi32_t * obj);
uint64_t boxu64_getY(const boxu64_t * obj);
int64_t boxi64_getY(const boxi64_t * obj);
float boxf_getY(const boxf_t * obj);
double boxd_getY(const boxd_t * obj);
long double boxld_getY(const boxld_t * obj);

//getZ()
uint8_t boxu8_getZ(const boxu8_t * obj);
int8_t boxi8_getZ(const boxi8_t * obj);
uint16_t boxu16_getZ(const boxu16_t * obj);
int16_t boxi16_getZ(const boxi16_t * obj);
uint32_t boxu32_getZ(const boxu32_t * obj);
int32_t boxi32_getZ(const boxi32_t * obj);
uint64_t boxu64_getZ(const boxu64_t * obj);
int64_t boxi64_getZ(const boxi64_t * obj);
float boxf_getZ(const boxf_t * obj);
double boxd_getZ(const boxd_t * obj);
long double boxld_getZ(const boxld_t * obj);

//getWidth()
uint8_t boxu8_getWidth(const boxu8_t * obj);
int8_t boxi8_getWidth(const boxi8_t * obj);
uint16_t boxu16_getWidth(const boxu16_t * obj);
int16_t boxi16_getWidth(const boxi16_t * obj);
uint32_t boxu32_getWidth(const boxu32_t * obj);
int32_t boxi32_getWidth(const boxi32_t * obj);
uint64_t boxu64_getWidth(const boxu64_t * obj);
int64_t boxi64_getWidth(const boxi64_t * obj);
float boxf_getWidth(const boxf_t * obj);
double boxd_getWidth(const boxd_t * obj);
long double boxld_getWidth(const boxld_t * obj);


//getHeight()
uint8_t boxu8_getHeight(const boxu8_t * obj);
int8_t boxi8_getHeight(const boxi8_t * obj);
uint16_t boxu16_getHeight(const boxu16_t * obj);
int16_t boxi16_getHeight(const boxi16_t * obj);
uint32_t boxu32_getHeight(const boxu32_t * obj);
int32_t boxi32_getHeight(const boxi32_t * obj);
uint64_t boxu64_getHeight(const boxu64_t * obj);
int64_t boxi64_getHeight(const boxi64_t * obj);
float boxf_getHeight(const boxf_t * obj);
double boxd_getHeight(const boxd_t * obj);
long double boxld_getHeight(const boxld_t * obj);

//getDepth()
uint8_t boxu8_getDepth(const boxu8_t * obj);
int8_t boxi8_getDepth(const boxi8_t * obj);
uint16_t boxu16_getDepth(const boxu16_t * obj);
int16_t boxi16_getDepth(const boxi16_t * obj);
uint32_t boxu32_geDepth(const boxu32_t * obj);
int32_t boxi32_getDepth(const boxi32_t * obj);
uint64_t boxu64_getDepth(const boxu64_t * obj);
int64_t boxi64_getDepth(const boxi64_t * obj);
float boxf_getDepth(const boxf_t * obj);
double boxd_getDepth(const boxd_t * obj);
long double boxld_getDepth(const boxld_t * obj);


//setters
//setPosX()
void boxu8_setPosX(boxu8_t * obj, uint8_t posX);
void boxi8_setPosX(boxi8_t * obj, int8_t posX);
void boxu16_setPosX(boxu16_t * obj, uint16_t posX);
void boxi16_setPosX(boxi16_t * obj, int16_t posX);
void boxu32_setPosX(boxu32_t * obj, uint32_t posX);
void boxi32_setPosX(boxi32_t * obj, int32_t posX);
void boxu64_setPosX(boxu64_t * obj, uint64_t posX);
void boxi64_setPosX(boxi64_t * obj, int64_t posX);
void boxf_setPosX(boxf_t * obj, float posX);
void boxd_setPosX(boxd_t * obj, double posX);
void boxld_setPosX(boxld_t * obj, long double posX);

//setPosY()
void boxu8_setPosY(boxu8_t * obj, uint8_t posY);
void boxi8_setPosY(boxi8_t * obj, int8_t posY);
void boxu16_setPosY(boxu16_t * obj, uint16_t posY);
void boxi16_setPosY(boxi16_t * obj, int16_t posY);
void boxu32_setPosY(boxu32_t * obj, uint32_t posY);
void boxi32_setPosY(boxi32_t * obj, int32_t posY);
void boxu64_setPosY(boxu64_t * obj, uint64_t posY);
void boxi64_setPosY(boxi64_t * obj, int64_t posY);
void boxf_setPosY(boxf_t * obj, float posY);
void boxd_setPosY(boxd_t * obj, double posY);
void boxld_setPosY(boxld_t * obj, long double posY);

//setPosZ()
void boxu8_setPosZ(boxu8_t * obj, uint8_t posZ);
void boxi8_setPosZ(boxi8_t * obj, int8_t posZ);
void boxu16_setPosZ(boxu16_t * obj, uint16_t posZ);
void boxi16_setPosZ(boxi16_t * obj, int16_t posZ);
void boxu32_setPosZ(boxu32_t * obj, uint32_t posZ);
void boxi32_setPosZ(boxi32_t * obj, int32_t posZ);
void boxu64_setPosZ(boxu64_t * obj, uint64_t posZ);
void boxi64_setPosZ(boxi64_t * obj, int64_t posZ);
void boxf_setPosZ(boxf_t * obj, float posZ);
void boxd_setPosZ(boxd_t * obj, double posZ);
void boxld_setPosZ(boxld_t * obj, long double posZ);

//setPos()
void boxu8_setPos(boxu8_t * obj, uint8_t posX, uint8_t posY, uint8_t posZ);
void boxi8_setPos(boxi8_t * obj, int8_t posX, int8_t posY, int8_t posZ);
void boxu16_setPos(boxu16_t * obj, uint16_t posX, uint16_t posY, uint16_t posZ);
void boxi16_setPos(boxi16_t * obj, int16_t posX, int16_t posY, int16_t posZ);
void boxu32_setPos(boxu32_t * obj, uint32_t posX, uint32_t posY, uint32_t posZ);
void boxi32_setPos(boxi32_t * obj, int32_t posX, int32_t posY, int32_t posZ);
void boxu64_setPos(boxu64_t * obj, uint64_t posX, uint64_t posY, uint64_t posZ);
void boxi64_setPos(boxi64_t * obj, int64_t posX, int64_t posY, int64_t posZ);
void boxf_setPos(boxf_t * obj, float posX, float posY, float posZ);
void boxd_setPos(boxd_t * obj, double posX, double posY, double posZ);
void boxld_setPos(boxld_t * obj, long double posX, long double posY, long double posZ);

//setWidth()
void boxu8_setWidth(boxu8_t * obj, uint8_t width);
void boxi8_setWidth(boxi8_t * obj, int8_t width);
void boxu16_setWidth(boxu16_t * obj, uint16_t width);
void boxi16_setWidth(boxi16_t * obj, int16_t width);
void boxu32_setWidth(boxu32_t * obj, uint32_t width);
void boxi32_setWidth(boxi32_t * obj, int32_t width);
void boxu64_setWidth(boxu64_t * obj, uint64_t width);
void boxi64_setWidth(boxi64_t * obj, int64_t width);
void boxf_setWidth(boxf_t * obj, float width);
void boxd_setWidth(boxd_t * obj, double width);
void boxld_setWidth(boxld_t * obj, long double width);

//setHeight()
void boxu8_setHeight(boxu8_t * obj, uint8_t height);
void boxi8_setHeight(boxi8_t * obj, int8_t height);
void boxu16_setHeight(boxu16_t * obj, uint16_t height);
void boxi16_setHeight(boxi16_t * obj, int16_t height);
void boxu32_setHeight(boxu32_t * obj, uint32_t height);
void boxi32_setHeight(boxi32_t * obj, int32_t height);
void boxu64_setHeight(boxu64_t * obj, uint64_t height);
void boxi64_setHeight(boxi64_t * obj, int64_t height);
void boxf_setHeight(boxf_t * obj, float height);
void boxd_setHeight(boxd_t * obj, double height);
void boxld_setHeight(boxld_t * obj, long double height);

//setDepth()
void boxu8_setDepth(boxu8_t * obj, uint8_t depth);
void boxi8_setDepth(boxi8_t * obj, int8_t depth);
void boxu16_setDepth(boxu16_t * obj, uint16_t depth);
void boxi16_setDepth(boxi16_t * obj, int16_t depth);
void boxu32_setDepth(boxu32_t * obj, uint32_t depth);
void boxi32_setDepth(boxi32_t * obj, int32_t depth);
void boxu64_setDepth(boxu64_t * obj, uint64_t depth);
void boxi64_setDepth(boxi64_t * obj, int64_t depth);
void boxf_setDepth(boxf_t * obj, float depth);
void boxd_setDepth(boxd_t * obj, double depth);
void boxld_setDepth(boxld_t * obj, long double depth);

//setSize()
void boxu8_setSize(boxu8_t * obj, uint8_t width, uint8_t height, uint8_t depth);
void boxi8_setSize(boxi8_t * obj, int8_t width, int8_t height, int8_t depth);
void boxu16_setSize(boxu16_t * obj, uint16_t width, uint16_t height, uint16_t depth);
void boxi16_setSize(boxi16_t * obj, int16_t width, int16_t height, int16_t depth);
void boxu32_setSize(boxu32_t * obj, uint32_t width, uint32_t height, uint32_t depth);
void boxi32_setSize(boxi32_t * obj, int32_t width, int32_t height, int32_t depth);
void boxu64_setSize(boxu64_t * obj, uint64_t width, uint64_t height, uint64_t depth);
void boxi64_setSize(boxi64_t * obj, int64_t width, int64_t height, int64_t depth);
void boxf_setSize(boxf_t * obj, float width, float height, float depth);
void boxd_setSize(boxd_t * obj, double width, double height, double depth);
void boxld_setSize(boxld_t * obj, long double width, long double depth, long double depth);

//moveX()
void boxu8_moveX(boxu8_t * obj, uint8_t dx);
void boxi8_moveX(boxi8_t * obj, int8_t dx);
void boxu16_moveX(boxu16_t * obj, uint16_t dx);
void boxi16_moveX(boxi16_t * obj, int16_t dx);
void boxu32_moveX(boxu32_t * obj, uint32_t dx);
void boxi32_moveX(boxi32_t * obj, int32_t dx);
void boxu64_moveX(boxu64_t * obj, uint64_t dx);
void boxi64_moveX(boxi64_t * obj, int64_t dx);
void boxf_moveX(boxf_t * obj, float dx);
void boxd_moveX(boxd_t * obj, double dx);
void boxld_moveX(boxld_t * obj, long double dx);

//moveY()
void boxu8_moveY(boxu8_t * obj, uint8_t dy);
void boxi8_moveY(boxi8_t * obj, int8_t dy);
void boxu16_moveY(boxu16_t * obj, uint16_t dy);
void boxi16_moveY(boxi16_t * obj, int16_t dy);
void boxu32_moveY(boxu32_t * obj, uint32_t dy);
void boxi32_moveY(boxi32_t * obj, int32_t dy);
void boxu64_moveY(boxu64_t * obj, uint64_t dy);
void boxi64_moveY(boxi64_t * obj, int64_t dy);
void boxf_moveY(boxf_t * obj, float dy);
void boxd_moveY(boxd_t * obj, double dy);
void boxld_moveY(boxld_t * obj, long double dy);

//moveZ()
void boxu8_moveZ(boxu8_t * obj, uint8_t dz);
void boxi8_moveZ(boxi8_t * obj, int8_t dz);
void boxu16_moveZ(boxu16_t * obj, uint16_t dz);
void boxi16_moveZ(boxi16_t * obj, int16_t dz);
void boxu32_moveZ(boxu32_t * obj, uint32_t dz);
void boxi32_moveZ(boxi32_t * obj, int32_t dz);
void boxu64_moveZ(boxu64_t * obj, uint64_t dz);
void boxi64_moveZ(boxi64_t * obj, int64_t dz);
void boxf_moveZ(boxf_t * obj, float dz);
void boxd_moveZ(boxd_t * obj, double dz);
void boxld_moveZ(boxld_t * obj, long double dz);

//move()
void boxu8_move(boxu8_t * obj, uint8_t dx, uint8_t dy, uint8_t dz);
void boxi8_move(boxi8_t * obj, int8_t dx, int8_td dy, int8_td dz);
void boxu16_move(boxu16_t * obj, uint16_t dx, uint16_t dy, uint16_t dz);
void boxi16_move(boxi16_t * obj, int16_t dx, int16_t dy, int16_t dz);
void boxu32_move(boxu32_t * obj, uint32_t dx, uint32_t dy, uint32_t dz);
void boxi32_move(boxi32_t * obj, int32_t dx, int32_t dy, int32_t dz);
void boxu64_move(boxu64_t * obj, uint64_t dx, uint64_t dy, uint64_t dz);
void boxi64_move(boxi64_t * obj, int64_t dx, int64_t dy, int64_t dz);
void boxf_move(boxf_t * obj, float dx, float dy, float dz);
void boxd_move(boxd_t * obj, double dx, double dy, double dz);
void boxld_move(boxld_t * obj, long double dx, long double dy, long double dz);

//resizeWidth()
void boxu8_resizeWidth(boxu8_t * obj, uint8_t dw);
void boxi8_resizeWidth(boxi8_t * obj, int8_t dw);
void boxu16_resizeWidth(boxu16_t * obj, uint16_t dw);
void boxi16_resizeWidth(boxi16_t * obj, int16_t dw);
void boxu32_resizeWidth(boxu32_t * obj, uint32_t dw);
void boxi32_resizeWidth(boxi32_t * obj, int32_t dw);
void boxu64_resizeWidth(boxu64_t * obj, uint64_t dw);
void boxi64_resizeWidth(boxi64_t * obj, int64_t dw);
void boxf_resizeWidth(boxf_t * obj, float dw);
void boxd_resizeWidth(boxd_t * obj, double dw);
void boxld_resizeWidth(boxld_t * obj, long double dw);


//resizeHeight()
void boxu8_resizeHeight(boxu8_t * obj, uint8_t dh);
void boxi8_resizeHeight(boxi8_t * obj, int8_t dh);
void boxu16_resizeHeight(boxu16_t * obj, uint16_t dh);
void boxi16_resizeHeight(boxi16_t * obj, int16_t dh);
void boxu32_resizeHeight(boxu32_t * obj, uint32_t dh);
void boxi32_resizeHeight(boxi32_t * obj, int32_t dh);
void boxu64_resizeHeight(boxu64_t * obj, uint64_t dh);
void boxi64_resizeHeight(boxi64_t * obj, int64_t dh);
void boxf_resizeHeight(boxf_t * obj, float dh);
void boxd_resizeHeight(boxd_t * obj, double dh);
void boxld_resizeHeight(boxld_t * obj, long double dh);

//resizeDepth()
void boxu8_resizeDepth(boxu8_t * obj, uint8_t dd);
void boxi8_resizeDepth(boxi8_t * obj, int8_t dd);
void boxu16_resizeDepth(boxu16_t * obj, uint16_t dd);
void boxi16_resizeDepth(boxi16_t * obj, int16_t dd);
void boxu32_resizeDepth(boxu32_t * obj, uint32_t dd);
void boxi32_resizeDepth(boxi32_t * obj, int32_t dd);
void boxu64_resizeDepth(boxu64_t * obj, uint64_t dd);
void boxi64_resizeDepth(boxi64_t * obj, int64_t dd);
void boxf_resizeDepth(boxf_t * obj, float dd);
void boxd_resizeDepth(boxd_t * obj, double dd);
void boxld_resizeDepth(boxld_t * obj, long double dd);

//resize()
void boxu8_resize(boxu8_t * obj, uint8_t dw, uint8_t dh, uint8_t dd);
void boxi8_resize(boxi8_t * obj, int8_t dw, int8_t dh, int8_t dd);
void boxu16_resize(boxu16_t * obj, uint16_t dw, uint16_t dh, uint16_t dd);
void boxi16_resize(boxi16_t * obj, int16_t dw, int16_t dh, int16_t dd);
void boxu32_resize(boxu32_t * obj, uint32_t dw, uint32_t dh, uint32_t dd);
void boxi32_resize(boxi32_t * obj, int32_t dw, int32_t dh, int32_t dd);
void boxu64_resize(boxu64_t * obj, uint64_t dw, uint64_t dh, uint64_t dd);
void boxi64_resize(boxi64_t * obj, int64_t dw, int64_t dh, int64_t dd);
void boxf_resize(boxf_t * obj, float dw, float dh, float dd);
void boxd_resize(boxd_t * obj, double dw, double dh, double dd);
void boxld_resize(boxld_t * obj, long double dw, long double dh, long double dd);

//Vector Extensions
#ifdef VEC3_DEFINED
//vec3 getPosition()
//YOU MUST FREE THIS MEMORY
vec3uint8_t * boxu8_getPosVec3(boxu8_t * obj);
vec3int8_t * boxi8_getPosVec3(boxi8_t * obj);
vec3uint16_t * boxu16_getPosVec3(boxu16_t * obj);
vec3int16_t * boxi16_getPosVec3(boxi16_t * obj);
vec3uint32_t * boxu32_getPosVec3(boxu32_t * obj);
vec3int32_t * boxi32_getPosVec3(boxi32_t * obj);
vec3uint64_t * boxu64_getPosVec3(boxu64_t * obj);
vec3int64_t * boxi64_getPosVec3(boxi64_t * obj);
vec3f8_t * boxf_getPosVec3(boxf_t * obj);
vec3f8_t * boxf_getPosVec3(boxf_t * obj);
vec3ld_t * boxld_getPosVec3(boxld_t * obj);


//vec3 getSize()
//YOU MUST FREE THIS MEMORY
vec3uint8_t * boxu8_getSizeVec3(boxu8_t * obj);
vec3int8_t * boxi8_getSizeVec3(boxi8_t * obj);
vec3uint16_t * boxu16_getSizeVec3(boxu16_t * obj);
vec3int16_t * boxi16_getSizeVec3(boxi16_t * obj);
vec3uint32_t * boxu32_getSizeVec3(boxu32_t * obj);
vec3int32_t * boxi32_getSizeVec3(boxi32_t * obj);
vec3uint64_t * boxu64_getSizeVec3(boxu64_t * obj);
vec3int64_t * boxi64_getSizeVec3(boxi64_t * obj);
vec3f8_t * boxf_getSizeVec3(boxf_t * obj);
vec3f8_t * boxf_getSizeVec3(boxf_t * obj);
vec3ld_t * boxld_getSizeVec3(boxld_t * obj);

//setSizeVec3()
void boxu8_setSizeVec3(boxu8_t * obj, const vec3uint8_t * size);
void boxi8_setSizeVec3(boxi8_t * obj, const vec3int8_t * size);
void boxu16_setSizeVec3(boxu16_t * obj, const vec3uint16_t * size);
void boxi16_setSizeVec3(boxi16_t * obj, const vec3int16_t * size);
void boxu32_setSizeVec3(boxu32_t * obj, const vec3uint32_t * size);
void boxi32_setSizeVec3(boxi32_t * obj, const vec3int32_t * size);
void boxu64_setSizeVec3(boxu64_t * obj, const vec3uint64_t * size);
void boxi64_setSizeVec3(boxi64_t * obj, const vec3int64_t * size);
void boxf_setSizeVec3(boxf_t * obj, const vec3f_t * size);
void boxd_setSizeVec3(boxd_t * obj, const vec3d_t * size);
void boxld_setSizeVec3(boxld_t * obj, const vec3ld_t * size);

//setPosVec3()
void boxu8_setPosVec3(boxu8_t * obj, const vec3uint8_t * pos);
void boxi8_setPosVec3(boxi8_t * obj, const vec3int8_t * pos);
void boxu16_setPosVec3(boxu16_t * obj, const vec3uint16_t * pos);
void boxi16_setPosVec3(boxi16_t * obj, const vec3int16_t * pos);
void boxu32_setPosVec3(boxu32_t * obj, const vec3uint32_t * pos);
void boxi32_setPosVec3(boxi32_t * obj, const vec3int32_t * pos);
void boxu64_setPosVec3(boxu64_t * obj, const vec3uint64_t * pos);
void boxi64_setPosVec3(boxi64_t * obj, const vec3int64_t * pos);
void boxf_setPosVec3(boxf_t * obj, const vec3f_t * pos);
void boxd_setPosVec3(boxd_t * obj, const vec3d_t * pos);
void boxld_setPosVec3(boxld_t * obj, const vec3ld_t * pos);

// moveVec3()
void boxu8_moveVec3(boxu8_t * obj, const vec3int8_t * delta);
void boxi8_moveVec3(boxi8_t * obj, const vec3int8_t * delta);
void boxu16_moveVec3(boxu16_t * obj, const vec3int16_t * delta);
void boxi16_moveVec3(boxi16_t * obj, const vec3int16_t * delta);
void boxu32_moveVec3(boxu32_t * obj, const vec3int32_t * delta);
void boxi32_moveVec3(boxi32_t * obj, const vec3int32_t * delta);
void boxu64_moveVec3(boxu64_t * obj, const vec3int64_t * delta);
void boxi64_moveVec3(boxi64_t * obj, const vec3int64_t * delta);
void boxf_moveVec3(boxf_t * obj, const vec3f_t * delta);
void boxd_moveVec3(boxd_t * obj, const vec3d_t * delta);
void boxld_moveVec3(boxld_t * obj, const vec3ld_t * delta);

// resizeVec3()
void boxu8_resizeVec3(boxu8_t * obj, const vec3uint8_t * delta);
void boxi8_resizeVec3(boxi8_t * obj, const vec3int8_t * delta);
void boxu16_resizeVec3(boxu16_t * obj, const vec3uint16_t * delta);
void boxi16_resizeVec3(boxi16_t * obj, const vec3int16_t * delta);
void boxu32_resizeVec3(boxu32_t * obj, const vec3uint32_t * delta);
void boxi32_resizeVec3(boxi32_t * obj, const vec3int32_t * delta);
void boxu64_resizeVec3(boxu64_t * obj, const vec3uint64_t * delta);
void boxi64_resizeVec3(boxi64_t * obj, const vec3int64_t * delta);
void boxf_resizeVec3(boxf_t * obj, const vec3f_t * delta);
void boxd_resizeVec3(boxd_t * obj, const vec3d_t * delta);
void boxld_resizeVec3(boxld_t * obj, const vec3ld_t * delta);

#endif


//Geometry
//getSideX()
uint8_t boxu8_getSideX(const boxu8_t * obj);
int8_t boxi8_getSideX(const boxi8_t * obj);
uint16_t boxu16_getSideX(const boxu16_t * obj);
int16_t boxi16_getSideX(const boxi16_t * obj);
uint32_t boxu32_getSideX(const boxu32_t * obj);
int32_t boxi32_getSideX(const boxi32_t * obj);
uint64_t boxu64_getSideX(const boxu64_t * obj);
int64_t boxi64_getSideX(const boxi64_t * obj);
float boxf_getSideX(const boxf_t * obj);
double boxd_getSideX(const boxd_t * obj);
long double boxld_getSideX(const boxld_t * obj);

//getSideY()
uint8_t boxu8_getSideY(const boxu8_t * obj);
int8_t boxi8_getSideY(const boxi8_t * obj);
uint16_t boxu16_getSideY(const boxu16_t * obj);
int16_t boxi16_getSideY(const boxi16_t * obj);
uint32_t boxu32_getSideY(const boxu32_t * obj);
int32_t boxi32_getSideY(const boxi32_t * obj);
uint64_t boxu64_getSideY(const boxu64_t * obj);
int64_t boxi64_getSideY(const boxi64_t * obj);
float boxf_getSideY(const boxf_t * obj);
double boxd_getSideY(const boxd_t * obj);
long double boxld_getSideY(const boxld_t * obj);

//getSideZ()
uint8_t boxu8_getSideZ(const boxu8_t * obj);
int8_t boxi8_getSideZ(const boxi8_t * obj);
uint16_t boxu16_getSideZ(const boxu16_t * obj);
int16_t boxi16_getSideZ(const boxi16_t * obj);
uint32_t boxu32_getSideZ(const boxu32_t * obj);
int32_t boxi32_getSideZ(const boxi32_t * obj);
uint64_t boxu64_getSideZ(const boxu64_t * obj);
int64_t boxi64_getSideZ(const boxi64_t * obj);
float boxf_getSideZ(const boxf_t * obj);
double boxd_getSideZ(const boxd_t * obj);
long double boxld_getSideZ(const boxld_t * obj);

//volume()
uint8_t boxu8_volume(const boxu8_t * obj);
int8_t boxi8_volume(const boxi8_t * obj);
uint16_t boxu16_volume(const boxu16_t * obj);
int16_t boxi16_volume(const boxi16_t * obj);
uint32_t boxu32_volume(const boxu32_t * obj);
int32_t boxi32_volume(const boxi32_t * obj);
uint64_t boxu64_volume(const boxu64_t * obj);
int64_t boxi64_volume(const boxi64_t * obj);
float boxf_volume(const boxf_t * obj);
double boxd_volume(const boxd_t * obj);
long double boxld_volume(const boxld_t * obj);

#ifdef HAS_RECT
//frontRect()
rectu8_t * boxu8_frontRect(boxu8_t * obj);
recti8_t * boxi8_frontRect(boxi8_t * obj);
rectu16_t * boxu16_frontRect(boxu16_t * obj);
recti16_t * boxi16_frontRect(boxi16_t * obj);
rectu32_t * boxu32_frontRect(boxu32_t * obj);
recti32_t * boxi32_frontRect(boxi32_t * obj);
rectu64_t * boxu64_frontRect(boxu64_t * obj);
recti64_t * boxi64_frontRect(boxi64_t * obj);
rectf_t * boxf_frontRect(boxf_t * obj);
rectd_t * boxd_frontRect(boxd_t * obj);
rectld_t * boxld_frontRect(boxld_t * obj);

//backRect()
rectu8_t * boxu8_backRect(boxu8_t * obj);
recti8_t * boxi8_backRect(boxi8_t * obj);
rectu16_t * boxu16_backRect(boxu16_t * obj);
recti16_t * boxi16_backRect(boxi16_t * obj);
rectu32_t * boxu32_backRect(boxu32_t * obj);
recti32_t * boxi32_backRect(boxi32_t * obj);
rectu64_t * boxu64_backRect(boxu64_t * obj);
recti64_t * boxi64_backRect(boxi64_t * obj);
rectf_t * boxf_backRect(boxf_t * obj);
rectd_t * boxd_backRect(boxd_t * obj);
rectld_t * boxld_backRect(boxld_t * obj);

//leftRect()
rectu8_t * boxu8_leftRect(boxu8_t * obj);
recti8_t * boxi8_leftRect(boxi8_t * obj);
rectu16_t * boxu16_leftRect(boxu16_t * obj);
recti16_t * boxi16_leftRect(boxi16_t * obj);
rectu32_t * boxu32_leftRect(boxu32_t * obj);
recti32_t * boxi32_leftRect(boxi32_t * obj);
rectu64_t * boxu64_leftRect(boxu64_t * obj);
recti64_t * boxi64_leftRect(boxi64_t * obj);
rectf_t * boxf_leftRect(boxf_t * obj);
rectd_t * boxd_leftRect(boxd_t * obj);
rectld_t * boxld_leftRect(boxld_t * obj);

//rightRect()
rectu8_t * boxu8_rightRect(boxu8_t * obj);
recti8_t * boxi8_rightRect(boxi8_t * obj);
rectu16_t * boxu16_rightRect(boxu16_t * obj);
recti16_t * boxi16_rightRect(boxi16_t * obj);
rectu32_t * boxu32_rightRect(boxu32_t * obj);
recti32_t * boxi32_rightRect(boxi32_t * obj);
rectu64_t * boxu64_rightRect(boxu64_t * obj);
recti64_t * boxi64_rightRect(boxi64_t * obj);
rectf_t * boxf_rightRect(boxf_t * obj);
rectd_t * boxd_rightRect(boxd_t * obj);
rectld_t * boxld_rightRect(boxld_t * obj);

//topRect()
rectu8_t * boxu8_topRect(boxu8_t * obj);
recti8_t * boxi8_topRect(boxi8_t * obj);
rectu16_t * boxu16_topRect(boxu16_t * obj);
recti16_t * boxi16_topRect(boxi16_t * obj);
rectu32_t * boxu32_topRect(boxu32_t * obj);
recti32_t * boxi32_topRect(boxi32_t * obj);
rectu64_t * boxu64_topRect(boxu64_t * obj);
recti64_t * boxi64_topRect(boxi64_t * obj);
rectf_t * boxf_topRect(boxf_t * obj);
rectd_t * boxd_topRect(boxd_t * obj);
rectld_t * boxld_topRect(boxld_t * obj);

//bottomRect()
rectu8_t * boxu8_bottomRect(boxu8_t * obj);
recti8_t * boxi8_bottomRect(boxi8_t * obj);
rectu16_t * boxu16_bottomRect(boxu16_t * obj);
recti16_t * boxi16_bottomRect(boxi16_t * obj);
rectu32_t * boxu32_bottomRect(boxu32_t * obj);
recti32_t * boxi32_bottomRect(boxi32_t * obj);
rectu64_t * boxu64_bottomRect(boxu64_t * obj);
recti64_t * boxi64_bottomRect(boxi64_t * obj);
rectf_t * boxf_bottomRect(boxf_t * obj);
rectd_t * boxd_bottomRect(boxd_t * obj);
rectld_t * boxld_bottomRect(boxld_t * obj);
#endif //has rect

//Relationships
//collides()
bool boxu8_collides(const boxu8_t * obj, const boxu8_t * other);
bool boxi8_collides(const boxi8_t * obj, const boxi8_t * other);
bool boxu16_collides(const boxu16_t * obj, const boxu16_t * other);
bool boxi16_collides(const boxi16_t * obj, const boxi16_t * other);
bool boxu32_collides(const boxu32_t * obj, const boxu32_t * other);
bool boxi32_collides(const boxi32_t * obj, const boxi32_t * other);
bool boxu64_collides(const boxu64_t * obj, const boxu64_t * other);
bool boxi64_collides(const boxi64_t * obj, const boxi64_t * other);
bool boxf_collides(const boxf_t * obj, const boxf_t * other);
bool boxd_collides(const boxd_t * obj, const boxd_t * other);
bool boxld_collides(const boxld_t * obj, const boxld_t * other);

//contains_point()
bool boxu8_contains_point(const boxu8_t * obj, uint8_t width, uint8_t height);
bool boxi8_contains_point(const boxi8_t * obj, int8_t width, int8_t height);
bool boxu16_contains_point(const boxu16_t * obj, uint16_t width, uint16_t height);
bool boxi16_contains_point(const boxi16_t * obj, int16_t width, int16_t height);
bool boxu32_contains_point(const boxu32_t * obj, uint32_t width, uint32_t height);
bool boxi32_contains_point(const boxi32_t * obj, int32_t width, int32_t height);
bool boxu64_contains_point(const boxu64_t * obj, uint64_t width, uint64_t height);
bool boxi64_contains_point(const boxi64_t * obj, int64_t width, int64_t height);
bool boxf_contains_point(const boxf_t * obj, float width, float height);
bool boxd_contains_point(const boxd_t * obj, double width, double height);
bool boxld_contains_point(const boxld_t * obj, long double width, long double height);

//contains_box()
bool boxu8_contains_box(const boxu8_t * obj, const boxu8_t * other);
bool boxi8_contains_box(const boxi8_t * obj, const boxi8_t * other);
bool boxu16_contains_box(const boxu16_t * obj, const boxu16_t * other);
bool boxi16_contains_box(const boxi16_t * obj, const boxi16_t * other);
bool boxu32_contains_box(const boxu32_t * obj, const boxu32_t * other);
bool boxi32_contains_box(const boxi32_t * obj, const boxi32_t * other);
bool boxu64_contains_box(const boxu64_t * obj, const boxu64_t * other);
bool boxi64_contains_box(const boxi64_t * obj, const boxi64_t * other);
bool boxf_contains_box(const boxf_t * obj, const boxf_t * other);
bool boxd_contains_box(const boxd_t * obj, const boxd_t * other);
bool boxld_contains_box(const boxld_t * obj, const boxld_t * other);

//Operations
//intersection()
bool boxu8_intersection(const boxu8_t * left, const boxu8_t * right, boxu8_t * result);
bool boxi8_intersection(const boxi8_t * left, const boxi8_t * right, boxi8_t * result);
bool boxu16_intersection(const boxu16_t * left, const boxu16_t * right, boxu16_t * result);
bool boxi16_intersection(const boxi16_t * left, const boxi16_t * right, boxi16_t * result);
bool boxu32_intersection(const boxu32_t * left, const boxu32_t * right, boxu32_t * result);
bool boxi32_intersection(const boxi32_t * left, const boxi32_t * right, boxi32_t * result);
bool boxu64_intersection(const boxu64_t * left, const boxu64_t * right, boxu64_t * result);
bool boxi64_intersection(const boxi64_t * left, const boxi64_t * right, boxi64_t * result);
bool boxf_intersection(const boxf_t * left,const  boxf_t * right, boxf_t * result);
bool boxd_intersection(const boxd_t * left, const boxd_t * right, boxd_t * result);
bool boxld_intersection(const boxld_t * left, const boxld_t * right, boxld_t * result);


//union()
void boxu8_union(const boxu8_t * left, const boxu8_t * right, boxu8_t * result);
void boxi8_union(const boxi8_t * left, const boxi8_t * right, boxi8_t * result);
void boxu16_union(const boxu16_t * left, const boxu16_t * right, boxu16_t * result);
void boxi16_union(const boxi16_t * left, const boxi16_t * right, boxi16_t * result);
void boxu32_union(const boxu32_t * left, const boxu32_t * right, boxu32_t * result);
void boxi32_union(const boxi32_t * left, const boxi32_t * right, boxi32_t * result);
void boxu64_union(const boxu64_t * left, const boxu64_t * right, boxu64_t * result);
void boxi64_union(const boxi64_t * left, const boxi64_t * right, boxi64_t * result);
void boxf_union(const boxf_t * left,const  boxf_t * right, boxf_t * result);
void boxd_union(const boxd_t * left, const boxd_t * right, boxd_t * result);
void boxld_union(const boxld_t * left, const boxld_t * right, boxld_t * result);


//clamp()
void boxu8_clamp(boxu8_t * obj, const boxu8_t * bounds);
void boxi8_clamp(boxi8_t * obj, const boxi8_t * bounds);
void boxu16_clamp(boxu16_t * obj, const boxu16_t * bounds);
void boxi16_clamp(boxi16_t * obj, const boxi16_t * bounds);
void boxu32_clamp(boxu32_t * obj, const boxu32_t * bounds);
void boxi32_clamp(boxi32_t * obj, const boxi32_t * bounds);
void boxu64_clamp(boxu64_t * obj, const boxu64_t * bounds);
void boxi64_clamp(boxi64_t * obj, const boxi64_t * bounds);
void boxf_clamp(boxf_t * obj, const boxf_t * bounds);
void boxd_clamp(boxd_t * obj, const boxd_t * bounds);
void boxld_clamp(boxld_t * obj, const boxld_t * bounds);



//Utilities
//equals()
bool boxu8_equals(const boxu8_t * obj, const boxu8_t * other);
bool boxi8_equals(const boxi8_t * obj, const boxi8_t * other);
bool boxu16_equals(const boxu16_t * obj, const boxu16_t * other);
bool boxi16_equals(const boxi16_t * obj, const boxi16_t * other);
bool boxu32_equals(const boxu32_t * obj, const boxu32_t * other);
bool boxi32_equals(const boxi32_t * obj, const boxi32_t * other);
bool boxu64_equals(const boxu64_t * obj, const boxu64_t * other);
bool boxi64_equals(const boxi64_t * obj, const boxi64_t * other);
bool boxf_equals(const boxf_t * obj, const boxf_t * other);
bool boxd_equals(const boxd_t * obj, const boxd_t * other);
bool boxld_equals(const boxld_t * obj, const boxld_t * other);

//print()
void boxu8_print(const boxu8_t * obj);
void boxi8_print(const boxi8_t * obj);
void boxu16_print(const boxu16_t * obj);
void boxi16_print(const boxi16_t * obj);
void boxu32_print(const boxu32_t * obj);
void boxi32_print(const boxi32_t * obj);
void boxu64_print(const boxu64_t * obj);
void boxi64_print(const boxi64_t * obj);
void boxf_print(const boxf_t * obj);
void boxd_print(const boxd_t * obj);
void boxld_print(const boxld_t * obj);



//Serialization
//toArray()
void boxu8_toArray(uint8_t * output , const boxu8_t * src);
void boxi8_toArray(int8_t * output , const boxi8_t * src);
void boxu16_toArray(uint16_t * output , const boxu16_t * src);
void boxi16_toArray(int16_t * output , const boxi16_t * src);
void boxu32_toArray(uint32_t * output , const boxu32_t * src);
void boxi32_toArray(int32_t * output , const boxi32_t * src);
void boxu64_toArray(uint64_t * output , const boxu64_t * src);
void boxi64_toArray(int64_t * output , const boxi64_t * src);
void boxf_toArray(float * output , const boxf_t * src);
void boxd_toArray(double * output , const boxd_t * src);
void boxld_toArray(long double * output , const boxld_t * src);

//fromArray()
void boxu8_fromArray(boxu8_t * output, const uint8_t * src);
void boxi8_fromArray(boxi8_t * output, const int8_t * src);
void boxu16_fromArray(boxu16_t * output, const uint16_t * src);
void boxi16_fromArray(boxi16_t * output, const int16_t * src);
void boxu32_fromArray(boxu32_t * output, const uint32_t * src);
void boxi32_fromArray(boxi32_t * output, const int32_t * src);
void boxu64_fromArray(boxu64_t * output, const uint64_t * src);
void boxi64_fromArray(boxi64_t * output, const int64_t * src);
void boxf_fromArray(boxf_t * output, const float * src);
void boxd_fromArray(boxd_t * output, const double * src);
void boxld_fromArray(boxld_t * output, const long double * src);

// toBytes()
void boxu8_toBytes(const boxu8_t* obj, uint8_t* dst);
void boxi8_toBytes(const boxi8_t* obj, uint8_t* dst);
void boxu16_toBytes(const boxu16_t* obj, uint8_t* dst);
void boxi16_toBytes(const boxi16_t* obj, uint8_t* dst);
void boxu32_toBytes(const boxu32_t* obj, uint8_t* dst);
void boxi32_toBytes(const boxi32_t* obj, uint8_t* dst);
void boxu64_toBytes(const boxu64_t* obj, uint8_t* dst);
void boxi64_toBytes(const boxi64_t* obj, uint8_t* dst);
void boxf_toBytes(const boxf_t* obj, uint8_t* dst);
void boxd_toBytes(const boxd_t* obj, uint8_t* dst);
void boxld_toBytes(const boxld_t* obj, uint8_t* dst);

// fromBytes()
void boxu8_fromBytes(boxu8_t* obj, const uint8_t* src);
void boxi8_fromBytes(boxi8_t* obj, const uint8_t* src);
void boxu16_fromBytes(boxu16_t* obj, const uint8_t* src);
void boxi16_fromBytes(boxi16_t* obj, const uint8_t* src);
void boxu32_fromBytes(boxu32_t* obj, const uint8_t* src);
void boxi32_fromBytes(boxi32_t* obj, const uint8_t* src);
void boxu64_fromBytes(boxu64_t* obj, const uint8_t* src);
void boxi64_fromBytes(boxi64_t* obj, const uint8_t* src);
void boxf_fromBytes(boxf_t* obj, const uint8_t* src);
void boxd_fromBytes(boxd_t* obj, const uint8_t* src);
void boxld_fromBytes(boxld_t* obj, const uint8_t* src);

// toBytesLE()
void boxu8_toBytesLE(const boxu8_t* obj, uint8_t* dst);
void boxi8_toBytesLE(const boxi8_t* obj, uint8_t* dst);
void boxu16_toBytesLE(const boxu16_t* obj, uint8_t* dst);
void boxi16_toBytesLE(const boxi16_t* obj, uint8_t* dst);
void boxu32_toBytesLE(const boxu32_t* obj, uint8_t* dst);
void boxi32_toBytesLE(const boxi32_t* obj, uint8_t* dst);
void boxu64_toBytesLE(const boxu64_t* obj, uint8_t* dst);
void boxi64_toBytesLE(const boxi64_t* obj, uint8_t* dst);
void boxf_toBytesLE(const boxf_t* obj, uint8_t* dst);
void boxd_toBytesLE(const boxd_t* obj, uint8_t* dst);
void boxld_toBytesLE(const boxld_t* obj, uint8_t* dst);

// fromBytesLE()
void boxu8_fromBytesLE(boxu8_t* obj, const uint8_t* src);
void boxi8_fromBytesLE(boxi8_t* obj, const uint8_t* src);
void boxu16_fromBytesLE(boxu16_t* obj, const uint8_t* src);
void boxi16_fromBytesLE(boxi16_t* obj, const uint8_t* src);
void boxu32_fromBytesLE(boxu32_t* obj, const uint8_t* src);
void boxi32_fromBytesLE(boxi32_t* obj, const uint8_t* src);
void boxu64_fromBytesLE(boxu64_t* obj, const uint8_t* src);
void boxi64_fromBytesLE(boxi64_t* obj, const uint8_t* src);
void boxf_fromBytesLE(boxf_t* obj, const uint8_t* src);
void boxd_fromBytesLE(boxd_t* obj, const uint8_t* src);
void boxld_fromBytesLE(boxld_t* obj, const uint8_t* src);



#endif
