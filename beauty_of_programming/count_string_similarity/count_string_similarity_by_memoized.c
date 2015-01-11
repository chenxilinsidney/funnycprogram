/**
 * @file count_string_similarity_by_memoized.c
 * @brief count the similarity between two strings by dynamic programming
 * with top-down with memoization method.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-31
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
// #define NDEBUG
#include <assert.h>

#include "memory.h"
// #define NDBG_PRINT
#include "debug_print.h"

// min macro, warning: can not use with '++' and '--' operator
#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

typedef int TYPE;

/**
 * @brief calculate string distance by dynamic programming.
 *
 * @param[in]      str_a    string a
 * @param[in]      a_begin  begin index of a(included)
 * @param[in]      a_end    end index of a(included)
 * @param[in]      str_b    string b
 * @param[in]      b_begin  begin index of b(included)
 * @param[in]      b_end    end index of b(included)
 * @param[in]      cache    save sub-problem result by memoization.
 * @param[in]      cache_width width of cache for two dimensional array.
 *
 * @return distance between string a and b
 */
TYPE calculate_string_distance(char* str_a, TYPE a_begin, TYPE a_end,
        char* str_b, TYPE b_begin, TYPE b_end, TYPE* cache, TYPE cache_width)
{
    DEBUG_PRINT_STRING("In Recursion\n");
    DEBUG_PRINT_VALUE("%d", a_begin);
    DEBUG_PRINT_VALUE("%d", b_begin);
    /// try to get distance from cache
    TYPE value_temp;
    if((value_temp = cache[a_begin * cache_width + b_begin]) > INT_MIN) {
        DEBUG_PRINT_STRING("get distance from cache!\n");
        DEBUG_PRINT_VALUE("%d", a_begin);
        DEBUG_PRINT_VALUE("%d", b_begin);
        DEBUG_PRINT_STRING("Out of Recursion\n");
        return value_temp;
    }
    /// check if the begin value by index of a and b are equal
    if(str_a[a_begin] == str_b[b_begin]) {
        DEBUG_PRINT_STRING("have same word\n");
        DEBUG_PRINT_STRING("set distance to cache!\n");
        DEBUG_PRINT_VALUE("%d", a_begin);
        DEBUG_PRINT_VALUE("%d", b_begin);
        DEBUG_PRINT_STRING("Out of Recursion\n");
        return cache[a_begin * cache_width + b_begin] =
            calculate_string_distance(str_a, a_begin + 1, a_end,
                str_b, b_begin + 1, b_end, cache, cache_width);
    } else {
        /// get the minimum distance for sub-string by three methods.
        TYPE d_1 = calculate_string_distance(str_a, a_begin + 1, a_end,
                str_b, b_begin, b_end, cache, cache_width);
        TYPE d_2 = calculate_string_distance(str_a, a_begin, a_end,
                str_b, b_begin + 1, b_end, cache, cache_width);
        TYPE d_3 = calculate_string_distance(str_a, a_begin + 1, a_end,
                str_b, b_begin + 1, b_end, cache, cache_width);
        /// set distance to cache
        DEBUG_PRINT_STRING("set distance to cache!\n");
        DEBUG_PRINT_VALUE("%d", a_begin);
        DEBUG_PRINT_VALUE("%d", b_begin);
        DEBUG_PRINT_STRING("Out of Recursion\n");
        return cache[a_begin * cache_width + b_begin] =
            MIN(MIN(d_1, d_2), d_3) + 1;
    }
}

TYPE calculate_string_distance_by_memoized(char* str_a, TYPE a_length,
        char* str_b, TYPE b_length)
{
    assert(a_length >= 1 && b_length >= 1);
    /// initialize cache first
    TYPE memoized_length = (a_length + 1) * (b_length + 1);
    TYPE* memoized_cache = SMALLOC(memoized_length, TYPE); 
    TYPE i;
    for(i = 0; i < memoized_length; i++)
        memoized_cache[i] = INT_MIN;
    /// set edge elements first to reduce calculation in program.
    for(i = 0; i < b_length + 1; i++)
        memoized_cache[a_length * (b_length + 1) + i] = b_length - i;
    for(i = 0; i < a_length + 1; i++)
        memoized_cache[i * (b_length + 1) + b_length] = a_length - i;
    /// get distance by memoized method
    TYPE value = calculate_string_distance(str_a, 0, a_length - 1,
            str_b, 0, b_length - 1, memoized_cache, b_length + 1);
    /// free memory
    SFREE(&memoized_cache);
    return value;
}

int main(void)
{
    char* string_a = "ddsag";
    char* string_b = "sdsg";
    TYPE distance = calculate_string_distance_by_memoized(string_a,
            strlen(string_a),
            string_b,
            strlen(string_b));
    printf("string %s and string %s\ndistance: %d similarity: %f\n",
            string_a, string_b, distance, 1 / ((double)distance + 1));
    return EXIT_SUCCESS;
}
