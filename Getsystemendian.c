/**
 * @file Getsystemendian.c
 * @brief get system endian type:Big-Endian or Little-Endian.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-06
 */

#include<stdio.h>

/// union to test endian type
union test {
    int a;
    char b;
};

int main(void)
{
    union test sample;
    sample.a = 1;
    if ((int)(sample.b) == 1)
        printf("Big-Endian:Lower address postion save higher bytes data.\n");
    else
        printf("Little-Endian:Higher address "
                "position save higher bytes data.\n");
}

