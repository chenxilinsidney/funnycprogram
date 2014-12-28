/**
 * @file count_number_1_in_byte_v1.c
 * @brief count the number 1 in binary form of a byte(8 bits).
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-28
 */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef unsigned char TYPE;
TYPE N = 234;
TYPE search_list[UCHAR_MAX] = {0};

TYPE count_number_1_in_byte(TYPE n)
{
    TYPE sum = 0;
    while(n) {
        n &= (n - 1);
        sum++;
    }
    return sum;
}

int main(void)
{
    /// 预先生成表
    TYPE i = 0;
    for (i = 0; i < UCHAR_MAX; i++)
        search_list[i] = count_number_1_in_byte(i);
    /// 查表法求值
    TYPE sum = 0;
    sum = search_list[N];
    printf("sum of number 1 in %d is %d.\n", N, sum);
    return EXIT_SUCCESS;
}
