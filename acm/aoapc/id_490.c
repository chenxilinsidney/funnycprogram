/**
 * @file id_490.c
 * @brief AOAPC I 490
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char data[100][100];
int sentence_length[100];

int main()
{
    int num_sentence = 0;
    int max_length = 0;
    while (gets(*(data + num_sentence)) != NULL) {
        sentence_length[num_sentence] = strlen(*(data + num_sentence));
        if (max_length < sentence_length[num_sentence])
            max_length = sentence_length[num_sentence];
        num_sentence++;
    }
    int i, j;
    int right_most_setence = 0;
    for (i = 0; i < max_length; i++) {
        for (j = num_sentence - 1; j >= right_most_setence; j--) {
            if (i < sentence_length[j])
                printf("%c", data[j][i]);
            else if (j == right_most_setence)
                right_most_setence++;
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
