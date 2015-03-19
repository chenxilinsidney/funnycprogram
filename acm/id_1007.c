/**
 * @file id_1007.c
 * @brief HDOJ Problem ID 1007.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-19
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include <math.h>

#ifndef ONLINE_JUDGE
// #define ONLINE_JUDGE
#endif

typedef struct Point {
    double x;
    double y;
} Point;

int compare_point_by_x(void const* a, void const* b)
{
    double temp = ((Point*)a)->x - ((Point*)b)->x;
    if (temp > 0.00001)
        return 1;
    else if (temp < -0.00001)
        return -1;
    else
        return 0;
}

int compare_point_by_y(void const* a, void const* b)
{
    double temp = ((Point*)a)->y - ((Point*)b)->y;
    if (temp > 0.00001)
        return 1;
    else if (temp < -0.00001)
        return -1;
    else
        return 0;
}

double get_two_point_distance(Point point_a, Point point_b)
{
    return (double)((point_a.x - point_b.x) *
            (point_a.x - point_b.x) +
            (point_a.y - point_b.y) *
            (point_a.y - point_b.y));
}

double get_middle_distance(Point* array, int index_begin,
        int index_end, int index_mid, double distance_threshold)
{
    int index_temp;
    double distance_temp;
    double distance_best = distance_threshold;
    for (index_temp = index_mid - 1; index_temp >= index_begin; index_temp--) {
        if (array[index_mid].x - array[index_temp].x >= distance_best)
            break;
        if ((distance_temp = get_two_point_distance(array[index_temp],
                        array[index_mid])) < distance_best)
            distance_best = distance_temp;
    }
    for (index_temp = index_mid + 1; index_temp <= index_end; index_temp++) {
        if (array[index_temp].x - array[index_mid].x >= distance_best)
            break;
        if ((distance_temp = get_two_point_distance(array[index_temp],
                        array[index_mid])) < distance_best)
            distance_best = distance_temp;
    }
    if ((distance_temp = get_two_point_distance(array[index_mid - 1],
                    array[index_mid + 1])) < distance_best)
        distance_best = distance_temp;
#ifndef ONLINE_JUDGE
    printf("distance_best = %lf\n", distance_best);
#endif
    return distance_best;
}

double merge_conquer(Point* array, int index_begin, int index_end)
{
#ifndef ONLINE_JUDGE
    printf("in merge %d %d\n", index_begin, index_end);
#endif
    if ((index_end - index_begin) == 1) {
        return get_two_point_distance(array[index_begin], array[index_end]);
    } else if ((index_end - index_begin) < 1) {
        return FLT_MAX;
    }
    int index_mid = index_begin + ((unsigned)(index_end - index_begin) >> 1);
    double distance_left = merge_conquer(array, index_begin, index_mid - 1);
    double distance_right = merge_conquer(array, index_mid + 1, index_end);
    double distance_small = distance_left > distance_right ?
        distance_right : distance_left;
    double distance_middle = get_middle_distance(array, index_begin,
            index_end, index_mid, distance_small);
#ifndef ONLINE_JUDGE
    printf("%d %d %d %lf %lf %lf\n", index_begin, index_mid, index_end,
            distance_left, distance_middle, distance_right);
#endif
    return distance_small > distance_middle ? distance_middle : distance_small;
}

double get_min_pair(Point* array, int array_length)
{
    qsort((void*)array, (size_t)array_length, sizeof(Point),
            compare_point_by_x);
#ifndef ONLINE_JUDGE
    printf("sorted array\n");
    int i;
    for (i = 0; i < array_length; i++) {
        printf("%d %lf %lf\n", i, array[i].x, array[i].y);
    }
#endif
    double distance = merge_conquer(array, 0, array_length - 1);
    return (double)(sqrt(distance) / 2.0);
}

int main()
{
    Point data[100000];
    int count;
    while (scanf("%d", &count) != EOF && count != 0) {
        int data_index = 0;
        while (data_index < count) {
            scanf("%lf%lf", &(data[data_index].x), &(data[data_index].y));
            data_index++;
        }
#ifndef ONLINE_JUDGE
        int i;
        for (i = 0; i < count; i++) {
            printf ("%d %0.2f %0.2f\n", i, data[i].x, data[i].y);
        }
#endif
        printf("%0.2f\n", get_min_pair(data, count));
    }
    return 0;
}
