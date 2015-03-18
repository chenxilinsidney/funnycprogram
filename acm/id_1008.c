/**
 * @file id_1008.c
 * @brief HDOJ Problem ID 1008.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-18
 */

#include <stdio.h>

int main()
{
    int a, b;
    int count, time;
    while (scanf("%d", &count) != EOF && count != 0) {
        a = 0;
        time = 0;
        while (count--) {
            scanf("%d", &b);
            if (a > b) {
                time += 4 * (a - b) + 5;
            } else {
                time += 6 * (b - a) + 5;
            }
            a = b;
        }
        printf("%d\n", time);
    }
    return 0;
}
