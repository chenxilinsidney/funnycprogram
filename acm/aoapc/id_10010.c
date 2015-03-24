/**
 * @file id_10010.c
 * @brief AOAPC I 10010
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char grid_letter[50][50];
char word[51];
int main()
{
    int num_case, num_word;
    scanf("%d", &num_case);
    while (num_case--) {
        int m, n;
        scanf("%d%d\n", &m, &n);
        int m_index, n_index;
        for (m_index = 0; m_index < m; m_index++) {
            for (n_index = 0; n_index < n; n_index++) {
                grid_letter[m_index][n_index] = tolower(getchar());
            }
            getchar();
        }
        scanf("%d\n", &num_word);
        while (num_word--) {
            scanf("%s", word);
            int word_length = strlen(word);
            for (m_index = 0; m_index < word_length; m_index++) {
                word[m_index] = tolower(word[m_index]);
            }
            /* get match word position of the first letter */
            int first_m = 0, first_n = 0, flag_found = 0, first_index;
            for (m_index = 0; m_index < m && !flag_found; m_index++) {
                for (n_index = 0; n_index < n && !flag_found; n_index++) {
                    flag_found = 0;
                    if (n_index <= n - word_length && !flag_found) {
                        /* match from left to right*/
                        flag_found = 1;
                        for (first_index = 0; first_index < word_length;
                                first_index++) {
                            if (word[first_index] !=
                                    grid_letter[m_index]
                                    [n_index + first_index]) {
                                flag_found = 0;
                                break;
                            }
                        }
                    }
                    if (n_index >= word_length - 1 && !flag_found) {
                        /* match from right to left*/
                        flag_found = 1;
                        for (first_index = 0; first_index < word_length;
                                first_index++) {
                            if (word[first_index] !=
                                    grid_letter[m_index]
                                    [n_index - first_index]) {
                                flag_found = 0;
                                break;
                            }
                        }
                    }
                    if (m_index <= m - word_length && !flag_found) {
                        /* match from top to bottom*/
                        flag_found = 1;
                        for (first_index = 0; first_index < word_length;
                                first_index++) {
                            if (word[first_index] !=
                                    grid_letter[m_index + first_index]
                                    [n_index]) {
                                flag_found = 0;
                                break;
                            }
                        }
                    }
                    if (m_index >= word_length - 1 && !flag_found) {
                        /* match from bottom to top*/
                        flag_found = 1;
                        for (first_index = 0; first_index < word_length;
                                first_index++) {
                            if (word[first_index] !=
                                    grid_letter[m_index - first_index]
                                    [n_index]) {
                                flag_found = 0;
                                break;
                            }
                        }
                    }
                    if (n_index <= n - word_length &&
                            m_index <= m - word_length && !flag_found) {
                        /* match from left-top to right-bottom*/
                        flag_found = 1;
                        for (first_index = 0; first_index < word_length;
                                first_index++) {
                            if (word[first_index] !=
                                    grid_letter[m_index + first_index]
                                    [n_index + first_index]) {
                                flag_found = 0;
                                break;
                            }
                        }
                    }
                    if (n_index >= word_length - 1 &&
                            m_index >= word_length - 1 && !flag_found) {
                        /* match from right-bottom to left-top*/
                        flag_found = 1;
                        for (first_index = 0; first_index < word_length;
                                first_index++) {
                            if (word[first_index] !=
                                    grid_letter[m_index - first_index]
                                    [n_index - first_index]) {
                                flag_found = 0;
                                break;
                            }
                        }
                    }
                    if (n_index <= n - word_length &&
                            m_index >= word_length - 1 && !flag_found) {
                        /* match from left-bottom to right-top*/
                        flag_found = 1;
                        for (first_index = 0; first_index < word_length;
                                first_index++) {
                            if (word[first_index] !=
                                    grid_letter[m_index - first_index]
                                    [n_index + first_index]) {
                                flag_found = 0;
                                break;
                            }
                        }
                    }
                    if (m_index <= m - word_length &&
                            n_index >= word_length - 1 && !flag_found) {
                        /* match from right-top to left-bottom*/
                        flag_found = 1;
                        for (first_index = 0; first_index < word_length;
                                first_index++) {
                            if (word[first_index] !=
                                    grid_letter[m_index + first_index]
                                    [n_index - first_index]) {
                                flag_found = 0;
                                break;
                            }
                        }
                    }
                    if (flag_found == 1) {
                        first_m = m_index + 1;
                        first_n = n_index + 1;
                        break;
                    }
                }
            }
            printf("%d %d\n", first_m, first_n);
        }
        if (num_case)
            printf("\n");
    }
    return 0;
}
