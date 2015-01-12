/**
 * @file search_max_and_min_value_v2.c
 * @brief search the maximum and minimum value in the sequence.
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
 * @brief swap value a and value b by thrid value
 *
 * @param[in]      p_a   value a's address
 * @param[in]      p_b   value b's address
 */
static void swap(TYPE* p_a, TYPE* p_b)
{
    TYPE temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;
    return;
}
/**
 * @brief search the maximum and minimum value in the array
 *
 * @param[in]      array  sequence for search
 * @param[in]      count  sequence length
 * @param[out]     max    maximum value from the sequence
 * @param[out]     min    minimum value from the sequence
 */
void search_max_and_min_value(TYPE* array, TYPE count, TYPE* max, TYPE* min)
{
    assert(max != NULL && min != NULL && count >= 1);
    /// initialize max and min value
    *max = INT_MIN;
    *min = INT_MAX;
    TYPE i;
    for (i = 0; i < count - 1; i += 2) {
        /// compare between odd and even position value for N/2 times(N=count).
        if (array[i] <= array[i + 1])
            /// save large value to even position, small value to odd position.
            swap(array + i, array + i + 1);
        /// compare in even position value to get max value for N/2 times.
        if (array[i] >= *max)
            /// save maximum value
            *max = array[i];
        /// compare in odd position value to get min value for N/2 times.
        if (array[i + 1] <= *min)
            /// save minimum value
            *min = array[i + 1];
    }
    /// should not forget the last value if N is an odd number.
    if ((count & 0x1) == 1) {
        /// compare last value with max and min value for 2 times.
        if (array[count - 1] >= *max)
            *max = array[count - 1];
        if (array[count - 1] <= *min)
            *min = array[count - 1];
    }
    /// totally compare 1.5N times(N = count).swap times no more than N/2
    return;
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// search maximum and minimum value
    TYPE max = 0;
    TYPE min = 0;
    search_max_and_min_value(array, count, &max, &min);
    /// output result
    printf("max element is %d\n", max);
    printf("min element is %d\n", min);
    return EXIT_SUCCESS;
}
