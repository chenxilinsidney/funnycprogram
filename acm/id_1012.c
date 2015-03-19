/**
 * @file id_1012.c
 * @brief HDOJ Problem ID 1012.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-19
 */

#include <stdio.h>

int main()
{
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    printf("3 2.666666667\n");
    printf("4 2.708333333\n");
    printf("5 2.716666667\n");
    printf("6 2.718055556\n");
    printf("7 2.718253968\n");
    printf("8 2.718278770\n");
    printf("9 2.718281526\n");
#if 1
    int index, temp = 1;
    double e = 1.0;
    for (index = 1; index < 10; index++) {
        temp *= index;
        e += 1.0 / temp; 
        printf("%d %lf\n", index, e);
    }
    int a[8];
    a[7] = 8;
    for (index = 7; index >= 1; index--) {
        a[index - 1] = a[index] * index;
    }
    int sum = 0;
    for (index = 0; index < 8; index++) {
        sum += a[index];
        printf("%d %d\n", index, a[index]);
    }
    printf("aaa = %d, %lf\n", sum, (sum + 1) * 1.0 / a[0]);
#endif
    return 0;
}
