/**
 * @file stack.c
 * @brief stack method implements.
 * The methods use <assert.h> to help debug the program.
 * The stack use linked list.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-21
 */

#include "stack.h"

/**
 * @brief initialize the stack.
 *
 * @param[in,out]  S     stack struct pointer
 *
 */
void InitStack(Stack* S)
{
    assert(S != NULL);
    S->top = NULL;
    S->count = 0;
}

/**
 * @brief clear the stack.
 *
 * @param[in,out]  S     stack struct pointer
 *
 */
void ClearStack(Stack* S)
{
    assert(S != NULL && S->count >= 0);
    StackPtr new_node = S->top;
    while (new_node) {
        S->top = new_node->next;
        free(new_node);
        new_node = S->top;
    }
    S->count = 0;
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
    assert(S != NULL && S->count >= 0);
    /// detect count value
    if (S->count == 0)
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
    assert(S != NULL && S->count >= 0);
    return S->count;
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
    assert(S != NULL && e != NULL && S->count >= 0);
    if (S->count == 0)
        return ERROR;
    /// get element from stack
    *e = S->top->data;
    return OK;
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
    assert(S != NULL && S->count >= 0);
    StackPtr new_node;
    if ((new_node = (StackPtr)malloc(sizeof(StackNode))) == NULL) {
        assert(0);
        exit(EXIT_FAILURE);
    }
    new_node->data = e;
    new_node->next = S->top;
    S->top = new_node;
    S->count++;
    return OK;
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
    assert(S != NULL && e != NULL && S->count >= 0);
    if (S->count == 0)
        return ERROR;
    StackPtr new_node = S->top;
    *e = new_node->data;
    S->top = new_node->next;
    free(new_node);
    S->count--;
    return OK;
}
