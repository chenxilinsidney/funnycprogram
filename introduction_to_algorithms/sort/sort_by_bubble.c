/**
 * @file sort_by_bubble.c
 * @brief sort sequence by bubble sort method.
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

void bubble_sort(TYPE* array, TYPE count)
{
    TYPE i;
    TYPE flag_repeat = 1;
    TYPE current_count = count - 1;
    /// repeated until no swaps
    while (flag_repeat) {
        flag_repeat = 0;
        for (i = 0; i < current_count; i++) {
            /// compares adjacent items and swaps them if in wrong order.
            if (array[i] > array[i + 1]) {
                TYPE temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                flag_repeat = i;
            }
        }
        /// new count for comparison
        current_count = flag_repeat;
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
    bubble_sort(array, count);
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
