/**
 * @file id_644.c
 * @brief AOAPC I 644
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1025
char line[MAX_LINE_LENGTH];
char code_list[9][11];
int code_length[11];

int main()
{
    int word_list_index = 0;
    int num_case = 1;
    char code_temp[11];
    while (scanf("%s", code_list[word_list_index]) != EOF) {
        code_length[word_list_index] = strlen(code_list[word_list_index]);
        word_list_index++;
        if (code_list[word_list_index - 1][0] == '9') {
            word_list_index--;
            int index_a, index_b;
            int flag_result = 0;
            for (index_a = 0;
                    index_a < word_list_index && !flag_result;
                    index_a++) {
                int length_a = code_length[index_a];
                for (index_b = index_a + 1;
                        index_b < word_list_index && !flag_result;
                        index_b++) {
                    int length_b = code_length[index_b];
                    if (length_a <= code_length[index_b]) {
                        memcpy(code_temp, code_list[index_b],
                                length_a);
                        code_temp[length_a] = '\0';
                        if (!strcmp(code_temp, code_list[index_a])) {
                            printf("Set %d is not immediately decodable\n",
                                    num_case);
                            flag_result = 1;
                            break;
                        }
                    } else {
                        memcpy(code_temp, code_list[index_a],
                                length_b);
                        code_temp[length_b] = '\0';
                        if (!strcmp(code_temp, code_list[index_b])) {
                            printf("Set %d is not immediately decodable\n",
                                    num_case);
                            flag_result = 1;
                            break;
                        }
                    }
                }
            }
            if (!flag_result)
                printf("Set %d is immediately decodable\n", num_case);

            word_list_index = 0;
            num_case++;
        }
    }
    return 0;
}
