/**
 * @file Testbuserror.c
 * @brief test bus error
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-07
 */

#include<stdio.h>

union test {
    char a[10];
    int i;
} ex;

int main(void)
{
    int *p = (int*)&(ex.a[1]);  // not alignment
    printf("ex address = %p\n", &ex);
    printf("p address = %p\n", p);
    *(p) = 6550038;
    printf("no bus error!\n");
    return 0;
}
