/**
 * @file id_10755.c
 * @brief AOAPC I 10755
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_WIDTH 10
char word_list[10005][MAX_WORD_WIDTH];

int compare_string(void const* a, void const* b)
{
    return strcmp((char*)a, (char*)b);
}

int change_to_number(int a)
{
    if (a < 'Q')
        return (a - 'A') / 3 + 2 + '0';
    else
        return (a - 'A' - 1) / 3 + 2 + '0';
}

int main()
{
    int num_case;
    scanf("%d\n", &num_case);
    while (num_case--) {
        int num_numbers;
        scanf("%d\n", &num_numbers);
        int word_list_index = 0;
        while (word_list_index < num_numbers) {
            int char_index = 0;
            int character;
            while ((character = getchar()) != '\n') {
                if (isdigit(character)) {
                    word_list[word_list_index][char_index] = character;
                    char_index++;
                    if (char_index == 3)
                        word_list[word_list_index][char_index++] = '-';
                } else if (isupper(character)) {
                    character = change_to_number(character);
                    word_list[word_list_index][char_index] = character;
                    char_index++;
                    if (char_index == 3)
                        word_list[word_list_index][char_index++] = '-';
                }
            }
            if (char_index != 8)
                printf("char_index = %d\n", char_index);
            word_list[word_list_index][char_index] = '\0';
            word_list_index++;
        }
        qsort(word_list, word_list_index, MAX_WORD_WIDTH, compare_string);
        /* get distinct word list */
        int distinct_index, word_index;
        int flag_repeat = 0;
        for (distinct_index = 0, word_index = 0;
                word_index < word_list_index;
                word_index++) {
            while (!strcmp(word_list[distinct_index], word_list[word_index]))
                word_index++;
            if (word_index - distinct_index != 1) {
                printf("%s %d\n", word_list[word_index - 1],
                        word_index - distinct_index);
                flag_repeat = 1;
            }
            distinct_index = word_index;
        }
        if (!flag_repeat)
            printf("No duplicates.\n");
        if (num_case)
            printf("\n");
    }
    return 0;
}
