#ifndef FOUNDATIONS_MATH_PRIV_TYPES_H_
#define FOUNDATIONS_MATH_PRIV_TYPES_H_

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

#ifdef DEFINE_ALL_VEC2
struct vector2int8{
  int8_t _x;
  int8_t _y;
};
struct vector2uint8{
  uint8_t _x;
  uint8_t _y;
};
struct vector2int16{
  int16_t _x;
  int16_t _y;
};
struct vector2uint16{
  uint16_t _x;
  uint16_t _y;
};
struct vector2int32{
  int32_t _x;
  int32_t _y;
};
struct vector2uint32{
  uint32_t _x;
  uint32_t _y;
};
struct vector2int64{
  int64_t _x;
  int64_t _y;
};
struct vector2uint64{
  uint64_t _x;
  uint64_t _y;
};
struct vector2char{
  char _x;
  char _y;
};
struct vector2float{
  float _x;
  float _y;
};
struct vector2double{
  double _x;
  double _y;
};
#endif

#ifdef DEFINE_ALL_VEC3
struct vector3int8{
  int8_t _x;
  int8_t _y;
  int8_t _z;
};
struct vector3uint8{
  uint8_t _x;
  uint8_t _y;
  uint8_t _z;
};
struct vector3int16{
  int16_t _x;
  int16_t _y;
  int16_t _z;
};
struct vector3uint16{
  uint16_t _x;
  uint16_t _y;
  uint16_t _z;
};
struct vector3int32{
  int32_t _x;
  int32_t _y;
  int32_t _z;
};
struct vector3uint32{
  uint32_t _x;
  uint32_t _y;
  uint32_t _z;
};
struct vector3int64{
  int64_t _x;
  int64_t _y;
  int64_t _z;
};
struct vector3uint64{
  uint64_t _x;
  uint64_t _y;
  uint64_t _z;
};
struct vector3char{
  char _x;
  char _y;
  char _z;
};
struct vector3float{
  float _x;
  float _y;
  float _z;
};
struct vector3double{
  double _x;
  double _y;
  double _z;
};
#endif

#ifdef DEFINE_ALL_VEC4
struct vector4int8{
  int8_t _x;
  int8_t _y;
  int8_t _z;
  int8_t _w;
};
struct vector4uint8{
  uint8_t _x;
  uint8_t _y;
  uint8_t _z;
  uint8_t _w;
};
struct vector4int16{
  int16_t _x;
  int16_t _y;
  int16_t _z;
  int16_t _w;
};
struct vector4uint16{
  uint16_t _x;
  uint16_t _y;
  uint16_t _z;
  uint16_t _w;
};
struct vector4int32{
  int32_t _x;
  int32_t _y;
  int32_t _z;
  int32_t _w;
};
struct vector4uint32{
  uint32_t _x;
  uint32_t _y;
  uint32_t _z;
  uint32_t _w;
};
struct vector4int64{
  int64_t _x;
  int64_t _y;
  int64_t _z;
  int64_t _w;
};
struct vector4uint64{
  uint64_t _x;
  uint64_t _y;
  uint64_t _z;
  uint64_t _w;
};
struct vector4char{
  char _x;
  char _y;
  char _z;
  char _w;
};
struct vector4float{
  float _x;
  float _y;
  float _z;
  float _w;
};
struct vector4double{
  double _x;
  double _y;
  double _z;
  double _w;
};
#endif

#endif
