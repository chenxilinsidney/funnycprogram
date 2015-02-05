/**
 * @file range_overlap_judgement.c
 * @brief judge if the given source range is in the given target ranges.
 * @author chenxilinsidney@gmail.com
 * @version 1.0
 * @date 2015-02-03
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

#include "memory.h"
// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define MAX_COUNT      10
TYPE array[MAX_COUNT][2] = {{0}};

/**
 * @brief judge if the given source range is in the given target ranges.
 *
 * @param[in]     source   source range array length 2
 * @param[in]     target   target range, each range has two values
 * @param[in]     count    target range count
 *
 * @return return 1 if the given source range is in the given target ranges,
 * others return 0.
 */
TYPE range_overlap_judgement(TYPE* source, TYPE* target, TYPE count)
{
    // x <= y for range [x, y]
    assert(source[0] <= source[1]);
    TYPE i, j;
    for (i = 0; i < count; i++) {
        assert(target[i << 1] <= target[(i << 1) + 1]);
    }
    // target range combined
    TYPE *x1, *y1, *x2, *y2;
    TYPE* flag_targe_done = SCALLOC(count, TYPE);
    /// get first range
    for (i = 0; i < count; i++) {
        if (flag_targe_done[i])
            continue;
        x1 = target + (i << 1);
        y1 = target + (i << 1) + 1;
        /// do with the second range
        for (j = i + 1; j < count; j++) {
            if (flag_targe_done[j])
                continue;
            x2 = target + (j << 1);
            y2 = target + (j << 1) + 1;
            /// process two relative range
            if (*x2 >= *x1 && *x2 <= *y1) {
                if (y1 <= y2) {
                    /// refresh range
                    *y1 = *y2;
                }
                flag_targe_done[j] = 1;
            } else if (*y2 >= *x1 && *y2 <= *y1) {
                if (*x2 <= *x1) {
                    /// refresh range
                    *x1 = *x2;
                }
                flag_targe_done[j] = 1;
            } else if(*x2 <= *x1 && *y1 <= *y2) {
                /// refresh range
                *x1 = *x2;
                *y1 = *y2;
                flag_targe_done[j] = 1;
            }
        }
    }
    // display the processed range
    DEBUG_PRINT_STRING("test flag and range.\n");
    for (i = 0; i < count; i++) {
        /// ignore useless range
        if (!flag_targe_done[i]) {
            DEBUG_PRINT_VALUE("%d", target[i << 1]);
            DEBUG_PRINT_VALUE("%d", target[(i << 1) + 1]);
        }
    }
    // source range detect
    DEBUG_PRINT_STRING("test source range.\n");
    for (i = 0; i < count; i++) {
        /// ignore useless range and test if source range in the target range
        if (!flag_targe_done[i] && target[i << 1] <= source[0] &&
                target[(i << 1) + 1] >= source[1]) {
            SFREE(&flag_targe_done);
            return 1;
        }
    }
    SFREE(&flag_targe_done);
    return 0;
}

int main(void) {
    /// read range to array, each range write as [32,24]
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("[%d,%d]\n",
                *(array + count), *(array + count) + 1) == 2) {
        ++count;
    }
    /// make last range as source range
    TYPE source[2] = {0};
    count--;
    source[0] = array[count][0];
    source[1] = array[count][1];
    printf("the source range(ex:3 5) is [%d,%d]\n",source[0], source[1]);
    printf("the target range count = %d\n", count);
    /// output result
    if(range_overlap_judgement(source, (TYPE*)array, count)) {
        printf("The source range is in the target range.\n");
    } else {
        printf("The source range is not in the target range.\n");
    }
    return EXIT_SUCCESS;
}
