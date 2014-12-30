/**
 * @file generate_random_data.c
 * @brief generate random data:generate different numbers by line to
 * random_data.txt.
 * your should input the max value and generate counts.
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
    TYPE index, k;
    /// get max value
    /// to use "%" operater with rand(), max value should less than RAND_MAX
    printf("MAX VALUE of the random number: %u\n", (unsigned)RAND_MAX - 1);
    printf("Please input the max value(excluded) of the random number: ");
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
    printf("Please input the count of the random number: ");
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
    /// generate random number
    TYPE* list = SMALLOC(random_number, TYPE);
    srand(time(NULL));
    printf("start generating random numbers...........\n");
    for(index = 0; index < random_number; index++) {
        TYPE flag = 1;
        while(flag) {
            list[index] = rand() % max_value;
            flag = 0;
            for(k = 0; k < index; k++) {
                if(list[k] == list[index]) {
                    flag = 1;
                    break;
                }
            }
        }
    }
    /// write data to file
    FILE* fp = fopen("random_data.txt", "w");
    if(fp == NULL) {
        perror("random_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    for(index = 0; index < random_number; index++) {
        fprintf(fp, "%u\n", list[index]);
    }
    if(fclose(fp) != 0) {
        perror("random_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    printf("random numbers saved to random_data.txt!\n");
    /// free memory
    SFREE(&list);
    /// return
    return EXIT_SUCCESS;
}
