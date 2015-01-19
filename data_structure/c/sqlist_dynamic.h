/**
 * @file sqlist_dynamic.h
 * @brief dynamic sequence list header.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-19
 */
#ifndef __SQLIST_DYNAMIC_H__
#define __SQLIST_DYNAMIC_H__

#include "list.h"

/// dynamic sequence list structure
typedef struct {
    ElementType* data;                ///< list elements
    CommonType length;                ///< list length
    CommonType listsize;              ///< list size mallocated
}SqList;

/// dynamic sequence list method

/// initialize list
void InitList(SqList* L);
/// destroy list
void DestroyList(SqList* L);
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

#endif  // __SQLIST_DYNAMIC_H__
