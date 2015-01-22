/**
 * @file queue_by_stack.c
 * @brief queue method implements.
 * The methods use <assert.h> to help debug the program.
 * The queue use two stack.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-21
 */

#include "queue_by_stack.h"

/**
 * @brief initialize the queue.
 *
 * @param[in,out]  Q     queue struct pointer
 *
 */
void InitQueue(Queue* Q)
{
    assert(Q != NULL);
    InitStack(&Q->s1);
    InitStack(&Q->s2);
}

/**
 * @brief clear the queue.
 *
 * @param[in,out]  Q     queue struct pointer
 *
 */
void ClearQueue(Queue* Q)
{
    assert(Q != NULL);
    ClearStack(&Q->s1);
    ClearStack(&Q->s2);
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
    assert(Q != NULL);
    if (StackEmpty(&Q->s1) && StackEmpty(&Q->s2))
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
    assert(Q != NULL);
    return StackLength(&Q->s1) + StackLength(&Q->s2);
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
    assert(Q != NULL && e != NULL);
    if (!StackEmpty(&Q->s2)) {
        GetTop(&Q->s2, e);
        return OK;
    } else if (!StackEmpty(&Q->s1)) {
        while (Pop(&Q->s1, e)) {
            Push(&Q->s2, *e);
        }
        return OK;
    } else {
        return ERROR;
    }
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
    assert(Q != NULL);
    return Push(&Q->s1, e);
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
    assert(Q != NULL && e != NULL);
    if (!StackEmpty(&Q->s2)) {
        Pop(&Q->s2, e);
        return OK;
    } else if (!StackEmpty(&Q->s1)) {
        CommonType keep_one = StackLength(&Q->s1) - 1;
        while (keep_one--) {
            Pop(&Q->s1, e);
            Push(&Q->s2, *e);
        }
        Pop(&Q->s1, e);
        return OK;
    } else {
        return ERROR;
    }
}
