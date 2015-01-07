/**
 * @file sort_by_cocktail.c
 * @brief sort sequence by cocktail sort method.
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

void cocktail_sort(TYPE* array, TYPE count)
{
    TYPE i;
    TYPE flag_repeat = 1;
    TYPE begin = 0;
    TYPE end = count - 1;
    /// repeated until no swaps
    while (flag_repeat) {
        /// from begin to end
        flag_repeat = 0;
        for (i = begin; i < end; i++) {
            /// compares adjacent items and swaps them if in wrong order.
            if (array[i] > array[i + 1]) {
                TYPE temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                flag_repeat = i;
            }
        }
        /// out of loop if no swap
        if (flag_repeat == 0)
            break;
        /// new end for comparison
        end = flag_repeat;
        /// from end to begin
        flag_repeat = 0;
        for (i = end; i > begin; i--) {
            /// compares adjacent items and swaps them if in wrong order.
            if (array[i] < array[i - 1]) {
                TYPE temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                flag_repeat = i;
            }
        }
        /// new begin for comparison
        begin = flag_repeat;
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
    cocktail_sort(array, count);
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
