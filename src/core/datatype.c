#include "../../include/core/datatype.h"

struct datatype{
  char *_name;
  size_t _size;
  etypeCategory _category;
  size_t _alignment;
  int _is_signed;
  long long _min_value;
  long long _max_value;
  int _precision;
};


// Allocate memory for a new datatype_t structure and initialize its attributes
// Parameters:
// - name: Name of the datatype
// - size: Size of the datatype in bytes
// - category: Category of the datatype (primitive, composite, or derived)
// - alignment: Alignment requirements of the datatype
// - is_signed: Indicates whether the datatype is signed (1 for signed, 0 for unsigned)
// - min_value: Minimum value of the datatype (applicable for primitive types)
// - max_value: Maximum value of the datatype (applicable for primitive types)
// - precision: Precision of the datatype (applicable for floating-point types)
// Returns:
// - A pointer to the newly allocated datatype_t structure
datatype_t *datatype_malloc(const char *name, size_t size, etypeCategory category,
                            size_t alignment, int is_signed, long long min_value,
                            long long max_value, int precision) {
    // Allocate memory for the datatype_t structure
    datatype_t *out = malloc(sizeof(datatype_t));
    if (out == NULL) {
        // Optionally handle error: Memory allocation failed
        return NULL;
    }

    // Allocate memory for the name attribute and copy the provided name
    out->_name = strdup(name);
    if (out->_name == NULL) {
        // Optionally handle error: Memory allocation failed
        free(out); // Free previously allocated memory
        return NULL;
    }

    // Initialize other attributes of the datatype_t structure
    out->_size = size;
    out->_category = category;
    out->_alignment = alignment;
    out->_is_signed = is_signed;
    out->_min_value = min_value;
    out->_max_value = max_value;
    out->_precision = precision;

    return out; // Return the pointer to the newly allocated datatype_t structure
}


// Free memory allocated for a datatype_t structure and associated resources
// Parameters:
// - datatype: Pointer to the datatype_t structure to be freed
// Returns:
// - None
void datatype_free(datatype_t *datatype) {
    // Free memory allocated for the name attribute
    free(datatype->_name);
    // Free memory allocated for the datatype_t structure itself
    free(datatype);
}


// Initialize a new datatype_t structure with the provided attributes
// Parameters:
// - name: Name of the datatype
// - size: Size of the datatype in bytes
// - category: Category of the datatype (primitive, composite, or derived)
// - alignment: Alignment requirements of the datatype
// - is_signed: Indicates whether the datatype is signed (1 for signed, 0 for unsigned)
// - min_value: Minimum value of the datatype (applicable for primitive types)
// - max_value: Maximum value of the datatype (applicable for primitive types)
// - precision: Precision of the datatype (applicable for floating-point types)
// Returns:
// - An initialized datatype_t structure
datatype_t datatype_init(const char *name, size_t size, etypeCategory category,
                         size_t alignment, int is_signed, long long min_value,
                         long long max_value, int precision) {
    // Create a new datatype_t structure
    datatype_t out;

    // Allocate memory for the name attribute and copy the provided name
    out._name = strdup(name);
    if (out._name == NULL) {
        // Optionally handle error: Memory allocation failed
        // You might want to return an error code or handle the error according to your application's requirements
    }

    // Initialize other attributes of the datatype_t structure
    out._size = size;
    out._category = category;
    out._alignment = alignment;
    out._is_signed = is_signed;
    out._min_value = min_value;
    out._max_value = max_value;
    out._precision = precision;

    return out; // Return the initialized datatype_t structure
}



// Deallocate resources associated with a datatype_t structure
void datatype_uninit(datatype_t *datatype) {
  if (datatype == NULL) {
  // Optionally handle error: Invalid input parameter
    return;
  }
  free(datatype->_name);
  // Optionally free any other dynamically allocated resources
}


// Get the name of the datatype
const char *datatype_getName(datatype_t *dt) {
    return dt->_name;
}

// Get the name of the datatype (const version, doesn't allow modification of the structure)
const char *datatype_Name(const datatype_t *dt) {
    return dt->_name;
}

// Get the size of the datatype in bytes
size_t datatype_getSize(datatype_t *dt) {
    return dt->_size;
}

// Get the size of the datatype in bytes (const version)
size_t datatype_Size(const datatype_t *dt) {
    return dt->_size;
}

// Get the category of the datatype (primitive, composite, or derived)
etypeCategory datatype_getCategory(datatype_t *dt) {
    return dt->_category;
}

// Get the category of the datatype (const version)
etypeCategory datatype_Category(const datatype_t *dt) {
    return dt->_category;
}

// Get the alignment requirements of the datatype
size_t datatype_getAlignment(datatype_t *dt) {
    return dt->_alignment;
}

// Get the alignment requirements of the datatype (const version)
size_t datatype_Alignment(const datatype_t *dt) {
    return dt->_alignment;
}

// Check if the datatype is signed (returns 1 if signed, 0 otherwise)
int datatype_is_getSigned(datatype_t *dt) {
    return dt->_is_signed;
}

// Check if the datatype is signed (const version)
int datatype_is_Signed(const datatype_t *dt) {
    return dt->_is_signed;
}

// Get the minimum value of the datatype
long long datatype_getMinValue(datatype_t *dt) {
    return dt->_min_value;
}

// Get the minimum value of the datatype (const version)
long long datatype_MinValue(const datatype_t *dt) {
    return dt->_min_value;
}

// Get the maximum value of the datatype
long long datatype_getMaxValue(datatype_t *dt) {
    return dt->_max_value;
}

// Get the maximum value of the datatype (const version)
long long datatype_MaxValue(const datatype_t *dt) {
    return dt->_max_value;
}

// Get the precision of the datatype (applicable for floating-point types)
int datatype_getPrecision(datatype_t *dt) {
    return dt->_precision;
}

// Get the precision of the datatype (const version)
int datatype_Precision(const datatype_t *dt) {
    return dt->_precision;
}
