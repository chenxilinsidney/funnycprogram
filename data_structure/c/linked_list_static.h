/**
 * @file linked_list_static.h
 * @brief static linked list header.
 * the data was not in the first node.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-19
 */
#ifndef __LINKED_LIST_STATIC_H__
#define __LINKED_LIST_STATIC_H__

#include "list.h"

/// component structure
typedef struct
{
    ElementType data;     ///< data in the component
    CommonType cur;       ///< cursor to next component
}Component,LinkList[MAXSIZE];

/// static linked list method

/// initialize list
void InitList(LinkList* L, CommonType size);
/// destroy list
void DestroyList(LinkList* L);
/// detect if list is empty
Status ListEmpty(LinkList* L);
/// clear list
void ClearList(LinkList* L);
/// get list length
CommonType ListLength(LinkList* L);
/// get element from the list
Status GetElem(LinkList* L, CommonType index, ElementType* e);
/// locate element of the index
CommonType LocateElem(LinkList* L, ElementType e);
/// insert element to the list
Status ListInsert(LinkList* L, CommonType index, ElementType e);
/// delete element from the list
Status ListDelete(LinkList* L, CommonType index, ElementType* e);

#endif  // __LINKED_LIST_STATIC_H__
