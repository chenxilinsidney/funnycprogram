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
 * @brief select the last element as a pivoit.
 * Reorder the array so that all elements with values less than the pivot
 * come before the pivot, while all elements with values greater than the pivot
 * come after it (equal values can go either way). After this partitioning, the
 * pivot is in its final position. 
 *
 * @param[in,out]  array          input and output array
 * @param[in]      index_begin    the begin index of the array(included)
 * @param[in]      index_end      the end index of the array(included)
 *
 * @return the position of the pivot(index from the array)
 */
TYPE partition(TYPE* array, TYPE index_begin, TYPE index_end)
{
    /// pick last element of the array as the pivot
    TYPE pivot = array[index_end];
    /// index of the elments that not greater than pivot
    TYPE i = index_begin - 1;
    TYPE j, temp;
    /// check array's elment one by one
    for (j = index_begin; j < index_end; j++) {
        if (array[j] <= pivot) {
            /// save the elements not greater than pivot to left index of i.
            i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    /// set the pivot to the right position
    array[index_end] = array[++i];
    array[i] = pivot;
    /// return the position of the pivot
    return i;
}

/**
 * @brief quick sort method for input array from index_begin to index_end.
 *
 * @param[in,out]  array          input and output array
 * @param[in]      index_begin    the begin index of the array(included)
 * @param[in]      index_end      the end index of the array(included)
 */
void quick_sort(TYPE* array, TYPE index_begin, TYPE index_end)
{
    /// sort only under the index_begin < index_end condition
    if ( index_begin < index_end) {
        /// exchange elements to the pivot position by partition function
        TYPE index_pivot = partition(array, index_begin, index_end);
        /// sort the array before the pivot position
        quick_sort(array, index_begin, index_pivot - 1);
        /// sort the array after the pivot position
        quick_sort(array, index_pivot + 1, index_end);
    }
}

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
    /// sort array by quick sort method
    quick_sort(array, 0, length - 1);
    /// search by two pointers at the begining and end of the array
    TYPE i = 0, j = length - 1, sum_temp;
    while (i < j) {
        sum_temp = array[i] + array[j];
        if (sum_temp < sum) {
            i++;
        } else if (sum_temp > sum) {
            j--;
        } else {
            *value_a = array[i];
            *value_b = array[j];
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
