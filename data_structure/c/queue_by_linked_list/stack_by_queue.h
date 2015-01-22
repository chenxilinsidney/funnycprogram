/**
 * @file stack_by_stack.h
 * @brief implement of a stack by two queues.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-22
 */
#ifndef __STACK_BY_QUEUE_H__
#define __STACK_BY_QUEUE_H__

#include "queue.h"

/// stack data structure by two queue
typedef struct Stack {
    Queue q1;
    Queue q2;
}Stack;

/// stack methods

/// initialize stack
void InitStack(Stack* S);
/// clear stack
void ClearStack(Stack* S);
/// detect if stack is empty
Status StackEmpty(Stack* S);
/// get stack length
CommonType StackLength(Stack* S);
/// get top element from the stack
Status GetTop(Stack* S, ElementType* e);
/// push element to the stack
Status Push(Stack* S, ElementType e);
/// pop element from the stack
Status Pop(Stack* S, ElementType* e);

#endif  // __STACK_BY_QUEUE_H__
