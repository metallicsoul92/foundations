#ifndef FOUNDATIONS_PHYSICS_LINE2_H_
#define FOUNDATIONS_PHYSICS_LINE2_H_

/* standard headers */
#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

#ifndef STDBOOL_DEFINED
#include <stdbool.h>
#define STDBOOL_DEFINED 1
#endif

/* line types */
#ifndef DEFINE_LINE_TYPES
  #define LINE_TYPE_LINE 1
  #define LINE_TYPE_VECTOR 2
  #define DEFINE_LINE_TYPES
#endif

/* forward declarations (must match C struct tags) */
typedef struct line2Du8  line2Du8_t;
typedef struct line2Di8  line2Di8_t;
typedef struct line2Du16 line2Du16_t;
typedef struct line2Di16 line2Di16_t;
typedef struct line2Du32 line2Du32_t;
typedef struct line2Di32 line2Di32_t;
typedef struct line2Du64 line2Du64_t;
typedef struct line2Di64 line2Di64_t;
typedef struct line2Df   line2Df_t;
typedef struct line2Dd   line2Dd_t;
typedef struct line2Dld  line2Dld_t;

/* Error reporting (string from implementation) */
const char* line2_get_error_string(void);

/* Malloc / constructors */
line2Du8_t  * line2Du8_malloc(uint8_t type, uint8_t bx, uint8_t by, uint8_t ex, uint8_t ey);
line2Di8_t  * line2Di8_malloc(uint8_t type, int8_t bx, int8_t by, int8_t ex, int8_t ey);
line2Du16_t * line2Du16_malloc(uint8_t type, uint16_t bx, uint16_t by, uint16_t ex, uint16_t ey);
line2Di16_t * line2Di16_malloc(uint8_t type, int16_t bx, int16_t by, int16_t ex, int16_t ey);
line2Du32_t * line2Du32_malloc(uint8_t type, uint32_t bx, uint32_t by, uint32_t ex, uint32_t ey);
line2Di32_t * line2Di32_malloc(uint8_t type, int32_t bx, int32_t by, int32_t ex, int32_t ey);
line2Du64_t * line2Du64_malloc(uint8_t type, uint64_t bx, uint64_t by, uint64_t ex, uint64_t ey);
line2Di64_t * line2Di64_malloc(uint8_t type, int64_t bx, int64_t by, int64_t ex, int64_t ey);
line2Df_t   * line2Df_malloc(uint8_t type, float bx, float by, float ex, float ey);
line2Dd_t   * line2Dd_malloc(uint8_t type, double bx, double by, double ex, double ey);
line2Dld_t  * line2Dld_malloc(uint8_t type, long double bx, long double by, long double ex, long double ey);

/* Malloc from copy */
line2Du8_t  * line2Du8_copy(const line2Du8_t * copy);
line2Di8_t  * line2Di8_copy(const line2Di8_t * copy);
line2Du16_t * line2Du16_copy(const line2Du16_t * copy);
line2Di16_t * line2Di16_copy(const line2Di16_t * copy);
line2Du32_t * line2Du32_copy(const line2Du32_t * copy);
line2Di32_t * line2Di32_copy(const line2Di32_t * copy);
line2Du64_t * line2Du64_copy(const line2Du64_t * copy);
line2Di64_t * line2Di64_copy(const line2Di64_t * copy);
line2Df_t   * line2Df_copy(const line2Df_t * copy);
line2Dd_t   * line2Dd_copy(const line2Dd_t * copy);
line2Dld_t  * line2Dld_copy(const line2Dld_t * copy);

/* Move (transfer ownership) via pointer-to-pointer */
line2Du8_t  * line2Du8_memmove(line2Du8_t ** move);
line2Di8_t  * line2Di8_memmove(line2Di8_t ** move);
line2Du16_t * line2Du16_memmove(line2Du16_t ** move);
line2Di16_t * line2Di16_memmove(line2Di16_t ** move);
line2Du32_t * line2Du32_memmove(line2Du32_t ** move);
line2Di32_t * line2Di32_memmove(line2Di32_t ** move);
line2Du64_t * line2Du64_memmove(line2Du64_t ** move);
line2Di64_t * line2Di64_memmove(line2Di64_t ** move);
line2Df_t   * line2Df_memmove(line2Df_t ** move);
line2Dd_t   * line2Dd_memmove(line2Dd_t ** move);
line2Dld_t  * line2Dld_memmove(line2Dld_t ** move);

/* Free / destructors  */
void line2Du8_free(line2Du8_t * line);
void line2Di8_free(line2Di8_t * line);
void line2Du16_free(line2Du16_t * line);
void line2Di16_free(line2Di16_t * line);
void line2Du32_free(line2Du32_t * line);
void line2Di32_free(line2Di32_t * line);
void line2Du64_free(line2Du64_t * line);
void line2Di64_free(line2Di64_t * line);
void line2Df_free(line2Df_t * line);
void line2Dd_free(line2Dd_t * line);
void line2Dld_free(line2Dld_t * line);

/* Length functions (implementation returns double uniformly) */
double line2Du8_length(const line2Du8_t * line);
double line2Di8_length(const line2Di8_t * line);
double line2Du16_length(const line2Du16_t * line);
double line2Di16_length(const line2Di16_t * line);
double line2Du32_length(const line2Du32_t * line);
double line2Di32_length(const line2Di32_t * line);
double line2Du64_length(const line2Du64_t * line);
double line2Di64_length(const line2Di64_t * line);
double line2Df_length(const line2Df_t * line);
double line2Dd_length(const line2Dd_t * line);
double line2Dld_length(const line2Dld_t * line);

/* Getters (Start X / Start Y / End X / End Y) */
/* u8 */
uint8_t  line2Du8_getStartX(line2Du8_t * out);
uint8_t  line2Du8_getStartY(line2Du8_t * out);
uint8_t  line2Du8_getEndX  (line2Du8_t * out);
uint8_t  line2Du8_getEndY  (line2Du8_t * out);
/* i8 */
int8_t   line2Di8_getStartX(line2Di8_t * out);
int8_t   line2Di8_getStartY(line2Di8_t * out);
int8_t   line2Di8_getEndX  (line2Di8_t * out);
int8_t   line2Di8_getEndY  (line2Di8_t * out);
/* u16 */
uint16_t line2Du16_getStartX(line2Du16_t * out);
uint16_t line2Du16_getStartY(line2Du16_t * out);
uint16_t line2Du16_getEndX  (line2Du16_t * out);
uint16_t line2Du16_getEndY  (line2Du16_t * out);
/* i16 */
int16_t  line2Di16_getStartX(line2Di16_t * out);
int16_t  line2Di16_getStartY(line2Di16_t * out);
int16_t  line2Di16_getEndX  (line2Di16_t * out);
int16_t  line2Di16_getEndY  (line2Di16_t * out);
/* u32 */
uint32_t line2Du32_getStartX(line2Du32_t * out);
uint32_t line2Du32_getStartY(line2Du32_t * out);
uint32_t line2Du32_getEndX  (line2Du32_t * out);
uint32_t line2Du32_getEndY  (line2Du32_t * out);
/* i32 */
int32_t  line2Di32_getStartX(line2Di32_t * out);
int32_t  line2Di32_getStartY(line2Di32_t * out);
int32_t  line2Di32_getEndX  (line2Di32_t * out);
int32_t  line2Di32_getEndY  (line2Di32_t * out);
/* u64 */
uint64_t line2Du64_getStartX(line2Du64_t * out);
uint64_t line2Du64_getStartY(line2Du64_t * out);
uint64_t line2Du64_getEndX  (line2Du64_t * out);
uint64_t line2Du64_getEndY  (line2Du64_t * out);
/* i64 (signed!) */
int64_t  line2Di64_getStartX(line2Di64_t * out);
int64_t  line2Di64_getStartY(line2Di64_t * out);
int64_t  line2Di64_getEndX  (line2Di64_t * out);
int64_t  line2Di64_getEndY  (line2Di64_t * out);
/* float/double/long double */
float        line2Df_getStartX(line2Df_t * out);
float        line2Df_getStartY(line2Df_t * out);
float        line2Df_getEndX  (line2Df_t * out);
float        line2Df_getEndY  (line2Df_t * out);

double       line2Dd_getStartX(line2Dd_t * out);
double       line2Dd_getStartY(line2Dd_t * out);
double       line2Dd_getEndX  (line2Dd_t * out);
double       line2Dd_getEndY  (line2Dd_t * out);

long double  line2Dld_getStartX(line2Dld_t * out);
long double  line2Dld_getStartY(line2Dld_t * out);
long double  line2Dld_getEndX  (line2Dld_t * out);
long double  line2Dld_getEndY  (line2Dld_t * out);

/* Setters (Start X/Y, End X/Y) — keep void (errors reported via line2_get_error_string) */
void line2Du8_setStartX(line2Du8_t * out, uint8_t x);
void line2Du8_setStartY(line2Du8_t * out, uint8_t y);
void line2Du8_setEndX  (line2Du8_t * out, uint8_t x);
void line2Du8_setEndY  (line2Du8_t * out, uint8_t y);

void line2Di8_setStartX(line2Di8_t * out, int8_t x);
void line2Di8_setStartY(line2Di8_t * out, int8_t y);
void line2Di8_setEndX  (line2Di8_t * out, int8_t x);
void line2Di8_setEndY  (line2Di8_t * out, int8_t y);

void line2Du16_setStartX(line2Du16_t * out, uint16_t x);
void line2Du16_setStartY(line2Du16_t * out, uint16_t y);
void line2Du16_setEndX  (line2Du16_t * out, uint16_t x);
void line2Du16_setEndY  (line2Du16_t * out, uint16_t y);

void line2Di16_setStartX(line2Di16_t * out, int16_t x);
void line2Di16_setStartY(line2Di16_t * out, int16_t y);
void line2Di16_setEndX  (line2Di16_t * out, int16_t x);
void line2Di16_setEndY  (line2Di16_t * out, int16_t y);

void line2Du32_setStartX(line2Du32_t * out, uint32_t x);
void line2Du32_setStartY(line2Du32_t * out, uint32_t y);
void line2Du32_setEndX  (line2Du32_t * out, uint32_t x);
void line2Du32_setEndY  (line2Du32_t * out, uint32_t y);

void line2Di32_setStartX(line2Di32_t * out, int32_t x);
void line2Di32_setStartY(line2Di32_t * out, int32_t y);
void line2Di32_setEndX  (line2Di32_t * out, int32_t x);
void line2Di32_setEndY  (line2Di32_t * out, int32_t y);

void line2Du64_setStartX(line2Du64_t * out, uint64_t x);
void line2Du64_setStartY(line2Du64_t * out, uint64_t y);
void line2Du64_setEndX  (line2Du64_t * out, uint64_t x);
void line2Du64_setEndY  (line2Du64_t * out, uint64_t y);

void line2Di64_setStartX(line2Di64_t * out, int64_t x);
void line2Di64_setStartY(line2Di64_t * out, int64_t y);
void line2Di64_setEndX  (line2Di64_t * out, int64_t x);
void line2Di64_setEndY  (line2Di64_t * out, int64_t y);

void line2Df_setStartX(line2Df_t * out, float x);
void line2Df_setStartY(line2Df_t * out, float y);
void line2Df_setEndX  (line2Df_t * out, float x);
void line2Df_setEndY  (line2Df_t * out, float y);

void line2Dd_setStartX(line2Dd_t * out, double x);
void line2Dd_setStartY(line2Dd_t * out, double y);
void line2Dd_setEndX  (line2Dd_t * out, double x);
void line2Dd_setEndY  (line2Dd_t * out, double y);

void line2Dld_setStartX(line2Dld_t * out, long double x);
void line2Dld_setStartY(line2Dld_t * out, long double y);
void line2Dld_setEndX  (line2Dld_t * out, long double x);
void line2Dld_setEndY  (line2Dld_t * out, long double y);

/* Intersection tests */
bool line2Du8_intersects(line2Du8_t * first, line2Du8_t * second);
bool line2Di8_intersects(line2Di8_t * first, line2Di8_t * second);
bool line2Du16_intersects(line2Du16_t * first, line2Du16_t * second);
bool line2Di16_intersects(line2Di16_t * first, line2Di16_t * second);
bool line2Du32_intersects(line2Du32_t * first, line2Du32_t * second);
bool line2Di32_intersects(line2Di32_t * first, line2Di32_t * second);
bool line2Du64_intersects(line2Du64_t * first, line2Du64_t * second);
bool line2Di64_intersects(line2Di64_t * first, line2Di64_t * second);
bool line2Df_intersects(line2Df_t * first, line2Df_t * second);
bool line2Dd_intersects(line2Dd_t * first, line2Dd_t * second);
bool line2Dld_intersects(line2Dld_t * first, line2Dld_t * second);

/* String conversion functions */
char* line2Du8_toString(const line2Du8_t* line);
char* line2Di8_toString(const line2Di8_t* line);
char* line2Du16_toString(const line2Du16_t* line);
char* line2Di16_toString(const line2Di16_t* line);
char* line2Du32_toString(const line2Du32_t* line);
char* line2Di32_toString(const line2Di32_t* line);
char* line2Du64_toString(const line2Du64_t* line);
char* line2Di64_toString(const line2Di64_t* line);
char* line2Df_toString(const line2Df_t* line);
char* line2Dd_toString(const line2Dd_t* line);
char* line2Dld_toString(const line2Dld_t* line);

line2Du8_t* line2Du8_fromString(const char* str);
line2Di8_t* line2Di8_fromString(const char* str);
line2Du16_t* line2Du16_fromString(const char* str);
line2Di16_t* line2Di16_fromString(const char* str);
line2Du32_t* line2Du32_fromString(const char* str);
line2Di32_t* line2Di32_fromString(const char* str);
line2Du64_t* line2Du64_fromString(const char* str);
line2Di64_t* line2Di64_fromString(const char* str);
line2Df_t* line2Df_fromString(const char* str);
line2Dd_t* line2Dd_fromString(const char* str);
line2Dld_t* line2Dld_fromString(const char* str);


/* Translation functions */
void line2Du8_translate(line2Du8_t *line, uint8_t x, uint8_t y);
void line2Du8_translateX(line2Du8_t *line, uint8_t x);
void line2Du8_translateY(line2Du8_t *line, uint8_t y);
void line2Du8_translateLine(line2Du8_t *outLine, const line2Du8_t *line);

void line2Di8_translate(line2Di8_t *line, int8_t x, int8_t y);
void line2Di8_translateX(line2Di8_t *line, int8_t x);
void line2Di8_translateY(line2Di8_t *line, int8_t y);
void line2Di8_translateLine(line2Di8_t *outLine, const line2Di8_t *line);

void line2Du16_translate(line2Du16_t *line, uint16_t x, uint16_t y);
void line2Du16_translateX(line2Du16_t *line, uint16_t x);
void line2Du16_translateY(line2Du16_t *line, uint16_t y);
void line2Du16_translateLine(line2Du16_t *outLine, const line2Du16_t *line);

void line2Di16_translate(line2Di16_t *line, int16_t x, int16_t y);
void line2Di16_translateX(line2Di16_t *line, int16_t x);
void line2Di16_translateY(line2Di16_t *line, int16_t y);
void line2Di16_translateLine(line2Di16_t *outLine, const line2Di16_t *line);

void line2Du32_translate(line2Du32_t *line, uint32_t x, uint32_t y);
void line2Du32_translateX(line2Du32_t *line, uint32_t x);
void line2Du32_translateY(line2Du32_t *line, uint32_t y);
void line2Du32_translateLine(line2Du32_t *outLine, const line2Du32_t *line);

void line2Di32_translate(line2Di32_t *line, int32_t x, int32_t y);
void line2Di32_translateX(line2Di32_t *line, int32_t x);
void line2Di32_translateY(line2Di32_t *line, int32_t y);
void line2Di32_translateLine(line2Di32_t *outLine, const line2Di32_t *line);

void line2Du64_translate(line2Du64_t *line, uint64_t x, uint64_t y);
void line2Du64_translateX(line2Du64_t *line, uint64_t x);
void line2Du64_translateY(line2Du64_t *line, uint64_t y);
void line2Du64_translateLine(line2Du64_t *outLine, const line2Du64_t *line);

void line2Di64_translate(line2Di64_t *line, int64_t x, int64_t y);
void line2Di64_translateX(line2Di64_t *line, int64_t x);
void line2Di64_translateY(line2Di64_t *line, int64_t y);
void line2Di64_translateLine(line2Di64_t *outLine, const line2Di64_t *line);

void line2Df_translate(line2Df_t *line, float x, float y);
void line2Df_translateX(line2Df_t *line, float x);
void line2Df_translateY(line2Df_t *line, float y);
void line2Df_translateLine(line2Df_t *outLine, const line2Df_t *line);

void line2Dd_translate(line2Dd_t *line, double x, double y);
void line2Dd_translateX(line2Dd_t *line, double x);
void line2Dd_translateY(line2Dd_t *line, double y);
void line2Dd_translateLine(line2Dd_t *outLine, const line2Dd_t *line);

void line2Dld_translate(line2Dld_t *line, long double x, long double y);
void line2Dld_translateX(line2Dld_t *line, long double x);
void line2Dld_translateY(line2Dld_t *line, long double y);
void line2Dld_translateLine(line2Dld_t *outLine, const line2Dld_t *line);


/* Serialization functions */

/* Array serialization/deserialization */
void line2Du8_toArray(const line2Du8_t *line, uint8_t arr[5]);
line2Du8_t *line2Du8_fromArray(const uint8_t arr[5]);

void line2Di8_toArray(const line2Di8_t *line, int8_t arr[5]);
line2Di8_t *line2Di8_fromArray(const int8_t arr[5]);

void line2Du16_toArray(const line2Du16_t *line, uint16_t arr[5]);
line2Du16_t *line2Du16_fromArray(const uint16_t arr[5]);

void line2Di16_toArray(const line2Di16_t *line, int16_t arr[5]);
line2Di16_t *line2Di16_fromArray(const int16_t arr[5]);

void line2Du32_toArray(const line2Du32_t *line, uint32_t arr[5]);
line2Du32_t *line2Du32_fromArray(const uint32_t arr[5]);

void line2Di32_toArray(const line2Di32_t *line, int32_t arr[5]);
line2Di32_t *line2Di32_fromArray(const int32_t arr[5]);

void line2Du64_toArray(const line2Du64_t *line, uint64_t arr[5]);
line2Du64_t *line2Du64_fromArray(const uint64_t arr[5]);

void line2Di64_toArray(const line2Di64_t *line, int64_t arr[5]);
line2Di64_t *line2Di64_fromArray(const int64_t arr[5]);

void line2Df_toArray(const line2Df_t *line, float arr[5]);
line2Df_t *line2Df_fromArray(const float arr[5]);

void line2Dd_toArray(const line2Dd_t *line, double arr[5]);
line2Dd_t *line2Dd_fromArray(const double arr[5]);

void line2Dld_toArray(const line2Dld_t *line, long double arr[5]);
line2Dld_t *line2Dld_fromArray(const long double arr[5]);

/* Byte serialization/deserialization (native byte order) */
size_t line2Du8_toBytes(const line2Du8_t *line, uint8_t *bytes);
line2Du8_t *line2Du8_fromBytes(const uint8_t *bytes);

size_t line2Di8_toBytes(const line2Di8_t *line, uint8_t *bytes);
line2Di8_t *line2Di8_fromBytes(const uint8_t *bytes);

size_t line2Du16_toBytes(const line2Du16_t *line, uint8_t *bytes);
line2Du16_t *line2Du16_fromBytes(const uint8_t *bytes);

size_t line2Di16_toBytes(const line2Di16_t *line, uint8_t *bytes);
line2Di16_t *line2Di16_fromBytes(const uint8_t *bytes);

size_t line2Du32_toBytes(const line2Du32_t *line, uint8_t *bytes);
line2Du32_t *line2Du32_fromBytes(const uint8_t *bytes);

size_t line2Di32_toBytes(const line2Di32_t *line, uint8_t *bytes);
line2Di32_t *line2Di32_fromBytes(const uint8_t *bytes);

size_t line2Du64_toBytes(const line2Du64_t *line, uint8_t *bytes);
line2Du64_t *line2Du64_fromBytes(const uint8_t *bytes);

size_t line2Di64_toBytes(const line2Di64_t *line, uint8_t *bytes);
line2Di64_t *line2Di64_fromBytes(const uint8_t *bytes);

size_t line2Df_toBytes(const line2Df_t *line, uint8_t *bytes);
line2Df_t *line2Df_fromBytes(const uint8_t *bytes);

size_t line2Dd_toBytes(const line2Dd_t *line, uint8_t *bytes);
line2Dd_t *line2Dd_fromBytes(const uint8_t *bytes);

size_t line2Dld_toBytes(const line2Dld_t *line, uint8_t *bytes);
line2Dld_t *line2Dld_fromBytes(const uint8_t *bytes);

/* Byte serialization/deserialization (little-endian) */
size_t line2Du8_toBytesLE(const line2Du8_t *line, uint8_t *bytes);
line2Du8_t *line2Du8_fromBytesLE(const uint8_t *bytes);

size_t line2Di8_toBytesLE(const line2Di8_t *line, uint8_t *bytes);
line2Di8_t *line2Di8_fromBytesLE(const uint8_t *bytes);

size_t line2Du16_toBytesLE(const line2Du16_t *line, uint8_t *bytes);
line2Du16_t *line2Du16_fromBytesLE(const uint8_t *bytes);

size_t line2Di16_toBytesLE(const line2Di16_t *line, uint8_t *bytes);
line2Di16_t *line2Di16_fromBytesLE(const uint8_t *bytes);

size_t line2Du32_toBytesLE(const line2Du32_t *line, uint8_t *bytes);
line2Du32_t *line2Du32_fromBytesLE(const uint8_t *bytes);

size_t line2Di32_toBytesLE(const line2Di32_t *line, uint8_t *bytes);
line2Di32_t *line2Di32_fromBytesLE(const uint8_t *bytes);

size_t line2Du64_toBytesLE(const line2Du64_t *line, uint8_t *bytes);
line2Du64_t *line2Du64_fromBytesLE(const uint8_t *bytes);

size_t line2Di64_toBytesLE(const line2Di64_t *line, uint8_t *bytes);
line2Di64_t *line2Di64_fromBytesLE(const uint8_t *bytes);

size_t line2Df_toBytesLE(const line2Df_t *line, uint8_t *bytes);
line2Df_t *line2Df_fromBytesLE(const uint8_t *bytes);

size_t line2Dd_toBytesLE(const line2Dd_t *line, uint8_t *bytes);
line2Dd_t *line2Dd_fromBytesLE(const uint8_t *bytes);

size_t line2Dld_toBytesLE(const line2Dld_t *line, uint8_t *bytes);
line2Dld_t *line2Dld_fromBytesLE(const uint8_t *bytes);



/* Vector extension functions */
#ifdef VEC2_DEFINED

/* Get/Set start/end positions as vec2 types */
vec2uint8_t * line2Du8_getStartPosVec2(line2Du8_t *line);
vec2uint8_t * line2Du8_getEndPosVec2(line2Du8_t *line);
void line2Du8_setStartPosVec2(line2Du8_t *line, const vec2uint8_t *vec);
void line2Du8_setEndPosVec2(line2Du8_t *line, const vec2uint8_t *vec);

vec2int8_t * line2Di8_getStartPosVec2(line2Di8_t *line);
vec2int8_t * line2Di8_getEndPosVec2(line2Di8_t *line);
void line2Di8_setStartPosVec2(line2Di8_t *line, const vec2int8_t *vec);
void line2Di8_setEndPosVec2(line2Di8_t *line, const vec2int8_t *vec);

vec2uint16_t * line2Du16_getStartPosVec2(line2Du16_t *line);
vec2uint16_t * line2Du16_getEndPosVec2(line2Du16_t *line);
void line2Du16_setStartPosVec2(line2Du16_t *line, const vec2uint16_t *vec);
void line2Du16_setEndPosVec2(line2Du16_t *line, const vec2uint16_t *vec);

vec2int16_t * line2Di16_getStartPosVec2(line2Di16_t *line);
vec2int16_t * line2Di16_getEndPosVec2(line2Di16_t *line);
void line2Di16_setStartPosVec2(line2Di16_t *line, const vec2int16_t *vec);
void line2Di16_setEndPosVec2(line2Di16_t *line, const vec2int16_t *vec);

vec2uint32_t * line2Du32_getStartPosVec2(line2Du32_t *line);
vec2uint32_t * line2Du32_getEndPosVec2(line2Du32_t *line);
void line2Du32_setStartPosVec2(line2Du32_t *line, const vec2uint32_t *vec);
void line2Du32_setEndPosVec2(line2Du32_t *line, const vec2uint32_t *vec);

vec2int32_t * line2Di32_getStartPosVec2(line2Di32_t *line);
vec2int32_t * line2Di32_getEndPosVec2(line2Di32_t *line);
void line2Di32_setStartPosVec2(line2Di32_t *line, const vec2int32_t *vec);
void line2Di32_setEndPosVec2(line2Di32_t *line, const vec2int32_t *vec);

vec2uint64_t * line2Du64_getStartPosVec2(line2Du64_t *line);
vec2uint64_t * line2Du64_getEndPosVec2(line2Du64_t *line);
void line2Du64_setStartPosVec2(line2Du64_t *line, const vec2uint64_t *vec);
void line2Du64_setEndPosVec2(line2Du64_t *line, const vec2uint64_t *vec);

vec2int64_t * line2Di64_getStartPosVec2(line2Di64_t *line);
vec2int64_t * line2Di64_getEndPosVec2(line2Di64_t *line);
void line2Di64_setStartPosVec2(line2Di64_t *line, const vec2int64_t *vec);
void line2Di64_setEndPosVec2(line2Di64_t *line, const vec2int64_t *vec);

vec2f_t * line2Df_getStartPosVec2(line2Df_t *line);
vec2f_t * line2Df_getEndPosVec2(line2Df_t *line);
void line2Df_setStartPosVec2(line2Df_t *line, const vec2f_t *vec);
void line2Df_setEndPosVec2(line2Df_t *line, const vec2f_t *vec);

vec2d_t * line2Dd_getStartPosVec2(line2Dd_t *line);
vec2d_t * line2Dd_getEndPosVec2(line2Dd_t *line);
void line2Dd_setStartPosVec2(line2Dd_t *line, const vec2d_t *vec);
void line2Dd_setEndPosVec2(line2Dd_t *line, const vec2d_t *vec);

vec2ld_t * line2Dld_getStartPosVec2(line2Dld_t *line);
vec2ld_t * line2Dld_getEndPosVec2(line2Dld_t *line);
void line2Dld_setStartPosVec2(line2Dld_t *line, const vec2ld_t *vec);
void line2Dld_setEndPosVec2(line2Dld_t *line, const vec2ld_t *vec);

#endif /* VEC2_DEFINED */

#endif /* FOUNDATIONS_PHYSICS_LINE2_H_ */
