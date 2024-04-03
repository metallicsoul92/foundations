#ifndef FOUNDATIONS_PHYSICS_LINE_H_
#define FOUNDATIONS_PHYSICS_LINE_H_

// LINE TYPE : LINE . Has 2 end points
#define LINE_TYPE_LINE 1

// LINE TYPE : VECTOR . Has 1 end point, and a directional vector
#define LINE_TYPE_VECTOR 2

// Standard header for size_t
#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

// Standard header for fixed-size integer types
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

//Standard header for booleans
#ifndef STDBOOL_DEFINED
#include <stdbool.h>
#define STDBOOL_DEFINED 1
#endif

/*
* 2D definitions
*/

typedef struct line2Du8 line2Du8_t;
typedef struct line2Di8 line2Di8_t;
typedef struct line2Du16 line2Du16_t;
typedef struct line2Di16 line2Di16_t;
typedef struct line2Du32 line2Du32_t;
typedef struct line2Di32 line2Di32_t;
typedef struct line2Du64 line2Du64_t;
typedef struct line2Di64 line2Di64_t;
typedef struct line2Df line2Df_t;
typedef struct line2Dd line2Dd_t;

/*
* 3D definitions
*/

typedef struct line3Du8 line3Du8_t;
typedef struct line3Di8 line3Di8_t;
typedef struct line3Du16 line3Du16_t;
typedef struct line3Di16 line3Di16_t;
typedef struct line3Du32 line3Du32_t;
typedef struct line3Di32 line3Di32_t;
typedef struct line3Du64 line3Du64_t;
typedef struct line3Di64 line3Di64_t;
typedef struct line3Df line3Df_t;
typedef struct line3Dd line3Dd_t;

/*
* 4D definitions
*/

typedef struct line4Du8 line4Du8_t;
typedef struct line4Di8 line4Di8_t;
typedef struct line4Du16 line4Du16_t;
typedef struct line4Di16 line4Di16_t;
typedef struct line4Du32 line4Du32_t;
typedef struct line4Di32 line4Di32_t;
typedef struct line4Du64 line4Du64_t;
typedef struct line4Di64 line4Di64_t;
typedef struct line4Df line4Df_t;
typedef struct line4Dd line4Dd_t;

/**
* Malloc functions
**/

line2Du8_t * line2Du8_malloc(uint8_t type, uint8_t bx, uint8_t by, uint8_t ex, uint8_t ey);
line2Di8_t * line2Di8_malloc(uint8_t type, int8_t bx, int8_t by, int8_t ex, int8_t ey);
line2Du16_t * line2Du16_malloc(uint8_t type, uint16_t bx, uint16_t by, uint16_t ex, uint16_t ey);
line2Di16_t * line2Di16_malloc(uint8_t type, int16_t bx, int16_t by, int16_t ex, int16_t ey);
line2Du32_t * line2Du32_malloc(uint8_t type, uint32_t bx, uint32_t by, uint32_t ex, uint32_t ey);
line2Di32_t * line2Di32_malloc(uint8_t type, int32_t bx, int32_t by, int32_t ex, int32_t ey);
line2Du64_t * line2Du64_malloc(uint8_t type, uint64_t bx, uint64_t by, uint64_t ex, uint64_t ey);
line2Di64_t * line2Di64_malloc(uint8_t type, int64_t bx, int64_t by, int64_t ex, int64_t ey);
line2Df_t * line2Df_malloc(uint8_t type, float bx, float by, float ex, float ey);
line2Dd_t * line2Dd_malloc(uint8_t type, double bx, double by, double ex, double ey);

line3Du8_t * line3Du8_malloc(uint8_t type, uint8_t bx, uint8_t by, uint8_t bz ,uint8_t ex, uint8_t ey, uint8_t ez);
line3Di8_t * line3Di8_malloc(uint8_t type, int8_t bx, int8_t by, int8_t bz ,int8_t ex, int8_t ey, int8_t ez);
line3Du16_t * line3Du16_malloc(uint8_t type,  uint16_t bx, uint16_t by, uint16_t bz ,uint16_t ex, uint16_t ey, uint16_t ez);
line3Di16_t * line3Di16_malloc(uint8_t type, int16_t bx, int16_t by, int16_t bz ,int16_t ex, int16_t ey, int16_t ez);
line3Du32_t * line3Du32_malloc(uint8_t type, uint32_t bx, uint32_t by, uint32_t bz ,uint32_t ex, uint32_t ey, uint32_t ez);
line3Di32_t * line3Di32_malloc(uint8_t type, int32_t bx, int32_t by, int32_t bz ,int32_t ex, int32_t ey, int32_t ez);
line3Du64_t * line3Du64_malloc(uint8_t type, uint64_t bx, uint64_t by, uint64_t bz ,uint64_t ex, uint64_t ey, uint64_t ez);
line3Di64_t * line3Di64_malloc(uint8_t type, int64_t bx, int64_t by, int64_t bz ,int64_t ex, int64_t ey, int64_t ez);
line3Df_t * line3Df_malloc(uint8_t type, float bx, float by, float bz, float ex, float ey, float ez);
line3Dd_t * line3Dd_malloc(uint8_t type, double bx, double by, double bz, double ex, double ey, double ez);

line4Du8_t * line4Du8_malloc(uint8_t type, uint8_t bx, uint8_t by, uint8_t bz , uint8_t bq, uint8_t ex, uint8_t ey, uint8_t ez, uint8_t eq);
line4Di8_t * line4Di8_malloc(uint8_t type,  int8_t bx, int8_t by, int8_t bz , int8_t bq, int8_t ex, int8_t ey, int8_t ez, int8_t eq);
line4Du16_t * line4Du16_malloc(uint8_t type,  uint16_t bx, uint16_t by, uint16_t bz , uint16_t bq, uint16_t ex, uint16_t ey, uint16_t ez, uint16_t eq);
line4Di16_t * line4Di16_malloc(uint8_t type,  int16_t bx, int16_t by, int16_t bz , int16_t bq, int16_t ex, int16_t ey, int16_t ez, int16_t eq);
line4Du32_t * line4Du32_malloc(uint8_t type, uint32_t bx, uint32_t by, uint32_t bz , uint32_t bq, uint32_t ex, uint32_t ey, uint32_t ez, uint32_t eq);
line4Di32_t * line4Di32_malloc(uint8_t type,  int32_t bx, int32_t by, int32_t bz , int32_t bq, int32_t ex, int32_t ey, int32_t ez, int32_t eq);
line4Du64_t * line4Du64_malloc(uint8_t type, uint64_t bx, uint64_t by, uint64_t bz , uint64_t bq ,uint64_t ex, uint64_t ey, uint64_t ez,  uint64_t eq);
line4Di64_t * line4Di64_malloc(uint8_t type,  int64_t bx, int64_t by, int64_t bz , int64_t bq, int64_t ex, int64_t ey, int64_t ez, int64_t eq);
line4Df_t * line4Df_malloc(uint8_t type, float bx, float by, float bz, float bq, float ex, float ey, float ez, float eq);
line4Dd_t * line4Dd_malloc(uint8_t type, double bx, double by, double bz, double bq, double ex, double ey, double ez, double eq);

/**
* free function
**/
void line_free(void * out);

/**
* Get Start X
**/

uint8_t line2Du8_getStartX(line2Du8_t * out);
int8_t line2Di8_getStartX(line2Di8_t * out);
uint16_t line2Du16_getStartX(line2Du16_t * out);
int16_t line2Di16_getStartX(line2Di16_t * out);
uint32_t line2Du32_getStartX(line2Du32_t * out);
int32_t line2Di32_getStartX(line2Di32_t * out);
uint64_t line2Du64_getStartX(line2Du64_t * out);
uint64_t line2Di64_getStartX(line2Di64_t * out);
float line2Df_getStartX(line2Df_t * out);
double line2Dd_getStartX(line2Dd_t * out);

uint8_t line3Du8_getStartX(line3Du8_t * out);
int8_t line3Di8_getStartX(line3Di8_t * out);
uint16_t line3Du16_getStartX(line3Du16_t * out);
int16_t line3Di16_getStartX(line3Di16_t * out);
uint32_t line3Du32_getStartX(line3Du32_t * out);
int32_t line3Di32_getStartX(line3Di32_t * out);
uint64_t line3Du64_getStartX(line3Du64_t * out);
int64_t line3Di64_getStartX(line3Di64_t * out);
float line3Df_getStartX(line3Df_t * out);
double line3Dd_getStartX(line3Dd_t * out);

uint8_t line4Du8_getStartX(line4Du8_t * out);
int8_t line4Di8_getStartX(line4Di8_t * out);
uint16_t line4Du16_getStartX(line4Du16_t * out);
int16_t line4Di16_getStartX(line4Di16_t * out);
uint32_t line42Du32_getStartX(line4Du32_t * out);
int32_t line4Di32_getStartX(line4Di32_t * out);
uint64_t line4Du64_getStartX(line4Du64_t * out);
int64_t line4Di64_getStartX(line4Di64_t * out);
float line4Df_getStartX(line4Df_t * out);
double line4Dd_getStartX(line4Dd_t * out);


/**
* Get Start Y
**/

uint8_t line2Du8_getStartY(line2Du8_t * out);
int8_t line2Di8_getStartY(line2Di8_t * out);
uint16_t line2Du16_getStartY(line2Du16_t * out);
int16_t line2Di16_getStartY(line2Di16_t * out);
uint32_t line2Du32_getStartY(line2Du32_t * out);
int32_t line2Di32_getStartY(line2Di32_t * out);
uint64_t line2Du64_getStartY(line2Du64_t * out);
uint64_t line2Di64_getStartY(line2Di64_t * out);
float line2Df_getStartY(line2Df_t * out);
double line2Dd_getStartY(line2Dd_t * out);

uint8_t line3Du8_getStartY(line3Du8_t * out);
int8_t line3Di8_getStartY(line3Di8_t * out);
uint16_t line3Du16_getStartY(line3Du16_t * out);
int16_t line3Di16_getStartY(line3Di16_t * out);
uint32_t line3Du32_getStartY(line3Du32_t * out);
int32_t line3Di32_getStartY(line3Di32_t * out);
uint64_t line3Du64_getStartY(line3Du64_t * out);
int64_t line3Di64_getStartY(line3Di64_t * out);
float line3Df_getStartY(line3Df_t * out);
double line3Dd_getStartY(line3Dd_t * out);

uint8_t line4Du8_getStartY(line4Du8_t * out);
int8_t line4Di8_getStartY(line4Di8_t * out);
uint16_t line4Du16_getStartY(line4Du16_t * out);
int16_t line4Di16_getStartY(line4Di16_t * out);
uint32_t line42Du32_getStartY(line4Du32_t * out);
int32_t line4Di32_getStartY(line4Di32_t * out);
uint64_t line4Du64_getStartY(line4Du64_t * out);
int64_t line4Di64_getStartY(line4Di64_t * out);
float line4Df_getStartY(line4Df_t * out);
double line4Dd_getStartY(line4Dd_t * out);


/**
* Get End X
**/
uint8_t line2Du8_getEndX(line2Du8_t * out);
int8_t line2Di8_getEndX(line2Di8_t * out);
uint16_t line2Du16_getEndX(line2Du16_t * out);
int16_t line2Di16_getEndX(line2Di16_t * out);
uint32_t line2Du32_getEndX(line2Du32_t * out);
int32_t line2Di32_getEndX(line2Di32_t * out);
uint64_t line2Du64_getEndX(line2Du64_t * out);
uint64_t line2Di64_getEndX(line2Di64_t * out);
float line2Df_getEndX(line2Df_t * out);
double line2Dd_getEndX(line2Dd_t * out);

uint8_t line3Du8_getEndX(line3Du8_t * out);
int8_t line3Di8_getEndX(line3Di8_t * out);
uint16_t line3Du16_getEndX(line3Du16_t * out);
int16_t line3Di16_getEndX(line3Di16_t * out);
uint32_t line3Du32_getEndX(line3Du32_t * out);
int32_t line3Di32_getEndX(line3Di32_t * out);
uint64_t line3Du64_getEndX(line3Du64_t * out);
int64_t line3Di64_getEndX(line3Di64_t * out);
float line3Df_getEndX(line3Df_t * out);
double line3Dd_getEndX(line3Dd_t * out);

uint8_t line4Du8_getEndX(line4Du8_t * out);
int8_t line4Di8_getEndX(line4Di8_t * out);
uint16_t line4Du16_getEndX(line4Du16_t * out);
int16_t line4Di16_getEndX(line4Di16_t * out);
uint32_t line42Du32_getEndX(line4Du32_t * out);
int32_t line4Di32_getEndX(line4Di32_t * out);
uint64_t line4Du64_getEndX(line4Du64_t * out);
int64_t line4Di64_getEndX(line4Di64_t * out);
float line4Df_getEndX(line4Df_t * out);
double line4Dd_getEndX(line4Dd_t * out);

/**
* Get End Y
**/
uint8_t line2Du8_getEndY(line2Du8_t * out);
int8_t line2Di8_getEndY(line2Di8_t * out);
uint16_t line2Du16_getEndY(line2Du16_t * out);
int16_t line2Di16_getEndY(line2Di16_t * out);
uint32_t line2Du32_getEndY(line2Du32_t * out);
int32_t line2Di32_getEndY(line2Di32_t * out);
uint64_t line2Du64_getEndY(line2Du64_t * out);
uint64_t line2Di64_getEndY(line2Di64_t * out);
float line2Df_getEndY(line2Df_t * out);
double line2Dd_getEndY(line2Dd_t * out);

uint8_t line3Du8_getEndY(line3Du8_t * out);
int8_t line3Di8_getEndY(line3Di8_t * out);
uint16_t line3Du16_getEndY(line3Du16_t * out);
int16_t line3Di16_getEndY(line3Di16_t * out);
uint32_t line3Du32_getEndY(line3Du32_t * out);
int32_t line3Di32_getEndY(line3Di32_t * out);
uint64_t line3Du64_getEndY(line3Du64_t * out);
int64_t line3Di64_getEndY(line3Di64_t * out);
float line3Df_getEndY(line3Df_t * out);
double line3Dd_getEndY(line3Dd_t * out);

uint8_t line4Du8_getEndY(line4Du8_t * out);
int8_t line4Di8_getEndY(line4Di8_t * out);
uint16_t line4Du16_getEndY(line4Du16_t * out);
int16_t line4Di16_getEndY(line4Di16_t * out);
uint32_t line42Du32_getEndY(line4Du32_t * out);
int32_t line4Di32_getEndY(line4Di32_t * out);
uint64_t line4Du64_getEndY(line4Du64_t * out);
int64_t line4Di64_getEndY(line4Di64_t * out);
float line4Df_getEndY(line4Df_t * out);
double line4Dd_getEndY(line4Dd_t * out);

/**
End of 2D Line Getter Functions
**/

/**
* Get Start Z
* For 3D & 4D Lines
**/

uint8_t line3Du8_getStartZ(line3Du8_t * out);
int8_t line3Di8_getStartZ(line3Di8_t * out);
uint16_t line3Du16_getStartZ(line3Du16_t * out);
int16_t line3Di16_getStartZ(line3Di16_t * out);
uint32_t line3Du32_getStartZ(line3Du32_t * out);
int32_t line3Di32_getStartZ(line3Di32_t * out);
uint64_t line3Du64_getStartZ(line3Du64_t * out);
int64_t line3Di64_getStartZ(line3Di64_t * out);
float line3Df_getStartZ(line3Df_t * out);
double line3Dd_getStartZ(line3Dd_t * out);

uint8_t line4Du8_getStartZ(line4Du8_t * out);
int8_t line4Di8_getStartZ(line4Di8_t * out);
uint16_t line4Du16_getStartZ(line4Du16_t * out);
int16_t line4Di16_getStartZ(line4Di16_t * out);
uint32_t line42Du32_getStartZ(line4Du32_t * out);
int32_t line4Di32_getStartZ(line4Di32_t * out);
uint64_t line4Du64_getStartZ(line4Du64_t * out);
int64_t line4Di64_getStartZ(line4Di64_t * out);
float line4Df_getStartZ(line4Df_t * out);
double line4Dd_getStartZ(line4Dd_t * out);

/**
* Get End Z
* for 3D & 4D Lines
**/

uint8_t line3Du8_getEndZ(line3Du8_t * out);
int8_t line3Di8_getEndZ(line3Di8_t * out);
uint16_t line3Du16_getEndZ(line3Du16_t * out);
int16_t line3Di16_getEndZ(line3Di16_t * out);
uint32_t line3Du32_getEndZ(line3Du32_t * out);
int32_t line3Di32_getEndZ(line3Di32_t * out);
uint64_t line3Du64_getEndZ(line3Du64_t * out);
int64_t line3Di64_getEndZ(line3Di64_t * out);
float line3Df_getEndZ(line3Df_t * out);
double line3Dd_getEndZ(line3Dd_t * out);

uint8_t line4Du8_getEndZ(line4Du8_t * out);
int8_t line4Di8_getEndZ(line4Di8_t * out);
uint16_t line4Du16_getEndZ(line4Du16_t * out);
int16_t line4Di16_getEndZ(line4Di16_t * out);
uint32_t line42Du32_getEndZ(line4Du32_t * out);
int32_t line4Di32_getEndZ(line4Di32_t * out);
uint64_t line4Du64_getEndZ(line4Du64_t * out);
int64_t line4Di64_getEndZ(line4Di64_t * out);
float line4Df_getEndZ(line4Df_t * out);
double line4Dd_getEndZ(line4Dd_t * out);

/**
End of 3D Line Getter Functions
**/

/**
* Get Start W
* For  4D Lines
**/

uint8_t line4Du8_getStartW(line4Du8_t * out);
int8_t line4Di8_getStartW(line4Di8_t * out);
uint16_t line4Du16_getStartW(line4Du16_t * out);
int16_t line4Di16_getStartW(line4Di16_t * out);
uint32_t line42Du32_getStartW(line4Du32_t * out);
int32_t line4Di32_getStartW(line4Di32_t * out);
uint64_t line4Du64_getStartW(line4Du64_t * out);
int64_t line4Di64_getStartW(line4Di64_t * out);
float line4Df_getStartW(line4Df_t * out);
double line4Dd_getStartW(line4Dd_t * out);

/**
* Get End W
* For  4D Lines
**/
uint8_t line4Du8_getEndW(line4Du8_t * out);
int8_t line4Di8_getEndW(line4Di8_t * out);
uint16_t line4Du16_getEndW(line4Du16_t * out);
int16_t line4Di16_getEndW(line4Di16_t * out);
uint32_t line42Du32_getEndW(line4Du32_t * out);
int32_t line4Di32_getEndW(line4Di32_t * out);
uint64_t line4Du64_getEndW(line4Du64_t * out);
int64_t line4Di64_getEndW(line4Di64_t * out);
float line4Df_getEndW(line4Df_t * out);
double line4Dd_getEndW(line4Dd_t * out);



/**
* Set Start X
**/

void line2Du8_setStartX(line2Du8_t * out, uint8_t x);
void line2Di8_setStartX(line2Di8_t * out, int8_t x);
void line2Du16_setStartX(line2Du16_t * out,uint16_t x);
void line2Di16_setStartX(line2Di16_t * out, int16_t x);
void line2Du32_setStartX(line2Du32_t * out, uint32_t x);
void line2Di32_setStartX(line2Di32_t * out, int32_t x);
void line2Du64_setStartX(line2Du64_t * out, uint64_t x);
void line2Di64_setStartX(line2Di64_t * out, uint64_t x);
void line2Df_setStartX(line2Df_t * out, float x);
void line2Dd_setStartX(line2Dd_t * out, double x);

void line3Du8_setStartX(line3Du8_t * out, uint8_t x);
void line3Di8_setStartX(line3Di8_t * out, int8_t x);
void line3Du16_setStartX(line3Du16_t * out,uint16_t x);
void line3Di16_setStartX(line3Di16_t * out, int16_t x);
void line3Du32_setStartX(line3Du32_t * out, uint32_t x);
void line3Di32_setStartX(line3Di32_t * out, int32_t x);
void line3Du64_setStartX(line3Du64_t * out, uint64_t x);
void line3Di64_setStartX(line3Di64_t * out, uint64_t x);
void line3Df_setStartX(line3Df_t * out, float x);
void line3Dd_setStartX(line3Dd_t * out, double x);

void line4Du8_setStartX(line4Du8_t * out, uint8_t x);
void line4Di8_setStartX(line4Di8_t * out, int8_t x);
void line4Du16_setStartX(line4Du16_t * out,uint16_t x);
void line4Di16_setStartX(line4Di16_t * out, int16_t x);
void line4Du32_setStartX(line4Du32_t * out, uint32_t x);
void line4Di32_setStartX(line4Di32_t * out, int32_t x);
void line4Du64_setStartX(line4Du64_t * out, uint64_t x);
void line4Di64_setStartX(line4Di64_t * out, uint64_t x);
void line4Df_setStartX(line4Df_t * out, float x);
void line4Dd_setStartX(line4Dd_t * out, double x);

/**
* Set Start Y
**/

void line2Du8_setStartY(line2Du8_t * out, uint8_t x);
void line2Di8_setStartY(line2Di8_t * out, int8_t x);
void line2Du16_setStartY(line2Du16_t * out,uint16_t x);
void line2Di16_setStartY(line2Di16_t * out, int16_t x);
void line2Du32_setStartY(line2Du32_t * out, uint32_t x);
void line2Di32_setStartY(line2Di32_t * out, int32_t x);
void line2Du64_setStartY(line2Du64_t * out, uint64_t x);
void line2Di64_setStartY(line2Di64_t * out, uint64_t x);
void line2Df_setStartY(line2Df_t * out, float x);
void line2Dd_setStartY(line2Dd_t * out, double x);

void line3Du8_setStartY(line3Du8_t * out, uint8_t x);
void line3Di8_setStartY(line3Di8_t * out, int8_t x);
void line3Du16_setStartY(line3Du16_t * out,uint16_t x);
void line3Di16_setStartY(line3Di16_t * out, int16_t x);
void line3Du32_setStartY(line3Du32_t * out, uint32_t x);
void line3Di32_setStartY(line3Di32_t * out, int32_t x);
void line3Du64_setStartY(line3Du64_t * out, uint64_t x);
void line3Di64_setStartY(line3Di64_t * out, uint64_t x);
void line3Df_setStartY(line3Df_t * out, float x);
void line3Dd_setStartY(line3Dd_t * out, double x);

void line4Du8_setStartY(line4Du8_t * out, uint8_t x);
void line4Di8_setStartY(line4Di8_t * out, int8_t x);
void line4Du16_setStartY(line4Du16_t * out,uint16_t x);
void line4Di16_setStartY(line4Di16_t * out, int16_t x);
void line4Du32_setStartY(line4Du32_t * out, uint32_t x);
void line4Di32_setStartY(line4Di32_t * out, int32_t x);
void line4Du64_setStartY(line4Du64_t * out, uint64_t x);
void line4Di64_setStartY(line4Di64_t * out, uint64_t x);
void line4Df_setStartY(line4Df_t * out, float x);
void line4Dd_setStartY(line4Dd_t * out, double x);

/**
* Set End X
**/

void line2Du8_setEndX(line2Du8_t * out, uint8_t x);
void line2Di8_setEndX(line2Di8_t * out, int8_t x);
void line2Du16_setEndX(line2Du16_t * out,uint16_t x);
void line2Di16_setEndX(line2Di16_t * out, int16_t x);
void line2Du32_setEndX(line2Du32_t * out, uint32_t x);
void line2Di32_setEndX(line2Di32_t * out, int32_t x);
void line2Du64_setEndX(line2Du64_t * out, uint64_t x);
void line2Di64_setEndX(line2Di64_t * out, uint64_t x);
void line2Df_setEndX(line2Df_t * out, float x);
void line2Dd_setEndX(line2Dd_t * out, double x);

void line3Du8_setEndX(line3Du8_t * out, uint8_t x);
void line3Di8_setEndX(line3Di8_t * out, int8_t x);
void line3Du16_setEndX(line3Du16_t * out,uint16_t x);
void line3Di16_setEndX(line3Di16_t * out, int16_t x);
void line3Du32_setEndX(line3Du32_t * out, uint32_t x);
void line3Di32_setEndX(line3Di32_t * out, int32_t x);
void line3Du64_setEndX(line3Du64_t * out, uint64_t x);
void line3Di64_setEndX(line3Di64_t * out, uint64_t x);
void line3Df_setEndX(line3Df_t * out, float x);
void line3Dd_setEndX(line3Dd_t * out, double x);

void line4Du8_setEndX(line4Du8_t * out, uint8_t x);
void line4Di8_setEndX(line4Di8_t * out, int8_t x);
void line4Du16_setEndX(line4Du16_t * out,uint16_t x);
void line4Di16_setEndX(line4Di16_t * out, int16_t x);
void line4Du32_setEndX(line4Du32_t * out, uint32_t x);
void line4Di32_setEndX(line4Di32_t * out, int32_t x);
void line4Du64_setEndX(line4Du64_t * out, uint64_t x);
void line4Di64_setEndX(line4Di64_t * out, uint64_t x);
void line4Df_setEndX(line4Df_t * out, float x);
void line4Dd_setEndX(line4Dd_t * out, double x);

/**
* Set End Y
**/

void line2Du8_setEndY(line2Du8_t * out, uint8_t x);
void line2Di8_setEndY(line2Di8_t * out, int8_t x);
void line2Du16_setEndY(line2Du16_t * out,uint16_t x);
void line2Di16_setEndY(line2Di16_t * out, int16_t x);
void line2Du32_setEndY(line2Du32_t * out, uint32_t x);
void line2Di32_setEndY(line2Di32_t * out, int32_t x);
void line2Du64_setEndY(line2Du64_t * out, uint64_t x);
void line2Di64_setEndY(line2Di64_t * out, uint64_t x);
void line2Df_setEndY(line2Df_t * out, float x);
void line2Dd_setEndY(line2Dd_t * out, double x);

void line3Du8_setEndY(line3Du8_t * out, uint8_t x);
void line3Di8_setEndY(line3Di8_t * out, int8_t x);
void line3Du16_setEndY(line3Du16_t * out,uint16_t x);
void line3Di16_setEndY(line3Di16_t * out, int16_t x);
void line3Du32_setEndY(line3Du32_t * out, uint32_t x);
void line3Di32_setEndY(line3Di32_t * out, int32_t x);
void line3Du64_setEndY(line3Du64_t * out, uint64_t x);
void line3Di64_setEndY(line3Di64_t * out, uint64_t x);
void line3Df_setEndY(line3Df_t * out, float x);
void line3Dd_setEndY(line3Dd_t * out, double x);

void line4Du8_setEndY(line4Du8_t * out, uint8_t x);
void line4Di8_setEndY(line4Di8_t * out, int8_t x);
void line4Du16_setEndY(line4Du16_t * out,uint16_t x);
void line4Di16_setEndY(line4Di16_t * out, int16_t x);
void line4Du32_setEndY(line4Du32_t * out, uint32_t x);
void line4Di32_setEndY(line4Di32_t * out, int32_t x);
void line4Du64_setEndY(line4Du64_t * out, uint64_t x);
void line4Di64_setEndY(line4Di64_t * out, uint64_t x);
void line4Df_setEndY(line4Df_t * out, float x);
void line4Dd_setEndY(line4Dd_t * out, double x);

/**
* Set Start Z
**/

void line3Du8_setStartZ(line3Du8_t * out, uint8_t x);
void line3Di8_setStartZ(line3Di8_t * out, int8_t x);
void line3Du16_setStartZ(line3Du16_t * out,uint16_t x);
void line3Di16_setStartZ(line3Di16_t * out, int16_t x);
void line3Du32_setStartZ(line3Du32_t * out, uint32_t x);
void line3Di32_setStartZ(line3Di32_t * out, int32_t x);
void line3Du64_setStartZ(line3Du64_t * out, uint64_t x);
void line3Di64_setStartZ(line3Di64_t * out, uint64_t x);
void line3Df_setStartZ(line3Df_t * out, float x);
void line3Dd_setStartZ(line3Dd_t * out, double x);

void line4Du8_setStartZ(line4Du8_t * out, uint8_t x);
void line4Di8_setStartZ(line4Di8_t * out, int8_t x);
void line4Du16_setStartZ(line4Du16_t * out,uint16_t x);
void line4Di16_setStartZ(line4Di16_t * out, int16_t x);
void line4Du32_setStartZ(line4Du32_t * out, uint32_t x);
void line4Di32_setStartZ(line4Di32_t * out, int32_t x);
void line4Du64_setStartZ(line4Du64_t * out, uint64_t x);
void line4Di64_setStartZ(line4Di64_t * out, uint64_t x);
void line4Df_setStartZ(line4Df_t * out, float x);
void line4Dd_setStartZ(line4Dd_t * out, double x);

/**
* Set End Z
**/

void line3Du8_setEndZ(line3Du8_t * out, uint8_t x);
void line3Di8_setEndZ(line3Di8_t * out, int8_t x);
void line3Du16_setEndZ(line3Du16_t * out,uint16_t x);
void line3Di16_setEndZ(line3Di16_t * out, int16_t x);
void line3Du32_setEndZ(line3Du32_t * out, uint32_t x);
void line3Di32_setEndZ(line3Di32_t * out, int32_t x);
void line3Du64_setEndZ(line3Du64_t * out, uint64_t x);
void line3Di64_setEndZ(line3Di64_t * out, uint64_t x);
void line3Df_setEndZ(line3Df_t * out, float x);
void line3Dd_setEndZ(line3Dd_t * out, double x);

void line4Du8_setEndZ(line4Du8_t * out, uint8_t x);
void line4Di8_setEndZ(line4Di8_t * out, int8_t x);
void line4Du16_setEndZ(line4Du16_t * out,uint16_t x);
void line4Di16_setEndZ(line4Di16_t * out, int16_t x);
void line4Du32_setEndZ(line4Du32_t * out, uint32_t x);
void line4Di32_setEndZ(line4Di32_t * out, int32_t x);
void line4Du64_setEndZ(line4Du64_t * out, uint64_t x);
void line4Di64_setEndZ(line4Di64_t * out, uint64_t x);
void line4Df_setEndZ(line4Df_t * out, float x);
void line4Dd_setEndZ(line4Dd_t * out, double x);



/**
* Set Start W
**/

void line4Du8_setStartW(line4Du8_t * out, uint8_t x);
void line4Di8_setStartW(line4Di8_t * out, int8_t x);
void line4Du16_setStartW(line4Du16_t * out,uint16_t x);
void line4Di16_setStartW(line4Di16_t * out, int16_t x);
void line4Du32_setStartW(line4Du32_t * out, uint32_t x);
void line4Di32_setStartW(line4Di32_t * out, int32_t x);
void line4Du64_setStartW(line4Du64_t * out, uint64_t x);
void line4Di64_setStartW(line4Di64_t * out, uint64_t x);
void line4Df_setStartW(line4Df_t * out, float x);
void line4Dd_setStartW(line4Dd_t * out, double x);

/**
* Set End W
**/

void line4Du8_setEndW(line4Du8_t * out, uint8_t x);
void line4Di8_setEndW(line4Di8_t * out, int8_t x);
void line4Du16_setEndW(line4Du16_t * out,uint16_t x);
void line4Di16_setEndW(line4Di16_t * out, int16_t x);
void line4Du32_setEndW(line4Du32_t * out, uint32_t x);
void line4Di32_setEndW(line4Di32_t * out, int32_t x);
void line4Du64_setEndW(line4Du64_t * out, uint64_t x);
void line4Di64_setEndW(line4Di64_t * out, uint64_t x);
void line4Df_setEndW(line4Df_t * out, float x);
void line4Dd_setEndW(line4Dd_t * out, double x);



/**
* intersects functions
**/
bool line2du8_intersects(line2Du8 * first, line2Du8 * second);


#endif
