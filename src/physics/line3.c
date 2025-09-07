#include "../../include/physics/line3.h"
#include "../../include/math/vec3.h"

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
    LINE3_SUCCESS = 0,
    LINE3_ERROR_MALLOC_FAILED,
    LINE3_ERROR_OVERFLOW,
    LINE3_ERROR_INVALID_DIMENSIONS,
    LINE3_ERROR_ZERO_LENGTH,
    LINE3_ERROR_NULL_POINTER,
    LINE3_ERROR_UNKNOWN
} line3_error_t;

/* global error state */
static line3_error_t line3_last_error = LINE3_SUCCESS;
static const char *line3_error_string = NULL;

static const char *LINE3_ERROR_STRINGS[] = {
    "Success",
    "Memory allocation failed",
    "Line would cause coordinate overflow",
    "Invalid dimensions provided",
    "Zero-length line (start == end)",
    "Null pointer supplied",
    "Unknown error"
};

const char* line3_get_error_string(void) {
    if (line3_error_string != NULL) return line3_error_string;
    size_t idx = (size_t) line3_last_error;
    if (idx < (sizeof(LINE3_ERROR_STRINGS)/sizeof(*LINE3_ERROR_STRINGS))) {
        return LINE3_ERROR_STRINGS[idx];
    }
    return "Invalid error code";
}

/* internal helpers to set/clear errors */
static void line3_clear_error(void) {
    line3_last_error = LINE3_SUCCESS;
    line3_error_string = NULL;
}

static void line3_set_error(line3_error_t e, const char *custom) {
    line3_last_error = e;
    line3_error_string = custom;
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
   Generic math helpers (long double-based to reduce overflow risk)
   --------------------------- */

/* Compute Euclidean length in 3D using long double then return double */
static double compute_length_3d_ld(long double sx, long double sy, long double sz,
                                   long double ex, long double ey, long double ez) {
    long double dx = ex - sx;
    long double dy = ey - sy;
    long double dz = ez - sz;
    long double sum = dx*dx + dy*dy + dz*dz;
    long double r = sqrtl(sum);
    return (double) r;
}

/* Check whether point D (dx,dy,dz) lies on segment ABC inclusive */
static bool on_segment_3d_ld(long double ax, long double ay, long double az,
                             long double bx, long double by, long double bz,
                             long double cx, long double cy, long double cz,
                             long double dx, long double dy, long double dz) {
    // First check if point D is colinear with segment ABC
    long double cross_x = (by - ay) * (cz - az) - (bz - az) * (cy - ay);
    long double cross_y = (bz - az) * (cx - ax) - (bx - ax) * (cz - az);
    long double cross_z = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);

    long double dot_x = (dx - ax) * cross_x;
    long double dot_y = (dy - ay) * cross_y;
    long double dot_z = (dz - az) * cross_z;

    // If not colinear, return false
    if (fabsl(dot_x + dot_y + dot_z) > 1e-18L) return false;

    // Check if D is within the bounding box of ABC
    long double minx = fminl(fminl(ax, bx), cx);
    long double maxx = fmaxl(fmaxl(ax, bx), cx);
    long double miny = fminl(fminl(ay, by), cy);
    long double maxy = fmaxl(fmaxl(ay, by), cy);
    long double minz = fminl(fminl(az, bz), cz);
    long double maxz = fmaxl(fmaxl(az, bz), cz);

    return (dx >= minx - 1e-18L && dx <= maxx + 1e-18L &&
            dy >= miny - 1e-18L && dy <= maxy + 1e-18L &&
            dz >= minz - 1e-18L && dz <= maxz + 1e-18L);
}

/* General segment intersection test in 3D using long double arithmetic */
static bool segments_intersect_3d_ld(long double a1x, long double a1y, long double a1z,
                                     long double a2x, long double a2y, long double a2z,
                                     long double b1x, long double b1y, long double b1z,
                                     long double b2x, long double b2y, long double b2z) {
    // For 3D line intersection, we need to check if they are coplanar and then
    // check if they intersect in that plane

    // Calculate vectors for both lines
    long double ux = a2x - a1x, uy = a2y - a1y, uz = a2z - a1z;
    long double vx = b2x - b1x, vy = b2y - b1y, vz = b2z - b1z;
    long double wx = a1x - b1x, wy = a1y - b1y, wz = a1z - b1z;

    // Calculate cross product of u and v
    long double cross_x = uy * vz - uz * vy;
    long double cross_y = uz * vx - ux * vz;
    long double cross_z = ux * vy - uy * vx;

    // Check if lines are parallel (cross product is zero)
    if (fabsl(cross_x) < 1e-18L && fabsl(cross_y) < 1e-18L && fabsl(cross_z) < 1e-18L) {
        // Lines are parallel, check if they are colinear and overlapping
        // Check if the vector from a1 to b1 is parallel to u
        long double cross2_x = uy * wz - uz * wy;
        long double cross2_y = uz * wx - ux * wz;
        long double cross2_z = ux * wy - uy * wx;

        if (fabsl(cross2_x) > 1e-18L || fabsl(cross2_y) > 1e-18L || fabsl(cross2_z) > 1e-18L) {
            // Not colinear
            return false;
        }

        // Lines are colinear, check if they overlap
        // Project all points onto the line and check for overlap
        long double u_len_sq = ux*ux + uy*uy + uz*uz;
        if (fabsl(u_len_sq) < 1e-18L) {
            // u is zero vector, check if points are the same
            return (fabsl(a1x - b1x) < 1e-18L && fabsl(a1y - b1y) < 1e-18L && fabsl(a1z - b1z) < 1e-18L);
        }

        // Calculate parameters for all points on the line
        long double t_a1 = 0;
        long double t_a2 = (ux*ux + uy*uy + uz*uz) / u_len_sq;
        long double t_b1 = (ux*(b1x - a1x) + uy*(b1y - a1y) + uz*(b1z - a1z)) / u_len_sq;
        long double t_b2 = (ux*(b2x - a1x) + uy*(b2y - a1y) + uz*(b2z - a1z)) / u_len_sq;

        // Find the range of parameters
        long double min_t = fminl(fminl(t_a1, t_a2), fminl(t_b1, t_b2));
        long double max_t = fmaxl(fmaxl(t_a1, t_a2), fmaxl(t_b1, t_b2));

        // Check if the ranges overlap
        return (max_t - min_t) <= (fabsl(t_a2 - t_a1) + fabsl(t_b2 - t_b1) + 1e-18L);
    }

    // Lines are not parallel, check if they are coplanar
    // The scalar triple product (u × v) · w should be zero for coplanar lines
    long double scalar_triple = wx * cross_x + wy * cross_y + wz * cross_z;
    if (fabsl(scalar_triple) > 1e-18L) {
        // Lines are not coplanar, so they don't intersect
        return false;
    }

    // Lines are coplanar, solve for intersection parameters
    // We need to solve: a1 + s*u = b1 + t*v
    // This is a system of 3 equations with 2 unknowns

    // Choose the two equations with the largest determinants for numerical stability
    long double det1 = vy * cross_z - vz * cross_y;
    long double det2 = vz * cross_x - vx * cross_z;
    long double det3 = vx * cross_y - vy * cross_x;

    long double max_det = fmaxl(fmaxl(fabsl(det1), fabsl(det2)), fabsl(det3));

    long double s, t;
    if (max_det == fabsl(det1)) {
        s = (vy * wz - vz * wy) / det1;
        t = (uy * wz - uz * wy) / det1;
    } else if (max_det == fabsl(det2)) {
        s = (vz * wx - vx * wz) / det2;
        t = (uz * wx - ux * wz) / det2;
    } else {
        s = (vx * wy - vy * wx) / det3;
        t = (ux * wy - uy * wx) / det3;
    }

    // Check if the intersection point is within both segments
    if (s < -1e-18L || s > 1.0 + 1e-18L || t < -1e-18L || t > 1.0 + 1e-18L) {
        return false;
    }

    // Calculate the intersection point from both segments
    long double ix1 = a1x + s * ux;
    long double iy1 = a1y + s * uy;
    long double iz1 = a1z + s * uz;

    long double ix2 = b1x + t * vx;
    long double iy2 = b1y + t * vy;
    long double iz2 = b1z + t * vz;

    // Verify that both calculations give the same point (within tolerance)
    return (fabsl(ix1 - ix2) < 1e-18L &&
            fabsl(iy1 - iy2) < 1e-18L &&
            fabsl(iz1 - iz2) < 1e-18L);
}


/* ---------------------------
   Concrete struct definitions
   --------------------------- */

struct line3Du8  {
  uint8_t   _type;
  uint8_t   _startX,_startY,_startZ,_endX,_endY,_endZ;
};
struct line3Di8  {
  uint8_t   _type;
  int8_t    _startX,_startY,_startZ,_endX,_endY,_endZ;
};
struct line3Du16 {
  uint8_t   _type;
  uint16_t  _startX,_startY,_startZ,_endX,_endY,_endZ;
};
struct line3Di16 {
  uint8_t   _type;
  int16_t   _startX,_startY,_startZ,_endX,_endY,_endZ;
};
struct line3Du32 {
  uint8_t   _type;
  uint32_t  _startX,_startY,_startZ,_endX,_endY,_endZ;
};
struct line3Di32 {
  uint8_t   _type;
  int32_t   _startX,_startY,_startZ,_endX,_endY,_endZ;
};
struct line3Du64 {
  uint8_t   _type;
  uint64_t  _startX,_startY,_startZ,_endX,_endY,_endZ;
};
struct line3Di64 {
  uint8_t   _type;
  int64_t   _startX,_startY,_startZ,_endX,_endY,_endZ;
};
struct line3Df   {
  uint8_t   _type;
  float     _startX,_startY,_startZ,_endX,_endY,_endZ;
};
struct line3Dd   {
  uint8_t   _type;
  double    _startX,_startY,_startZ,_endX,_endY,_endZ;
};
struct line3Dld  {
  uint8_t   _type;
  long double _startX,_startY,_startZ,_endX,_endY,_endZ;
};


/* Malloc / constructors implementation */
line3Du8_t * line3Du8_malloc(uint8_t type, uint8_t bx, uint8_t by, uint8_t bz, uint8_t ex, uint8_t ey, uint8_t ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Du8_t *line = malloc(sizeof(line3Du8_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

line3Di8_t * line3Di8_malloc(uint8_t type, int8_t bx, int8_t by, int8_t bz, int8_t ex, int8_t ey, int8_t ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Di8_t *line = malloc(sizeof(line3Di8_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

line3Du16_t * line3Du16_malloc(uint8_t type, uint16_t bx, uint16_t by, uint16_t bz, uint16_t ex, uint16_t ey, uint16_t ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Du16_t *line = malloc(sizeof(line3Du16_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

line3Di16_t * line3Di16_malloc(uint8_t type, int16_t bx, int16_t by, int16_t bz, int16_t ex, int16_t ey, int16_t ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Di16_t *line = malloc(sizeof(line3Di16_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

line3Du32_t * line3Du32_malloc(uint8_t type, uint32_t bx, uint32_t by, uint32_t bz, uint32_t ex, uint32_t ey, uint32_t ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Du32_t *line = malloc(sizeof(line3Du32_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

line3Di32_t * line3Di32_malloc(uint8_t type, int32_t bx, int32_t by, int32_t bz, int32_t ex, int32_t ey, int32_t ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Di32_t *line = malloc(sizeof(line3Di32_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

line3Du64_t * line3Du64_malloc(uint8_t type, uint64_t bx, uint64_t by, uint64_t bz, uint64_t ex, uint64_t ey, uint64_t ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Du64_t *line = malloc(sizeof(line3Du64_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

line3Di64_t * line3Di64_malloc(uint8_t type, int64_t bx, int64_t by, int64_t bz, int64_t ex, int64_t ey, int64_t ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Di64_t *line = malloc(sizeof(line3Di64_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

line3Df_t * line3Df_malloc(uint8_t type, float bx, float by, float bz, float ex, float ey, float ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Df_t *line = malloc(sizeof(line3Df_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

line3Dd_t * line3Dd_malloc(uint8_t type, double bx, double by, double bz, double ex, double ey, double ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Dd_t *line = malloc(sizeof(line3Dd_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

line3Dld_t * line3Dld_malloc(uint8_t type, long double bx, long double by, long double bz, long double ex, long double ey, long double ez) {
    line3_clear_error();

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    line3Dld_t *line = malloc(sizeof(line3Dld_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    line->_type = type;
    line->_startX = bx;
    line->_startY = by;
    line->_startZ = bz;
    line->_endX = ex;
    line->_endY = ey;
    line->_endZ = ez;

    return line;
}

/* Malloc from copy implementation */
line3Du8_t * line3Du8_copy(const line3Du8_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Du8_t *line = malloc(sizeof(line3Du8_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Du8_t));
    return line;
}

line3Di8_t * line3Di8_copy(const line3Di8_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Di8_t *line = malloc(sizeof(line3Di8_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Di8_t));
    return line;
}

line3Du16_t * line3Du16_copy(const line3Du16_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Du16_t *line = malloc(sizeof(line3Du16_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Du16_t));
    return line;
}

line3Di16_t * line3Di16_copy(const line3Di16_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Di16_t *line = malloc(sizeof(line3Di16_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Di16_t));
    return line;
}

line3Du32_t * line3Du32_copy(const line3Du32_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Du32_t *line = malloc(sizeof(line3Du32_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Du32_t));
    return line;
}

line3Di32_t * line3Di32_copy(const line3Di32_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Di32_t *line = malloc(sizeof(line3Di32_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Di32_t));
    return line;
}

line3Du64_t * line3Du64_copy(const line3Du64_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Du64_t *line = malloc(sizeof(line3Du64_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Du64_t));
    return line;
}

line3Di64_t * line3Di64_copy(const line3Di64_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Di64_t *line = malloc(sizeof(line3Di64_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Di64_t));
    return line;
}

line3Df_t * line3Df_copy(const line3Df_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Df_t *line = malloc(sizeof(line3Df_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Df_t));
    return line;
}

line3Dd_t * line3Dd_copy(const line3Dd_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Dd_t *line = malloc(sizeof(line3Dd_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Dd_t));
    return line;
}

line3Dld_t * line3Dld_copy(const line3Dld_t * copy) {
    line3_clear_error();

    if (!copy) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot copy from NULL pointer");
        return NULL;
    }

    line3Dld_t *line = malloc(sizeof(line3Dld_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, copy, sizeof(line3Dld_t));
    return line;
}

/* Move (transfer ownership) via pointer-to-pointer implementation */
line3Du8_t * line3Du8_memmove(line3Du8_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Du8_t *line = *move;
    *move = NULL;
    return line;
}

line3Di8_t * line3Di8_memmove(line3Di8_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Di8_t *line = *move;
    *move = NULL;
    return line;
}

line3Du16_t * line3Du16_memmove(line3Du16_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Du16_t *line = *move;
    *move = NULL;
    return line;
}

line3Di16_t * line3Di16_memmove(line3Di16_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Di16_t *line = *move;
    *move = NULL;
    return line;
}

line3Du32_t * line3Du32_memmove(line3Du32_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Du32_t *line = *move;
    *move = NULL;
    return line;
}

line3Di32_t * line3Di32_memmove(line3Di32_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Di32_t *line = *move;
    *move = NULL;
    return line;
}

line3Du64_t * line3Du64_memmove(line3Du64_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Du64_t *line = *move;
    *move = NULL;
    return line;
}

line3Di64_t * line3Di64_memmove(line3Di64_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Di64_t *line = *move;
    *move = NULL;
    return line;
}

line3Df_t * line3Df_memmove(line3Df_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Df_t *line = *move;
    *move = NULL;
    return line;
}

line3Dd_t * line3Dd_memmove(line3Dd_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Dd_t *line = *move;
    *move = NULL;
    return line;
}

line3Dld_t * line3Dld_memmove(line3Dld_t ** move) {
    line3_clear_error();

    if (!move || !*move) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot move NULL pointer");
        return NULL;
    }

    line3Dld_t *line = *move;
    *move = NULL;
    return line;
}

/* Free / destructors implementation */
void line3Du8_free(line3Du8_t * line) {
    if (line) {
        free(line);
    }
}

void line3Di8_free(line3Di8_t * line) {
    if (line) {
        free(line);
    }
}

void line3Du16_free(line3Du16_t * line) {
    if (line) {
        free(line);
    }
}

void line3Di16_free(line3Di16_t * line) {
    if (line) {
        free(line);
    }
}

void line3Du32_free(line3Du32_t * line) {
    if (line) {
        free(line);
    }
}

void line3Di32_free(line3Di32_t * line) {
    if (line) {
        free(line);
    }
}

void line3Du64_free(line3Du64_t * line) {
    if (line) {
        free(line);
    }
}

void line3Di64_free(line3Di64_t * line) {
    if (line) {
        free(line);
    }
}

void line3Df_free(line3Df_t * line) {
    if (line) {
        free(line);
    }
}

void line3Dd_free(line3Dd_t * line) {
    if (line) {
        free(line);
    }
}

void line3Dld_free(line3Dld_t * line) {
    if (line) {
        free(line);
    }
}

/* Length functions implementation */
double line3Du8_length(const line3Du8_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        (long double)line->_startX, (long double)line->_startY, (long double)line->_startZ,
        (long double)line->_endX, (long double)line->_endY, (long double)line->_endZ
    );
}

double line3Di8_length(const line3Di8_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        (long double)line->_startX, (long double)line->_startY, (long double)line->_startZ,
        (long double)line->_endX, (long double)line->_endY, (long double)line->_endZ
    );
}

double line3Du16_length(const line3Du16_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        (long double)line->_startX, (long double)line->_startY, (long double)line->_startZ,
        (long double)line->_endX, (long double)line->_endY, (long double)line->_endZ
    );
}

double line3Di16_length(const line3Di16_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        (long double)line->_startX, (long double)line->_startY, (long double)line->_startZ,
        (long double)line->_endX, (long double)line->_endY, (long double)line->_endZ
    );
}

double line3Du32_length(const line3Du32_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        (long double)line->_startX, (long double)line->_startY, (long double)line->_startZ,
        (long double)line->_endX, (long double)line->_endY, (long double)line->_endZ
    );
}

double line3Di32_length(const line3Di32_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        (long double)line->_startX, (long double)line->_startY, (long double)line->_startZ,
        (long double)line->_endX, (long double)line->_endY, (long double)line->_endZ
    );
}

double line3Du64_length(const line3Du64_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        (long double)line->_startX, (long double)line->_startY, (long double)line->_startZ,
        (long double)line->_endX, (long double)line->_endY, (long double)line->_endZ
    );
}

double line3Di64_length(const line3Di64_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        (long double)line->_startX, (long double)line->_startY, (long double)line->_startZ,
        (long double)line->_endX, (long double)line->_endY, (long double)line->_endZ
    );
}

double line3Df_length(const line3Df_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        (long double)line->_startX, (long double)line->_startY, (long double)line->_startZ,
        (long double)line->_endX, (long double)line->_endY, (long double)line->_endZ
    );
}

double line3Dd_length(const line3Dd_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        (long double)line->_startX, (long double)line->_startY, (long double)line->_startZ,
        (long double)line->_endX, (long double)line->_endY, (long double)line->_endZ
    );
}

double line3Dld_length(const line3Dld_t * line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot calculate length of NULL line");
        return 0.0;
    }

    return compute_length_3d_ld(
        line->_startX, line->_startY, line->_startZ,
        line->_endX, line->_endY, line->_endZ
    );
}

/* Getters implementation for line3Du8_t */
uint8_t line3Du8_getStartX(line3Du8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartX from NULL line");
        return 0;
    }

    return out->_startX;
}

uint8_t line3Du8_getStartY(line3Du8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartY from NULL line");
        return 0;
    }

    return out->_startY;
}

uint8_t line3Du8_getStartZ(line3Du8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartZ from NULL line");
        return 0;
    }

    return out->_startZ;
}

uint8_t line3Du8_getEndX(line3Du8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndX from NULL line");
        return 0;
    }

    return out->_endX;
}

uint8_t line3Du8_getEndY(line3Du8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndY from NULL line");
        return 0;
    }

    return out->_endY;
}

uint8_t line3Du8_getEndZ(line3Du8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndZ from NULL line");
        return 0;
    }

    return out->_endZ;
}

/* i8 getters implementation */
int8_t line3Di8_getStartX(line3Di8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartX from NULL line");
        return 0;
    }

    return out->_startX;
}

int8_t line3Di8_getStartY(line3Di8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartY from NULL line");
        return 0;
    }

    return out->_startY;
}

int8_t line3Di8_getStartZ(line3Di8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartZ from NULL line");
        return 0;
    }

    return out->_startZ;
}

int8_t line3Di8_getEndX(line3Di8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndX from NULL line");
        return 0;
    }

    return out->_endX;
}

int8_t line3Di8_getEndY(line3Di8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndY from NULL line");
        return 0;
    }

    return out->_endY;
}

int8_t line3Di8_getEndZ(line3Di8_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndZ from NULL line");
        return 0;
    }

    return out->_endZ;
}

/* u16 getters implementation */
uint16_t line3Du16_getStartX(line3Du16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartX from NULL line");
        return 0;
    }

    return out->_startX;
}

uint16_t line3Du16_getStartY(line3Du16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartY from NULL line");
        return 0;
    }

    return out->_startY;
}

uint16_t line3Du16_getStartZ(line3Du16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartZ from NULL line");
        return 0;
    }

    return out->_startZ;
}

uint16_t line3Du16_getEndX(line3Du16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndX from NULL line");
        return 0;
    }

    return out->_endX;
}

uint16_t line3Du16_getEndY(line3Du16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndY from NULL line");
        return 0;
    }

    return out->_endY;
}

uint16_t line3Du16_getEndZ(line3Du16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndZ from NULL line");
        return 0;
    }

    return out->_endZ;
}

/* i16 getters implementation */
int16_t line3Di16_getStartX(line3Di16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartX from NULL line");
        return 0;
    }

    return out->_startX;
}

int16_t line3Di16_getStartY(line3Di16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartY from NULL line");
        return 0;
    }

    return out->_startY;
}

int16_t line3Di16_getStartZ(line3Di16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartZ from NULL line");
        return 0;
    }

    return out->_startZ;
}

int16_t line3Di16_getEndX(line3Di16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndX from NULL line");
        return 0;
    }

    return out->_endX;
}

int16_t line3Di16_getEndY(line3Di16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndY from NULL line");
        return 0;
    }

    return out->_endY;
}

int16_t line3Di16_getEndZ(line3Di16_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndZ from NULL line");
        return 0;
    }

    return out->_endZ;
}

/* u32 getters implementation */
uint32_t line3Du32_getStartX(line3Du32_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartX from NULL line");
        return 0;
    }

    return out->_startX;
}

uint32_t line3Du32_getStartY(line3Du32_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartY from NULL line");
        return 0;
    }

    return out->_startY;
}

uint32_t line3Du32_getStartZ(line3Du32_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartZ from NULL line");
        return 0;
    }

    return out->_startZ;
}

uint32_t line3Du32_getEndX(line3Du32_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndX from NULL line");
        return 0;
    }

    return out->_endX;
}

uint32_t line3Du32_getEndY(line3Du32_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndY from NULL line");
        return 0;
    }

    return out->_endY;
}

uint32_t line3Du32_getEndZ(line3Du32_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndZ from NULL line");
        return 0;
    }

    return out->_endZ;
}

/* i64 getters implementation */
int64_t line3Di64_getStartX(line3Di64_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartX from NULL line");
        return 0;
    }

    return out->_startX;
}

int64_t line3Di64_getStartY(line3Di64_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartY from NULL line");
        return 0;
    }

    return out->_startY;
}

int64_t line3Di64_getStartZ(line3Di64_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartZ from NULL line");
        return 0;
    }

    return out->_startZ;
}

int64_t line3Di64_getEndX(line3Di64_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndX from NULL line");
        return 0;
    }

    return out->_endX;
}

int64_t line3Di64_getEndY(line3Di64_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndY from NULL line");
        return 0;
    }

    return out->_endY;
}

int64_t line3Di64_getEndZ(line3Di64_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndZ from NULL line");
        return 0;
    }

    return out->_endZ;
}

/* float getters implementation */
float line3Df_getStartX(line3Df_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartX from NULL line");
        return 0.0f;
    }

    return out->_startX;
}

float line3Df_getStartY(line3Df_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartY from NULL line");
        return 0.0f;
    }

    return out->_startY;
}

float line3Df_getStartZ(line3Df_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartZ from NULL line");
        return 0.0f;
    }

    return out->_startZ;
}

float line3Df_getEndX(line3Df_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndX from NULL line");
        return 0.0f;
    }

    return out->_endX;
}

float line3Df_getEndY(line3Df_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndY from NULL line");
        return 0.0f;
    }

    return out->_endY;
}

float line3Df_getEndZ(line3Df_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndZ from NULL line");
        return 0.0f;
    }

    return out->_endZ;
}

/* double getters implementation */
double line3Dd_getStartX(line3Dd_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartX from NULL line");
        return 0.0;
    }

    return out->_startX;
}

double line3Dd_getStartY(line3Dd_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartY from NULL line");
        return 0.0;
    }

    return out->_startY;
}

double line3Dd_getStartZ(line3Dd_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartZ from NULL line");
        return 0.0;
    }

    return out->_startZ;
}

double line3Dd_getEndX(line3Dd_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndX from NULL line");
        return 0.0;
    }

    return out->_endX;
}

double line3Dd_getEndY(line3Dd_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndY from NULL line");
        return 0.0;
    }

    return out->_endY;
}

double line3Dd_getEndZ(line3Dd_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndZ from NULL line");
        return 0.0;
    }

    return out->_endZ;
}

/* long double getters implementation */
long double line3Dld_getStartX(line3Dld_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartX from NULL line");
        return 0.0L;
    }

    return out->_startX;
}

long double line3Dld_getStartY(line3Dld_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartY from NULL line");
        return 0.0L;
    }

    return out->_startY;
}

long double line3Dld_getStartZ(line3Dld_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get StartZ from NULL line");
        return 0.0L;
    }

    return out->_startZ;
}

long double line3Dld_getEndX(line3Dld_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndX from NULL line");
        return 0.0L;
    }

    return out->_endX;
}

long double line3Dld_getEndY(line3Dld_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndY from NULL line");
        return 0.0L;
    }

    return out->_endY;
}

long double line3Dld_getEndZ(line3Dld_t * out) {
    line3_clear_error();

    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot get EndZ from NULL line");
        return 0.0L;
    }

    return out->_endZ;
}

/* Setters implementation */
void line3Du8_setStartX(line3Du8_t * out, uint8_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Du8_setStartY(line3Du8_t * out, uint8_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Du8_setStartZ(line3Du8_t * out, uint8_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Du8_setEndX(line3Du8_t * out, uint8_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Du8_setEndY(line3Du8_t * out, uint8_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Du8_setEndZ(line3Du8_t * out, uint8_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* i8 setters implementation */
void line3Di8_setStartX(line3Di8_t * out, int8_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Di8_setStartY(line3Di8_t * out, int8_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Di8_setStartZ(line3Di8_t * out, int8_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Di8_setEndX(line3Di8_t * out, int8_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Di8_setEndY(line3Di8_t * out, int8_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Di8_setEndZ(line3Di8_t * out, int8_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* u16 setters implementation */
void line3Du16_setStartX(line3Du16_t * out, uint16_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Du16_setStartY(line3Du16_t * out, uint16_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Du16_setStartZ(line3Du16_t * out, uint16_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Du16_setEndX(line3Du16_t * out, uint16_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Du16_setEndY(line3Du16_t * out, uint16_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Du16_setEndZ(line3Du16_t * out, uint16_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* i16 setters implementation */
void line3Di16_setStartX(line3Di16_t * out, int16_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Di16_setStartY(line3Di16_t * out, int16_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Di16_setStartZ(line3Di16_t * out, int16_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Di16_setEndX(line3Di16_t * out, int16_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Di16_setEndY(line3Di16_t * out, int16_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Di16_setEndZ(line3Di16_t * out, int16_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* u32 setters implementation */
void line3Du32_setStartX(line3Du32_t * out, uint32_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Du32_setStartY(line3Du32_t * out, uint32_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Du32_setStartZ(line3Du32_t * out, uint32_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Du32_setEndX(line3Du32_t * out, uint32_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Du32_setEndY(line3Du32_t * out, uint32_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Du32_setEndZ(line3Du32_t * out, uint32_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* i32 setters implementation */
void line3Di32_setStartX(line3Di32_t * out, int32_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Di32_setStartY(line3Di32_t * out, int32_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Di32_setStartZ(line3Di32_t * out, int32_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Di32_setEndX(line3Di32_t * out, int32_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Di32_setEndY(line3Di32_t * out, int32_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Di32_setEndZ(line3Di32_t * out, int32_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* u64 setters implementation */
void line3Du64_setStartX(line3Du64_t * out, uint64_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Du64_setStartY(line3Du64_t * out, uint64_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Du64_setStartZ(line3Du64_t * out, uint64_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Du64_setEndX(line3Du64_t * out, uint64_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Du64_setEndY(line3Du64_t * out, uint64_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Du64_setEndZ(line3Du64_t * out, uint64_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* i64 setters implementation */
void line3Di64_setStartX(line3Di64_t * out, int64_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Di64_setStartY(line3Di64_t * out, int64_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Di64_setStartZ(line3Di64_t * out, int64_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Di64_setEndX(line3Di64_t * out, int64_t x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Di64_setEndY(line3Di64_t * out, int64_t y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Di64_setEndZ(line3Di64_t * out, int64_t z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* float setters implementation */
void line3Df_setStartX(line3Df_t * out, float x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Df_setStartY(line3Df_t * out, float y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Df_setStartZ(line3Df_t * out, float z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Df_setEndX(line3Df_t * out, float x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Df_setEndY(line3Df_t * out, float y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Df_setEndZ(line3Df_t * out, float z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* double setters implementation */
void line3Dd_setStartX(line3Dd_t * out, double x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Dd_setStartY(line3Dd_t * out, double y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Dd_setStartZ(line3Dd_t * out, double z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Dd_setEndX(line3Dd_t * out, double x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Dd_setEndY(line3Dd_t * out, double y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Dd_setEndZ(line3Dd_t * out, double z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* long double setters implementation */
void line3Dld_setStartX(line3Dld_t * out, long double x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartX on NULL line");
        return;
    }
    out->_startX = x;
}

void line3Dld_setStartY(line3Dld_t * out, long double y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartY on NULL line");
        return;
    }
    out->_startY = y;
}

void line3Dld_setStartZ(line3Dld_t * out, long double z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set StartZ on NULL line");
        return;
    }
    out->_startZ = z;
}

void line3Dld_setEndX(line3Dld_t * out, long double x) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndX on NULL line");
        return;
    }
    out->_endX = x;
}

void line3Dld_setEndY(line3Dld_t * out, long double y) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndY on NULL line");
        return;
    }
    out->_endY = y;
}

void line3Dld_setEndZ(line3Dld_t * out, long double z) {
    line3_clear_error();
    if (!out) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot set EndZ on NULL line");
        return;
    }
    out->_endZ = z;
}

/* Intersection tests implementation */
bool line3Du8_intersects(line3Du8_t * first, line3Du8_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        (long double)first->_startX, (long double)first->_startY, (long double)first->_startZ,
        (long double)first->_endX, (long double)first->_endY, (long double)first->_endZ,
        (long double)second->_startX, (long double)second->_startY, (long double)second->_startZ,
        (long double)second->_endX, (long double)second->_endY, (long double)second->_endZ
    );
}

bool line3Di8_intersects(line3Di8_t * first, line3Di8_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        (long double)first->_startX, (long double)first->_startY, (long double)first->_startZ,
        (long double)first->_endX, (long double)first->_endY, (long double)first->_endZ,
        (long double)second->_startX, (long double)second->_startY, (long double)second->_startZ,
        (long double)second->_endX, (long double)second->_endY, (long double)second->_endZ
    );
}

bool line3Du16_intersects(line3Du16_t * first, line3Du16_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        (long double)first->_startX, (long double)first->_startY, (long double)first->_startZ,
        (long double)first->_endX, (long double)first->_endY, (long double)first->_endZ,
        (long double)second->_startX, (long double)second->_startY, (long double)second->_startZ,
        (long double)second->_endX, (long double)second->_endY, (long double)second->_endZ
    );
}

bool line3Di16_intersects(line3Di16_t * first, line3Di16_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        (long double)first->_startX, (long double)first->_startY, (long double)first->_startZ,
        (long double)first->_endX, (long double)first->_endY, (long double)first->_endZ,
        (long double)second->_startX, (long double)second->_startY, (long double)second->_startZ,
        (long double)second->_endX, (long double)second->_endY, (long double)second->_endZ
    );
}

bool line3Du32_intersects(line3Du32_t * first, line3Du32_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        (long double)first->_startX, (long double)first->_startY, (long double)first->_startZ,
        (long double)first->_endX, (long double)first->_endY, (long double)first->_endZ,
        (long double)second->_startX, (long double)second->_startY, (long double)second->_startZ,
        (long double)second->_endX, (long double)second->_endY, (long double)second->_endZ
    );
}

bool line3Di32_intersects(line3Di32_t * first, line3Di32_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        (long double)first->_startX, (long double)first->_startY, (long double)first->_startZ,
        (long double)first->_endX, (long double)first->_endY, (long double)first->_endZ,
        (long double)second->_startX, (long double)second->_startY, (long double)second->_startZ,
        (long double)second->_endX, (long double)second->_endY, (long double)second->_endZ
    );
}

bool line3Du64_intersects(line3Du64_t * first, line3Du64_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        (long double)first->_startX, (long double)first->_startY, (long double)first->_startZ,
        (long double)first->_endX, (long double)first->_endY, (long double)first->_endZ,
        (long double)second->_startX, (long double)second->_startY, (long double)second->_startZ,
        (long double)second->_endX, (long double)second->_endY, (long double)second->_endZ
    );
}

bool line3Di64_intersects(line3Di64_t * first, line3Di64_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        (long double)first->_startX, (long double)first->_startY, (long double)first->_startZ,
        (long double)first->_endX, (long double)first->_endY, (long double)first->_endZ,
        (long double)second->_startX, (long double)second->_startY, (long double)second->_startZ,
        (long double)second->_endX, (long double)second->_endY, (long double)second->_endZ
    );
}

bool line3Df_intersects(line3Df_t * first, line3Df_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        (long double)first->_startX, (long double)first->_startY, (long double)first->_startZ,
        (long double)first->_endX, (long double)first->_endY, (long double)first->_endZ,
        (long double)second->_startX, (long double)second->_startY, (long double)second->_startZ,
        (long double)second->_endX, (long double)second->_endY, (long double)second->_endZ
    );
}

bool line3Dd_intersects(line3Dd_t * first, line3Dd_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        (long double)first->_startX, (long double)first->_startY, (long double)first->_startZ,
        (long double)first->_endX, (long double)first->_endY, (long double)first->_endZ,
        (long double)second->_startX, (long double)second->_startY, (long double)second->_startZ,
        (long double)second->_endX, (long double)second->_endY, (long double)second->_endZ
    );
}

bool line3Dld_intersects(line3Dld_t * first, line3Dld_t * second) {
    line3_clear_error();

    if (!first || !second) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot check intersection with NULL line");
        return false;
    }

    return segments_intersect_3d_ld(
        first->_startX, first->_startY, first->_startZ,
        first->_endX, first->_endY, first->_endZ,
        second->_startX, second->_startY, second->_startZ,
        second->_endX, second->_endY, second->_endZ
    );
}

/* String conversion functions implementation */
char* line3Du8_toString(const line3Du8_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(64); // Enough space for all coordinates and type
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 64, "%u %u %u %u %u %u %u",
             line->_type,
             line->_startX, line->_startY, line->_startZ,
             line->_endX, line->_endY, line->_endZ);

    return str;
}

char* line3Di8_toString(const line3Di8_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(64);
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 64, "%u %d %d %d %d %d %d",
             line->_type,
             line->_startX, line->_startY, line->_startZ,
             line->_endX, line->_endY, line->_endZ);

    return str;
}

char* line3Du16_toString(const line3Du16_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(128);
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 128, "%u %u %u %u %u %u %u",
             line->_type,
             line->_startX, line->_startY, line->_startZ,
             line->_endX, line->_endY, line->_endZ);

    return str;
}

char* line3Di16_toString(const line3Di16_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(128);
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 128, "%u %d %d %d %d %d %d",
             line->_type,
             line->_startX, line->_startY, line->_startZ,
             line->_endX, line->_endY, line->_endZ);

    return str;
}

char* line3Du32_toString(const line3Du32_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(256);
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 256, "%u %u %u %u %u %u %u",
             line->_type,
             line->_startX, line->_startY, line->_startZ,
             line->_endX, line->_endY, line->_endZ);

    return str;
}

char* line3Di32_toString(const line3Di32_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(256);
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 256, "%u %d %d %d %d %d %d",
             line->_type,
             line->_startX, line->_startY, line->_startZ,
             line->_endX, line->_endY, line->_endZ);

    return str;
}

char* line3Du64_toString(const line3Du64_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(512);
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 512, "%u %llu %llu %llu %llu %llu %llu",
             line->_type,
             (unsigned long long)line->_startX, (unsigned long long)line->_startY, (unsigned long long)line->_startZ,
             (unsigned long long)line->_endX, (unsigned long long)line->_endY, (unsigned long long)line->_endZ);

    return str;
}

char* line3Di64_toString(const line3Di64_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(512);
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 512, "%u %lld %lld %lld %lld %lld %lld",
             line->_type,
             (long long)line->_startX, (long long)line->_startY, (long long)line->_startZ,
             (long long)line->_endX, (long long)line->_endY, (long long)line->_endZ);

    return str;
}

char* line3Df_toString(const line3Df_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(256);
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 256, "%u %.6g %.6g %.6g %.6g %.6g %.6g",
             line->_type,
             line->_startX, line->_startY, line->_startZ,
             line->_endX, line->_endY, line->_endZ);

    return str;
}

char* line3Dd_toString(const line3Dd_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(512);
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 512, "%u %.15g %.15g %.15g %.15g %.15g %.15g",
             line->_type,
             line->_startX, line->_startY, line->_startZ,
             line->_endX, line->_endY, line->_endZ);

    return str;
}

char* line3Dld_toString(const line3Dld_t* line) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot convert NULL line to string");
        return NULL;
    }

    char* str = malloc(1024);
    if (!str) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    snprintf(str, 1024, "%u %.21Lg %.21Lg %.21Lg %.21Lg %.21Lg %.21Lg",
             line->_type,
             line->_startX, line->_startY, line->_startZ,
             line->_endX, line->_endY, line->_endZ);

    return str;
}

/* fromString functions implementation */
line3Du8_t* line3Du8_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    uint8_t sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %hhu %hhu %hhu %hhu %hhu %hhu",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    return line3Du8_malloc(type, sx, sy, sz, ex, ey, ez);
}

line3Di8_t* line3Di8_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    int8_t sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %hhd %hhd %hhd %hhd %hhd %hhd",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    return line3Di8_malloc(type, sx, sy, sz, ex, ey, ez);
}

line3Du16_t* line3Du16_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    uint16_t sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %hu %hu %hu %hu %hu %hu",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    return line3Du16_malloc(type, sx, sy, sz, ex, ey, ez);
}

line3Di16_t* line3Di16_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    int16_t sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %hd %hd %hd %hd %hd %hd",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    return line3Di16_malloc(type, sx, sy, sz, ex, ey, ez);
}

line3Du32_t* line3Du32_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    uint32_t sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %u %u %u %u %u %u",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    return line3Du32_malloc(type, sx, sy, sz, ex, ey, ez);
}

line3Di32_t* line3Di32_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    int32_t sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %d %d %d %d %d %d",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    return line3Di32_malloc(type, sx, sy, sz, ex, ey, ez);
}

line3Du64_t* line3Du64_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    unsigned long long sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %llu %llu %llu %llu %llu %llu",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    // Check for overflow
    if (sx > UINT64_MAX || sy > UINT64_MAX || sz > UINT64_MAX ||
        ex > UINT64_MAX || ey > UINT64_MAX || ez > UINT64_MAX) {
        line3_set_error(LINE3_ERROR_OVERFLOW, "Value too large for uint64_t");
        return NULL;
    }

    return line3Du64_malloc(type, (uint64_t)sx, (uint64_t)sy, (uint64_t)sz,
                           (uint64_t)ex, (uint64_t)ey, (uint64_t)ez);
}

line3Di64_t* line3Di64_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    long long sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %lld %lld %lld %lld %lld %lld",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    // Check for overflow
    if (sx > INT64_MAX || sx < INT64_MIN ||
        sy > INT64_MAX || sy < INT64_MIN ||
        sz > INT64_MAX || sz < INT64_MIN ||
        ex > INT64_MAX || ex < INT64_MIN ||
        ey > INT64_MAX || ey < INT64_MIN ||
        ez > INT64_MAX || ez < INT64_MIN) {
        line3_set_error(LINE3_ERROR_OVERFLOW, "Value out of range for int64_t");
        return NULL;
    }

    return line3Di64_malloc(type, (int64_t)sx, (int64_t)sy, (int64_t)sz,
                           (int64_t)ex, (int64_t)ey, (int64_t)ez);
}

line3Df_t* line3Df_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    float sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %f %f %f %f %f %f",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    return line3Df_malloc(type, sx, sy, sz, ex, ey, ez);
}

line3Dd_t* line3Dd_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    double sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %lf %lf %lf %lf %lf %lf",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    return line3Dd_malloc(type, sx, sy, sz, ex, ey, ez);
}

line3Dld_t* line3Dld_fromString(const char* str) {
    line3_clear_error();

    if (!str) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot parse NULL string");
        return NULL;
    }

    char* trimmed = trim_whitespace((char*)str);
    if (!trimmed || strlen(trimmed) == 0) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Empty string provided");
        return NULL;
    }

    uint8_t type;
    long double sx, sy, sz, ex, ey, ez;

    int parsed = sscanf(trimmed, "%hhu %Lf %Lf %Lf %Lf %Lf %Lf",
                        &type, &sx, &sy, &sz, &ex, &ey, &ez);

    if (parsed != 7) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid string format");
        return NULL;
    }

    if (type != LINE_TYPE_LINE && type != LINE_TYPE_VECTOR) {
        line3_set_error(LINE3_ERROR_INVALID_DIMENSIONS, "Invalid line type");
        return NULL;
    }

    return line3Dld_malloc(type, sx, sy, sz, ex, ey, ez);
}

/* Translation functions implementation */
void line3Du8_translate(line3Du8_t *line, uint8_t x, uint8_t y, uint8_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Du8_translateX(line3Du8_t *line, uint8_t x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Du8_translateY(line3Du8_t *line, uint8_t y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Du8_translateZ(line3Du8_t *line, uint8_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Du8_translateLine(line3Du8_t *outLine, const line3Du8_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    uint8_t dx = line->_endX - line->_startX;
    uint8_t dy = line->_endY - line->_startY;
    uint8_t dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* i8 translation functions */
void line3Di8_translate(line3Di8_t *line, int8_t x, int8_t y, int8_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Di8_translateX(line3Di8_t *line, int8_t x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Di8_translateY(line3Di8_t *line, int8_t y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Di8_translateZ(line3Di8_t *line, int8_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Di8_translateLine(line3Di8_t *outLine, const line3Di8_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    int8_t dx = line->_endX - line->_startX;
    int8_t dy = line->_endY - line->_startY;
    int8_t dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* u16 translation functions */
void line3Du16_translate(line3Du16_t *line, uint16_t x, uint16_t y, uint16_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Du16_translateX(line3Du16_t *line, uint16_t x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Du16_translateY(line3Du16_t *line, uint16_t y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Du16_translateZ(line3Du16_t *line, uint16_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Du16_translateLine(line3Du16_t *outLine, const line3Du16_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    uint16_t dx = line->_endX - line->_startX;
    uint16_t dy = line->_endY - line->_startY;
    uint16_t dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* i16 translation functions */
void line3Di16_translate(line3Di16_t *line, int16_t x, int16_t y, int16_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Di16_translateX(line3Di16_t *line, int16_t x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Di16_translateY(line3Di16_t *line, int16_t y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Di16_translateZ(line3Di16_t *line, int16_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Di16_translateLine(line3Di16_t *outLine, const line3Di16_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    int16_t dx = line->_endX - line->_startX;
    int16_t dy = line->_endY - line->_startY;
    int16_t dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* u32 translation functions */
void line3Du32_translate(line3Du32_t *line, uint32_t x, uint32_t y, uint32_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Du32_translateX(line3Du32_t *line, uint32_t x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Du32_translateY(line3Du32_t *line, uint32_t y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Du32_translateZ(line3Du32_t *line, uint32_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Du32_translateLine(line3Du32_t *outLine, const line3Du32_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    uint32_t dx = line->_endX - line->_startX;
    uint32_t dy = line->_endY - line->_startY;
    uint32_t dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* i32 translation functions */
void line3Di32_translate(line3Di32_t *line, int32_t x, int32_t y, int32_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Di32_translateX(line3Di32_t *line, int32_t x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Di32_translateY(line3Di32_t *line, int32_t y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Di32_translateZ(line3Di32_t *line, int32_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Di32_translateLine(line3Di32_t *outLine, const line3Di32_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    int32_t dx = line->_endX - line->_startX;
    int32_t dy = line->_endY - line->_startY;
    int32_t dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* u64 translation functions */
void line3Du64_translate(line3Du64_t *line, uint64_t x, uint64_t y, uint64_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Du64_translateX(line3Du64_t *line, uint64_t x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Du64_translateY(line3Du64_t *line, uint64_t y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Du64_translateZ(line3Du64_t *line, uint64_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Du64_translateLine(line3Du64_t *outLine, const line3Du64_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    uint64_t dx = line->_endX - line->_startX;
    uint64_t dy = line->_endY - line->_startY;
    uint64_t dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* i64 translation functions */
void line3Di64_translate(line3Di64_t *line, int64_t x, int64_t y, int64_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Di64_translateX(line3Di64_t *line, int64_t x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Di64_translateY(line3Di64_t *line, int64_t y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Di64_translateZ(line3Di64_t *line, int64_t z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Di64_translateLine(line3Di64_t *outLine, const line3Di64_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    int64_t dx = line->_endX - line->_startX;
    int64_t dy = line->_endY - line->_startY;
    int64_t dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* float translation functions */
void line3Df_translate(line3Df_t *line, float x, float y, float z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Df_translateX(line3Df_t *line, float x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Df_translateY(line3Df_t *line, float y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Df_translateZ(line3Df_t *line, float z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Df_translateLine(line3Df_t *outLine, const line3Df_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    float dx = line->_endX - line->_startX;
    float dy = line->_endY - line->_startY;
    float dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* double translation functions */
void line3Dd_translate(line3Dd_t *line, double x, double y, double z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Dd_translateX(line3Dd_t *line, double x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Dd_translateY(line3Dd_t *line, double y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Dd_translateZ(line3Dd_t *line, double z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Dd_translateLine(line3Dd_t *outLine, const line3Dd_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    double dx = line->_endX - line->_startX;
    double dy = line->_endY - line->_startY;
    double dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* long double translation functions */
void line3Dld_translate(line3Dld_t *line, long double x, long double y, long double z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_startY += y;
    line->_startZ += z;
    line->_endX += x;
    line->_endY += y;
    line->_endZ += z;
}

void line3Dld_translateX(line3Dld_t *line, long double x) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startX += x;
    line->_endX += x;
}

void line3Dld_translateY(line3Dld_t *line, long double y) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startY += y;
    line->_endY += y;
}

void line3Dld_translateZ(line3Dld_t *line, long double z) {
    line3_clear_error();

    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate NULL line");
        return;
    }

    line->_startZ += z;
    line->_endZ += z;
}

void line3Dld_translateLine(line3Dld_t *outLine, const line3Dld_t *line) {
    line3_clear_error();

    if (!outLine || !line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot translate with NULL line");
        return;
    }

    long double dx = line->_endX - line->_startX;
    long double dy = line->_endY - line->_startY;
    long double dz = line->_endZ - line->_startZ;

    outLine->_startX += dx;
    outLine->_startY += dy;
    outLine->_startZ += dz;
    outLine->_endX += dx;
    outLine->_endY += dy;
    outLine->_endZ += dz;
}

/* Array serialization/deserialization implementation */
void line3Du8_toArray(const line3Du8_t *line, uint8_t arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Du8_t *line3Du8_fromArray(const uint8_t arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Du8_malloc(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

void line3Di8_toArray(const line3Di8_t *line, int8_t arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = (int8_t)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Di8_t *line3Di8_fromArray(const int8_t arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Di8_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

void line3Du16_toArray(const line3Du16_t *line, uint16_t arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Du16_t *line3Du16_fromArray(const uint16_t arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Du16_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

void line3Di16_toArray(const line3Di16_t *line, int16_t arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = (int16_t)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Di16_t *line3Di16_fromArray(const int16_t arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Di16_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

void line3Du32_toArray(const line3Du32_t *line, uint32_t arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Du32_t *line3Du32_fromArray(const uint32_t arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Du32_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

void line3Di32_toArray(const line3Di32_t *line, int32_t arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = (int32_t)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Di32_t *line3Di32_fromArray(const int32_t arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Di32_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

void line3Du64_toArray(const line3Du64_t *line, uint64_t arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Du64_t *line3Du64_fromArray(const uint64_t arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Du64_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

void line3Di64_toArray(const line3Di64_t *line, int64_t arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = (int64_t)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Di64_t *line3Di64_fromArray(const int64_t arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Di64_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

void line3Df_toArray(const line3Df_t *line, float arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = (float)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Df_t *line3Df_fromArray(const float arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Df_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

void line3Dd_toArray(const line3Dd_t *line, double arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = (double)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Dd_t *line3Dd_fromArray(const double arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Dd_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

void line3Dld_toArray(const line3Dld_t *line, long double arr[7]) {
    if (!line || !arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return;
    }

    arr[0] = (long double)line->_type;
    arr[1] = line->_startX;
    arr[2] = line->_startY;
    arr[3] = line->_startZ;
    arr[4] = line->_endX;
    arr[5] = line->_endY;
    arr[6] = line->_endZ;
}

line3Dld_t *line3Dld_fromArray(const long double arr[7]) {
    if (!arr) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL array");
        return NULL;
    }

    return line3Dld_malloc((uint8_t)arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
}

/* Byte serialization/deserialization (native byte order) implementation */

/* Helper function to calculate size of each line type */
size_t line3Du8_size(void) { return sizeof(line3Du8_t); }
size_t line3Di8_size(void) { return sizeof(line3Di8_t); }
size_t line3Du16_size(void) { return sizeof(line3Du16_t); }
size_t line3Di16_size(void) { return sizeof(line3Di16_t); }
size_t line3Du32_size(void) { return sizeof(line3Du32_t); }
size_t line3Di32_size(void) { return sizeof(line3Di32_t); }
size_t line3Du64_size(void) { return sizeof(line3Du64_t); }
size_t line3Di64_size(void) { return sizeof(line3Di64_t); }
size_t line3Df_size(void) { return sizeof(line3Df_t); }
size_t line3Dd_size(void) { return sizeof(line3Dd_t); }
size_t line3Dld_size(void) { return sizeof(line3Dld_t); }

/* u8 byte functions */
size_t line3Du8_toBytes(const line3Du8_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Du8_t));
    return sizeof(line3Du8_t);
}

line3Du8_t *line3Du8_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Du8_t *line = malloc(sizeof(line3Du8_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Du8_t));
    return line;
}

/* i8 byte functions */
size_t line3Di8_toBytes(const line3Di8_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Di8_t));
    return sizeof(line3Di8_t);
}

line3Di8_t *line3Di8_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Di8_t *line = malloc(sizeof(line3Di8_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Di8_t));
    return line;
}

/* u16 byte functions */
size_t line3Du16_toBytes(const line3Du16_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Du16_t));
    return sizeof(line3Du16_t);
}

line3Du16_t *line3Du16_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Du16_t *line = malloc(sizeof(line3Du16_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Du16_t));
    return line;
}

/* i16 byte functions */
size_t line3Di16_toBytes(const line3Di16_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Di16_t));
    return sizeof(line3Di16_t);
}

line3Di16_t *line3Di16_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Di16_t *line = malloc(sizeof(line3Di16_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Di16_t));
    return line;
}

/* u32 byte functions */
size_t line3Du32_toBytes(const line3Du32_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Du32_t));
    return sizeof(line3Du32_t);
}

line3Du32_t *line3Du32_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Du32_t *line = malloc(sizeof(line3Du32_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Du32_t));
    return line;
}

/* i32 byte functions */
size_t line3Di32_toBytes(const line3Di32_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Di32_t));
    return sizeof(line3Di32_t);
}

line3Di32_t *line3Di32_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Di32_t *line = malloc(sizeof(line3Di32_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Di32_t));
    return line;
}

/* u64 byte functions */
size_t line3Du64_toBytes(const line3Du64_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Du64_t));
    return sizeof(line3Du64_t);
}

line3Du64_t *line3Du64_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Du64_t *line = malloc(sizeof(line3Du64_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Du64_t));
    return line;
}

/* i64 byte functions */
size_t line3Di64_toBytes(const line3Di64_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Di64_t));
    return sizeof(line3Di64_t);
}

line3Di64_t *line3Di64_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Di64_t *line = malloc(sizeof(line3Di64_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Di64_t));
    return line;
}

/* float byte functions */
size_t line3Df_toBytes(const line3Df_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Df_t));
    return sizeof(line3Df_t);
}

line3Df_t *line3Df_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Df_t *line = malloc(sizeof(line3Df_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Df_t));
    return line;
}

/* double byte functions */
size_t line3Dd_toBytes(const line3Dd_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Dd_t));
    return sizeof(line3Dd_t);
}

line3Dd_t *line3Dd_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Dd_t *line = malloc(sizeof(line3Dd_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Dd_t));
    return line;
}

/* long double byte functions */
size_t line3Dld_toBytes(const line3Dld_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize/deserialize NULL pointer");
        return 0;
    }

    memcpy(bytes, line, sizeof(line3Dld_t));
    return sizeof(line3Dld_t);
}

line3Dld_t *line3Dld_fromBytes(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Dld_t *line = malloc(sizeof(line3Dld_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    memcpy(line, bytes, sizeof(line3Dld_t));
    return line;
}

/* Helper functions for little-endian conversion */
static uint16_t read_le16(const uint8_t *bytes) {
    return (uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8);
}

static void write_le16(uint8_t *bytes, uint16_t value) {
    bytes[0] = (uint8_t)(value);
    bytes[1] = (uint8_t)(value >> 8);
}

static uint32_t read_le32(const uint8_t *bytes) {
    return (uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8) |
           ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[3] << 24);
}

static void write_le32(uint8_t *bytes, uint32_t value) {
    bytes[0] = (uint8_t)(value);
    bytes[1] = (uint8_t)(value >> 8);
    bytes[2] = (uint8_t)(value >> 16);
    bytes[3] = (uint8_t)(value >> 24);
}

static uint64_t read_le64(const uint8_t *bytes) {
    return (uint64_t)bytes[0] | ((uint64_t)bytes[1] << 8) |
           ((uint64_t)bytes[2] << 16) | ((uint64_t)bytes[3] << 24) |
           ((uint64_t)bytes[4] << 32) | ((uint64_t)bytes[5] << 40) |
           ((uint64_t)bytes[6] << 48) | ((uint64_t)bytes[7] << 56);
}

static void write_le64(uint8_t *bytes, uint64_t value) {
    bytes[0] = (uint8_t)(value);
    bytes[1] = (uint8_t)(value >> 8);
    bytes[2] = (uint8_t)(value >> 16);
    bytes[3] = (uint8_t)(value >> 24);
    bytes[4] = (uint8_t)(value >> 32);
    bytes[5] = (uint8_t)(value >> 40);
    bytes[6] = (uint8_t)(value >> 48);
    bytes[7] = (uint8_t)(value >> 56);
}

static float read_le32_float(const uint8_t *bytes) {
    union {
        uint32_t i;
        float f;
    } u;
    u.i = read_le32(bytes);
    return u.f;
}

static void write_le32_float(uint8_t *bytes, float value) {
    union {
        uint32_t i;
        float f;
    } u;
    u.f = value;
    write_le32(bytes, u.i);
}

static double read_le64_double(const uint8_t *bytes) {
    union {
        uint64_t i;
        double d;
    } u;
    u.i = read_le64(bytes);
    return u.d;
}

static void write_le64_double(uint8_t *bytes, double value) {
    union {
        uint64_t i;
        double d;
    } u;
    u.d = value;
    write_le64(bytes, u.i);
}

/* For long double, we need to handle platform-specific sizes */
/* We'll use a byte-by-byte copy for long double */
static void write_le_longdouble(uint8_t *bytes, long double value, size_t size) {
    union {
        long double ld;
        uint8_t b[sizeof(long double)];
    } u;
    u.ld = value;

    /* Copy bytes in little-endian order */
    for (size_t i = 0; i < size; i++) {
        bytes[i] = u.b[i];
    }
}

static long double read_le_longdouble(const uint8_t *bytes, size_t size) {
    union {
        long double ld;
        uint8_t b[sizeof(long double)];
    } u;

    /* Copy bytes from little-endian representation */
    for (size_t i = 0; i < size; i++) {
        u.b[i] = bytes[i];
    }

    return u.ld;
}

/* Byte serialization/deserialization (little-endian) implementation */

/* u8 byte functions (same as native since single byte) */
size_t line3Du8_toBytesLE(const line3Du8_t *line, uint8_t *bytes) {
    return line3Du8_toBytes(line, bytes);
}

line3Du8_t *line3Du8_fromBytesLE(const uint8_t *bytes) {
    return line3Du8_fromBytes(bytes);
}

/* i8 byte functions (same as native since single byte) */
size_t line3Di8_toBytesLE(const line3Di8_t *line, uint8_t *bytes) {
    return line3Di8_toBytes(line, bytes);
}

line3Di8_t *line3Di8_fromBytesLE(const uint8_t *bytes) {
    return line3Di8_fromBytes(bytes);
}

/* u16 byte functions */
size_t line3Du16_toBytesLE(const line3Du16_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize NULL pointer");
        return 0;
    }

    size_t offset = 0;
    bytes[offset++] = line->_type;

    write_le16(bytes + offset, line->_startX); offset += 2;
    write_le16(bytes + offset, line->_startY); offset += 2;
    write_le16(bytes + offset, line->_startZ); offset += 2;
    write_le16(bytes + offset, line->_endX); offset += 2;
    write_le16(bytes + offset, line->_endY); offset += 2;
    write_le16(bytes + offset, line->_endZ); offset += 2;

    return offset;
}

line3Du16_t *line3Du16_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Du16_t *line = malloc(sizeof(line3Du16_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    size_t offset = 0;
    line->_type = bytes[offset++];

    line->_startX = read_le16(bytes + offset); offset += 2;
    line->_startY = read_le16(bytes + offset); offset += 2;
    line->_startZ = read_le16(bytes + offset); offset += 2;
    line->_endX = read_le16(bytes + offset); offset += 2;
    line->_endY = read_le16(bytes + offset); offset += 2;
    line->_endZ = read_le16(bytes + offset); offset += 2;

    return line;
}

/* i16 byte functions */
size_t line3Di16_toBytesLE(const line3Di16_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize NULL pointer");
        return 0;
    }

    size_t offset = 0;
    bytes[offset++] = line->_type;

    write_le16(bytes + offset, (uint16_t)line->_startX); offset += 2;
    write_le16(bytes + offset, (uint16_t)line->_startY); offset += 2;
    write_le16(bytes + offset, (uint16_t)line->_startZ); offset += 2;
    write_le16(bytes + offset, (uint16_t)line->_endX); offset += 2;
    write_le16(bytes + offset, (uint16_t)line->_endY); offset += 2;
    write_le16(bytes + offset, (uint16_t)line->_endZ); offset += 2;

    return offset;
}

line3Di16_t *line3Di16_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Di16_t *line = malloc(sizeof(line3Di16_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    size_t offset = 0;
    line->_type = bytes[offset++];

    line->_startX = (int16_t)read_le16(bytes + offset); offset += 2;
    line->_startY = (int16_t)read_le16(bytes + offset); offset += 2;
    line->_startZ = (int16_t)read_le16(bytes + offset); offset += 2;
    line->_endX = (int16_t)read_le16(bytes + offset); offset += 2;
    line->_endY = (int16_t)read_le16(bytes + offset); offset += 2;
    line->_endZ = (int16_t)read_le16(bytes + offset); offset += 2;

    return line;
}

/* u32 byte functions */
size_t line3Du32_toBytesLE(const line3Du32_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize NULL pointer");
        return 0;
    }

    size_t offset = 0;
    bytes[offset++] = line->_type;

    write_le32(bytes + offset, line->_startX); offset += 4;
    write_le32(bytes + offset, line->_startY); offset += 4;
    write_le32(bytes + offset, line->_startZ); offset += 4;
    write_le32(bytes + offset, line->_endX); offset += 4;
    write_le32(bytes + offset, line->_endY); offset += 4;
    write_le32(bytes + offset, line->_endZ); offset += 4;

    return offset;
}

line3Du32_t *line3Du32_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Du32_t *line = malloc(sizeof(line3Du32_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    size_t offset = 0;
    line->_type = bytes[offset++];

    line->_startX = read_le32(bytes + offset); offset += 4;
    line->_startY = read_le32(bytes + offset); offset += 4;
    line->_startZ = read_le32(bytes + offset); offset += 4;
    line->_endX = read_le32(bytes + offset); offset += 4;
    line->_endY = read_le32(bytes + offset); offset += 4;
    line->_endZ = read_le32(bytes + offset); offset += 4;

    return line;
}

/* i32 byte functions */
size_t line3Di32_toBytesLE(const line3Di32_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize NULL pointer");
        return 0;
    }

    size_t offset = 0;
    bytes[offset++] = line->_type;

    write_le32(bytes + offset, (uint32_t)line->_startX); offset += 4;
    write_le32(bytes + offset, (uint32_t)line->_startY); offset += 4;
    write_le32(bytes + offset, (uint32_t)line->_startZ); offset += 4;
    write_le32(bytes + offset, (uint32_t)line->_endX); offset += 4;
    write_le32(bytes + offset, (uint32_t)line->_endY); offset += 4;
    write_le32(bytes + offset, (uint32_t)line->_endZ); offset += 4;

    return offset;
}

line3Di32_t *line3Di32_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Di32_t *line = malloc(sizeof(line3Di32_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    size_t offset = 0;
    line->_type = bytes[offset++];

    line->_startX = (int32_t)read_le32(bytes + offset); offset += 4;
    line->_startY = (int32_t)read_le32(bytes + offset); offset += 4;
    line->_startZ = (int32_t)read_le32(bytes + offset); offset += 4;
    line->_endX = (int32_t)read_le32(bytes + offset); offset += 4;
    line->_endY = (int32_t)read_le32(bytes + offset); offset += 4;
    line->_endZ = (int32_t)read_le32(bytes + offset); offset += 4;

    return line;
}

/* u64 byte functions */
size_t line3Du64_toBytesLE(const line3Du64_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize NULL pointer");
        return 0;
    }

    size_t offset = 0;
    bytes[offset++] = line->_type;

    write_le64(bytes + offset, line->_startX); offset += 8;
    write_le64(bytes + offset, line->_startY); offset += 8;
    write_le64(bytes + offset, line->_startZ); offset += 8;
    write_le64(bytes + offset, line->_endX); offset += 8;
    write_le64(bytes + offset, line->_endY); offset += 8;
    write_le64(bytes + offset, line->_endZ); offset += 8;

    return offset;
}

line3Du64_t *line3Du64_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Du64_t *line = malloc(sizeof(line3Du64_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    size_t offset = 0;
    line->_type = bytes[offset++];

    line->_startX = read_le64(bytes + offset); offset += 8;
    line->_startY = read_le64(bytes + offset); offset += 8;
    line->_startZ = read_le64(bytes + offset); offset += 8;
    line->_endX = read_le64(bytes + offset); offset += 8;
    line->_endY = read_le64(bytes + offset); offset += 8;
    line->_endZ = read_le64(bytes + offset); offset += 8;

    return line;
}

/* i64 byte functions */
size_t line3Di64_toBytesLE(const line3Di64_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize NULL pointer");
        return 0;
    }

    size_t offset = 0;
    bytes[offset++] = line->_type;

    write_le64(bytes + offset, (uint64_t)line->_startX); offset += 8;
    write_le64(bytes + offset, (uint64_t)line->_startY); offset += 8;
    write_le64(bytes + offset, (uint64_t)line->_startZ); offset += 8;
    write_le64(bytes + offset, (uint64_t)line->_endX); offset += 8;
    write_le64(bytes + offset, (uint64_t)line->_endY); offset += 8;
    write_le64(bytes + offset, (uint64_t)line->_endZ); offset += 8;

    return offset;
}

line3Di64_t *line3Di64_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Di64_t *line = malloc(sizeof(line3Di64_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    size_t offset = 0;
    line->_type = bytes[offset++];

    line->_startX = (int64_t)read_le64(bytes + offset); offset += 8;
    line->_startY = (int64_t)read_le64(bytes + offset); offset += 8;
    line->_startZ = (int64_t)read_le64(bytes + offset); offset += 8;
    line->_endX = (int64_t)read_le64(bytes + offset); offset += 8;
    line->_endY = (int64_t)read_le64(bytes + offset); offset += 8;
    line->_endZ = (int64_t)read_le64(bytes + offset); offset += 8;

    return line;
}

/* double byte functions */
size_t line3Dd_toBytesLE(const line3Dd_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize NULL pointer");
        return 0;
    }

    size_t offset = 0;
    bytes[offset++] = line->_type;

    write_le64_double(bytes + offset, line->_startX); offset += 8;
    write_le64_double(bytes + offset, line->_startY); offset += 8;
    write_le64_double(bytes + offset, line->_startZ); offset += 8;
    write_le64_double(bytes + offset, line->_endX); offset += 8;
    write_le64_double(bytes + offset, line->_endY); offset += 8;
    write_le64_double(bytes + offset, line->_endZ); offset += 8;

    return offset;
}



/* float byte functions */
size_t line3Df_toBytesLE(const line3Df_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize NULL pointer");
        return 0;
    }

    size_t offset = 0;
    bytes[offset++] = line->_type;

    write_le32_float(bytes + offset, line->_startX); offset += 4;
    write_le32_float(bytes + offset, line->_startY); offset += 4;
    write_le32_float(bytes + offset, line->_startZ); offset += 4;
    write_le32_float(bytes + offset, line->_endX); offset += 4;
    write_le32_float(bytes + offset, line->_endY); offset += 4;
    write_le32_float(bytes + offset, line->_endZ); offset += 4;

    return offset;
}

line3Df_t *line3Df_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Df_t *line = malloc(sizeof(line3Df_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    size_t offset = 0;
    line->_type = bytes[offset++];

    line->_startX = read_le32_float(bytes + offset); offset += 4;
    line->_startY = read_le32_float(bytes + offset); offset += 4;
    line->_startZ = read_le32_float(bytes + offset); offset += 4;
    line->_endX = read_le32_float(bytes + offset); offset += 4;
    line->_endY = read_le32_float(bytes + offset); offset += 4;
    line->_endZ = read_le32_float(bytes + offset); offset += 4;

    return line;
}

line3Dd_t *line3Dd_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Dd_t *line = malloc(sizeof(line3Dd_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    size_t offset = 0;
    line->_type = bytes[offset++];

    line->_startX = read_le64_double(bytes + offset); offset += 8;
    line->_startY = read_le64_double(bytes + offset); offset += 8;
    line->_startZ = read_le64_double(bytes + offset); offset += 8;
    line->_endX = read_le64_double(bytes + offset); offset += 8;
    line->_endY = read_le64_double(bytes + offset); offset += 8;
    line->_endZ = read_le64_double(bytes + offset); offset += 8;

    return line;
}

/* long double byte functions */
size_t line3Dld_toBytesLE(const line3Dld_t *line, uint8_t *bytes) {
    if (!line || !bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot serialize NULL pointer");
        return 0;
    }

    size_t offset = 0;
    bytes[offset++] = line->_type;

    write_le_longdouble(bytes + offset, line->_startX, sizeof(long double)); offset += sizeof(long double);
    write_le_longdouble(bytes + offset, line->_startY, sizeof(long double)); offset += sizeof(long double);
    write_le_longdouble(bytes + offset, line->_startZ, sizeof(long double)); offset += sizeof(long double);
    write_le_longdouble(bytes + offset, line->_endX, sizeof(long double)); offset += sizeof(long double);
    write_le_longdouble(bytes + offset, line->_endY, sizeof(long double)); offset += sizeof(long double);
    write_le_longdouble(bytes + offset, line->_endZ, sizeof(long double)); offset += sizeof(long double);

    return offset;
}

line3Dld_t *line3Dld_fromBytesLE(const uint8_t *bytes) {
    if (!bytes) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, "Cannot deserialize from NULL bytes");
        return NULL;
    }

    line3Dld_t *line = malloc(sizeof(line3Dld_t));
    if (!line) {
        line3_set_error(LINE3_ERROR_MALLOC_FAILED, NULL);
        return NULL;
    }

    size_t offset = 0;
    line->_type = bytes[offset++];

    line->_startX = read_le_longdouble(bytes + offset, sizeof(long double)); offset += sizeof(long double);
    line->_startY = read_le_longdouble(bytes + offset, sizeof(long double)); offset += sizeof(long double);
    line->_startZ = read_le_longdouble(bytes + offset, sizeof(long double)); offset += sizeof(long double);
    line->_endX = read_le_longdouble(bytes + offset, sizeof(long double)); offset += sizeof(long double);
    line->_endY = read_le_longdouble(bytes + offset, sizeof(long double)); offset += sizeof(long double);
    line->_endZ = read_le_longdouble(bytes + offset, sizeof(long double)); offset += sizeof(long double);

    return line;
}


#ifdef VEC3_DEFINED

// For line3Du8_t
vec3uint8_t* line3Du8_getStartPosVec3(line3Du8_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3U8(line->_startX, line->_startY, line->_startZ);
}

vec3uint8_t* line3Du8_getEndPosVec3(line3Du8_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3U8(line->_endX, line->_endY, line->_endZ);
}

void line3Du8_setStartPosVec3(line3Du8_t* line, const vec3uint8_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3u8_X((vec3uint8_t*)vec);
    line->_startY = vec3u8_Y((vec3uint8_t*)vec);
    line->_startZ = vec3u8_Z((vec3uint8_t*)vec);
}

void line3Du8_setEndPosVec3(line3Du8_t* line, const vec3uint8_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3u8_X((vec3uint8_t*)vec);
    line->_endY = vec3u8_Y((vec3uint8_t*)vec);
    line->_endZ = vec3u8_Z((vec3uint8_t*)vec);
}

// For line3Di8_t
vec3int8_t* line3Di8_getStartPosVec3(line3Di8_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3I8(line->_startX, line->_startY, line->_startZ);
}

vec3int8_t* line3Di8_getEndPosVec3(line3Di8_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3I8(line->_endX, line->_endY, line->_endZ);
}

void line3Di8_setStartPosVec3(line3Di8_t* line, const vec3int8_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3i8_X((vec3int8_t*)vec);
    line->_startY = vec3i8_Y((vec3int8_t*)vec);
    line->_startZ = vec3i8_Z((vec3int8_t*)vec);
}

void line3Di8_setEndPosVec3(line3Di8_t* line, const vec3int8_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3i8_X((vec3int8_t*)vec);
    line->_endY = vec3i8_Y((vec3int8_t*)vec);
    line->_endZ = vec3i8_Z((vec3int8_t*)vec);
}

// For line3Du16_t
vec3uint16_t* line3Du16_getStartPosVec3(line3Du16_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3U16(line->_startX, line->_startY, line->_startZ);
}

vec3uint16_t* line3Du16_getEndPosVec3(line3Du16_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3U16(line->_endX, line->_endY, line->_endZ);
}

void line3Du16_setStartPosVec3(line3Du16_t* line, const vec3uint16_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3u16_X((vec3uint16_t*)vec);
    line->_startY = vec3u16_Y((vec3uint16_t*)vec);
    line->_startZ = vec3u16_Z((vec3uint16_t*)vec);
}

void line3Du16_setEndPosVec3(line3Du16_t* line, const vec3uint16_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3u16_X((vec3uint16_t*)vec);
    line->_endY = vec3u16_Y((vec3uint16_t*)vec);
    line->_endZ = vec3u16_Z((vec3uint16_t*)vec);
}

// For line3Di16_t
vec3int16_t* line3Di16_getStartPosVec3(line3Di16_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3I16(line->_startX, line->_startY, line->_startZ);
}

vec3int16_t* line3Di16_getEndPosVec3(line3Di16_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3I16(line->_endX, line->_endY, line->_endZ);
}

void line3Di16_setStartPosVec3(line3Di16_t* line, const vec3int16_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3i16_X((vec3int16_t*)vec);
    line->_startY = vec3i16_Y((vec3int16_t*)vec);
    line->_startZ = vec3i16_Z((vec3int16_t*)vec);
}

void line3Di16_setEndPosVec3(line3Di16_t* line, const vec3int16_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3i16_X((vec3int16_t*)vec);
    line->_endY = vec3i16_Y((vec3int16_t*)vec);
    line->_endZ = vec3i16_Z((vec3int16_t*)vec);
}

// For line3Du32_t
vec3uint32_t* line3Du32_getStartPosVec3(line3Du32_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3U32(line->_startX, line->_startY, line->_startZ);
}

vec3uint32_t* line3Du32_getEndPosVec3(line3Du32_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3U32(line->_endX, line->_endY, line->_endZ);
}

void line3Du32_setStartPosVec3(line3Du32_t* line, const vec3uint32_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3u32_X((vec3uint32_t*)vec);
    line->_startY = vec3u32_Y((vec3uint32_t*)vec);
    line->_startZ = vec3u32_Z((vec3uint32_t*)vec);
}

void line3Du32_setEndPosVec3(line3Du32_t* line, const vec3uint32_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3u32_X((vec3uint32_t*)vec);
    line->_endY = vec3u32_Y((vec3uint32_t*)vec);
    line->_endZ = vec3u32_Z((vec3uint32_t*)vec);
}

// For line3Di32_t
vec3int32_t* line3Di32_getStartPosVec3(line3Di32_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3I32(line->_startX, line->_startY, line->_startZ);
}

vec3int32_t* line3Di32_getEndPosVec3(line3Di32_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3I32(line->_endX, line->_endY, line->_endZ);
}

void line3Di32_setStartPosVec3(line3Di32_t* line, const vec3int32_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3i32_X((vec3int32_t*)vec);
    line->_startY = vec3i32_Y((vec3int32_t*)vec);
    line->_startZ = vec3i32_Z((vec3int32_t*)vec);
}

void line3Di32_setEndPosVec3(line3Di32_t* line, const vec3int32_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3i32_X((vec3int32_t*)vec);
    line->_endY = vec3i32_Y((vec3int32_t*)vec);
    line->_endZ = vec3i32_Z((vec3int32_t*)vec);
}

// For line3Du64_t
vec3uint64_t* line3Du64_getStartPosVec3(line3Du64_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3U64(line->_startX, line->_startY, line->_startZ);
}

vec3uint64_t* line3Du64_getEndPosVec3(line3Du64_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3U64(line->_endX, line->_endY, line->_endZ);
}

void line3Du64_setStartPosVec3(line3Du64_t* line, const vec3uint64_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3u64_X((vec3uint64_t*)vec);
    line->_startY = vec3u64_Y((vec3uint64_t*)vec);
    line->_startZ = vec3u64_Z((vec3uint64_t*)vec);
}

void line3Du64_setEndPosVec3(line3Du64_t* line, const vec3uint64_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3u64_X((vec3uint64_t*)vec);
    line->_endY = vec3u64_Y((vec3uint64_t*)vec);
    line->_endZ = vec3u64_Z((vec3uint64_t*)vec);
}

// For line3Di64_t
vec3int64_t* line3Di64_getStartPosVec3(line3Di64_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3I64(line->_startX, line->_startY, line->_startZ);
}

vec3int64_t* line3Di64_getEndPosVec3(line3Di64_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3I64(line->_endX, line->_endY, line->_endZ);
}

void line3Di64_setStartPosVec3(line3Di64_t* line, const vec3int64_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3i64_X((vec3int64_t*)vec);
    line->_startY = vec3i64_Y((vec3int64_t*)vec);
    line->_startZ = vec3i64_Z((vec3int64_t*)vec);
}

void line3Di64_setEndPosVec3(line3Di64_t* line, const vec3int64_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3i64_X((vec3int64_t*)vec);
    line->_endY = vec3i64_Y((vec3int64_t*)vec);
    line->_endZ = vec3i64_Z((vec3int64_t*)vec);
}

// For line3Df_t (float)
vec3f_t* line3Df_getStartPosVec3(line3Df_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3F(line->_startX, line->_startY, line->_startZ);
}

vec3f_t* line3Df_getEndPosVec3(line3Df_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3F(line->_endX, line->_endY, line->_endZ);
}

void line3Df_setStartPosVec3(line3Df_t* line, const vec3f_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3f_X((vec3f_t*)vec);
    line->_startY = vec3f_Y((vec3f_t*)vec);
    line->_startZ = vec3f_Z((vec3f_t*)vec);
}

void line3Df_setEndPosVec3(line3Df_t* line, const vec3f_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3f_X((vec3f_t*)vec);
    line->_endY = vec3f_Y((vec3f_t*)vec);
    line->_endZ = vec3f_Z((vec3f_t*)vec);
}

// For line3Dd_t (double)
vec3d_t* line3Dd_getStartPosVec3(line3Dd_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3D(line->_startX, line->_startY, line->_startZ);
}

vec3d_t* line3Dd_getEndPosVec3(line3Dd_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3D(line->_endX, line->_endY, line->_endZ);
}

void line3Dd_setStartPosVec3(line3Dd_t* line, const vec3d_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3d_X((vec3d_t*)vec);
    line->_startY = vec3d_Y((vec3d_t*)vec);
    line->_startZ = vec3d_Z((vec3d_t*)vec);
}

void line3Dd_setEndPosVec3(line3Dd_t* line, const vec3d_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3d_X((vec3d_t*)vec);
    line->_endY = vec3d_Y((vec3d_t*)vec);
    line->_endZ = vec3d_Z((vec3d_t*)vec);
}

// For line3Dld_t (long double)
vec3ld_t* line3Dld_getStartPosVec3(line3Dld_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3LD(line->_startX, line->_startY, line->_startZ);
}

vec3ld_t* line3Dld_getEndPosVec3(line3Dld_t* line) {
    if (!line) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return NULL;
    }
    line3_clear_error();
    return allocvec3LD(line->_endX, line->_endY, line->_endZ);
}

void line3Dld_setStartPosVec3(line3Dld_t* line, const vec3ld_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_startX = vec3ld_X((vec3ld_t*)vec);
    line->_startY = vec3ld_Y((vec3ld_t*)vec);
    line->_startZ = vec3ld_Z((vec3ld_t*)vec);
}

void line3Dld_setEndPosVec3(line3Dld_t* line, const vec3ld_t* vec) {
    if (!line || !vec) {
        line3_set_error(LINE3_ERROR_NULL_POINTER, NULL);
        return;
    }
    line3_clear_error();
    line->_endX = vec3ld_X((vec3ld_t*)vec);
    line->_endY = vec3ld_Y((vec3ld_t*)vec);
    line->_endZ = vec3ld_Z((vec3ld_t*)vec);
}

#endif /* VEC3_DEFINED */
