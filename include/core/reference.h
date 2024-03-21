#ifndef FOUNDATIONS_CORE_REFERENCE_H_
#define FOUNDATIONS_CORE_REFERENCE_H_

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#define REF_NO_ERR 0
#define REF_ERR_INVDMEM 1  //Invalid Memory
#define REF_ERR_SIZE 2     //Incorrect Size
#define REF_ERR_NOEMPTY 4  //Reference is still being used.

typedef struct reference ref_t;

//Memory Allocating
ref_t * ref_malloc(size_t size, void * data);
uint8_t ref_free(ref_t * out);


//Getter Functions
size_t ref_getDataSize(ref_t * out);
size_t ref_getReferenceCount(ref_t * out);




//Globals
uint8_t g_ref_setDataFromRef(ref_t * ref, void  * outData);
uint8_t g_ref_removeDataToRef(void * data, ref_t * ref);

#endif
