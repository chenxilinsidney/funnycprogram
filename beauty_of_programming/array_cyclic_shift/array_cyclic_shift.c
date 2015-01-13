/**
 * @file array_cyclic_shift.c
 * @brief an operation for an array of cyclic shift
 * with time O(N) limit and only two additional variables.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-13
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
 * @brief get greatest commont divisor(gcd) for value m and n.
 *
 * @param[in]      m  first value
 * @param[in]      n  second value
 *
 * @return gcd value
 */
TYPE gcd(TYPE m, TYPE n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (m < n) {
        TYPE temp = m;
        m = n;
        n = temp;
    }
    while (n != 0) {
        TYPE temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}
/**
 * @brief cyclic shift for an array
 *
 * @param[in,out]  array   shift array
 * @param[in]      count   array length
 * @param[in]      right_shift  right shift count
 */
void array_cyclic_shift(TYPE* array, TYPE count, TYPE right_shift)
{
    assert(array != NULL && right_shift >= 0 && count >= 1);
    /// let right shift smaller than count
    right_shift %= count;
    TYPE i, k, temp;
    /// get the gcd value from right_shift and count to set cyclic shift times
    TYPE cyclic_count = gcd(right_shift, count);
    for (k = 0; k < cyclic_count; k++) {
        /// index begin from the top value
        i = count - 1 - k;
        /// save top value to buffer
        temp =  array[i];
        /// set value to value right_shift distance before it in a cycle
        while (((i - right_shift + count) % count) != count - 1 - k) {
            array[i] = array[(i - right_shift + count) % count];
            i = (i - right_shift + count) % count;
        }
        /// set last value from buffer
        array[i] = temp;
    }
    return;
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%d\n", array + count) == 1) {
        ++count;
    }
    /// test for all shift
    TYPE j;
    for (j = 1; j < count; j++) {
        array_cyclic_shift(array, count, j);
        if (array[j] != 1) {
            DEBUG_PRINT_VALUE("%d", j);
            DEBUG_PRINT_STRING("get wrong array by shift.\n");
        }
        array_cyclic_shift(array, count, count - j);
    }
    /// output result
    TYPE i;
    for(i = 0; i < count; i++) {
        printf("%d\n", array[i]);
    }
    return EXIT_SUCCESS;
}
