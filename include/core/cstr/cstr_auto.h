// cstr_auto.h
#ifndef FOUNDATIONS_CORE_CSTR_CSTR_AUTO_H
#define FOUNDATIONS_CORE_CSTR_CSTR_AUTO_H

#include "cstr.h"

typedef struct {
    cstr_t *str;
} cstr_auto_t;

static inline void cstr_auto_cleanup(cstr_auto_t *auto_str) {
    if (auto_str && auto_str->str) {
        cstr_free(auto_str->str);
        auto_str->str = NULL;
    }
}

// Macro to declare an auto-managed cstr_auto_t variable
#ifdef __GNUC__
    #define CSTR_AUTO(var_name) \
        __attribute__((cleanup(cstr_auto_cleanup))) cstr_auto_t var_name
#else
    // Fallback for compilers without cleanup attribute
    #define CSTR_AUTO(var_name) cstr_auto_t var_name
    // User must manually call cstr_auto_cleanup(&var_name)
#endif

#endif // CSTR_AUTO_H
