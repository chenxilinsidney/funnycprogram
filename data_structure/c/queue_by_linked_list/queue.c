/**
 * @file queue.c
 * @brief queue method implements.
 * The methods use <assert.h> to help debug the program.
 * The queue use linked list.
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
    if ((Q->head = (QueuePtr)malloc(sizeof(QueueNode))) == NULL) {
        assert(0);
        exit(EXIT_FAILURE);
    }
    Q->tail = Q->head;
    Q->head->next = NULL;
    Q->count = 0;
}

/**
 * @brief clear the queue.
 *
 * @param[in,out]  Q     queue struct pointer
 *
 */
void ClearQueue(Queue* Q)
{
    assert(Q != NULL && Q->count >= 0);
    /// set index only, ignore the queue data
    QueuePtr new_node = Q->head;
    while (new_node != Q->tail) {
        Q->head = new_node->next;
        free(new_node);
        new_node = Q->head;
    }
    Q->count = 0;
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
    assert(Q != NULL && Q->count >= 0);
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
    assert(Q != NULL && Q->count >= 0);
    return Q->count;
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
    assert(Q != NULL && e != NULL && Q->count >= 0);
    if (Q->head == Q->tail)
        return ERROR;
    /// get element from queue
    *e = Q->head->next->data;
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
    assert(Q != NULL && Q->count >= 0);
    QueuePtr new_node;
    if ((new_node = (QueuePtr)malloc(sizeof(QueueNode))) == NULL) {
        assert(0);
        exit(EXIT_FAILURE);
    }
    new_node->data = e;
    new_node->next = NULL;
    Q->tail->next = new_node;
    Q->tail = new_node;
    Q->count++;
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
    assert(Q != NULL && e != NULL && Q->count >= 0);
    /// queue is empty
    if (Q->tail == Q->head)
        return ERROR;
    QueuePtr old_node = Q->head->next;
    *e = old_node->data;
    Q->head->next = old_node->next;
    if (Q->tail == old_node)
        Q->tail = Q->head;
    free(old_node);
    Q->count--;
    return OK;
}
