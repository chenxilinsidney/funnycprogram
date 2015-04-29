/**
 * @file id_129.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-29
 */

#include <iostream>

using namespace std;

int array[100];
int index;
int num;
int count;

void display_result(int length)
{
    for (int i = 0; i < length; i++) {
        cout << char(array[i] + 'A');
        if (i + 1 < length && (i + 1) % 4 == 0) {
            if ((i + 1) % 64 != 0) cout << " ";
            else cout << endl;
        }
    }
    if (length % 64) cout << endl;
    cout << length << endl;
}

bool dfs(int cur)
{
#ifndef ONLINE_JUDGE
    cout << "in dfs " << ", " << cur << endl;
    for (int i = 0; i < cur; i++) cout << char(array[i] + 'A');
    cout << endl;
#endif
    count++;
    if (index == count) {
        display_result(cur);
        return true;
    }
    for (int j = 0; j < num; j++) {
        array[cur] = j;
        bool same_string = false;
        for (int k = 0; k < (cur + 1) / 2; k++) {
            bool same = true;
            for (int m = 0; m <= k; m++) {
                if (array[cur - m] != array[cur - m - 1 - k]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                same_string = true;
                break;
            }
        }
        if (!same_string) {
            if (dfs(cur + 1)) return true;
        }
    }
    return false;
}

int main(void)
{
    while (cin >> index >> num && index != 0) {
        count = -1;
        dfs(0);
    }
    return 0;
}
