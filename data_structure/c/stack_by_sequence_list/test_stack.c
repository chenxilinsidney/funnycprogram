/**
 * @file test_stack.c
 * @brief test stack data structure.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-21
 */

#include "stack.h"

int main(void)
{
    /// create stack
    Stack stack;
    InitStack(&stack);
    /// push element to stack
    Push(&stack, 1);
    Push(&stack, 11);
    Push(&stack, 111);
    Push(&stack, 1111);
    Push(&stack, 11111);
    /// stack length
    int length = StackLength(&stack);
    printf("stack length is %d\n", length);
    /// get stack top element
    int element;
    GetTop(&stack, &element);
    printf("element in top is %d\n", element);
    /// pop element from stack
    Pop(&stack, &element);
    printf("deleted element in top is %d\n", element);
    /// clear list
    ClearStack(&stack);
    printf("stack empty after clear is %d\n", StackEmpty(&stack));
    /// destroy list
    DestroyStack(&stack);
    return EXIT_SUCCESS;
}
