/**
 * @file id_699.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-08
 */

#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>

#define LEAVES_HALF_WIDTH 200
int array[LEAVES_HALF_WIDTH] = {0};

using namespace std;

bool build_tree_inorder(int leaves_index)
{
    int key;
    cin >> key;
    if (key == -1)
        return false;
    array[leaves_index] += key;
    build_tree_inorder(leaves_index - 1);
    build_tree_inorder(leaves_index + 1);
    return true;
}

int main(void)
{
    int num_case = 0;
    while (1) {
        memset(array, 0, sizeof(int) * LEAVES_HALF_WIDTH);
        if (!build_tree_inorder(100)) break;
        // print result
        num_case++;
        cout << "Case " << num_case << ":" << endl;
        int index;
        for (index = 0; index < LEAVES_HALF_WIDTH; index++) {
            if (array[index]) break;
        }
        for ( ; index < LEAVES_HALF_WIDTH; index++) {
            if (array[index + 1]) {
                cout << array[index] << " ";
            } else {
                cout << array[index] << endl;
                break;
            }
        }
        cout << endl;
#ifndef ONLINE_JUDGE
        cout << "left_max_index:" << left_max_index << endl;
        cout << "right_max_index:" << right_max_index << endl;
        cout << endl;
#endif
    }
    return 0;
}
