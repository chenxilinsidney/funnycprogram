/**
 * @file id_120.c
 * @brief AOAPC I 120
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-25
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
char line[MAX_LINE_LENGTH];
int pancake[30];

void flip(int* array, int array_index)
{
    int index_begin, temp;
    for (index_begin = 0; index_begin < array_index;
            array_index--, index_begin++) {
        temp = array[index_begin];
        array[index_begin] = array[array_index];
        array[array_index] = temp;
    }
}

int main()
{
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        int line_length = strlen(line);
        int num_pancake = 0;
        int line_index;
        int flag = 0, index_begin = 0;
        for (line_index = 0; line_index <= line_length; line_index++) {
            if (!flag && isdigit(line[line_index])) {
                index_begin = line_index;
                flag = !flag;
            }
            if (flag && !isdigit(line[line_index])) {
                int pancake_d;
                sscanf(line + index_begin, "%d", &pancake_d);
                pancake[num_pancake++] = pancake_d;
                flag = !flag;
            }
        }
        printf("%s", line);
        int index_end = num_pancake;
        while (index_end) {
            int max_index = 0;
            int max_pancake = 0;
            for (index_begin = 0; index_begin < index_end; index_begin++) {
                if (pancake[index_begin] > max_pancake) {
                    max_pancake = pancake[index_begin];
                    max_index = index_begin;
                }
            }
            if (max_index != index_end - 1) {
                if (max_index != 0) {
                    flip(pancake, max_index);
                    printf("%d ", num_pancake - max_index);
                }
                flip(pancake, index_end - 1);
                printf("%d ", num_pancake - index_end + 1);
            }
            index_end--;
        }
        printf("0\n");
    }
    return 0;
}
