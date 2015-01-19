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
void InitList(SqList* L);
/// destroy list
void DestroyList(SqList* L);
/// detect if list is empty
Status ListEmpty(LinkList* L);
/// clear list
void ClearList(LinkList* L);
/// get list length
CommonType ListLength(SqList* L);
/// get element from the list
Status GetElem(LinkList* L, CommonType index, ElementType* e);
/// locate element of the index
CommonType LocateElem(SqList* L, ElementType e);
/// insert element to the list
Status ListInsert(LinkList* L, CommonType index, ElementType e);
/// delete element from the list
Status ListDelete(SqList* L, CommonType index, ElementTypElementType* e);

/*随机产生n个元素的值，建立带头结点的单链表L,头插法*/
Status CreateLinkListHead(LinkList *L,int n)
{
    LinkList p;
    srand((unsigned int)time(0));                       /*初始化随机数种子*/
    *L = (LinkList)malloc(sizeof(Node));  /*建立一个带头结点的单链表，申请内存空间*/
    (*L)->data = n;                       /*建立一个带头结点的单链表，头结点数据域存储单链表长度附加信息*/
    (*L)->next = NULL;                    /*建立一个带头结点的单链表，头结点指针域初始化为NULL*/
    for(int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*建立一个新结点，申请内存空间*/
        p->data = rand()%100 + 1;           /*随机生成1～100的数字*/
        p->next = (*L)->next;               /*把新的结点插入头结点与前一新结点之间，即新结点始终在头结点之后*/
        (*L)->next = p;                     /*把新结点的地址复制到头结点的指针域*/
    }
    return OK;
}
/*随机产生n个元素的值，建立带头结点的单链表L,尾插法*/
Status CreateLinkListTail(LinkList *L, int n)
{
    LinkList p,r;
    srand((unsigned int)time(0));                       /*初始化随机数种子*/
    *L = (LinkList)malloc(sizeof(Node));  /*建立一个带头结点的单链表，申请内存空间*/
    r = *L;                               /*r为指向尾部的结点*/
    for(int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*建立一个新结点，申请内存空间*/
        p->data = rand()%100 + 1;           /*随机生成1～100的数字*/
        r->next = p;                        /*将表尾终端结点的指针指向新结点*/
        r = p;                              /*将当前的新结点定义为表尾终端结点*/
    }
    r->next = NULL;                         /*表示单链表结束*/
    return OK;
}

#endif  // __LINKED_LIST_DYNAMIC_H__
