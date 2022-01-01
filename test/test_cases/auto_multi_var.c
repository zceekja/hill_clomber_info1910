#include <stdio.h>
#include "test.h"
#include "climber.h"
#include "hills_multi_var.h"

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
    hills_multi_var,
    hills_multi_var_format,
    NUM_ATTEMPTS_HILLS_MULTI_VAR);

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

