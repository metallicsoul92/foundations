#include "../../include/core/datatype.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

typedef union _value{
  int64_t _i64;
  uint64_t _u64;
  float _float;
  double _double;
  long double _ldouble;
} value_t;

// Structure to represent a datatype
struct datatype {
    char *_name;            // Name of the datatype
    size_t _size;           // Size of the datatype in bytes
    etypeCategory _category;   // Category of the datatype (primitive, composite, derived)
    size_t _alignment;      // Alignment requirement of the datatype
    int _is_signed;         // Indicates if the datatype is signed (1 for true, 0 for false)
    value_t _min_value;   // Minimum value of the datatype
    value_t _max_value;   // Maximum value of the datatype
    int _precision;         // Precision of the datatype (e.g., number of decimal digits for floating-point types)
};

size_t datatype_static_structSize(){
  return sizeof(datatype_t);
}


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
datatype_t *datatype_malloci(const char *name, size_t size, etypeCategory category,
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
    out->_min_value._i64 = min_value;
    out->_max_value._i64 = max_value;
    out->_precision = precision;

    return out; // Return the pointer to the newly allocated datatype_t structure
}

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
datatype_t *datatype_mallocu(const char *name, size_t size, etypeCategory category,
                            size_t alignment, int is_signed, unsigned long long min_value,
                            unsigned long long max_value, int precision) {
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
    out->_min_value._u64 = min_value;
    out->_max_value._u64 = max_value;
    out->_precision = precision;

    return out; // Return the pointer to the newly allocated datatype_t structure
}


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
datatype_t *datatype_mallocf(const char *name, size_t size, etypeCategory category,
                            size_t alignment, int is_signed, float min_value,
                            float max_value, int precision) {
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
    out->_min_value._float = min_value;
    out->_max_value._float = max_value;
    out->_precision = precision;

    return out; // Return the pointer to the newly allocated datatype_t structure
}

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
datatype_t *datatype_mallocd(const char *name, size_t size, etypeCategory category,
                            size_t alignment, int is_signed, double min_value,
                            double max_value, int precision) {
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
    out->_min_value._double = min_value;
    out->_max_value._double = max_value;
    out->_precision = precision;

    return out; // Return the pointer to the newly allocated datatype_t structure
}

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
datatype_t *datatype_mallocld(const char *name, size_t size, etypeCategory category,
                            size_t alignment, int is_signed, long double min_value,
                            long double max_value, int precision) {
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
    out->_min_value._ldouble = min_value;
    out->_max_value._ldouble = max_value;
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
datatype_t datatype_initi(const char *name, size_t size, etypeCategory category,
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
    out._min_value._i64 = min_value;
    out._max_value._i64 = max_value;
    out._precision = precision;

    return out; // Return the initialized datatype_t structure
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
datatype_t datatype_initu(const char *name, size_t size, etypeCategory category,
                         size_t alignment, int is_signed, unsigned long long min_value,
                         unsigned long long max_value, int precision) {
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
    out._min_value._u64 = min_value;
    out._max_value._u64 = max_value;
    out._precision = precision;

    return out; // Return the initialized datatype_t structure
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
datatype_t datatype_initf(const char *name, size_t size, etypeCategory category,
                         size_t alignment, int is_signed, float min_value,
                         float max_value, int precision) {
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
    out._min_value._float = min_value;
    out._max_value._float = max_value;
    out._precision = precision;

    return out; // Return the initialized datatype_t structure
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
datatype_t datatype_initd(const char *name, size_t size, etypeCategory category,
                         size_t alignment, int is_signed, double min_value,
                         double max_value, int precision) {
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
    out._min_value._double = min_value;
    out._max_value._double = max_value;
    out._precision = precision;

    return out; // Return the initialized datatype_t structure
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
datatype_t datatype_initld(const char *name, size_t size, etypeCategory category,
                         size_t alignment, int is_signed, long double min_value,
                         long double max_value, int precision) {
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
    out._min_value._ldouble = min_value;
    out._max_value._ldouble = max_value;
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
int64_t datatype_getMinValue_asi64(datatype_t *dt) {
    if (dt->_is_signed) {
        return dt->_min_value._i64;
    } else {
        return 0;
    }
}

uint64_t datatype_getMinValue_asu64(datatype_t *dt) {
    if (dt->_is_signed) {
        return 0;
    } else {
        return dt->_min_value._u64;
    }
}

float datatype_getMinValue_asfloat(datatype_t *dt) {
    return dt->_min_value._float;
}

double datatype_getMinValue_asdouble(datatype_t *dt) {
    return dt->_min_value._double;
}

long double datatype_getMinValue_aslongdouble(datatype_t *dt) {
    return dt->_min_value._ldouble;
}

// Get the minimum value of the datatype (const version)
int64_t datatype_MinValue_asi64(const datatype_t *dt) {
    if (dt->_is_signed) {
        return dt->_min_value._i64;
    } else {
        return 0;
    }
}

uint64_t datatype_MinValue_asu64(const datatype_t *dt) {
    if (dt->_is_signed) {
        return 0;
    } else {
        return dt->_min_value._u64;
    }
}

float datatype_MinValue_asfloat(const datatype_t *dt) {
    return dt->_min_value._float;
}

double datatype_MinValue_asdouble(const datatype_t *dt) {
    return dt->_min_value._double;
}

long double datatype_MinValue_aslongdouble(const datatype_t *dt) {
    return dt->_min_value._ldouble;
}

// Get the maximum value of the datatype
int64_t datatype_getMaxValue_asi64(datatype_t *dt) {
    return dt->_max_value._i64;
}

uint64_t datatype_getMaxValue_asu64(datatype_t *dt) {
    return dt->_max_value._u64;
}

float datatype_getMaxValue_asfloat(datatype_t *dt) {
    return dt->_max_value._float;
}

double datatype_getMaxValue_asdouble(datatype_t *dt) {
    return dt->_max_value._double;
}

long double datatype_getMaxValue_aslongdouble(datatype_t *dt) {
    return dt->_max_value._ldouble;
}

// Get the maximum value of the datatype (const version)
int64_t datatype_MaxValue_asi64(const datatype_t *dt) {
    return dt->_max_value._i64;
}

uint64_t datatype_MaxValue_asu64(const datatype_t *dt) {
    return dt->_max_value._u64;
}

float datatype_MaxValue_asfloat(const datatype_t *dt) {
    return dt->_max_value._float;
}

double datatype_MaxValue_asdouble(const datatype_t *dt) {
    return dt->_max_value._double;
}

long double datatype_MaxValue_aslongdouble(const datatype_t *dt) {
    return dt->_max_value._ldouble;
}


// Get the precision of the datatype (applicable for floating-point types)
int datatype_getPrecision(datatype_t *dt) {
    return dt->_precision;
}

// Get the precision of the datatype (const version)
int datatype_Precision(const datatype_t *dt) {
    return dt->_precision;
}
