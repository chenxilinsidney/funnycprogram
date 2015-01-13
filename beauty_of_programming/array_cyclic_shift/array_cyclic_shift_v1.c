/**
 * @file array_cyclic_shift_v1.c
 * @brief an operation for an array of cyclic shift.
 * with time O(N^2) limit and only two additional variables.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-13
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define MAX_COUNT      10000000
TYPE array[MAX_COUNT] = {0};

/**
 * @brief cyclic shift for an array
 *
 * @param[in,out]  array   shift array
 * @param[in]      count   array length
 * @param[in]      right_shift  right shift count
 */
void array_cyclic_shift(TYPE* array, TYPE count, TYPE right_shift)
{
    assert(array != NULL && right_shift >= 0 && count >= 1);
    /// let right shift smaller than count
    right_shift %= count;
    TYPE i, temp;
    /// shift right_shift times
    while (right_shift--) {
        /// save top value to buffer
        temp = array[count - 1];
        /// set higher value by lower value
        for (i = count - 1; i > 0; i--)
            array[i] = array[i - 1];
        /// set bottom value from buffer
        array[0] = temp;
    }
    return;
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%d\n", array + count) == 1) {
        ++count;
    }
    /// test for all shift
    TYPE j;
    for (j = 1; j < count; j++) {
        array_cyclic_shift(array, count, j);
        if (array[j] != 1) {
            DEBUG_PRINT_VALUE("%d", j);
            DEBUG_PRINT_STRING("get wrong array by shift.\n");
        }
        array_cyclic_shift(array, count, count - j);
    }
    /// output result
    TYPE i;
    for(i = 0; i < count; i++) {
        printf("%d\n", array[i]);
    }
    return EXIT_SUCCESS;
}
