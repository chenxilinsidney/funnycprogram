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

#define MAX_WORD_WIDTH 76
char word_list[2000][MAX_WORD_WIDTH];

int compare_string(void const* a, void const* b)
{
    char* ptr_a = (char*)a;
    char* ptr_b = (char*)b;
    while (*ptr_a != '\n' && *ptr_b != '\n') {
        if (*ptr_a < *ptr_b) {
            return -1;
        } else if (*ptr_a > *ptr_b) {
            return 1;
        }
        ptr_a++;
        ptr_b++;
    }
    if (*ptr_a == '\0')
        return -1;
    else
        return 1;
}

int main()
{
    int num_line = 0;
    scanf("%d\n", &num_line);
    int word_list_index = 0;
    while (num_line--) {
        gets(line);
        sscanf(line, "%s", word_list[word_list_index++]);
    }
    /* sort the word list first */
    qsort((void*)(word_list), word_list_index, MAX_WORD_WIDTH,
            compare_string);
    /* get distinct word list */
    int distinct_index, word_index;
    for (distinct_index = 0, word_index = 0;
            word_index < word_list_index;
            word_index++) {
        while (!strcmp(word_list[distinct_index], word_list[word_index]))
            word_index++;
        printf("%s %d\n", word_list[word_index - 1],
                word_index - distinct_index);
        distinct_index = word_index;
    }
    return 0;
}
