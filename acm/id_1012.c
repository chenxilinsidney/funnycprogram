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
    int index, temp = 2;
    double e = 2.5;
    for (index = 3; index < 10; index++) {
        temp *= index;
        e += 1.0 / temp; 
        printf("%d %.9lf\n", index, e);
    }
    return 0;
}
