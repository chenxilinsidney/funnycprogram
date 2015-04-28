/**
 * @file id_524.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 
 * @date 2015-04-28
 */

#include <iostream>
#include <algorithm>

using namespace std;

int is_prime[32] = {
    0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1
};

int A[16];
int visit[16];

void dfs(int n, int cur)
{
    if (n == cur && is_prime[A[n - 1] + A[0]]) {
        for (int i = 0; i < n - 1; i++)
            cout << A[i] << " ";
        cout << A[n - 1] << endl;
    } else {
        for (int i = 1; i < n; i++) {
            if (!visit[i] && is_prime[i + 1 + A[cur - 1]]) {
                visit[i] = 1;
                A[cur] = i + 1;
                dfs(n, cur + 1);
                visit[i] = 0;
            }
        }
    }
}

int main(void)
{
    int n;
    int index_case = 1;
    while (cin >> n) {
        cout << "Case " << index_case++ << ":" << endl;
#if 0
        for (int i = 0; i < n; i++) A[i] = i + 1;
        do {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (!is_prime[A[i] + A[(i + 1) % n]]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int i = 0; i < n - 1; i++)
                    cout << A[i] << " ";
                cout << A[n - 1] << endl;
            }
        } while (next_permutation(A + 1, A + n));
#endif
        for (int i = 0; i < n; i++) visit[i] = 0;
        visit[0] = 1; A[0] = 1;
        dfs(n, 1);
        cout << endl;
    }
    return 0;
}
