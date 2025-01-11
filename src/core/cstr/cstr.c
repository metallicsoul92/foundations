#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <uchar.h>
#include "../../include/cstr/cchartraits.h" // Include the header file for char_traits_t
#include "../../include/cstr/cstr.h"


// Define the cstr_t structure
typedef struct cstr {
    const char_traits_t * _charTraits; // Pointer to the appropriate char_traits_t
    size_t _size;                      // Current number of characters in buffer
    size_t _capacity;                  // Current capacity of the buffer
    void * _data;                      // Data buffer (flexible size based on charTraits)
} cstr_t;

/*
Goal:
  cstr_t *regularString = cstr_malloc_empty(&char_char_traits);    // Regular string
  cstr_t *wideString = cstr_malloc_empty(&wchar_t_char_traits);    // Wide string
  cstr_t *u16String = cstr_malloc_empty(&char16_t_char_traits);    // Unicode string (16-bit)
  cstr_t *u32String = cstr_malloc_empty(&char32_t_char_traits);    // Unicode string (32-bit)
*/

cstr_t * cstr_malloc_empty(const char_traits_t *charTraits) {
    if (!charTraits) return NULL; // Ensure charTraits is valid

    // Determine the size of each character type using the charTraits' copy function
    size_t dSize;
    if (charTraits == &char_char_traits) {
        dSize = 1;
    } else if (charTraits == &wchar_t_char_traits) {
        dSize = sizeof(wchar_t);
    } else if (charTraits == &char16_t_char_traits) {
        dSize = sizeof(char16_t);
    } else if (charTraits == &char32_t_char_traits) {
        dSize = sizeof(char32_t);
    } else {
        // Unsupported character trait
        return NULL;
    }

    // Allocate memory for the cstr_t object
    cstr_t *out = malloc(sizeof(cstr_t));
    if (!out) return NULL;

    out->_size = 0;
    out->_capacity = 8; // Initial capacity
    out->_data = calloc(out->_capacity, dSize); // Allocate and zero-initialize the data buffer
    if (!out->_data) {
        free(out);
        return NULL;
    }

    // Set the appropriate charTraits
    out->_charTraits = charTraits;

    return out;
}

cstr_t * cstr_malloc_ccp(const void *string, const char_traits_t *charTraits) {
    if (!string || !charTraits) return NULL;

    size_t len = charTraits->length(string);
    size_t dSize = len * (charTraits == &char_char_traits ? 1 :
                          charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                          charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                          sizeof(char32_t));

    cstr_t *out = malloc(sizeof(cstr_t));
    if (!out) return NULL;

    out->_size = len;
    out->_capacity = len + 1;
    out->_data = malloc(out->_capacity * dSize);
    if (!out->_data) {
        free(out);
        return NULL;
    }

    out->_charTraits = charTraits;
    charTraits->copy(out->_data, string, len);
    return out;
}

cstr_t * cstr_malloc_copy(const cstr_t *str) {
    if (!str || !str->_charTraits) return NULL;

    cstr_t *copy = malloc(sizeof(cstr_t));
    if (!copy) return NULL;

    copy->_size = str->_size;
    copy->_capacity = str->_capacity;
    copy->_charTraits = str->_charTraits;

    size_t dSize = copy->_size * (str->_charTraits == &char_char_traits ? 1 :
                                  str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                                  str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                                  sizeof(char32_t));

    copy->_data = malloc(copy->_capacity * dSize);
    if (!copy->_data) {
        free(copy);
        return NULL;
    }

    str->_charTraits->copy(copy->_data, str->_data, copy->_size);
    return copy;
}

cstr_t * cstr_malloc_ccp_n(const void *string, size_t n, const char_traits_t *charTraits) {
    if (!string || !charTraits) return NULL;

    size_t dSize = (charTraits == &char_char_traits ? 1 :
                    charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    cstr_t *out = malloc(sizeof(cstr_t));
    if (!out) return NULL;

    out->_size = n;
    out->_capacity = n + 1;
    out->_data = malloc(out->_capacity * dSize);
    if (!out->_data) {
        free(out);
        return NULL;
    }

    out->_charTraits = charTraits;
    charTraits->copy(out->_data, string, n);
    return out;
}

cstr_t * cstr_malloc_fill(size_t n, const void *c, const char_traits_t *charTraits) {
    if (!c || !charTraits) return NULL;

    size_t dSize = (charTraits == &char_char_traits ? 1 :
                    charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    cstr_t *out = malloc(sizeof(cstr_t));
    if (!out) return NULL;

    out->_size = n;
    out->_capacity = n + 1;
    out->_data = malloc(out->_capacity * dSize);
    if (!out->_data) {
        free(out);
        return NULL;
    }

    out->_charTraits = charTraits;
    for (size_t i = 0; i < n; i++) {
        charTraits->assign((char *)out->_data + i * dSize, c);
    }

    return out;
}

cstr_t * cstr_malloc_move(cstr_t *mov) {
    if (!mov) return NULL;

    cstr_t *out = malloc(sizeof(cstr_t));
    if (!out) return NULL;

    // Transfer ownership of the data
    *out = *mov;
    mov->_data = NULL; // Clear the original to prevent double free
    mov->_size = 0;
    mov->_capacity = 0;

    return out;
}

void cstr_free(cstr_t *ret) {
    if (!ret) {
        return; // Nothing to free if ret is NULL
    }

    // Free the data buffer if it exists
    if (ret->_data) {
        free(ret->_data);
        ret->_data = NULL; // Avoid dangling pointer
    }

    // Free the cstr_t object itself
    free(ret);
}

cstr_t * cstr_assign_copy(cstr_t * out, const cstr_t * str) {
    if (!out || !str || !str->_charTraits) return NULL;

    // Resize if necessary
    if (out->_capacity < str->_size) {
        void *new_data = realloc(out->_data, str->_size * sizeof(str->_charTraits));
        if (!new_data) return NULL;
        out->_data = new_data;
        out->_capacity = str->_size;
    }

    // Copy the data
    str->_charTraits->copy(out->_data, str->_data, str->_size);
    out->_size = str->_size;

    return out;
}

cstr_t * cstr_assign_ccp(cstr_t * out, const void * str, const char_traits_t * charTraits) {
    if (!out || !str || !charTraits) return NULL;

    size_t len = charTraits->length(str);

    // Resize if necessary
    size_t dSize = len * (charTraits == &char_char_traits ? 1 :
                          charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                          charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                          sizeof(char32_t));
    if (out->_capacity < len) {
        void *new_data = realloc(out->_data, len * dSize);
        if (!new_data) return NULL;
        out->_data = new_data;
        out->_capacity = len;
    }

    // Copy the data
    charTraits->copy(out->_data, str, len);
    out->_size = len;
    out->_charTraits = charTraits;

    return out;
}

cstr_t * cstr_assign_c(cstr_t * out, const void * c, const char_traits_t * charTraits) {
    if (!out || !c || !charTraits) return NULL;

    // Resize if necessary
    size_t dSize = (charTraits == &char_char_traits ? 1 :
                    charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));
    if (out->_capacity < 1) {
        void *new_data = realloc(out->_data, dSize);
        if (!new_data) return NULL;
        out->_data = new_data;
        out->_capacity = 1;
    }

    // Assign the character
    charTraits->assign(out->_data, c);
    out->_size = 1;
    out->_charTraits = charTraits;

    return out;
}

cstr_t * cstr_assign_move(cstr_t * out, cstr_t * mov) {
    if (!out || !mov) return NULL;

    // Free the current data in out
    if (out->_data) {
        free(out->_data);
    }

    // Move data from mov to out
    *out = *mov;

    // Invalidate mov
    mov->_data = NULL;
    mov->_size = 0;
    mov->_capacity = 0;

    return out;
}

cstr_t * cstr_assign_substr(cstr_t * out, const cstr_t * str, size_t subpos, size_t sublen) {
    if (!out || !str || !str->_charTraits || subpos >= str->_size) return NULL;

    if (subpos + sublen > str->_size) {
        sublen = str->_size - subpos;
    }

    size_t dSize = sublen * (str->_charTraits == &char_char_traits ? 1 :
                             str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                             str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                             sizeof(char32_t));

    // Resize if necessary
    if (out->_capacity < sublen) {
        void *new_data = realloc(out->_data, sublen * dSize);
        if (!new_data) return NULL;
        out->_data = new_data;
        out->_capacity = sublen;
    }

    // Copy the substring
    str->_charTraits->copy(out->_data, (char *)str->_data + subpos * dSize, sublen);
    out->_size = sublen;
    out->_charTraits = str->_charTraits;

    return out;
}

// Returns the size of the string (number of characters, excluding null terminator)
const size_t cstr_size(const cstr_t *str) {
    return str ? str->_size : 0;
}

// Returns the length of the string (alias for cstr_size)
const size_t cstr_length(const cstr_t *str) {
    return cstr_size(str);
}

// Returns the maximum size the string can hold (implementation-defined)
const size_t cstr_maxSize(const cstr_t *str) {
    return (size_t)-1 / (str && str->_charTraits == &char_char_traits ? 1 :
                         str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                         str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                         sizeof(char32_t));
}

// Returns the currently allocated capacity of the string
const size_t cstr_capacity(const cstr_t *str) {
    return str ? str->_capacity : 0;
}

// Resizes the string to hold n characters, filling new characters with default values
void cstr_resize(cstr_t *str, size_t n) {
    if (!str || !str->_charTraits) return;

    size_t dSize = (str->_charTraits == &char_char_traits ? 1 :
                    str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    if (n > str->_capacity) {
        void *new_data = realloc(str->_data, n * dSize);
        if (!new_data) return;
        str->_data = new_data;
        str->_capacity = n;
    }

    if (n > str->_size) {
        // Fill new space with default values
        memset((char *)str->_data + str->_size * dSize, 0, (n - str->_size) * dSize);
    }

    str->_size = n;
}

// Resizes the string to hold n characters, filling new characters with c
void cstr_resize_c(cstr_t *str, size_t n, const void *c) {
    if (!str || !str->_charTraits || !c) return;

    size_t dSize = (str->_charTraits == &char_char_traits ? 1 :
                    str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    if (n > str->_capacity) {
        void *new_data = realloc(str->_data, n * dSize);
        if (!new_data) return;
        str->_data = new_data;
        str->_capacity = n;
    }

    if (n > str->_size) {
        // Fill new space with the provided character
        for (size_t i = str->_size; i < n; i++) {
            str->_charTraits->assign((char *)str->_data + i * dSize, c);
        }
    }

    str->_size = n;
}

// Ensures the string has at least n capacity
void cstr_reserve(cstr_t *str, size_t n) {
    if (!str || str->_capacity >= n) return;

    size_t dSize = (str->_charTraits == &char_char_traits ? 1 :
                    str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    void *new_data = realloc(str->_data, n * dSize);
    if (!new_data) return;
    str->_data = new_data;
    str->_capacity = n;
}

// Clears the contents of the string, retaining its capacity
void cstr_clear(cstr_t *str) {
    if (!str) return;
    str->_size = 0;
}

// Checks if the string is empty (returns 1 if true, 0 otherwise)
int cstr_isEmpty(const cstr_t *str) {
    return str && str->_size == 0;
}

// Reduces the capacity of the string to match its size
void cstr_shrinkToFit(cstr_t *str) {
    if (!str || str->_capacity == str->_size) return;

    size_t dSize = (str->_charTraits == &char_char_traits ? 1 :
                    str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    void *new_data = realloc(str->_data, str->_size * dSize);
    if (!new_data) return;
    str->_data = new_data;
    str->_capacity = str->_size;
}


// Returns the character at position pos in the string.
// Returns '\0' (or equivalent for the char type) if pos is out of bounds.
const void * cstr_at(const cstr_t *str, size_t pos) {
    if (!str || pos >= str->_size) {
        static char null_char = '\0';
        return &null_char; // Return a null equivalent
    }

    size_t dSize = (str->_charTraits == &char_char_traits ? 1 :
                    str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    return (const void *)((char *)str->_data + pos * dSize);
}

// Returns the first character of the string.
// Returns '\0' (or equivalent) if the string is empty.
const void * cstr_front(const cstr_t *str) {
    return cstr_at(str, 0);
}

// Returns the last character of the string.
// Returns '\0' (or equivalent) if the string is empty.
const void * cstr_back(const cstr_t *str) {
    if (!str || str->_size == 0) {
        static char null_char = '\0';
        return &null_char;
    }
    return cstr_at(str, str->_size - 1);
}

// Appends the contents of other to ret. Returns ret on success, NULL on failure.
cstr_t * cstr_append_cstr(cstr_t *ret, const cstr_t *other) {
    if (!ret || !other || ret->_charTraits != other->_charTraits) return NULL;

    size_t dSize = (ret->_charTraits == &char_char_traits ? 1 :
                    ret->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    ret->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    size_t new_size = ret->_size + other->_size;
    if (new_size > ret->_capacity) {
        void *new_data = realloc(ret->_data, new_size * dSize);
        if (!new_data) return NULL;
        ret->_data = new_data;
        ret->_capacity = new_size;
    }

    ret->_charTraits->copy((char *)ret->_data + ret->_size * dSize, other->_data, other->_size);
    ret->_size = new_size;

    return ret;
}

// Appends a substring of other to ret. Returns ret on success, NULL on failure.
cstr_t * cstr_append_csubstr(cstr_t *ret, const cstr_t *other, size_t subpos, size_t sublen) {
    if (!ret || !other || subpos >= other->_size || ret->_charTraits != other->_charTraits) return NULL;

    if (subpos + sublen > other->_size) {
        sublen = other->_size - subpos;
    }

    size_t dSize = (ret->_charTraits == &char_char_traits ? 1 :
                    ret->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    ret->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    size_t new_size = ret->_size + sublen;
    if (new_size > ret->_capacity) {
        void *new_data = realloc(ret->_data, new_size * dSize);
        if (!new_data) return NULL;
        ret->_data = new_data;
        ret->_capacity = new_size;
    }

    ret->_charTraits->copy((char *)ret->_data + ret->_size * dSize,
                           (char *)other->_data + subpos * dSize,
                           sublen);
    ret->_size = new_size;

    return ret;
}

// Appends a null-terminated C-string to ret. Returns ret on success, NULL on failure.
cstr_t * cstr_append_ccp(cstr_t *ret, const void *other) {
    if (!ret || !other) return NULL;

    size_t len = ret->_charTraits->length(other);
    return cstr_append_csubstr(ret, (const cstr_t *)&other, 0, len);
}

// Appends the first n characters of other to ret. Returns ret on success, NULL on failure.
cstr_t * cstr_append_cstr_buffer(cstr_t *ret, const cstr_t *other, size_t n) {
    if (!ret || !other || ret->_charTraits != other->_charTraits) return NULL;

    if (n > other->_size) {
        n = other->_size;
    }

    return cstr_append_csubstr(ret, other, 0, n);
}

// Appends n repetitions of character c to ret. Returns ret on success, NULL on failure.
cstr_t * cstr_append_fill(cstr_t *ret, size_t n, const void *c) {
    if (!ret || !c) return NULL;

    size_t dSize = (ret->_charTraits == &char_char_traits ? 1 :
                    ret->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    ret->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    size_t new_size = ret->_size + n;
    if (new_size > ret->_capacity) {
        void *new_data = realloc(ret->_data, new_size * dSize);
        if (!new_data) return NULL;
        ret->_data = new_data;
        ret->_capacity = new_size;
    }

    for (size_t i = 0; i < n; i++) {
        ret->_charTraits->assign((char *)ret->_data + (ret->_size + i) * dSize, c);
    }

    ret->_size = new_size;

    return ret;
}

// Pushes a single character to the back of the string.
void cstr_pushBack(cstr_t *ret, const void *c) {
    if (!ret || !c) return;

    cstr_append_fill(ret, 1, c);
}

// Inserts other at position pos in out. Returns out on success, NULL on failure.
cstr_t * cstr_insert_cstr(cstr_t *out, size_t pos, const cstr_t *other) {
    if (!out || !other || pos > out->_size || out->_charTraits != other->_charTraits) return NULL;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    size_t new_size = out->_size + other->_size;
    if (new_size > out->_capacity) {
        void *new_data = realloc(out->_data, new_size * dSize);
        if (!new_data) return NULL;
        out->_data = new_data;
        out->_capacity = new_size;
    }

    // Shift data after pos to the right
    memmove((char *)out->_data + (pos + other->_size) * dSize,
            (char *)out->_data + pos * dSize,
            (out->_size - pos) * dSize);

    // Insert the new data
    out->_charTraits->copy((char *)out->_data + pos * dSize, other->_data, other->_size);
    out->_size = new_size;

    return out;
}

// Inserts a substring of other at position pos in out. Returns out on success, NULL on failure.
cstr_t * cstr_insert_substr(cstr_t *out, size_t pos, const cstr_t *other, size_t subpos, size_t sublen) {
    if (!out || !other || pos > out->_size || subpos >= other->_size || out->_charTraits != other->_charTraits) return NULL;

    if (subpos + sublen > other->_size) {
        sublen = other->_size - subpos;
    }

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    size_t new_size = out->_size + sublen;
    if (new_size > out->_capacity) {
        void *new_data = realloc(out->_data, new_size * dSize);
        if (!new_data) return NULL;
        out->_data = new_data;
        out->_capacity = new_size;
    }

    // Shift data after pos to the right
    memmove((char *)out->_data + (pos + sublen) * dSize,
            (char *)out->_data + pos * dSize,
            (out->_size - pos) * dSize);

    // Insert the substring
    out->_charTraits->copy((char *)out->_data + pos * dSize,
                           (char *)other->_data + subpos * dSize,
                           sublen);
    out->_size = new_size;

    return out;
}

// Inserts a null-terminated C-string at position pos in out. Returns out on success, NULL on failure.
cstr_t * cstr_insert_ccp(cstr_t *out, size_t pos, const void *other) {
    if (!out || !other) return NULL;

    size_t len = out->_charTraits->length(other);
    return cstr_insert_substr(out, pos, (const cstr_t *)&other, 0, len);
}

// Inserts the first n characters of other at position pos in out. Returns out on success, NULL on failure.
cstr_t * cstr_insert_buffer(cstr_t *out, size_t pos, const void *other, size_t n) {
    if (!out || !other || pos > out->_size) return NULL;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    size_t new_size = out->_size + n;
    if (new_size > out->_capacity) {
        void *new_data = realloc(out->_data, new_size * dSize);
        if (!new_data) return NULL;
        out->_data = new_data;
        out->_capacity = new_size;
    }

    // Shift data after pos to the right
    memmove((char *)out->_data + (pos + n) * dSize,
            (char *)out->_data + pos * dSize,
            (out->_size - pos) * dSize);

    // Insert the buffer
    out->_charTraits->copy((char *)out->_data + pos * dSize, other, n);
    out->_size = new_size;

    return out;
}

// Inserts n repetitions of character c at position pos in out. Returns out on success, NULL on failure.
cstr_t * cstr_insert_fill(cstr_t *out, size_t pos, size_t n, const void *c) {
    if (!out || !c || pos > out->_size) return NULL;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    size_t new_size = out->_size + n;
    if (new_size > out->_capacity) {
        void *new_data = realloc(out->_data, new_size * dSize);
        if (!new_data) return NULL;
        out->_data = new_data;
        out->_capacity = new_size;
    }

    // Shift data after pos to the right
    memmove((char *)out->_data + (pos + n) * dSize,
            (char *)out->_data + pos * dSize,
            (out->_size - pos) * dSize);

    // Insert the repeated character
    for (size_t i = 0; i < n; i++) {
        out->_charTraits->assign((char *)out->_data + (pos + i) * dSize, c);
    }
    out->_size = new_size;

    return out;
}

// Erases len characters starting from position pos in the string.
// Returns the modified string on success, NULL on failure.
cstr_t * cstr_erase(cstr_t *out, size_t pos, size_t len) {
    if (!out || pos >= out->_size) return NULL;

    if (pos + len > out->_size) {
        len = out->_size - pos;
    }

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    // Shift data after the erased section to the left
    memmove((char *)out->_data + pos * dSize,
            (char *)out->_data + (pos + len) * dSize,
            (out->_size - (pos + len)) * dSize);

    out->_size -= len;

    return out;
}

// Replaces characters starting at pos in out with the contents of other.
// Returns out on success, NULL on failure.
cstr_t * cstr_replace_cstr(cstr_t *out, size_t pos, const cstr_t *other) {
    if (!out || !other || pos > out->_size || out->_charTraits != other->_charTraits) return NULL;

    cstr_erase(out, pos, other->_size);
    return cstr_insert_cstr(out, pos, other);
}

// Replaces characters starting at pos in out with a substring of other.
// Returns out on success, NULL on failure.
cstr_t * cstr_replace_substr(cstr_t *out, size_t pos, const cstr_t *other, size_t subpos, size_t sublen) {
    if (!out || !other || pos > out->_size || out->_charTraits != other->_charTraits) return NULL;

    cstr_erase(out, pos, sublen);
    return cstr_insert_substr(out, pos, other, subpos, sublen);
}

// Replaces characters starting at pos in out with a C-string other.
// Returns out on success, NULL on failure.
cstr_t * cstr_replace_ccp(cstr_t *out, size_t pos, const void *other) {
    if (!out || !other || pos > out->_size) return NULL;

    size_t len = out->_charTraits->length(other);

    cstr_erase(out, pos, len);
    return cstr_insert_buffer(out, pos, other, len);
}

// Replaces characters starting at pos in out with the first n characters of other.
// Returns out on success, NULL on failure.
cstr_t * cstr_replace_buffer(cstr_t *out, size_t pos, const void *other, size_t n) {
    if (!out || !other || pos > out->_size) return NULL;

    cstr_erase(out, pos, n);
    return cstr_insert_buffer(out, pos, other, n);
}

// Replaces n characters starting at pos in out with n repetitions of character c.
// Returns out on success, NULL on failure.
cstr_t * cstr_replace_fill(cstr_t *out, size_t pos, size_t n, const void *c) {
    if (!out || !c || pos > out->_size) return NULL;

    cstr_erase(out, pos, n);
    return cstr_insert_fill(out, pos, n, c);
}

// Swaps the contents of out and other.
void cstr_swap(cstr_t *out, cstr_t *other) {
    if (!out || !other) return;

    cstr_t temp = *out;
    *out = *other;
    *other = temp;
}

// Removes the last character from out.
void cstr_popBack(cstr_t *out) {
    if (!out || out->_size == 0) return;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    // Reduce the size by one character
    out->_size--;

    // Optional: Zero out the last character for safety
    memset((char *)out->_data + out->_size * dSize, 0, dSize);
}

// Returns a null-terminated C-string representation of out.
const void * cstr_c_str(cstr_t *out) {
    if (!out || !out->_data) return NULL;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    // Ensure there's enough space for a null terminator
    if (out->_capacity <= out->_size) {
        void *new_data = realloc(out->_data, (out->_size + 1) * dSize);
        if (!new_data) return NULL;
        out->_data = new_data;
        out->_capacity = out->_size + 1;
    }

    // Null-terminate the string
    memset((char *)out->_data + out->_size * dSize, 0, dSize);

    return out->_data;
}

// Returns a pointer to the internal data buffer of out (not null-terminated).
const void * cstr_data(cstr_t *out) {
    return (out && out->_data) ? out->_data : NULL;
}
// Copies up to len characters from out starting at position pos into s.
// Returns the number of characters copied.
size_t cstr_copy(cstr_t *out, void *s, size_t len, size_t pos) {
    if (!out || !s || pos >= out->_size) return 0;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    size_t copy_len = (pos + len > out->_size) ? out->_size - pos : len;
    out->_charTraits->copy(s, (char *)out->_data + pos * dSize, copy_len);

    return copy_len;
}

// Finds the first occurrence of str in out starting from pos.
// Returns the position of the first match, or SIZE_MAX if not found.
size_t cstr_find_cstr(cstr_t *out, const cstr_t *str, size_t pos) {
    if (!out || !str || pos >= out->_size || out->_charTraits != str->_charTraits) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = pos; i <= out->_size - str->_size; i++) {
        if (out->_charTraits->compare((char *)out->_data + i * dSize, str->_data, str->_size) == 0) {
            return i;
        }
    }

    return SIZE_MAX;
}

// Finds the first occurrence of a C-string s in out starting from pos.
// Returns the position of the first match, or SIZE_MAX if not found.
size_t cstr_find_ccp(cstr_t *out, const void *s, size_t pos) {
    if (!out || !s || pos >= out->_size) return SIZE_MAX;

    size_t len = out->_charTraits->length(s);
    return cstr_find_buffer(out, s, pos, len);
}

// Finds the first occurrence of a buffer s of length n in out starting from pos.
// Returns the position of the first match, or SIZE_MAX if not found.
size_t cstr_find_buffer(cstr_t *out, const void *s, size_t pos, size_t n) {
    if (!out || !s || pos >= out->_size || n == 0) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = pos; i <= out->_size - n; i++) {
        if (out->_charTraits->compare((char *)out->_data + i * dSize, s, n) == 0) {
            return i;
        }
    }

    return SIZE_MAX;
}

// Finds the first occurrence of character c in out starting from pos.
// Returns the position of the first match, or SIZE_MAX if not found.
size_t cstr_find_char(cstr_t *out, const void *c, size_t pos) {
    if (!out || !c || pos >= out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = pos; i < out->_size; i++) {
        if (out->_charTraits->eq((char *)out->_data + i * dSize, c)) {
            return i;
        }
    }

    return SIZE_MAX;
}

// Finds the last occurrence of str in out up to pos.
// Returns the position of the last match, or SIZE_MAX if not found.
size_t cstr_rfind_cstr(cstr_t *out, const cstr_t *str, size_t pos) {
    if (!out || !str || out->_charTraits != str->_charTraits || str->_size > out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    if (pos > out->_size - str->_size) pos = out->_size - str->_size;

    for (size_t i = pos + 1; i-- > 0;) {
        if (out->_charTraits->compare((char *)out->_data + i * dSize, str->_data, str->_size) == 0) {
            return i;
        }
    }

    return SIZE_MAX;
}

// Finds the last occurrence of a C-string s in out up to pos.
// Returns the position of the last match, or SIZE_MAX if not found.
size_t cstr_rfind_ccp(cstr_t *out, const void *s, size_t pos) {
    if (!out || !s) return SIZE_MAX;

    size_t len = out->_charTraits->length(s);
    return cstr_rfind_buffer(out, s, pos, len);
}

// Finds the last occurrence of a buffer s of length n in out up to pos.
// Returns the position of the last match, or SIZE_MAX if not found.
size_t cstr_rfind_buffer(cstr_t *out, const void *s, size_t pos, size_t n) {
    if (!out || !s || n > out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    if (pos > out->_size - n) pos = out->_size - n;

    for (size_t i = pos + 1; i-- > 0;) {
        if (out->_charTraits->compare((char *)out->_data + i * dSize, s, n) == 0) {
            return i;
        }
    }

    return SIZE_MAX;
}

// Finds the last occurrence of character c in out up to pos.
// Returns the position of the last match, or SIZE_MAX if not found.
size_t cstr_rfind_char(cstr_t *out, const void *c, size_t pos) {
    if (!out || !c) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    if (pos >= out->_size) pos = out->_size - 1;

    for (size_t i = pos + 1; i-- > 0;) {
        if (out->_charTraits->eq((char *)out->_data + i * dSize, c)) {
            return i;
        }
    }

    return SIZE_MAX;
}

// Finds the first occurrence in out (starting at pos) of any character present in str.
// Returns the position of the first match, or SIZE_MAX if no match is found.
size_t cstr_find_first_of_cstr(cstr_t *out, const cstr_t *str, size_t pos) {
    if (!out || !str || out->_charTraits != str->_charTraits || pos >= out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = pos; i < out->_size; i++) {
        for (size_t j = 0; j < str->_size; j++) {
            if (out->_charTraits->eq((char *)out->_data + i * dSize,
                                     (char *)str->_data + j * dSize)) {
                return i;
            }
        }
    }

    return SIZE_MAX;
}

// Finds the first occurrence in out (starting at pos) of any character present in the C-string s.
// Returns the position of the first match, or SIZE_MAX if no match is found.
size_t cstr_find_first_of_ccp(cstr_t *out, const void *s, size_t pos) {
    if (!out || !s || pos >= out->_size) return SIZE_MAX;

    cstr_t temp = { ._data = (void *)s, ._size = out->_charTraits->length(s), ._charTraits = out->_charTraits };
    return cstr_find_first_of_cstr(out, &temp, pos);
}

// Finds the first occurrence in out (starting at pos) of any character present in the first n bytes of s.
// Returns the position of the first match, or SIZE_MAX if no match is found.
size_t cstr_find_first_of_buffer(cstr_t *out, const void *s, size_t pos, size_t n) {
    if (!out || !s || pos >= out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = pos; i < out->_size; i++) {
        for (size_t j = 0; j < n; j++) {
            if (out->_charTraits->eq((char *)out->_data + i * dSize, (char *)s + j * dSize)) {
                return i;
            }
        }
    }

    return SIZE_MAX;
}

// Finds the first occurrence in out (starting at pos) of the character c.
// Returns the position of the first match, or SIZE_MAX if no match is found.
size_t cstr_find_first_of_char(cstr_t *out, const void *c, size_t pos) {
    if (!out || !c || pos >= out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = pos; i < out->_size; i++) {
        if (out->_charTraits->eq((char *)out->_data + i * dSize, c)) {
            return i;
        }
    }

    return SIZE_MAX;
}

// Finds the last occurrence in out (up to pos) of any character present in str.
// Returns the position of the last match, or SIZE_MAX if no match is found.
size_t cstr_find_last_of_cstr(cstr_t *out, const cstr_t *str, size_t pos) {
    if (!out || !str || pos >= out->_size || out->_charTraits != str->_charTraits) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = (pos + 1); i-- > 0;) {
        for (size_t j = 0; j < str->_size; j++) {
            if (out->_charTraits->eq((char *)out->_data + i * dSize,
                                     (char *)str->_data + j * dSize)) {
                return i;
            }
        }
    }

    return SIZE_MAX;
}

// Finds the last occurrence in out (up to pos) of any character present in the C-string s.
// Returns the position of the last match, or SIZE_MAX if no match is found.
size_t cstr_find_last_of_ccp(cstr_t *out, const void *s, size_t pos) {
    if (!out || !s || pos >= out->_size) return SIZE_MAX;

    cstr_t temp = { ._data = (void *)s, ._size = out->_charTraits->length(s), ._charTraits = out->_charTraits };
    return cstr_find_last_of_cstr(out, &temp, pos);
}

// Finds the last occurrence in out (up to pos) of any character present in the first n bytes of s.
// Returns the position of the last match, or SIZE_MAX if no match is found.
size_t cstr_find_last_of_buffer(cstr_t *out, const void *s, size_t pos, size_t n) {
    if (!out || !s || pos >= out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = (pos + 1); i-- > 0;) {
        for (size_t j = 0; j < n; j++) {
            if (out->_charTraits->eq((char *)out->_data + i * dSize, (char *)s + j * dSize)) {
                return i;
            }
        }
    }

    return SIZE_MAX;
}

// Finds the last occurrence in out (up to pos) of the character c.
// Returns the position of the last match, or SIZE_MAX if no match is found.
size_t cstr_find_last_of_char(cstr_t *out, const void *c, size_t pos) {
    if (!out || !c || pos >= out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = (pos + 1); i-- > 0;) {
        if (out->_charTraits->eq((char *)out->_data + i * dSize, c)) {
            return i;
        }
    }

    return SIZE_MAX;
}

// Finds the first position in out (starting from pos) where the character is not in str.
// Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_first_not_of_cstr(cstr_t *out, const cstr_t *str, size_t pos) {
    if (!out || !str || pos >= out->_size || out->_charTraits != str->_charTraits) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = pos; i < out->_size; i++) {
        int found = 0;
        for (size_t j = 0; j < str->_size; j++) {
            if (out->_charTraits->eq((char *)out->_data + i * dSize,
                                     (char *)str->_data + j * dSize)) {
                found = 1;
                break;
            }
        }
        if (!found) return i;
    }

    return SIZE_MAX;
}

// Finds the first position in out (starting from pos) where the character is not in the C-string s.
// Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_first_not_of_ccp(cstr_t *out, const void *s, size_t pos) {
    if (!out || !s || pos >= out->_size) return SIZE_MAX;

    cstr_t temp = { ._data = (void *)s, ._size = out->_charTraits->length(s), ._charTraits = out->_charTraits };
    return cstr_find_first_not_of_cstr(out, &temp, pos);
}

// Finds the first position in out (starting from pos) where the character is not in the first n bytes of s.
// Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_first_not_of_buffer(cstr_t *out, const void *s, size_t pos, size_t n) {
    if (!out || !s || pos >= out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = pos; i < out->_size; i++) {
        int found = 0;
        for (size_t j = 0; j < n; j++) {
            if (out->_charTraits->eq((char *)out->_data + i * dSize, (char *)s + j * dSize)) {
                found = 1;
                break;
            }
        }
        if (!found) return i;
    }

    return SIZE_MAX;
}

// Finds the first position in out (starting from pos) where the character is not c.
// Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_first_not_of_char(cstr_t *out, const void *c, size_t pos) {
    if (!out || !c || pos >= out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = pos; i < out->_size; i++) {
        if (!out->_charTraits->eq((char *)out->_data + i * dSize, c)) {
            return i;
        }
    }

    return SIZE_MAX;
}

// Finds the last position in out (up to pos) where the character is not in str.
// Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_last_not_of_cstr(cstr_t *out, const cstr_t *str, size_t pos) {
    if (!out || !str || pos >= out->_size || out->_charTraits != str->_charTraits) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = (pos + 1); i-- > 0;) {
        int found = 0;
        for (size_t j = 0; j < str->_size; j++) {
            if (out->_charTraits->eq((char *)out->_data + i * dSize,
                                     (char *)str->_data + j * dSize)) {
                found = 1;
                break;
            }
        }
        if (!found) return i;
    }

    return SIZE_MAX;
}

// Finds the last position in out (up to pos) where the character is not in the C-string s.
// Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_last_not_of_ccp(cstr_t *out, const void *s, size_t pos) {
    if (!out || !s || pos >= out->_size) return SIZE_MAX;

    cstr_t temp = { ._data = (void *)s, ._size = out->_charTraits->length(s), ._charTraits = out->_charTraits };
    return cstr_find_last_not_of_cstr(out, &temp, pos);
}

// Finds the last position in out (up to pos) where the character is not in the first n bytes of s.
// Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_last_not_of_buffer(cstr_t *out, const void *s, size_t pos, size_t n) {
    if (!out || !s || pos >= out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = (pos + 1); i-- > 0;) {
        int found = 0;
        for (size_t j = 0; j < n; j++) {
            if (out->_charTraits->eq((char *)out->_data + i * dSize, (char *)s + j * dSize)) {
                found = 1;
                break;
            }
        }
        if (!found) return i;
    }

    return SIZE_MAX;
}

// Finds the last position in out (up to pos) where the character is not c.
// Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_last_not_of_char(cstr_t *out, const void *c, size_t pos) {
    if (!out || !c || pos >= out->_size) return SIZE_MAX;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    for (size_t i = (pos + 1); i-- > 0;) {
        if (!out->_charTraits->eq((char *)out->_data + i * dSize, c)) {
            return i;
        }
    }

    return SIZE_MAX;
}

// Creates a substring of length len from out, starting at the beginning.
// Returns a new cstr_t object containing the substring, or NULL on error.
cstr_t *cstr_substr(cstr_t *out, size_t len) {
    if (!out || len > out->_size) return NULL;

    cstr_t *substr = malloc(sizeof(cstr_t));
    if (!substr) return NULL;

    size_t dSize = (out->_charTraits == &char_char_traits ? 1 :
                    out->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    out->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    substr->_data = malloc(len * dSize);
    if (!substr->_data) {
        free(substr);
        return NULL;
    }

    out->_charTraits->copy(substr->_data, out->_data, len);
    substr->_size = len;
    substr->_capacity = len;
    substr->_charTraits = out->_charTraits;

    return substr;
}

// Compares two cstr_t strings lexicographically.
// Returns 0 if a equals b, negative if a < b, and positive if a > b.
int cstr_compare_cstr(const cstr_t *a, const cstr_t *b) {
    if (!a || !b || a->_charTraits != b->_charTraits) return -1;

    size_t min_size = (a->_size < b->_size) ? a->_size : b->_size;
    int cmp = a->_charTraits->compare(a->_data, b->_data, min_size);
    if (cmp == 0) {
        return (a->_size > b->_size) - (a->_size < b->_size);
    }

    return cmp;
}

// Compares a substring of a (starting at pos, length len) with b lexicographically.
// Returns 0 if they are equal, negative if the substring is less than b, positive if greater.
int cstr_compare_substr(const cstr_t *a, size_t pos, size_t len, const cstr_t *b) {
    if (!a || !b || pos >= a->_size || a->_charTraits != b->_charTraits) return -1;

    size_t actual_len = (pos + len > a->_size) ? a->_size - pos : len;
    size_t min_size = (actual_len < b->_size) ? actual_len : b->_size;

    int cmp = a->_charTraits->compare((char *)a->_data + pos *
                                      (a->_charTraits == &char_char_traits ? 1 :
                                       a->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                                       a->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                                       sizeof(char32_t)),
                                      b->_data, min_size);
    if (cmp == 0) {
        return (actual_len > b->_size) - (actual_len < b->_size);
    }

    return cmp;
}

// Compares a cstr_t string with a null-terminated C-string lexicographically.
// Returns 0 if they are equal, negative if a < b, positive if a > b.
int cstr_compare_ccp(const cstr_t *a, const char *b) {
    if (!a || !b) return -1;

    size_t b_len = a->_charTraits->length(b);
    size_t min_len = (a->_size < b_len) ? a->_size : b_len;

    int cmp = a->_charTraits->compare(a->_data, b, min_len);
    if (cmp == 0) {
        return (a->_size > b_len) - (a->_size < b_len);
    }

    return cmp;
}

// Compares a substring of a (starting at pos, length len) with a buffer s of length n lexicographically.
// Returns 0 if they are equal, negative if the substring is less than s, positive if greater.
int cstr_compare_buffer(const cstr_t *a, size_t pos, size_t len, const char *s, size_t n) {
    if (!a || !s || pos >= a->_size) return -1;

    size_t actual_len = (pos + len > a->_size) ? a->_size - pos : len;
    size_t min_len = (actual_len < n) ? actual_len : n;

    size_t dSize = (a->_charTraits == &char_char_traits ? 1 :
                    a->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    a->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    int cmp = a->_charTraits->compare((char *)a->_data + pos * dSize, s, min_len);
    if (cmp == 0) {
        return (actual_len > n) - (actual_len < n);
    }

    return cmp;
}

// Returns a constant representing "not found" (equivalent to SIZE_MAX).
const size_t cstr_npos(cstr_t *out) {
    (void)out; // Unused parameter
    return SIZE_MAX;
}

// Creates a forward iterator pointing to the beginning of the string
cstr_iterator_t cstr_begin(cstr_t *str) {
    return (cstr_iterator_t){ .str = str, .index = 0 };
}

// Creates a forward iterator pointing to the end of the string (one past the last character)
cstr_iterator_t cstr_end(cstr_t *str) {
    return (cstr_iterator_t){ .str = str, .index = str ? str->_size : 0 };
}

// Creates a reverse iterator pointing to the last character of the string
cstr_reverse_iterator_t cstr_rbegin(cstr_t *str) {
    return (cstr_reverse_iterator_t){ .str = str, .index = str ? str->_size - 1 : 0 };
}

// Creates a reverse iterator pointing to one before the beginning of the string
cstr_reverse_iterator_t cstr_rend(cstr_t *str) {
    return (cstr_reverse_iterator_t){ .str = str, .index = (size_t)-1 };
}

// Advances the forward iterator by one step
void cstr_iterator_next(cstr_iterator_t *it) {
    if (it && it->str && it->index < it->str->_size) {
        it->index++;
    }
}

// Moves the reverse iterator back by one step
void cstr_reverse_iterator_prev(cstr_reverse_iterator_t *it) {
    if (it && it->str && it->index != (size_t)-1) {
        it->index--;
    }
}

// Accesses the character at the current iterator position
const void *cstr_iterator_deref(const cstr_iterator_t *it) {
    if (!it || !it->str || it->index >= it->str->_size) return NULL;

    size_t dSize = (it->str->_charTraits == &char_char_traits ? 1 :
                    it->str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    it->str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    return (const void *)((char *)it->str->_data + it->index * dSize);
}

// Accesses the character at the current reverse iterator position
const void *cstr_reverse_iterator_deref(const cstr_reverse_iterator_t *it) {
    if (!it || !it->str || it->index >= it->str->_size) return NULL;

    size_t dSize = (it->str->_charTraits == &char_char_traits ? 1 :
                    it->str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    it->str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    return (const void *)((char *)it->str->_data + it->index * dSize);
}

int cstr_iterator_equal(const cstr_iterator_t *a, const cstr_iterator_t *b) {
    return a && b && a->str == b->str && a->index == b->index;
}

int cstr_reverse_iterator_equal(const cstr_reverse_iterator_t *a, const cstr_reverse_iterator_t *b) {
    return a && b && a->str == b->str && a->index == b->index;
}

const void *cstr_iterator_advance(const cstr_iterator_t *it, size_t n) {
    if (!it || !it->str || it->index + n >= it->str->_size) return NULL;

    size_t dSize = (it->str->_charTraits == &char_char_traits ? 1 :
                    it->str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    it->str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    return (const void *)((char *)it->str->_data + (it->index + n) * dSize);
}

const void *cstr_reverse_iterator_advance(const cstr_reverse_iterator_t *it, size_t n) {
    if (!it || !it->str || n > it->index) return NULL;

    size_t dSize = (it->str->_charTraits == &char_char_traits ? 1 :
                    it->str->_charTraits == &wchar_t_char_traits ? sizeof(wchar_t) :
                    it->str->_charTraits == &char16_t_char_traits ? sizeof(char16_t) :
                    sizeof(char32_t));

    return (const void *)((char *)it->str->_data + (it->index - n) * dSize);
}
