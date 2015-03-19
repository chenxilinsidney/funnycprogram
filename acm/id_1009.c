/**
 * @file id_1009.c
 * @brief HDOJ Problem ID 1009.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-19
 */

#include <stdio.h>
#include <float.h>

typedef struct JF {
    int J;
    int F;
    double rate;
} JF;

int compare_by_data(void const* a, void const* b)
{
    double temp = ((JF*)a)->rate - ((JF*)b)->rate;
    if (temp >= DBL_EPSILON)
        return -1;
    else if (temp <= -1 * DBL_EPSILON)
        return 1;
    else
        return 0;
}


int main()
{
    JF array[1000];
    int M, N, count;
    double max_J;
    while (scanf("%d%d", &M, &N) != EOF && (!(M == -1 && N == -1))) {
        count = 0;
        while (count < N) {
            scanf("%d%d", &(array[count].J), &(array[count].F));
            array[count].rate = (double)(array[count].J) /
                (double)(array[count].F);
            count++;
        }
        qsort((void*)array, (size_t)N, sizeof(array[0]), compare_by_data);
#ifndef ONLINE_JUDGE
        int index;
        for (index = 0; index < N; index++) {
            printf("data %d J: %d F: %d rate: %lf\n", index,
                    array[index].J,
                    array[index].F,
                    array[index].rate);
        }
#endif
        max_J = 0.0;
        for (count = 0; count < N; count++) {
            if (M >= array[count].F) {
                max_J += array[count].J;
                M -= array[count].F;
            } else {
                max_J += array[count].rate * M;
                break;
            }
        }
        printf("%0.3lf\n", max_J);
    }
    return 0;
}
