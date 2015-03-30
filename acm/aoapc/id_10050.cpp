/**
 * @file id_10050.cpp
 * @brief AOAPC I 10050
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-30
 */

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_DAYS 3752
int day_log[MAX_DAYS];

int main()
{
    int num_cases;
    int days;
    int parities;
    int hartal;
    cin >> num_cases;
    while (num_cases--) {
        cin >> days;
        memset(day_log, 0, sizeof(day_log[0]) * (1 + days));
        cin >> parities;
        while (parities--) {
            cin >> hartal;
            int length = hartal;
            while (length <= days) {
                day_log[length] = 1;
                length += hartal;
            }
        }
        int result = 0;
        for (int i = 1; i <= days; i++) {
            if (day_log[i] && i % 7 != 0 && i % 7 != 6)
                result++;
        }
        cout << result << endl;
    }
}
