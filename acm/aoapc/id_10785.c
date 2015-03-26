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

char line_vowel[255];
char line_consonant[255];

int compare_special_a(void const* a, void const* b)
{
    int char_a = ((char*)a)[1];
    int char_b = ((char*)b)[1];
    return char_a - char_b;
}

int compare_special_b(void const* a, void const* b)
{
    int char_a = ((char*)a)[0];
    int char_b = ((char*)b)[0];
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
#ifndef ONLINE_JUDGE
        printf("length = %d\n", length);
#endif
        int count_even = length / 2;
        int count_odd = length - count_even;
        int temp_index = 0;
        int vowel[5] = {0};
        int consonant[21] = {0};
        while (count_even > 5) {
            consonant[temp_index] = 5;
#ifndef ONLINE_JUDGE
            if (temp_index >= 21)
                printf("error even = %d\n", temp_index);
#endif
            count_even -= 5;
            temp_index++;
        }
        consonant[temp_index] = count_even;
        temp_index = 0;
        while (count_odd > 21) {
            vowel[temp_index] = 21;
#ifndef ONLINE_JUDGE
            if (temp_index >= 21)
                printf("error odd = %d\n", temp_index);
#endif
            count_odd -= 21;
            temp_index++;
        }
        vowel[temp_index] = count_odd;
        memset(line_consonant, 0, (length + 1) * sizeof(char));
        int line_index = 1;
        for (temp_index = 0; temp_index < 21; temp_index++) {
            if (consonant[temp_index] != 0) {
                while (consonant[temp_index]--) {
                    line_consonant[line_index] = consonant_list[temp_index];
                    line_index += 2;
                }
            } else {
                break;
            }
        }
        qsort(line_consonant, length / 2,
                sizeof(line_consonant[0]) * 2, compare_special_a);
        memset(line_vowel, 0, (length + 1) * sizeof(char));
        line_index = 0;
        for (temp_index = 0; temp_index < 5; temp_index++) {
            if (vowel[temp_index] != 0) {
                while (vowel[temp_index]--) {
                    line_vowel[line_index] = vowel_list[temp_index];
                    line_index += 2;
                }
            } else {
                break;
            }
        }
        qsort(line_vowel, length - length / 2,
                sizeof(line_vowel[0]) * 2, compare_special_b);
        for (line_index = 0; line_index < length; line_index++) {
            if (line_index & 0x1) 
                putchar(line_consonant[line_index]);
            else
                putchar(line_vowel[line_index]);
        }
        putchar('\n');
    }
    return 0;
}
