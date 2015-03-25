/**
 * @file id_10474.c
 * @brief AOAPC I 10474
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <stdlib.h>

int N_list[10000];

int compare_int(void const* a, void const* b)
{
    return *((int*)a) - *((int*)b);
}

int main()
{
    int num_case = 1;
    int N, Q;
    while (scanf("%d%d", &N, &Q) && (!(N == 0 && Q == 0))) {
        printf("CASE# %d:\n", num_case++);
        int N_index = 0;
        while (N_index < N)
            scanf("%d", N_list + N_index++);
        qsort((void*)N_list, N, sizeof(N_list[0]), compare_int);
        while (Q--) {
            int query;
            scanf("%d", &query);
            for (N_index = 0; N_index < N; N_index++) {
                if (N_list[N_index] == query) {
                    printf("%d found at %d\n", query, N_index + 1);
                    break;
                }
            }
            if (N_index == N)
                printf("%d not found\n", query);
        }
    }
    return 0;
}
