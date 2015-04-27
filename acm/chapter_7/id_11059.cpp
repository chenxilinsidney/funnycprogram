/**
 * @file id_11059.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-27
 */

#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int list[18];
    long long max;
    long long temp;
    int num_case = 1;
    while (cin >> n) {
        cout << "Case #" << num_case++ << ": The maximum product is ";
        int positive = 0;
        int negative = 0;
        int zero = 0;
        for (int i = 0; i < n; i++) {
            cin >> list[i];
            if (list[i] > 0) positive++;
            else if (list[i] < 0) negative++;
            else zero++;
        }
        if (negative <= 1 && negative + zero == n) {
            cout << "0." << endl << endl;
            continue;
        }
        if (!(negative & 1) && zero == 0) {
            max = 1;
            for (int i = 0; i < n; i++) max *= list[i];
            cout << max << "." << endl << endl;
            continue;
        }
        max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                temp = 1;
                for (int k = i; k <= j; k++) {
                    temp *= list[k];
                }
                if (temp > max) max = temp;
            }
        }
        cout << max << "." << endl << endl;
    }
    return 0;
}
