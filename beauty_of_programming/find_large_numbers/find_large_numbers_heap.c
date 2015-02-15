/**
 * @file find_large_numbers_heap.c
 * @brief find largest k numbers in a given array.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-02-04
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

#include "heap.h"
// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define MAX_COUNT      10000000
TYPE array[MAX_COUNT] = {0};

/**
 * @brief find the last index of the input array for largets N numbers.
 * the numbers that index in the array is before the last index is
 * the largest N numbers.
 *
 * @param[in,out]  array          input and output array
 * @param[in]      array_length   array length
 * @param[in]      count          the count of the largest numbers.
 */
void find_heap_sort(TYPE* array, TYPE array_length, TYPE count)
{
    assert(array != NULL && array_length > 0 && count > 0);
    /// array need not to adjust if count larger than or equal to array length
    if (count >= array_length)
        return;
    /// build heap with first count of the array
    Heap heap;
    BuildHeap(&heap, count, array - 1, count);
    /// adjust heap with other elements
    TYPE i, element;
    for (i = count; i < array_length; i++) {
        HeapGet(&heap, &element);
        if (array[i] > element) {
            heap.data[1] = array[i];
            Heapify(heap.data, 1, count);
        }
    }
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// find largest N numbers
    TYPE N = 15;
    TYPE i;
    find_heap_sort(array, count, N);
    printf("get the largest %d numbers:\n", N);
    for (i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    return EXIT_SUCCESS;
}
