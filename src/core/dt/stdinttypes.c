#include "../../../include/collections/vector.h"
#include "../../../include/core/dt/dt.h"
#include "../../../include/core/datatype.h"
#include <stdlib.h> // For atexit
#include <stdalign.h>
// Function to add a primitive datatype to the vector
void addstdintDatatypeToVector(datatype_t *datatype) {
    vector_t *dataVector = getDatatypeDefinitionsVector();
    if (dataVector == NULL) {
        // Vector not initialized, handle error
        return;
    }
    vector_push(dataVector, datatype);
}


// Function to add stdint datatypes to the vector
void addstdintDatatypes() {
    // Add stdint integer types
    addstdintDatatypeToVector(datatype_malloci("int8_t", sizeof(int8_t), TC_PRIMITIVE, alignof(int8_t), 1, INT8_MIN, INT8_MAX, 0));
    addstdintDatatypeToVector(datatype_mallocu("uint8_t", sizeof(uint8_t), TC_PRIMITIVE, alignof(uint8_t), 0, 0, UINT8_MAX, 0));
    addstdintDatatypeToVector(datatype_malloci("int16_t", sizeof(int16_t), TC_PRIMITIVE, alignof(int16_t), 1, INT16_MIN, INT16_MAX, 0));
    addstdintDatatypeToVector(datatype_mallocu("uint16_t", sizeof(uint16_t), TC_PRIMITIVE, alignof(uint16_t), 0, 0, UINT16_MAX, 0));
    addstdintDatatypeToVector(datatype_malloci("int32_t", sizeof(int32_t), TC_PRIMITIVE, alignof(int32_t), 1, INT32_MIN, INT32_MAX, 0));
    addstdintDatatypeToVector(datatype_mallocu("uint32_t", sizeof(uint32_t), TC_PRIMITIVE, alignof(uint32_t), 0, 0, UINT32_MAX, 0));
    addstdintDatatypeToVector(datatype_malloci("int64_t", sizeof(int64_t), TC_PRIMITIVE, alignof(int64_t), 1, INT64_MIN, INT64_MAX, 0));
    addstdintDatatypeToVector(datatype_mallocu("uint64_t", sizeof(uint64_t), TC_PRIMITIVE, alignof(uint64_t), 0, 0, UINT64_MAX, 0));
}


void initstdintDataVector() {
    vector_t *dataVector = getDatatypeDefinitionsVector();
    if (dataVector == NULL) {
        initDataDefinitions();
    }
    addstdintDatatypes();
}
