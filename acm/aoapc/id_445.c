/**
 * @file id_490.c
 * @brief AOAPC I 490
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
    while (gets(line) != NULL) {
        int line_length = strlen(line);
        if (line_length == 0) {
            printf("\n");
            continue;
        }
        int line_index;
        int count_char = 0;
        for (line_index = 0; line_index < line_length; line_index++) {
            char temp = line[line_index];
            if (isdigit(temp)) {
                count_char += temp - '0';
            } else if (temp == '!') {
                printf("\n");
            } else if (isupper(temp) || temp == '*') {
                while (count_char--) {
                    printf("%c", temp);
                }
                count_char = 0;
            } else if (temp == 'b') {
                while (count_char--) {
                    printf(" ");
                }
                count_char = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
