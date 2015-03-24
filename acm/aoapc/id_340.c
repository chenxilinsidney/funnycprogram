/**
 * @file id_340.c
 * @brief AOAPC I 340
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>

#define MAX_LINE_LENGTH 1001
int secret_code[MAX_LINE_LENGTH];
int guess_code[MAX_LINE_LENGTH];

int main()
{
    int length_code;
    int num_case = 0;
    while (scanf("%d", &length_code) && length_code != 0) {
        num_case++;
        printf("Game %d:\n", num_case);
        int index = 0;
        while (index < length_code) {
            scanf("%d", secret_code + index);
            index++;
        }
        while (scanf("%d", guess_code) && guess_code[0] != 0) {
            int strong = 0, weak = 0;
            index = 1;
            while (index < length_code) {
                scanf("%d", guess_code + index);
                index++;
            }
            int guess_count[10] = {0};
            int secret_count[10] = {0};
            for (index = 0; index < length_code; index++) {
                if (secret_code[index] == guess_code[index]) {
                    strong++;
                } else {
                    guess_count[guess_code[index]]++;
                    secret_count[secret_code[index]]++;
                }
            }
            for (index = 1; index < 10; index++) {
                weak += guess_count[index] >= secret_count[index] ?
                    secret_count[index] : guess_count[index];
            }
            printf("    (%d,%d)\n", strong, weak);
        }
        index = 1;
        while (index++ < length_code) {
            scanf("%*d");
        }
    }
    return 0;
}
