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

/**
 * @brief calculate string distance by recursion.
 *
 * @param[in]      str_a    string a
 * @param[in]      a_begin  begin index of a(included)
 * @param[in]      a_end    end index of a(included)
 * @param[in]      str_b    string b
 * @param[in]      b_begin  begin index of b(included)
 * @param[in]      b_end    end index of b(included)
 *
 * @return distance between string a and b
 */
TYPE calculate_string_distance(char* str_a, TYPE a_begin, TYPE a_end,
        char* str_b, TYPE b_begin, TYPE b_end)
{
    /// check if index of string a or b exceeds their length.
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
    /// check if the begin value by index of a and b are equal
    if(str_a[a_begin] == str_b[b_begin]) {
        return calculate_string_distance(str_a, a_begin + 1, a_end,
                str_b, b_begin + 1, b_end);
    } else {
        /// get the minimum distance for sub-string by three methods.
        TYPE d_1 = calculate_string_distance(str_a, a_begin + 1, a_end,
                str_b, b_begin, b_end);
        TYPE d_2 = calculate_string_distance(str_a, a_begin, a_end,
                str_b, b_begin + 1, b_end);
        TYPE d_3 = calculate_string_distance(str_a, a_begin + 1, a_end,
                str_b, b_begin + 1, b_end);
        return MIN(MIN(d_1, d_2), d_3) + 1;
    }
}

TYPE calculate_string_distance_by_recursion(char* str_a, TYPE a_length,
        char* str_b, TYPE b_length)
{
    return calculate_string_distance(str_a, 0, a_length - 1,
            str_b, 0, b_length - 1);
}

int main(void)
{
    char* string_a = "d";
    char* string_b = "s";
    TYPE distance = calculate_string_distance_by_recursion(string_a,
            strlen(string_a),
            string_b,
            strlen(string_b));
    printf("string %s and string %s\ndistance: %d similarity: %f\n",
            string_a, string_b, distance, 1 / ((double)distance + 1));
    return EXIT_SUCCESS;
}
