#ifndef FOUNDATIONS_CORE_CSTR_C_CHAR_TRAITS_H_
#define FOUNDATIONS_CORE_CSTR_C_CHAR_TRAITS_H_

#include <stddef.h> // For size_t

// Define a char_traits interface using function pointers.
// This structure allows defining character-type-specific operations dynamically
// without relying on compile-time templates like C++'s std::char_traits.
typedef struct char_traits {
    // Function to calculate the length of a string for a given character type.
    // - Input: str - pointer to the string (can be any type, e.g., char, wchar_t).
    // - Returns: Length of the string as size_t.
    size_t (*length)(const void *str);

    // Function to copy `n` characters from src to dst.
    // - Input: dst - destination buffer.
    //          src - source buffer.
    //          n   - number of characters to copy.
    // - Returns: Pointer to the destination buffer (dst).
    void * (*copy)(void *dst, const void *src, size_t n);

    // Function to compare two strings for a given character type.
    // - Input: s1 - pointer to the first string.
    //          s2 - pointer to the second string.
    //          n  - number of characters to compare.
    // - Returns: An integer < 0, 0, or > 0 depending on the lexicographical comparison.
    int (*compare)(const void *s1, const void *s2, size_t n);

    // Function to assign a character from src to dst.
    // - Input: dst - destination buffer.
    //          src - source character.
    // - Returns: Pointer to the destination buffer (dst).
    void * (*assign)(void *dst, const void *src);

    // Function to check if two characters are equal.
    // - Input: a - pointer to the first character.
    //          b - pointer to the second character.
    // - Returns: 1 if equal, 0 otherwise.
    int (*eq)(const void *a, const void *b);

    // Function to check if one character is less than another.
    // - Input: a - pointer to the first character.
    //          b - pointer to the second character.
    // - Returns: 1 if a < b, 0 otherwise.
    int (*lt)(const void *a, const void *b);
} char_traits_t;

// Function table declarations for different character types.
// These tables provide the appropriate implementations of char_traits
// for each supported character type (e.g., char, wchar_t, char16_t, char32_t).

// Character traits for `char` type (e.g., "Hello").
extern const char_traits_t char_char_traits;

// Character traits for `wchar_t` type (e.g., L"Hello").
extern const char_traits_t wchar_t_char_traits;

// Character traits for `char16_t` type (e.g., u"Hello").
extern const char_traits_t char16_t_char_traits;

// Character traits for `char32_t` type (e.g., U"Hello").
extern const char_traits_t char32_t_char_traits;

#endif // CHARTRAITS_H_
