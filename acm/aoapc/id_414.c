/**
 * @file id_414.c
 * @brief AOAPC I 414
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char line[1024];

int main()
{
    int line_count;
    while (scanf("%d\n", &line_count) && line_count != 0) {
        int line_index = 0;
        int width;
        int min_width = 25;
        int sum_space = 0;
        while (line_index < line_count) {
            int index = 1;
            int postion_left = 0;
            gets(line);
            while (index < 24 && line[index] == 'X')
                index++;
            if (index == 24) {
                min_width = 0;
            } else {
                postion_left = index;
                index = 23;
                while (index > 0 && line[index] == 'X')
                    index--;
                width = index - postion_left + 1;
                sum_space += width;
                if (min_width > width)
                    min_width = width;
            }
            line_index++;
        }
        printf("%d\n", sum_space - line_count * min_width);
    }
    return 0;
}
