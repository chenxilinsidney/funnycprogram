/**
 * @file queue.h
 * @brief queue data structure header.
 * The queue use linked list.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-21
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define NDEBUG
#include <assert.h>

/// function return state
#ifndef OK
#define OK        1
#endif
#ifndef ERROR
#define ERROR     0
#endif
#ifndef TRUE
#define TRUE      1
#endif
#ifndef FALSE
#define FALSE     0
#endif

/// data type, can be modified
typedef int Status;         ///< status data type
typedef int ElementType;    ///< element data type
typedef int CommonType;     ///< common data type

/// queue data structure
typedef struct QueueNode {
    ElementType data;                  ///< queue elements
    struct QueueNode* next;            ///< queue node pointer
}QueueNode, *QueuePtr;

typedef struct Queue {
    QueuePtr head;                     ///< queue head data pointer
    QueuePtr tail;                     ///< quaue tail data pointer
    CommonType count;                  ///< quaue data count
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

#endif  // __QUEUE_H__
