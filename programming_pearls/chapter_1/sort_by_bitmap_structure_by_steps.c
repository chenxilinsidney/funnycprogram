/**
 * @file sort_by_bitmap_structure.c
 * @brief sort a list of random data quickly by bitmap structure in two steps.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-30
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

#include "memory.h"
#include "type.h"
// #define NDBG_PRINT
#include "debug_print.h"

typedef uint32 TYPE;
/// max random data value
#define MAX_VALUE      5000000
/// bitmap structure initialize to empty
#define BITMAP_BITS          32
#define BITMAP_SHIFT          5
#define BITMAP_MASK        0x1F
#define BITMAP_LENGTH ((unsigned)((MAX_VALUE)+(BITMAP_BITS)-1)>>(BITMAP_SHIFT))
TYPE bitmap_structure[BITMAP_LENGTH] = {0};
int main(void) {
    /// insert present elements into the set
    /// read data from file in first step
    FILE* fr = fopen("random_data.txt", "r");
    if(fr == NULL) {
        perror("random_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// set bitmap structure in first step.
    TYPE value;
    TYPE count = 0;
    while(fscanf(fr, "%u\n", &value) == 1) {
        if(value < MAX_VALUE) {
            bitmap_structure[value >> BITMAP_SHIFT] |=
                1 << (value & BITMAP_MASK);
            count++;
        }
    }
    printf("get total number in first step: %d.\n", count);
    /// write sorted output
    /// set write data file
    FILE* fw = fopen("sorted_data.txt","w");
    if(fw == NULL) {
        perror("sorted_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// write sorted data to file in first step
    TYPE i;
    for(i = 0; i < count; i++) {
        if(bitmap_structure[i >> BITMAP_SHIFT] & (1 << (i & BITMAP_MASK))) {
            fprintf(fw, "%u\n", i);
        }
    }
    /// read data from file in second step
    fr = freopen("random_data.txt", "r", fr);
    if(fr == NULL) {
        perror("random_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// set bitmap structure in second step.
    count = 0;
    while(fscanf(fr, "%u\n", &value) == 1) {
        if(value >= MAX_VALUE) {
            value -= MAX_VALUE;
            bitmap_structure[value >> BITMAP_SHIFT] |=
                1 << (value & BITMAP_MASK);
            count++;
        }
    }
    printf("get total number in second step: %d.\n", count);
    /// write sorted data to file in second step
    for(i = 0; i < count; i++) {
        if(bitmap_structure[i >> BITMAP_SHIFT] & (1 << (i & BITMAP_MASK))) {
            fprintf(fw, "%u\n", i + MAX_VALUE);
        }
    }
    /// close read data file
    if(fclose(fr) != 0) {
        perror("random_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
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
