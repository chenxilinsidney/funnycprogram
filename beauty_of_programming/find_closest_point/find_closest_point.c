/**
 * @file find_closest_point.c
 * @brief find the two points in a given array that make their distance be
 * the minimum value so the the points are the closest pairs.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-02-15
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int ElementType;    ///< element data type
typedef int CommonType;     ///< common data type

/// Point struct
typedef struct {
    ElementType x;
    ElementType y;
}Point;
#define MAX_COUNT      1000000
Point point_x[MAX_COUNT];
Point point_y[MAX_COUNT];

/// sort point array by x from small to big
int compare_x(const void* a, const void* b)
{
    return (*(Point*)a).x - (*(Point*)b).x;
}
/// sort point array by y from small to big
int compare_y(const void* a, const void* b)
{
    return (*(Point*)a).y - (*(Point*)b).y;
}

/// get distance for two point
double distance_2D(Point x, Point y)
{
    return sqrt((x.x - y.x)*(x.x - y.x) + (x.y - y.y)*(x.y - y.y)); 
}

/// get distance for value that x is not larger than y
double distance(ElementType x, ElementType y)
{
    return (double)(y - x);
}
/**
 * @brief find point_a and point_b that they have the minimum distance in
 * the array.
 *
 * @param[in,out] array_x         element array
 * @param[in,out] array_y         element array
 * @param[in]     array_size      element array size
 * @param[out]    point_a         element a
 * @param[out]    point_b         element b
 *
 * @return return the minimum distance between value_a and value_b
 */
ElementType find_closest_point(Point* array_x, Point* array_y,
        CommonType array_size, Point* point_a, Point* point_b)
{
    /// divide and conquer
    if (array_size > 2) {
        /// get middle point
        CommonType middle = (unsigned)array_size >> 1;
        /// get left and right distance
        Point left_point_a, left_point_b, right_point_a, right_point_b;
        double distance_left = find_closest_point(array_x, array_y,
                middle, &left_point_a, &left_point_b);
        double distance_right = find_closest_point(array_x + middle,
                array_y + middle,
                array_size - middle, &right_point_a, &right_point_b);
        /// get min distance of the two distance
        double distance_min_lr =
            distance_left < distance_right ? distance_left : distance_right;
        /// get search range
        CommonType ii = middle - 1;
        while (array_x[middle].x - array_x[ii].x < distance_min_lr) ii--;
        CommonType jj = middle;
        while (array_x[jj].x - array_x[middle].x < distance_min_lr) jj++;
        /// get middle distance in range
        CommonType i, j;
        double temp;
        for (i = ii; i < middle; i++)
            for (j = jj; j < array_size; j++)
                if ((temp = distance_2D(array_x[i], array_x[j]))
                        < distance_min_lr)
                    distance_min_lr = temp;
        return distance_min_lr;
    } else if (array_size == 2) {
        *point_a = array_x[0];
        *point_b = array_x[1];
        return distance_2D(*point_a, *point_b);
    } else {
        return 1000000;
    }
}

int main(void) {
    /// read data to array
    CommonType count = 0;
    while(count < MAX_COUNT && scanf("(%u,%u)\n", &(point_x[count].x),
                &(point_x[count].y)) == 2) {
        ++count;
    }
    memcpy(point_y, point_x, count * sizeof(point_x[0]));
    /// sort array by x and y
    qsort(point_x, count, sizeof(point_x[0]), compare_x);
    qsort(point_y, count, sizeof(point_y[0]), compare_y);
    /// display
    printf("Point count = %d\n", count);
    CommonType i;
    for (i = 0; i < count; i++) {
        printf("sorted point by x is (%d,%d).\n", point_x[i].x, point_x[i].y);
    }
    for (i = 0; i < count; i++) {
        printf("sorted point by y is (%d,%d).\n", point_y[i].x, point_y[i].y);
    }
    /// find closest values
    Point value_a;
    Point value_b;
    double distance = find_closest_point(point_x, point_y, count,
            &value_a, &value_b);
    /// output result
    // printf("closest value_a and value_b is %d, %d.\n", value_a, value_b);
    printf("closest distance is %f.\n", distance);
    return EXIT_SUCCESS;
}
