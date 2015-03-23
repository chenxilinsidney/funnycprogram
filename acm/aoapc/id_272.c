/**
 * @file id_272.c
 * @brief AOAPC I 272
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>

int main()
{
    int text;
    int flag_even = 1;
    while ((text = getchar()) != EOF) {
        if (text == '\"') {
            printf("%s", flag_even ? "``" : "''");
            flag_even = !flag_even;
        } else {
            putchar(text);
        }
    }
    return 0;
}
