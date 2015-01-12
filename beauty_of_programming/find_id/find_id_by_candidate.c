/**
 * @file find_id_by_candidate.c
 * @brief find the id which repeats most in the sequence.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-07
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
 * @brief find the element that repeats max times in the unsorted array
 *
 * @param[in,out]  array  unsorted array
 * @param[in]      count  array length
 *
 * @return the element value that repeats max times(times > 1 / 2 total)
 */
TYPE find_id(TYPE* array, TYPE count)
{
    TYPE i;
    TYPE candidate, nTimes = 0;
    for (i = 0; i < count; i++) {
        if (nTimes == 0) {
            candidate = array[i];
            nTimes = 1;
        } else {
            if (candidate == array[i])
                nTimes++;
            else
                nTimes--;
        }
    }
    return candidate;
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// find id
    TYPE id = find_id(array, count);
    /// output result
    printf("max repeat count element is %d.\n", id);
    return EXIT_SUCCESS;
}
