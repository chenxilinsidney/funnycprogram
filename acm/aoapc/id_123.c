
/**
 * @file id_123.c
 * @brief AOAPC I 123
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef ONLINE_JUDGE
// #define ONLINE_JUDGE
#endif

#define MAX_WORD_IGNORE_WIDTH 15
char word_ignore_list[55][MAX_WORD_IGNORE_WIDTH];

#define MAX_TITLE_WIDTH 1025
char title_list[205][MAX_TITLE_WIDTH];

typedef struct {
    char word[MAX_WORD_IGNORE_WIDTH];
    int  title_id;
    int  word_index_begin;
    int  word_index_end;
} KWIC_struct;

KWIC_struct KWIC_list[10001];

int compare_string(void const* a, void const* b)
{
    return strcmp((char*)a, (char*)b);
}

int compare_struct(void const* a, void const* b)
{
    /* check if different word first */
    int str = strcmp(((KWIC_struct*)a)->word, ((KWIC_struct*)b)->word);
    if (str != 0)
        return str;
    /* check if different id */
    int id = ((KWIC_struct*)a)->title_id - ((KWIC_struct*)b)->title_id;
    if (id != 0)
        return id;
    /* check if previous postion */
    return ((KWIC_struct*)a)->word_index_begin -
        ((KWIC_struct*)b)->word_index_begin;
}

void string_to_upper(char* str)
{
    while (*str != '\0') {
        *str = toupper(*str);
        str++;
    }
}

void string_to_lower(char* str)
{
    while (*str != '\0') {
        *str = tolower(*str);
        str++;
    }
}

int main()
{
    /* get word ignore list */
    int word_ignore_length = 0;
    while (scanf("%s\n", word_ignore_list[word_ignore_length]) &&
            strcmp(word_ignore_list[word_ignore_length], "::"))
        word_ignore_length++;
#ifndef ONLINE_JUDGE
    printf("w = %d\n", word_ignore_length);
#endif
    /* sort word ignore list */
    qsort(word_ignore_list, word_ignore_length, MAX_WORD_IGNORE_WIDTH,
            compare_string);
    /* get title list */
    int title_list_length = 0;
    while (fgets(title_list[title_list_length], MAX_TITLE_WIDTH, stdin))
        title_list_length++;
#ifndef ONLINE_JUDGE
    printf("t = %d\n", title_list_length);
#endif
    /* title list to lower case */
    int title_list_index;
    for (title_list_index = 0; title_list_index < title_list_length;
            title_list_index++)
        string_to_lower(title_list[title_list_index]);
    /* get KWIC list */
    int KWIC_list_length = 0;
    for (title_list_index = 0; title_list_index < title_list_length;
            title_list_index++) {
        int char_length = strlen(title_list[title_list_index]);
        int char_index = 0;
        int char_flag = 0;
        int word_begin = 0, word_length = 0;
        char word_temp[MAX_WORD_IGNORE_WIDTH];
        int flag_alpha;
        char* title_ptr = title_list[title_list_index];
        if (title_ptr[char_length - 1] == '\n') {
            title_ptr[char_length - 1] = '\0';
            char_length--;
#ifndef ONLINE_JUDGE
                    printf("char_length = %d\n", char_length);
#endif
        }
#ifndef ONLINE_JUDGE
                    printf("title = %s\n", title_ptr);
#endif
        for (char_index = 0; char_index <= char_length; char_index++) {
            flag_alpha = isalpha(title_ptr[char_index]);
            if (!char_flag && flag_alpha) {
                word_begin = char_index;
                char_flag = !char_flag;
            } else if (char_flag && !flag_alpha) {
                /* get and search the word */
                word_length = char_index - word_begin;
                memcpy(word_temp, title_ptr + word_begin, word_length);
                word_temp[word_length] = '\0';
                if (!bsearch(word_temp, word_ignore_list, word_ignore_length,
                        MAX_WORD_IGNORE_WIDTH, compare_string)) {
                    /* refresh KWIC list */
                    string_to_upper(word_temp);
#ifndef ONLINE_JUDGE
                    printf("ssskwic = %s\n", word_temp);
                    printf("kwic = %d\n", KWIC_list_length);
#endif
                    memcpy(KWIC_list[KWIC_list_length].word,
                            word_temp, word_length + 1);
                    KWIC_list[KWIC_list_length].word_index_begin = word_begin;
                    KWIC_list[KWIC_list_length].word_index_end = char_index - 1;
                    KWIC_list[KWIC_list_length].title_id = title_list_index;
                    KWIC_list_length++;
                }
                char_flag = !char_flag;
            }
        }
    }
#ifndef ONLINE_JUDGE
    printf("kwic = %d\n", KWIC_list_length);
#endif
    /* sort KWIC list */
    qsort(KWIC_list, KWIC_list_length, sizeof(KWIC_list[0]), compare_struct);
    /* output title by KWIC list */
    int KWIC_list_index = 0;
    for (KWIC_list_index = 0; KWIC_list_index < KWIC_list_length;
            KWIC_list_index++) {
        char* title_ptr = title_list[KWIC_list[KWIC_list_index].title_id];
        int char_index = 0;
        int char_length = strlen(title_ptr);
        int word_index_begin = KWIC_list[KWIC_list_index].word_index_begin;
        int word_index_end = KWIC_list[KWIC_list_index].word_index_end;
        for (char_index = 0; char_index < word_index_begin; char_index++) {
            putchar(title_ptr[char_index]);
        }
        printf("%s", KWIC_list[KWIC_list_index].word);
        for (char_index = word_index_end + 1;
                char_index < char_length; char_index++) {
            putchar(title_ptr[char_index]);
        }
        putchar('\n');
    }
    return 0;
}
