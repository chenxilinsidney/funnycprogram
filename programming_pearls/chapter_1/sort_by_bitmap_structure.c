/**
 * @file sort_by_bitmap_structure.c
 * @brief sort a list of random data quickly by bitmap structure.
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
/// max random data value
#define max_value 10000000
/// bitmap structure initialize to empty
#define bitmap_length (unsigned)(max_value + 31) >> 5
TYPE bitmap_structure[bitmap_length] = {0};
int main(void) {
    /// insert present elements into the set
    /// read data from file
    FILE* fr = fopen("random_data.txt", "r");
    if(fr == NULL) {
        perror("random_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// set bitmap structure
    TYPE i, j;
    TYPE value;
    while(scanf("%u\n", &value) == 1) {
        bitmap_structure[value / 32] |= 1 << (value % 32);
    }
    /// close read data file
    if(fclose(fr) != 0) {
        perror("random_data.txt");
        DEBUG_PRINT_STATE;
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
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
    /// write sorted data to file
    for(i = 0; i < bitmap_length; i++) {
        for(j = 0; j < 32; j++) {
            if(bitmap_structure[i] & (1 << value)) {
                fprintf(fw, "%u\n", (i << 5) + j);
            }
        }
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
