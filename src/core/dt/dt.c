#include "../../../include/core/dt/dt.h"
#include "../../../include/collections/vector.h"
#include "../../../include/core/datatype.h"
#include <stdlib.h> // For atexit
#include <stdbool.h>
#include <string.h>

bool _datatypeDefInit = false;

#define INITIAL_CAPACITY 64

vector_t * datatypeDefinitions;


void initDataDefinitions(){
  if(datatypeDefinitions == NULL || !_datatypeDefInit){
    datatypeDefinitions = vector_malloc(datatype_static_structSize(), INITIAL_CAPACITY);
    _datatypeDefInit = true;
  }
}


// Function to retrieve a datatype definition by its name
datatype_t *getDatatypeDefinition(const char *name) {
    if (datatypeDefinitions == NULL) {
        // Vector not initialized
        return NULL;
    }

    // Iterate through the vector to find the datatype with the specified name
    for (size_t i = 0; i < vector_getCount(datatypeDefinitions); i++) {
        datatype_t *datatype = vector_getElementAt(datatypeDefinitions, i);
        if (strcmp(datatype_getName(datatype), name) == 0) {
            // Found the datatype, return its definition
            return datatype;
        }
    }

    // Datatype not found
    return NULL;
}
