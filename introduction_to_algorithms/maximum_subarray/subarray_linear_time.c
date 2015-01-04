/**
 * @file subarray_linear_time.c
 * @brief cacluating the max subarray in linear time.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-04
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NDEBUG
#include <assert.h>

#include "memory.h"
#define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

/// used for save data
struct subarray {
    TYPE index_begin;  ///< index begin from an array when get max sum
    TYPE index_end;    ///< index end from an array when get max sum
    TYPE sum_max;      ///< max sum of the subarray
};

/**
 * @brief find maximum subarray in linear time.
 *
 * @param TYPE
 * @param index_begin
 * @param index_end
 */
struct subarray find_maximum_subarray(TYPE* array,
        TYPE index_begin,
        TYPE index_end)
{
    assert(index_begin <= index_end);
    struct subarray end_current;
    struct subarray all_current;
    struct subarray end_previous = {index_begin, index_begin,
        array[index_begin]};
    struct subarray all_previous = {index_begin, index_begin,
        array[index_begin]};
    TYPE i;
    for(i = index_begin + 1; i <= index_end; i++) {
        if(end_previous.sum_max < 0) {
            end_current.sum_max = array[i];
            end_current.index_begin = end_current.index_end = i;
        } else {
            end_current.sum_max = end_previous.sum_max + array[i];
            end_current.index_end++;
        }
        if(end_current.sum_max >= all_previous.sum_max) {
            all_current = end_current;
        } else {
            all_current = all_previous;
        }
        all_previous = all_current;
        end_previous = end_current;
    }
    return all_current;
}

int main(void) {
    // read data from stdin
    // read data count
    TYPE count = 0;
    if(scanf("%d\n", &count) != 1 && count <= 0) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get right data count.\n");
        DEBUG_PRINT_VALUE("%d", count);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    TYPE* array = SCALLOC(count, TYPE);
    // read data to array
    // get first value
    TYPE temp;
    if(scanf("%d\n", &temp) != 1) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get data.\n");
        DEBUG_PRINT_VALUE("%d", temp);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    // get difference value
    TYPE i;
    TYPE current;
    for(i = 0; i < count - 1; i++) {
        if(scanf("%d\n", &current) != 1) {
            DEBUG_PRINT_STATE;
            DEBUG_PRINT_STRING("can not get data.\n");
            DEBUG_PRINT_VALUE("%d", i);
            DEBUG_PRINT_VALUE("%d", current);
            fflush(stdout);
            assert(0);
            exit(EXIT_FAILURE);
        }
        array[i] = current - temp;
        temp = current;
        DEBUG_PRINT_VALUE("%d", i);
        DEBUG_PRINT_VALUE("%d", array[i]);
    }
    count--;
    // get result in linear time
    struct subarray data_final;
    data_final = find_maximum_subarray(array, 0, count - 1);
    // output result
    printf("max different value = %d\n", data_final.sum_max);
    printf("index in array: %d to %d\n", data_final.index_begin,
            data_final.index_end + 1);
    SFREE(&array);
    return EXIT_SUCCESS;
}
