/**
 * @file sequence_search.c
 * @brief search for data in an array by sequence search method.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-20
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

#include "memory.h"
// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define MAX_COUNT      10000000
TYPE array[MAX_COUNT] = {0};

/**
 * @brief search the value in the array of the index
 *
 * @param[in]      array  input array
 * @param[in]      length  array length
 * @param[in]      value  search value
 *
 * @warning array index begin from 0
 *
 * @return index if success, else return -1
 */
TYPE sequence_search(TYPE* array, TYPE length, TYPE value)
{
    TYPE i;
    for (i = 0; i < length; i++)
        if (array[i] == value)
            return i;
    return -1;
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// search value
    TYPE value = 124366;
    /// output result
    TYPE index = -1;
    if ((index = sequence_search(array, count, value)) >= 0) {
        printf("search element index is %d\n", index);
    } else {
        printf("can not found element: %d\n", value);
    }
    return EXIT_SUCCESS;
}
