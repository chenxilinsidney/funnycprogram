/**
 * @file find_subarray_max_multipulation_by_memory.c
 * @brief find the subarray the max multipulation using more memory space.
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

#include "memory.h"
// #define NDBG_PRINT
#include "debug_print.h"

typedef int ElementType;    ///< element data type
typedef int CommonType;     ///< common data type

#define MAX_COUNT      10000000
ElementType array[MAX_COUNT] = {0};

/**
 * @brief find the subarray the max multipulation using more memory space.
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
    CommonType i;
    ElementType temp, max_mutipulation = INT_MIN;
    /// memory space to save temp multipulation result
    ElementType* head_multiple = SMALLOC(count, ElementType);
    ElementType* tail_multiple = SMALLOC(count, ElementType);
    /// get head multipulation result
    head_multiple[0] = 1;
    for (i = 1; i < count; i++)
        head_multiple[i] = head_multiple[i - 1] * array[i - 1];
    /// get tail multipulation result
    tail_multiple[count - 1] = 1;
    for (i = count - 2; i >= 0; i--)
        tail_multiple[i] = tail_multiple[i + 1] * array[i + 1];
    /// get max multipulation result
    for (i = 0; i < count; i++) {
        if ((temp = head_multiple[i] * tail_multiple[i]) > max_mutipulation)
            max_mutipulation = temp;
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
