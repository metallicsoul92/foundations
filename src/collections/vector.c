#include "../../include/collections/vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char * NULL_VECTOR_BLOCK;
void * VECNULL = &NULL_VECTOR_BLOCK;

struct vector {
    size_t _elementSize;
    size_t _capacity;
    size_t _count;
    uint8_t _eflag;
    void * _data;
};

size_t vector_getSize(vector_t * out) {
    return out->_elementSize;
}

size_t vector_getCapacity(vector_t * out) {
    return out->_capacity;
}

size_t vector_getCount(vector_t * out) {
    return out->_count;
}

uint8_t vector_eFlag(vector_t * out) {
    return out->_eflag;
}

void * vector_getElementAt(vector_t * out, size_t index) {
    if (index >= out->_count) {
        return VECNULL;
    }
    uintptr_t offset = (uintptr_t)out->_data + (out->_elementSize * index);
    return (void *)offset;
}

void * vector_getRawData(vector_t * out) {
    return out->_data;
}

vector_t * vector_malloc(size_t size, size_t capacity) {
    vector_t * out = malloc(sizeof(vector_t));
    if (!out) return NULL;
    out->_elementSize = size;
    out->_capacity = capacity;
    out->_count = 0;
    out->_eflag = VEC_FLAG_EMPTY;
    out->_data = malloc(size * capacity);
    if (!out->_data) {
        free(out);
        return NULL;
    }
    return out;
}

vector_t * vector_init(vector_t * out, size_t size, size_t capacity) {
    if (!out) return NULL;
    out->_elementSize = size;
    out->_capacity = capacity;
    out->_count = 0;
    out->_eflag = VEC_FLAG_EMPTY;
    out->_data = malloc(size * capacity);
    if (!out->_data) {
        return NULL;
    }
    return out;
}

vector_t * vector_copy(const vector_t * copy) {
    vector_t * out = vector_malloc(copy->_elementSize, copy->_capacity);
    if (!out) return NULL;
    out->_count = copy->_count;
    out->_eflag = copy->_eflag;
    memcpy(out->_data, copy->_data, out->_elementSize * out->_capacity);
    return out;
}

vector_t * vector_move(vector_t * move) {
    vector_t * out = vector_malloc(move->_elementSize, move->_capacity);
    if (!out) return NULL;
    out->_count = move->_count;
    out->_eflag = move->_eflag;
    memmove(out->_data, move->_data, move->_elementSize * move->_capacity);
    free_vector(move);
    return out;
}

void free_vector(vector_t * out) {
    if (!out) return;
    free(out->_data);
    free(out);
}

void vector_empty(vector_t * out) {
    if (!out) return;
    memset(out->_data, 0, out->_elementSize * out->_count);
    out->_count = 0;
}

void vector_push(vector_t * out, void * element) {
    if (!out || !element) return;
    if (out->_count == out->_capacity) {
        vector_resize(out);
    }
    uintptr_t offset = (uintptr_t)out->_data + (out->_elementSize * out->_count);
    memcpy((void *)offset, element, out->_elementSize);
    out->_count++;
    if (out->_count == out->_capacity) {
        out->_eflag = VEC_FLAG_FULL;
    } else {
        out->_eflag = VEC_FLAG_NONE;
    }
}

void * vector_pop(vector_t * out) {
    if (!out || out->_count == 0) {
        out->_eflag = VEC_FLAG_EMPTY;
        return VECNULL;
    }
    uintptr_t offset = (uintptr_t)out->_data + (out->_elementSize * (out->_count - 1));
    void * ret = (void *)offset;
    out->_count--;
    if (out->_eflag == VEC_FLAG_FULL) {
        out->_eflag = VEC_FLAG_NONE;
    }
    return ret;
}

void vector_resize(vector_t * out) {
    size_t newCap = out->_capacity * 2;
    void * newData = realloc(out->_data, newCap * out->_elementSize);
    if (!newData) {
        out->_eflag = VEC_FLAG_INVALID_RESIZE;
        return;
    }
    out->_data = newData;
    out->_capacity = newCap;
}

void vector_exactResize(vector_t * out, size_t newCap) {
    if (out->_capacity >= newCap) {
        out->_eflag = VEC_FLAG_INVALID_RESIZE;
        return;
    }
    void * newData = realloc(out->_data, newCap * out->_elementSize);
    if (!newData) {
        out->_eflag = VEC_FLAG_INVALID_RESIZE;
        return;
    }
    out->_data = newData;
    out->_capacity = newCap;
}
