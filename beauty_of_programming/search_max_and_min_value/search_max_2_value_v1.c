/**
 * @file search_max_2_value_v1.c
 * @brief search the second maximum value in the sequence.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-12
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define MAX_COUNT      10000000
TYPE array[MAX_COUNT] = {0};

/**
 * @brief search the maximum and minimum value in the array
 *
 * @param[in]      array  sequence for search
 * @param[in]      count  sequence length
 * @param[out]     max_first    maximum value from the sequence
 * @param[out]     max_second   second maximum value from the sequence
 */
void search_max_2_value(TYPE* array, TYPE count,
        TYPE* max_first, TYPE* max_second)
{
    assert(array != NULL && max_first != NULL && max_second != NULL &&
            count >= 1);
    TYPE i;
    /// initialize max_first and max_second value
    if ((count & 0x1) == 1) {
        /// if N is an odd number.
        /// set max_first and max_second value as first element
        *max_first = array[0];
        *max_second = INT_MIN;
        i = 1;
    } else {
        /// if N is an even number.
        /// compare first two element,set max_first and max_second value 1 times
        if (array[0] > array[1]) {
            *max_first = array[0];
            *max_second = array[1];
        } else {
            *max_first = array[1];
            *max_second = array[0];
        }
        i = 2;
    }
    /// if N is odd, each compare times=[N/2], else each compare times=[(N-2)/2]
    for ( ; i < count - 1; i += 2) {
        /// compare odd with even position value.
        if (array[i] > array[i + 1]) {
            if (array[i] > *max_first) {
                /// update max_second value
                if (array[i + 1] > *max_first)
                    *max_second = array[i + 1];
                else
                    *max_second = *max_first;
                /// update max_first value
                *max_first = array[i];
            } else {
                /// update max_second value
                if (array[i] > *max_second)
                    *max_second = array[i];
            }
        } else {
            if (array[i + 1] > *max_first) {
                /// update max_second value
                if (array[i] > *max_first)
                    *max_second = array[i];
                else
                    *max_second = *max_first;
                /// update max_first value
                *max_first = array[i + 1];
            } else {
                /// update max_second value
                if (array[i + 1] > *max_second)
                    *max_second = array[i + 1];
            }
        }
    }
    return;
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// search maximum and minimum value
    TYPE max_first = 0;
    TYPE max_second = 0;
    search_max_2_value(array, count, &max_first, &max_second);
    /// output result
    printf("max_first element is %d\n", max_first);
    printf("max_second element is %d\n", max_second);
    return EXIT_SUCCESS;
}
