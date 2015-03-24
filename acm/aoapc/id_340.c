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
int secret_mask[MAX_LINE_LENGTH];
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
            int strong = 0, weak = 0, pair_index = 0, i_index;
            index = 1;
            while (index < length_code) {
                scanf("%d", guess_code + index);
                index++;
            }
            for (pair_index = 0; pair_index < length_code; pair_index++) {
                if (secret_code[pair_index] == guess_code[pair_index]) {
                    strong++;
                    secret_mask[pair_index] = 0;
                    guess_code[pair_index] = 0;
                } else {
                    secret_mask[pair_index] = 1;
                }
            }
            if (strong != length_code) {
                for (pair_index = 0; pair_index < length_code; pair_index++) {
                    if (guess_code[pair_index]) {
                        for (i_index = 0; i_index < length_code; i_index++) {
                            if (secret_mask[i_index] &&
                                    guess_code[pair_index] ==
                                    secret_code[i_index]) {
                                weak++;
                                secret_mask[i_index] = 0;
                                break;
                            }
                        }
                    }
                }
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
