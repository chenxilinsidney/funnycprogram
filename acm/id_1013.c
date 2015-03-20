/**
 * @file id_1013.c
 * @brief HDOJ Problem ID 1013.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-20
 */

#include <stdio.h>

int main()
{
    int a, b;
    while ((a = getchar()) != EOF && a != '0') {
        int digital_roots = a - '0';
        while ((b = getchar()) != '\n') {
            digital_roots = (digital_roots + b - '0') % 10;
        }
        printf("%d\n", digital_roots);
    }
    return 0;
}
