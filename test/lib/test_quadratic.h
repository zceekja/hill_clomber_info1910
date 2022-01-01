#ifndef TEST_QUADRATIC
#define TEST_QUADRATIC

#include <stddef.h>

#include "test.h"
#include "hills_quadratic.h"

/*
 * test_quadratic
 * 
 * Tests a climber against the quadratic hills 
 *
 * :: int (*climber)(
    int (*hills)(const void*),
    char* (*hills_format)(),
    size_t num_attempts) :: Function pointer to our intrepid climber
 *
 * Returns the best height achieved
 */
int test_quadratic(int (*climber)(
    int (*hills)(const void*),
    char* (*hills_format)(),
    size_t num_attempts));

#endif