/**
 * @file id_1002.c
 * @brief HDOJ Problem ID 1002.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-18
 */

#include <stdio.h>

int main()
{
    int count, i = 1;
    unsigned long long a, b;
    scanf("%d", &count);
    while (scanf("%Illu%Illu", &a, &b) != EOF) {
        printf("Case %d:\n", i);
        printf("%Illu + %Illu = %Illu\n", a, b, a + b);
        if (i < count) printf("\n");
        i++;
    }
    return 0;
}
