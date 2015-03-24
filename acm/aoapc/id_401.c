/**
 * @file id_401.c
 * @brief AOAPC I 401
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 21
char line[MAX_LINE_LENGTH];
int line_result[MAX_LINE_LENGTH];

char* list = "A---3--HIL-JM-O---2TUVWXY51SE-Z--8-";

int detect_two_char(const char* list, char a, char b)
{
    char list_a;
    if (isupper(a))
        list_a = list[a -'A'];
    else if (isdigit(a))
        list_a = list[a -'1' + 26];
    if (a == b) {
        if (list_a == b)
            /* mirror and palindrome */
            return 3;
        else
            /* only palindrome */
            return 1;
    } else {
        if (list_a == b)
            /* only mirror */
            return 2;
    }
    /* not mirror and palindrome */
    return 0;
}

int main()
{
    while (scanf("%s", line) != EOF) {
        int line_length = strlen(line);
        int line_result_length = (line_length + 1) / 2;
        int index_begin, index_end;
        for (index_begin = 0, index_end = line_length - 1;
                index_begin <= index_end; index_begin++, index_end--) {
            line_result[index_begin] =
                detect_two_char(list, line[index_begin], line[index_end]);
        }
        int flag_exist[4] = {0};
        for (index_begin = 0; index_begin < line_result_length; index_begin++) {
            flag_exist[line_result[index_begin]]++;
            if (flag_exist[0] || (flag_exist[1] && flag_exist[2]))
                break;
        }
        if (flag_exist[0] || (flag_exist[1] && flag_exist[2]))
            printf("%s -- is not a palindrome.\n", line);
        else if (flag_exist[1])
            printf("%s -- is a regular palindrome.\n", line);
        else if (flag_exist[2])
            printf("%s -- is a mirrored string.\n", line);
        else
            printf("%s -- is a mirrored palindrome.\n", line);
        printf("\n");
    }
    return 0;
}
