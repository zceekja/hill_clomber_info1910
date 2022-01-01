#ifndef HILLS_TEST
#define HILLS_TEST

#include <stddef.h>
#include <stdio.h>

////////////////////////////////////
// STRUCTS AND TYPEDEFS
///////////////////////////////////

#define BYTE_OFFSET(type, location, i) (*((type)(location + i)))

/*
 * hills_f
 * 
 * Hills function
 * 
 * :: const void* :: Buffer passed to the hills function
 *
 * Returns the height achieved by the values in the buffer
 */
typedef int (*hills_f)(const void*);

/*
 * hills_format_f
 * Hills format function 
 * 
 * Returns a format string for the hills function
 */
typedef char* (*hills_format_f)();


/*
 * climber_f
 * Function pointer for a climber, 
 * 
 * :: hills_f hills :: Hills function
 * :: hills_format_f hills_format :: Hills format function
 * :: size_t num_attempts :: Number of attempts allowed
 *
 * Returns the best height reached
 */
typedef int (*climber_f)(hills_f hills, hills_format_f hills_format, size_t num_attempts);


////////////////////////////////////
// FUNCTION DECLARATIONS
///////////////////////////////////

/*
 * test_hills
 * 
 * Tests a given hills function against a given climber
 * 
 * :: climber_f climber :: The climber to test
 * :: hills_f hills :: The hills to test against
 * :: hills_format_f format :: The hills format string
 * :: size_t num_attempts :: The number of permitted attempts
 *
 * Returns the best height achieved
 */
int test_hills(
    climber_f climber,
    hills_f hills,
    hills_format_f format,
    size_t num_attempts);



/*
 * result_printer
 * 
 * Prints the results of a test
 * 
 * :: char* test_name :: The name of the test that was run
 * :: int result :: The result of the test
 * 
 * Nothing returned, prints to standard output
 */
void result_printer(char* test_name, int result);

#endif