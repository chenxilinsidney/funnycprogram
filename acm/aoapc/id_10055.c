/**
 * @file id_10055.c
 * @brief AOAPC I 10055
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-22
 */

#include <stdio.h>

int main()
{
    long a, b;
    while (scanf("%ld%ld", &a, &b) != EOF) {
        if (a > b)
            printf("%ld\n", a - b);
        else
            printf("%ld\n", b - a);
    }
    return 0;
}
