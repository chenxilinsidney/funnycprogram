/**
 * @file find_subarray_max_multipulation_by_math.c
 * @brief find the subarray the max multipulation using math method.
 * the subarray with length n - 1 from input array with length n.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-02-01
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int ElementType;    ///< element data type
typedef int CommonType;     ///< common data type

#define MAX_COUNT      10000000
ElementType array[MAX_COUNT] = {0};

/**
 * @brief find the subarray the max multipulation using math method.
 * the subarray with length n - 1 from input array with length n.
 *
 * @param[in,out]  array  array
 * @param[in]      count  array length
 *
 * @return the max multipulation
 */
ElementType find_subarray_max_multipulation(ElementType* array,
        CommonType count)
{
    assert(array != NULL && count > 1);
    CommonType i, flag_exclude = 0;
    CommonType positive_count = 0, negative_count = 0, zero_count = 0;
    ElementType max_mutipulation = 1;
    ElementType min_positive = INT_MAX, max_negative = INT_MIN;
    /// search needed math information from the array
    for (i = 0; i < count; i++) {
        /// count the positive, negative, zero value numbers
        /// get the minimum positive value and maximum negative value
        if (array[i] > 0) {
            positive_count++;
            if (min_positive > array[i])
                min_positive = array[i];
        } else if (array[i] < 0) {
            negative_count++;
            if (max_negative < array[i])
                max_negative = array[i];
        } else {
            zero_count++;
        }
    }
    /// get max multipulation by math analysis
    if (zero_count > 0) {
        if (zero_count > 1 || (negative_count & 0x01)) {
            max_mutipulation = 0;
        } else {
            /// exclude 0 element
            for (i = 0; i < count; i++) {
                if (array[i])
                    max_mutipulation *= array[i];
            }
        }
    } else if (negative_count & 0x01) {
        /// exclude a maximum negative element
        for (i = 0; i < count; i++) {
            if (array[i] == max_negative && !flag_exclude) {
                flag_exclude = 1;
                continue;
            }
            max_mutipulation *= array[i];
        }
    } else {
        /// exclude a minimum positive element
        for (i = 0; i < count; i++) {
            if (array[i] == min_positive && !flag_exclude) {
                flag_exclude = 1;
                continue;
            }
            max_mutipulation *= array[i];
        }
    }
    return max_mutipulation;
}

int main(void) {
    /// read data to array
    CommonType count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// find max subarray
    ElementType multipulation = find_subarray_max_multipulation(array, count);
    /// output result
    printf("max multipulation is %d.\n", multipulation);
    return EXIT_SUCCESS;
}
