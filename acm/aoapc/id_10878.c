/**
 * @file id_10878.c
 * @brief AOAPC I 10878
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 12
char line[MAX_LINE_LENGTH];

int bit_list[8] = {128, 64, 32, 16, 8, 4, 2, 1};

int main()
{
    while (gets(line)) {
        if (line[0] != '|')
            continue;
        int line_index = 1;
        int character = 0;
        while (line_index < 6) {
            if (line[line_index] == 'o')
                character += bit_list[line_index - 1];
            line_index++;
        }
        line_index = 7;
        while (line_index < 10) {
            if (line[line_index] == 'o')
                character += bit_list[line_index - 2];
            line_index++;
        }
        putchar(character);
    }
    return 0;
}
