/**
 * @file exercise.cpp
 * @brief exercise in 7.2
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-28
 */

#include <iostream>
#include <algorithm>

using namespace std;

int P[5] = {1, 1, 3, 5, 6};
void print_permutation(int n, int* A, int cur)
{
    if (n == cur) {
        for (int i = 0; i < n; i++) cout << A[i] << " ";
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (i && P[i] == P[i -1]) continue;
            int c1 = 0, c2 = 0;
            for (int j = 0; j < n; j++) if (P[j] == P[i]) c1++;
            for (int j = 0; j < cur; j++) if (A[j] == P[i]) c2++;
            if (c2 < c1) {
                A[cur] = P[i];
                print_permutation(n, A, cur + 1);
            }
        }
    }
}

int B[5] = {1, 3, 5, 7, 9};
void print_subset(int n, int* A, int cur)
{
    for (int i = 0; i < cur; i++) cout << A[i] << " ";
    cout << endl;
    int s = cur ? A[cur - 1] + 1 : 0;
    for (int i = s; i < n; i++) {
        A[cur] = i;
        print_subset(n, A, cur + 1);
    }
}
int main(void)
{
    int n = 4;
    int a[4] = {0};
    // print_permutation(2, a, 0);
    // do {
    //     for (int i = 0; i < 5; i++) cout << P[i] << " ";
    //     cout << endl;
    // } while (next_permutation(P, P + 5));
    print_subset(5, B, 0);
}

