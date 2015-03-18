/**
 * @file id_1003.c
 * @brief HDOJ Problem ID 1003.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-18
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#ifndef ONLINE_JUDGE
#define ONLINE_JUDGE
#endif

int get_max_subarray(int* array_data, int array_length,
        int* output_index_begin,
        int* output_index_end)
{
    assert(array_length > 1 && array_data != NULL &&
            output_index_begin != NULL && output_index_end != NULL);
    int sum_right = 0;
    *output_index_begin = 1;
    *output_index_end = 1;
    int sum_best = array_data[0];
    int array_index;
    for (array_index = 0; array_index < array_length; array_index++) {
        sum_right += array_data[array_index];
        if (sum_right > sum_best) {
            sum_best = sum_right;
            *output_index_end = array_index + 1;
        }
        if (sum_right < 0) {
            sum_right = 0;
            *output_index_begin = array_index + 2;
        }
    }
    return sum_best;
}

int main()
{
    int line_count, line_index = 1;
    scanf("%d", &line_count);
    int sequence_length, sequence_index, sequence_data[100000];
    while (line_index <= line_count) {
        scanf("%d", &sequence_length);
        sequence_index = 0;
        while (sequence_index < sequence_length) {
            scanf("%d", sequence_data + sequence_index);
            sequence_index++;
        }
        printf("Case %d:\n", line_index);
#ifndef ONLINE_JUDGE
        printf("%d", sequence_length);
        int index = 0;
        for (index = 0; index < sequence_length; index++)
            printf(" %d", sequence_data[index]);
        printf("\n");
#endif
        int sum, index_begin, index_end;
        sum = get_max_subarray(sequence_data, sequence_length,
                &index_begin, &index_end);
        printf("%d %d %d\n", sum, index_begin, index_end);
        if (line_index < line_count) printf("\n");
        line_index++;
    }
    return 0;
}
