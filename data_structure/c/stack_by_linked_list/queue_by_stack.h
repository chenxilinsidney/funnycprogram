/**
 * @file queue_by_stack.h
 * @brief implement of a queue by two stacks.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-22
 */
#ifndef __QUEUE_BY_STACK_H__
#define __QUEUE_BY_STACK_H__

#include "stack.h"

/// queue data structure by two stacks
typedef struct Queue {
    Stack s1;
    Stack s2;
}Queue;

/// queue methods

/// initialize queue
void InitQueue(Queue* Q);
/// clear queue
void ClearQueue(Queue* Q);
/// detect if queue is empty
Status QueueEmpty(Queue* Q);
/// get queue length
CommonType QueueLength(Queue* Q);
/// get head element from the queue
Status GetHead(Queue* Q, ElementType* e);
/// insert element to the queue
Status EnQueue(Queue* Q, ElementType e);
/// delete element from the queue
Status DeQueue(Queue* Q, ElementType* e);

#endif  // __QUEUE_BY_STACK_H__
