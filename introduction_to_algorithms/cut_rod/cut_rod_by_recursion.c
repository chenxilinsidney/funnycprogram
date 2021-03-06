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
TYPE rod_cut_by_recursion(TYPE* rod_price,
        TYPE rod_length)
{
    if (rod_length == 0)
        return 0;
    TYPE i;
    TYPE max = INT_MIN;
    for (i = 0; i < rod_length; i++) {
        TYPE temp = rod_cut_by_recursion(rod_price,
                rod_length - i - 1) + rod_price[i];
        if (temp > max)
            max = temp;
    }
    return max;
}

int main(void) {
    // set rod length
    TYPE rod_length = 8;
    assert(rod_length >= 1 && rod_length <= ROD_PRICE_LENGTH);
    // get maximum rod price by cutting rod
    TYPE max_total_price = rod_cut_by_recursion(rod_price,
            rod_length);
    // output result
    printf("max total price = %d\n", max_total_price);
    return EXIT_SUCCESS;
}
