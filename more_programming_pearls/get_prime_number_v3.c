/**
 * @file get_prime_number_v3.c
 * @brief get the prime number and anlyse with gprop
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-26
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime_number(int count)
{
    if(0 == count % 2)
        return (2 == count);
    if(0 == count % 3)
        return (3 == count);
    if(0 == count % 5)
        return (5 == count);
    if(0 == count % 7)
        return (7 == count);
    int i;
    int root = sqrt(count);
    for(i = 11; i <= root; i += 2) {
        if(0 == count % i)
            return 0;
    }
    return 1;
}

int main(void)
{
    int i;
    int count = 1000;
    for(i = 2; i <= count; i++) {
        if(is_prime_number(i))
            printf("%d\n", i);
    }
    return EXIT_SUCCESS;
}
