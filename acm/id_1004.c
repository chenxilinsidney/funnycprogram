/**
 * @file id_1004.c
 * @brief HDOJ Problem ID 1004.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-18
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#ifndef ONLINE_JUDGE
// #define ONLINE_JUDGE
#endif

int main()
{
    char color_type_table[1000][16];
    int color_count_table[1000];
    int color_type_index = 0;
    int color_type = 0;
    int color_count;
    int color_index = 0;
    char color[16];
    while (scanf("%d", &color_count) && color_count != 0) {
        memset(color_count_table, 0, sizeof(color_count_table[0]) * 1000);
        for (color_index = 0; color_index < color_count; color_index++) {
           scanf("%s", color);
           for (color_type_index = 0; color_type_index < color_type;
                   color_type_index++) {
               if (strcmp(*(color_type_table + color_type_index), color)
                       == 0) {
                   color_count_table[color_type_index] =
                       color_count_table[color_type_index] + 1;
                   break;
               }
           }
           if (color_type_index == color_type) {
               strcpy(*(color_type_table + color_type), color);
               color_count_table[color_type] = 1;
               color_type++;
           }
        }
        int best_color_count = 0, best_color_index;
        for (color_index = 0; color_index < color_type; color_index++) {
#ifndef ONLINE_JUDGE
            printf("%d %s %d\n", color_index,
                    *(color_type_table + color_index),
                    color_count_table[color_index]);
#endif
            if (color_count_table[color_index] > best_color_count) {
                best_color_count = color_count_table[color_index];
                best_color_index = color_index;
            }
        }
        printf("%s\n", *(color_type_table + best_color_index));
    }
    return 0;
}
