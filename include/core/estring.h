#ifndef FOUNDATIONS_CORE_ESTRING_H_
#define FOUNDATIONS_CORE_ESTRING_H_

//forward declare the fixed data types
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif
//forward declare booleans
#ifndef STDBOOL_DEFINED
#include <stdbool.h>
#define STDBOOL_DEFINED 1
#endif



typedef struct estring estring_t;

//construction/destruction
estring_t * malloc_estring(const char * data);
estring_t * copy_estring(const estring_t * data);
estring_t * move_estring(estring_t * data);
void free_estring(estring_t * self);
//getters
uint32_t estring_length(estring_t *self);
char * estring_str(estring_t*self);
char estring_getAt(estring_t *self, uint32_t index);
bool estring_isEqual(estring_t * a, estring_t * b);

//setters
void estring_append(estring_t * self, const char * extra);
void estring_setAt(estring_t * self, const char letter, uint32_t index);

estring_t * estring_substr(estring_t * str, uint32_t start, uint32_t end);

#endif
