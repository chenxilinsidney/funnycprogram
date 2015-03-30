/**
 * @file id_10152.cpp
 * @brief AOAPC I 10152
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-30
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string original[205];
    string required[205];
    int num_cases;
    cin >> num_cases;
    int num_names;
    while (num_cases--) {
        // number of names
        cin >> num_names;
        cin.get();
        // original
        for (int i = 0; i < num_names; i++)
            getline(cin, original[i]);
        // required
        for (int i = 0; i < num_names; i++)
            getline(cin, required[i]);
        int j = num_names - 1;
        for (int i = num_names - 1; i >= 0; i--) {
            if (required[j] == original[i])
                j--;
        }
        for (int i = j; i >= 0; i--) {
            cout << required[i] << endl;
        }
        cout << endl;
    }
    return 0;
}
