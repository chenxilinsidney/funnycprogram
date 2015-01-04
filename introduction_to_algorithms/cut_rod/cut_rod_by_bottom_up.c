/**
 * @file cut_rod_by_recursion.c
 * @brief get maximum price of cut rod by recursion.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-04
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

#define ROD_PRICE_LENGTH  10
TYPE rod_price[ROD_PRICE_LENGTH] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

/**
 * @brief get max rod price by cutting rod by recursion method.
 *
 * @param rod_price rod price list for each type of different length
 * @param rod_price_length rod price list length
 * @param rod_length given rod length
 *
 * @return max rod price
 */
TYPE rod_cut_by_memoized(TYPE* rod_price,
        TYPE rod_length)
{
    TYPE memoized_cache[ROD_PRICE_LENGTH + 1] = {0};
    TYPE i, j;
    for (i = 1; i <= rod_length; i++) {
        memoized_cache[i] = INT_MIN;
        for (j = 0; j <= i - 1; j++) {
            TYPE temp = memoized_cache[i - j - 1] + rod_price[j];
            if (memoized_cache[i] < temp)
                memoized_cache[i] = temp;
        }
    }
    return memoized_cache[rod_length];
}

int main(void) {
    // set rod length
    TYPE rod_length = 8;
    assert(rod_length >= 1 && rod_length <= ROD_PRICE_LENGTH);
    // get maximum rod price by cutting rod
    TYPE max_total_price = rod_cut_by_memoized(rod_price,
            rod_length);
    // output result
    printf("max total price = %d\n", max_total_price);
    return EXIT_SUCCESS;
}
