/**
 * @file find_closest_array_violent.c
 * @brief find the two values in a given array that make their distance be
 * the minimum value so the the values are the closest pairs.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-02-15
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int ElementType;    ///< element data type
typedef int CommonType;     ///< common data type

#define MAX_COUNT      10000000
ElementType array[MAX_COUNT] = {0};

/**
 * @brief find value_a and value_b that they have the minimum distance in
 * the array.
 *
 * @param[in]     array           element array
 * @param[in]     array_size      element array size
 * @param[out]    value_a         element a
 * @param[out]    value_b         element b
 *
 * @return return the minimum distance between value_a and value_b
 */
ElementType find_closest_array(ElementType* array, CommonType array_size,
        ElementType* value_a, ElementType* value_b)
{
    assert(array != NULL && value_a != NULL &&
            value_b != NULL && array_size >= 2);
    /// initialize values.
    ElementType distance_min = abs(array[0] - array[1]);
    *value_a = array[0];
    *value_b = array[1];
    /// find closest value_a and value_b by violent
    CommonType i, j;
    ElementType temp;
    for (i = 0; i < array_size; i++) {
        for (j = i + 1; j < array_size; j++) {
            if ((temp = abs(array[i] - array[j])) < distance_min) {
                *value_a = array[i];
                *value_b = array[j];
                distance_min = temp;
            }
        }
    }
    /// return minimum distance
    return distance_min;
}

int main(void) {
    /// read data to array
    CommonType count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// find closest values
    ElementType value_a;
    ElementType value_b;
    ElementType distance = find_closest_array(array, count,
            &value_a, &value_b);
    /// output result
    printf("closest value_a and value_b is %d, %d.\n", value_a, value_b);
    printf("closest distance is %d.\n", distance);
    return EXIT_SUCCESS;
}
