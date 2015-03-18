/**
 * @file id_1001.c
 * @brief HDOJ Problem ID 1001.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-18
 */

#include <stdio.h>

int main()
{
    int a;
    while (scanf("%d", &a) != EOF) {
        printf("%d\n\n", ((a + 1) * (unsigned)a) >> 1);
    }
    return 0;
}
