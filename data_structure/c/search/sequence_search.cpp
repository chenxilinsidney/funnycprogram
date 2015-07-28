/**
 * @file sequence_search.cpp
 * @brief sequence search algorithm
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
 * @brief sequence search algorithm
 *
 * @param[in]    array     array input
 * @param[in]    length    array length
 * @param[in]    key       key value
 *
 * @warning the index of the array begin for 1
 *
 * @return the index of the key, return 0 if no fountd
 */
int sequence_search(int* array, int length, int key)
{
    assert(array != NULL && length >= 0);
    for (int i = 1; i <= length; i++) {
        if (array[i] == key)
            return i;
    }
    return 0;
}

/**
 * @brief sequence search algorithm using a sentinel
 *
 * @param[in]    array     array input
 * @param[in]    length    array length
 * @param[in]    key       key value
 *
 * @warning the index of the array begin for 1
 *
 * @return the index of the key, return 0 if no fountd
 */
int sequence_search_opt(int* array, int length, int key)
{
    assert(array != NULL && length >= 0);
    array[0] = key;
    int i = length;
    while (array[i] != key) i--;
    return i;
}

int main() {
    int array[6] = {0, 1, 3, 5, 6, 7};
    int key = 5;
    cout << "search key " << key << " result: " <<
        sequence_search_opt(array, 5, key) << endl;
    key = 9;
    cout << "search key " << key << " result: " <<
        sequence_search_opt(array, 5, key) << endl;
}
