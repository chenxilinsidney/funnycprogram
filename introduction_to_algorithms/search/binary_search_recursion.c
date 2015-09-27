/**
 * @file binary_search_recursion.c
 * @brief search for data in an array by binary search method
 * with recursion
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
 * @param[in]      index_begin begin index of input array
 * @param[in]      index_end   end index of input array
 * @param[in]      value  search value
 *
 * @warning array index begin from 0
 *
 * @return index if success, else return -1
 */
TYPE binary_search(TYPE* array, TYPE index_begin, TYPE index_end, TYPE value)
{
    assert(array != NULL && index_begin >= -1 && index_begin <= index_end + 1);
    if (index_begin > index_end)
        return -1;
    TYPE middle = index_begin + ((unsigned)(index_end - index_begin) >> 1);
    if (array[middle] < value)
        return binary_search(array, middle + 1, index_end, value);
    else if (array[middle] > value)
        return binary_search(array, index_begin, middle - 1, value);
    else
        return middle;
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
    if ((index = binary_search(array, 0, count - 1, value)) >= 0) {
        printf("search element index is %d\n", index);
    } else {
        printf("can not found element: %d\n", value);
    }
    return EXIT_SUCCESS;
}
