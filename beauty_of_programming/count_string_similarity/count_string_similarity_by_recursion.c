/**
 * @file count_string_similarity_v1.c
 * @brief count the similarity between two strings by recursion.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-31
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// min macro, warning: can not use with '++' and '--' operator
#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif
typedef int TYPE;

TYPE calculate_string_distance(char* str_a, TYPE a_begin, TYPE a_end,
        char* str_b, TYPE b_begin, TYPE b_end)
{
    if(a_begin > a_end) {
        if(b_begin > b_end)
            return 0;
        else
            return b_end - b_begin + 1;
    }
    if(b_begin > b_end) {
        if(a_begin > a_end)
            return 0;
        else
            return a_end - a_begin + 1;
    }
    if(str_a[a_begin] == str_b[b_begin]) {
        return calculate_string_distance(str_a, a_begin + 1, a_end,
                str_b, b_begin + 1, b_end);
    } else {
        TYPE d_1 = calculate_string_distance(str_a, a_begin + 1, a_end,
                str_b, b_begin, b_end);
        TYPE d_2 = calculate_string_distance(str_a, a_begin, a_end,
                str_b, b_begin + 1, b_end);
        TYPE d_3 = calculate_string_distance(str_a, a_begin + 1, a_end,
                str_b, b_begin + 1, b_end);
        return MIN(MIN(d_1, d_2), d_3) + 1;
    }
}

int main(void)
{
    char* string_a = "dsfetrtegh";
    char* string_b = "sdfgerwefe";
    TYPE distance = calculate_string_distance(string_a, 0, strlen(string_a),
            string_b, 0, strlen(string_b));
    printf("string %s and string %s\ndistance: %d similarity: %f\n",
            string_a, string_b, distance, 1 / ((double)distance + 1));
    return EXIT_SUCCESS;
}
