#include "../../include/cstr/cchartraits.h"
#include <string.h>  // For strlen, memcpy, etc.
#include <wchar.h>   // For wcslen, wmemcpy, etc.
#include <uchar.h>
#include <stdint.h>  // For char16_t, char32_t

// ====== Implementation for char ======
static size_t char_length(const char *str) {
    return strlen(str);
}

static void * char_copy(char *dst, const char *src, size_t n) {
    return memcpy(dst, src, n);
}

static int char_compare(const char *s1, const char *s2, size_t n) {
    return strncmp(s1, s2, n);
}

static void * char_assign(char *dst, const char *src) {
    *dst = *src;
    return dst;
}

static int char_eq(const char *a, const char *b) {
    return *a == *b;
}

static int char_lt(const char *a, const char *b) {
    return *a < *b;
}

const char_traits_t char_char_traits = {
    .length = (size_t (*)(const void *))char_length,
    .copy = (void *(*)(void *, const void *, size_t))char_copy,
    .compare = (int (*)(const void *, const void *, size_t))char_compare,
    .assign = (void *(*)(void *, const void *))char_assign,
    .eq = (int (*)(const void *, const void *))char_eq,
    .lt = (int (*)(const void *, const void *))char_lt
};

// ====== Implementation for wchar_t ======
static size_t wchar_length(const wchar_t *str) {
    return wcslen(str);
}

static void * wchar_copy(wchar_t *dst, const wchar_t *src, size_t n) {
    return wmemcpy(dst, src, n);
}

static int wchar_compare(const wchar_t *s1, const wchar_t *s2, size_t n) {
    return wmemcmp(s1, s2, n);
}

static void * wchar_assign(wchar_t *dst, const wchar_t *src) {
    *dst = *src;
    return dst;
}

static int wchar_eq(const wchar_t *a, const wchar_t *b) {
    return *a == *b;
}

static int wchar_lt(const wchar_t *a, const wchar_t *b) {
    return *a < *b;
}

const char_traits_t wchar_t_char_traits = {
    .length = (size_t (*)(const void *))wchar_length,
    .copy = (void *(*)(void *, const void *, size_t))wchar_copy,
    .compare = (int (*)(const void *, const void *, size_t))wchar_compare,
    .assign = (void *(*)(void *, const void *))wchar_assign,
    .eq = (int (*)(const void *, const void *))wchar_eq,
    .lt = (int (*)(const void *, const void *))wchar_lt
};

// ====== Implementation for char16_t ======
static size_t char16_length(const char16_t *str) {
    const char16_t *ptr = str;
    while (*ptr++) {}
    return ptr - str - 1;
}

static void * char16_copy(char16_t *dst, const char16_t *src, size_t n) {
    return memcpy(dst, src, n * sizeof(char16_t));
}

static int char16_compare(const char16_t *s1, const char16_t *s2, size_t n) {
    return memcmp(s1, s2, n * sizeof(char16_t));
}

static void * char16_assign(char16_t *dst, const char16_t *src) {
    *dst = *src;
    return dst;
}

static int char16_eq(const char16_t *a, const char16_t *b) {
    return *a == *b;
}

static int char16_lt(const char16_t *a, const char16_t *b) {
    return *a < *b;
}

const char_traits_t char16_t_char_traits = {
    .length = (size_t (*)(const void *))char16_length,
    .copy = (void *(*)(void *, const void *, size_t))char16_copy,
    .compare = (int (*)(const void *, const void *, size_t))char16_compare,
    .assign = (void *(*)(void *, const void *))char16_assign,
    .eq = (int (*)(const void *, const void *))char16_eq,
    .lt = (int (*)(const void *, const void *))char16_lt
};

// ====== Implementation for char32_t ======
static size_t char32_length(const char32_t *str) {
    const char32_t *ptr = str;
    while (*ptr++) {}
    return ptr - str - 1;
}

static void * char32_copy(char32_t *dst, const char32_t *src, size_t n) {
    return memcpy(dst, src, n * sizeof(char32_t));
}

static int char32_compare(const char32_t *s1, const char32_t *s2, size_t n) {
    return memcmp(s1, s2, n * sizeof(char32_t));
}

static void * char32_assign(char32_t *dst, const char32_t *src) {
    *dst = *src;
    return dst;
}

static int char32_eq(const char32_t *a, const char32_t *b) {
    return *a == *b;
}

static int char32_lt(const char32_t *a, const char32_t *b) {
    return *a < *b;
}

const char_traits_t char32_t_char_traits = {
    .length = (size_t (*)(const void *))char32_length,
    .copy = (void *(*)(void *, const void *, size_t))char32_copy,
    .compare = (int (*)(const void *, const void *, size_t))char32_compare,
    .assign = (void *(*)(void *, const void *))char32_assign,
    .eq = (int (*)(const void *, const void *))char32_eq,
    .lt = (int (*)(const void *, const void *))char32_lt
};
