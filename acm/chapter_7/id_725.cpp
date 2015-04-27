/**
 * @file id_725.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-27
 */

#include <iostream>
#include <iomanip>

using namespace std;

bool isdifferent(int a, int b)
{
    int flag[10] = {0};
    if (a < 10000) flag[0] = 1;
    if (b < 10000) {
        if (!flag[0])
            flag[0] = 1;
        else
            return false;
    }
    while (a) {
        if (!flag[a % 10])
            flag[a % 10] = 1;
        else
            return false;
        a = a / 10;
    }
    while (b) {
        if (!flag[b % 10])
            flag[b % 10] = 1;
        else
            return false;
        b = b / 10;
    }
    return true;
}
int main(void)
{
    int n, b;
    cin >> n;
    while (n != 0) {
        int flag = false;
        for (int i = 1234; i < 100000; i++) {
            b = n * i;
            if (b >= 100000) break;
            if (isdifferent(i, b)) {
                cout << setfill('0') << setw(5) << b <<
                    " / " << setfill('0') << setw(5) << i << " = " << n << endl;
                flag = true;
            }
        }
        if (!flag) cout << "There are no solutions for " << n << "." << endl;
        cin >> n;
        if (n) cout << endl;
    }
    return 0;
}
