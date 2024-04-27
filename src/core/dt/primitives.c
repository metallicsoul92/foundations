#include "../../../include/core/dt/dt.h"
#include "../../../include/core/datatype.h"
#include "../../../include/collections/vector.h"
#include <stdlib.h> // For atexit
#include <stdbool.h>
#include <float.h>
#include <limits.h>
#include <stdalign.h>
// Function to add a primitive datatype to the vector
void addPrimitiveDatatypeToVector(datatype_t *datatype) {
    vector_t *dataVector = getDatatypeDefinitionsVector();
    if (dataVector == NULL) {
        // Vector not initialized, handle error
        return;
    }
    vector_push(dataVector, datatype);
}

void addPrimitiveDatatypes() {
    // Add integer types
    addPrimitiveDatatypeToVector(datatype_malloci("char", sizeof(char), TC_PRIMITIVE, alignof(char), 0, CHAR_MIN, CHAR_MAX, 0));
    addPrimitiveDatatypeToVector(datatype_malloci("signed char", sizeof(signed char), TC_PRIMITIVE, alignof(signed char), 1, SCHAR_MIN, SCHAR_MAX, 0));
    addPrimitiveDatatypeToVector(datatype_mallocu("unsigned char", sizeof(unsigned char), TC_PRIMITIVE, alignof(unsigned char), 0, 0, UCHAR_MAX, 0));
    addPrimitiveDatatypeToVector(datatype_malloci("short", sizeof(short), TC_PRIMITIVE, alignof(short), 1, SHRT_MIN, SHRT_MAX, 0));
    addPrimitiveDatatypeToVector(datatype_mallocu("unsigned short", sizeof(unsigned short), TC_PRIMITIVE, alignof(unsigned short), 0, 0, USHRT_MAX, 0));
    addPrimitiveDatatypeToVector(datatype_malloci("int", sizeof(int), TC_PRIMITIVE, alignof(int), 1, INT_MIN, INT_MAX, 0));
    addPrimitiveDatatypeToVector(datatype_mallocu("unsigned int", sizeof(unsigned int), TC_PRIMITIVE, alignof(unsigned int), 0, 0, UINT_MAX, 0));
    addPrimitiveDatatypeToVector(datatype_malloci("long", sizeof(long), TC_PRIMITIVE, alignof(long), 1, LONG_MIN, LONG_MAX, 0));
    addPrimitiveDatatypeToVector(datatype_mallocu("unsigned long", sizeof(unsigned long), TC_PRIMITIVE, alignof(unsigned long), 0, 0, ULONG_MAX, 0));
    addPrimitiveDatatypeToVector(datatype_malloci("long long", sizeof(long long), TC_PRIMITIVE, alignof(long long), 1, LLONG_MIN, LLONG_MAX, 0));
    addPrimitiveDatatypeToVector(datatype_mallocu("unsigned long long", sizeof(unsigned long long), TC_PRIMITIVE, alignof(unsigned long long), 0, 0, ULLONG_MAX, 0));

    // Add floating-point types
    addPrimitiveDatatypeToVector(datatype_mallocf("float", sizeof(float), TC_PRIMITIVE, alignof(float), 1, -FLT_MAX, FLT_MAX, FLT_DECIMAL_DIG));
    addPrimitiveDatatypeToVector(datatype_mallocd("double", sizeof(double), TC_PRIMITIVE, alignof(double), 1, -DBL_MAX, DBL_MAX, DBL_DECIMAL_DIG));
    addPrimitiveDatatypeToVector(datatype_mallocld("long double", sizeof(long double), TC_PRIMITIVE, alignof(long double), 1, -LDBL_MAX, LDBL_MAX, LDBL_DECIMAL_DIG));

    // Add boolean type
    addPrimitiveDatatypeToVector(datatype_malloci("_Bool", sizeof(_Bool), TC_PRIMITIVE, alignof(_Bool), 0, 0, 1, 0));
}

void initPrimitiveDataVector() {
    vector_t *dataVector = getDatatypeDefinitionsVector();
    if (dataVector == NULL) {
        initDataDefinitions();
    }
    addPrimitiveDatatypes();
}
