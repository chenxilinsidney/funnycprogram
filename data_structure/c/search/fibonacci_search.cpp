/**
 * @file fibonacci_search.cpp
 * @brief fibonacci search algorithm
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-07-28
 */

#include <cassert>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


int F[10] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 24};
/**
 * @brief fibonacci search algorithm
 *
 * @param[in]    array     array input
 * @param[in]    length    array length
 * @param[in]    key       key value
 *
 * @warning the index of the array begin from 0
 *
 * @return the index of the key, return -1 if no found
 */
int fibonacci_search(int* array, int length, int key)
{
    assert(array != NULL && length > 0);
    int k = 0;
    while (length > F[k] - 1)
        k++; // get fibonacci index
    for (int i = length; i < F[k] - 1; i++)
        array[i] = array[length - 1];  // fix the value
    int index_begin = 0;
    int index_end = length - 1;
    int index_mid;
    while (index_begin <= index_end) {
        index_mid = index_begin + F[k - 1] - 1;
        if (array[index_mid] == key) {
            if (index_mid <= length - 1)
                return index_mid;
            else
                return -1; // exceed the range because of fixed value
        } else if (array[index_mid] < key) {
            index_begin = index_mid + 1;
            k -= 2;  // right half
        } else {
            index_end = index_mid - 1;
            k -= 1;  // left half
        }
    }
    return -1;
}

int main() {
    int array[6] = {0, 1, 3, 5, 6, 7};
    int key = 5;
    cout << "search key " << key << " result: " <<
        fibonacci_search(array, 6, key) << endl;
    key = 9;
    cout << "search key " << key << " result: " <<
        fibonacci_search(array, 6, key) << endl;
}
