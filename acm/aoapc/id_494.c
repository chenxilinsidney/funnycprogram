/**
 * @file id_494.c
 * @brief AOAPC I 494
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char line[1025];

int main()
{
    while (gets(line) != NULL) {
        int line_length = strlen(line);
        int index = 0;
        int flag = 1;
        int num_word = 0;
        while (index < line_length) {
            if (isalpha(line[index])) {
                if (flag) {
                    num_word++;
                    flag = 0;
                }
            } else {
                flag = 1;
            }
            index++;
        }
        printf("%d\n", num_word);
    }
    return 0;
}
