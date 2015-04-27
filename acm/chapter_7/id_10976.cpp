/**
 * @file id_10976.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-27
 */

#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int k;
int count;
int y[10000];
int x[10000];
double temp;
int temp_f;
int main(void)
{
    int k;
    while (cin >> k) {
        count = 0;
        for (int i = k + 1; i <= k * 2; i++) {
            temp = k * i * 1.0 / (i - k);
            temp_f = floor(temp);
            if (temp - temp_f >= 0 &&
                    temp - temp_f < numeric_limits<double>::epsilon()) {
                x[count] = temp_f;
                y[count] = i;
                count++;
            } else if (temp_f + 1 - temp >= 0 &&
                    temp_f - temp + 1 < numeric_limits<double>::epsilon()) {
                x[count] = temp_f + 1;
                y[count] = i;
                count++;
            }
        }
        cout << count << endl;
        for (int i = 0; i < count; i++)
            cout << "1/" << k << " = " << "1/" << x[i] << " + " <<
                "1/" << y[i] << endl;
    }
    return 0;
}
