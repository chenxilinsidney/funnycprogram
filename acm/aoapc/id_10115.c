/**
 * @file id_10114.c
 * @brief AOAPC I 10114
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
char line[MAX_LINE_LENGTH];

char rule_list[10][2][81];

int find_and_replace(char* src, int src_length,
        char* find, int find_length,
        char* replace, int replace_length)
{
    int src_index;
    for (src_index = 0; src_index <= src_length - find_length;
            src_index++) {
        /* find the string */
        int find_index;
        int find_flag = 1;
        for (find_index = 0; find_index < find_length; find_index++) {
            if (src[find_index + src_index] != find[find_index]) {
                find_flag = 0;
                break;
            }
        }
        if (find_flag) {
            if (find_length >= replace_length) {
                /* replace first */
                memcpy(src + src_index, replace, replace_length);
                int find_index = src_index + replace_length;
                int replace_index = src_index + find_length;
                /* move src second */
                while (replace_index <= src_length) {
                    src[find_index] = src[replace_index]; 
                    find_index++;
                    replace_index++;
                }
                return src_length - find_length + replace_length;
            } else {
                /* move src first */
                int replace_index = src_length + replace_length
                    - find_length;
                int error = replace_length - find_length;
                int length = src_length - src_index - find_length + 1;
                while (length--) {
                    src[replace_index] = src[replace_index - error];
                    replace_index--;
                }
                /* replace second */
                memcpy(src + src_index, replace, replace_length);
                return src_length - find_length + replace_length;
            }
        }
    }
    return 0;
}

int main()
{
    int num_rules;
    while (scanf("%d\n", &num_rules) && num_rules != 0) {
        int rule_index = 0;
        while (rule_index < num_rules) {
            gets(rule_list[rule_index][0]);
            gets(rule_list[rule_index][1]);
            rule_index++;
        }
        gets(line);
        rule_index = 0;
        while (rule_index < num_rules) {
            /* replace by rule */
            int line_index = 0;
            int rule_length = strlen(rule_list[rule_index][0]);
            int line_length = strlen(line);
            while (line_index <= line_length - rule_length) {
                int flag;
                int find_length = strlen(rule_list[rule_index][0]);
                int replace_length = strlen(rule_list[rule_index][1]);
                if ((flag = find_and_replace(line, line_length,
                            rule_list[rule_index][0], find_length,
                            rule_list[rule_index][1], replace_length)) != 0) {
                    line_length = flag;
                    line_index = 0;
                } else {
                    line_index++;
                }
            }
            rule_index++;
        }
        printf("%s\n", line);
    }
    return 0;
}
