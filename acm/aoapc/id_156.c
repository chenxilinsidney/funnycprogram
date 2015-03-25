/**
 * @file id_152.c
 * @brief AOAPC I 152
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-25
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 81
char line[MAX_LINE_LENGTH];

#define MAX_WORD_WIDTH 21

typedef struct {
    int  flag_annagrams;
    char word_src[MAX_WORD_WIDTH];
    char word_low[MAX_WORD_WIDTH];
}word_struct;

word_struct word_list[1000];

int compare_char(void const* a, void const* b)
{
    return (int)(*((char*)a)) - ((int)*((char*)b));
}

int compare_word(void const* a, void const* b)
{
    char* ptr_a = ((word_struct*)a)->word_low;
    char* ptr_b = ((word_struct*)b)->word_low;
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

int compare_word_ananagrams(void const* a, void const* b)
{
    char* ptr_a = ((word_struct*)a)->word_src;
    char* ptr_b = ((word_struct*)b)->word_src;
    while (*ptr_a != '\n' && *ptr_b != '\n') {
        int flag_case_a = isupper(*ptr_a);
        int flag_case_b = isupper(*ptr_b);
        if (flag_case_a && !flag_case_b)
            return -1;
        else if (!flag_case_a && flag_case_b)
            return 1;
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
    int word_list_index = 0;
    while (gets(line) && line[0] != '#') {
        int line_index = 0;
        int line_length = strlen(line);
        int flag_character = 0;
        int word_begin = 0;
        int word_index;
        for (line_index = 0; line_index <= line_length; line_index++) {
            int flag_alpha = isalpha(line[line_index]);
            if (!flag_character && flag_alpha) {
                word_begin = line_index;
                flag_character = !flag_character;
            } else if (flag_character && !flag_alpha) {
                line[line_index] = '\0';
                /* source word */
                memcpy(word_list[word_list_index].word_src,
                        line + word_begin,
                        line_index - word_begin + 1);
                /* lowcase word */
                word_begin = line_index - word_begin;
                for (word_index = 0; word_index < word_begin; word_index++)
                    word_list[word_list_index].word_low[word_index] =
                        tolower(word_list[word_list_index].
                                word_src[word_index]);
                word_list[word_list_index].word_low[word_index] = '\0';
                /* sort single word */
                qsort((void*)word_list[word_list_index].word_low, word_begin,
                        sizeof(char),
                        compare_char);
                /* flag initialized */
                word_list[word_list_index].flag_annagrams = 0;
                word_list_index++;
                flag_character = !flag_character;
            }
        }
    }
    /* sort word list */
    qsort((void*)word_list, word_list_index, sizeof(word_list[0]),
            compare_word);
    /* get special word list */
    int i, j;
    for (i = 0, j = 0; i < word_list_index;) {
        while (!strcmp(word_list[i].word_low, word_list[j].word_low))
            j++;
        if (j - i == 1) {
            word_list[i].flag_annagrams = 1;
        }
        i = j;
    }
    /* sort special list */
    qsort((void*)word_list, word_list_index, sizeof(word_list[0]),
            compare_word_ananagrams);
    for (i = 0; i < word_list_index; i++) {
        if (word_list[i].flag_annagrams)
            printf("%s\n", word_list[i].word_src);
    }
    return 0;
}
