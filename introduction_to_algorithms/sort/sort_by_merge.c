/**
 * @file sort_by_merge.c
 * @brief sort sequence by merge sort method.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-07
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #define NDEBUG
#include <assert.h>

#include "memory.h"
// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define MAX_COUNT      10000000
TYPE array1[MAX_COUNT] = {0};
TYPE array2[MAX_COUNT] = {0};

/**
 * @brief merge two sorted array from array1 to array2
 *
 * @param[in]      array1 input array, where array[index_begin] to
 * array[index_middle] are sorted and array1[index_middle+1] to
 * array[index_end] are sorted too.
 * @param[out]     array2 sorted array from array[index_begin] to
 * array[index_end]
 * @param[in]      index_begin    array begin index
 * @param[in]      index_middle   array middle index
 * @param[in]      index_end      array end index
 */
void merge(TYPE* array1,
        TYPE* array2,
        TYPE index_begin,
        TYPE index_middle,
        TYPE index_end)
{
    assert(index_begin <= index_middle && index_middle < index_end);
    TYPE i;
    TYPE i_left = index_begin;
    TYPE i_right = index_middle + 1;
    for (i = index_begin; i <= index_end; i++) {
        if (i_left <= index_middle &&
                (i_right > index_end || array1[i_left] <= array1[i_right])) {
            array2[i] = array1[i_left];
            i_left++;
        } else {
            array2[i] = array1[i_right];
            i_right++;
        }
    }
}

void merge_sort_split(TYPE* array1,
        TYPE* array2,
        TYPE index_begin,
        TYPE index_end)
{
    assert(index_begin <= index_end);
    if (index_end == index_begin)
        return;
    TYPE index_middle = (unsigned)(index_end + index_begin) >> 1;
    merge_sort_split(array1, array2, index_begin, index_middle);
    merge_sort_split(array1, array2, index_middle + 1, index_end);
    merge(array1, array2, index_begin, index_middle, index_end);
    memcpy(array1 + index_begin, array2 + index_begin,
            sizeof(array1[0]) * (index_end - index_begin + 1));
}

void merge_sort(TYPE* array, TYPE count)
{
    memcpy(array2, array1, count * sizeof(array1[0]));
    merge_sort_split(array1, array2, 0, count - 1);
}

int main(void) {
    /// read data from file
    FILE* fr = fopen("random_data.txt", "r");
    if(fr == NULL) {
        perror("random_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && fscanf(fr, "%u\n", array1 + count) == 1) {
        ++count;
    }
    /// close read data file
    if(fclose(fr) != 0) {
        perror("random_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// sort data
    merge_sort(array1, count);
    /// set write data file
    FILE* fw = fopen("sorted_data.txt","w");
    if(fw == NULL) {
        perror("sorted_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// write sorted data to file
    TYPE i;
    for(i = 0; i < count; i++) {
        fprintf(fw, "%u\n", array1[i]);
    }
    /// close write data file
    if(fclose(fw) != 0) {
        perror("sorted_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
