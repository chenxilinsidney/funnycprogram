/**
 * @file interpolation_search.cpp
 * @brief interpolation search algorithm
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-07-28
 */

#include <cassert>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

/**
 * @brief interpolation search algorithm
 *
 * @param[in]    array     array input
 * @param[in]    length    array length
 * @param[in]    key       key value
 *
 * @warning the index of the array begin from 0
 *
 * @return the index of the key, return -1 if no found
 */
int interpolation_search(int* array, int length, int key)
{
    assert(array != NULL && length > 0);
    int index_begin = 0;
    int index_end = length - 1;
    int index_mid;
    while (array[index_end] != array[index_begin] &&
            array[index_begin] <= key &&
            array[index_end] >= key) {
        index_mid = index_begin + (key - array[index_begin]) *
            (index_end - index_begin) / (array[index_end] - array[index_begin]);
        if (array[index_mid] == key)
            return index_mid;
        else if (array[index_mid] < key)
            index_begin = index_mid + 1;
        else
            index_end = index_mid - 1;
    }
    if (array[index_begin] == key)
        return index_begin;
    else
        return -1;
}

int main() {
    int array[6] = {0, 1, 3, 5, 6, 7};
    int key = 5;
    cout << "search key " << key << " result: " <<
        interpolation_search(array, 6, key) << endl;
    key = 9;
    cout << "search key " << key << " result: " <<
        interpolation_search(array, 6, key) << endl;
}
