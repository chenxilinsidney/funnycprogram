/**
 * @file id_488.c
 * @brief AOAPC I 488
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>

int main()
{
    int case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        int amplitude, frequency;
        int index, temp;
        scanf("%d%d", &amplitude, &frequency);
        while (frequency--) {
            for (index = 1; index <= amplitude; index++) {
                temp = index;
                while (temp--)
                    printf("%d", index);
                printf("\n");
            }
            for (index = amplitude - 1; index >= 1; index--) {
                temp = index;
                while (temp--)
                    printf("%d", index);
                printf("\n");
            }
            if (frequency)
                printf("\n");
        }
        if (case_num)
            printf("\n");
    }
    return 0;
}
