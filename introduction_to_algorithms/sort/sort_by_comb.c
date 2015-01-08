/**
 * @file sort_by_comb.c
 * @brief sort sequence by comb sort method.
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

#define MAX_COUNT      100000
TYPE array[MAX_COUNT] = {0};

void comb_sort(TYPE* array, TYPE count)
{
    TYPE i;
    TYPE flag_repeat = 1;
    /// initialize gap size
    TYPE gap = count;
    /// set gap shrink factor
    double shrink = 1.3;
    /// repeated until no swaps
    while (gap != 1 || flag_repeat) {
        /// update gap from shrink
        if (gap > 1)  ///< minimum gap = 1
            gap /= shrink;
        flag_repeat = 0;
        for (i = 0; i < count - gap; i++) {
            /// compares 'comb' items and swaps them if in wrong order.
            if (array[i] > array[i + gap]) {
                TYPE temp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = temp;
                flag_repeat = 1;
            }
        }
    }
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
    comb_sort(array, count);
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
