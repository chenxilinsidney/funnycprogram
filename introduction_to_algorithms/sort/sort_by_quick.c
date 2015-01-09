/**
 * @file sort_by_quick.c
 * @brief sort sequence by quicksort method.
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

/**
 * @brief select the last element as a pivoit.
 * Reorder the array so that all elements with values less than the pivot
 * come before the pivot, while all elements with values greater than the pivot
 * come after it (equal values can go either way). After this partitioning, the
 * pivot is in its final position. 
 *
 * @param[in,out]  array          input and output array
 * @param[in]      index_begin    the begin index of the array(included)
 * @param[in]      index_end      the end index of the array(included)
 *
 * @return the position of the pivot(index from the array)
 */
TYPE partition(TYPE* array, TYPE index_begin, TYPE index_end)
{
    /// select last element of the array as pivot
    TYPE pivot = array[index_end];
    /// index of the elments that not greater than pivot
    TYPE i = index_begin - 1;
    TYPE j;
    /// check array's elment one by one
    for (j = index_begin; j < index_end; j++) {
        if (array[j] <= pivot) {
            /// save the elements not greater than pivot to left index of i.
            i++;
            TYPE temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    /// set the pivot to the right position
    array[index_end] = array[++i];
    array[i] = pivot;
    /// return the position of the pivot
    return i;
}

void quick_sort(TYPE* array, TYPE index_begin, TYPE index_end)
{
    /// sort only under the index_begin < index_end condition
    if ( index_begin < index_end) {
        /// exchange elements to the pivot position by partition function
        TYPE index_pivot = partition(array, index_begin, index_end);
        /// sort the array before the pivot position
        quick_sort(array, index_begin, index_pivot - 1);
        /// sort the array after the pivot position
        quick_sort(array, index_pivot + 1, index_end);
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
    quick_sort(array, 0, count - 1);
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
