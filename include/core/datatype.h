#ifndef FOUNDATIONS_CORE_DATATYPE_H_
#define FOUNDATIONS_CORE_DATATYPE_H_

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif


typedef enum {
  TC_PRIMITIVE,
  TC_COMPOSITE,
  TC_DERIVED
} etypeCategory;


#ifndef DATATYPE_DEF
typedef struct datatype datatype_t;
#define DATATYPE_DEF
#endif

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
                            long long max_value, int precision);

//
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
                            unsigned long long max_value, int precision);


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
                            float max_value, int precision);



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
                            double max_value, int precision);

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
                            long double max_value, int precision);


// Free memory allocated for a datatype_t structure
// Parameters:
// - datatype: Pointer to the datatype_t structure to be freed
void datatype_free(datatype_t *datatype);

// Initialize a datatype_t structure with the provided attributes
// Note: This function doesn't allocate memory for the datatype_t structure itself.
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
                         long long max_value, int precision);

//
// Initialize a datatype_t structure with the provided attributes
// Note: This function doesn't allocate memory for the datatype_t structure itself.
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
                         unsigned long long max_value, int precision);

//
// Initialize a datatype_t structure with the provided attributes
// Note: This function doesn't allocate memory for the datatype_t structure itself.
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
                         float max_value, int precision);

//
// Initialize a datatype_t structure with the provided attributes
// Note: This function doesn't allocate memory for the datatype_t structure itself.
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
                         double max_value, int precision);


//
// Initialize a datatype_t structure with the provided attributes
// Note: This function doesn't allocate memory for the datatype_t structure itself.
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
                         long double max_value, int precision);



// Deallocate resources associated with a datatype_t structure
 // This function is used to free resources allocated by functions like datatype_init
// Parameters:
// - datatype: Pointer to the datatype_t structure to be uninitialized
// Returns:
// - None
void datatype_uninit(datatype_t * datatype);

// Getter functions for accessing attributes of the datatype_t structure

// Get the name of the datatype
const char *datatype_getName(datatype_t *dt);

// Get the name of the datatype (const version, doesn't allow modification of the structure)
const char *datatype_Name(const datatype_t *dt);

// Get the size of the datatype in bytes
size_t datatype_getSize(datatype_t *dt);

// Get the size of the datatype in bytes (const version)
size_t datatype_Size(const datatype_t *dt);

// Get the category of the datatype (primitive, composite, or derived)
etypeCategory datatype_getCategory(datatype_t *dt);

// Get the category of the datatype (const version)
etypeCategory datatype_Category(const datatype_t *dt);

// Get the alignment requirements of the datatype
size_t datatype_getAlignment(datatype_t *dt);

// Get the alignment requirements of the datatype (const version)
size_t datatype_Alignment(const datatype_t *dt);

// Check if the datatype is signed (returns 1 if signed, 0 otherwise)
int datatype_is_getSigned(datatype_t *dt);

// Check if the datatype is signed (const version)
int datatype_is_Signed(const datatype_t *dt);

// Get the minimum value of the datatype
int64_t datatype_getMinValue_asi64(datatype_t *dt);
uint64_t datatype_getMinValue_asu64(datatype_t *dt);
float datatype_getMinValue_asfloat(datatype_t *dt);
double datatype_getMinValue_asdouble(datatype_t *dt);
long double datatype_getMinValue_aslongdouble(datatype_t *dt);



// Get the minimum value of the datatype (const version)
int64_t datatype_MinValue_asi64(const datatype_t *dt);
uint64_t datatype_MinValue_asu64(const datatype_t *dt);
float datatype_MinValue_asfloat(const datatype_t *dt);
double datatype_MinValue_asdouble(const datatype_t *dt);
long double datatype_MinValue_aslongdouble(const datatype_t *dt);


// Get the maximum value of the datatype
int64_t datatype_getMaxValue_asi64(datatype_t *dt);
uint64_t datatype_getMaxValue_asu64(datatype_t *dt);
float datatype_getMaxValue_asfloat(datatype_t *dt);
double datatype_getMaxValue_asdouble(datatype_t *dt);
long double datatype_getMaxValue_aslongdouble(datatype_t *dt);



// Get the minimum value of the datatype (const version)
int64_t datatype_MaxValue_asi64(const datatype_t *dt);
uint64_t datatype_MaxValue_asu64(const datatype_t *dt);
float datatype_MaxValue_asfloat(const datatype_t *dt);
double datatype_MaxValue_asdouble(const datatype_t *dt);
long double datatype_MaxValue_aslongdouble(const datatype_t *dt);

// Get the precision of the datatype (applicable for floating-point types)
int datatype_getPrecision(datatype_t *dt);

// Get the precision of the datatype (const version)
int datatype_Precision(const datatype_t *dt);


size_t datatype_static_structSize();

#endif
