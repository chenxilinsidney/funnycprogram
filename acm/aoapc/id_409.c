/**
 * @file id_409.c
 * @brief AOAPC I 409
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keyword_list[20][21];
char keyword_list_length[20];

#define MAX_LINE_LENGTH 71
char line[20][MAX_LINE_LENGTH];

int main()
{
    int index_case = 0;
    int K, E;
    while (scanf("%d%d", &K, &E) != EOF) {
        index_case++;
        /* get keyword list */
        int K_index = 0;
        while (K_index < K) {
            scanf("%s\n", keyword_list[K_index]);
            keyword_list_length[K_index] = strlen(keyword_list[K_index]);
            K_index++;
        }
        int num_incidences[20] = {0};
        /* get excuses list */
        int E_index = 0;
        while (E_index < E) {
            gets(line[E_index]);
            int line_length = strlen(line[E_index]);
            int line_index;
            int word_begin = 0, word_end = 0;
            int flag = 0;
            /* match two word */
            for (line_index = 0; line_index <= line_length; line_index++) {
                char temp = line[E_index][line_index];
                if (!flag && isalpha(temp)) {
                    word_begin = line_index;
                    flag = !flag;
                } else if (flag && !(isalpha(temp))) {
                    word_end = line_index - 1;
                    int word_length = word_end - word_begin + 1;
                    for (K_index = 0; K_index < K; K_index++) {
                        if (keyword_list_length[K_index] != word_length) {
                            continue;
                        } else {
                            int flag_match = 1;
                            int key_index = 0;
                            while (word_begin <= word_end) {
                                if (tolower(line[E_index][word_begin]) !=
                                        keyword_list[K_index][key_index++]) {
                                    flag_match = 0;
                                    break;
                                }
                                word_begin++;
                            }
                            if (flag_match) {
                                num_incidences[E_index]++;
                                break;
                            }
                        }
                    }
                    flag = !flag;
                }
            }
            E_index++;
        }
        /* get worst excuse */
        int worst_number = 0;
        for (E_index = 0; E_index < E; E_index++) {
            if (num_incidences[E_index] > worst_number)
                worst_number = num_incidences[E_index];
        }
        printf("Excuse Set #%d\n", index_case);
        for (E_index = 0; E_index < E; E_index++) {
            if (num_incidences[E_index] == worst_number)
                printf("%s\n", line[E_index]);
        }
        printf("\n");
    }
    return 0;
}
