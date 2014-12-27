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

#define TEST_COUNT      10000000
#define TEST_COUNT_HALF 10000000u >> 1

int prime_list[TEST_COUNT_HALF] = {0};
///< 0 means prime number, begin from 2, 3, 5, 7..., only include odd number

int main(void)
{
    int i, j;
    int sum = 0;
    int count = TEST_COUNT;
    int root = sqrt(count);
    for(i = 3; i <= root; i += 2) {
        if(!prime_list[(unsigned)(i - 1) >> 1]) {
            for(j = i * i; j <= count; j += i << 1) {
                prime_list[(unsigned)(j - 1) >> 1] = 1;
            }
        }
    }
    if(count >= 2) {
        printf("%d\n", i);
        sum++;
    }
    for(i = 3; i <= count; i += 2) {
        if(!prime_list[(unsigned)(i - 1) >> 1]) {
            printf("%d\n", i);
            sum++;
        }
    }
    printf("sum of the prime number to %d is %d.\n", count, sum);
    return EXIT_SUCCESS;
}
