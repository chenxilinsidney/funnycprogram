/**
 * @file find_continue_numbers_formula.c
 * @brief find continue numbers that their sum are the input 64-bit value.
 * @author chenxilinsidney@gmail.com
 * @version 1.0
 * @date 2015-02-03
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// #define NDEBUG
#include <assert.h>

#define NDBG_PRINT
#include "debug_print.h"

typedef unsigned long TYPE;

#define MAX_COUNT      10000000
TYPE array[MAX_COUNT] = {0};

/**
 * @brief find continue numbers that their sum are the input value.
 *
 *
 * @param[in]     sum    the sum of the continue numbers
 * @param[out]    array  array that save the first number value and
 * count one by one
 *
 * @return numbers of the solutions
 */
TYPE find_continue_numbers(TYPE sum, TYPE* array)
{
    assert(array != NULL && sum >= 1);
    TYPE count = 0;
    TYPE i, j;
    TYPE sum_temp;
    TYPE number_count_max = (TYPE)(-1 + sqrt(1 + (sum << 3))) >> 1;
    DEBUG_PRINT_VALUE("%lu", number_count_max);
    for (i = 1; i < sum; i++) {
        for (j = 0; j <= number_count_max; j++) {
            sum_temp = (((i << 1) + j - 1) * j) >> 1;
            DEBUG_PRINT_VALUE("%lu", sum_temp);
            if (sum_temp == sum) {
                array[count << 1] = i;
                array[(count << 1) + 1] = j;
                count++;
            } else if (sum_temp > sum) {
                break;
            }
        }
    }
    return count;
}

int main(void) {
    /// read sum
    TYPE sum = 0;
    printf("input the sum of the continue numbers:");
    if(scanf("%lu", &sum) != 1) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get the right value.\n");
        DEBUG_PRINT_VALUE("%lu", sum);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// output result
    TYPE i, j, count;
    if((count = find_continue_numbers(sum, array)) != 0) {
        printf("Solution count = %lu\n", count);
        for (i = 0; i < count; i++) {
            for (j = 0; j < array[(i << 1) + 1] - 1; j++) {
                printf("%lu + ", array[i << 1] + j);
            }
            printf("%lu = %lu\n", array[i << 1] + array[(i << 1) + 1] - 1, sum);
        }
    } else {
        printf("Can not get solutions.\n");
    }
    return EXIT_SUCCESS;
}
