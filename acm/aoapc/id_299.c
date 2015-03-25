/**
 * @file id_299.c
 * @brief AOAPC I 299
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-25
 */

#include <stdio.h>
#include <stdlib.h>

int list[50];

int main()
{
    int num_case;
    scanf("%d", &num_case);
    while (num_case--) {
        int length;
        scanf("%d", &length);
        if (length == 0) {
            printf("Optimal train swapping takes 0 swaps.\n");
            continue;
        }
        int index = 0, j, temp;
        int count = 0;
        while (index < length) scanf("%d", list + index++);
        for (index = 0; index < length; index++) {
            for (j = 0; j < length - 1; j++) {
                if (list[j] > list[j + 1]) {
                    temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    return 0;
}
