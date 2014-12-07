/**
 * @file Getsystemmemorysize.c
 * @brief get a program max memory malloc size
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-07
 */

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int MB = 0;
    while (malloc(1 << 20)) ++MB;
    printf("Allocated %d MB total.\n", MB);
    return 0;
}

