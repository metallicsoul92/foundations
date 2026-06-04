#include "../../../include/core/dt/dt.h"
#include "../../../include/core/datatype.h"
#include "../../../include/collections/vector.h"
#include <stddef.h> // Include stddef.h for standard type definitions like size_t
#include <stdlib.h> // For atexit
#include <stdalign.h>
// Function to add a stddef datatype to the vector
void addstddefDatatypeToVector(datatype_t *datatype) {
    vector_t *dataVector = getDatatypeDefinitionsVector();
    if (dataVector == NULL) {
        // Vector not initialized, handle error
        return;
    }
    vector_push(dataVector, datatype);
}

// Function to add stddef datatypes to the vector
void addstddefDatatypes() {
    // Add stddef types
    addstddefDatatypeToVector(datatype_mallocu("size_t", sizeof(size_t), TC_PRIMITIVE, alignof(size_t), 0, 0, SIZE_MAX, 0));
    addstddefDatatypeToVector(datatype_mallocu("ptrdiff_t", sizeof(ptrdiff_t), TC_PRIMITIVE, alignof(ptrdiff_t), 1, PTRDIFF_MIN, PTRDIFF_MAX, 0));
    addstddefDatatypeToVector(datatype_malloci("wchar_t", sizeof(wchar_t), TC_PRIMITIVE, alignof(wchar_t), 0, WCHAR_MIN, WCHAR_MAX, 0));
    addstddefDatatypeToVector(datatype_malloci("max_align_t", sizeof(max_align_t), TC_PRIMITIVE, alignof(max_align_t), 0, 0, 0, 0));
    // You can add more stddef types as needed
}

void initstddefDataVector() {
    vector_t *dataVector = getDatatypeDefinitionsVector();
    if (dataVector == NULL) {
        initDataDefinitions();
    }
    addstddefDatatypes();
}
