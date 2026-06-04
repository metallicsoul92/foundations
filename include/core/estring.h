/**
 * @file estring.h
 * @brief A custom string library for C.
 *
 * This library provides functionality for working with custom string structures.
 * Users can create, manipulate, and manage strings using this library.
 * The library includes functions for construction, destruction, getters,
 * setters, and substring extraction.
 *
 * The custom string structure (`estring_t`) is designed for more efficient
 * string handling and serves as an alternative to the standard C string functions.
 *
 * @attention This library is meant to work with simple ASCII strings and does not
 * handle Unicode or complex encoding. For more advanced use cases, consider
 * using other libraries or developing custom solutions.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_CORE_ESTRING_H_
#define FOUNDATIONS_CORE_ESTRING_H_

#ifndef STDINT_DEFINED
	#include <stdint.h>
	#define STDINT_DEFINED 1
#endif

#ifndef STDBOOL_DEFINED
	#include <stdbool.h>
	#define STDBOOL_DEFINED 1
#endif

#ifndef STDIO_DEFINED
#include <stdio.h>
#define STDIO_DEFINED 1
#endif


/** @struct estring
 *  @brief A custom string structure for C.
 *
 *  The `estring` structure represents a custom string type that provides
 *  efficient string manipulation.
 *
 *  @var estring::_length
 *  The length of the string.
 *
 *  @var estring::_string
 *  A pointer to the character data of the string.
 */
typedef struct estring estring_t;

/** @brief Allocate a new `estring_t` and initialize it with the provided data.
 *
 *  @param data A pointer to the character data to initialize the string with.
 *  @return A pointer to the newly created `estring_t`.
 */
estring_t * malloc_estring(const char * data);

/** @brief Create a new `estring_t` and copy the contents of an existing string into it.
 *
 *  @param data The `estring_t` to copy.
 *  @return A pointer to the newly created `estring_t` containing the copied data.
 */
estring_t * copy_estring(const estring_t * data);

/** @brief Move an existing `estring_t` to a new one and invalidate the original string.
 *
 *  @param data The `estring_t` to move.
 *  @return A pointer to the newly created `estring_t` with the data from the original.
 */
estring_t * move_estring(estring_t * data);

/** @brief Create estring from file .
 *
 *  @param The filepath as a const char *
 *  @return An estring_t of the file contents
 */
estring_t * estring_fromFile(const char *filepath);

/** @brief Deallocate memory used by an `estring_t`.
 *
 *  @param self A pointer to the `estring_t` to free.
 */
void free_estring(estring_t * self);

/** @brief Get the length of an `estring_t`.
 *
 *  @param self A pointer to the `estring_t`.
 *  @return The length of the string.
 */
uint32_t estring_length(estring_t *self);

/** @brief Get the character data of an `estring_t`.
 *
 *  @param self A pointer to the `estring_t`.
 *  @return A pointer to the character data.
 */
char * estring_str(estring_t *self);

/** @brief Get the character at a specific index in an `estring_t`.
 *
 *  @param self A pointer to the `estring_t`.
 *  @param index The index of the character to retrieve.
 *  @return The character at the specified index or '\0' if out of bounds.
 */
char estring_getAt(estring_t *self, uint32_t index);

/** @brief Check if two `estring_t` objects contain the same data.
 *
 *  @param a The first `estring_t`.
 *  @param b The second `estring_t`.
 *  @return `true` if the strings are equal, `false` otherwise.
 */
bool estring_isEqual(estring_t * a, estring_t * b);

/** @brief Append additional characters to an `estring_t`.
 *
 *  @param self A pointer to the `estring_t`.
 *  @param extra A pointer to the character data to append.
 */
void estring_append(estring_t * self, const char * extra);

/** @brief Set a character at a specific index in an `estring_t`.
 *
 *  @param self A pointer to the `estring_t`.
 *  @param letter The character to set.
 *  @param index The index at which to set the character.
 */
void estring_setAt(estring_t * self, const char letter, uint32_t index);

/** @brief Create a new `estring_t` that is a substring of an existing string.
 *
 *  @param str A pointer to the `estring_t` to extract the substring from.
 *  @param start The starting index of the substring.
 *  @param end The ending index of the substring.
 *  @return A pointer to the newly created `estring_t` representing the substring.
 *          Returns `NULL` if the indices are out of bounds.
 */
estring_t * estring_substr(estring_t * str, uint32_t start, uint32_t end);

#endif
