#ifndef FOUNDATIONS_PHYSICS_LINE3_H_
#define FOUNDATIONS_PHYSICS_LINE3_H_

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
typedef struct line3Du8  line3Du8_t;
typedef struct line3Di8  line3Di8_t;
typedef struct line3Du16 line3Du16_t;
typedef struct line3Di16 line3Di16_t;
typedef struct line3Du32 line3Du32_t;
typedef struct line3Di32 line3Di32_t;
typedef struct line3Du64 line3Du64_t;
typedef struct line3Di64 line3Di64_t;
typedef struct line3Df   line3Df_t;
typedef struct line3Dd   line3Dd_t;
typedef struct line3Dld  line3Dld_t;

/* Error reporting (string from implementation) */
const char* line3_get_error_string(void);

/* Malloc / constructors */
line3Du8_t  * line3Du8_malloc(uint8_t type, uint8_t bx, uint8_t by,uint8_t bz, uint8_t ex, uint8_t ey, uint8_t ez);
line3Di8_t  * line3Di8_malloc(uint8_t type, int8_t bx, int8_t by, int8_t bz, int8_t ex, int8_t ey, int8_t ez);
line3Du16_t * line3Du16_malloc(uint8_t type, uint16_t bx, uint16_t by, uint16_t bz, uint16_t ex, uint16_t ey, uint16_t ez);
line3Di16_t * line3Di16_malloc(uint8_t type, int16_t bx, int16_t by, int16_t bz, int16_t ex, int16_t ey, int16_t ez);
line3Du32_t * line3Du32_malloc(uint8_t type, uint32_t bx, uint32_t by, uint32_t bz, uint32_t ex, uint32_t ey, uint32_t ez);
line3Di32_t * line3Di32_malloc(uint8_t type, int32_t bx, int32_t by, int32_t bz, int32_t ex, int32_t ey, int32_t ez);
line3Du64_t * line3Du64_malloc(uint8_t type, uint64_t bx, uint64_t by, uint64_t bz, uint64_t ex, uint64_t ey, uint64_t ez);
line3Di64_t * line3Di64_malloc(uint8_t type, int64_t bx, int64_t by, int64_t bz, int64_t ex, int64_t ey, int64_t ez);
line3Df_t   * line3Df_malloc(uint8_t type, float bx, float by,float bz, float ex, float ey, float ez);
line3Dd_t   * line3Dd_malloc(uint8_t type, double bx, double by, double bz, double ex, double ey, double ez);
line3Dld_t  * line3Dld_malloc(uint8_t type, long double bx, long double by, long double bz, long double ex, long double ey, long double ez);

/* Malloc from copy */
line3Du8_t  * line3Du8_copy(const line3Du8_t * copy);
line3Di8_t  * line3Di8_copy(const line3Di8_t * copy);
line3Du16_t * line3Du16_copy(const line3Du16_t * copy);
line3Di16_t * line3Di16_copy(const line3Di16_t * copy);
line3Du32_t * line3Du32_copy(const line3Du32_t * copy);
line3Di32_t * line3Di32_copy(const line3Di32_t * copy);
line3Du64_t * line3Du64_copy(const line3Du64_t * copy);
line3Di64_t * line3Di64_copy(const line3Di64_t * copy);
line3Df_t   * line3Df_copy(const line3Df_t * copy);
line3Dd_t   * line3Dd_copy(const line3Dd_t * copy);
line3Dld_t  * line3Dld_copy(const line3Dld_t * copy);

/* Move (transfer ownership) via pointer-to-pointer */
line3Du8_t  * line3Du8_memmove(line3Du8_t ** move);
line3Di8_t  * line3Di8_memmove(line3Di8_t ** move);
line3Du16_t * line3Du16_memmove(line3Du16_t ** move);
line3Di16_t * line3Di16_memmove(line3Di16_t ** move);
line3Du32_t * line3Du32_memmove(line3Du32_t ** move);
line3Di32_t * line3Di32_memmove(line3Di32_t ** move);
line3Du64_t * line3Du64_memmove(line3Du64_t ** move);
line3Di64_t * line3Di64_memmove(line3Di64_t ** move);
line3Df_t   * line3Df_memmove(line3Df_t ** move);
line3Dd_t   * line3Dd_memmove(line3Dd_t ** move);
line3Dld_t  * line3Dld_memmove(line3Dld_t ** move);

/* Free / destructors  */
void line3Du8_free(line3Du8_t * line);
void line3Di8_free(line3Di8_t * line);
void line3Du16_free(line3Du16_t * line);
void line3Di16_free(line3Di16_t * line);
void line3Du32_free(line3Du32_t * line);
void line3Di32_free(line3Di32_t * line);
void line3Du64_free(line3Du64_t * line);
void line3Di64_free(line3Di64_t * line);
void line3Df_free(line3Df_t * line);
void line3Dd_free(line3Dd_t * line);
void line3Dld_free(line3Dld_t * line);

/* Length functions (implementation returns double uniformly) */
double line3Du8_length(const line3Du8_t * line);
double line3Di8_length(const line3Di8_t * line);
double line3Du16_length(const line3Du16_t * line);
double line3Di16_length(const line3Di16_t * line);
double line3Du32_length(const line3Du32_t * line);
double line3Di32_length(const line3Di32_t * line);
double line3Du64_length(const line3Du64_t * line);
double line3Di64_length(const line3Di64_t * line);
double line3Df_length(const line3Df_t * line);
double line3Dd_length(const line3Dd_t * line);
double line3Dld_length(const line3Dld_t * line);

/* Getters (Start X / Start Y / End X / End Y) */
/* u8 */
uint8_t  line3Du8_getStartX(line3Du8_t * out);
uint8_t  line3Du8_getStartY(line3Du8_t * out);
uint8_t  line3Du8_getStartZ(line3Du8_t * out);
uint8_t  line3Du8_getEndX  (line3Du8_t * out);
uint8_t  line3Du8_getEndY  (line3Du8_t * out);
uint8_t  line3Du8_getEndZ  (line3Du8_t * out);

/* i8 */
int8_t   line3Di8_getStartX(line3Di8_t * out);
int8_t   line3Di8_getStartY(line3Di8_t * out);
int8_t   line3Di8_getStartZ(line3Di8_t * out);
int8_t   line3Di8_getEndX  (line3Di8_t * out);
int8_t   line3Di8_getEndY  (line3Di8_t * out);
int8_t   line3Di8_getEndZ  (line3Di8_t * out);

/* u16 */
uint16_t line3Du16_getStartX(line3Du16_t * out);
uint16_t line3Du16_getStartY(line3Du16_t * out);
uint16_t line3Du16_getStartZ(line3Du16_t * out);
uint16_t line3Du16_getEndX  (line3Du16_t * out);
uint16_t line3Du16_getEndY  (line3Du16_t * out);
uint16_t line3Du16_getEndZ  (line3Du16_t * out);

/* i16 */
int16_t  line3Di16_getStartX(line3Di16_t * out);
int16_t  line3Di16_getStartY(line3Di16_t * out);
int16_t  line3Di16_getStartZ(line3Di16_t * out);
int16_t  line3Di16_getEndX  (line3Di16_t * out);
int16_t  line3Di16_getEndY  (line3Di16_t * out);
int16_t  line3Di16_getEndZ  (line3Di16_t * out);

/* u32 */
uint32_t line3Du32_getStartX(line3Du32_t * out);
uint32_t line3Du32_getStartY(line3Du32_t * out);
uint32_t line3Du32_getStartZ(line3Du32_t * out);
uint32_t line3Du32_getEndX  (line3Du32_t * out);
uint32_t line3Du32_getEndY  (line3Du32_t * out);
uint32_t line3Du32_getEndZ  (line3Du32_t * out);

/* i32 */
int32_t  line3Di32_getStartX(line3Di32_t * out);
int32_t  line3Di32_getStartY(line3Di32_t * out);
int32_t  line3Di32_getStartZ(line3Di32_t * out);
int32_t  line3Di32_getEndX  (line3Di32_t * out);
int32_t  line3Di32_getEndY  (line3Di32_t * out);
int32_t  line3Di32_getEndZ  (line3Di32_t * out);

/* u64 */
uint64_t line3Du64_getStartX(line3Du64_t * out);
uint64_t line3Du64_getStartY(line3Du64_t * out);
uint64_t line3Du64_getStartZ(line3Du64_t * out);
uint64_t line3Du64_getEndX  (line3Du64_t * out);
uint64_t line3Du64_getEndY  (line3Du64_t * out);
uint64_t line3Du64_getEndZ  (line3Du64_t * out);

/* i64 (signed!) */
int64_t  line3Di64_getStartX(line3Di64_t * out);
int64_t  line3Di64_getStartY(line3Di64_t * out);
int64_t  line3Di64_getStartZ(line3Di64_t * out);
int64_t  line3Di64_getEndX  (line3Di64_t * out);
int64_t  line3Di64_getEndY  (line3Di64_t * out);
int64_t  line3Di64_getEndZ  (line3Di64_t * out);


/* float/double/long double */
float        line3Df_getStartX(line3Df_t * out);
float        line3Df_getStartY(line3Df_t * out);
float        line3Df_getStartZ(line3Df_t * out);
float        line3Df_getEndX  (line3Df_t * out);
float        line3Df_getEndY  (line3Df_t * out);
float        line3Df_getEndZ  (line3Df_t * out);


double       line3Dd_getStartX(line3Dd_t * out);
double       line3Dd_getStartY(line3Dd_t * out);
double       line3Dd_getStartZ(line3Dd_t * out);
double       line3Dd_getEndX  (line3Dd_t * out);
double       line3Dd_getEndY  (line3Dd_t * out);
double       line3Dd_getEndZ  (line3Dd_t * out);

long double  line3Dld_getStartX(line3Dld_t * out);
long double  line3Dld_getStartY(line3Dld_t * out);
long double  line3Dld_getStartZ(line3Dld_t * out);
long double  line3Dld_getEndX  (line3Dld_t * out);
long double  line3Dld_getEndY  (line3Dld_t * out);
long double  line3Dld_getEndZ  (line3Dld_t * out);

/* Setters (Start X/Y, End X/Y) — keep void (errors reported via line3_get_error_string) */
void line3Du8_setStartX(line3Du8_t * out, uint8_t x);
void line3Du8_setStartY(line3Du8_t * out, uint8_t y);
void line3Du8_setStartZ(line3Du8_t * out, uint8_t z);
void line3Du8_setEndX  (line3Du8_t * out, uint8_t x);
void line3Du8_setEndY  (line3Du8_t * out, uint8_t y);
void line3Du8_setEndZ  (line3Du8_t * out, uint8_t z);


void line3Di8_setStartX(line3Di8_t * out, int8_t x);
void line3Di8_setStartY(line3Di8_t * out, int8_t y);
void line3Di8_setStartZ(line3Di8_t * out, int8_t z);
void line3Di8_setEndX  (line3Di8_t * out, int8_t x);
void line3Di8_setEndY  (line3Di8_t * out, int8_t y);
void line3Di8_setEndZ  (line3Di8_t * out, int8_t z);


void line3Du16_setStartX(line3Du16_t * out, uint16_t x);
void line3Du16_setStartY(line3Du16_t * out, uint16_t y);
void line3Du16_setStartZ(line3Du16_t * out, uint16_t z);
void line3Du16_setEndX  (line3Du16_t * out, uint16_t x);
void line3Du16_setEndY  (line3Du16_t * out, uint16_t y);
void line3Du16_setEndZ  (line3Du16_t * out, uint16_t z);


void line3Di16_setStartX(line3Di16_t * out, int16_t x);
void line3Di16_setStartY(line3Di16_t * out, int16_t y);
void line3Di16_setStartZ(line3Di16_t * out, int16_t z);
void line3Di16_setEndX  (line3Di16_t * out, int16_t x);
void line3Di16_setEndY  (line3Di16_t * out, int16_t y);
void line3Di16_setEndZ  (line3Di16_t * out, int16_t z);


void line3Du32_setStartX(line3Du32_t * out, uint32_t x);
void line3Du32_setStartY(line3Du32_t * out, uint32_t y);
void line3Du32_setStartZ(line3Du32_t * out, uint32_t z);
void line3Du32_setEndX  (line3Du32_t * out, uint32_t x);
void line3Du32_setEndY  (line3Du32_t * out, uint32_t y);
void line3Du32_setEndZ  (line3Du32_t * out, uint32_t z);


void line3Di32_setStartX(line3Di32_t * out, int32_t x);
void line3Di32_setStartY(line3Di32_t * out, int32_t y);
void line3Di32_setStartZ(line3Di32_t * out, int32_t z);
void line3Di32_setEndX  (line3Di32_t * out, int32_t x);
void line3Di32_setEndY  (line3Di32_t * out, int32_t y);
void line3Di32_setEndZ  (line3Di32_t * out, int32_t z);


void line3Du64_setStartX(line3Du64_t * out, uint64_t x);
void line3Du64_setStartY(line3Du64_t * out, uint64_t y);
void line3Du64_setStartZ(line3Du64_t * out, uint64_t z);
void line3Du64_setEndX  (line3Du64_t * out, uint64_t x);
void line3Du64_setEndY  (line3Du64_t * out, uint64_t y);
void line3Du64_setEndZ  (line3Du64_t * out, uint64_t z);


void line3Di64_setStartX(line3Di64_t * out, int64_t x);
void line3Di64_setStartY(line3Di64_t * out, int64_t y);
void line3Di64_setStartZ(line3Di64_t * out, int64_t z);
void line3Di64_setEndX  (line3Di64_t * out, int64_t x);
void line3Di64_setEndY  (line3Di64_t * out, int64_t y);
void line3Di64_setEndZ  (line3Di64_t * out, int64_t z);


void line3Df_setStartX(line3Df_t * out, float x);
void line3Df_setStartY(line3Df_t * out, float y);
void line3Df_setStartZ(line3Df_t * out, float z);
void line3Df_setEndX  (line3Df_t * out, float x);
void line3Df_setEndY  (line3Df_t * out, float y);
void line3Df_setEndZ  (line3Df_t * out, float z);

void line3Dd_setStartX(line3Dd_t * out, double x);
void line3Dd_setStartY(line3Dd_t * out, double y);
void line3Dd_setStartZ(line3Dd_t * out, double z);
void line3Dd_setEndX  (line3Dd_t * out, double x);
void line3Dd_setEndY  (line3Dd_t * out, double y);
void line3Dd_setEndZ  (line3Dd_t * out, double z);


void line3Dld_setStartX(line3Dld_t * out, long double x);
void line3Dld_setStartY(line3Dld_t * out, long double y);
void line3Dld_setStartZ(line3Dld_t * out, long double z);
void line3Dld_setEndX  (line3Dld_t * out, long double x);
void line3Dld_setEndY  (line3Dld_t * out, long double y);
void line3Dld_setEndZ  (line3Dld_t * out, long double z);

/* Intersection tests */
bool line3Du8_intersects(line3Du8_t * first, line3Du8_t * second);
bool line3Di8_intersects(line3Di8_t * first, line3Di8_t * second);
bool line3Du16_intersects(line3Du16_t * first, line3Du16_t * second);
bool line3Di16_intersects(line3Di16_t * first, line3Di16_t * second);
bool line3Du32_intersects(line3Du32_t * first, line3Du32_t * second);
bool line3Di32_intersects(line3Di32_t * first, line3Di32_t * second);
bool line3Du64_intersects(line3Du64_t * first, line3Du64_t * second);
bool line3Di64_intersects(line3Di64_t * first, line3Di64_t * second);
bool line3Df_intersects(line3Df_t * first, line3Df_t * second);
bool line3Dd_intersects(line3Dd_t * first, line3Dd_t * second);
bool line3Dld_intersects(line3Dld_t * first, line3Dld_t * second);

/* String conversion functions */
char* line3Du8_toString(const line3Du8_t* line);
char* line3Di8_toString(const line3Di8_t* line);
char* line3Du16_toString(const line3Du16_t* line);
char* line3Di16_toString(const line3Di16_t* line);
char* line3Du32_toString(const line3Du32_t* line);
char* line3Di32_toString(const line3Di32_t* line);
char* line3Du64_toString(const line3Du64_t* line);
char* line3Di64_toString(const line3Di64_t* line);
char* line3Df_toString(const line3Df_t* line);
char* line3Dd_toString(const line3Dd_t* line);
char* line3Dld_toString(const line3Dld_t* line);

line3Du8_t* line3Du8_fromString(const char* str);
line3Di8_t* line3Di8_fromString(const char* str);
line3Du16_t* line3Du16_fromString(const char* str);
line3Di16_t* line3Di16_fromString(const char* str);
line3Du32_t* line3Du32_fromString(const char* str);
line3Di32_t* line3Di32_fromString(const char* str);
line3Du64_t* line3Du64_fromString(const char* str);
line3Di64_t* line3Di64_fromString(const char* str);
line3Df_t* line3Df_fromString(const char* str);
line3Dd_t* line3Dd_fromString(const char* str);
line3Dld_t* line3Dld_fromString(const char* str);


/* Translation functions */
void line3Du8_translate(line3Du8_t *line, uint8_t x, uint8_t y, uint8_t z);
void line3Du8_translateX(line3Du8_t *line, uint8_t x);
void line3Du8_translateY(line3Du8_t *line, uint8_t y);
void line3Du8_translateZ(line3Du8_t *line, uint8_t z);
void line3Du8_translateLine(line3Du8_t *outLine, const line3Du8_t *line);

void line3Di8_translate(line3Di8_t *line, int8_t x, int8_t y, int8_t z);
void line3Di8_translateX(line3Di8_t *line, int8_t x);
void line3Di8_translateY(line3Di8_t *line, int8_t y);
void line3Di8_translateZ(line3Di8_t *line, int8_t z);
void line3Di8_translateLine(line3Di8_t *outLine, const line3Di8_t *line);

void line3Du16_translate(line3Du16_t *line, uint16_t x, uint16_t y, uint16_t z);
void line3Du16_translateX(line3Du16_t *line, uint16_t x);
void line3Du16_translateY(line3Du16_t *line, uint16_t y);
void line3Du16_translateZ(line3Du16_t *line, uint16_t z);
void line3Du16_translateLine(line3Du16_t *outLine, const line3Du16_t *line);

void line3Di16_translate(line3Di16_t *line, int16_t x, int16_t y, int16_t z);
void line3Di16_translateX(line3Di16_t *line, int16_t x);
void line3Di16_translateY(line3Di16_t *line, int16_t y);
void line3Di16_translateZ(line3Di16_t *line, int16_t z);
void line3Di16_translateLine(line3Di16_t *outLine, const line3Di16_t *line);

void line3Du32_translate(line3Du32_t *line, uint32_t x, uint32_t y, uint32_t z);
void line3Du32_translateX(line3Du32_t *line, uint32_t x);
void line3Du32_translateY(line3Du32_t *line, uint32_t y);
void line3Du32_translateZ(line3Du32_t *line, uint32_t z);
void line3Du32_translateLine(line3Du32_t *outLine, const line3Du32_t *line);

void line3Di32_translate(line3Di32_t *line, int32_t x, int32_t y, int32_t z);
void line3Di32_translateX(line3Di32_t *line, int32_t x);
void line3Di32_translateY(line3Di32_t *line, int32_t y);
void line3Di32_translateZ(line3Di32_t *line, int32_t z);
void line3Di32_translateLine(line3Di32_t *outLine, const line3Di32_t *line);

void line3Du64_translate(line3Du64_t *line, uint64_t x, uint64_t y, uint64_t z);
void line3Du64_translateX(line3Du64_t *line, uint64_t x);
void line3Du64_translateY(line3Du64_t *line, uint64_t y);
void line3Du64_translateZ(line3Du64_t *line, uint64_t z);
void line3Du64_translateLine(line3Du64_t *outLine, const line3Du64_t *line);

void line3Di64_translate(line3Di64_t *line, int64_t x, int64_t y, int64_t z);
void line3Di64_translateX(line3Di64_t *line, int64_t x);
void line3Di64_translateY(line3Di64_t *line, int64_t y);
void line3Di64_translateZ(line3Di64_t *line, int64_t z);
void line3Di64_translateLine(line3Di64_t *outLine, const line3Di64_t *line);

void line3Df_translate(line3Df_t *line, float x, float y, float z);
void line3Df_translateX(line3Df_t *line, float x);
void line3Df_translateY(line3Df_t *line, float y);
void line3Df_translateZ(line3Df_t *line, float z);
void line3Df_translateLine(line3Df_t *outLine, const line3Df_t *line);

void line3Dd_translate(line3Dd_t *line, double x, double y, double z);
void line3Dd_translateX(line3Dd_t *line, double x);
void line3Dd_translateY(line3Dd_t *line, double y);
void line3Dd_translateZ(line3Dd_t *line, double z);
void line3Dd_translateLine(line3Dd_t *outLine, const line3Dd_t *line);

void line3Dld_translate(line3Dld_t *line, long double x, long double y, long double z);
void line3Dld_translateX(line3Dld_t *line, long double x);
void line3Dld_translateY(line3Dld_t *line, long double y);
void line3Dld_translateZ(line3Dld_t *line, long double z);
void line3Dld_translateLine(line3Dld_t *outLine, const line3Dld_t *line);


/* Serialization functions */

/* Array serialization/deserialization */
void line3Du8_toArray(const line3Du8_t *line, uint8_t arr[7]);
line3Du8_t *line3Du8_fromArray(const uint8_t arr[7]);

void line3Di8_toArray(const line3Di8_t *line, int8_t arr[7]);
line3Di8_t *line3Di8_fromArray(const int8_t arr[7]);

void line3Du16_toArray(const line3Du16_t *line, uint16_t arr[7]);
line3Du16_t *line3Du16_fromArray(const uint16_t arr[7]);

void line3Di16_toArray(const line3Di16_t *line, int16_t arr[7]);
line3Di16_t *line3Di16_fromArray(const int16_t arr[7]);

void line3Du32_toArray(const line3Du32_t *line, uint32_t arr[7]);
line3Du32_t *line3Du32_fromArray(const uint32_t arr[7]);

void line3Di32_toArray(const line3Di32_t *line, int32_t arr[7]);
line3Di32_t *line3Di32_fromArray(const int32_t arr[7]);

void line3Du64_toArray(const line3Du64_t *line, uint64_t arr[7]);
line3Du64_t *line3Du64_fromArray(const uint64_t arr[7]);

void line3Di64_toArray(const line3Di64_t *line, int64_t arr[7]);
line3Di64_t *line3Di64_fromArray(const int64_t arr[7]);

void line3Df_toArray(const line3Df_t *line, float arr[7]);
line3Df_t *line3Df_fromArray(const float arr[7]);

void line3Dd_toArray(const line3Dd_t *line, double arr[7]);
line3Dd_t *line3Dd_fromArray(const double arr[7]);

void line3Dld_toArray(const line3Dld_t *line, long double arr[7]);
line3Dld_t *line3Dld_fromArray(const long double arr[7]);

/* Byte serialization/deserialization (native byte order) */
size_t line3Du8_toBytes(const line3Du8_t *line, uint8_t *bytes);
line3Du8_t *line3Du8_fromBytes(const uint8_t *bytes);

size_t line3Di8_toBytes(const line3Di8_t *line, uint8_t *bytes);
line3Di8_t *line3Di8_fromBytes(const uint8_t *bytes);

size_t line3Du16_toBytes(const line3Du16_t *line, uint8_t *bytes);
line3Du16_t *line3Du16_fromBytes(const uint8_t *bytes);

size_t line3Di16_toBytes(const line3Di16_t *line, uint8_t *bytes);
line3Di16_t *line3Di16_fromBytes(const uint8_t *bytes);

size_t line3Du32_toBytes(const line3Du32_t *line, uint8_t *bytes);
line3Du32_t *line3Du32_fromBytes(const uint8_t *bytes);

size_t line3Di32_toBytes(const line3Di32_t *line, uint8_t *bytes);
line3Di32_t *line3Di32_fromBytes(const uint8_t *bytes);

size_t line3Du64_toBytes(const line3Du64_t *line, uint8_t *bytes);
line3Du64_t *line3Du64_fromBytes(const uint8_t *bytes);

size_t line3Di64_toBytes(const line3Di64_t *line, uint8_t *bytes);
line3Di64_t *line3Di64_fromBytes(const uint8_t *bytes);

size_t line3Df_toBytes(const line3Df_t *line, uint8_t *bytes);
line3Df_t *line3Df_fromBytes(const uint8_t *bytes);

size_t line3Dd_toBytes(const line3Dd_t *line, uint8_t *bytes);
line3Dd_t *line3Dd_fromBytes(const uint8_t *bytes);

size_t line3Dld_toBytes(const line3Dld_t *line, uint8_t *bytes);
line3Dld_t *line3Dld_fromBytes(const uint8_t *bytes);

/* Byte serialization/deserialization (little-endian) */
size_t line3Du8_toBytesLE(const line3Du8_t *line, uint8_t *bytes);
line3Du8_t *line3Du8_fromBytesLE(const uint8_t *bytes);

size_t line3Di8_toBytesLE(const line3Di8_t *line, uint8_t *bytes);
line3Di8_t *line3Di8_fromBytesLE(const uint8_t *bytes);

size_t line3Du16_toBytesLE(const line3Du16_t *line, uint8_t *bytes);
line3Du16_t *line3Du16_fromBytesLE(const uint8_t *bytes);

size_t line3Di16_toBytesLE(const line3Di16_t *line, uint8_t *bytes);
line3Di16_t *line3Di16_fromBytesLE(const uint8_t *bytes);

size_t line3Du32_toBytesLE(const line3Du32_t *line, uint8_t *bytes);
line3Du32_t *line3Du32_fromBytesLE(const uint8_t *bytes);

size_t line3Di32_toBytesLE(const line3Di32_t *line, uint8_t *bytes);
line3Di32_t *line3Di32_fromBytesLE(const uint8_t *bytes);

size_t line3Du64_toBytesLE(const line3Du64_t *line, uint8_t *bytes);
line3Du64_t *line3Du64_fromBytesLE(const uint8_t *bytes);

size_t line3Di64_toBytesLE(const line3Di64_t *line, uint8_t *bytes);
line3Di64_t *line3Di64_fromBytesLE(const uint8_t *bytes);

size_t line3Df_toBytesLE(const line3Df_t *line, uint8_t *bytes);
line3Df_t *line3Df_fromBytesLE(const uint8_t *bytes);

size_t line3Dd_toBytesLE(const line3Dd_t *line, uint8_t *bytes);
line3Dd_t *line3Dd_fromBytesLE(const uint8_t *bytes);

size_t line3Dld_toBytesLE(const line3Dld_t *line, uint8_t *bytes);
line3Dld_t *line3Dld_fromBytesLE(const uint8_t *bytes);


// getSize meta-function
size_t line3Du8_size(void);
size_t line3Di8_size(void);
size_t line3Du16_size(void);
size_t line3Di16_size(void);
size_t line3Du32_size(void);
size_t line3Di32_size(void);
size_t line3Du64_size(void);
size_t line3Di64_size(void);
size_t line3Df_size(void);
size_t line3Dd_size(void);
size_t line3Dld_size(void);

/* Vector extension functions */
#ifdef VEC3_DEFINED

/* Get/Set start/end positions as vec3 types */
vec3uint8_t * line3Du8_getStartPosVec3(line3Du8_t *line);
vec3uint8_t * line3Du8_getEndPosVec3(line3Du8_t *line);
void line3Du8_setStartPosVec3(line3Du8_t *line, const vec3uint8_t *vec);
void line3Du8_setEndPosVec3(line3Du8_t *line, const vec3uint8_t *vec);

vec3int8_t * line3Di8_getStartPosVec3(line3Di8_t *line);
vec3int8_t * line3Di8_getEndPosVec3(line3Di8_t *line);
void line3Di8_setStartPosVec3(line3Di8_t *line, const vec3int8_t *vec);
void line3Di8_setEndPosVec3(line3Di8_t *line, const vec3int8_t *vec);

vec3uint16_t * line3Du16_getStartPosVec3(line3Du16_t *line);
vec3uint16_t * line3Du16_getEndPosVec3(line3Du16_t *line);
void line3Du16_setStartPosVec3(line3Du16_t *line, const vec3uint16_t *vec);
void line3Du16_setEndPosVec3(line3Du16_t *line, const vec3uint16_t *vec);

vec3int16_t * line3Di16_getStartPosVec3(line3Di16_t *line);
vec3int16_t * line3Di16_getEndPosVec3(line3Di16_t *line);
void line3Di16_setStartPosVec3(line3Di16_t *line, const vec3int16_t *vec);
void line3Di16_setEndPosVec3(line3Di16_t *line, const vec3int16_t *vec);

vec3uint32_t * line3Du32_getStartPosVec3(line3Du32_t *line);
vec3uint32_t * line3Du32_getEndPosVec3(line3Du32_t *line);
void line3Du32_setStartPosVec3(line3Du32_t *line, const vec3uint32_t *vec);
void line3Du32_setEndPosVec3(line3Du32_t *line, const vec3uint32_t *vec);

vec3int32_t * line3Di32_getStartPosVec3(line3Di32_t *line);
vec3int32_t * line3Di32_getEndPosVec3(line3Di32_t *line);
void line3Di32_setStartPosVec3(line3Di32_t *line, const vec3int32_t *vec);
void line3Di32_setEndPosVec3(line3Di32_t *line, const vec3int32_t *vec);

vec3uint64_t * line3Du64_getStartPosVec3(line3Du64_t *line);
vec3uint64_t * line3Du64_getEndPosVec3(line3Du64_t *line);
void line3Du64_setStartPosVec3(line3Du64_t *line, const vec3uint64_t *vec);
void line3Du64_setEndPosVec3(line3Du64_t *line, const vec3uint64_t *vec);

vec3int64_t * line3Di64_getStartPosVec3(line3Di64_t *line);
vec3int64_t * line3Di64_getEndPosVec3(line3Di64_t *line);
void line3Di64_setStartPosVec3(line3Di64_t *line, const vec3int64_t *vec);
void line3Di64_setEndPosVec3(line3Di64_t *line, const vec3int64_t *vec);

vec3f_t * line3Df_getStartPosVec3(line3Df_t *line);
vec3f_t * line3Df_getEndPosVec3(line3Df_t *line);
void line3Df_setStartPosVec3(line3Df_t *line, const vec3f_t *vec);
void line3Df_setEndPosVec3(line3Df_t *line, const vec3f_t *vec);

vec3d_t * line3Dd_getStartPosVec3(line3Dd_t *line);
vec3d_t * line3Dd_getEndPosVec3(line3Dd_t *line);
void line3Dd_setStartPosVec3(line3Dd_t *line, const vec3d_t *vec);
void line3Dd_setEndPosVec3(line3Dd_t *line, const vec3d_t *vec);

vec3ld_t * line3Dld_getStartPosVec3(line3Dld_t *line);
vec3ld_t * line3Dld_getEndPosVec3(line3Dld_t *line);
void line3Dld_setStartPosVec3(line3Dld_t *line, const vec3ld_t *vec);
void line3Dld_setEndPosVec3(line3Dld_t *line, const vec3ld_t *vec);

#endif /* VEC3_DEFINED */


#endif /* FOUNDATIONS_PHYSICS_LINE2_H_ */
