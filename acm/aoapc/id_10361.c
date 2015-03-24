/**
 * @file id_10361.c
 * @brief AOAPC I 10361
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 101
char line[2][MAX_LINE_LENGTH];

int main()
{
    int num_case;
    scanf("%d\n", &num_case);
    while (num_case--) {
        gets(*line);
        gets(*(line+ 1));
        int line_length_a = strlen(*line);
        int line_length_b = strlen(*(line + 1));
        int line_index = 0;
        int char_position[4] = {0};
        int position_index = 0;
        /* output first line */
        while (line_index < line_length_a) {
            int character = line[0][line_index];
            if (character != '<' && character != '>')
                putchar(character);
            else
                char_position[position_index++] = line_index;
            line_index++;
        }
        printf("\n");
        /* output second line */
        line[1][line_length_b - 3] = '\0';
        printf("%s", line[1]);
        for (position_index = 2; position_index >= 0; position_index--)
            for (line_index = char_position[position_index] + 1; line_index <
                    char_position[position_index + 1]; line_index++)
                putchar(line[0][line_index]);
        printf("%s", line[0] + char_position[3] + 1);
        printf("\n");
    }
    return 0;
}
