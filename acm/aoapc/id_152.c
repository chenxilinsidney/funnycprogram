/**
 * @file id_152.c
 * @brief AOAPC I 152
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <stdlib.h>

int N_list[10000];
int square_list[11] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100};

int compare_int(void const* a, void const* b)
{
    return *((int*)a) - *((int*)b);
}

unsigned char tree_list[5000][3];

int main()
{
    int num_case = 0;
    int output[10] = {0};
    int a, b, c;
    int index;
    while (scanf("%d%d%d", &a, &b, &c) && (!(a == 0 && b == 0 && c == 0))) {
        tree_list[num_case][0] = a;
        tree_list[num_case][1] = b;
        tree_list[num_case][2] = c;
        num_case++;
    }
    int i, j, distance, a0, b0, c0;
    for (i = 0; i < num_case; i++) {
        a0 = tree_list[i][0];
        b0 = tree_list[i][1];
        c0 = tree_list[i][2];
        int min = 100;
        for (j = 0; j < num_case; j++) {
            if (j == i) {
                continue;
            }
            a = tree_list[j][0];
            b = tree_list[j][1];
            c = tree_list[j][2];
            if (abs(a - a0) >= 10 || abs(b - b0) >= 10 ||
                    abs(c - c0) >= 10) {
                continue;
            }
            distance = (a - a0) * (a - a0) +
                (b - b0) * (b - b0) +
                (c - c0) * (c - c0);
            if (min > distance)
                min = distance;
        }
        if (min == 100)
            continue;
        index = 0;
        for (index = 0; index < 10; index++) {
            if (min >= square_list[index] &&
                    min < square_list[index + 1]) {
                output[index]++;
                break;
            }
        }
    }
    for (index = 0; index < 10; index++)
        printf("%4d", output[index]);
    printf("\n");
    return 0;
}
