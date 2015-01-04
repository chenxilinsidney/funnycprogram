/**
 * @file subarray_directly_calculating.c
 * @brief directly cacluating the max subarray.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-03
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
 * @brief get the max subarray when cross the middle point of the array
 *
 * @param[in]      array
 * @param[in]      index_begin
 * @param[in]      index_end
 *
 * @return subarray
 */
struct subarray find_max_crossing_subarray(TYPE* array,
        TYPE index_begin,
        TYPE index_end)
{
    // should have special input value
    assert(index_begin < index_end);
    // get middle index
    TYPE index_middle = (unsigned)(index_begin + index_end) >> 1;
    struct subarray return_subarray;
    TYPE i;
    TYPE sum_temp = INT_MIN;
    TYPE sum = 0;
    for(i = index_middle; i >= index_begin; i--) {
        sum += array[i];
        if(sum > sum_temp) {
            return_subarray.index_begin = i;
            sum_temp = sum;
        }
    }
    return_subarray.sum_max = sum_temp;
    sum = 0;
    sum_temp = INT_MIN;
    for(i = index_middle + 1; i <= index_end; i++) {
        sum += array[i];
        if(sum > sum_temp) {
            return_subarray.index_end = i;
            sum_temp = sum;
        }
    }
    return_subarray.sum_max += sum_temp;
    return return_subarray;
}

/**
 * @brief find maximum subarray by divide and conquer method.
 *
 * @param TYPE
 * @param index_begin
 * @param index_end
 */
struct subarray find_maximum_subarray(TYPE* array,
        TYPE index_begin,
        TYPE index_end)
{
    DEBUG_PRINT_STRING("In recursion now.\n");
    DEBUG_PRINT_VALUE("%d", index_begin);
    DEBUG_PRINT_VALUE("%d", index_end);
    assert(index_begin <= index_end);
    if(index_begin == index_end) {
        struct subarray return_subarray = {index_begin,
            index_end,
            array[index_begin]};
        DEBUG_PRINT_VALUE("%d", return_subarray.sum_max);
        DEBUG_PRINT_VALUE("%d", return_subarray.index_begin);
        DEBUG_PRINT_VALUE("%d", return_subarray.index_end);
        DEBUG_PRINT_VALUE("%d", index_begin);
        DEBUG_PRINT_VALUE("%d", index_end);
        DEBUG_PRINT_STRING("Out recursion now.\n");
        return return_subarray;
    } else {
        TYPE index_middle = (unsigned)(index_begin + index_end) >> 1;
        struct subarray data_left =
            find_maximum_subarray(array, index_begin, index_middle);
        struct subarray data_right =
            find_maximum_subarray(array, index_middle + 1, index_end);
        struct subarray data_cross =
            find_max_crossing_subarray(array, index_begin, index_end);
        if(data_left.sum_max >= data_right.sum_max &&
                data_left.sum_max >= data_cross.sum_max) {
            DEBUG_PRINT_VALUE("%d", data_left.sum_max);
            DEBUG_PRINT_VALUE("%d", data_left.index_begin);
            DEBUG_PRINT_VALUE("%d", data_left.index_end);
            DEBUG_PRINT_VALUE("%d", index_begin);
            DEBUG_PRINT_VALUE("%d", index_end);
            DEBUG_PRINT_STRING("Out recursion now.\n");
            return data_left;
        } else if(data_right.sum_max >= data_left.sum_max &&
                data_right.sum_max >= data_cross.sum_max) {
            DEBUG_PRINT_VALUE("%d", data_right.sum_max);
            DEBUG_PRINT_VALUE("%d", data_right.index_begin);
            DEBUG_PRINT_VALUE("%d", data_right.index_end);
            DEBUG_PRINT_VALUE("%d", index_begin);
            DEBUG_PRINT_VALUE("%d", index_end);
            DEBUG_PRINT_STRING("Out recursion now.\n");
            return data_right;
        } else {
            DEBUG_PRINT_VALUE("%d", data_cross.sum_max);
            DEBUG_PRINT_VALUE("%d", data_cross.index_begin);
            DEBUG_PRINT_VALUE("%d", data_cross.index_end);
            DEBUG_PRINT_VALUE("%d", index_begin);
            DEBUG_PRINT_VALUE("%d", index_end);
            DEBUG_PRINT_STRING("Out recursion now.\n");
            return data_cross;
        }
    }
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
    // get differenct value
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
    // divide and conquer method
    struct subarray data_final;
    data_final = find_maximum_subarray(array, 0, count - 1);
    // output result
    printf("max different value = %d\n", data_final.sum_max);
    printf("index in array: %d to %d\n", data_final.index_begin,
            data_final.index_end + 1);
    return EXIT_SUCCESS;
}
