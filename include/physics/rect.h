/**
 * @file rect.h
 * @brief Generic rectangle library for multiple numeric types (integer and floating-point).
 *
 * Supports allocation, transformations, geometry checks, collisions, and
 * serialization to/from arrays and byte buffers in both host and little-endian order.
 */

#ifndef FOUNDATIONS_PHYSICS_RECT_H
#define FOUNDATIONS_PHYSICS_RECT_H

#ifndef HAS_STDINT_H_
#include <stdint.h>
#define HAS_STDINT_H_
#endif

#ifndef HAS_STDBOOL_H_
#include <stdbool.h>
#define HAS_STDBOOL_H_
#endif

typedef struct _rectu8_t rectu8_t;
typedef struct _recti8_t recti8_t;

typedef struct _rectu16_t rectu16_t;
typedef struct _recti16_t recti16_t;

typedef struct _rectu32_t rectu32_t;
typedef struct _recti32_t recti32_t;

typedef struct _rectu64_t rectu64_t;
typedef struct _recti64_t recti64_t;

typedef struct _rectf_t rectf_t;
typedef struct _rectd_t rectd_t;
typedef struct _rectld_t rectld_t;

//error handling
const char* rect_get_error_string(void);
//Memory Allocation
//malloc from parameters
rectu8_t * rectu8_malloc(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
recti8_t * recti8_malloc(int8_t x, int8_t y, int8_t width, int8_t height);
rectu16_t * rectu16_malloc(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
recti16_t * recti16_malloc(int16_t x, int16_t y, int16_t width, int16_t height);
rectu32_t * rectu32_malloc(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
recti32_t * recti32_malloc(int32_t x, int32_t y, int32_t width, int32_t height);
rectu64_t * rectu64_malloc(uint64_t x, uint64_t y, uint64_t width, uint64_t height);
recti64_t * recti64_malloc(int64_t x, int64_t y, int64_t width, int64_t height);
rectf_t * rectf_malloc(float x , float y, float width, float height);
rectd_t * rectd_malloc(double x, double y, double width, double height);
rectld_t * rectld_malloc(long double x, long double y , long double width, long double height);

//malloc empty
rectu8_t * rectu8_mallocEmpty();
recti8_t * recti8_mallocEmpty();
rectu16_t * rectu16_mallocEmpty();
recti16_t * recti16_mallocEmpty();
rectu32_t * rectu32_mallocEmpty();
recti32_t * recti32_mallocEmpty();
rectu64_t * rectu64_mallocEmpty();
recti64_t * recti64_mallocEmpty();
rectf_t * rectf_mallocEmpty();
rectd_t * rectd_mallocEmpty();
rectld_t * rectld_mallocEmpty();

//malloc via copy from other
rectu8_t * rectu8_copy(const rectu8_t * copy);
recti8_t * recti8_copy(const recti8_t * copy);
rectu16_t * rectu16_copy(const rectu16_t * copy);
recti16_t * recti16_copy(const recti16_t * copy);
rectu32_t * rectu32_copy(const rectu32_t * copy);
recti32_t * recti32_copy(const recti32_t * copy);
rectu64_t * rectu64_copy(const rectu64_t * copy);
recti64_t * recti64_copy(const recti64_t * copy);
rectf_t * rectf_copy(const rectf_t * copy);
rectd_t * rectd_copy(const rectd_t * copy);
rectld_t * rectld_copy(const rectld_t * copy);
//Move via other
rectu8_t * rectu8_memmove(rectu8_t ** move);
recti8_t * recti8_memmove(recti8_t ** move);
rectu16_t * rectu16_memmove(rectu16_t ** move);
recti16_t * recti16_memmove(recti16_t ** move);
rectu32_t * rectu32_memmove(rectu32_t ** move);
recti32_t * recti32_memmove(recti32_t ** move);
rectu64_t * rectu64_memmove(rectu64_t ** move);
recti64_t * recti64_memmove(recti64_t ** move);
rectf_t * rectf_memmove(rectf_t ** move);
rectd_t * rectd_memmove(rectd_t ** move);
rectld_t * rectld_memmove(rectld_t ** move);

//free
void rectu8_free(rectu8_t * obj);
void recti8_free(recti8_t * obj);
void rectu16_free(rectu16_t * obj);
void recti16_free(recti16_t * obj);
void rectu32_free(rectu32_t * obj);
void recti32_free(recti32_t * obj);
void rectu64_free(rectu64_t * obj);
void recti64_free(recti64_t * obj);
void rectf_free(rectf_t * obj);
void rectd_free(rectd_t * obj);
void rectld_free(rectld_t * obj);

//Accessors
//getX()
uint8_t rectu8_getX(const rectu8_t * obj);
int8_t recti8_getX(const recti8_t * obj);
uint16_t rectu16_getX(const rectu16_t * obj);
int16_t recti16_getX(const recti16_t * obj);
uint32_t rectu32_getX(const rectu32_t * obj);
int32_t recti32_getX(const recti32_t * obj);
uint64_t rectu64_getX(const rectu64_t * obj);
int64_t recti64_getX(const recti64_t * obj);
float rectf_getX(const rectf_t * obj);
double rectd_getX(const rectd_t * obj);
long double rectld_getX(const rectld_t * obj);

//getY()
uint8_t rectu8_getY(const rectu8_t * obj);
int8_t recti8_getY(const recti8_t * obj);
uint16_t rectu16_getY(const rectu16_t * obj);
int16_t recti16_getY(const recti16_t * obj);
uint32_t rectu32_getY(const rectu32_t * obj);
int32_t recti32_getY(const recti32_t * obj);
uint64_t rectu64_getY(const rectu64_t * obj);
int64_t recti64_getY(const recti64_t * obj);
float rectf_getY(const rectf_t * obj);
double rectd_getY(const rectd_t * obj);
long double rectld_getY(const rectld_t * obj);

//getWidth()
uint8_t rectu8_getWidth(const rectu8_t * obj);
int8_t recti8_getWidth(const recti8_t * obj);
uint16_t rectu16_getWidth(const rectu16_t * obj);
int16_t recti16_getWidth(const recti16_t * obj);
uint32_t rectu32_getWidth(const rectu32_t * obj);
int32_t recti32_getWidth(const recti32_t * obj);
uint64_t rectu64_getWidth(const rectu64_t * obj);
int64_t recti64_getWidth(const recti64_t * obj);
float rectf_getWidth(const rectf_t * obj);
double rectd_getWidth(const rectd_t * obj);
long double rectld_getWidth(const rectld_t * obj);


//getHeight()
uint8_t rectu8_getHeight(const rectu8_t * obj);
int8_t recti8_getHeight(const recti8_t * obj);
uint16_t rectu16_getHeight(const rectu16_t * obj);
int16_t recti16_getHeight(const recti16_t * obj);
uint32_t rectu32_getHeight(const rectu32_t * obj);
int32_t recti32_getHeight(const recti32_t * obj);
uint64_t rectu64_getHeight(const rectu64_t * obj);
int64_t recti64_getHeight(const recti64_t * obj);
float rectf_getHeight(const rectf_t * obj);
double rectd_getHeight(const rectd_t * obj);
long double rectld_getHeight(const rectld_t * obj);


//setters
//setPosX()
void rectu8_setPosX(rectu8_t * obj, uint8_t posX);
void recti8_setPosX(recti8_t * obj, int8_t posX);
void rectu16_setPosX(rectu16_t * obj, uint16_t posX);
void recti16_setPosX(recti16_t * obj, int16_t posX);
void rectu32_setPosX(rectu32_t * obj, uint32_t posX);
void recti32_setPosX(recti32_t * obj, int32_t posX);
void rectu64_setPosX(rectu64_t * obj, uint64_t posX);
void recti64_setPosX(recti64_t * obj, int64_t posX);
void rectf_setPosX(rectf_t * obj, float posX);
void rectd_setPosX(rectd_t * obj, double posX);
void rectld_setPosX(rectld_t * obj, long double posX);

//setPosY()
void rectu8_setPosY(rectu8_t * obj, uint8_t posY);
void recti8_setPosY(recti8_t * obj, int8_t posY);
void rectu16_setPosY(rectu16_t * obj, uint16_t posY);
void recti16_setPosY(recti16_t * obj, int16_t posY);
void rectu32_setPosY(rectu32_t * obj, uint32_t posY);
void recti32_setPosY(recti32_t * obj, int32_t posY);
void rectu64_setPosY(rectu64_t * obj, uint64_t posY);
void recti64_setPosY(recti64_t * obj, int64_t posY);
void rectf_setPosY(rectf_t * obj, float posY);
void rectd_setPosY(rectd_t * obj, double posY);
void rectld_setPosY(rectld_t * obj, long double posY);

//setPos()
void rectu8_setPos(rectu8_t * obj, uint8_t posX, uint8_t posY);
void recti8_setPos(recti8_t * obj, int8_t posX, int8_t posY);
void rectu16_setPos(rectu16_t * obj, uint16_t posX, uint16_t posY);
void recti16_setPos(recti16_t * obj, int16_t posX, int16_t posY);
void rectu32_setPos(rectu32_t * obj, uint32_t posX, uint32_t posY);
void recti32_setPos(recti32_t * obj, int32_t posX, int32_t posY);
void rectu64_setPos(rectu64_t * obj, uint64_t posX, uint64_t posY);
void recti64_setPos(recti64_t * obj, int64_t posX, int64_t posY);
void rectf_setPos(rectf_t * obj, float posX, float posY);
void rectd_setPos(rectd_t * obj, double posX, double posY);
void rectld_setPos(rectld_t * obj, long double posX, long double posY);



//setWidth()
void rectu8_setWidth(rectu8_t * obj, uint8_t width);
void recti8_setWidth(recti8_t * obj, int8_t width);
void rectu16_setWidth(rectu16_t * obj, uint16_t width);
void recti16_setWidth(recti16_t * obj, int16_t width);
void rectu32_setWidth(rectu32_t * obj, uint32_t width);
void recti32_setWidth(recti32_t * obj, int32_t width);
void rectu64_setWidth(rectu64_t * obj, uint64_t width);
void recti64_setWidth(recti64_t * obj, int64_t width);
void rectf_setWidth(rectf_t * obj, float width);
void rectd_setWidth(rectd_t * obj, double width);
void rectld_setWidth(rectld_t * obj, long double width);

//setHeight()
void rectu8_setHeight(rectu8_t * obj, uint8_t height);
void recti8_setHeight(recti8_t * obj, int8_t height);
void rectu16_setHeight(rectu16_t * obj, uint16_t height);
void recti16_setHeight(recti16_t * obj, int16_t height);
void rectu32_setHeight(rectu32_t * obj, uint32_t height);
void recti32_setHeight(recti32_t * obj, int32_t height);
void rectu64_setHeight(rectu64_t * obj, uint64_t height);
void recti64_setHeight(recti64_t * obj, int64_t height);
void rectf_setHeight(rectf_t * obj, float height);
void rectd_setHeight(rectd_t * obj, double height);
void rectld_setHeight(rectld_t * obj, long double height);

//setSize()
void rectu8_setSize(rectu8_t * obj, uint8_t width, uint8_t height);
void recti8_setSize(recti8_t * obj, int8_t width, int8_t height);
void rectu16_setSize(rectu16_t * obj, uint16_t width, uint16_t height);
void recti16_setSize(recti16_t * obj, int16_t width, int16_t height);
void rectu32_setSize(rectu32_t * obj, uint32_t width, uint32_t height);
void recti32_setSize(recti32_t * obj, int32_t width, int32_t height);
void rectu64_setSize(rectu64_t * obj, uint64_t width, uint64_t height);
void recti64_setSize(recti64_t * obj, int64_t width, int64_t height);
void rectf_setSize(rectf_t * obj, float width, float height);
void rectd_setSize(rectd_t * obj, double width, double height);
void rectld_setSize(rectld_t * obj, long double width, long double height);


//moveX()
void rectu8_moveX(rectu8_t * obj, uint8_t dx);
void recti8_moveX(recti8_t * obj, int8_t dx);
void rectu16_moveX(rectu16_t * obj, uint16_t dx);
void recti16_moveX(recti16_t * obj, int16_t dx);
void rectu32_moveX(rectu32_t * obj, uint32_t dx);
void recti32_moveX(recti32_t * obj, int32_t dx);
void rectu64_moveX(rectu64_t * obj, uint64_t dx);
void recti64_moveX(recti64_t * obj, int64_t dx);
void rectf_moveX(rectf_t * obj, float dx);
void rectd_moveX(rectd_t * obj, double dx);
void rectld_moveX(rectld_t * obj, long double dx);

//moveY()
void rectu8_moveY(rectu8_t * obj, uint8_t dy);
void recti8_moveY(recti8_t * obj, int8_t dy);
void rectu16_moveY(rectu16_t * obj, uint16_t dy);
void recti16_moveY(recti16_t * obj, int16_t dy);
void rectu32_moveY(rectu32_t * obj, uint32_t dy);
void recti32_moveY(recti32_t * obj, int32_t dy);
void rectu64_moveY(rectu64_t * obj, uint64_t dy);
void recti64_moveY(recti64_t * obj, int64_t dy);
void rectf_moveY(rectf_t * obj, float dy);
void rectd_moveY(rectd_t * obj, double dy);
void rectld_moveY(rectld_t * obj, long double dy);

//move()
void rectu8_move(rectu8_t * obj, uint8_t dx, uint8_t dy);
void recti8_move(recti8_t * obj, int8_t dx, int8_t dy);
void rectu16_move(rectu16_t * obj, uint16_t dx, uint16_t dy);
void recti16_move(recti16_t * obj, int16_t dx, int16_t dy);
void rectu32_move(rectu32_t * obj, uint32_t dx, uint32_t dy);
void recti32_move(recti32_t * obj, int32_t dx, int32_t dy);
void rectu64_move(rectu64_t * obj, uint64_t dx, uint64_t dy);
void recti64_move(recti64_t * obj, int64_t dx, int64_t dy);
void rectf_move(rectf_t * obj, float dx, float dy);
void rectd_move(rectd_t * obj, double dx, double dy);
void rectld_move(rectld_t * obj, long double dx, long double dy);


//resizeWidth()
void rectu8_resizeWidth(rectu8_t * obj, uint8_t dw);
void recti8_resizeWidth(recti8_t * obj, int8_t dw);
void rectu16_resizeWidth(rectu16_t * obj, uint16_t dw);
void recti16_resizeWidth(recti16_t * obj, int16_t dw);
void rectu32_resizeWidth(rectu32_t * obj, uint32_t dw);
void recti32_resizeWidth(recti32_t * obj, int32_t dw);
void rectu64_resizeWidth(rectu64_t * obj, uint64_t dw);
void recti64_resizeWidth(recti64_t * obj, int64_t dw);
void rectf_resizeWidth(rectf_t * obj, float dw);
void rectd_resizeWidth(rectd_t * obj, double dw);
void rectld_resizeWidth(rectld_t * obj, long double dw);


//resizeHeight()
void rectu8_resizeHeight(rectu8_t * obj, uint8_t dh);
void recti8_resizeHeight(recti8_t * obj, int8_t dh);
void rectu16_resizeHeight(rectu16_t * obj, uint16_t dh);
void recti16_resizeHeight(recti16_t * obj, int16_t dh);
void rectu32_resizeHeight(rectu32_t * obj, uint32_t dh);
void recti32_resizeHeight(recti32_t * obj, int32_t dh);
void rectu64_resizeHeight(rectu64_t * obj, uint64_t dh);
void recti64_resizeHeight(recti64_t * obj, int64_t dh);
void rectf_resizeHeight(rectf_t * obj, float dh);
void rectd_resizeHeight(rectd_t * obj, double dh);
void rectld_resizeHeight(rectld_t * obj, long double dh);

//resize()
void rectu8_resize(rectu8_t * obj, uint8_t dw, uint8_t dh);
void recti8_resize(recti8_t * obj, int8_t dw, int8_t dh);
void rectu16_resize(rectu16_t * obj, uint16_t dw, uint16_t dh);
void recti16_resize(recti16_t * obj, int16_t dw, int16_t dh);
void rectu32_resize(rectu32_t * obj, uint32_t dw, uint32_t dh);
void recti32_resize(recti32_t * obj, int32_t dw, int32_t dh);
void rectu64_resize(rectu64_t * obj, uint64_t dw, uint64_t dh);
void recti64_resize(recti64_t * obj, int64_t dw, int64_t dh);
void rectf_resize(rectf_t * obj, float dw, float dh);
void rectd_resize(rectd_t * obj, double dw, double dh);
void rectld_resize(rectld_t * obj, long double dw, long double dh);

//Geometry
//getSideX()
uint8_t rectu8_getSideX(const rectu8_t * obj);
int8_t recti8_getSideX(const recti8_t * obj);
uint16_t rectu16_getSideX(const rectu16_t * obj);
int16_t recti16_getSideX(const recti16_t * obj);
uint32_t rectu32_getSideX(const rectu32_t * obj);
int32_t recti32_getSideX(const recti32_t * obj);
uint64_t rectu64_getSideX(const rectu64_t * obj);
int64_t recti64_getSideX(const recti64_t * obj);
float rectf_getSideX(const rectf_t * obj);
double rectd_getSideX(const rectd_t * obj);
long double rectld_getSideX(const rectld_t * obj);

//getSideY()
uint8_t rectu8_getSideY(const rectu8_t * obj);
int8_t recti8_getSideY(const recti8_t * obj);
uint16_t rectu16_getSideY(const rectu16_t * obj);
int16_t recti16_getSideY(const recti16_t * obj);
uint32_t rectu32_getSideY(const rectu32_t * obj);
int32_t recti32_getSideY(const recti32_t * obj);
uint64_t rectu64_getSideY(const rectu64_t * obj);
int64_t recti64_getSideY(const recti64_t * obj);
float rectf_getSideY(const rectf_t * obj);
double rectd_getSideY(const rectd_t * obj);
long double rectld_getSideY(const rectld_t * obj);

//area()
uint8_t rectu8_area(const rectu8_t * obj);
int8_t recti8_area(const recti8_t * obj);
uint16_t rectu16_area(const rectu16_t * obj);
int16_t recti16_area(const recti16_t * obj);
uint32_t rectu32_area(const rectu32_t * obj);
int32_t recti32_area(const recti32_t * obj);
uint64_t rectu64_area(const rectu64_t * obj);
int64_t recti64_area(const recti64_t * obj);
float rectf_area(const rectf_t * obj);
double rectd_area(const rectd_t * obj);
long double rectld_area(const rectld_t * obj);

#ifdef VEC2_DEFINED

//vec2 getPosVec2()
//YOU MUST FREE THIS MEMORY
vec2uint8_t * rectu8_getPosVec2(rectu8_t * obj);
vec2int8_t * recti8_getPosVec2(recti8_t * obj);
vec2uint16_t * rectu16_getPosVec2(rectu16_t * obj);
vec2int16_t * recti16_getPosVec2(recti16_t * obj);
vec2uint32_t * rectu32_getPosVec2(rectu32_t * obj);
vec2int32_t * recti32_getPosVec2(recti32_t * obj);
vec2uint64_t * rectu64_getPosVec2(rectu64_t * obj);
vec2int64_t * recti64_getPosVec2(recti64_t * obj);
vec2f_t * rectf_getPosVec2(rectf_t * obj);
vec2d_t * rectd_getPosVec2(rectd_t * obj);
vec2ld_t * rectld_getPosVec2(rectld_t * obj);


//vec2 getSize()
//YOU MUST FREE THIS MEMORY
vec2uint8_t * rectu8_getSizeVec2(rectu8_t * obj);
vec2int8_t * recti8_getSizeVec2(recti8_t * obj);
vec2uint16_t * rectu16_getSizeVec2(rectu16_t * obj);
vec2int16_t * recti16_getSizeVec2(recti16_t * obj);
vec2uint32_t * rectu32_getSizeVec2(rectu32_t * obj);
vec2int32_t * recti32_getSizeVec2(recti32_t * obj);
vec2uint64_t * rectu64_getSizeVec2(rectu64_t * obj);
vec2int64_t * recti64_getSizeVec2(recti64_t * obj);
vec2f_t * rectf_getSizeVec2(rectf_t * obj);
vec2d_t * rectd_getSizeVec2(rectd_t * obj);
vec2ld_t * rectld_getSizeVec2(rectld_t * obj);



//setSizeVec2()
void rectu8_setSizeVec2(rectu8_t * obj, const vec2uint8_t * size);
void recti8_setSizeVec2(recti8_t * obj, const vec2int8_t * size);
void rectu16_setSizeVec2(rectu16_t * obj, const vec2uint16_t * size);
void recti16_setSizeVec2(recti16_t * obj, const vec2int16_t * size);
void rectu32_setSizeVec2(rectu32_t * obj, const vec2uint32_t * size);
void recti32_setSizeVec2(recti32_t * obj, const vec2int32_t * size);
void rectu64_setSizeVec2(rectu64_t * obj, const vec2uint64_t * size);
void recti64_setSizeVec2(recti64_t * obj, const vec2int64_t * size);
void rectf_setSizeVec2(rectf_t * obj, const vec2f_t * size);
void rectd_setSizeVec2(rectd_t * obj, const vec2d_t * size);
void rectld_setSizeVec2(rectld_t * obj, const vec2ld_t * size);

//setPosVec2()
void rectu8_setPosVec2(rectu8_t * obj, const vec2uint8_t * pos);
void recti8_setPosVec2(recti8_t * obj, const vec2int8_t * pos);
void rectu16_setPosVec2(rectu16_t * obj, const vec2uint16_t * pos);
void recti16_setPosVec2(recti16_t * obj, const vec2int16_t * pos);
void rectu32_setPosVec2(rectu32_t * obj, const vec2uint32_t * pos);
void recti32_setPosVec2(recti32_t * obj, const vec2int32_t * pos);
void rectu64_setPosVec2(rectu64_t * obj, const vec2uint64_t * pos);
void recti64_setPosVec2(recti64_t * obj, const vec2int64_t * pos);
void rectf_setPosVec2(rectf_t * obj, const vec2f_t * pos);
void rectd_setPosVec2(rectd_t * obj, const vec2d_t * pos);
void rectld_setPosVec2(rectld_t * obj, const vec2ld_t * pos);

// moveVec2()
void rectu8_moveVec2(rectu8_t * obj, const vec2int8_t * delta);
void recti8_moveVec2(recti8_t * obj, const vec2int8_t * delta);
void rectu16_moveVec2(rectu16_t * obj, const vec2int16_t * delta);
void recti16_moveVec2(recti16_t * obj, const vec2int16_t * delta);
void rectu32_moveVec2(rectu32_t * obj, const vec2int32_t * delta);
void recti32_moveVec2(recti32_t * obj, const vec2int32_t * delta);
void rectu64_moveVec2(rectu64_t * obj, const vec2int64_t * delta);
void recti64_moveVec2(recti64_t * obj, const vec2int64_t * delta);
void rectf_moveVec2(rectf_t * obj, const vec2f_t * delta);
void rectd_moveVec2(rectd_t * obj, const vec2d_t * delta);
void rectld_moveVec2(rectld_t * obj, const vec2ld_t * delta);

// resizeVec2()
void rectu8_resizeVec2(rectu8_t * obj, const vec2uint8_t * delta);
void recti8_resizeVec2(recti8_t * obj, const vec2int8_t * delta);
void rectu16_resizeVec2(rectu16_t * obj, const vec2uint16_t * delta);
void recti16_resizeVec2(recti16_t * obj, const vec2int16_t * delta);
void rectu32_resizeVec2(rectu32_t * obj, const vec2uint32_t * delta);
void recti32_resizeVec2(recti32_t * obj, const vec2int32_t * delta);
void rectu64_resizeVec2(rectu64_t * obj, const vec2uint64_t * delta);
void recti64_resizeVec2(recti64_t * obj, const vec2int64_t * delta);
void rectf_resizeVec2(rectf_t * obj, const vec2f_t * delta);
void rectd_resizeVec2(rectd_t * obj, const vec2d_t * delta);
void rectld_resizeVec2(rectld_t * obj, const vec2ld_t * delta);


#endif

//Relationships
//collides()
bool rectu8_collides(const rectu8_t * obj, const rectu8_t * other);
bool recti8_collides(const recti8_t * obj, const recti8_t * other);
bool rectu16_collides(const rectu16_t * obj, const rectu16_t * other);
bool recti16_collides(const recti16_t * obj, const recti16_t * other);
bool rectu32_collides(const rectu32_t * obj, const rectu32_t * other);
bool recti32_collides(const recti32_t * obj, const recti32_t * other);
bool rectu64_collides(const rectu64_t * obj, const rectu64_t * other);
bool recti64_collides(const recti64_t * obj, const recti64_t * other);
bool rectf_collides(const rectf_t * obj, const rectf_t * other);
bool rectd_collides(const rectd_t * obj, const rectd_t * other);
bool rectld_collides(const rectld_t * obj, const rectld_t * other);

//contains_point()
bool rectu8_contains_point(const rectu8_t * obj, uint8_t width, uint8_t height);
bool recti8_contains_point(const recti8_t * obj, int8_t width, int8_t height);
bool rectu16_contains_point(const rectu16_t * obj, uint16_t width, uint16_t height);
bool recti16_contains_point(const recti16_t * obj, int16_t width, int16_t height);
bool rectu32_contains_point(const rectu32_t * obj, uint32_t width, uint32_t height);
bool recti32_contains_point(const recti32_t * obj, int32_t width, int32_t height);
bool rectu64_contains_point(const rectu64_t * obj, uint64_t width, uint64_t height);
bool recti64_contains_point(const recti64_t * obj, int64_t width, int64_t height);
bool rectf_contains_point(const rectf_t * obj, float width, float height);
bool rectd_contains_point(const rectd_t * obj, double width, double height);
bool rectld_contains_point(const rectld_t * obj, long double width, long double height);

//contains_rect()
bool rectu8_contains_rect(const rectu8_t * obj, const rectu8_t * other);
bool recti8_contains_rect(const recti8_t * obj, const recti8_t * other);
bool rectu16_contains_rect(const rectu16_t * obj, const rectu16_t * other);
bool recti16_contains_rect(const recti16_t * obj, const recti16_t * other);
bool rectu32_contains_rect(const rectu32_t * obj, const rectu32_t * other);
bool recti32_contains_rect(const recti32_t * obj, const recti32_t * other);
bool rectu64_contains_rect(const rectu64_t * obj, const rectu64_t * other);
bool recti64_contains_rect(const recti64_t * obj, const recti64_t * other);
bool rectf_contains_rect(const rectf_t * obj, const rectf_t * other);
bool rectd_contains_rect(const rectd_t * obj, const rectd_t * other);
bool rectld_contains_rect(const rectld_t * obj, const rectld_t * other);

//Operations
//intersection()
bool rectu8_intersection(const rectu8_t * left, const rectu8_t * right, rectu8_t * result);
bool recti8_intersection(const recti8_t * left, const recti8_t * right, recti8_t * result);
bool rectu16_intersection(const rectu16_t * left, const rectu16_t * right, rectu16_t * result);
bool recti16_intersection(const recti16_t * left, const recti16_t * right, recti16_t * result);
bool rectu32_intersection(const rectu32_t * left, const rectu32_t * right, rectu32_t * result);
bool recti32_intersection(const recti32_t * left, const recti32_t * right, recti32_t * result);
bool rectu64_intersection(const rectu64_t * left, const rectu64_t * right, rectu64_t * result);
bool recti64_intersection(const recti64_t * left, const recti64_t * right, recti64_t * result);
bool rectf_intersection(const rectf_t * left,const  rectf_t * right, rectf_t * result);
bool rectd_intersection(const rectd_t * left, const rectd_t * right, rectd_t * result);
bool rectld_intersection(const rectld_t * left, const rectld_t * right, rectld_t * result);


//union()
void rectu8_union(const rectu8_t * left, const rectu8_t * right, rectu8_t * result);
void recti8_union(const recti8_t * left, const recti8_t * right, recti8_t * result);
void rectu16_union(const rectu16_t * left, const rectu16_t * right, rectu16_t * result);
void recti16_union(const recti16_t * left, const recti16_t * right, recti16_t * result);
void rectu32_union(const rectu32_t * left, const rectu32_t * right, rectu32_t * result);
void recti32_union(const recti32_t * left, const recti32_t * right, recti32_t * result);
void rectu64_union(const rectu64_t * left, const rectu64_t * right, rectu64_t * result);
void recti64_union(const recti64_t * left, const recti64_t * right, recti64_t * result);
void rectf_union(const rectf_t * left,const  rectf_t * right, rectf_t * result);
void rectd_union(const rectd_t * left, const rectd_t * right, rectd_t * result);
void rectld_union(const rectld_t * left, const rectld_t * right, rectld_t * result);


//clamp()
void rectu8_clamp(rectu8_t * obj, const rectu8_t * bounds);
void recti8_clamp(recti8_t * obj, const recti8_t * bounds);
void rectu16_clamp(rectu16_t * obj, const rectu16_t * bounds);
void recti16_clamp(recti16_t * obj, const recti16_t * bounds);
void rectu32_clamp(rectu32_t * obj, const rectu32_t * bounds);
void recti32_clamp(recti32_t * obj, const recti32_t * bounds);
void rectu64_clamp(rectu64_t * obj, const rectu64_t * bounds);
void recti64_clamp(recti64_t * obj, const recti64_t * bounds);
void rectf_clamp(rectf_t * obj, const rectf_t * bounds);
void rectd_clamp(rectd_t * obj, const rectd_t * bounds);
void rectld_clamp(rectld_t * obj, const rectld_t * bounds);



//Utilities
//equals()
bool rectu8_equals(const rectu8_t * obj, const rectu8_t * other);
bool recti8_equals(const recti8_t * obj, const recti8_t * other);
bool rectu16_equals(const rectu16_t * obj, const rectu16_t * other);
bool recti16_equals(const recti16_t * obj, const recti16_t * other);
bool rectu32_equals(const rectu32_t * obj, const rectu32_t * other);
bool recti32_equals(const recti32_t * obj, const recti32_t * other);
bool rectu64_equals(const rectu64_t * obj, const rectu64_t * other);
bool recti64_equals(const recti64_t * obj, const recti64_t * other);
bool rectf_equals(const rectf_t * obj, const rectf_t * other);
bool rectd_equals(const rectd_t * obj, const rectd_t * other);
bool rectld_equals(const rectld_t * obj, const rectld_t * other);

//print()
void rectu8_print(const rectu8_t * obj);
void recti8_print(const recti8_t * obj);
void rectu16_print(const rectu16_t * obj);
void recti16_print(const recti16_t * obj);
void rectu32_print(const rectu32_t * obj);
void recti32_print(const recti32_t * obj);
void rectu64_print(const rectu64_t * obj);
void recti64_print(const recti64_t * obj);
void rectf_print(const rectf_t * obj);
void rectd_print(const rectd_t * obj);
void rectld_print(const rectld_t * obj);



//Serialization
//toArray()
void rectu8_toArray(uint8_t * output , const rectu8_t * src);
void recti8_toArray(int8_t * output , const recti8_t * src);
void rectu16_toArray(uint16_t * output , const rectu16_t * src);
void recti16_toArray(int16_t * output , const recti16_t * src);
void rectu32_toArray(uint32_t * output , const rectu32_t * src);
void recti32_toArray(int32_t * output , const recti32_t * src);
void rectu64_toArray(uint64_t * output , const rectu64_t * src);
void recti64_toArray(int64_t * output , const recti64_t * src);
void rectf_toArray(float * output , const rectf_t * src);
void rectd_toArray(double * output , const rectd_t * src);
void rectld_toArray(long double * output , const rectld_t * src);

//fromArray()
void rectu8_fromArray(rectu8_t * output, const uint8_t * src);
void recti8_fromArray(recti8_t * output, const int8_t * src);
void rectu16_fromArray(rectu16_t * output, const uint16_t * src);
void recti16_fromArray(recti16_t * output, const int16_t * src);
void rectu32_fromArray(rectu32_t * output, const uint32_t * src);
void recti32_fromArray(recti32_t * output, const int32_t * src);
void rectu64_fromArray(rectu64_t * output, const uint64_t * src);
void recti64_fromArray(recti64_t * output, const int64_t * src);
void rectf_fromArray(rectf_t * output, const float * src);
void rectd_fromArray(rectd_t * output, const double * src);
void rectld_fromArray(rectld_t * output, const long double * src);

// toBytes()
void rectu8_toBytes(const rectu8_t* obj, uint8_t* dst);
void recti8_toBytes(const recti8_t* obj, uint8_t* dst);
void rectu16_toBytes(const rectu16_t* obj, uint8_t* dst);
void recti16_toBytes(const recti16_t* obj, uint8_t* dst);
void rectu32_toBytes(const rectu32_t* obj, uint8_t* dst);
void recti32_toBytes(const recti32_t* obj, uint8_t* dst);
void rectu64_toBytes(const rectu64_t* obj, uint8_t* dst);
void recti64_toBytes(const recti64_t* obj, uint8_t* dst);
void rectf_toBytes(const rectf_t* obj, uint8_t* dst);
void rectd_toBytes(const rectd_t* obj, uint8_t* dst);
void rectld_toBytes(const rectld_t* obj, uint8_t* dst);

// fromBytes()
void rectu8_fromBytes(rectu8_t* obj, const uint8_t* src);
void recti8_fromBytes(recti8_t* obj, const uint8_t* src);
void rectu16_fromBytes(rectu16_t* obj, const uint8_t* src);
void recti16_fromBytes(recti16_t* obj, const uint8_t* src);
void rectu32_fromBytes(rectu32_t* obj, const uint8_t* src);
void recti32_fromBytes(recti32_t* obj, const uint8_t* src);
void rectu64_fromBytes(rectu64_t* obj, const uint8_t* src);
void recti64_fromBytes(recti64_t* obj, const uint8_t* src);
void rectf_fromBytes(rectf_t* obj, const uint8_t* src);
void rectd_fromBytes(rectd_t* obj, const uint8_t* src);
void rectld_fromBytes(rectld_t* obj, const uint8_t* src);

// toBytesLE()
void rectu8_toBytesLE(const rectu8_t* obj, uint8_t* dst);
void recti8_toBytesLE(const recti8_t* obj, uint8_t* dst);
void rectu16_toBytesLE(const rectu16_t* obj, uint8_t* dst);
void recti16_toBytesLE(const recti16_t* obj, uint8_t* dst);
void rectu32_toBytesLE(const rectu32_t* obj, uint8_t* dst);
void recti32_toBytesLE(const recti32_t* obj, uint8_t* dst);
void rectu64_toBytesLE(const rectu64_t* obj, uint8_t* dst);
void recti64_toBytesLE(const recti64_t* obj, uint8_t* dst);
void rectf_toBytesLE(const rectf_t* obj, uint8_t* dst);
void rectd_toBytesLE(const rectd_t* obj, uint8_t* dst);
void rectld_toBytesLE(const rectld_t* obj, uint8_t* dst);

// fromBytesLE()
void rectu8_fromBytesLE(rectu8_t* obj, const uint8_t* src);
void recti8_fromBytesLE(recti8_t* obj, const uint8_t* src);
void rectu16_fromBytesLE(rectu16_t* obj, const uint8_t* src);
void recti16_fromBytesLE(recti16_t* obj, const uint8_t* src);
void rectu32_fromBytesLE(rectu32_t* obj, const uint8_t* src);
void recti32_fromBytesLE(recti32_t* obj, const uint8_t* src);
void rectu64_fromBytesLE(rectu64_t* obj, const uint8_t* src);
void recti64_fromBytesLE(recti64_t* obj, const uint8_t* src);
void rectf_fromBytesLE(rectf_t* obj, const uint8_t* src);
void rectd_fromBytesLE(rectd_t* obj, const uint8_t* src);
void rectld_fromBytesLE(rectld_t* obj, const uint8_t* src);

#define HAS_RECT 1
#endif // RECT_H
