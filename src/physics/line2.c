#include "../../include/physics/line2.h"
#include "../../include/math/vec2.h"

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
/* ---------------------------
   Error handling (internal)
   --------------------------- */
typedef enum {
    LINE2_SUCCESS = 0,
    LINE2_ERROR_MALLOC_FAILED,
    LINE2_ERROR_OVERFLOW,
    LINE2_ERROR_INVALID_DIMENSIONS,
    LINE2_ERROR_ZERO_LENGTH,
    LINE2_ERROR_NULL_POINTER,
    LINE2_ERROR_UNKNOWN
} line2_error_t;

/* global error state */
static line2_error_t line2_last_error = LINE2_SUCCESS;
static const char *line2_error_string = NULL;

static const char *LINE2_ERROR_STRINGS[] = {
    "Success",
    "Memory allocation failed",
    "Line would cause coordinate overflow",
    "Invalid dimensions provided",
    "Zero-length line (start == end)",
    "Null pointer supplied",
    "Unknown error"
};

const char* line2_get_error_string(void) {
    if (line2_error_string != NULL) return line2_error_string;
    size_t idx = (size_t) line2_last_error;
    if (idx < (sizeof(LINE2_ERROR_STRINGS)/sizeof(*LINE2_ERROR_STRINGS))) {
        return LINE2_ERROR_STRINGS[idx];
    }
    return "Invalid error code";
}

/* internal helpers to set/clear errors */
static void line2_clear_error(void) {
    line2_last_error = LINE2_SUCCESS;
    line2_error_string = NULL;
}
static void line2_set_error(line2_error_t e, const char *custom) {
    line2_last_error = e;
    line2_error_string = custom;
}


/* Helper function to trim whitespace from both ends of a string */
static char* trim_whitespace(char* str) {
    if (!str) return NULL;

    char* end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    if (*str == 0)  // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator
    *(end + 1) = '\0';

    return str;
}




/* ---------------------------
   Concrete struct definitions
   --------------------------- */

struct line2Du8  {
  uint8_t   _type;
  uint8_t   _startX,_startY,_endX,_endY;
};
struct line2Di8  {
  uint8_t   _type;
  int8_t    _startX,_startY,_endX,_endY;
};
struct line2Du16 {
  uint8_t   _type;
  uint16_t  _startX,_startY,_endX,_endY;
};
struct line2Di16 {
  uint8_t   _type;
  int16_t   _startX,_startY,_endX,_endY;
};
struct line2Du32 {
  uint8_t   _type;
  uint32_t  _startX,_startY,_endX,_endY;
};
struct line2Di32 {
  uint8_t   _type;
  int32_t   _startX,_startY,_endX,_endY;
};
struct line2Du64 {
  uint8_t   _type;
  uint64_t  _startX,_startY,_endX,_endY;
};
struct line2Di64 {
  uint8_t   _type;
  int64_t   _startX,_startY,_endX,_endY;
};
struct line2Df   {
  uint8_t   _type;
  float     _startX,_startY,_endX,_endY;
};
struct line2Dd   {
  uint8_t   _type;
  double    _startX,_startY,_endX,_endY;
};
struct line2Dld  {
  uint8_t   _type;
  long double _startX,_startY,_endX,_endY;
};

/* ---------------------------
   Generic math helpers (long double-based to reduce overflow risk)
   --------------------------- */

/* Compute Euclidean length using long double then return double */
static double compute_length_ld_longdouble(long double sx, long double sy, long double ex, long double ey) {
    long double dx = ex - sx;
    long double dy = ey - sy;
    long double sum = dx*dx + dy*dy;
    long double r = sqrtl(sum);
    return (double) r;
}

/* Orientation test: returns 0 = colinear, 1 = clockwise, 2 = counterclockwise
   Uses long double arithmetic and is type-agnostic when coordinates are cast to long double. */
static int orientation_ld(long double ax, long double ay, long double bx, long double by, long double cx, long double cy) {
    long double val = (by - ay) * (cx - bx) - (bx - ax) * (cy - by);
    if (fabsl(val) < 1e-18L) return 0;
    return (val > 0) ? 1 : 2;
}

/* Check whether point C (cx,cy) lies on segment AB inclusive */
static bool on_segment_ld(long double ax, long double ay, long double bx, long double by, long double cx, long double cy) {
    long double minx = fminl(ax, bx), maxx = fmaxl(ax, bx);
    long double miny = fminl(ay, by), maxy = fmaxl(ay, by);
    return (cx >= minx - 1e-18L && cx <= maxx + 1e-18L &&
            cy >= miny - 1e-18L && cy <= maxy + 1e-18L);
}

/* General segment intersection test using long double arithmetic */
static bool segments_intersect_ld(long double a1x,long double a1y,long double a2x,long double a2y,
                                  long double b1x,long double b1y,long double b2x,long double b2y)
{
    int o1 = orientation_ld(a1x,a1y,a2x,a2y,b1x,b1y);
    int o2 = orientation_ld(a1x,a1y,a2x,a2y,b2x,b2y);
    int o3 = orientation_ld(b1x,b1y,b2x,b2y,a1x,a1y);
    int o4 = orientation_ld(b1x,b1y,b2x,b2y,a2x,a2y);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && on_segment_ld(a1x,a1y,a2x,a2y,b1x,b1y)) return true;
    if (o2 == 0 && on_segment_ld(a1x,a1y,a2x,a2y,b2x,b2y)) return true;
    if (o3 == 0 && on_segment_ld(b1x,b1y,b2x,b2y,a1x,a1y)) return true;
    if (o4 == 0 && on_segment_ld(b1x,b1y,b2x,b2y,a2x,a2y)) return true;

    return false;
}

/* ---------------------------
   Implementations for each concrete type
   --------------------------- */

/* --- u8 --- */
line2Du8_t * line2Du8_malloc(uint8_t type, uint8_t bx, uint8_t by, uint8_t ex, uint8_t ey) {
    line2_clear_error();
    if (bx == ex && by == ey) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return NULL;
    }
    line2Du8_t *out = (line2Du8_t*) malloc(sizeof(line2Du8_t));
    if (!out) { line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
      return NULL;
    }
    out->_type = type; out->_startX = bx; out->_startY = by; out->_endX = ex; out->_endY = ey;
    line2_clear_error();
    return out;
}

line2Du8_t * line2Du8_copy(const line2Du8_t *copy) {
    line2_clear_error();
    if (!copy) { line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
       return NULL;
     }
    line2Du8_t *out = (line2Du8_t*) malloc(sizeof(line2Du8_t));
    if (!out) { line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
      return NULL;
    }
    memcpy(out, copy, sizeof(*out));
    return out;
}

line2Du8_t * line2Du8_memmove(line2Du8_t **move) {
    line2_clear_error();
    if (!move || !*move) { line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
      return NULL;
    }
    line2Du8_t *tmp = *move;
    *move = NULL;
    return tmp;
}

uint8_t line2Du8_getStartX(line2Du8_t *out) {
  if (!out) {
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  } line2_clear_error();
  return out->_startX;
}

uint8_t line2Du8_getStartY(line2Du8_t *out) {
  if (!out) {
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  } line2_clear_error();
  return out->_startY;
}

uint8_t line2Du8_getEndX  (line2Du8_t *out) {
  if (!out) {
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  } line2_clear_error();
  return out->_endX;
}

uint8_t line2Du8_getEndY  (line2Du8_t *out) {
  if (!out) {
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  } line2_clear_error();
  return out->_endY;
}

void line2Du8_setStartX(line2Du8_t *out, uint8_t x) {
  if (!out) {
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if (x == out->_endX && out->_startY == out->_endY) {
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
    out->_startX = x;
    line2_clear_error();
}

void line2Du8_setStartY(line2Du8_t *out, uint8_t y) {
  if (!out) {
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if (out->_startX == out->_endX && y == out->_endY) {
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
    out->_startY = y;
    line2_clear_error();
}

void line2Du8_setEndX(line2Du8_t *out, uint8_t x) {
  if (!out) {
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if (x == out->_startX && out->_startY == out->_endY) {
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
    out->_endX = x;
    line2_clear_error();
}

void line2Du8_setEndY(line2Du8_t *out, uint8_t y) {
  if (!out) {
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if (out->_startX == out->_endX && y == out->_startY) {
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  out->_endY = y;
  line2_clear_error();
}

bool line2Du8_intersects(line2Du8_t *first, line2Du8_t *second) {
  if (!first || !second) {
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  long double a1x = first->_startX, a1y = first->_startY, a2x = first->_endX, a2y = first->_endY;
  long double b1x = second->_startX, b1y = second->_startY, b2x = second->_endX, b2y = second->_endY;
  bool res = segments_intersect_ld(a1x,a1y,a2x,a2y,b1x,b1y,b2x,b2y);
  line2_clear_error();
  return res;
}

double line2Du8_length(const line2Du8_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Du8_free(line2Du8_t *line) {
    free(line);
}

char* line2Du8_toString(const line2Du8_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    // Allocate enough space for the string representation
    // Format: "type startX startY endX endY"
    char* str = malloc(64);  // More than enough for u8 values
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 64, "%u %u %u %u %u",
             line->_type, line->_startX, line->_startY, line->_endX, line->_endY);

    line2_clear_error();
    return str;
}

line2Du8_t* line2Du8_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    // Make a copy we can modify
    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type, startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %hhu %hhu %hhu %hhu",
               &type, &startX, &startY, &endX, &endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Du8_malloc(type, startX, startY, endX, endY);
}

void line2Du8_translate(line2Du8_t *line, uint8_t x, uint8_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Du8_translateX(line2Du8_t *line, uint8_t x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Du8_translateY(line2Du8_t *line, uint8_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Du8_translateLine(line2Du8_t *outLine, const line2Du8_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}


/* --- i8 --- */
line2Di8_t * line2Di8_malloc(uint8_t type, int8_t bx, int8_t by, int8_t ex, int8_t ey) {
    line2_clear_error();
    if (bx == ex && by == ey) { line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
      return NULL;
    }
    line2Di8_t *out = (line2Di8_t*) malloc(sizeof(line2Di8_t));
    if (!out) { line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
      return NULL;
    }
    out->_type=type; out->_startX=bx; out->_startY=by; out->_endX=ex; out->_endY=ey;
    return out;
}

line2Di8_t * line2Di8_copy(const line2Di8_t *copy) {
    line2_clear_error();
    if (!copy) { line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
      return NULL;
    }
    line2Di8_t *out = (line2Di8_t*) malloc(sizeof(line2Di8_t));
    if (!out) { line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
      return NULL;
    }
    memcpy(out, copy, sizeof(*out));
    return out;
}

line2Di8_t * line2Di8_memmove(line2Di8_t **move) {
    line2_clear_error();
    if (!move || !*move) { line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
      return NULL;
    }
    line2Di8_t *tmp = *move;
    *move = NULL;
    return tmp;
}

int8_t line2Di8_getStartX(line2Di8_t *out) {
  if(!out){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return out->_startX;
}

int8_t line2Di8_getStartY(line2Di8_t *out) {
  if(!out){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }

  line2_clear_error();
  return out->_startY;
}

int8_t line2Di8_getEndX(line2Di8_t *out)   {
  if(!out){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return out->_endX;
}

int8_t line2Di8_getEndY(line2Di8_t *out)   {
  if(!out){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return out->_endY;
}

void line2Di8_setStartX(line2Di8_t *out, int8_t x){
  if(!out){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==out->_endX && out->_startY==out->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  out->_startX=x;
  line2_clear_error();
}

void line2Di8_setStartY(line2Di8_t *out, int8_t y){
  if(!out){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(out->_startX==out->_endX && y==out->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  out->_startY=y;
  line2_clear_error();
}

void line2Di8_setEndX(line2Di8_t *out, int8_t x){
  if(!out){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==out->_startX && out->_startY==out->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  out->_endX=x;
  line2_clear_error();
}

void line2Di8_setEndY(line2Di8_t *out, int8_t y){
  if(!out){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(out->_startX==out->_endX && y==out->_startY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  out->_endY=y;
  line2_clear_error();
}

bool line2Di8_intersects(line2Di8_t *first, line2Di8_t *second) {
  if(!first||!second){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  long double a1x=first->_startX,a1y=first->_startY,a2x=first->_endX,a2y=first->_endY;
  long double b1x=second->_startX,b1y=second->_startY,b2x=second->_endX,b2y=second->_endY;
  bool r = segments_intersect_ld(a1x,a1y,a2x,a2y,b1x,b1y,b2x,b2y);
  line2_clear_error();
  return r;
}

double line2Di8_length(const line2Di8_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Di8_free(line2Di8_t *line) {
    free(line);
}

char* line2Di8_toString(const line2Di8_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* str = malloc(64);
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 64, "%u %d %d %d %d",
             line->_type, line->_startX, line->_startY, line->_endX, line->_endY);

    line2_clear_error();
    return str;
}

line2Di8_t* line2Di8_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type;
    int8_t startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %hhd %hhd %hhd %hhd",
               &type, &startX, &startY, &endX, &endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Di8_malloc(type, startX, startY, endX, endY);
}

void line2Di8_translate(line2Di8_t *line, int8_t x, int8_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Di8_translateX(line2Di8_t *line, int8_t x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Di8_translateY(line2Di8_t *line, int8_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Di8_translateLine(line2Di8_t *outLine, const line2Di8_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}


/* --- u16 --- */
line2Du16_t * line2Du16_malloc(uint8_t type, uint16_t bx, uint16_t by, uint16_t ex, uint16_t ey) {
    line2_clear_error();
    if (bx==ex && by==ey) {
      line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
      return NULL;
    }
    line2Du16_t *out = malloc(sizeof(line2Du16_t));
    if (!out) {
      line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
      return NULL;
    }
    out->_type=type;
    out->_startX=bx;
    out->_startY=by;
    out->_endX=ex;
    out->_endY=ey;
    return out;
}

line2Du16_t * line2Du16_copy(const line2Du16_t *copy) {
  line2_clear_error();
  if(!copy){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  } line2Du16_t *o=malloc(sizeof(*o));
  if(!o){
    line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  memcpy(o,copy,sizeof(*o));
  return o;
}

line2Du16_t * line2Du16_memmove(line2Du16_t **move) {
  line2_clear_error();
  if(!move||!*move){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Du16_t *tmp=*move;
  *move=NULL;
   return tmp;
}

uint16_t line2Du16_getStartX(line2Du16_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_startX;
}

uint16_t line2Du16_getStartY(line2Du16_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_startY;
}

uint16_t line2Du16_getEndX(line2Du16_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_endX;
}

uint16_t line2Du16_getEndY(line2Du16_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_endY;
}

void line2Du16_setStartX(line2Du16_t *o, uint16_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  } if(x==o->_endX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startX=x; line2_clear_error();
}

void line2Du16_setStartY(line2Du16_t *o, uint16_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  } if(o->_startX==o->_endX && y==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startY=y; line2_clear_error();
}

void line2Du16_setEndX(line2Du16_t *o, uint16_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  } if(x==o->_startX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endX=x; line2_clear_error();
}

void line2Du16_setEndY(line2Du16_t *o, uint16_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  } if(o->_startX==o->_endX && y==o->_startY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endY=y;
  line2_clear_error();
}

bool line2Du16_intersects(line2Du16_t *a, line2Du16_t *b){
  if(!a||!b){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  bool r=segments_intersect_ld(a->_startX,a->_startY,a->_endX,a->_endY,b->_startX,b->_startY,b->_endX,b->_endY);
  line2_clear_error();
  return r;
}

double line2Du16_length(const line2Du16_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Du16_free(line2Du16_t *line) {
    free(line);
}

char* line2Du16_toString(const line2Du16_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* str = malloc(96);
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 96, "%u %u %u %u %u",
             line->_type, line->_startX, line->_startY, line->_endX, line->_endY);

    line2_clear_error();
    return str;
}

line2Du16_t* line2Du16_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type;
    uint16_t startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %hu %hu %hu %hu",
               &type, &startX, &startY, &endX, &endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Du16_malloc(type, startX, startY, endX, endY);
}

void line2Du16_translate(line2Du16_t *line, uint16_t x, uint16_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Du16_translateX(line2Du16_t *line, uint16_t x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Du16_translateY(line2Du16_t *line, uint16_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Du16_translateLine(line2Du16_t *outLine, const line2Du16_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}


/* --- i16 --- */
line2Di16_t * line2Di16_malloc(uint8_t type, int16_t bx, int16_t by, int16_t ex, int16_t ey) {
    line2_clear_error();
    if (bx==ex && by==ey) { line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
      return NULL;
    }
    line2Di16_t *out = malloc(sizeof(line2Di16_t));
    if (!out) { line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
      return NULL;
    }
    out->_type=type;
    out->_startX=bx;
    out->_startY=by;
    out->_endX=ex;
    out->_endY=ey;
    return out;
}

line2Di16_t * line2Di16_copy(const line2Di16_t *copy) {
  line2_clear_error();
  if(!copy){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Di16_t *o=malloc(sizeof(*o));
  if(!o){
    line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  memcpy(o,copy,sizeof(*o));
  return o;
}

line2Di16_t * line2Di16_memmove(line2Di16_t **move) {
  line2_clear_error();
  if(!move||!*move){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Di16_t *tmp=*move;
  *move=NULL;
  return tmp;
}

int16_t line2Di16_getStartX(line2Di16_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_startX;
}

int16_t line2Di16_getStartY(line2Di16_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_startY;
}

int16_t line2Di16_getEndX(line2Di16_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_endX;
}

int16_t line2Di16_getEndY(line2Di16_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_endY;
}

void line2Di16_setStartX(line2Di16_t *o, int16_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_endX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startX=x;
  line2_clear_error();
}

void line2Di16_setStartY(line2Di16_t *o, int16_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startY=y;
  line2_clear_error();
}

void line2Di16_setEndX(line2Di16_t *o, int16_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_startX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endX=x;
  line2_clear_error();
}

void line2Di16_setEndY(line2Di16_t *o, int16_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
}
  if(o->_startX==o->_endX && y==o->_startY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endY=y;
  line2_clear_error();
}

bool line2Di16_intersects(line2Di16_t *a, line2Di16_t *b){
  if(!a||!b){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  bool r=segments_intersect_ld(a->_startX,a->_startY,a->_endX,a->_endY,b->_startX,b->_startY,b->_endX,b->_endY);
  line2_clear_error();
  return r;
}

double line2Di16_length(const line2Di16_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Di16_free(line2Di16_t *line) {
    free(line);
}

char* line2Di16_toString(const line2Di16_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* str = malloc(96);
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 96, "%u %d %d %d %d",
             line->_type, line->_startX, line->_startY, line->_endX, line->_endY);

    line2_clear_error();
    return str;
}

line2Di16_t* line2Di16_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type;
    int16_t startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %hd %hd %hd %hd",
               &type, &startX, &startY, &endX, &endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Di16_malloc(type, startX, startY, endX, endY);
}

void line2Di16_translate(line2Di16_t *line, int16_t x, int16_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Di16_translateX(line2Di16_t *line, int16_t x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Di16_translateY(line2Di16_t *line, int16_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Di16_translateLine(line2Di16_t *outLine, const line2Di16_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}


/* --- u32 --- */
line2Du32_t * line2Du32_malloc(uint8_t type, uint32_t bx, uint32_t by, uint32_t ex, uint32_t ey) {
    line2_clear_error();
    if (bx==ex && by==ey) { line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL); return NULL; }
    line2Du32_t *out = malloc(sizeof(line2Du32_t));
    if (!out) { line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL); return NULL; }
    out->_type=type;
    out->_startX=bx;
    out->_startY=by;
    out->_endX=ex;
    out->_endY=ey;
    return out;
}

line2Du32_t * line2Du32_copy(const line2Du32_t *copy) {
  line2_clear_error();
  if(!copy){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Du32_t *o=malloc(sizeof(*o));
  if(!o){
    line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  memcpy(o,copy,sizeof(*o));
  return o;
}

line2Du32_t * line2Du32_memmove(line2Du32_t **move) {
  line2_clear_error();
  if(!move||!*move){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Du32_t *tmp=*move;
  *move=NULL;
  return tmp;
}

uint32_t line2Du32_getStartX(line2Du32_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_startX;
}

uint32_t line2Du32_getStartY(line2Du32_t *o){
if(!o){
  line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
  return 0;
  }
  line2_clear_error();
  return o->_startY;
}

uint32_t line2Du32_getEndX(line2Du32_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
    }
  line2_clear_error();
  return o->_endX;
}

uint32_t line2Du32_getEndY(line2Du32_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
    }
  line2_clear_error();
  return o->_endY;
}

void line2Du32_setStartX(line2Du32_t *o, uint32_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
    }
  if(x==o->_endX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
    }
  o->_startX=x;
  line2_clear_error();
}

void line2Du32_setStartY(line2Du32_t *o, uint32_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
    }
  if(o->_startX==o->_endX && y==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
    }
  o->_startY=y;
  line2_clear_error();
}

void line2Du32_setEndX(line2Du32_t *o, uint32_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_startX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endX=x;
  line2_clear_error();
}

void line2Du32_setEndY(line2Du32_t *o, uint32_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_startY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endY=y;
  line2_clear_error();
}

bool line2Du32_intersects(line2Du32_t *a, line2Du32_t *b){
  if(!a||!b){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  bool r=segments_intersect_ld(a->_startX,a->_startY,a->_endX,a->_endY,b->_startX,b->_startY,b->_endX,b->_endY);
  line2_clear_error();
  return r;
}

double line2Du32_length(const line2Du32_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Du32_free(line2Du32_t *line) {
    free(line);
}

char* line2Du32_toString(const line2Du32_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* str = malloc(128);
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 128, "%u %u %u %u %u",
             line->_type, line->_startX, line->_startY, line->_endX, line->_endY);

    line2_clear_error();
    return str;
}

line2Du32_t* line2Du32_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type;
    uint32_t startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %u %u %u %u",
               &type, &startX, &startY, &endX, &endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Du32_malloc(type, startX, startY, endX, endY);
}

void line2Du32_translate(line2Du32_t *line, uint32_t x, uint32_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Du32_translateX(line2Du32_t *line, uint32_t x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Du32_translateY(line2Du32_t *line, uint32_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Du32_translateLine(line2Du32_t *outLine, const line2Du32_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}


/* --- i32 --- */
line2Di32_t * line2Di32_malloc(uint8_t type, int32_t bx, int32_t by, int32_t ex, int32_t ey) {
    line2_clear_error();
    if (bx==ex && by==ey) { line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
      return NULL;
    }
    line2Di32_t *out = malloc(sizeof(line2Di32_t));
    if (!out) { line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
      return NULL;
    }
    out->_type=type;
    out->_startX=bx;
    out->_startY=by;
    out->_endX=ex;
    out->_endY=ey;
    return out;
}

line2Di32_t * line2Di32_copy(const line2Di32_t *copy) {
  line2_clear_error();
  if(!copy){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Di32_t *o=malloc(sizeof(*o));
  if(!o){line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  memcpy(o,copy,sizeof(*o));
  return o;
}

line2Di32_t * line2Di32_memmove(line2Di32_t **move) {
  line2_clear_error();
  if(!move||!*move){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Di32_t *tmp=*move;
  *move=NULL;
  return tmp;
}

int32_t line2Di32_getStartX(line2Di32_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_startX;
}

int32_t line2Di32_getStartY(line2Di32_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_startY;
}

int32_t line2Di32_getEndX(line2Di32_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_endX;
}

int32_t line2Di32_getEndY(line2Di32_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_endY;
}

void line2Di32_setStartX(line2Di32_t *o, int32_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_endX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startX=x;
  line2_clear_error();
}

void line2Di32_setStartY(line2Di32_t *o, int32_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startY=y;
  line2_clear_error();
}

void line2Di32_setEndX(line2Di32_t *o, int32_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_startX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endX=x;
  line2_clear_error();
}

void line2Di32_setEndY(line2Di32_t *o, int32_t y){
    if(!o){
      line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
      return;}
      if(o->_startX==o->_endX && y==o->_startY){
        line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
        return;
      }
      o->_endY=y;
      line2_clear_error();
}

bool line2Di32_intersects(line2Di32_t *a, line2Di32_t *b){
  if(!a||!b){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  bool r=segments_intersect_ld(a->_startX,a->_startY,a->_endX,a->_endY,b->_startX,b->_startY,b->_endX,b->_endY);
  line2_clear_error();
  return r;
}

double line2Di32_length(const line2Di32_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Di32_free(line2Di32_t *line) {
    free(line);
}

char* line2Di32_toString(const line2Di32_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* str = malloc(128);
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 128, "%u %d %d %d %d",
             line->_type, line->_startX, line->_startY, line->_endX, line->_endY);

    line2_clear_error();
    return str;
}

line2Di32_t* line2Di32_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type;
    int32_t startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %d %d %d %d",
               &type, &startX, &startY, &endX, &endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Di32_malloc(type, startX, startY, endX, endY);
}

void line2Di32_translate(line2Di32_t *line, int32_t x, int32_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Di32_translateX(line2Di32_t *line, int32_t x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Di32_translateY(line2Di32_t *line, int32_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Di32_translateLine(line2Di32_t *outLine, const line2Di32_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}


/* --- u64 --- */
line2Du64_t * line2Du64_malloc(uint8_t type, uint64_t bx, uint64_t by, uint64_t ex, uint64_t ey) {
    line2_clear_error();
    if (bx==ex && by==ey) {
      line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
      return NULL;
    }

    line2Du64_t *out = malloc(sizeof(line2Du64_t));
    if (!out) {
      line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
      return NULL;
    }
    out->_type=type;
    out->_startX=bx;
    out->_startY=by;
    out->_endX=ex;
    out->_endY=ey;
    return out;
}

line2Du64_t * line2Du64_copy(const line2Du64_t *copy) {
  line2_clear_error();
  if(!copy){line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  } line2Du64_t *o=malloc(sizeof(*o));
  if(!o){
    line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  memcpy(o,copy,sizeof(*o));
  return o;
}

line2Du64_t * line2Du64_memmove(line2Du64_t **move) {
  line2_clear_error();
  if(!move||!*move){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Du64_t *tmp=*move;
  *move=NULL;
  return tmp;
}

uint64_t line2Du64_getStartX(line2Du64_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
    line2_clear_error();
    return o->_startX;
  }

uint64_t line2Du64_getStartY(line2Du64_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_startY;
}

uint64_t line2Du64_getEndX(line2Du64_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;}
    line2_clear_error();
    return o->_endX;
  }

uint64_t line2Du64_getEndY(line2Du64_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;}
    line2_clear_error();
    return o->_endY;
}

void line2Du64_setStartX(line2Du64_t *o, uint64_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;}
    if(x==o->_endX && o->_startY==o->_endY){
      line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
      return;
    }
    o->_startX=x;
    line2_clear_error();
  }

void line2Du64_setStartY(line2Du64_t *o, uint64_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;}
    if(o->_startX==o->_endX && y==o->_endY){
      line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
      return;
    }
    o->_startY=y;
    line2_clear_error();
  }

void line2Du64_setEndX(line2Du64_t *o, uint64_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;}
    if(x==o->_startX && o->_startY==o->_endY){
      line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
      return;
    }
    o->_endX=x;
    line2_clear_error();
}

void line2Du64_setEndY(line2Du64_t *o, uint64_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;}
    if(o->_startX==o->_endX && y==o->_startY){
      line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
      return;
    }
    o->_endY=y;
    line2_clear_error();
}

bool line2Du64_intersects(line2Du64_t *a, line2Du64_t *b){
  if(!a||!b){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  bool r=segments_intersect_ld((long double)a->_startX,(long double)a->_startY,(long double)a->_endX,(long double)a->_endY,(long double)b->_startX,(long double)b->_startY,(long double)b->_endX,(long double)b->_endY);
  line2_clear_error();
  return r;
}

double line2Du64_length(const line2Du64_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Du64_free(line2Du64_t *line) {
    free(line);
}

char* line2Du64_toString(const line2Du64_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* str = malloc(192);
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 192, "%u %llu %llu %llu %llu",
             line->_type,
             (unsigned long long)line->_startX,
             (unsigned long long)line->_startY,
             (unsigned long long)line->_endX,
             (unsigned long long)line->_endY);

    line2_clear_error();
    return str;
}

line2Du64_t* line2Du64_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type;
    uint64_t startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %llu %llu %llu %llu",
               &type,
               (unsigned long long*)&startX,
               (unsigned long long*)&startY,
               (unsigned long long*)&endX,
               (unsigned long long*)&endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Du64_malloc(type, startX, startY, endX, endY);
}

void line2Du64_translate(line2Du64_t *line, uint64_t x, uint64_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Du64_translateX(line2Du64_t *line, uint64_t x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Du64_translateY(line2Du64_t *line, uint64_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Du64_translateLine(line2Du64_t *outLine, const line2Du64_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}


/* --- i64 --- */
line2Di64_t * line2Di64_malloc(uint8_t type, int64_t bx, int64_t by, int64_t ex, int64_t ey) {
  line2_clear_error();
  if (bx==ex && by==ey) {
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return NULL;
  }
  line2Di64_t *out = malloc(sizeof(line2Di64_t));
  if (!out) { line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL); return NULL; }
  out->_type=type;
  out->_startX=bx;
  out->_startY=by;
  out->_endX=ex;
  out->_endY=ey;
  return out;
}

line2Di64_t * line2Di64_copy(const line2Di64_t *copy) {
  line2_clear_error();
  if(!copy){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Di64_t *o=malloc(sizeof(*o));
  if(!o){
    line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  memcpy(o,copy,sizeof(*o));
  return o;
}

line2Di64_t * line2Di64_memmove(line2Di64_t **move) {
    line2_clear_error();
    if(!move||!*move){
      line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
      return NULL;
    }
    line2Di64_t *tmp=*move;
    *move=NULL;
    return tmp;
  }

int64_t line2Di64_getStartX(line2Di64_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_startX;
}

int64_t line2Di64_getStartY(line2Di64_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_startY;
}

int64_t line2Di64_getEndX(line2Di64_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_endX;
}

int64_t line2Di64_getEndY(line2Di64_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0;
  }
  line2_clear_error();
  return o->_endY;
}

void line2Di64_setStartX(line2Di64_t *o, int64_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
    if(x==o->_endX && o->_startY==o->_endY){
      line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
      return;
    }
    o->_startX=x;
    line2_clear_error();
}

void line2Di64_setStartY(line2Di64_t *o, int64_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startY=y;
  line2_clear_error();
}

void line2Di64_setEndX(line2Di64_t *o, int64_t x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_startX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endX=x;
  line2_clear_error();
}

void line2Di64_setEndY(line2Di64_t *o, int64_t y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_startY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endY=y;
  line2_clear_error();
}

bool line2Di64_intersects(line2Di64_t *a, line2Di64_t *b){
  if(!a||!b){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  bool r=segments_intersect_ld((long double)a->_startX,(long double)a->_startY,(long double)a->_endX,(long double)a->_endY,(long double)b->_startX,(long double)b->_startY,(long double)b->_endX,(long double)b->_endY);
  line2_clear_error();
  return r;
}

double line2Di64_length(const line2Di64_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Di64_free(line2Di64_t *line) {
    free(line);
}

char* line2Di64_toString(const line2Di64_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* str = malloc(192);
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 192, "%u %lld %lld %lld %lld",
             line->_type,
             (long long)line->_startX,
             (long long)line->_startY,
             (long long)line->_endX,
             (long long)line->_endY);

    line2_clear_error();
    return str;
}

line2Di64_t* line2Di64_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type;
    int64_t startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %lld %lld %lld %lld",
               &type,
               (long long*)&startX,
               (long long*)&startY,
               (long long*)&endX,
               (long long*)&endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Di64_malloc(type, startX, startY, endX, endY);
}

void line2Di64_translate(line2Di64_t *line, int64_t x, int64_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Di64_translateX(line2Di64_t *line, int64_t x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Di64_translateY(line2Di64_t *line, int64_t y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Di64_translateLine(line2Di64_t *outLine, const line2Di64_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}


/* --- float --- */
line2Df_t * line2Df_malloc(uint8_t type, float bx, float by, float ex, float ey) {
  line2_clear_error();
  if (bx==ex && by==ey) {
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return NULL;
  }
  line2Df_t *out = malloc(sizeof(line2Df_t));
  if (!out) {
    line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  out->_type=type;
  out->_startX=bx;
  out->_startY=by;
  out->_endX=ex;
  out->_endY=ey;
  return out;
}

line2Df_t * line2Df_copy(const line2Df_t *copy) {
  line2_clear_error();
  if(!copy){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Df_t *o=malloc(sizeof(*o));
  if(!o){
    line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  memcpy(o,copy,sizeof(*o));
  return o;
}

line2Df_t * line2Df_memmove(line2Df_t **move) {
  line2_clear_error();
  if(!move||!*move){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Df_t *tmp=*move;
  *move=NULL;
  return tmp;
}

float line2Df_getStartX(line2Df_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0f;
  }
  line2_clear_error();
  return o->_startX;
  }

float line2Df_getStartY(line2Df_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0f;
  }
  line2_clear_error();
  return o->_startY;
}

float line2Df_getEndX(line2Df_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0f;
  }
  line2_clear_error();
  return o->_endX;
}

float line2Df_getEndY(line2Df_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0f;
  }
  line2_clear_error();
  return o->_endY;
}

void line2Df_setStartX(line2Df_t *o, float x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_endX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;}
    o->_startX=x;
    line2_clear_error();
}

void line2Df_setStartY(line2Df_t *o, float y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;}
    o->_startY=y;
    line2_clear_error();
  }

void line2Df_setEndX(line2Df_t *o, float x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_startX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endX=x;
  line2_clear_error();
}

void line2Df_setEndY(line2Df_t *o, float y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_startY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endY=y;
  line2_clear_error();
}

bool line2Df_intersects(line2Df_t *a, line2Df_t *b){
  if(!a||!b){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  bool r=segments_intersect_ld(a->_startX,a->_startY,a->_endX,a->_endY,b->_startX,b->_startY,b->_endX,b->_endY);
  line2_clear_error();
  return r;
}

double line2Df_length(const line2Df_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Df_free(line2Df_t *line) {
    free(line);
}

char* line2Df_toString(const line2Df_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* str = malloc(192);
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 192, "%u %.6g %.6g %.6g %.6g",
             line->_type, line->_startX, line->_startY, line->_endX, line->_endY);

    line2_clear_error();
    return str;
}

line2Df_t* line2Df_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type;
    float startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %f %f %f %f",
               &type, &startX, &startY, &endX, &endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Df_malloc(type, startX, startY, endX, endY);
}

void line2Df_translate(line2Df_t *line, float x, float y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Df_translateX(line2Df_t *line, float x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Df_translateY(line2Df_t *line, float y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Df_translateLine(line2Df_t *outLine, const line2Df_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}


/* --- double --- */
line2Dd_t * line2Dd_malloc(uint8_t type, double bx, double by, double ex, double ey) {
  line2_clear_error();
  if (bx==ex && by==ey) {
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return NULL;
  }
  line2Dd_t *out = malloc(sizeof(line2Dd_t));
  if (!out) { line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  out->_type=type; out->_startX=bx;
  out->_startY=by;
  out->_endX=ex;
  out->_endY=ey;
  return out;
}

line2Dd_t * line2Dd_copy(const line2Dd_t *copy) {
  line2_clear_error();
  if(!copy){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }

  line2Dd_t *o=malloc(sizeof(*o));
  if(!o){
    line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  memcpy(o,copy,sizeof(*o));
  return o;
}

line2Dd_t * line2Dd_memmove(line2Dd_t **move) {
  line2_clear_error();
  if(!move||!*move){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Dd_t *tmp=*move;
  *move=NULL;
  return tmp;
}

double line2Dd_getStartX(line2Dd_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0;
  }
  line2_clear_error();
  return o->_startX;
}

double line2Dd_getStartY(line2Dd_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0;
  }
  line2_clear_error();
  return o->_startY;
}

double line2Dd_getEndX(line2Dd_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0;
  }
  line2_clear_error();
  return o->_endX;
}

double line2Dd_getEndY(line2Dd_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0;
  }
  line2_clear_error();
  return o->_endY;
}

void line2Dd_setStartX(line2Dd_t *o, double x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_endX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startX=x;
  line2_clear_error();
}

void line2Dd_setStartY(line2Dd_t *o, double y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startY=y;
  line2_clear_error();
}

void line2Dd_setEndX(line2Dd_t *o, double x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_startX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endX=x;
  line2_clear_error();
}

void line2Dd_setEndY(line2Dd_t *o, double y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_startY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endY=y;
  line2_clear_error();
}

bool line2Dd_intersects(line2Dd_t *a, line2Dd_t *b){
  if(!a||!b){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  bool r=segments_intersect_ld(a->_startX,a->_startY,a->_endX,a->_endY,b->_startX,b->_startY,b->_endX,b->_endY);
  line2_clear_error();
  return r;
}

double line2Dd_length(const line2Dd_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Dd_free(line2Dd_t *line) {
    free(line);
}

char* line2Dd_toString(const line2Dd_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* str = malloc(256);
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 256, "%u %.15g %.15g %.15g %.15g",
             line->_type, line->_startX, line->_startY, line->_endX, line->_endY);

    line2_clear_error();
    return str;
}

line2Dd_t* line2Dd_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type;
    double startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %lf %lf %lf %lf",
               &type, &startX, &startY, &endX, &endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Dd_malloc(type, startX, startY, endX, endY);
}

void line2Dd_translate(line2Dd_t *line, double x, double y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Dd_translateX(line2Dd_t *line, double x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Dd_translateY(line2Dd_t *line, double y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Dd_translateLine(line2Dd_t *outLine, const line2Dd_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}


/* --- long double --- */
line2Dld_t * line2Dld_malloc(uint8_t type, long double bx, long double by, long double ex, long double ey) {
  line2_clear_error();
  if (bx==ex && by==ey) { line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return NULL;
  }
  line2Dld_t *out = malloc(sizeof(line2Dld_t));
  if (!out) { line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  out->_type=type; out->_startX=bx;
  out->_startY=by;
  out->_endX=ex;
  out->_endY=ey;
  return out;
}

line2Dld_t * line2Dld_copy(const line2Dld_t *copy) {
  line2_clear_error();
  if(!copy){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);return NULL;
  }
  line2Dld_t *o=malloc(sizeof(*o));
  if(!o){
    line2_set_error(LINE2_ERROR_MALLOC_FAILED,NULL);
    return NULL;
  }
  memcpy(o,copy,sizeof(*o));
  return o;
}

line2Dld_t * line2Dld_memmove(line2Dld_t **move) {
  line2_clear_error();
  if(!move||!*move){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return NULL;
  }
  line2Dld_t *tmp=*move;
  *move=NULL;
  return tmp;
}

long double line2Dld_getStartX(line2Dld_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0L;
  }
  line2_clear_error();
  return o->_startX;
}

long double line2Dld_getStartY(line2Dld_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0L;
  }
  line2_clear_error();
  return o->_startY;
}

long double line2Dld_getEndX(line2Dld_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0L;
  }
  line2_clear_error();
  return o->_endX;
}

long double line2Dld_getEndY(line2Dld_t *o){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return 0.0L;
  }
  line2_clear_error();
  return o->_endY;
}

void line2Dld_setStartX(line2Dld_t *o, long double x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_endX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startX=x;
  line2_clear_error();
}

void line2Dld_setStartY(line2Dld_t *o, long double y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_startY=y;
  line2_clear_error();
}

void line2Dld_setEndX(line2Dld_t *o, long double x){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(x==o->_startX && o->_startY==o->_endY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endX=x;
  line2_clear_error();
}

void line2Dld_setEndY(line2Dld_t *o, long double y){
  if(!o){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return;
  }
  if(o->_startX==o->_endX && y==o->_startY){
    line2_set_error(LINE2_ERROR_ZERO_LENGTH,NULL);
    return;
  }
  o->_endY=y;
  line2_clear_error();
}

bool line2Dld_intersects(line2Dld_t *a, line2Dld_t *b){
  if(!a||!b){
    line2_set_error(LINE2_ERROR_NULL_POINTER,NULL);
    return false;
  }
  bool r = segments_intersect_ld(a->_startX,a->_startY,a->_endX,a->_endY,b->_startX,b->_startY,b->_endX,b->_endY);
  line2_clear_error();
  return r;
}

double line2Dld_length(const line2Dld_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0.0;
    }
    line2_clear_error();
    return compute_length_ld_longdouble(line->_startX, line->_startY, line->_endX, line->_endY);
}

void line2Dld_free(line2Dld_t *line) {
    free(line);
}

char* line2Dld_toString(const line2Dld_t* line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* str = malloc(384);
    if (!str) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 384, "%u %.21Lg %.21Lg %.21Lg %.21Lg",
             line->_type, line->_startX, line->_startY, line->_endX, line->_endY);

    line2_clear_error();
    return str;
}

line2Dld_t* line2Dld_fromString(const char* str) {
    if (!str) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    char* copy = strdup(str);
    if (!copy) {
        line2_set_error(LINE2_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    char* trimmed = trim_whitespace(copy);
    uint8_t type;
    long double startX, startY, endX, endY;

    if (sscanf(trimmed, "%hhu %Lf %Lf %Lf %Lf",
               &type, &startX, &startY, &endX, &endY) != 5) {
        free(copy);
        line2_set_error(LINE2_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    free(copy);
    return line2Dld_malloc(type, startX, startY, endX, endY);
}

void line2Dld_translate(line2Dld_t *line, long double x, long double y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_startY += y;
    line->_endX += x;
    line->_endY += y;
    line2_clear_error();
}

void line2Dld_translateX(line2Dld_t *line, long double x) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startX += x;
    line->_endX += x;
    line2_clear_error();
}

void line2Dld_translateY(line2Dld_t *line, long double y) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    line->_startY += y;
    line->_endY += y;
    line2_clear_error();
}

void line2Dld_translateLine(line2Dld_t *outLine, const line2Dld_t *line) {
    if (!outLine || !line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    outLine->_startX += line->_endX - line->_startX;
    outLine->_startY += line->_endY - line->_startY;
    outLine->_endX += line->_endX - line->_startX;
    outLine->_endY += line->_endY - line->_startY;
    line2_clear_error();
}

// getSize meta-function
size_t line2Du8_size(void){
  return sizeof(line2Du8_t);
}
size_t line2Di8_size(void){
  return sizeof(line2Di8_t);
}
size_t line2Du16_size(void){
  return sizeof(line2Du16_t);
}
size_t line2Di16_size(void){
  return sizeof(line2Di16_t);
}
size_t line2Du32_size(void){
  return sizeof(line2Du32_t);
}
size_t line2Di32_size(void){
  return sizeof(line2Di32_t);
}
size_t line2Du64_size(void){
  return sizeof(line2Du64_t);
}
size_t line2Di64_size(void){
  return sizeof(line2Di64_t);
}
size_t line2Df_size(void){
  return sizeof(line2Df_t);
}
size_t line2Dd_size(void){
  return sizeof(line2Dd_t);
}
size_t line2Dld_size(void){
  return sizeof(line2Dld_t);
}




/* line2.c additions - Vector extension functions */

#ifdef VEC2_DEFINED

/* --- u8 --- */
vec2uint8_t * line2Du8_getStartPosVec2(line2Du8_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2U8(line->_startX, line->_startY);
}

vec2uint8_t * line2Du8_getEndPosVec2(line2Du8_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2U8(line->_endX, line->_endY);
}

void line2Du8_setStartPosVec2(line2Du8_t *line, const vec2uint8_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    uint8_t x = vec2u8_X((vec2uint8_t *)vec);
    uint8_t y = vec2u8_Y((vec2uint8_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Du8_setEndPosVec2(line2Du8_t *line, const vec2uint8_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    uint8_t x = vec2u8_X((vec2uint8_t *)vec);
    uint8_t y = vec2u8_Y((vec2uint8_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

/* --- i8 --- */
vec2int8_t * line2Di8_getStartPosVec2(line2Di8_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2I8(line->_startX, line->_startY);
}

vec2int8_t * line2Di8_getEndPosVec2(line2Di8_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2I8(line->_endX, line->_endY);
}

void line2Di8_setStartPosVec2(line2Di8_t *line, const vec2int8_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    int8_t x = vec2i8_X((vec2int8_t *)vec);
    int8_t y = vec2i8_Y((vec2int8_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Di8_setEndPosVec2(line2Di8_t *line, const vec2int8_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    int8_t x = vec2i8_X((vec2int8_t *)vec);
    int8_t y = vec2i8_Y((vec2int8_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

/* --- u16 --- */
vec2uint16_t * line2Du16_getStartPosVec2(line2Du16_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2U16(line->_startX, line->_startY);
}

vec2uint16_t * line2Du16_getEndPosVec2(line2Du16_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2U16(line->_endX, line->_endY);
}

void line2Du16_setStartPosVec2(line2Du16_t *line, const vec2uint16_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    uint16_t x = vec2u16_X((vec2uint16_t *)vec);
    uint16_t y = vec2u16_Y((vec2uint16_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Du16_setEndPosVec2(line2Du16_t *line, const vec2uint16_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    uint16_t x = vec2u16_X((vec2uint16_t *)vec);
    uint16_t y = vec2u16_Y((vec2uint16_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

/* --- i16 --- */
vec2int16_t * line2Di16_getStartPosVec2(line2Di16_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2I16(line->_startX, line->_startY);
}

vec2int16_t * line2Di16_getEndPosVec2(line2Di16_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2I16(line->_endX, line->_endY);
}

void line2Di16_setStartPosVec2(line2Di16_t *line, const vec2int16_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    int16_t x = vec2i16_X((vec2int16_t *)vec);
    int16_t y = vec2i16_Y((vec2int16_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Di16_setEndPosVec2(line2Di16_t *line, const vec2int16_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    int16_t x = vec2i16_X((vec2int16_t *)vec);
    int16_t y = vec2i16_Y((vec2int16_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

/* --- u32 --- */
vec2uint32_t * line2Du32_getStartPosVec2(line2Du32_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2U32(line->_startX, line->_startY);
}

vec2uint32_t * line2Du32_getEndPosVec2(line2Du32_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2U32(line->_endX, line->_endY);
}

void line2Du32_setStartPosVec2(line2Du32_t *line, const vec2uint32_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    uint32_t x = vec2u32_X((vec2uint32_t *)vec);
    uint32_t y = vec2u32_Y((vec2uint32_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Du32_setEndPosVec2(line2Du32_t *line, const vec2uint32_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    uint32_t x = vec2u32_X((vec2uint32_t *)vec);
    uint32_t y = vec2u32_Y((vec2uint32_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

/* --- i32 --- */
vec2int32_t * line2Di32_getStartPosVec2(line2Di32_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2I32(line->_startX, line->_startY);
}

vec2int32_t * line2Di32_getEndPosVec2(line2Di32_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2I32(line->_endX, line->_endY);
}

void line2Di32_setStartPosVec2(line2Di32_t *line, const vec2int32_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    int32_t x = vec2i32_X((vec2int32_t *)vec);
    int32_t y = vec2i32_Y((vec2int32_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Di32_setEndPosVec2(line2Di32_t *line, const vec2int32_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    int32_t x = vec2i32_X((vec2int32_t *)vec);
    int32_t y = vec2i32_Y((vec2int32_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

/* --- u64 --- */
vec2uint64_t * line2Du64_getStartPosVec2(line2Du64_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2U64(line->_startX, line->_startY);
}

vec2uint64_t * line2Du64_getEndPosVec2(line2Du64_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2U64(line->_endX, line->_endY);
}

void line2Du64_setStartPosVec2(line2Du64_t *line, const vec2uint64_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    uint64_t x = vec2u64_X((vec2uint64_t *)vec);
    uint64_t y = vec2u64_Y((vec2uint64_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Du64_setEndPosVec2(line2Du64_t *line, const vec2uint64_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    uint64_t x = vec2u64_X((vec2uint64_t *)vec);
    uint64_t y = vec2u64_Y((vec2uint64_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

/* --- i64 --- */
vec2int64_t * line2Di64_getStartPosVec2(line2Di64_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2I64(line->_startX, line->_startY);
}

vec2int64_t * line2Di64_getEndPosVec2(line2Di64_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2I64(line->_endX, line->_endY);
}

void line2Di64_setStartPosVec2(line2Di64_t *line, const vec2int64_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    int64_t x = vec2i64_X((vec2int64_t *)vec);
    int64_t y = vec2i64_Y((vec2int64_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Di64_setEndPosVec2(line2Di64_t *line, const vec2int64_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    int64_t x = vec2i64_X((vec2int64_t *)vec);
    int64_t y = vec2i64_Y((vec2int64_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

/* --- float --- */
vec2f_t * line2Df_getStartPosVec2(line2Df_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2F(line->_startX, line->_startY);
}

vec2f_t * line2Df_getEndPosVec2(line2Df_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2F(line->_endX, line->_endY);
}

void line2Df_setStartPosVec2(line2Df_t *line, const vec2f_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    float x = vec2f_X((vec2f_t *)vec);
    float y = vec2f_Y((vec2f_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Df_setEndPosVec2(line2Df_t *line, const vec2f_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    float x = vec2f_X((vec2f_t *)vec);
    float y = vec2f_Y((vec2f_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

/* --- double --- */
vec2d_t * line2Dd_getStartPosVec2(line2Dd_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2D(line->_startX, line->_startY);
}

vec2d_t * line2Dd_getEndPosVec2(line2Dd_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2D(line->_endX, line->_endY);
}

void line2Dd_setStartPosVec2(line2Dd_t *line, const vec2d_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    double x = vec2d_X((vec2d_t *)vec);
    double y = vec2d_Y((vec2d_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Dd_setEndPosVec2(line2Dd_t *line, const vec2d_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    double x = vec2d_X((vec2d_t *)vec);
    double y = vec2d_Y((vec2d_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

/* --- long double --- */
vec2ld_t * line2Dld_getStartPosVec2(line2Dld_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2LD(line->_startX, line->_startY);
}

vec2ld_t * line2Dld_getEndPosVec2(line2Dld_t *line) {
    if (!line) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line2_clear_error();
    return allocvec2LD(line->_endX, line->_endY);
}

void line2Dld_setStartPosVec2(line2Dld_t *line, const vec2ld_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    long double x = vec2ld_X((vec2ld_t *)vec);
    long double y = vec2ld_Y((vec2ld_t *)vec);

    if (x == line->_endX && y == line->_endY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_startX = x;
    line->_startY = y;
    line2_clear_error();
}

void line2Dld_setEndPosVec2(line2Dld_t *line, const vec2ld_t *vec) {
    if (!line || !vec) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    long double x = vec2ld_X((vec2ld_t *)vec);
    long double y = vec2ld_Y((vec2ld_t *)vec);

    if (x == line->_startX && y == line->_startY) {
        line2_set_error(LINE2_ERROR_ZERO_LENGTH, NULL);
        return;
    }

    line->_endX = x;
    line->_endY = y;
    line2_clear_error();
}

#endif /* VEC2_DEFINED */

/* Serialization/Deserialization */

/* Helper functions for endianness conversion */
static uint16_t swap16(uint16_t x) {
    return (x << 8) | (x >> 8);
}

static uint32_t swap32(uint32_t x) {
    return ((x << 24) & 0xff000000) |
           ((x << 8)  & 0x00ff0000) |
           ((x >> 8)  & 0x0000ff00) |
           ((x >> 24) & 0x000000ff);
}

static uint64_t swap64(uint64_t x) {
    return ((x << 56) & 0xff00000000000000ULL) |
           ((x << 40) & 0x00ff000000000000ULL) |
           ((x << 24) & 0x0000ff0000000000ULL) |
           ((x << 8)  & 0x000000ff00000000ULL) |
           ((x >> 8)  & 0x00000000ff000000ULL) |
           ((x >> 24) & 0x0000000000ff0000ULL) |
           ((x >> 40) & 0x000000000000ff00ULL) |
           ((x >> 56) & 0x00000000000000ffULL);
}

/* Array serialization/deserialization */

/* --- u8 --- */
void line2Du8_toArray(const line2Du8_t *line, uint8_t arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Du8_t *line2Du8_fromArray(const uint8_t arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Du8_malloc(arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* --- i8 --- */
void line2Di8_toArray(const line2Di8_t *line, int8_t arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = (int8_t)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Di8_t *line2Di8_fromArray(const int8_t arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Di8_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* --- u16 --- */
void line2Du16_toArray(const line2Du16_t *line, uint16_t arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Du16_t *line2Du16_fromArray(const uint16_t arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Du16_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* --- i16 --- */
void line2Di16_toArray(const line2Di16_t *line, int16_t arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = (int16_t)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Di16_t *line2Di16_fromArray(const int16_t arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Di16_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* --- u32 --- */
void line2Du32_toArray(const line2Du32_t *line, uint32_t arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Du32_t *line2Du32_fromArray(const uint32_t arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Du32_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* --- i32 --- */
void line2Di32_toArray(const line2Di32_t *line, int32_t arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = (int32_t)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Di32_t *line2Di32_fromArray(const int32_t arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Di32_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* --- u64 --- */
void line2Du64_toArray(const line2Du64_t *line, uint64_t arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Du64_t *line2Du64_fromArray(const uint64_t arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Du64_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* --- i64 --- */
void line2Di64_toArray(const line2Di64_t *line, int64_t arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = (int64_t)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Di64_t *line2Di64_fromArray(const int64_t arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Di64_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* --- float --- */
void line2Df_toArray(const line2Df_t *line, float arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = (float)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Df_t *line2Df_fromArray(const float arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Df_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* --- double --- */
void line2Dd_toArray(const line2Dd_t *line, double arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = (double)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Dd_t *line2Dd_fromArray(const double arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Dd_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* --- long double --- */
void line2Dld_toArray(const line2Dld_t *line, long double arr[5]) {
    if (!line || !arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return;
    }
    arr[0] = (long double)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_endX;
    arr[4] = line->_endY;
    line2_clear_error();
}

line2Dld_t *line2Dld_fromArray(const long double arr[5]) {
    if (!arr) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Dld_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4]);
}

/* Byte serialization/deserialization (native byte order) */

/* --- u8 --- */
size_t line2Du8_toBytes(const line2Du8_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    bytes[1] = line->_startX;
    bytes[2] = line->_startY;
    bytes[3] = line->_endX;
    bytes[4] = line->_endY;
    line2_clear_error();
    return 5;
}

line2Du8_t *line2Du8_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    return line2Du8_malloc(bytes[0], bytes[1], bytes[2], bytes[3], bytes[4]);
}

/* --- i8 --- */
size_t line2Di8_toBytes(const line2Di8_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    memcpy(&bytes[1], &line->_startX, sizeof(int8_t));
    memcpy(&bytes[2], &line->_startY, sizeof(int8_t));
    memcpy(&bytes[3], &line->_endX, sizeof(int8_t));
    memcpy(&bytes[4], &line->_endY, sizeof(int8_t));
    line2_clear_error();
    return 5;
}

line2Di8_t *line2Di8_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    int8_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(int8_t));
    memcpy(&startY, &bytes[2], sizeof(int8_t));
    memcpy(&endX, &bytes[3], sizeof(int8_t));
    memcpy(&endY, &bytes[4], sizeof(int8_t));
    return line2Di8_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- u16 --- */
size_t line2Du16_toBytes(const line2Du16_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    memcpy(&bytes[1], &line->_startX, sizeof(uint16_t));
    memcpy(&bytes[3], &line->_startY, sizeof(uint16_t));
    memcpy(&bytes[5], &line->_endX, sizeof(uint16_t));
    memcpy(&bytes[7], &line->_endY, sizeof(uint16_t));
    line2_clear_error();
    return 9;
}

line2Du16_t *line2Du16_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    uint16_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(uint16_t));
    memcpy(&startY, &bytes[3], sizeof(uint16_t));
    memcpy(&endX, &bytes[5], sizeof(uint16_t));
    memcpy(&endY, &bytes[7], sizeof(uint16_t));
    return line2Du16_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- i16 --- */
size_t line2Di16_toBytes(const line2Di16_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    memcpy(&bytes[1], &line->_startX, sizeof(int16_t));
    memcpy(&bytes[3], &line->_startY, sizeof(int16_t));
    memcpy(&bytes[5], &line->_endX, sizeof(int16_t));
    memcpy(&bytes[7], &line->_endY, sizeof(int16_t));
    line2_clear_error();
    return 9;
}

line2Di16_t *line2Di16_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    int16_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(int16_t));
    memcpy(&startY, &bytes[3], sizeof(int16_t));
    memcpy(&endX, &bytes[5], sizeof(int16_t));
    memcpy(&endY, &bytes[7], sizeof(int16_t));
    return line2Di16_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- u32 --- */
size_t line2Du32_toBytes(const line2Du32_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    memcpy(&bytes[1], &line->_startX, sizeof(uint32_t));
    memcpy(&bytes[5], &line->_startY, sizeof(uint32_t));
    memcpy(&bytes[9], &line->_endX, sizeof(uint32_t));
    memcpy(&bytes[13], &line->_endY, sizeof(uint32_t));
    line2_clear_error();
    return 17;
}

line2Du32_t *line2Du32_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    uint32_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(uint32_t));
    memcpy(&startY, &bytes[5], sizeof(uint32_t));
    memcpy(&endX, &bytes[9], sizeof(uint32_t));
    memcpy(&endY, &bytes[13], sizeof(uint32_t));
    return line2Du32_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- i32 --- */
size_t line2Di32_toBytes(const line2Di32_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    memcpy(&bytes[1], &line->_startX, sizeof(int32_t));
    memcpy(&bytes[5], &line->_startY, sizeof(int32_t));
    memcpy(&bytes[9], &line->_endX, sizeof(int32_t));
    memcpy(&bytes[13], &line->_endY, sizeof(int32_t));
    line2_clear_error();
    return 17;
}

line2Di32_t *line2Di32_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    int32_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(int32_t));
    memcpy(&startY, &bytes[5], sizeof(int32_t));
    memcpy(&endX, &bytes[9], sizeof(int32_t));
    memcpy(&endY, &bytes[13], sizeof(int32_t));
    return line2Di32_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- u64 --- */
size_t line2Du64_toBytes(const line2Du64_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    memcpy(&bytes[1], &line->_startX, sizeof(uint64_t));
    memcpy(&bytes[9], &line->_startY, sizeof(uint64_t));
    memcpy(&bytes[17], &line->_endX, sizeof(uint64_t));
    memcpy(&bytes[25], &line->_endY, sizeof(uint64_t));
    line2_clear_error();
    return 33;
}

line2Du64_t *line2Du64_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    uint64_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(uint64_t));
    memcpy(&startY, &bytes[9], sizeof(uint64_t));
    memcpy(&endX, &bytes[17], sizeof(uint64_t));
    memcpy(&endY, &bytes[25], sizeof(uint64_t));
    return line2Du64_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- i64 --- */
size_t line2Di64_toBytes(const line2Di64_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    memcpy(&bytes[1], &line->_startX, sizeof(int64_t));
    memcpy(&bytes[9], &line->_startY, sizeof(int64_t));
    memcpy(&bytes[17], &line->_endX, sizeof(int64_t));
    memcpy(&bytes[25], &line->_endY, sizeof(int64_t));
    line2_clear_error();
    return 33;
}

line2Di64_t *line2Di64_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    int64_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(int64_t));
    memcpy(&startY, &bytes[9], sizeof(int64_t));
    memcpy(&endX, &bytes[17], sizeof(int64_t));
    memcpy(&endY, &bytes[25], sizeof(int64_t));
    return line2Di64_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- float --- */
size_t line2Df_toBytes(const line2Df_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    memcpy(&bytes[1], &line->_startX, sizeof(float));
    memcpy(&bytes[5], &line->_startY, sizeof(float));
    memcpy(&bytes[9], &line->_endX, sizeof(float));
    memcpy(&bytes[13], &line->_endY, sizeof(float));
    line2_clear_error();
    return 17;
}

line2Df_t *line2Df_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    float startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(float));
    memcpy(&startY, &bytes[5], sizeof(float));
    memcpy(&endX, &bytes[9], sizeof(float));
    memcpy(&endY, &bytes[13], sizeof(float));
    return line2Df_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- double --- */
size_t line2Dd_toBytes(const line2Dd_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    memcpy(&bytes[1], &line->_startX, sizeof(double));
    memcpy(&bytes[9], &line->_startY, sizeof(double));
    memcpy(&bytes[17], &line->_endX, sizeof(double));
    memcpy(&bytes[25], &line->_endY, sizeof(double));
    line2_clear_error();
    return 33;
}

line2Dd_t *line2Dd_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    double startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(double));
    memcpy(&startY, &bytes[9], sizeof(double));
    memcpy(&endX, &bytes[17], sizeof(double));
    memcpy(&endY, &bytes[25], sizeof(double));
    return line2Dd_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- long double --- */
size_t line2Dld_toBytes(const line2Dld_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;
    memcpy(&bytes[1], &line->_startX, sizeof(long double));
    memcpy(&bytes[1 + sizeof(long double)], &line->_startY, sizeof(long double));
    memcpy(&bytes[1 + 2 * sizeof(long double)], &line->_endX, sizeof(long double));
    memcpy(&bytes[1 + 3 * sizeof(long double)], &line->_endY, sizeof(long double));
    line2_clear_error();
    return 1 + 4 * sizeof(long double);
}

line2Dld_t *line2Dld_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    long double startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(long double));
    memcpy(&startY, &bytes[1 + sizeof(long double)], sizeof(long double));
    memcpy(&endX, &bytes[1 + 2 * sizeof(long double)], sizeof(long double));
    memcpy(&endY, &bytes[1 + 3 * sizeof(long double)], sizeof(long double));
    return line2Dld_malloc(bytes[0], startX, startY, endX, endY);
}

/* Byte serialization/deserialization (little-endian) */

/* --- u8 --- */
size_t line2Du8_toBytesLE(const line2Du8_t *line, uint8_t *bytes) {
    /* u8 is the same in LE and BE */
    return line2Du8_toBytes(line, bytes);
}

line2Du8_t *line2Du8_fromBytesLE(const uint8_t *bytes) {
    /* u8 is the same in LE and BE */
    return line2Du8_fromBytes(bytes);
}

/* --- i8 --- */
size_t line2Di8_toBytesLE(const line2Di8_t *line, uint8_t *bytes) {
    /* i8 is the same in LE and BE */
    return line2Di8_toBytes(line, bytes);
}

line2Di8_t *line2Di8_fromBytesLE(const uint8_t *bytes) {
    /* i8 is the same in LE and BE */
    return line2Di8_fromBytes(bytes);
}

/* --- u16 --- */
size_t line2Du16_toBytesLE(const line2Du16_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;

    uint16_t startX_le = swap16(line->_startX);
    uint16_t startY_le = swap16(line->_startY);
    uint16_t endX_le = swap16(line->_endX);
    uint16_t endY_le = swap16(line->_endY);

    memcpy(&bytes[1], &startX_le, sizeof(uint16_t));
    memcpy(&bytes[3], &startY_le, sizeof(uint16_t));
    memcpy(&bytes[5], &endX_le, sizeof(uint16_t));
    memcpy(&bytes[7], &endY_le, sizeof(uint16_t));

    line2_clear_error();
    return 9;
}

line2Du16_t *line2Du16_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    uint16_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(uint16_t));
    memcpy(&startY, &bytes[3], sizeof(uint16_t));
    memcpy(&endX, &bytes[5], sizeof(uint16_t));
    memcpy(&endY, &bytes[7], sizeof(uint16_t));

    startX = swap16(startX);
    startY = swap16(startY);
    endX = swap16(endX);
    endY = swap16(endY);

    return line2Du16_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- i16 --- */
size_t line2Di16_toBytesLE(const line2Di16_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;

    int16_t startX_le = (int16_t)swap16((uint16_t)line->_startX);
    int16_t startY_le = (int16_t)swap16((uint16_t)line->_startY);
    int16_t endX_le = (int16_t)swap16((uint16_t)line->_endX);
    int16_t endY_le = (int16_t)swap16((uint16_t)line->_endY);

    memcpy(&bytes[1], &startX_le, sizeof(int16_t));
    memcpy(&bytes[3], &startY_le, sizeof(int16_t));
    memcpy(&bytes[5], &endX_le, sizeof(int16_t));
    memcpy(&bytes[7], &endY_le, sizeof(int16_t));

    line2_clear_error();
    return 9;
}

line2Di16_t *line2Di16_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    int16_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(int16_t));
    memcpy(&startY, &bytes[3], sizeof(int16_t));
    memcpy(&endX, &bytes[5], sizeof(int16_t));
    memcpy(&endY, &bytes[7], sizeof(int16_t));

    startX = (int16_t)swap16((uint16_t)startX);
    startY = (int16_t)swap16((uint16_t)startY);
    endX = (int16_t)swap16((uint16_t)endX);
    endY = (int16_t)swap16((uint16_t)endY);

    return line2Di16_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- u32 --- */
size_t line2Du32_toBytesLE(const line2Du32_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;

    uint32_t startX_le = swap32(line->_startX);
    uint32_t startY_le = swap32(line->_startY);
    uint32_t endX_le = swap32(line->_endX);
    uint32_t endY_le = swap32(line->_endY);

    memcpy(&bytes[1], &startX_le, sizeof(uint32_t));
    memcpy(&bytes[5], &startY_le, sizeof(uint32_t));
    memcpy(&bytes[9], &endX_le, sizeof(uint32_t));
    memcpy(&bytes[13], &endY_le, sizeof(uint32_t));

    line2_clear_error();
    return 17;
}

line2Du32_t *line2Du32_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    uint32_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(uint32_t));
    memcpy(&startY, &bytes[5], sizeof(uint32_t));
    memcpy(&endX, &bytes[9], sizeof(uint32_t));
    memcpy(&endY, &bytes[13], sizeof(uint32_t));

    startX = swap32(startX);
    startY = swap32(startY);
    endX = swap32(endX);
    endY = swap32(endY);

    return line2Du32_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- i32 --- */
size_t line2Di32_toBytesLE(const line2Di32_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;

    int32_t startX_le = (int32_t)swap32((uint32_t)line->_startX);
    int32_t startY_le = (int32_t)swap32((uint32_t)line->_startY);
    int32_t endX_le = (int32_t)swap32((uint32_t)line->_endX);
    int32_t endY_le = (int32_t)swap32((uint32_t)line->_endY);

    memcpy(&bytes[1], &startX_le, sizeof(int32_t));
    memcpy(&bytes[5], &startY_le, sizeof(int32_t));
    memcpy(&bytes[9], &endX_le, sizeof(int32_t));
    memcpy(&bytes[13], &endY_le, sizeof(int32_t));

    line2_clear_error();
    return 17;
}

line2Di32_t *line2Di32_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    int32_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(int32_t));
    memcpy(&startY, &bytes[5], sizeof(int32_t));
    memcpy(&endX, &bytes[9], sizeof(int32_t));
    memcpy(&endY, &bytes[13], sizeof(int32_t));

    startX = (int32_t)swap32((uint32_t)startX);
    startY = (int32_t)swap32((uint32_t)startY);
    endX = (int32_t)swap32((uint32_t)endX);
    endY = (int32_t)swap32((uint32_t)endY);

    return line2Di32_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- u64 --- */
size_t line2Du64_toBytesLE(const line2Du64_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;

    uint64_t startX_le = swap64(line->_startX);
    uint64_t startY_le = swap64(line->_startY);
    uint64_t endX_le = swap64(line->_endX);
    uint64_t endY_le = swap64(line->_endY);

    memcpy(&bytes[1], &startX_le, sizeof(uint64_t));
    memcpy(&bytes[9], &startY_le, sizeof(uint64_t));
    memcpy(&bytes[17], &endX_le, sizeof(uint64_t));
    memcpy(&bytes[25], &endY_le, sizeof(uint64_t));

    line2_clear_error();
    return 33;
}

line2Du64_t *line2Du64_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    uint64_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(uint64_t));
    memcpy(&startY, &bytes[9], sizeof(uint64_t));
    memcpy(&endX, &bytes[17], sizeof(uint64_t));
    memcpy(&endY, &bytes[25], sizeof(uint64_t));

    startX = swap64(startX);
    startY = swap64(startY);
    endX = swap64(endX);
    endY = swap64(endY);

    return line2Du64_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- i64 --- */
size_t line2Di64_toBytesLE(const line2Di64_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;

    int64_t startX_le = (int64_t)swap64((uint64_t)line->_startX);
    int64_t startY_le = (int64_t)swap64((uint64_t)line->_startY);
    int64_t endX_le = (int64_t)swap64((uint64_t)line->_endX);
    int64_t endY_le = (int64_t)swap64((uint64_t)line->_endY);

    memcpy(&bytes[1], &startX_le, sizeof(int64_t));
    memcpy(&bytes[9], &startY_le, sizeof(int64_t));
    memcpy(&bytes[17], &endX_le, sizeof(int64_t));
    memcpy(&bytes[25], &endY_le, sizeof(int64_t));

    line2_clear_error();
    return 33;
}

line2Di64_t *line2Di64_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    int64_t startX, startY, endX, endY;
    memcpy(&startX, &bytes[1], sizeof(int64_t));
    memcpy(&startY, &bytes[9], sizeof(int64_t));
    memcpy(&endX, &bytes[17], sizeof(int64_t));
    memcpy(&endY, &bytes[25], sizeof(int64_t));

    startX = (int64_t)swap64((uint64_t)startX);
    startY = (int64_t)swap64((uint64_t)startY);
    endX = (int64_t)swap64((uint64_t)endX);
    endY = (int64_t)swap64((uint64_t)endY);

    return line2Di64_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- float --- */
size_t line2Df_toBytesLE(const line2Df_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;

    /* For float, we need to handle endianness by treating as uint32_t */
    uint32_t startX_u32, startY_u32, endX_u32, endY_u32;
    memcpy(&startX_u32, &line->_startX, sizeof(float));
    memcpy(&startY_u32, &line->_startY, sizeof(float));
    memcpy(&endX_u32, &line->_endX, sizeof(float));
    memcpy(&endY_u32, &line->_endY, sizeof(float));

    startX_u32 = swap32(startX_u32);
    startY_u32 = swap32(startY_u32);
    endX_u32 = swap32(endX_u32);
    endY_u32 = swap32(endY_u32);

    memcpy(&bytes[1], &startX_u32, sizeof(uint32_t));
    memcpy(&bytes[5], &startY_u32, sizeof(uint32_t));
    memcpy(&bytes[9], &endX_u32, sizeof(uint32_t));
    memcpy(&bytes[13], &endY_u32, sizeof(uint32_t));

    line2_clear_error();
    return 17;
}

line2Df_t *line2Df_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    uint32_t startX_u32, startY_u32, endX_u32, endY_u32;
    memcpy(&startX_u32, &bytes[1], sizeof(uint32_t));
    memcpy(&startY_u32, &bytes[5], sizeof(uint32_t));
    memcpy(&endX_u32, &bytes[9], sizeof(uint32_t));
    memcpy(&endY_u32, &bytes[13], sizeof(uint32_t));

    startX_u32 = swap32(startX_u32);
    startY_u32 = swap32(startY_u32);
    endX_u32 = swap32(endX_u32);
    endY_u32 = swap32(endY_u32);

    float startX, startY, endX, endY;
    memcpy(&startX, &startX_u32, sizeof(float));
    memcpy(&startY, &startY_u32, sizeof(float));
    memcpy(&endX, &endX_u32, sizeof(float));
    memcpy(&endY, &endY_u32, sizeof(float));

    return line2Df_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- double --- */
size_t line2Dd_toBytesLE(const line2Dd_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return 0;
    }
    bytes[0] = line->_type;

    /* For double, we need to handle endianness by treating as uint64_t */
    uint64_t startX_u64, startY_u64, endX_u64, endY_u64;
    memcpy(&startX_u64, &line->_startX, sizeof(double));
    memcpy(&startY_u64, &line->_startY, sizeof(double));
    memcpy(&endX_u64, &line->_endX, sizeof(double));
    memcpy(&endY_u64, &line->_endY, sizeof(double));

    startX_u64 = swap64(startX_u64);
    startY_u64 = swap64(startY_u64);
    endX_u64 = swap64(endX_u64);
    endY_u64 = swap64(endY_u64);

    memcpy(&bytes[1], &startX_u64, sizeof(uint64_t));
    memcpy(&bytes[9], &startY_u64, sizeof(uint64_t));
    memcpy(&bytes[17], &endX_u64, sizeof(uint64_t));
    memcpy(&bytes[25], &endY_u64, sizeof(uint64_t));

    line2_clear_error();
    return 33;
}

line2Dd_t *line2Dd_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line2_set_error(LINE2_ERROR_NULL_POINTER, NULL);
        return NULL;
    }

    uint64_t startX_u64, startY_u64, endX_u64, endY_u64;
    memcpy(&startX_u64, &bytes[1], sizeof(uint64_t));
    memcpy(&startY_u64, &bytes[9], sizeof(uint64_t));
    memcpy(&endX_u64, &bytes[17], sizeof(uint64_t));
    memcpy(&endY_u64, &bytes[25], sizeof(uint64_t));

    startX_u64 = swap64(startX_u64);
    startY_u64 = swap64(startY_u64);
    endX_u64 = swap64(endX_u64);
    endY_u64 = swap64(endY_u64);

    double startX, startY, endX, endY;
    memcpy(&startX, &startX_u64, sizeof(double));
    memcpy(&startY, &startY_u64, sizeof(double));
    memcpy(&endX, &endX_u64, sizeof(double));
    memcpy(&endY, &endY_u64, sizeof(double));

    return line2Dd_malloc(bytes[0], startX, startY, endX, endY);
}

/* --- long double --- */
size_t line2Dld_toBytesLE(const line2Dld_t *line, uint8_t *bytes) {
    /* long double endianness handling is platform-specific and complex */
    /* For simplicity, we'll use the native format */
    return line2Dld_toBytes(line, bytes);
}

line2Dld_t *line2Dld_fromBytesLE(const uint8_t *bytes) {
    /* long double endianness handling is platform-specific and complex */
    /* For simplicity, we'll use the native format */
    return line2Dld_fromBytes(bytes);
}
