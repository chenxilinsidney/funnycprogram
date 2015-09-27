/**
 * @file id_167.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-28
 */

#include <iostream>
#include <algorithm>

using namespace std;

void print_violent(int n)
{
    int* array = new int[n];
    // init
    for (int i = 0; i < n; i++) array[i] = i;
    // permutation
    do {
        // for (int j = 0; j < n; j++) cout << array[j] << " ";
        // cout << endl;
        // judge
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i - array[i] == j - array[j] ||
                        i + array[i] == j + array[j]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            // print result
            cout << "get result: " << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (array[i] == j) cout << "*";
                    else cout << "#";
                }
                cout << endl;
            }
        }
    } while (next_permutation(array, array + n));
    delete array;
}

int main(void)
{
    int n;
    int index_case = 1;
    while (cin >> n) {
        cout << "Case #" << index_case++ << ":" << endl;
        print_violent(n);
    }
    return 0;
}

