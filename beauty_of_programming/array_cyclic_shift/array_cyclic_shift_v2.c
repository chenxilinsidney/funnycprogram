/**
 * @file array_cyclic_shift_v2.c
 * @brief an operation for an array of cyclic shift.
 * with time O(N) limit and only two additional variables.
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
 * @brief reverse an array from index_begin to index_end
 *
 * @param[in,out]  array       array to be reversed
 * @param[in]      index_begin index begin of the array(included)
 * @param[in]      index_end   index end of the array(included)
 */
void reverse(TYPE* array, TYPE index_begin, TYPE index_end)
{
    TYPE temp;
    /// swap between top index value and bottom index value
    for (; index_begin < index_end; index_begin++, index_end--) {
        temp = array[index_begin];
        array[index_begin] = array[index_end];
        array[index_end] = temp;
    }
}
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
    /// reverse the first (count - right_shift) elements
    reverse(array, 0, count - right_shift - 1);
    /// reverse the remain elements
    reverse(array, count - right_shift, count - 1);
    /// reverse all the elements
    reverse(array, 0, count - 1);
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
    for (j = 0; j < count; j++) {
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
