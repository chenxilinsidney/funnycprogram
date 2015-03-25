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

int main()
{
    while (gets(line)) {
        int line_length = strlen(line);
        int num_pancake = 0;
        int line_index;
        int flag = 0, index_begin = 0, index_end = 0;
        int min_pancake_d = 101, min_pancake_index = 0;
        int max_pancake_d = 0, max_pancake_index = 0;
        for (line_index = 0; line_index <= line_length; line_index++) {
            if (!flag && isdigit(line[line_index])) {
                index_begin = line_index;
                flag = !flag;
            }
            if (flag && !isdigit(line[line_index])) {
                index_end = line_index - 1;
                int power = 1;
                int pancake_d = 0;
                while (index_begin <= index_end) {
                    pancake_d += (line[index_end--] - '0') * power;
                    power *= 10;
                }
                num_pancake++;
                if (min_pancake_d > pancake_d) {
                    min_pancake_d = pancake_d;
                    min_pancake_index = num_pancake;
                }
                if (max_pancake_d < pancake_d) {
                    max_pancake_d = pancake_d;
                    max_pancake_index = num_pancake;
                }
                flag = !flag;
            }
        }
        printf("%s\n", line);
        if (max_pancake_index == num_pancake &&
                min_pancake_index == 1) {
            printf("0\n");
        } else if (max_pancake_index == 1 &&
                min_pancake_index == num_pancake) {
            printf("1 0\n");
        } else if (max_pancake_index > min_pancake_index &&
                max_pancake_index < num_pancake) {
            printf("%d 1 %d 0\n", num_pancake - max_pancake_index + 1,
                    num_pancake - max_pancake_index + min_pancake_index);
        } else if (max_pancake_index > min_pancake_index &&
                max_pancake_index == num_pancake) {
            printf("%d 0\n", num_pancake - min_pancake_index + 1);
        } else if (max_pancake_index < min_pancake_index &&
                min_pancake_index < num_pancake &&
                max_pancake_index > 1) {
            printf("%d 1 %d 0\n", num_pancake - max_pancake_index + 1,
                    min_pancake_index);
        } else if (max_pancake_index < min_pancake_index &&
                min_pancake_index == num_pancake) {
            printf("%d 1 0\n", num_pancake - max_pancake_index + 1);
        } else if (max_pancake_index < min_pancake_index &&
                max_pancake_index == 1) {
            printf("1 %d 0\n", min_pancake_index);
        }
    }
    return 0;
}
