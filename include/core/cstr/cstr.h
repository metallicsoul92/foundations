#ifndef FOUNDATIONS_CORE_CSTR_CSTR_H_
#define FOUNDATIONS_CORE_CSTR_CSTR_H_


typedef struct cstr cstr_t;

// Forward iterator structure
typedef struct {
    cstr_t *str;  // Pointer to the associated string
    size_t index; // Current index in the string
} cstr_iterator_t;

// Reverse iterator structure
typedef struct {
    cstr_t *str;  // Pointer to the associated string
    size_t index; // Current index in the string
} cstr_reverse_iterator_t;

/* --- Constructors --- */

// Constructs an empty cstr_t object with the specified character trait.
cstr_t *cstr_malloc_empty(const char_traits_t *charTraits);

// Constructs a cstr_t object from a null-terminated C-string.
cstr_t *cstr_malloc_ccp(const void *string, const char_traits_t *charTraits);

// Constructs a cstr_t object by copying another cstr_t.
cstr_t *cstr_malloc_copy(const cstr_t *str);

// Constructs a cstr_t object from the first n characters of a C-string.
cstr_t *cstr_malloc_ccp_n(const void *string, size_t n, const char_traits_t *charTraits);

// Constructs a cstr_t object filled with n repetitions of character c.
cstr_t *cstr_malloc_fill(size_t n, const void *c, const char_traits_t *charTraits);

// Moves an existing cstr_t object into a new one.
cstr_t *cstr_malloc_move(cstr_t *mov);

/* --- Destructor --- */

// Frees memory associated with a cstr_t object.
void cstr_free(cstr_t *ret);

/* --- Assignment Operators --- */

// Assigns the contents of str to out. Returns out on success, NULL on failure.
cstr_t *cstr_assign_copy(cstr_t *out, const cstr_t *str);

// Assigns a null-terminated C-string to out. Returns out on success, NULL on failure.
cstr_t *cstr_assign_ccp(cstr_t *out, const void *str, const char_traits_t *charTraits);

// Assigns a single character to out. Returns out on success, NULL on failure.
cstr_t *cstr_assign_c(cstr_t *out, const void *c, const char_traits_t *charTraits);

// Moves the contents of mov to out. Returns out on success, NULL on failure.
cstr_t *cstr_assign_move(cstr_t *out, cstr_t *mov);

// Assigns a substring of str to out. Returns out on success, NULL on failure.
cstr_t *cstr_assign_substr(cstr_t *out, const cstr_t *str, size_t subpos, size_t sublen);

/* --- Iterators --- */

// Returns a forward iterator pointing to the first character of the string.
cstr_iterator_t cstr_begin(cstr_t *str);

// Returns a forward iterator pointing one past the last character of the string.
cstr_iterator_t cstr_end(cstr_t *str);

// Returns a reverse iterator pointing to the last character of the string.
cstr_reverse_iterator_t cstr_rbegin(cstr_t *str);

// Returns a reverse iterator pointing one position before the first character of the string.
cstr_reverse_iterator_t cstr_rend(cstr_t *str);

// Advances the forward iterator to the next character in the string.
void cstr_iterator_next(cstr_iterator_t *it);

// Moves the reverse iterator to the previous character in the string.
void cstr_reverse_iterator_prev(cstr_reverse_iterator_t *it);

// Returns a pointer to the character at the current iterator position.
const void *cstr_iterator_deref(const cstr_iterator_t *it);

// Returns a pointer to the character at the current reverse iterator position.
const void *cstr_reverse_iterator_deref(const cstr_reverse_iterator_t *it);

// Checks if two forward iterators point to the same position in the same string.
int cstr_iterator_equal(const cstr_iterator_t *a, const cstr_iterator_t *b);

// Checks if two reverse iterators point to the same position in the same string.
int cstr_reverse_iterator_equal(const cstr_reverse_iterator_t *a, const cstr_reverse_iterator_t *b);

// Advances the forward iterator by n positions.
const void *cstr_iterator_advance(const cstr_iterator_t *it, size_t n);

// Moves the reverse iterator back by n positions.
const void *cstr_reverse_iterator_advance(const cstr_reverse_iterator_t *it, size_t n);

/* --- Capacity --- */

// Returns the size of the string (number of characters, excluding null terminator).
const size_t cstr_size(const cstr_t *str);

// Returns the length of the string (alias for cstr_size).
const size_t cstr_length(const cstr_t *str);

// Returns the maximum size the string can hold.
const size_t cstr_maxSize(const cstr_t *str);

// Returns the currently allocated capacity of the string.
const size_t cstr_capacity(const cstr_t *str);

// Resizes the string to hold n characters, filling new characters with default values.
void cstr_resize(cstr_t *str, size_t n);

// Resizes the string to hold n characters, filling new characters with c.
void cstr_resize_c(cstr_t *str, size_t n, const void *c);

// Ensures the string has at least n capacity.
void cstr_reserve(cstr_t *str, size_t n);

// Clears the contents of the string, retaining its capacity.
void cstr_clear(cstr_t *str);

// Checks if the string is empty (returns 1 if true, 0 otherwise).
int cstr_isEmpty(const cstr_t *str);

// Reduces the capacity of the string to match its size.
void cstr_shrinkToFit(cstr_t *str);

/* --- Modifiers --- */

// Returns the character at position pos in the string, or '\0' if pos is out of bounds.
const void *cstr_at(const cstr_t *str, size_t pos);

// Returns the first character of the string, or '\0' if the string is empty.
const void *cstr_front(const cstr_t *str);

// Returns the last character of the string, or '\0' if the string is empty.
const void *cstr_back(const cstr_t *str);

// Appends the contents of other to ret. Returns ret on success, NULL on failure.
cstr_t *cstr_append_cstr(cstr_t *ret, const cstr_t *other);

// Appends a substring of other to ret. Returns ret on success, NULL on failure.
cstr_t *cstr_append_csubstr(cstr_t *ret, const cstr_t *other, size_t subpos, size_t sublen);

// Appends a null-terminated C-string to ret. Returns ret on success, NULL on failure.
cstr_t *cstr_append_ccp(cstr_t *ret, const void *other);

// Appends the first n characters of other to ret. Returns ret on success, NULL on failure.
cstr_t *cstr_append_cstr_buffer(cstr_t *ret, const cstr_t *other, size_t n);

// Appends n repetitions of character c to ret. Returns ret on success, NULL on failure.
cstr_t *cstr_append_fill(cstr_t *ret, size_t n, const void *c);

// Pushes a single character to the back of the string.
void cstr_pushBack(cstr_t *ret, const void *c);

// Inserts other at position pos in out. Returns out on success, NULL on failure.
cstr_t *cstr_insert_cstr(cstr_t *out, size_t pos, const cstr_t *other);

// Inserts a substring of other at position pos in out. Returns out on success, NULL on failure.
cstr_t *cstr_insert_substr(cstr_t *out, size_t pos, const cstr_t *other, size_t subpos, size_t sublen);

// Inserts a null-terminated C-string at position pos in out. Returns out on success, NULL on failure.
cstr_t *cstr_insert_ccp(cstr_t *out, size_t pos, const void *other);

// Inserts the first n characters of other at position pos in out. Returns out on success, NULL on failure.
cstr_t *cstr_insert_buffer(cstr_t *out, size_t pos, const void *other, size_t n);

// Inserts n repetitions of character c at position pos in out. Returns out on success, NULL on failure.
cstr_t *cstr_insert_fill(cstr_t *out, size_t pos, size_t n, const void *c);

// Erases len characters starting from position pos in the string. Returns the modified string on success, NULL on failure.
cstr_t *cstr_erase(cstr_t *out, size_t pos, size_t len);

// Replaces characters starting at pos in out with the contents of other. Returns out on success, NULL on failure.
cstr_t *cstr_replace_cstr(cstr_t *out, size_t pos, const cstr_t *other);

// Replaces characters starting at pos in out with a substring of other. Returns out on success, NULL on failure.
cstr_t *cstr_replace_substr(cstr_t *out, size_t pos, const cstr_t *other, size_t subpos, size_t sublen);

// Replaces characters starting at pos in out with a C-string other. Returns out on success, NULL on failure.
cstr_t *cstr_replace_ccp(cstr_t *out, size_t pos, const void *other);

// Replaces characters starting at pos in out with the first n characters of other. Returns out on success, NULL on failure.
cstr_t *cstr_replace_buffer(cstr_t *out, size_t pos, const void *other, size_t n);

// Replaces n characters starting at pos in out with n repetitions of character c. Returns out on success, NULL on failure.
cstr_t *cstr_replace_fill(cstr_t *out, size_t pos, size_t n, const void *c);

// Swaps the contents of out and other.
void cstr_swap(cstr_t *out, cstr_t *other);

// Removes the last character from out.
void cstr_popBack(cstr_t *out);

/* --- Accessors --- */

// Returns a null-terminated C-string representation of out.
const void *cstr_c_str(cstr_t *out);

// Returns a pointer to the internal data buffer of out (not null-terminated).
const void *cstr_data(cstr_t *out);

/* --- Search --- */

// Copies up to len characters from out starting at position pos into s. Returns the number of characters copied.
size_t cstr_copy(cstr_t *out, void *s, size_t len, size_t pos);

// Finds the first occurrence of str in out starting from pos. Returns the position of the first match, or SIZE_MAX if not found.
size_t cstr_find_cstr(cstr_t *out, const cstr_t *str, size_t pos);

// Finds the first occurrence of a C-string s in out starting from pos. Returns the position of the first match, or SIZE_MAX if not found.
size_t cstr_find_ccp(cstr_t *out, const void *s, size_t pos);

// Finds the first occurrence of a buffer s of length n in out starting from pos. Returns the position of the first match, or SIZE_MAX if not found.
size_t cstr_find_buffer(cstr_t *out, const void *s, size_t pos, size_t n);

// Finds the first occurrence of character c in out starting from pos. Returns the position of the first match, or SIZE_MAX if not found.
size_t cstr_find_char(cstr_t *out, const void *c, size_t pos);

// Finds the last occurrence of str in out up to pos. Returns the position of the last match, or SIZE_MAX if not found.
size_t cstr_rfind_cstr(cstr_t *out, const cstr_t *str, size_t pos);

// Finds the last occurrence of a C-string s in out up to pos. Returns the position of the last match, or SIZE_MAX if not found.
size_t cstr_rfind_ccp(cstr_t *out, const void *s, size_t pos);

// Finds the last occurrence of a buffer s of length n in out up to pos. Returns the position of the last match, or SIZE_MAX if not found.
size_t cstr_rfind_buffer(cstr_t *out, const void *s, size_t pos, size_t n);

// Finds the last occurrence of character c in out up to pos. Returns the position of the last match, or SIZE_MAX if not found.
size_t cstr_rfind_char(cstr_t *out, const void *c, size_t pos);

// Finds the first occurrence in out (starting at pos) of any character present in str. Returns the position of the first match, or SIZE_MAX if no match is found.
size_t cstr_find_first_of_cstr(cstr_t *out, const cstr_t *str, size_t pos);

// Finds the first occurrence in out (starting at pos) of any character present in the C-string s. Returns the position of the first match, or SIZE_MAX if no match is found.
size_t cstr_find_first_of_ccp(cstr_t *out, const void *s, size_t pos);

// Finds the first occurrence in out (starting at pos) of any character present in the first n bytes of s. Returns the position of the first match, or SIZE_MAX if no match is found.
size_t cstr_find_first_of_buffer(cstr_t *out, const void *s, size_t pos, size_t n);

// Finds the first occurrence in out (starting at pos) of the character c. Returns the position of the first match, or SIZE_MAX if no match is found.
size_t cstr_find_first_of_char(cstr_t *out, const void *c, size_t pos);

// Finds the last occurrence in out (up to pos) of any character present in str. Returns the position of the last match, or SIZE_MAX if no match is found.
size_t cstr_find_last_of_cstr(cstr_t *out, const cstr_t *str, size_t pos);

// Finds the last occurrence in out (up to pos) of any character present in the C-string s. Returns the position of the last match, or SIZE_MAX if no match is found.
size_t cstr_find_last_of_ccp(cstr_t *out, const void *s, size_t pos);

// Finds the last occurrence in out (up to pos) of any character present in the first n bytes of s. Returns the position of the last match, or SIZE_MAX if no match is found.
size_t cstr_find_last_of_buffer(cstr_t *out, const void *s, size_t pos, size_t n);

// Finds the last occurrence in out (up to pos) of the character c. Returns the position of the last match, or SIZE_MAX if no match is found.
size_t cstr_find_last_of_char(cstr_t *out, const void *c, size_t pos);

// Finds the first position in out (starting from pos) where the character is not in str. Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_first_not_of_cstr(cstr_t *out, const cstr_t *str, size_t pos);

// Finds the first position in out (starting from pos) where the character is not in the C-string s. Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_first_not_of_ccp(cstr_t *out, const void *s, size_t pos);

// Finds the first position in out (starting from pos) where the character is not in the first n bytes of s. Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_first_not_of_buffer(cstr_t *out, const void *s, size_t pos, size_t n);

// Finds the first position in out (starting from pos) where the character is not c. Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_first_not_of_char(cstr_t *out, const void *c, size_t pos);

// Finds the last position in out (up to pos) where the character is not in str. Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_last_not_of_cstr(cstr_t *out, const cstr_t *str, size_t pos);

// Finds the last position in out (up to pos) where the character is not in the C-string s. Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_last_not_of_ccp(cstr_t *out, const void *s, size_t pos);

// Finds the last position in out (up to pos) where the character is not in the first n bytes of s. Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_last_not_of_buffer(cstr_t *out, const void *s, size_t pos, size_t n);

// Finds the last position in out (up to pos) where the character is not c. Returns the position, or SIZE_MAX if all characters match.
size_t cstr_find_last_not_of_char(cstr_t *out, const void *c, size_t pos);

/* --- Substrings and Comparison --- */

// Creates a substring of length len from out, starting at the beginning. Returns a new cstr_t object containing the substring, or NULL on error.
cstr_t *cstr_substr(cstr_t *out, size_t len);

// Compares two cstr_t strings lexicographically. Returns 0 if a equals b, negative if a < b, and positive if a > b.
int cstr_compare_cstr(const cstr_t *a, const cstr_t *b);

// Compares a substring of a (starting at pos, length len) with b lexicographically. Returns 0 if they are equal, negative if the substring is less than b, positive if greater.
int cstr_compare_substr(const cstr_t *a, size_t pos, size_t len, const cstr_t *b);

// Compares a cstr_t string with a null-terminated C-string lexicographically. Returns 0 if they are equal, negative if a < b, positive if a > b.
int cstr_compare_ccp(const cstr_t *a, const char *b);

// Compares a substring of a (starting at pos, length len) with a buffer s of length n lexicographically. Returns 0 if they are equal, negative if the substring is less than s, positive if greater.
int cstr_compare_buffer(const cstr_t *a, size_t pos, size_t len, const char *s, size_t n);

// Returns a constant representing "not found" (equivalent to SIZE_MAX).
const size_t cstr_npos(cstr_t *out);

#endif // LIBHERE_CSTR_H_
