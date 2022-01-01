#ifndef HILLS_MULTI_VAR_H
#define HILLS_MULTI_VAR_H

#include <stddef.h>
#include "test.h"

////////////////////////////////////
// CONSTANTS AND MACROS
///////////////////////////////////

#define NUM_ATTEMPTS_HILLS_MULTI_VAR 99

////////////////////////////////////
// FUNCTION DECLARATIONS
///////////////////////////////////

/*
 * hills_quadratic_format
 * Returns the format string for the quadratic hills
 * 
 * Takes no arguments
 * 
 * Returns a format string
 */
char* hills_multi_var_format();

/*
 * hills_quadratic
 * A wrapper for the hills function, performs quality of life checks
 *
 * :: const void* location :: The location buffer
 *
 * If the location is null, returns the current best result 
 * If the number of attempts has been exceeded, returns -1
 * Otherwise evaluates the function
 */
int hills_multi_var(const void* loc);

/*
 * hills_quadratic_function
 * Evaluates a particular hills function
 *
 * :: const void* location :: The location buffer
 *
 * Returns the evaluated function
 */
int hills_multi_var_function(const void* loc);


#endif