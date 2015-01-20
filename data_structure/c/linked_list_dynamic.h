/**
 * @file linked_list_dynamic.h
 * @brief dynamic linked list header.
 * the data was not in the first node.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-19
 */
#ifndef __LINKED_LIST_DYNAMIC_H__
#define __LINKED_LIST_DYNAMIC_H__

#include "list.h"

/// node structure
typedef struct Node
{
    ElementType data;     ///< data in the node
    struct Node* next;    ///< pointer to next node
}Node;

/// define single linked list
typedef Node* LinkList;

/// dynamic linked list method

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

#endif  // __LINKED_LIST_DYNAMIC_H__
