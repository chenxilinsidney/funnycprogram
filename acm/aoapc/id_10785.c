/**
 * @file id_10785.c
 * @brief AOAPC I 10785
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* vowel_list = "AUEOI";
char* consonant_list = "JSBKTCLDMVNWFXGPYHQZR";

char line[255];

int compare_special(void const* a, void const* b)
{
    char char_a = ((char*)a)[1];
    char char_b = ((char*)b)[1];
    return char_a - char_b;
}

int main()
{
    int num_case;
    int index_case = 0;
    scanf("%d", &num_case);
    while (num_case--) {
        index_case++;
        printf("Case %d: ", index_case);
        int length = 0;
        scanf("%d", &length);
        int count_even = length / 2;
        int count_odd = length - count_even;
        int temp_index = 0;
        int vowel[5] = {0};
        int consonant[21] = {0};
        while (count_even > 5) {
            consonant[temp_index] = 5;
            count_even -= 5;
            temp_index++;
        }
        consonant[temp_index] = count_even;
        temp_index = 0;
        while (count_odd > 21) {
            vowel[temp_index] = 21;
            count_odd -= 21;
            temp_index++;
        }
        vowel[temp_index] = count_odd;
        int line_index = 0;
        for (temp_index = 0; temp_index < 5; temp_index++) {
            if (vowel[temp_index] != 0) {
                while (vowel[temp_index]--) {
                    line[line_index] = vowel_list[temp_index];
                    line_index += 2;
                }
            } else {
                break;
            }
        }
        line_index = 1;
        for (temp_index = 0; temp_index < 21; temp_index++) {
            if (consonant[temp_index] != 0) {
                while (consonant[temp_index]--) {
                    line[line_index] = consonant_list[temp_index];
                    line_index += 2;
                }
            } else {
                break;
            }
        }
        line[length] = '\0';
        qsort(line, length / 2, sizeof(line[0]) * 2, compare_special);
        printf("%s\n", line);
    }
    return 0;
}
