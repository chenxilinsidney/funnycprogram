/**
 * @file queue.h
 * @brief queue data structure header.
 * The queue use sequence list.
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

/// queue array maz length, can be modified
#define QUEUE_MAXSIZE      1000

/// queue data structure
typedef struct {
    ElementType data[QUEUE_MAXSIZE];   ///< queue elements
    CommonType head;                   ///< queue head data index
    CommonType tail;                   ///< queue tail data index
}Queue;

/// queue methods

/// initialize queue
void InitQueue(Queue* Q);
/// destroy queue
void DestroyQueue(Queue* Q);
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
