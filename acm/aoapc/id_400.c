
/**
 * @file id_400.c
 * @brief AOAPC I 400
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

#define MAX_WORD_WIDTH 61
char list[1000][MAX_WORD_WIDTH];

int compare_string(void const* a, void const* b)
{
    char* ptr_a = (char*)a;
    char* ptr_b = (char*)b;
    while (*ptr_a != '\0' && *ptr_b != '\0') {
        if (*ptr_a < *ptr_b) {
            return -1;
        } else if (*ptr_a > *ptr_b) {
            return 1;
        }
        ptr_a++;
        ptr_b++;
    }
    if (*ptr_a == '\0' && *ptr_b == '\0')
        return 0;
    else if (*ptr_a == '\0')
        return -1;
    else
        return 1;
}

int main()
{
    int num_file_names;
    while (scanf("%d", &num_file_names) != EOF) {
        /* scan to get list and get max length */
        int list_index = 0;
        int max_length = 0;
        int temp_length = 0;
        while (list_index < num_file_names) {
            scanf("%s", list[list_index]);
            temp_length = strlen(list[list_index++]);
            if (temp_length > max_length)
                max_length = temp_length;
        }
        /* sort list */
        qsort((void*)(list), list_index, MAX_WORD_WIDTH,
                compare_string);
        /* get column and row */
        double column_f = 62.0 / (max_length + 2);
        int column = (int)(column_f + DBL_EPSILON);
        double row_f = list_index * 1.0 / column;
        int row = (int)(row_f + DBL_EPSILON);
        if (row * 1.0 - row_f > DBL_EPSILON ||
                row * 1.0 - row_f < -1 * DBL_EPSILON)
            row++;
        /* print result */
        int i, j, index, space;
        for (i = 0; i < 60; i++)
            printf("-");
        printf("\n");
        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                index = i + row * j;
                if (index >= list_index)
                    break;
                space = max_length + 2 - strlen(list[index]);
                printf("%s", list[index]);
                if (j == column - 1) space -= 2;
                if (j == column - 2 && index + row >= list_index) continue;
                while (space--) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
