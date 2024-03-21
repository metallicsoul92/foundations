#include "../../include/core/reference.h"
#include <string.h>

struct reference{
  size_t _sizeOfData;
  size_t _referenceCount;
  void * _data;
};

//helper functions
uint8_t int_increment_ref(ref_t * ref){
  if(!ref || !ref->_data)
    return REF_ERR_INVDMEM;

  ref->_referenceCount++;
  return REF_NO_ERR;
}

uint8_t int_decrement_ref(ref_t * ref){
  if(!ref || !ref->_data)
    return REF_ERR_INVDMEM;

  ref->_referenceCount--;
  return REF_NO_ERR;
}

ref_t *ref_malloc(size_t size, void *data) {
    size_t memsize = sizeof(ref_t) + size; // Calculate total size required
    ref_t *out = malloc(memsize);
    if (!out)
        return NULL;

    out->_sizeOfData = size;
    out->_referenceCount = 0;
    out->_data = (char *)out + sizeof(ref_t); // Point to the location after ref_t

    memcpy(out->_data, data, size); // Copy the data

    return out;
}

uint8_t ref_free(ref_t *out) {
    if (!out)
        return REF_ERR_INVDMEM; // Return error if 'out' is NULL

    if (out->_referenceCount > 0)
        return REF_ERR_NOEMPTY; // Return error if there are remaining references

    free(out->_data); // Free the data
    free(out); // Free the reference structure

    return REF_NO_ERR; // Return success
}




//This will assume outData is the correct size.
uint8_t g_ref_setDataFromRef(ref_t *ref, void *outData) {
    if (!ref || !outData)
        return REF_ERR_INVDMEM;

    // Move data to outData
    memcpy(ref->_data, outData, ref->_sizeOfData);


    // Increment reference count
    int_increment_ref(ref);

    return REF_NO_ERR;
}

uint8_t g_ref_removeDataToRef(void * data, ref_t * ref){
    if(!ref || !data)
      return REF_ERR_INVDMEM;

    //free the data that was being referenced
    free(data);
    //decrement the reference
    int_decrement_ref(ref);

    return REF_NO_ERR;
}
