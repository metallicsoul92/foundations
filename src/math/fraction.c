#include "../../include/math/fraction.h"
#include <math.h>
#include <stdlib.h>

struct _fract{
  int64_t _numerator;
  int64_t _denominator;
};

// Memory management functions

fraction_t *fraction_malloc(int64_t n, int64_t d) {
    // return if d == 0
    if( d == 0 ){
      return NULL;
    }
    // Allocate memory for a fraction structure
    fraction_t *fraction = (fraction_t *)malloc(sizeof(fraction_t));
    if (fraction == NULL) {
        // Memory allocation failed
        return NULL;
    }

    // Initialize numerator and denominator
    fraction->_numerator = n;
    fraction->_denominator = d;

    return fraction;
}

fraction_t fraction_init(int64_t n, int64_t d) {

  // return if d == 0
  if( d == 0 ){
    //set d to 1
    //TODO: Fix
    d++;
  }
    // Initialize a fraction structure without dynamic memory allocation
    fraction_t fraction;
    fraction._numerator = n;
    fraction._denominator = d;
    return fraction;
}

void fraction_free(fraction_t *out) {
    // Free memory associated with a fraction
    free(out);
}

// Getter functions

int64_t fraction_getNumerator(fraction_t *out) {
    // Get the numerator of a fraction
    return out->_numerator;
}

int64_t fraction_getDenominator(fraction_t *out) {
    // Get the denominator of a fraction
    return out->_denominator;
}

// Conversion functions

float fraction_toFloat(fraction_t *out) {
    // Convert a fraction to a float
    return (float)(out->_numerator) / (float)(out->_denominator);
}

double fraction_toDouble(fraction_t *out) {
    // Convert a fraction to a double
    return (double)(out->_numerator) / (double)(out->_denominator);
}


// Functions for creating fraction structures from floating-point numbers

// Allocate memory for a fraction from a float
fraction_t *fraction_allocFromFloat(float frac) {
    // Calculate the nearest integer value for the numerator
    int64_t n = (int64_t)frac;

    // Calculate the error between frac and its nearest integer value
    float error = frac - n;

    // Choose a suitable denominator based on the error
    int64_t d = 1;
    while (fabsf(error) > 0.00001) {  // Adjust tolerance level as needed
        d *= 10;
        n = (int64_t)(frac * d);
        error = frac * d - n;
    }

    // Allocate memory for the fraction
    fraction_t *fraction = fraction_malloc(n, d);
    return fraction;
}

// Allocate memory for a fraction from a double
fraction_t *fraction_allocFromDouble(double frac) {
    // Calculate the nearest integer value for the numerator
    int64_t n = (int64_t)frac;

    // Calculate the error between frac and its nearest integer value
    double error = frac - n;

    // Choose a suitable denominator based on the error
    int64_t d = 1;
    while (fabs(error) > 0.0000001) {  // Adjust tolerance level as needed
        d *= 10;
        n = (int64_t)(frac * d);
        error = frac * d - n;
    }

    // Allocate memory for the fraction
    fraction_t *fraction = fraction_malloc(n, d);
    return fraction;
}

// Initialize a fraction from a float without dynamic memory allocation
fraction_t fraction_initFromFloat(float frac) {
    // Calculate the nearest integer value for the numerator
    int64_t n = (int64_t)frac;

    // Calculate the error between frac and its nearest integer value
    float error = frac - n;

    // Choose a suitable denominator based on the error
    int64_t d = 1;
    while (fabsf(error) > 0.00001) {  // Adjust tolerance level as needed
        d *= 10;
        n = (int64_t)(frac * d);
        error = frac * d - n;
    }

    // Initialize the fraction without dynamic memory allocation
    fraction_t fraction = fraction_init(n, d);
    return fraction;
}

// Initialize a fraction from a double without dynamic memory allocation
fraction_t fraction_initFromDouble(double frac) {
    // Calculate the nearest integer value for the numerator
    int64_t n = (int64_t)frac;

    // Calculate the error between frac and its nearest integer value
    double error = frac - n;

    // Choose a suitable denominator based on the error
    int64_t d = 1;
    while (fabs(error) > 0.0000001) {  // Adjust tolerance level as needed
        d *= 10;
        n = (int64_t)(frac * d);
        error = frac * d - n;
    }

    // Initialize the fraction without dynamic memory allocation
    fraction_t fraction = fraction_init(n, d);
    return fraction;
}
