/**
 * @file id_1584.c
 * @brief AOAPC I 1584
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-23
 */

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 101
char line[MAX_LINE_LENGTH << 1];

int get_min_squence(char* sequence, int sequence_length)
{
    int i = 0, j = 1, k = 0, t;
    while (i < sequence_length && j < sequence_length &&
            k < sequence_length) {
        t = sequence[i + k] - sequence[j + k];
        if (t == 0) {
            k++;
        } else {
            if (t > 0) {
                i += k + 1;
            } else {
                j += k + 1;
            }
            if (i == j)
                j++;
            k = 0;
        }
    }
    return i < j ? i : j;
}
int main()
{
    int num_case;
    scanf("%d", &num_case);
    while (num_case--) {
        scanf("%s", line);
        int line_length = strlen(line);
        int line_index;
        /* get period */
        int period = 1;
        for (period = 1; period <= line_length; period++) {
            if ((line_length % period) != 0)
                continue;
            int flag_period = 1;
            for (line_index = period; line_index < line_length;
                    line_index++) {
                if (line[line_index] != line[line_index % period]) {
                    flag_period = 0;
                    break;
                }
            }
            if (flag_period) {
                break;
            }
        }
        /* get smallest sequence */
        memcpy(line + period, line, period * sizeof(line[0]));
        line[period * 2] = '\0';
        line_index = get_min_squence(line, line_length);
        line_index %= period;
        line[line_index + period] = '\0';
        printf("%s\n", line + line_index);
    }
    return 0;
}
