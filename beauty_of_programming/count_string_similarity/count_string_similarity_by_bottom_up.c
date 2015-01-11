/**
 * @file count_string_similarity_by_bottom_up.c
 * @brief count the similarity between two strings by dynamic programming
 * with bottom-up method.
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

TYPE calculate_string_distance_by_bottom_up(char* str_a, TYPE a_length,
        char* str_b, TYPE b_length)
{
    assert(a_length >= 1 && b_length >= 1);
    /// initialize cache first
    TYPE* memoized_cache = SMALLOC((a_length + 1) * (b_length + 1), TYPE); 
    TYPE* cache_offset;
    TYPE i, j;
    /// set edge elements first to reduce calculation in program.
    for(i = 0; i < b_length + 1; i++)
        memoized_cache[i] = i;
    for(i = 1; i < a_length + 1; i++)
        memoized_cache[i * (b_length + 1)] = i;
    /// get distance by bottom-up method
    /// i, j to index string from end to begin from the string now
    for (i = 0; i < a_length; i++) {
        for (j = 0; j < b_length; j++) {
            /// save offet pointer
            cache_offset = memoized_cache + (b_length + 1) * i + j;
            if (str_a[i] == str_b[j]) {
                /// use old distance if same word
                cache_offset[b_length + 1 + 1] =
                    cache_offset[0];
            } else {
                /// use minimum distance if not same word
                cache_offset[b_length + 1 + 1] = MIN(
                        MIN(cache_offset[b_length + 1],
                            cache_offset[1]),
                        cache_offset[0]) + 1;
            }
        }
    }
    /// get final distance
    TYPE distance = memoized_cache[a_length * (b_length + 1) + b_length];
    /// free memory
    SFREE(&memoized_cache);
    return distance;
}

int main(void)
{
    char* string_a = "ddsag";
    char* string_b = "sdsg";
    TYPE distance = calculate_string_distance_by_bottom_up(string_a,
            strlen(string_a),
            string_b,
            strlen(string_b));
    printf("string %s and string %s\ndistance: %d similarity: %f\n",
            string_a, string_b, distance, 1 / ((double)distance + 1));
    return EXIT_SUCCESS;
}
