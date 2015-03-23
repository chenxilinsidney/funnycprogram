/**
 * @file id_489.c
 * @brief AOAPC I 489
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>
#include <string.h>

char line_solution[1024];
char line_guess[1024];

#define MAX_STROKES 7

int main()
{
    int game_round;
    while (scanf("%d\n", &game_round) && game_round != -1) {
        printf("Round %d\n", game_round);
        gets(line_solution);
        int length_solution = strlen(line_solution);
        gets(line_guess);
        int length_guess = strlen(line_guess);
        int index, index_solution;
        int wrong_guess = 0;
        int win_lose = 0;
        for (index = 0; index < length_guess; index++) {
            int flag_exist = 0;
            for (index_solution = 0; index_solution < length_solution;
                    index_solution++) {
                if (line_guess[index] == line_solution[index_solution]) {
                    flag_exist = 1;
                    line_solution[index_solution] = ' ';
                }
            }
            int right_count = 0;
            for (index_solution = 0; index_solution < length_solution;
                    index_solution++) {
                if (line_solution[index_solution] == ' ')
                    right_count++;
            }
            if (right_count == length_solution) {
                printf("You win.\n");
                win_lose = 1;
                break;
            }
            if (!flag_exist)
                wrong_guess++;
            if (wrong_guess >= MAX_STROKES) {
                printf("You lose.\n");
                win_lose = 1;
                break;
            }
        }
        if (!win_lose) {
            printf("You chickened out.\n");
        }
    }
    return 0;
}
