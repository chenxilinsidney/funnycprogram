/**
 * @file sort_by_merge.c
 * @brief sort sequence by merge sort method.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-07
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

void merge_sort(TYPE* array, TYPE index_middle, TYPE index_end)
{
}

void merge_sort(TYPE* array, TYPE count)
{
    if (count == 1)
        return;
    TYPE middle = (unsigned)count >> 1;
    merge_sort(array, middle);
    merge_sort(array + middle, count - middle);
    merge(array, middle, count);
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
    while(count < MAX_COUNT && fscanf(fr, "%u\n", array + count) == 1) {
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
    merge_sort(array, count);
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
        fprintf(fw, "%u\n", array[i]);
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
