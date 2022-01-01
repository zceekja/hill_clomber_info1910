#include <stdio.h>
#include "test.h"
#include "climber.h"
#include "hills_blank_quad.h"

/*
 * test_quadratic
 *
 * Tests a climber against the quadratic hills
 *
 * Returns the best height achieved
 */


int main()
{

    // Quad two Test
    int result = test_hills(
    climber,
    hills_blank_quad,
    hills_blank_quad_format,
    NUM_ATTEMPTS_HILLS_BLANK_QUAD);

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

