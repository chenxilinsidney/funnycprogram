/**
 * @file id_1583.c
 * @brief AOAPC I 1583
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>

int digit_generator(int num)
{
    int count_digit = 1;
    int num_copy = num;
    while (num_copy /= 10) count_digit++;
    num_copy = num - 9 * count_digit;
    int index = num_copy > 0 ? num_copy : 0;
    while (index <= num) {
        num_copy = index;
        int sum = num_copy;
        while (num_copy) {
            sum += num_copy % 10;
            num_copy /= 10;
        }
        if (sum == num)
            return index;
        index++;
    }
    return 0;
}

int main()
{
    int num_case;
    scanf("%d", &num_case);
    while (num_case--) {
        int N;
        scanf("%d", &N);
        printf("%d\n", digit_generator(N));
    }
    return 0;
}
