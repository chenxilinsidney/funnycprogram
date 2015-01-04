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
TYPE rod_cut_by_memoized_aux(TYPE* rod_price,
        TYPE rod_length,
        TYPE* memoized_cache);
TYPE rod_cut_by_memoized(TYPE* rod_price,
        TYPE rod_length)
{
    // initialize cache
    TYPE memoized_cache[ROD_PRICE_LENGTH + 1];
    TYPE i;
    for (i = 0; i <= rod_length; i++)
        memoized_cache[i] = INT_MIN;
    return rod_cut_by_memoized_aux(rod_price, rod_length, memoized_cache);
}

TYPE rod_cut_by_memoized_aux(TYPE* rod_price,
        TYPE rod_length,
        TYPE* memoized_cache)
{
    DEBUG_PRINT_STRING("In recursion now.\n");
    DEBUG_PRINT_VALUE("%d", rod_length);
    if (memoized_cache[rod_length] > INT_MIN) {
        DEBUG_PRINT_STRING("get value from cache.\n");
        DEBUG_PRINT_VALUE("%d", memoized_cache[rod_length]);
        DEBUG_PRINT_VALUE("%d", rod_length);
        DEBUG_PRINT_STRING("Out recursion now.\n");
        return memoized_cache[rod_length];
    }
    if (rod_length == 0) {
        memoized_cache[rod_length] = 0;
        DEBUG_PRINT_STRING("set value to cache.\n");
        DEBUG_PRINT_VALUE("%d", memoized_cache[rod_length]);
        DEBUG_PRINT_VALUE("%d", rod_length);
        DEBUG_PRINT_STRING("Out recursion now.\n");
        return 0;
    }
    TYPE i;
    TYPE max = INT_MIN;
    for (i = 0; i < rod_length; i++) {
        TYPE temp = rod_cut_by_memoized(rod_price,
                rod_length - i - 1) + rod_price[i];
        if (temp > max)
            max = temp;
    }
    memoized_cache[rod_length] = max;
    DEBUG_PRINT_STRING("set value to cache.\n");
    DEBUG_PRINT_VALUE("%d", memoized_cache[rod_length]);
    DEBUG_PRINT_VALUE("%d", rod_length);
    DEBUG_PRINT_STRING("Out recursion now.\n");
    return max;
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
