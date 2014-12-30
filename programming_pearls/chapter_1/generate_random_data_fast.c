/**
 * @file generate_random_data.c
 * @brief generate random data:generate different numbers by line to
 * random_data.txt.
 * your should input the max value(excluded) and generate counts.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-29
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "memory.h"
// #define NDEBUG
#include <assert.h>
// #define NDBG_PRINT
#include "debug_print.h"

typedef unsigned int TYPE;

int main(void) {
    TYPE max_value = 0;
    TYPE random_number = 0;
    TYPE index;
    /// get max value
    /// to use "%" operater with rand(), max value should less than RAND_MAX
    if(scanf("%u", &max_value) != 1) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get the right max value(excluded).\n");
        DEBUG_PRINT_VALUE("%u", max_value);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    } else if(max_value > (RAND_MAX - 1)) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("value exceeds the limit max value.\n");
        DEBUG_PRINT_VALUE("%u", max_value);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// get count
    if(scanf("%u", &random_number) != 1) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get the right count.\n");
        DEBUG_PRINT_VALUE("%u", random_number);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    } else if(random_number > max_value) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("count exceeds the max value.\n");
        DEBUG_PRINT_VALUE("%u", max_value);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// initialize number
    TYPE* list = SMALLOC(max_value, TYPE);
    for(index = 0; index < max_value; index++) {
        list[index] = index;
    }
    /// generate random number
    TYPE index_from, index_to;
    srand(time(NULL));
    for(index = 0; index < max_value; index++) {
        index_from = rand() % max_value;
        index_to = rand() % max_value;
        while(index_from == index_to) {
            index_to = rand() % max_value;
        }
        TYPE temp = list[index_to];
        list[index_to] = list[index_from];
        list[index_from] = temp;
    }
    /// write data to stdout
    for(index = 0; index < random_number; index++) {
        printf("%u\n", list[index]);
    }
    /// free memory
    SFREE(&list);
    /// return
    return EXIT_SUCCESS;
}
