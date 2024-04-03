#ifndef FOUNDATIONS_MATH_FRACTION_H
#define FOUNDATIONS_MATH_FRACTION_H

// Standard header for fixed-size integer types
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

// Define the fraction structure as an opaque pointer
typedef struct _fract fraction_t;

// Memory management functions
fraction_t *fraction_malloc(int64_t n, int64_t d); // Allocate memory for a fraction with numerator n and denominator d
fraction_t fraction_init(int64_t n, int64_t d);   // Initialize a fraction without dynamic memory allocation
void fraction_free(fraction_t *out);             // Free memory associated with a fraction

// Getter functions
int64_t fraction_getNumerator(fraction_t *out);    // Get the numerator of a fraction
int64_t fraction_getDenominator(fraction_t *out);  // Get the denominator of a fraction

// Conversion functions
float fraction_toFloat(fraction_t *out);    // Convert a fraction to a float
double fraction_toDouble(fraction_t *out);  // Convert a fraction to a double

// Functions for creating fraction structures from floating-point numbers
fraction_t *fraction_allocFromFloat(float frac);    // Allocate memory for a fraction from a float
fraction_t *fraction_allocFromDouble(double frac);  // Allocate memory for a fraction from a double
fraction_t fraction_initFromFloat(float frac);      // Initialize a fraction from a float without dynamic memory allocation
fraction_t fraction_initFromDouble(double frac);    // Initialize a fraction from a double without dynamic memory allocation

#endif
