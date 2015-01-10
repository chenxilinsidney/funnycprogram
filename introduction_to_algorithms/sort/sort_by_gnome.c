/**
 * @file sort_by_gnome.c
 * @brief sort sequence by gnome sort method.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-07
 */

#include <stdlib.h>
#include <stdio.h>
#define NDEBUG
#include <assert.h>

#include "memory.h"
#define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define MAX_COUNT      100000
TYPE array[MAX_COUNT] = {0};

void gnome_sort(TYPE* array, TYPE count)
{
    TYPE i = 0, temp;
    TYPE pos_last = 0;
    /// repeated until move to end
    while (i < count - 1) {
        if (array[i] <= array[i + 1]) {
            /// if have saved position before, set to it.
            if (pos_last != 0) {
                DEBUG_PRINT_STRING("last pos get.\n");
                DEBUG_PRINT_VALUE("%d", pos_last);
                i = pos_last;
                pos_last = 0;
            }
            /// move forward
            i++;
        } else {
            /// swap and move backward
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            /// i can not smaller than 0
            if (i > 0) {
                /// save position at first time
                if (pos_last == 0) {
                    DEBUG_PRINT_STRING("last pos set.\n");
                    DEBUG_PRINT_VALUE("%d", pos_last);
                    pos_last = i;
                }
                /// move backward
                i--;
            } else {
                i++;
            }
        }
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
    gnome_sort(array, count);
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
