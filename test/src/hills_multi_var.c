#include "hills_multi_var.h"

/*
 * hills_quadratic_format
 * Returns the format string for the quadratic hills
 * 
 * Takes no arguments
 * 
 * Returns a format string
 */
char* hills_multi_var_format()
{
    return "%d %d %d %d";
}

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
int hills_multi_var(const void* location)
{

    static int best = -1;
    static int attempts = 0;

    // Query for current best
    if (NULL == location)
    {
        return best;
    }

    // Check number of attempts
    // If exceeded, set the best to zero and return -1
    if (NUM_ATTEMPTS_HILLS_MULTI_VAR < attempts)
    {
        best = 0;
        return -1; // Remembering that negatives are failures
    }

    // No special cases, make the attempt
    int current = hills_multi_var_function(location);
    attempts++;

    if (current > best)
    {
        best = current;
    }

    return current;
}

/*
 * hills_quadratic_function
 * Evaluates a particular hills function
 *
 * :: const void* location :: The location buffer
 *
 * Returns the evaluated function
 */
int hills_multi_var_function(const void* location)
{

    // Extract the integer from the buffer
    // Null checks were performed in the wrapper
    int a = BYTE_OFFSET(int*, location, (sizeof(int) + 1) * 0);
    int b = BYTE_OFFSET(int*, location, (sizeof(int) + 1) * 1);
    int c = BYTE_OFFSET(int*, location, (sizeof(int) + 1) * 2);
    int d = BYTE_OFFSET(int*, location, (sizeof(int) + 1) * 3);

    int val = - 0.3 * (a - 81) * (a - 26) - 0.3 * (b + 70) * (b + 83) - 0.3 * (c + 16) * (c - 27) - 0.3 * (d + 200) * (d + 250); 

    return val;
}



