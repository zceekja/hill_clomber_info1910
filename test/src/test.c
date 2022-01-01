#include "test.h"

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
    size_t num_attempts)
{
    // Call the climber on the hills function
    int reported = climber(hills, format, num_attempts);

    // Check what the hills function says about the result
    int result = hills(NULL);

    if (reported != result) // Someone is trying to cheat!
    {
        return -1;
    }

    return result;
}

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
void result_printer(char* test_name, int result)
{
    printf("  %s\n", test_name);
    if (result > 0)
    {
        printf("\tPassed\t:\t%d\n", result);
    }
    else
    {
        printf("\tFailed\t:\t%d\n", result);
    }
    printf("\n");
}