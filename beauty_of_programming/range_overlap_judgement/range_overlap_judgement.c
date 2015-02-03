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
 * @param[in]     target   target range 2-dimension array
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
        DEBUG_PRINT_VALUE("%d", i);
        DEBUG_PRINT_VALUE("%d", target[i << 1]);
        DEBUG_PRINT_VALUE("%d", target[(i << 1) + 1]);
    }
    // target range combined
    TYPE x1, y1, x2, y2, flag = 1;
    TYPE* targe_new = SMALLOC(count << 1, TYPE);
    TYPE* count_new = count;
    memcpy(targe_new, target, count << 1);
    while (flag) {
        flag = 0;
        for (i = 0; i < count; i++) {
            x1 = target[i << 1];
            y1 = target[(i << 1) + 1];
            for (j = i + 1; j < count; j++) {
                x2 = target[i << 1];
                y2 = target[(i << 1) + 1];
                if (x2 >= x1 && x2 <= y1) {
                    if (y1 <= y2) y1 = y2;
                    x1 = x2;
                    count_new--;
                    flag = 1;
                } else if (y2 >= x1 && y2 <= y1) {
                    if (x2 <= x1) x1 = x2;
                    y2 = y1;
                    count_new--;
                    flag = 1;
                }
            }
        }
    }
    return 1;
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
    DEBUG_PRINT_VALUE("%d", array[0][0]);
    DEBUG_PRINT_VALUE("%d", array[0][1]);
    DEBUG_PRINT_VALUE("%p", array);
    DEBUG_PRINT_VALUE("%p", *array);
    DEBUG_PRINT_VALUE("%p", *(array + 1));
    DEBUG_PRINT_VALUE("%p", *(array + 2));
    DEBUG_PRINT_VALUE("%p", *(array + 1) + 1);
    /// output result
    if(range_overlap_judgement(source, (TYPE*)array, count)) {
        printf("The source range is in the target range.\n");
    } else {
        printf("The source range is not in the target range.\n");
    }
    return EXIT_SUCCESS;
}

