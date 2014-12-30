/**
 * @file sort_by_bitmap_structure.c
 * @brief sort a list of random data by standard library.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-30
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
// #define NDEBUG
#include <assert.h>

#include "memory.h"
#include "type.h"
// #define NDBG_PRINT
#include "debug_print.h"

typedef uint32 TYPE;
#define MAX_VALUE      10000000
uint32 list[MAX_VALUE] = {0};

/**
 * @brief this function is used to compare a and b used by qsort function.
 *
 * @param[in]      a   first data
 * @param[in]      b   second data
 *
 * @return >1 if a > b, =0 if a == b, <0 if a < b
 */
int list_compare(void const* a, void const* b)
{
    TYPE first = *(TYPE*)a;
    TYPE second = *(TYPE*)b;
    if(first > second)
        return 1;
    else if(first == second)
        return 0;
    else
        return -1;
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
    /// read data to list
    TYPE count = 0;
    while(fscanf(fr, "%u\n", list + count) == 1) {
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
    /// sort data by standard library
    qsort(list, count, sizeof(TYPE), list_compare);
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
        fprintf(fw, "%u\n", list[i]);
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
