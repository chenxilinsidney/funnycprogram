/**
 * @file Getsystemheapdirection.c
 * @brief get system heap grow direction of address
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-07
 */

#include<stdio.h>
#include<malloc.h>

static int heap_grow_direction;

static void find_heap_grow_direction(void)
{
    static char* p1 = NULL;
    static char* p2 = NULL;
    if (p1 == NULL) {
        p1 = (char*)malloc(100);
        p2 = p1;
        find_heap_grow_direction();  /// recursion to make sure to use stack
    } else {
        p1 = (char*)malloc(100);
        if (p1 < p2)
            heap_grow_direction = -1;  ///< stack grow to lower address
        else
            heap_grow_direction = 1;   ///< stack grow to upper address
        printf("p1 = %p\n", p1);
        printf("p2 = %p\n", p2);
        free(p1);
        free(p2);
    }
}

int main(void)
{
    find_heap_grow_direction();
    if (heap_grow_direction == 1)
        printf("heap grow from lower address to upper address\n");
    else
        printf("heap grow from upper address to lower address\n");
    return 0;
}
