#include "../../include/core/reference.h"
#include <string.h>
#include <stdlib.h>

struct reference {
    size_t _sizeOfData;
    size_t _referenceCount;
    void *_data;
};

// Thread-safe increment/decrement (GCC/Clang)
uint8_t int_increment_ref(ref_t *ref) {
    if (!ref) return REF_ERR_INVDMEM;
    __atomic_fetch_add(&ref->_referenceCount, 1, __ATOMIC_RELAXED);
    return REF_NO_ERR;
}

uint8_t int_decrement_ref(ref_t *ref) {
    if (!ref) return REF_ERR_INVDMEM;
    __atomic_fetch_sub(&ref->_referenceCount, 1, __ATOMIC_RELAXED);
    return REF_NO_ERR;
}

ref_t *ref_malloc(size_t size, void *data) {
    ref_t *out = malloc(sizeof(ref_t) + size);
    if (!out) return NULL;

    out->_sizeOfData = size;
    out->_referenceCount = 1; // Creator holds the first reference
    out->_data = (char *)out + sizeof(ref_t);

    if (data) memcpy(out->_data, data, size);
    return out;
}

uint8_t ref_free(ref_t *out) {
    if (!out) return REF_ERR_INVDMEM;
    if (out->_referenceCount > 0) return REF_ERR_NOEMPTY;

    free(out); // Frees ref_t and _data in one operation
    return REF_NO_ERR;
}

// Getters
size_t ref_getDataSize(ref_t *out) { return out ? out->_sizeOfData : 0; }
size_t ref_getReferenceCount(ref_t *out) { return out ? out->_referenceCount : 0; }

// Data handling (assumes outData is pre-allocated)
uint8_t g_ref_setDataFromRef(ref_t *ref, void *outData) {
    if (!ref || !outData) return REF_ERR_INVDMEM;
    memcpy(outData, ref->_data, ref->_sizeOfData);
    return REF_NO_ERR;
}

uint8_t g_ref_removeDataToRef(void *data, ref_t *ref) {
    if (!data || !ref) return REF_ERR_INVDMEM;
    int_decrement_ref(ref);
    return REF_NO_ERR;
}
