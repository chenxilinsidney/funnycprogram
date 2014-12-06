/**
 * @file Getsystemstackdirection.c
 * @brief test stack grow direction.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-06
 */

#include<stdio.h>

static int stack_grow_direction;

static void find_stack_grow_direction(void)
{
    static char* p = NULL;
    char c;
    if (p == NULL) {
        p = &c;
        find_stack_grow_direction();  /// recursion to make sure to use stack
    } else {
        if (p > &c)
            stack_grow_direction = -1;  ///< stack grow to lower address
        else
            stack_grow_direction = 1;   ///< stack grow to upper address
    }
}

int main(void)
{
    if (stack_grow_direction == 1)
        printf("stack grow from lower address to upper address\n");
    else
        printf("stack grow from upper address to lower address\n");
    return 0;
}
