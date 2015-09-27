/**
 * @file id_1013.c
 * @brief HDOJ Problem ID 1013.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-20
 */

#include <stdio.h>

void sum(char* array, char num)
{
    char temp, inc;
    array[0] = (array[0] + num) % 10;
    char inc = (array[0] + num) / 10;
    int index = 1;
    while (inc) {
        temp = array[index] + inc;
        inc = temp / 10;
        array[index] = temp % 10;
        index++;
    }
}

void sum_2(char* array, char* array_source, int count)
{
    int index = 0;
    while (index < count) {
        sum = sum_2(array, array_source[index]);
        index++;
    }
}
int main()
{
    int a, count;
    while ((a = getchar()) != EOF && a != '0') {
        int sum_array[5] = {0};
        count = 1;
        sum_array[0] = a - '0';
        while ((b = getchar()) != '\n') {
            sum(sum_array, b - '0');
            count++;
        }
        if (count <= 11) {
            int sum_array_b[2] = {0};
            sum_2(sum_array_b, sum_array, 2);
            memset(sum_array, 0, 2 * sizeof(sum_array[0]));
            sum_2(sum_array, sum_array_b, 2);
            printf("%d\n", sum_array[0]);
        } else if (count <= 111) {
            int sum_array_b[3] = {0};
            sum_2(sum_array_b, sum_array, 3);
            memset(sum_array, 0, 3 * sizeof(sum_array[0]));
            sum(sum_array, sum_array_b[0]);
            sum(sum_array, sum_array_b[1]);
            printf("%d\n", sum_array[0]);
        }
    }
    return 0;
}
