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
 * @param[out]     count  three elements value that repeats max times
 * (times > 1 / 4 total)
 */
void find_id(TYPE* array, TYPE count, TYPE* candidate)
{
    TYPE i;
#define ELEMENT_COUNT 3
    /// iniitialize
    TYPE nTimes[ELEMENT_COUNT] = {0};
    candidate[0] = 0;
    candidate[1] = 0;
    candidate[2] = 0;
    for (i = 0; i < count; i++) {
        if (candidate[0] == array[i]) {
            nTimes[0]++;
        } else if (candidate[1] == array[i]) {
            nTimes[1]++;
        } else if (candidate[2] == array[i]) {
            nTimes[2]++;
        } else if (nTimes[0] == 0) {
            nTimes[0] = 1;
            candidate[0] = array[i];
        } else if (nTimes[1] == 0) {
            nTimes[1] = 1;
            candidate[1] = array[i];
        } else if (nTimes[2] == 0) {
            nTimes[2] = 1;
            candidate[2] = array[i];
        } else {
            nTimes[0]--;
            nTimes[1]--;
            nTimes[2]--;
        }
    }
#undef ELEMENT_COUNT
    return;
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// find id
    TYPE id[3] = {0};
    find_id(array, count, id);
    /// output result
    printf("max repeat count element is %d %d %d.\n", id[0], id[1], id[2]);
    return EXIT_SUCCESS;
}
