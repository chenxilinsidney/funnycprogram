/**
 * @file stack_by_queue.c
 * @brief stack method implements.
 * The methods use <assert.h> to help debug the program.
 * The stack use two queues.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-21
 */

#include "stack_by_queue.h"

/**
 * @brief initialize the stack.
 *
 * @param[in,out]  S     stack struct pointer
 *
 */
void InitStack(Stack* S)
{
    assert(S != NULL);
    InitQueue(&S->q1);
    InitQueue(&S->q2);
}

/**
 * @brief clear the stack.
 *
 * @param[in,out]  S     stack struct pointer
 *
 */
void ClearStack(Stack* S)
{
    assert(S != NULL);
    ClearQueue(&S->q1);
    ClearQueue(&S->q2);
}

/**
 * @brief detect if the stack is empty.
 *
 * @param[in]      S     stack struct pointer
 *
 * @return return TRUE if empty, else return FALSE
 */
Status StackEmpty(Stack* S)
{
    assert(S != NULL);
    if (QueueEmpty(&S->q1) && QueueEmpty(&S->q2))
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief  get stack length.
 *
 * @param[in]      S     stack struct pointer
 *
 * @return stack length
 */
CommonType StackLength(Stack* S)
{
    assert(S != NULL);
    return QueueLength(&S->q1) + QueueLength(&S->q2);
}

/**
 * @brief get top element from the stack.
 *
 * @param[in]      S     stack struct pointer
 * @param[out]     e     the element
 *
 * @return return OK if success, else return ERROR
 */
Status GetTop(Stack* S, ElementType* e)
{
    assert(S != NULL && e != NULL);
    if (QueueEmpty(&S->q1) == FALSE) {
        while (DeQueue(&S->q1, e)) {
            EnQueue(&S->q2, *e);
        }
        return OK;
    } else if (QueueEmpty(&S->q2) == FALSE) {
        while (DeQueue(&S->q2, e)) {
            EnQueue(&S->q1, *e);
        }
        return OK;
    } else {
        return ERROR;
    }
}

/**
 * @brief push element to the stack.
 *
 * @param[in,out]  S     stack struct pointer
 * @param[in]      e     the element to be insert
 *
 * @return return OK if success, else return ERROR
 */
Status Push(Stack* S, ElementType e)
{
    assert(S != NULL);
    if (QueueEmpty(&S->q2) == FALSE) {
        return EnQueue(&S->q1, e);
    } else {
        return EnQueue(&S->q2, e);
    }
}

/**
 * @brief pop element from the stack.
 *
 * @param[in,out]  S     stack struct pointer
 * @param[out]     e     the element to be deleted
 *
 * @return return OK and set e if success, else return ERROR
 */
Status Pop(Stack* S, ElementType* e)
{
    assert(S != NULL && e != NULL);
    if (QueueEmpty(&S->q1) == FALSE) {
        CommonType keep_one = QueueLength(&S->q1) - 1;
        while (keep_one--) {
            DeQueue(&S->q1, e);
            EnQueue(&S->q2, *e);
        }
        DeQueue(&S->q1, e);
        return OK;
    } else if (QueueEmpty(&S->q2) == FALSE) {
        CommonType keep_one = QueueLength(&S->q2) - 1;
        while (keep_one--) {
            DeQueue(&S->q2, e);
            EnQueue(&S->q1, *e);
        }
        DeQueue(&S->q2, e);
        return OK;
    } else {
        return ERROR;
    }
}
