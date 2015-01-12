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
    assert(max_first != NULL && max_second != NULL && count >= 1);
    /// initialize max_first and second max_second value
    *max_first = INT_MIN + 1;
    *max_second = INT_MIN;
    TYPE i;
    for (i = 0; i < count - 1; i += 2) {
        /// compare between odd and even position value for N/2 times(N=count).
        TYPE a, b, temp;
        if (array[i] == array[i + 1]) {
            a = array[i];
            if (a != *max_first) {
                if (*max_first < a) {
                    *max_second = *max_first;
                    *max_first = a;
                } else {
                    *max_second = *max_second > a ? *max_second : a;
                }
            }
        } else {
            if (array[i] > array[i + 1]) {
                a = array[i];
                b = array[i + 1];
            } else if (array[i] < array[i + 1]) {
                a = array[i + 1];
                b = array[i];
            }
            if (a != *max_first) {
                temp = *max_first;
                *max_first = *max_first > a ? *max_first : a;
                if (*max_first == a) 
                    *max_second = temp > b ? temp : b;
                else
                    *max_second = *max_second > a ? *max_second : a;
            } else {
                *max_second = *max_second > b ? *max_second : b;
            }
        }
        // DEBUG_PRINT_VALUE("%d", *max_first);
        // DEBUG_PRINT_VALUE("%d", *max_second);
        // DEBUG_PRINT_VALUE("%d", i);
    }
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
