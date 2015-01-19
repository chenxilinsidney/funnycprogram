/**
 * @file sqlist_static.c
 * @brief static sequence list method implements.
 * The methods use <assert.h> to help debug the program.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-19
 */

#include "sqlist_static.h"

/**
 * @brief initialize the list.
 *
 * @param[in,out]  L     list struct pointer
 *
 */
void InitList(SqList* L)
{
    assert(L != NULL && L->length >= 0);
    /// initialize length only, ignore the list data
    L->length = 0;
    return OK;
}

/**
 * @brief detect if the list is empty.
 *
 * @param[in]      L     list struct pointer
 *
 * @return return TRUE if empty, else return FALSE
 */
Status ListEmpty(SqList* L)
{
    assert(L != NULL && L->length >= 0);
    /// always have length >= 0
    if (L->length)
        return FALSE;
    else
        return TRUE;
}

/**
 * @brief clear the list.
 *
 * @param[in,out]  L     list struct pointer
 *
 */
void ClearList(SqList* L)
{
    assert(L != NULL && L->length >= 0);
    /// set length only, ignore the list data
    L->length = 0;
}

/**
 * @brief get element from the list.
 *
 * @param[in]      L     list struct pointer
 * @param[in]      index the index from the list
 * @param[out]     e     the element by index
 *
 * @warning index begin from 1
 *
 * @return return OK if success, else return ERROR
 */
Status GetElem(SqList* L, CommonType index, ElementType* e)
{
    assert(L != NULL && e != NULL && L->length >= 0);
    /// index should be in reasonable range
    if (index > L->length || index < 1)
        return ERROR;
    /// get element from list
    *e = L->data[index - 1];
    return OK;
}

/**
 * @brief locate element by index.
 *
 * @param[in]      L     list struct pointer
 * @param[in]      e     the element to be located
 *
 * @warning index begin from 1
 *
 * @return return the index of the element if success, else return 0
 */
CommonType LocateElem(SqList* L, ElementType e)
{
    assert(L != NULL && L->length >= 0);
    CommonType i;
    for (i = 1; i <= L->length; i++)
        if (L->data[i] == e)
            /// get index of the first found element from list
            return i;
    return 0;
}

/**
 * @brief insert element to the list at given index.
 *
 * @param[in,out]  L     list struct pointer
 * @param[in]      index the index from the list
 * @param[in]      e     the element to be insert
 *
 * @warning index begin from 1
 *
 * @return return OK if success, else return ERROR
 */
Status ListInsert(SqList* L, CommonType index, ElementType e)
{
    assert(L != NULL && L->length >= 0);
    /// list length and index should be in reasonable range
    if (L->length == LIST_MAXSIZE || index > (L->length + 1) || index < 1)
        return ERROR;
    /// move the element after the index position to next position
    TYPE i;
    for (i = L->length - 1; i >= index - 1; i--)
        L->data[i + 1] = L->data[i];
    /// increase list length
    L->length++;
    /// insert element
    L->data[index - 1] = e;
    return OK;
}

/**
 * @brief delete element from the list.
 *
 * @param[in,out]  L     list struct pointer
 * @param[in]      index the index from the list
 * @param[out]     e     the element to be deleted
 *
 * @warning index begin from 1
 *
 * @return return OK and set e if success, else return ERROR
 */
Status ListDelete(SqList* L, CommonType index, ElementType* e)
{
    assert(L != NULL && e != NULL && L->length >= 0);
    /// index should be in reasonable range
    if (index > L->length || index < 1)
        return ERROR;
    /// get deleted element
    *e = L->data[index];
    /// move the element after the index position to previous position
    TYPE i;
    for (i = index; i < L->length; i++)
        L->data[i - 1] = L->data[i];
    /// decrease list length
    L->length--;
    return OK;
}

/**
 * @brief  get list length.
 *
 * @param[in]      L     list struct pointer
 *
 * @return list length
 */
CommonType ListLength(SqList* L)
{
    assert(L != NULL && L->length >= 0);
    return L->length;
}
