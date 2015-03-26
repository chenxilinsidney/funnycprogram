/**
 * @file id_10815.c
 * @brief AOAPC I 10815
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1025
char line[MAX_LINE_LENGTH];

#define MAX_WORD_WIDTH 100
char word_list[5000*200][MAX_WORD_WIDTH];

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
    int word_list_index = 0;
    while (gets(line)) {
        int line_index = 0;
        int line_length = strlen(line);
        int flag_character = 0;
        int word_begin = 0;
        for (line_index = 0; line_index <= line_length; line_index++) {
            int flag_alpha = isalpha(line[line_index]);
            if (!flag_character && flag_alpha) {
                line[line_index] = tolower(line[line_index]);
                word_begin = line_index;
                flag_character = !flag_character;
            } else if (flag_character && !flag_alpha) {
                line[line_index] = '\0';
                memcpy(word_list[word_list_index++], line + word_begin,
                        line_index - word_begin + 1);
                flag_character = !flag_character;
            } else if (flag_alpha) {
                line[line_index] = tolower(line[line_index]);
            }
        }
    }
    /* sort the word list first */
    qsort((void*)(word_list), word_list_index, MAX_WORD_WIDTH,
            compare_string);
    /* get distinct word list */
    printf("%s\n", word_list[0]);
    int distinct_index, word_index;
    for (distinct_index = 1, word_index = 1;
            word_index < word_list_index;
            word_index++) {
        while (!strcmp(word_list[distinct_index], word_list[word_index]))
            word_index++;
        printf("%s\n", word_list[word_index]);
        distinct_index = word_index;
    }
    return 0;
}
