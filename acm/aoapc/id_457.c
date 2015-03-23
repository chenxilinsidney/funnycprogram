/**
 * @file id_488.c
 * @brief AOAPC I 488
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>
#include <string.h>

void print_value(int i)
{
    switch (i) {
        case 0:
            printf(" ");
            break;
        case 1:
            printf(".");
            break;
        case 2:
            printf("x");
            break;
        case 3:
            printf("W");
            break;
        default:
            printf("????");
    }
}
int main()
{
    int case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        int index = 0;
        int DNA[10] = {0};
        while (index < 10) {
            scanf("%d", DNA + index);
            index++;
        }
        int dishes[40] = {0};
        dishes[19] = 1;
        int dishes_new[40] = {0};
        for (index = 0; index < 40; index++) {
            print_value(dishes[index]);
        }
        printf("\n");
        for (index = 0; index < 49; index++) {
            dishes_new[0] = DNA[dishes[0] + dishes[1]];
            print_value(dishes_new[0]);
            int index_dish;
            for (index_dish = 1; index_dish < 39; index_dish++) {
                dishes_new[index_dish] =
                    DNA[dishes[index_dish - 1] + dishes[index_dish + 1] +
                    dishes[index_dish]];
                print_value(dishes_new[index_dish]);
            }
            dishes_new[39] = DNA[dishes[39] + dishes[38]];
            print_value(dishes_new[39]);
            printf("\n");
            memcpy(dishes, dishes_new, 40 * sizeof(dishes_new[0]));
        }
        if (case_num)
            printf("\n");
    }
    return 0;
}
