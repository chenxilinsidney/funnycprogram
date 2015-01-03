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
    // directly cacluating
    TYPE j;
    TYPE index_left, index_right;
    TYPE diff_max = INT_MIN;
    for(i = 0; i < count - 1; i++) {
        temp = array[i];
        for(j = i + 1; j < count; j++) {
            if((temp += array[j]) > diff_max) {
                diff_max = temp;
                index_left = i;
                index_right = j + 1;
            }
        }
    }
    // output result
    printf("max different value = %d\n", diff_max);
    printf("index in array: %d to %d\n", index_left, index_right);
    return EXIT_SUCCESS;
}
