/**
 * @file stack.c
 * @brief stack method implements.
 * The methods use <assert.h> to help debug the program.
 * The stack use sequence list.
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
    /// initialize top index only, ignore the stack data
    S->top = -1;
}

/**
 * @brief destroy the stack.
 *
 * @param[in,out]  S     stack struct pointer
 *
 */
void DestroyStack(Stack* S)
{
    assert(S != NULL && S->top >= -1);
    /// initialize top index only, ignore the stack data
    S->top = -1;
}

/**
 * @brief clear the stack.
 *
 * @param[in,out]  S     stack struct pointer
 *
 */
void ClearStack(Stack* S)
{
    assert(S != NULL && S->top >= -1);
    /// set top index only, ignore the stack data
    S->top = -1;
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
    assert(S != NULL && S->top >= -1);
    /// detect top index value
    if (S->top == -1)
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
    assert(S != NULL && S->top >= -1);
    return S->top + 1;
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
    assert(S != NULL && e != NULL && S->top >= -1);
    if (S->top == -1)
        return ERROR;
    /// get element from stack
    *e = S->data[S->top];
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
    assert(S != NULL && S->top >= -1);
    if (S->top == STACK_MAXSIZE - 1)
        return ERROR;
    S->data[++(S->top)] = e;
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
    assert(S != NULL && e != NULL && S->top >= -1);
    if (S->top == -1)
        return ERROR;
    *e = S->data[(S->top)--];
    return OK;
}
