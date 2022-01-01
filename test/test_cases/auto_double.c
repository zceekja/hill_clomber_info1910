#include <stdio.h>
#include "test.h"
#include "climber.h"
#include "hills_double.h"

/*
 * test_quadratic
 *
 * Tests a climber against the quadratic hills
 *
 * Returns the best height achieved
 */


int main()
{

    // Quadratic Test
    int result = test_hills(
    climber,
    hills_double,
    hills_double_format,
    NUM_ATTEMPTS_HILLS_DOUBLE);

    // Print Results
    if (result >= 0)
    {

        printf("Passed!\n");
    }
    else
    {
        printf("%d\n", result);
    }
    return 0;
};

