/**
 * @file find_two_numbers_violent.c
 * @brief find two numbers A and B in a input array(length N) that make
 * A + B = X, which X is given by input too.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-18
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define MAX_COUNT      10000000
TYPE array[MAX_COUNT] = {0};

/**
 * @brief find two numbers value_a and value_b in the array
 * (with limit length) with given sum to make: sum = value_a + value_b
 *
 * @param[in]      array   input array
 * @param[in]      length  array length
 * @param[in]      sum     sum that makes sum = value_a + value_b
 * @param[out]     value_a value_a in the array
 * @param[out]     value_b value_b in the array
 *
 * @return if get value_a and value_b, return 1, else return 0
 */
TYPE find_two_numbers(TYPE* array, TYPE length, TYPE sum,
        TYPE* value_a, TYPE* value_b)
{
    assert(array != NULL && length >= 2 && value_a != NULL && value_b != NULL);
    TYPE i, j;
    for (i = 0; i < length - 1; i++) {
        /// set value a
        *value_a = array[i];
        /// find value b
        *value_b = sum - array[i];
        for (j = i + 1; j < length; j++) {
            if (*value_b == array[j])
                return 1;
        }
    }
    return 0;
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// set last value as input value X (X = A + B)
    TYPE sum = array[count - 1];
    printf("sum of the two numbers in input array is %d\n", sum);
    /// get right array length N
    count--;
    /// search value A and value B in the array
    TYPE value_a = 0;
    TYPE value_b = 0;
    /// output result
    if(find_two_numbers(array, count, sum, &value_a, &value_b)) {
        printf("The first numbers in the array is %d\n", value_a);
        printf("The second numbers in the array is %d\n", value_b);
    } else {
        printf("Can not find the two numbers.\n");
    }
    return EXIT_SUCCESS;
}
