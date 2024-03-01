#include "../../include/physics/line.h"
#include "../../include/math/vec2"
#include "../../include/math/vec3"
#include "../../include/math/vec4"

/*
* 2D Implementations
*/
struct line2Du8{
  uint8_t _type; // type: Line or Vector
  vec2uint8_t *_start; // start of the line
  vec2uint8_t *_end; // if _type = vector, than this is the directional vector
};

struct line2Di8{
  uint8_t _type; // type: Line or Vector
  vec2int8_t *_start; // start of the line
  vec2int8_t *_end; // if _type = vector, than this is the directional vector
};

struct line2Du16{
  uint8_t _type; // type: Line or Vector
  vec2uint16_t *_start; // start of the line
  vec2uint16_t *_end; // if _type = vector, than this is the directional vector
};

struct line2Di16{
  uint8_t _type; // type: Line or Vector
  vec2int16_t *_start; // start of the line
  vec2int16_t *_end; // if _type = vector, than this is the directional vector
};

struct line2Du32{
  uint8_t _type; // type: Line or Vector
  vec2uint32_t *_start; // start of the line
  vec2uint32_t *_end; // if _type = vector, than this is the directional vector
};

struct line2Di32{
  uint8_t _type; // type: Line or Vector
  vec2int32_t *_start; // start of the line
  vec2int32_t *_end; // if _type = vector, than this is the directional vector
};

struct line2Du64{
  uint8_t _type; // type: Line or Vector
  vec2uint64_t *_start; // start of the line
  vec2uint64_t *_end; // if _type = vector, than this is the directional vector
};

struct line2Di64{
  uint8_t _type; // type: Line or Vector
  vec2int64_t *_start; // start of the line
  vec2int64_t *_end; // if _type = vector, than this is the directional vector
};

struct line2Df{
  uint8_t _type; // type: Line or Vector
  vec2f_t *_start; // start of the line
  vec2f_t *_end; // if _type = vector, than this is the directional vector
};

struct line2Dd{
  uint8_t _type; // type: Line or Vector
  vec2d_t *_start; // start of the line
  vec2d_t *_end; // if _type = vector, than this is the directional vector
};

/*
* 3D Implementations
*/
struct line3Du8{
  uint8_t _type; // type: Line or Vector
  vec3uint8_t *_start; // start of the line
  vec3uint8_t *_end; // if _type = vector, than this is the directional vector
};

struct line3Di8{
  uint8_t _type; // type: Line or Vector
  vec3int8_t *_start; // start of the line
  vec3int8_t *_end; // if _type = vector, than this is the directional vector
};

struct line3Du16{
  uint8_t _type; // type: Line or Vector
  vec3uint16_t *_start; // start of the line
  vec3uint16_t *_end; // if _type = vector, than this is the directional vector
};

struct line3Di16{
  uint8_t _type; // type: Line or Vector
  vec3int16_t *_start; // start of the line
  vec3int16_t *_end; // if _type = vector, than this is the directional vector
};

struct line3Du32{
  uint8_t _type; // type: Line or Vector
  vec3uint32_t *_start; // start of the line
  vec3uint32_t *_end; // if _type = vector, than this is the directional vector
};

struct line3Di32{
  uint8_t _type; // type: Line or Vector
  vec3int32_t *_start; // start of the line
  vec3int32_t *_end; // if _type = vector, than this is the directional vector
};

struct line3Du64{
  uint8_t _type; // type: Line or Vector
  vec3uint64_t *_start; // start of the line
  vec3uint64_t *_end; // if _type = vector, than this is the directional vector
};

struct line3Di64{
  uint8_t _type; // type: Line or Vector
  vec3int64_t *_start; // start of the line
  vec3int64_t *_end; // if _type = vector, than this is the directional vector
};

struct line3Df{
  uint8_t _type; // type: Line or Vector
  vec3f_t *_start; // start of the line
  vec3f_t *_end; // if _type = vector, than this is the directional vector
};

struct line3Dd{
  uint8_t _type; // type: Line or Vector
  vec3d_t *_start; // start of the line
  vec3d_t *_end; // if _type = vector, than this is the directional vector
};

/*
* 4D Implementations
*/
struct line4Du8{
  uint8_t _type; // type: Line or Vector
  vec4uint8_t *_start; // start of the line
  vec4uint8_t *_end; // if _type = vector, than this is the directional vector
};

struct line4Di8{
  uint8_t _type; // type: Line or Vector
  vec4int8_t *_start; // start of the line
  vec4int8_t *_end; // if _type = vector, than this is the directional vector
};

struct line4Du16{
  uint8_t _type; // type: Line or Vector
  vec4uint16_t *_start; // start of the line
  vec4uint16_t *_end; // if _type = vector, than this is the directional vector
};

struct line4Di16{
  uint8_t _type; // type: Line or Vector
  vec4int16_t *_start; // start of the line
  vec4int16_t *_end; // if _type = vector, than this is the directional vector
};

struct line4Du32{
  uint8_t _type; // type: Line or Vector
  vec4uint32_t *_start; // start of the line
  vec4uint32_t *_end; // if _type = vector, than this is the directional vector
};

struct line4Di32{
  uint8_t _type; // type: Line or Vector
  vec4int32_t *_start; // start of the line
  vec4int32_t *_end; // if _type = vector, than this is the directional vector
};

struct line4Du64{
  uint8_t _type; // type: Line or Vector
  vec4uint64_t *_start; // start of the line
  vec4uint64_t *_end; // if _type = vector, than this is the directional vector
};

struct line4Di64{
  uint8_t _type; // type: Line or Vector
  vec4int64_t *_start; // start of the line
  vec4int64_t *_end; // if _type = vector, than this is the directional vector
};

struct line4Df{
  uint8_t _type; // type: Line or Vector
  vec4f_t *_start; // start of the line
  vec4f_t *_end; // if _type = vector, than this is the directional vector
};

struct line4Dd{
  uint8_t _type; // type: Line or Vector
  vec4d_t *_start; // start of the line
  vec4d_t *_end; // if _type = vector, than this is the directional vector
};

/**
* Malloc functions
**/

line2Du8_t * line2Du8_malloc(uint8_t type, uint8_t bx, uint8_t by, uint8_t ex, uint8_t ey){
  line2Du8_t * out = malloc(sizeof(line2Du8_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec2U8(bx,by);
    out->_end = allocVec2U8(ex,ey);
  }
  return out;
}

line2Di8_t * line2Di8_malloc(uint8_t type, int8_t bx, int8_t by, int8_t ex, int8_t ey){
  line2Di8_t * out = malloc(sizeof(line2Di8_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec2I8(bx,by);
    out->_end = allocVec2I8(ex,ey);
  }
  return out;
}
line2Du16_t * line2Du16_malloc(uint8_t type, uint16_t bx, uint16_t by, uint16_t ex, uint16_t ey){
  line2Du16_t * out = malloc(sizeof(line2Du16_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec2U16(bx,by);
    out->_end = allocVec2U16(ex,ey);
  }
  return out;
}

line2Di16_t * line2Di16_malloc(uint8_t type, int16_t bx, int16_t by, int16_t ex, int16_t ey){
  line2Di16_t * out = malloc(sizeof(line2Di16_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec2I16(bx,by);
    out->_end = allocVec2I16(ex,ey);
  }
  return out;
}
line2Du32_t * line2Du32_malloc(uint8_t type, uint32_t bx, uint32_t by, uint32_t ex, uint32_t ey){
  line2Du32_t * out = malloc(sizeof(line2Du32_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec2U32(bx,by);
    out->_end = allocVec2U32(ex,ey);
  }
  return out;
}

line2Di32_t * line2Di32_malloc(uint8_t type, int32_t bx, int32_t by, int32_t ex, int32_t ey){
  line2Di32_t * out = malloc(sizeof(line2Di32_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec2I32(bx,by);
    out->_end = allocVec2I32(ex,ey);
  }
  return out;
}
line2Du64_t * line2Du64_malloc(uint8_t type, uint64_t bx, uint64_t by, uint64_t ex, uint64_t ey){
  line2Du64_t * out = malloc(sizeof(line2Du64_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec2U64(bx,by);
    out->_end = allocVec2U64(ex,ey);
  }
  return out;
}

line2Di64_t * line2Di64_malloc(uint8_t type, int64_t bx, int64_t by, int64_t ex, int64_t ey){
  line2Di64_t * out = malloc(sizeof(line2Di64_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec2I64(bx,by);
    out->_end = allocVec2I64(ex,ey);
  }
  return out;
}
line2Df_t * line2Df_malloc(uint8_t type, float bx, float by, float ex, float ey){
  line2Df_t * out = malloc(sizeof(line2Df_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec2F(bx,by);
    out->_end = allocVec2F(ex,ey);
  }
  return out;
}
line2Dd_t * line2Dd_malloc(uint8_t type, double bx, double by, double ex, double ey){
  line2Dd_t * out = malloc(sizeof(line2Dd_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec2D(bx,by);
    out->_end = allocVec2D(ex,ey);
  }
  return out;
}

line3Du8_t * line3Du8_malloc(uint8_t type, uint8_t bx, uint8_t by, uint8_t bz ,uint8_t ex, uint8_t ey, uint8_t ez){
  line3Du8_t * out = malloc(sizeof(line3Du8_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec3U8(bx,by,bz);
    out->_end = allocVec3U8(ex,ey,ez);
  }
  return out;
}

line3Di8_t * line3Di8_malloc(uint8_t type, int8_t bx, int8_t by, int8_t bz ,int8_t ex, int8_t ey, int8_t ez){
  line3Di8_t * out = malloc(sizeof(line3Di8_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec3I8(bx,by,bz);
    out->_end = allocVec3I8(ex,ey,ez);
  }
  return out;
}
line3Du16_t * line3Du16_malloc(uint8_t type,  uint16_t bx, uint16_t by, uint16_t bz ,uint16_t ex, uint16_t ey, uint16_t ez){
  line3Du16_t * out = malloc(sizeof(line3Du16_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec3U16(bx,by,bz);
    out->_end = allocVec3U16(ex,ey,ez);
  }
  return out;
}
line3Di16_t * line3Di16_malloc(uint8_t type, int16_t bx, int16_t by, int16_t bz ,int16_t ex, int16_t ey, int16_t ez){
  line3Di16_t * out = malloc(sizeof(line3Di16_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec3I16(bx,by,bz);
    out->_end = allocVec3I16(ex,ey,ez);
  }
  return out;
}
line3Du32_t * line3Du32_malloc(uint8_t type, uint32_t bx, uint32_t by, uint32_t bz ,uint32_t ex, uint32_t ey, uint32_t ez){
  line3Du32_t * out = malloc(sizeof(line3Du32_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec3U32(bx,by,bz);
    out->_end = allocVec3U32(ex,ey,ez);
  }
  return out;
}
line3Di32_t * line3Di32_malloc(uint8_t type, int32_t bx, int32_t by, int32_t bz ,int32_t ex, int32_t ey, int32_t ez){
  line3Di32_t * out = malloc(sizeof(line3Di32_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec3I32(bx,by,bz);
    out->_end = allocVec3I32(ex,ey,ez);
  }
  return out;
}
line3Du64_t * line3Du64_malloc(uint8_t type, uint64_t bx, uint64_t by, uint64_t bz ,uint64_t ex, uint64_t ey, uint64_t ez){
  line3Du64_t * out = malloc(sizeof(line3Du64_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec3U64(bx,by,bz);
    out->_end = allocVec3U64(ex,ey,ez);
  }
  return out;
}
line3Di64_t * line3Di64_malloc(uint8_t type, int64_t bx, int64_t by, int64_t bz ,int64_t ex, int64_t ey, int64_t ez){
  line3Di64_t * out = malloc(sizeof(line3Di64_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec3I64(bx,by,bz);
    out->_end = allocVec3I64(ex,ey,ez);
  }
  return out;
}
line3Df_t * line3Df_malloc(uint8_t type, float bx, float by, float bz, float ex, float ey, float ez){
  line3Df_t * out = malloc(sizeof(line3Df_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec3F(bx,by,bz);
    out->_end = allocVec3F(ex,ey,ez);
  }
  return out;
}
line3Dd_t * line3Dd_malloc(uint8_t type, double bx, double by, double bz, double ex, double ey, double ez){
  line3Dd_t * out = malloc(sizeof(line3Dd_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec3D(bx,by,bz);
    out->_end = allocVec3D(ex,ey,ez);
  }
  return out;
}

line4Du8_t * line4Du8_malloc(uint8_t type, uint8_t bx, uint8_t by, uint8_t bz , uint8_t bq, uint8_t ex, uint8_t ey, uint8_t ez, uint8_t eq){
  line4Du8_t * out = malloc(sizeof(line4Du8_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec4U8(bx,by,bz,bq);
    out->_end = allocVec4U8(ex,ey,ez,eq);
  }
  return out;
}
line4Di8_t * line4Di8_malloc(uint8_t type,  int8_t bx, int8_t by, int8_t bz , int8_t bq, int8_t ex, int8_t ey, int8_t ez, int8_t eq){
  line4Di8_t * out = malloc(sizeof(line4Di8_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec4I8(bx,by,bz,bq);
    out->_end = allocVec4I8(ex,ey,ez,eq);
  }
  return out;
}
line4Du16_t * line4Du16_malloc(uint8_t type,  uint16_t bx, uint16_t by, uint16_t bz , uint16_t bq, uint16_t ex, uint16_t ey, uint16_t ez, uint16_t eq){
  line4Du16_t * out = malloc(sizeof(line4Du16_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec4U16(bx,by,bz,bq);
    out->_end = allocVec4U16(ex,ey,ez,eq);
  }
  return out;
}
line4Di16_t * line4Di16_malloc(uint8_t type,  int16_t bx, int16_t by, int16_t bz , int16_t bq, int16_t ex, int16_t ey, int16_t ez, int16_t eq){
  line4Di16_t * out = malloc(sizeof(line4Di16_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec4I16(bx,by,bz,bq);
    out->_end = allocVec4I16(ex,ey,ez,eq);
  }
  return out;
}
line4Du32_t * line4Du32_malloc(uint8_t type, uint32_t bx, uint32_t by, uint32_t bz , uint32_t bq, uint32_t ex, uint32_t ey, uint32_t ez, uint32_t eq){
  line4Du32_t * out = malloc(sizeof(line4Du32_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec4U32(bx,by,bz,bq);
    out->_end = allocVec4U32(ex,ey,ez,eq);
  }
  return out;
}
line4Di32_t * line4Di32_malloc(uint8_t type,  int32_t bx, int32_t by, int32_t bz , int32_t bq, int32_t ex, int32_t ey, int32_t ez, int32_t eq){
  line4Di32_t * out = malloc(sizeof(line4Di32_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec4I32(bx,by,bz,bq);
    out->_end = allocVec4I32(ex,ey,ez,eq);
  }
  return out;
}
line4Du64_t * line4Du64_malloc(uint8_t type, uint64_t bx, uint64_t by, uint64_t bz , uint64_t bq ,uint64_t ex, uint64_t ey, uint64_t ez,  uint64_t eq){
  line4Du64_t * out = malloc(sizeof(line4Du64_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec4U64(bx,by,bz,bq);
    out->_end = allocVec4U64(ex,ey,ez,eq);
  }
  return out;
}
line4Di64_t * line4Di64_malloc(uint8_t type,  int64_t bx, int64_t by, int64_t bz , int64_t bq, int64_t ex, int64_t ey, int64_t ez, int64_t eq){
  line4Di64_t * out = malloc(sizeof(line4Di64_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec4I64(bx,by,bz,bq);
    out->_end = allocVec4I64(ex,ey,ez,eq);
  }
  return out;
}
line4Df_t * line4Df_malloc(uint8_t type, float bx, float by, float bz, float bq, float ex, float ey, float ez, float eq){
  line4Df_t * out = malloc(sizeof(line4Df_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec4F(bx,by,bz,bq);
    out->_end = allocVec4F(ex,ey,ez,eq);
  }
  return out;
}
line4Dd_t * line4Dd_malloc(uint8_t type, double bx, double by, double bz, double bq, double ex, double ey, double ez, double eq){
  line4Dd_t * out = malloc(sizeof(line4Dd_t));
  if(out != NULL){
    out->_type = type;
    out->_start = allocVec4D(bx,by,bz,bq);
    out->_end = allocVec4D(ex,ey,ez,eq);
  }
  return out;
}

/**
* free function
**/


//internal generic line struct since _start and _end are both pointers, they can
//be abstracted and treated similarly with each type of line.
struct line{
    uint8_t _type;
    void* _start;
    void* _end;
};

typedef struct line line_t;

void line_free(void *out) {
    if (out != NULL) {
        free(((line_t *)out)->_start);
        free(((line_t *)out)->_end);
        free(out);
    }
}


/**
* Get End X
**/
uint8_t line2Du8_getStartX(line2Du8_t * out){
  return vec2u8_X(out->_start);
}
int8_t line2Di8_getStartX(line2Di8_t * out){
  return vec2i8_X(out->_start);
}
uint16_t line2Du16_getStartX(line2Du16_t * out){
  return vec2u16_X(out->_start);
}
int16_t line2Di16_getStartX(line2Di16_t * out){
  return vec2i16_X(out->_start);
}
uint32_t line2Du32_getStartX(line2Du32_t * out){
  return vec2u32_X(out->_start);
}
int32_t line2Di32_getStartX(line2Di32_t * out){
  return vec2i32_X(out->_start);
}
uint64_t line2Du64_getStartX(line2Du64_t * out){
  return vec2u64_X(out->_start);
}
uint64_t line2Di64_getStartX(line2Di64_t * out){
  return vec2i64_X(out->_start);
}
float line2Df_getStartX(line2Df_t * out){
  return vec2f_X(out->_start);
}
double line2Dd_getStartX(line2Dd_t * out){
  return vec2d_X(out->_start);
}

uint8_t line3Du8_getStartX(line3Du8_t * out){
  return vec3u8_X(out->_start);
}
int8_t line3Di8_getStartX(line3Di8_t * out){
  return vec3i8_X(out->_start);
}
uint16_t line3Du16_getStartX(line3Du16_t * out){
  return vec3u16_X(out->_start);
}
int16_t line3Di16_getStartX(line3Di16_t * out){
  return vec3i16_X(out->_start);
}
uint32_t line3Du32_getStartX(line3Du32_t * out){
  return vec3u33_X(out->_start);
}
int32_t line3Di32_getStartX(line3Di32_t * out){
  return vec3i32_X(out->_start);
}
uint64_t line3Du64_getStartX(line3Du64_t * out){
  return vec3u64_X(out->_start);
}
uint64_t line3Di64_getStartX(line3Di64_t * out){
  return vec3i64_X(out->_start);
}
float line3Df_getStartX(line3Df_t * out){
  return vec3f_X(out->_start);
}
double line3Dd_getStartX(line3Dd_t * out){
  return vec3d_X(out->_start);
}

uint8_t line4Du8_getStartX(line4Du8_t * out){
  return vec4u8_X(out->_start);
}
int8_t line4Di8_getStartX(line4Di8_t * out){
  return vec4i8_X(out->_start);
}
uint16_t line4Du16_getStartX(line4Du16_t * out){
  return vec4u16_X(out->_start);
}
int16_t line4Di16_getStartX(line4Di16_t * out){
  return vec4i16_X(out->_start);
}
uint32_t line4Du32_getStartX(line4Du32_t * out){
  return vec4u32_X(out->_start);
}
int32_t line4Di32_getStartX(line4Di32_t * out){
  return vec4i32_X(out->_start);
}
uint64_t line4Du64_getStartX(line4Du64_t * out){
  return vec4u64_X(out->_start);
}
uint64_t line4Di64_getStartX(line4Di64_t * out){
  return vec4i64_X(out->_start);
}
float line4Df_getStartX(line4Df_t * out){
  return vec4f_X(out->_start);
}
double line4Dd_getStartX(line4Dd_t * out){
  return vec4d_X(out->_start);
}

/**
* Get Start Y
**/

uint8_t line2Du8_getStartY(line2Du8_t * out){
  return vec2u8_Y(out->_start);
}
int8_t line2Di8_getStartY(line2Di8_t * out){
  return vec2i8_Y(out->_start);
}
uint16_t line2Du16_getStartY(line2Du16_t * out){
  return vec2u16_Y(out->_start);
}
int16_t line2Di16_getStartY(line2Di16_t * out){
  return vec2i16_Y(out->_start);
}
uint32_t line2Du32_getStartY(line2Du32_t * out){
  return vec2u32_Y(out->_start);
}
int32_t line2Di32_getStartY(line2Di32_t * out){
  return vec2i32_Y(out->_start);
}
uint64_t line2Du64_getStartY(line2Du64_t * out){
  return vec2u64_Y(out->_start);
}
uint64_t line2Di64_getStartY(line2Di64_t * out){
  return vec2i64_Y(out->_start);
}
float line2Df_getStartY(line2Df_t * out){
  return vec2f_Y(out->_start);
}
double line2Dd_getStartY(line2Dd_t * out){
  return vec2d_Y(out->_start);
}

uint8_t line3Du8_getStartY(line3Du8_t * out){
  return vec3u8_Y(out->_start);
}
int8_t line3Di8_getStartY(line3Di8_t * out){
  return vec3i8_Y(out->_start);
}
uint16_t line3Du16_getStartY(line3Du16_t * out){
  return vec3u16_Y(out->_start);
}
int16_t line3Di16_getStartY(line3Di16_t * out){
  return vec3i16_Y(out->_start);
}
uint32_t line3Du32_getStartY(line3Du32_t * out){
  return vec3u33_Y(out->_start);
}
int32_t line3Di32_getStartY(line3Di32_t * out){
  return vec3i32_Y(out->_start);
}
uint64_t line3Du64_getStartY(line3Du64_t * out){
  return vec3u64_Y(out->_start);
}
uint64_t line3Di64_getStartY(line3Di64_t * out){
  return vec3i64_Y(out->_start);
}
float line3Df_getStartY(line3Df_t * out){
  return vec3f_Y(out->_start);
}
double line3Dd_getStartY(line3Dd_t * out){
  return vec3d_Y(out->_start);
}

uint8_t line4Du8_getStartY(line4Du8_t * out){
  return vec4u8_Y(out->_start);
}
int8_t line4Di8_getStartY(line4Di8_t * out){
  return vec4i8_Y(out->_start);
}
uint16_t line4Du16_getStartY(line4Du16_t * out){
  return vec4u16_Y(out->_start);
}
int16_t line4Di16_getStartY(line4Di16_t * out){
  return vec4i16_Y(out->_start);
}
uint32_t line4Du32_getStartY(line4Du32_t * out){
  return vec4u32_Y(out->_start);
}
int32_t line4Di32_getStartY(line4Di32_t * out){
  return vec4i32_Y(out->_start);
}
uint64_t line4Du64_getStartY(line4Du64_t * out){
  return vec4u64_Y(out->_start);
}
uint64_t line4Di64_getStartY(line4Di64_t * out){
  return vec4i64_Y(out->_start);
}
float line4Df_getStartY(line4Df_t * out){
  return vec4f_Y(out->_start);
}
double line4Dd_getStartY(line4Dd_t * out){
  return vec4d_Y(out->_start);
}

/**
* Get End X
**/
uint8_t line2Du8_getEndX(line2Du8_t * out){
  return vec2u8_X(out->_start);
}
int8_t line2Di8_getEndX(line2Di8_t * out){
  return vec2i8_X(out->_start);
}
uint16_t line2Du16_getEndX(line2Du16_t * out){
  return vec2u16_X(out->_start);
}
int16_t line2Di16_getEndX(line2Di16_t * out){
  return vec2i16_X(out->_start);
}
uint32_t line2Du32_getEndX(line2Du32_t * out){
  return vec2u32_X(out->_start);
}
int32_t line2Di32_getEndX(line2Di32_t * out){
  return vec2i32_X(out->_start);
}
uint64_t line2Du64_getEndX(line2Du64_t * out){
  return vec2u64_X(out->_start);
}
uint64_t line2Di64_getEndX(line2Di64_t * out){
  return vec2i64_X(out->_start);
}
float line2Df_getEndX(line2Df_t * out){
  return vec2f_X(out->_start);
}
double line2Dd_getEndX(line2Dd_t * out){
  return vec2d_X(out->_start);
}

uint8_t line3Du8_getEndX(line3Du8_t * out){
  return vec3u8_X(out->_start);
}
int8_t line3Di8_getEndX(line3Di8_t * out){
  return vec3i8_X(out->_start);
}
uint16_t line3Du16_getEndX(line3Du16_t * out){
  return vec3u16_X(out->_start);
}
int16_t line3Di16_getEndX(line3Di16_t * out){
  return vec3i16_X(out->_start);
}
uint32_t line3Du32_getEndX(line3Du32_t * out){
  return vec3u33_X(out->_start);
}
int32_t line3Di32_getEndX(line3Di32_t * out){
  return vec3i32_X(out->_start);
}
uint64_t line3Du64_getEndX(line3Du64_t * out){
  return vec3u64_X(out->_start);
}
uint64_t line3Di64_getEndX(line3Di64_t * out){
  return vec3i64_X(out->_start);
}
float line3Df_getEndX(line3Df_t * out){
  return vec3f_X(out->_start);
}
double line3Dd_getEndX(line3Dd_t * out){
  return vec3d_X(out->_start);
}

uint8_t line4Du8_getEndX(line4Du8_t * out){
  return vec4u8_X(out->_start);
}
int8_t line4Di8_getEndX(line4Di8_t * out){
  return vec4i8_X(out->_start);
}
uint16_t line4Du16_getEndX(line4Du16_t * out){
  return vec4u16_X(out->_start);
}
int16_t line4Di16_getEndX(line4Di16_t * out){
  return vec4i16_X(out->_start);
}
uint32_t line4Du32_getEndX(line4Du32_t * out){
  return vec4u32_X(out->_start);
}
int32_t line4Di32_getEndX(line4Di32_t * out){
  return vec4i32_X(out->_start);
}
uint64_t line4Du64_getEndX(line4Du64_t * out){
  return vec4u64_X(out->_start);
}
uint64_t line4Di64_getEndX(line4Di64_t * out){
  return vec4i64_X(out->_start);
}
float line4Df_getEndX(line4Df_t * out){
  return vec4f_X(out->_start);
}
double line4Dd_getEndX(line4Dd_t * out){
  return vec4d_X(out->_start);
}

/**
* Get End Y
**/

uint8_t line2Du8_getEndY(line2Du8_t * out){
  return vec2u8_Y(out->_start);
}
int8_t line2Di8_getEndY(line2Di8_t * out){
  return vec2i8_Y(out->_start);
}
uint16_t line2Du16_getEndY(line2Du16_t * out){
  return vec2u16_Y(out->_start);
}
int16_t line2Di16_getEndY(line2Di16_t * out){
  return vec2i16_Y(out->_start);
}
uint32_t line2Du32_getEndY(line2Du32_t * out){
  return vec2u32_Y(out->_start);
}
int32_t line2Di32_getEndY(line2Di32_t * out){
  return vec2i32_Y(out->_start);
}
uint64_t line2Du64_getEndY(line2Du64_t * out){
  return vec2u64_Y(out->_start);
}
uint64_t line2Di64_getEndY(line2Di64_t * out){
  return vec2i64_Y(out->_start);
}
float line2Df_getEndY(line2Df_t * out){
  return vec2f_Y(out->_start);
}
double line2Dd_getEndY(line2Dd_t * out){
  return vec2d_Y(out->_start);
}

uint8_t line3Du8_getEndY(line3Du8_t * out){
  return vec3u8_Y(out->_start);
}
int8_t line3Di8_getEndY(line3Di8_t * out){
  return vec3i8_Y(out->_start);
}
uint16_t line3Du16_getEndY(line3Du16_t * out){
  return vec3u16_Y(out->_start);
}
int16_t line3Di16_getEndY(line3Di16_t * out){
  return vec3i16_Y(out->_start);
}
uint32_t line3Du32_getEndY(line3Du32_t * out){
  return vec3u33_Y(out->_start);
}
int32_t line3Di32_getEndY(line3Di32_t * out){
  return vec3i32_Y(out->_start);
}
uint64_t line3Du64_getEndY(line3Du64_t * out){
  return vec3u64_Y(out->_start);
}
uint64_t line3Di64_getEndY(line3Di64_t * out){
  return vec3i64_Y(out->_start);
}
float line3Df_getEndY(line3Df_t * out){
  return vec3f_Y(out->_start);
}
double line3Dd_getEndY(line3Dd_t * out){
  return vec3d_Y(out->_start);
}

uint8_t line4Du8_getEndY(line4Du8_t * out){
  return vec4u8_Y(out->_start);
}
int8_t line4Di8_getEndY(line4Di8_t * out){
  return vec4i8_Y(out->_start);
}
uint16_t line4Du16_getEndY(line4Du16_t * out){
  return vec4u16_Y(out->_start);
}
int16_t line4Di16_getEndY(line4Di16_t * out){
  return vec4i16_Y(out->_start);
}
uint32_t line4Du32_getEndY(line4Du32_t * out){
  return vec4u32_Y(out->_start);
}
int32_t line4Di32_getEndY(line4Di32_t * out){
  return vec4i32_Y(out->_start);
}
uint64_t line4Du64_getEndY(line4Du64_t * out){
  return vec4u64_Y(out->_start);
}
uint64_t line4Di64_getEndY(line4Di64_t * out){
  return vec4i64_Y(out->_start);
}
float line4Df_getEndY(line4Df_t * out){
  return vec4f_Y(out->_start);
}
double line4Dd_getEndY(line4Dd_t * out){
  return vec4d_Y(out->_start);
}

/**
* Get Start Z
* For 3D & 4D Lines
**/

uint8_t line3Du8_getStartZ(line3Du8_t * out){
  return vec3u8_Z(out->_start);
}
int8_t line3Di8_getStartZ(line3Di8_t * out){
  return vec3i8_Z(out->_start);
}
uint16_t line3Du16_getStartZ(line3Du16_t * out){
  return vec3u16_Z(out->_start);
}
int16_t line3Di16_getStartZ(line3Di16_t * out){
  return vec3i16_Z(out->_start);
}
uint32_t line3Du32_getStartZ(line3Du32_t * out){
  return vec3u33_Z(out->_start);
}
int32_t line3Di32_getStartZ(line3Di32_t * out){
  return vec3i32_Z(out->_start);
}
uint64_t line3Du64_getStartZ(line3Du64_t * out){
  return vec3u64_Z(out->_start);
}
uint64_t line3Di64_getStartZ(line3Di64_t * out){
  return vec3i64_Z(out->_start);
}
float line3Df_getStartZ(line3Df_t * out){
  return vec3f_Z(out->_start);
}
double line3Dd_getStartZ(line3Dd_t * out){
  return vec3d_Z(out->_start);
}

uint8_t line4Du8_getStartZ(line4Du8_t * out){
  return vec4u8_Z(out->_start);
}
int8_t line4Di8_getStartZ(line4Di8_t * out){
  return vec4i8_Z(out->_start);
}
uint16_t line4Du16_getStartZ(line4Du16_t * out){
  return vec4u16_Z(out->_start);
}
int16_t line4Di16_getStartZ(line4Di16_t * out){
  return vec4i16_Z(out->_start);
}
uint32_t line4Du32_getStartZ(line4Du32_t * out){
  return vec4u32_Z(out->_start);
}
int32_t line4Di32_getStartZ(line4Di32_t * out){
  return vec4i32_Z(out->_start);
}
uint64_t line4Du64_getStartZ(line4Du64_t * out){
  return vec4u64_Z(out->_start);
}
uint64_t line4Di64_getStartZ(line4Di64_t * out){
  return vec4i64_Z(out->_start);
}
float line4Df_getStartZ(line4Df_t * out){
  return vec4f_Z(out->_start);
}
double line4Dd_getStartZ(line4Dd_t * out){
  return vec4d_Z(out->_start);
}

/**
* Get End Z
* for 3D & 4D Lines
**/

uint8_t line3Du8_getEndZ(line3Du8_t * out){
  return vec3u8_Z(out->_start);
}
int8_t line3Di8_getEndZ(line3Di8_t * out){
  return vec3i8_Z(out->_start);
}
uint16_t line3Du16_getEndZ(line3Du16_t * out){
  return vec3u16_Z(out->_start);
}
int16_t line3Di16_getEndZ(line3Di16_t * out){
  return vec3i16_Z(out->_start);
}
uint32_t line3Du32_getEndZ(line3Du32_t * out){
  return vec3u33_Z(out->_start);
}
int32_t line3Di32_getEndZ(line3Di32_t * out){
  return vec3i32_Z(out->_start);
}
uint64_t line3Du64_getEndZ(line3Du64_t * out){
  return vec3u64_Z(out->_start);
}
uint64_t line3Di64_getEndZ(line3Di64_t * out){
  return vec3i64_Z(out->_start);
}
float line3Df_getEndZ(line3Df_t * out){
  return vec3f_Z(out->_start);
}
double line3Dd_getEndZ(line3Dd_t * out){
  return vec3d_Z(out->_start);
}

uint8_t line4Du8_getEndZ(line4Du8_t * out){
  return vec4u8_Z(out->_start);
}
int8_t line4Di8_getEndZ(line4Di8_t * out){
  return vec4i8_Z(out->_start);
}
uint16_t line4Du16_getEndZ(line4Du16_t * out){
  return vec4u16_Z(out->_start);
}
int16_t line4Di16_getEndZ(line4Di16_t * out){
  return vec4i16_Z(out->_start);
}
uint32_t line4Du32_getEndZ(line4Du32_t * out){
  return vec4u32_Z(out->_start);
}
int32_t line4Di32_getEndZ(line4Di32_t * out){
  return vec4i32_Z(out->_start);
}
uint64_t line4Du64_getEndZ(line4Du64_t * out){
  return vec4u64_Z(out->_start);
}
uint64_t line4Di64_getEndZ(line4Di64_t * out){
  return vec4i64_Z(out->_start);
}
float line4Df_getEndZ(line4Df_t * out){
  return vec4f_Z(out->_start);
}
double line4Dd_getEndZ(line4Dd_t * out){
  return vec4d_Z(out->_start);
}

/**
* Get Start W
* For  4D Lines
**/

uint8_t line4Du8_getStartW(line4Du8_t * out){
  return vec4u8_W(out->_start);
}
int8_t line4Di8_getStartW(line4Di8_t * out){
  return vec4i8_W(out->_start);
}
uint16_t line4Du16_getStartW(line4Du16_t * out){
  return vec4u16_W(out->_start);
}
int16_t line4Di16_getStartW(line4Di16_t * out){
  return vec4i16_W(out->_start);
}
uint32_t line4Du32_getStartW(line4Du32_t * out){
  return vec4u32_W(out->_start);
}
int32_t line4Di32_getStartW(line4Di32_t * out){
  return vec4i32_W(out->_start);
}
uint64_t line4Du64_getStartW(line4Du64_t * out){
  return vec4u64_W(out->_start);
}
uint64_t line4Di64_getStartW(line4Di64_t * out){
  return vec4i64_W(out->_start);
}
float line4Df_getStartW(line4Df_t * out){
  return vec4f_W(out->_start);
}
double line4Dd_getStartW(line4Dd_t * out){
  return vec4d_W(out->_start);
}

/**
* Get End W
* For  4D Lines
**/
uint8_t line3Du8_getEndW(line3Du8_t * out){
  return vec3u8_W(out->_start);
}
int8_t line3Di8_getEndW(line3Di8_t * out){
  return vec3i8_W(out->_start);
}
uint16_t line3Du16_getEndW(line3Du16_t * out){
  return vec3u16_W(out->_start);
}
int16_t line3Di16_getEndW(line3Di16_t * out){
  return vec3i16_W(out->_start);
}
uint32_t line3Du32_getEndW(line3Du32_t * out){
  return vec3u33_W(out->_start);
}
int32_t line3Di32_getEndW(line3Di32_t * out){
  return vec3i32_W(out->_start);
}
uint64_t line3Du64_getEndW(line3Du64_t * out){
  return vec3u64_W(out->_start);
}
uint64_t line3Di64_getEndW(line3Di64_t * out){
  return vec3i64_W(out->_start);
}
float line3Df_getEndW(line3Df_t * out){
  return vec3f_W(out->_start);
}
double line3Dd_getEndW(line3Dd_t * out){
  return vec3d_W(out->_start);
}

uint8_t line4Du8_getEndW(line4Du8_t * out){
  return vec4u8_W(out->_start);
}
int8_t line4Di8_getEndW(line4Di8_t * out){
  return vec4i8_W(out->_start);
}
uint16_t line4Du16_getEndW(line4Du16_t * out){
  return vec4u16_W(out->_start);
}
int16_t line4Di16_getEndW(line4Di16_t * out){
  return vec4i16_W(out->_start);
}
uint32_t line4Du32_getEndW(line4Du32_t * out){
  return vec4u32_W(out->_start);
}
int32_t line4Di32_getEndW(line4Di32_t * out){
  return vec4i32_W(out->_start);
}
uint64_t line4Du64_getEndW(line4Du64_t * out){
  return vec4u64_W(out->_start);
}
uint64_t line4Di64_getEndW(line4Di64_t * out){
  return vec4i64_W(out->_start);
}
float line4Df_getEndW(line4Df_t * out){
  return vec4f_W(out->_start);
}
double line4Dd_getEndW(line4Dd_t * out){
  return vec4d_W(out->_start);
}

//Setters

/**
* Set Start X
**/


void line2Du8_setStartX(line2Du8_t * out, uint8_t x){
  vec2u8_setX(out->_start,x);
}
void line2Di8_setStartX(line2Di8_t * out, int8_t x){
  vec2i8_setX(out->_start,x);
}
void line2Du16_setStartX(line2Du16_t * out,uint16_t x){
  vec2u16_setX(out->_start,x);
}
void line2Di16_setStartX(line2Di16_t * out, int16_t x){
  vec2i16_setX(out->_start,x);
}
void line2Du32_setStartX(line2Du32_t * out, uint32_t x){
  vec2u32_setX(out->_start,x);
}
void line2Di32_setStartX(line2Di32_t * out, int32_t x){
  vec2i32_setX(out->_start,x);
}
void line2Du64_setStartX(line2Du64_t * out, uint64_t x){
  vec2u64_setX(out->_start,x);
}
void line2Di64_setStartX(line2Di64_t * out, uint64_t x){
  vec2i64_setX(out->_start,x);
}
void line2Df_setStartX(line2Df_t * out, float x){
  vec2f_setX(out->_start,x);
}
void line2Dd_setStartX(line2Dd_t * out, double x){
  vec2d_setX(out->_start,x);
}


void line3Du8_setStartX(line3Du8_t * out, uint8_t x){
  vec3u8_setX(out->_start,x);
}
void line3Di8_setStartX(line3Di8_t * out, int8_t x){
  vec3i8_setX(out->_start,x);
}
void line3Du16_setStartX(line3Du16_t * out,uint16_t x){
  vec3u16_setX(out->_start,x);
}
void line3Di16_setStartX(line3Di16_t * out, int16_t x){
  vec3i16_setX(out->_start,x);
}
void line3Du32_setStartX(line3Du32_t * out, uint32_t x){
  vec3u32_setX(out->_start,x);
}
void line3Di32_setStartX(line3Di32_t * out, int32_t x){
  vec3i32_setX(out->_start,x);
}
void line3Du64_setStartX(line3Du64_t * out, uint64_t x){
  vec3u64_setX(out->_start,x);
}
void line3Di64_setStartX(line3Di64_t * out, uint64_t x){
  vec3i64_setX(out->_start,x);
}
void line3Df_setStartX(line3Df_t * out, float x){
  vec3f_setX(out->_start,x);
}
void line3Dd_setStartX(line3Dd_t * out, double x){
  vec3d_setX(out->_start,x);
}

void line4Du8_setStartX(line4Du8_t * out, uint8_t x){
  vec4u8_setX(out->_start,x);
}
void line4Di8_setStartX(line4Di8_t * out, int8_t x){
  vec4i8_setX(out->_start,x);
}
void line4Du16_setStartX(line4Du16_t * out,uint16_t x){
  vec4u16_setX(out->_start,x);
}
void line4Di16_setStartX(line4Di16_t * out, int16_t x){
  vec4i16_setX(out->_start,x);
}
void line4Du32_setStartX(line4Du32_t * out, uint32_t x){
  vec4u32_setX(out->_start,x);
}
void line4Di32_setStartX(line4Di32_t * out, int32_t x){
  vec4i32_setX(out->_start,x);
}
void line4Du64_setStartX(line4Du64_t * out, uint64_t x){
  vec4u64_setX(out->_start,x);
}
void line4Di64_setStartX(line4Di64_t * out, uint64_t x){
  vec4i64_setX(out->_start,x);
}
void line4Df_setStartX(line4Df_t * out, float x){
  vec4f_setX(out->_start,x);
}
void line4Dd_setStartX(line4Dd_t * out, double x){
  vec4d_setX(out->_start,x);
}



/**
* Set Start Y
**/


void line2Du8_setStartY(line2Du8_t * out, uint8_t x){
  vec2u8_setY(out->_start,x);
}
void line2Di8_setStartY(line2Di8_t * out, int8_t x){
  vec2i8_setY(out->_start,x);
}
void line2Du16_setStartY(line2Du16_t * out,uint16_t x){
  vec2u16_setY(out->_start,x);
}
void line2Di16_setStartY(line2Di16_t * out, int16_t x){
  vec2i16_setY(out->_start,x);
}
void line2Du32_setStartY(line2Du32_t * out, uint32_t x){
  vec2u32_setY(out->_start,x);
}
void line2Di32_setStartY(line2Di32_t * out, int32_t x){
  vec2i32_setY(out->_start,x);
}
void line2Du64_setStartY(line2Du64_t * out, uint64_t x){
  vec2u64_setY(out->_start,x);
}
void line2Di64_setStartY(line2Di64_t * out, uint64_t x){
  vec2i64_setY(out->_start,x);
}
void line2Df_setStartY(line2Df_t * out, float x){
  vec2f_setY(out->_start,x);
}
void line2Dd_setStartY(line2Dd_t * out, double x){
  vec2d_setY(out->_start,x);
}


void line3Du8_setStartY(line3Du8_t * out, uint8_t x){
  vec3u8_setY(out->_start,x);
}
void line3Di8_setStartY(line3Di8_t * out, int8_t x){
  vec3i8_setY(out->_start,x);
}
void line3Du16_setStartY(line3Du16_t * out,uint16_t x){
  vec3u16_setY(out->_start,x);
}
void line3Di16_setStartY(line3Di16_t * out, int16_t x){
  vec3i16_setY(out->_start,x);
}
void line3Du32_setStartY(line3Du32_t * out, uint32_t x){
  vec3u32_setY(out->_start,x);
}
void line3Di32_setStartY(line3Di32_t * out, int32_t x){
  vec3i32_setY(out->_start,x);
}
void line3Du64_setStartY(line3Du64_t * out, uint64_t x){
  vec3u64_setY(out->_start,x);
}
void line3Di64_setStartY(line3Di64_t * out, uint64_t x){
  vec3i64_setY(out->_start,x);
}
void line3Df_setStartY(line3Df_t * out, float x){
  vec3f_setY(out->_start,x);
}
void line3Dd_setStartY(line3Dd_t * out, double x){
  vec3d_setY(out->_start,x);
}

void line4Du8_setStartY(line4Du8_t * out, uint8_t x){
  vec4u8_setY(out->_start,x);
}
void line4Di8_setStartY(line4Di8_t * out, int8_t x){
  vec4i8_setY(out->_start,x);
}
void line4Du16_setStartY(line4Du16_t * out,uint16_t x){
  vec4u16_setY(out->_start,x);
}
void line4Di16_setStartY(line4Di16_t * out, int16_t x){
  vec4i16_setY(out->_start,x);
}
void line4Du32_setStartY(line4Du32_t * out, uint32_t x){
  vec4u32_setY(out->_start,x);
}
void line4Di32_setStartY(line4Di32_t * out, int32_t x){
  vec4i32_setY(out->_start,x);
}
void line4Du64_setStartY(line4Du64_t * out, uint64_t x){
  vec4u64_setY(out->_start,x);
}
void line4Di64_setStartY(line4Di64_t * out, uint64_t x){
  vec4i64_setY(out->_start,x);
}
void line4Df_setStartY(line4Df_t * out, float x){
  vec4f_setY(out->_start,x);
}
void line4Dd_setStartY(line4Dd_t * out, double x){
  vec4d_setY(out->_start,x);
}


/**
* Set Start Z
**/


void line3Du8_setStartZ(line3Du8_t * out, uint8_t x){
  vec3u8_setZ(out->_start,x);
}
void line3Di8_setStartZ(line3Di8_t * out, int8_t x){
  vec3i8_setZ(out->_start,x);
}
void line3Du16_setStartZ(line3Du16_t * out,uint16_t x){
  vec3u16_setZ(out->_start,x);
}
void line3Di16_setStartZ(line3Di16_t * out, int16_t x){
  vec3i16_setZ(out->_start,x);
}
void line3Du32_setStartZ(line3Du32_t * out, uint32_t x){
  vec3u32_setZ(out->_start,x);
}
void line3Di32_setStartZ(line3Di32_t * out, int32_t x){
  vec3i32_setZ(out->_start,x);
}
void line3Du64_setStartZ(line3Du64_t * out, uint64_t x){
  vec3u64_setZ(out->_start,x);
}
void line3Di64_setStartZ(line3Di64_t * out, uint64_t x){
  vec3i64_setZ(out->_start,x);
}
void line3Df_setStartZ(line3Df_t * out, float x){
  vec3f_setZ(out->_start,x);
}
void line3Dd_setStartZ(line3Dd_t * out, double x){
  vec3d_setZ(out->_start,x);
}

void line4Du8_setStartZ(line4Du8_t * out, uint8_t x){
  vec4u8_setZ(out->_start,x);
}
void line4Di8_setStartZ(line4Di8_t * out, int8_t x){
  vec4i8_setZ(out->_start,x);
}
void line4Du16_setStartZ(line4Du16_t * out,uint16_t x){
  vec4u16_setZ(out->_start,x);
}
void line4Di16_setStartZ(line4Di16_t * out, int16_t x){
  vec4i16_setZ(out->_start,x);
}
void line4Du32_setStartZ(line4Du32_t * out, uint32_t x){
  vec4u32_setZ(out->_start,x);
}
void line4Di32_setStartZ(line4Di32_t * out, int32_t x){
  vec4i32_setZ(out->_start,x);
}
void line4Du64_setStartZ(line4Du64_t * out, uint64_t x){
  vec4u64_setZ(out->_start,x);
}
void line4Di64_setStartZ(line4Di64_t * out, uint64_t x){
  vec4i64_setZ(out->_start,x);
}
void line4Df_setStartZ(line4Df_t * out, float x){
  vec4f_setZ(out->_start,x);
}
void line4Dd_setStartZ(line4Dd_t * out, double x){
  vec4d_setZ(out->_start,x);
}


/**
* Set Start W
**/

void line4Du8_setStartW(line4Du8_t * out, uint8_t x){
  vec4u8_setW(out->_start,x);
}
void line4Di8_setStartW(line4Di8_t * out, int8_t x){
  vec4i8_setW(out->_start,x);
}
void line4Du16_setStartW(line4Du16_t * out,uint16_t x){
  vec4u16_setW(out->_start,x);
}
void line4Di16_setStartW(line4Di16_t * out, int16_t x){
  vec4i16_setW(out->_start,x);
}
void line4Du32_setStartW(line4Du32_t * out, uint32_t x){
  vec4u32_setW(out->_start,x);
}
void line4Di32_setStartW(line4Di32_t * out, int32_t x){
  vec4i32_setW(out->_start,x);
}
void line4Du64_setStartW(line4Du64_t * out, uint64_t x){
  vec4u64_setW(out->_start,x);
}
void line4Di64_setStartW(line4Di64_t * out, uint64_t x){
  vec4i64_setW(out->_start,x);
}
void line4Df_setStartW(line4Df_t * out, float x){
  vec4f_setW(out->_start,x);
}
void line4Dd_setStartW(line4Dd_t * out, double x){
  vec4d_setW(out->_start,x);
}




/**
* Set Start X
**/


void line2Du8_setEndX(line2Du8_t * out, uint8_t x){
  vec2u8_setX(out->_start,x);
}
void line2Di8_setEndX(line2Di8_t * out, int8_t x){
  vec2i8_setX(out->_start,x);
}
void line2Du16_setEndX(line2Du16_t * out,uint16_t x){
  vec2u16_setX(out->_start,x);
}
void line2Di16_setEndX(line2Di16_t * out, int16_t x){
  vec2i16_setX(out->_start,x);
}
void line2Du32_setEndX(line2Du32_t * out, uint32_t x){
  vec2u32_setX(out->_start,x);
}
void line2Di32_setEndX(line2Di32_t * out, int32_t x){
  vec2i32_setX(out->_start,x);
}
void line2Du64_setEndX(line2Du64_t * out, uint64_t x){
  vec2u64_setX(out->_start,x);
}
void line2Di64_setEndX(line2Di64_t * out, uint64_t x){
  vec2i64_setX(out->_start,x);
}
void line2Df_setEndX(line2Df_t * out, float x){
  vec2f_setX(out->_start,x);
}
void line2Dd_setEndX(line2Dd_t * out, double x){
  vec2d_setX(out->_start,x);
}


void line3Du8_setEndX(line3Du8_t * out, uint8_t x){
  vec3u8_setX(out->_start,x);
}
void line3Di8_setEndX(line3Di8_t * out, int8_t x){
  vec3i8_setX(out->_start,x);
}
void line3Du16_setEndX(line3Du16_t * out,uint16_t x){
  vec3u16_setX(out->_start,x);
}
void line3Di16_setEndX(line3Di16_t * out, int16_t x){
  vec3i16_setX(out->_start,x);
}
void line3Du32_setEndX(line3Du32_t * out, uint32_t x){
  vec3u32_setX(out->_start,x);
}
void line3Di32_setEndX(line3Di32_t * out, int32_t x){
  vec3i32_setX(out->_start,x);
}
void line3Du64_setEndX(line3Du64_t * out, uint64_t x){
  vec3u64_setX(out->_start,x);
}
void line3Di64_setEndX(line3Di64_t * out, uint64_t x){
  vec3i64_setX(out->_start,x);
}
void line3Df_setEndX(line3Df_t * out, float x){
  vec3f_setX(out->_start,x);
}
void line3Dd_setEndX(line3Dd_t * out, double x){
  vec3d_setX(out->_start,x);
}

void line4Du8_setEndX(line4Du8_t * out, uint8_t x){
  vec4u8_setX(out->_start,x);
}
void line4Di8_setEndX(line4Di8_t * out, int8_t x){
  vec4i8_setX(out->_start,x);
}
void line4Du16_setEndX(line4Du16_t * out,uint16_t x){
  vec4u16_setX(out->_start,x);
}
void line4Di16_setEndX(line4Di16_t * out, int16_t x){
  vec4i16_setX(out->_start,x);
}
void line4Du32_setEndX(line4Du32_t * out, uint32_t x){
  vec4u32_setX(out->_start,x);
}
void line4Di32_setEndX(line4Di32_t * out, int32_t x){
  vec4i32_setX(out->_start,x);
}
void line4Du64_setEndX(line4Du64_t * out, uint64_t x){
  vec4u64_setX(out->_start,x);
}
void line4Di64_setEndX(line4Di64_t * out, uint64_t x){
  vec4i64_setX(out->_start,x);
}
void line4Df_setEndX(line4Df_t * out, float x){
  vec4f_setX(out->_start,x);
}
void line4Dd_setEndX(line4Dd_t * out, double x){
  vec4d_setX(out->_start,x);
}


/**
* Set End Y
**/


void line2Du8_setEndY(line2Du8_t * out, uint8_t x){
  vec2u8_setY(out->_start,x);
}
void line2Di8_setEndY(line2Di8_t * out, int8_t x){
  vec2i8_setY(out->_start,x);
}
void line2Du16_setEndY(line2Du16_t * out,uint16_t x){
  vec2u16_setY(out->_start,x);
}
void line2Di16_setEndY(line2Di16_t * out, int16_t x){
  vec2i16_setY(out->_start,x);
}
void line2Du32_setEndY(line2Du32_t * out, uint32_t x){
  vec2u32_setY(out->_start,x);
}
void line2Di32_setEndY(line2Di32_t * out, int32_t x){
  vec2i32_setY(out->_start,x);
}
void line2Du64_setEndY(line2Du64_t * out, uint64_t x){
  vec2u64_setY(out->_start,x);
}
void line2Di64_setEndY(line2Di64_t * out, uint64_t x){
  vec2i64_setY(out->_start,x);
}
void line2Df_setEndY(line2Df_t * out, float x){
  vec2f_setY(out->_start,x);
}
void line2Dd_setEndY(line2Dd_t * out, double x){
  vec2d_setY(out->_start,x);
}


void line3Du8_setEndY(line3Du8_t * out, uint8_t x){
  vec3u8_setY(out->_start,x);
}
void line3Di8_setEndY(line3Di8_t * out, int8_t x){
  vec3i8_setY(out->_start,x);
}
void line3Du16_setEndY(line3Du16_t * out,uint16_t x){
  vec3u16_setY(out->_start,x);
}
void line3Di16_setEndY(line3Di16_t * out, int16_t x){
  vec3i16_setY(out->_start,x);
}
void line3Du32_setEndY(line3Du32_t * out, uint32_t x){
  vec3u32_setY(out->_start,x);
}
void line3Di32_setEndY(line3Di32_t * out, int32_t x){
  vec3i32_setY(out->_start,x);
}
void line3Du64_setEndY(line3Du64_t * out, uint64_t x){
  vec3u64_setY(out->_start,x);
}
void line3Di64_setEndY(line3Di64_t * out, uint64_t x){
  vec3i64_setY(out->_start,x);
}
void line3Df_setEndY(line3Df_t * out, float x){
  vec3f_setY(out->_start,x);
}
void line3Dd_setEndY(line3Dd_t * out, double x){
  vec3d_setY(out->_start,x);
}

void line4Du8_setEndY(line4Du8_t * out, uint8_t x){
  vec4u8_setY(out->_start,x);
}
void line4Di8_setEndY(line4Di8_t * out, int8_t x){
  vec4i8_setY(out->_start,x);
}
void line4Du16_setEndY(line4Du16_t * out,uint16_t x){
  vec4u16_setY(out->_start,x);
}
void line4Di16_setEndY(line4Di16_t * out, int16_t x){
  vec4i16_setY(out->_start,x);
}
void line4Du32_setEndY(line4Du32_t * out, uint32_t x){
  vec4u32_setY(out->_start,x);
}
void line4Di32_setEndY(line4Di32_t * out, int32_t x){
  vec4i32_setY(out->_start,x);
}
void line4Du64_setEndY(line4Du64_t * out, uint64_t x){
  vec4u64_setY(out->_start,x);
}
void line4Di64_setEndY(line4Di64_t * out, uint64_t x){
  vec4i64_setY(out->_start,x);
}
void line4Df_setEndY(line4Df_t * out, float x){
  vec4f_setY(out->_start,x);
}
void line4Dd_setEndY(line4Dd_t * out, double x){
  vec4d_setY(out->_start,x);
}



/**
* Set End Z
**/


void line3Du8_setEndZ(line3Du8_t * out, uint8_t x){
  vec3u8_setZ(out->_start,x);
}
void line3Di8_setEndZ(line3Di8_t * out, int8_t x){
  vec3i8_setZ(out->_start,x);
}
void line3Du16_setEndZ(line3Du16_t * out,uint16_t x){
  vec3u16_setZ(out->_start,x);
}
void line3Di16_setEndZ(line3Di16_t * out, int16_t x){
  vec3i16_setZ(out->_start,x);
}
void line3Du32_setEndZ(line3Du32_t * out, uint32_t x){
  vec3u32_setZ(out->_start,x);
}
void line3Di32_setEndZ(line3Di32_t * out, int32_t x){
  vec3i32_setZ(out->_start,x);
}
void line3Du64_setEndZ(line3Du64_t * out, uint64_t x){
  vec3u64_setZ(out->_start,x);
}
void line3Di64_setEndZ(line3Di64_t * out, uint64_t x){
  vec3i64_setZ(out->_start,x);
}
void line3Df_setEndZ(line3Df_t * out, float x){
  vec3f_setZ(out->_start,x);
}
void line3Dd_setEndZ(line3Dd_t * out, double x){
  vec3d_setZ(out->_start,x);
}

void line4Du8_setEndZ(line4Du8_t * out, uint8_t x){
  vec4u8_setZ(out->_start,x);
}
void line4Di8_setEndZ(line4Di8_t * out, int8_t x){
  vec4i8_setZ(out->_start,x);
}
void line4Du16_setEndZ(line4Du16_t * out,uint16_t x){
  vec4u16_setZ(out->_start,x);
}
void line4Di16_setEndZ(line4Di16_t * out, int16_t x){
  vec4i16_setZ(out->_start,x);
}
void line4Du32_setEndZ(line4Du32_t * out, uint32_t x){
  vec4u32_setZ(out->_start,x);
}
void line4Di32_setEndZ(line4Di32_t * out, int32_t x){
  vec4i32_setZ(out->_start,x);
}
void line4Du64_setEndZ(line4Du64_t * out, uint64_t x){
  vec4u64_setZ(out->_start,x);
}
void line4Di64_setEndZ(line4Di64_t * out, uint64_t x){
  vec4i64_setZ(out->_start,x);
}
void line4Df_setEndZ(line4Df_t * out, float x){
  vec4f_setZ(out->_start,x);
}
void line4Dd_setEndZ(line4Dd_t * out, double x){
  vec4d_setZ(out->_start,x);
}


/**
* Set End W
**/

void line4Du8_setEndW(line4Du8_t * out, uint8_t x){
  vec4u8_setW(out->_start,x);
}
void line4Di8_setEndW(line4Di8_t * out, int8_t x){
  vec4i8_setW(out->_start,x);
}
void line4Du16_setEndW(line4Du16_t * out,uint16_t x){
  vec4u16_setW(out->_start,x);
}
void line4Di16_setEndW(line4Di16_t * out, int16_t x){
  vec4i16_setW(out->_start,x);
}
void line4Du32_setEndW(line4Du32_t * out, uint32_t x){
  vec4u32_setW(out->_start,x);
}
void line4Di32_setEndW(line4Di32_t * out, int32_t x){
  vec4i32_setW(out->_start,x);
}
void line4Du64_setEndW(line4Du64_t * out, uint64_t x){
  vec4u64_setW(out->_start,x);
}
void line4Di64_setEndW(line4Di64_t * out, uint64_t x){
  vec4i64_setW(out->_start,x);
}
void line4Df_setEndW(line4Df_t * out, float x){
  vec4f_setW(out->_start,x);
}
void line4Dd_setEndW(line4Dd_t * out, double x){
  vec4d_setW(out->_start,x);
}
