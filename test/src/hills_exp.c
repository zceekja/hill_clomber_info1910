#include "hills_exp.h"

/*
 * hills_quadratic_format
 * Returns the format string for the quadratic hills
 * 
 * Takes no arguments
 * 
 * Returns a format string
 */
char* hills_exp_format()
{
    return "      %f        %f";
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
int hills_exp(const void* location)
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
    if (NUM_ATTEMPTS_HILLS_EXP < attempts)
    {
        best = 0;
        return -1; // Remembering that negatives are failures
    }

    // No special cases, make the attempt
    int current = hills_exp_function(location);
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
int hills_exp_function(const void* location)
{
    // Extract the integer from the buffer
    // Null checks were performed in the wrapper
    double x = BYTE_OFFSET(double*, location, 6);
    double y = BYTE_OFFSET(double*, location, 6 + sizeof(double) + 8);
 
    int val = 150 * exp(-((x - 10) * (x - 10) + (y - 15) * (y - 15)) / 100) 
        + 450 * exp(-((x + 100) * (x + 100) + (y + 150) * (y + 150)) / 100) - 100;

    return val;
}



