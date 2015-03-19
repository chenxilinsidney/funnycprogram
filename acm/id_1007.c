/**
 * @file id_1007.c
 * @brief HDOJ Problem ID 1007.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-19
 */

#include <stdio.h>
#include <math.h>

#ifndef ONLINE_JUDGE
#define ONLINE_JUDGE
#endif

struct Point {
    float x;
    float y;
};
int main()
{
    struct Point data[100000];
    int index_a, index_b;
    int count;
    while (scanf("%d", &count) != EOF && count != 0) {
        int data_index = 0;
        while (data_index < count) {
            scanf("%f%f", &(data[data_index].x), &(data[data_index].y));
            data_index++;
        }
#ifndef ONLINE_JUDGE
        int i;
        for (i = 0; i < count; i++) {
            printf ("%d %f %f\n", i, data[i].x, data[i].y);
        }
#endif
        float distance_temp;
        float distance_min =
            (data[0].x - data[1].x) *
            (data[0].x - data[1].x) +
            (data[0].y - data[1].y) *
            (data[0].y - data[1].y);
        for (index_a = 0; index_a < count; index_a++) {
            for (index_b = index_a + 1; index_b < count; index_b++) {
                if ((distance_temp =
                            (data[index_a].x - data[index_b].x) *
                            (data[index_a].x - data[index_b].x) +
                            (data[index_a].y - data[index_b].y) *
                            (data[index_a].y - data[index_b].y))
                        < distance_min) {
                    distance_min = distance_temp;
                }
#ifndef ONLINE_JUDGE
                printf ("d = %f\n", distance_temp);
#endif
            }
        }
        printf("%0.2f\n", sqrt(distance_min) / 2);
    }
    return 0;
}
