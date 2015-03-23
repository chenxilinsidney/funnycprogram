/**
 * @file id_10082.c
 * @brief AOAPC I 10082
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>

char* list = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    int text;
    while ((text = getchar()) != EOF) {
        int index = 1;
        while (list[index] != '\0') {
            if (text == list[index]) {
                text = list[index - 1];
                break;
            }
            index++;
        }
        putchar(text);
    }
    return 0;
}
