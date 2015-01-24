/**
 * @file binary_search_larger_than.c
 * @brief search for data in an array by binary search method
 * by deferred detection of equality
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
 * @brief get the largest index of the value in the array
 * that larger than the given value
 *
 * @param[in]      array  input array
 * @param[in]      count  input array length
 * @param[in]      value  search value
 *
 * @warning array index begin from 0
 *
 * @return index if success, else return -1
 */
TYPE binary_search_larger(TYPE* array, TYPE count, TYPE value)
{
    assert(array != NULL && count >= 0);
    TYPE middle, index_begin = 0, index_end = count - 1;
    while (index_begin < index_end) {
        middle = index_begin + ((unsigned)(index_end - index_begin + 1) >> 1);
        if (array[middle] > value)
            index_end = middle - 1;
        else
            index_begin = middle;
    }
    if (index_end == index_begin && array[index_begin] == value &&
            index_begin != count - 1)
        return index_begin + 1;
    else
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
    if ((index = binary_search_larger(array, count, value)) >= 0) {
        printf("search element index is %d\n", index);
    } else {
        printf("can not found element: %d\n", value);
    }
    return EXIT_SUCCESS;
}
