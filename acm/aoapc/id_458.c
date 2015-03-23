/**
 * @file id_458.c
 * @brief AOAPC I 458
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
        int index = 0;
        while (index < line_length) {
            printf("%c", line[index] - 7);
            index++;
        }
        printf("\n");
    }
    return 0;
}
