/**
 * @file directly_calculating.c
 * @brief directly cacluating the max money.
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
    TYPE i;
    for(i = 0; i < count; i++) {
        if(scanf("%d\n", array + i) != 1) {
            DEBUG_PRINT_STATE;
            DEBUG_PRINT_STRING("can not get data.\n");
            DEBUG_PRINT_VALUE("%d", i);
            DEBUG_PRINT_VALUE("%d", array[i]);
            fflush(stdout);
            assert(0);
            exit(EXIT_FAILURE);
        }
    }
    // directly cacluating
    TYPE j;
    TYPE index_left, index_right, temp;
    TYPE diff_max = INT_MIN;
    for(i = 0; i < count - 1; i++) {
        for(j = i + 1; j < count; j++) {
            if((temp = array[j] - array[i]) > diff_max) {
                diff_max = temp;
                index_left = i;
                index_right = j;
            }
        }
    }
    // output result
    printf("max different value = %d\n", diff_max);
    printf("index in array: %d to %d\n", index_left, index_right);
    SFREE(&array);
    return EXIT_SUCCESS;
}
