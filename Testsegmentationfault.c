/**
 * @file Testbuserror.c
 * @brief test segmentaion fault
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
    int *p = NULL;
    printf("p address = %p\n", p);
    *(p) = 6550038;
    printf("no segmentaion fault!\n");
    return 0;
}
