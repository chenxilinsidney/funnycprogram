/**
 * @file id_1005.c
 * @brief HDOJ Problem ID 1005.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-18
 */

#include <stdio.h>

#ifndef ONLINE_JUDGE
// #define ONLINE_JUDGE
#endif

int main()
{
    int a, b, n, n_index = 0;
    char flag_get;
    int array[50] = {1, 1};
    while (scanf("%d%d%d", &a, &b, &n) && (!(a == 0 && b == 0 && n == 0))) {
#ifndef ONLINE_JUDGE
            printf("n %d\n", n);
#endif
        n--;
        flag_get = 0;
        if (n < 2) {
            printf("%d\n", array[n]);
            continue;
        }
        for (n_index = 2; n_index < 50; n_index++) {
            array[n_index] =
                (a * array[n_index - 1] +
                b * array[n_index - 2]) % 7;
#ifndef ONLINE_JUDGE
            printf("AA %d %d\n", n_index, array[n_index]);
#endif
            if (n_index == n) {
                printf("%d\n", array[n]);
                flag_get = 1;
                break;
            }
        }
        if (flag_get == 0) {
            for (n_index = 1; n_index < 49; n_index++) {
                if (array[n_index] == 1 &&
                            array[n_index + 1] == 1) {
#ifndef ONLINE_JUDGE
                        printf("n %d length %d\n", n, n_index);
#endif
                        break;
                    }
            }
            printf("%d\n", array[n % n_index]);
        }
    }
    return 0;
}
