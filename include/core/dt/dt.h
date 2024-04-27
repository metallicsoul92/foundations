#ifndef FOUNDATIONS_CORE_DT_DT_H_
#define FOUNDATIONS_CORE_DT_DT_H_

#ifndef DATATYPE_DEF
typedef struct datatype datatype_t;
#define DATATYPE_DEF
#endif

#ifndef VECTOR_DEF
typedef struct vector vector_t;
#define VECTOR_DEF
#endif

// Function declarations for initializing data vectors
void initDataDefinitions();
void initPrimitiveDataVector();
void initstddefDataVector();
void initstdintDataVector();

// Function declaration for accessing and modifying the global variable
vector_t *getDatatypeDefinitionsVector();


// Function declaration for getting datatype definition by name
datatype_t * getDatatypeDefinition(const char * name);

#endif
