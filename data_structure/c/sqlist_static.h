/**
 * @file sqlist_static.h
 * @brief static sequence list header.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-19
 */
#ifndef __SQLIST_STATIC_H__
#define __SQLIST_STATIC_H__

#include "list.h"

/// static sequence list structure
typedef struct {
    ElementType data[LIST_MAXSIZE];   ///< list elements
    CommonType length;                ///< list length
}SqList;

/// static sequence list method

/// initialize list
void InitList(SqList* L);
/// detect if list is empty
Status ListEmpty(SqList* L);
/// clear list
void ClearList(SqList* L);
/// get list length
CommonType ListLength(SqList* L);
/// get element from the list
Status GetElem(SqList* L, CommonType index, ElementType* e);
/// locate element of the index
CommonType LocateElem(SqList* L, ElementType e);
/// insert element to the list
Status ListInsert(SqList* L, CommonType index, ElementType e);
/// delete element from the list
Status ListDelete(SqList* L, CommonType index, ElementTypElementType* e);

#endif  // __SQLIST_STATIC_H__
