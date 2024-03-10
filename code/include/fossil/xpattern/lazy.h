/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef FSCL_LAZY_H
#define FSCL_LAZY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>

// Define a simple string type
typedef struct {
    char *data;
} clazy_string;

// Enum to represent different data types
typedef enum {
    CLAZY_INT,
    CLAZY_BOOL,
    CLAZY_CHAR,
    CLAZY_STRING,
    CLAZY_NULL
} clazy_type;

typedef struct {
    int is_evaluated;
    clazy_type type;
    union {
        int int_value;
        bool bool_value;
        char char_value;
        clazy_string string_value;
    } data;

    // Memoization cache
    union {
        int memoized_int;
        bool memoized_bool;
        char memoized_char;
        clazy_string memoized_string;
    } cache;
} clazy;

// =================================================================
// Create and Erase
// =================================================================

/**
 * Create a lazy object with the specified type.
 *
 * @param type The type of the lazy object.
 * @return     The created lazy object.
 */
clazy fscl_lazy_create(clazy_type type);

/**
 * Erase a lazy object.
 *
 * @param lazy The lazy object to erase.
 */
void fscl_lazy_erase(clazy* lazy);

// =================================================================
// Jedi Dreamer Force Functions
// =================================================================

/**
 * Force the evaluation of the lazy object.
 *
 * @param lazy The lazy object to force.
 */
void fscl_lazy_force(clazy* lazy);

/**
 * Force and return the integer value of the lazy object.
 *
 * @param lazy The lazy object to force.
 * @return     The forced integer value.
 */
int fscl_lazy_force_int(clazy* lazy);

/**
 * Force and return the boolean value of the lazy object.
 *
 * @param lazy The lazy object to force.
 * @return     The forced boolean value.
 */
bool fscl_lazy_force_bool(clazy* lazy);

/**
 * Force and return the character value of the lazy object.
 *
 * @param lazy The lazy object to force.
 * @return     The forced character value.
 */
char fscl_lazy_force_char(clazy* lazy);

/**
 * Force and return the string value of the lazy object.
 *
 * @param lazy The lazy object to force.
 * @return     The forced string value.
 */
const char* fscl_lazy_force_string(clazy* lazy);

// =================================================================
// Additional Functions
// =================================================================

/**
 * Create a lazy sequence object.
 *
 * @return The created lazy sequence object.
 */
clazy fscl_lazy_sequence(void);

/**
 * Force and return the next value of the lazy sequence.
 *
 * @param lazy The lazy sequence object to force.
 * @param n    Number of values to skip.
 * @return     The forced integer value.
 */
int fscl_lazy_sequence_force(clazy* lazy, int n);

/**
 * Set the integer value of the lazy object.
 *
 * @param lazy  The lazy object to set.
 * @param value The integer value to set.
 */
void fscl_lazy_set_int(clazy* lazy, int value);

// Other lazy set functions ...

/**
 * Conditional evaluation of the lazy object based on the given condition.
 *
 * @param lazy      The lazy object to conditionally evaluate.
 * @param condition The condition for evaluation.
 */
void fscl_lazy_conditional_eval(clazy* lazy, int condition);

/**
 * Map the lazy integer object using the provided mapping function.
 *
 * @param lazy          The lazy integer object to map.
 * @param mapFunction   The mapping function for integers.
 */
void fscl_lazy_map_int(clazy* lazy, int (*mapFunction)(int));

// Other lazy map functions ...

/**
 * Concatenate two lazy string objects and store the result in another lazy object.
 *
 * @param result The lazy object to store the concatenated result.
 * @param str1   The first lazy string object.
 * @param str2   The second lazy string object.
 */
void fscl_lazy_concat_cstrings(clazy* result, clazy* str1, clazy* str2);

/**
 * Print the forced value of the lazy object.
 *
 * @param lazy The lazy object to print.
 */
void fscl_lazy_print(clazy* lazy);

#ifdef __cplusplus
}
#endif

#endif
