/**
 * @file queue.c
 * @brief queue method implements.
 * The methods use <assert.h> to help debug the program.
 * The queue use sequence list.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-21
 */

#include "queue.h"

/**
 * @brief initialize the queue.
 *
 * @param[in,out]  Q     queue struct pointer
 *
 */
void InitQueue(Queue* Q)
{
    assert(Q != NULL);
    /// initialize index only, ignore the queue data
    Q->head = 0;
    Q->tail = 0;
}

/**
 * @brief destroy the queue.
 *
 * @param[in,out]  Q     queue struct pointer
 *
 */
void DestroyQueue(Queue* Q)
{
    assert(Q != NULL && Q->head >= 0 && Q->tail >= 0);
    /// initialize index only, ignore the queue data
    Q->head = 0;
    Q->tail = 0;
}

/**
 * @brief clear the queue.
 *
 * @param[in,out]  Q     queue struct pointer
 *
 */
void ClearQueue(Queue* Q)
{
    assert(Q != NULL && Q->head >= 0 && Q->tail >= 0);
    /// set index only, ignore the queue data
    Q->head = 0;
    Q->tail = 0;
}

/**
 * @brief detect if the queue is empty.
 *
 * @param[in]      Q     queue struct pointer
 *
 * @return return TRUE if empty, else return FALQE
 */
Status QueueEmpty(Queue* Q)
{
    assert(Q != NULL && Q->head >= 0 && Q->tail >= 0);
    /// detect index value
    if (Q->head == Q->tail)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief  get queue length.
 *
 * @param[in]      Q     queue struct pointer
 *
 * @return queue length
 */
CommonType QueueLength(Queue* Q)
{
    assert(Q != NULL && Q->head >= 0 && Q->tail >= 0);
    return (Q->tail - Q->head + QUEUE_MAXSIZE) % QUEUE_MAXSIZE;
}

/**
 * @brief get head element from the queue.
 *
 * @param[in]      Q     queue struct pointer
 * @param[out]     e     the element
 *
 * @return return OK if success, else return ERROR
 */
Status GetHead(Queue* Q, ElementType* e)
{
    assert(Q != NULL && e != NULL && Q->head >= 0 && Q->tail >= 0);
    if (Q->head == Q->tail)
        return ERROR;
    /// get element from queue
    *e = Q->data[Q->head];
    return OK;
}

/**
 * @brief insert element to the queue.
 *
 * @param[in,out]  Q     queue struct pointer
 * @param[in]      e     the element to be insert
 *
 * @return return OK if success, else return ERROR
 */
Status EnQueue(Queue* Q, ElementType e)
{
    assert(Q != NULL && Q->head >= 0 && Q->tail >= 0);
    /// queue is full
    if ((Q->tail + 1) % QUEUE_MAXSIZE == Q->head)
        return ERROR;
    /// set data first and then increase tail index
    Q->data[Q->tail] = e;
    Q->tail = (Q->tail + 1) % QUEUE_MAXSIZE;
    return OK;
}

/**
 * @brief delete element from the queue.
 *
 * @param[in,out]  Q     queue struct pointer
 * @param[out]     e     the element to be deleted
 *
 * @return return OK and set e if success, else return ERROR
 */
Status DeQueue(Queue* Q, ElementType* e)
{
    assert(Q != NULL && e != NULL && Q->head >= 0 && Q->tail >= 0);
    /// queue is empty
    if (Q->tail == Q->head)
        return ERROR;
    /// get data first and then increase head index
    *e = Q->data[Q->head];
    Q->head = (Q->head + 1) % QUEUE_MAXSIZE;
    return OK;
}
