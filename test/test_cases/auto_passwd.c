#include <stdio.h>
#include "test.h"
#include "climber.h"
#include "hills_passwd.h"

/*
 * test_passwd
 *
 * Tests a climber against the password hills
 *
 */


int main()
{

    // Quadratic Test
    int result = test_hills(
    climber,
    hills_passwd,
    hills_passwd_format,
    NUM_ATTEMPTS_HILLS_PASSWD);

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

