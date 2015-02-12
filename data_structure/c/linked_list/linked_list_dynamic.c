/**
 * @file linked_list_dynamic.c
 * @brief dynamic linked list method implements.
 * The methods use <assert.h> to help debug the program.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-19
 */

#include "linked_list_dynamic.h"

/**
 * @brief initialize the list.insert node in the head of list.
 * The method can be alse modified to insert node in the tail
 * of list.
 *
 * @param[in,out]  L     list struct pointer
 * @param[in]      size  list data size
 *
 */
void InitList(LinkList* L, CommonType size)
{
    assert(size >= 0);
    /// initialize first node
    if ((*L = (LinkList)malloc(sizeof(Node))) == NULL) {
        assert(0);
        exit(EXIT_FAILURE);
    }
    (*L)->next = NULL;
    /// initialize other node
    LinkList new_node;
    while (size--) {
        /// add new node to the head of the list
        if ((new_node = (LinkList)malloc(sizeof(Node))) == NULL) {
            assert(0);
            exit(EXIT_FAILURE);
        }
        new_node->data = 0;
        new_node->next = (*L)->next;
        (*L)->next = new_node;
    }
}

/**
 * @brief destroy the list.
 *
 * @param[in,out]  L     list struct pointer
 *
 */
void DestroyList(LinkList* L)
{
    assert(L != NULL);
    /// pointer to the first node
    LinkList q, p = (*L);
    /// free memory
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    /// set first node to null
    *L = NULL;
}

/**
 * @brief detect if the list is empty.
 *
 * @param[in]      L     list struct pointer
 *
 * @return return TRUE if empty, else return FALSE
 */
Status ListEmpty(LinkList* L)
{
    assert(L != NULL);
    /// check the first data node
    if ((*L)->next)
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
void ClearList(LinkList* L)
{
    assert(L != NULL);
    /// pointer to the first data node
    LinkList q, p = (*L)->next;
    /// free memory
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    /// set first data node to NULL
    (*L)->next = NULL;
}

/**
 * @brief  get list length.
 *
 * @param[in]      L     list struct pointer
 *
 * @return list length
 */
CommonType ListLength(LinkList* L)
{
    assert(L != NULL);
    /// pointer to the first data node
    CommonType length = 0;
    LinkList p = (*L)->next;
    /// pointer to next node
    while (p) {
        p = p->next;
        length++;
    }
    return length;
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
Status GetElem(LinkList* L, CommonType index, ElementType* e)
{
    assert(L != NULL && e != NULL);
    /// pointer to the first data node
    CommonType j = 1;
    LinkList p = (*L)->next;
    /// pointer to node of index
    while (p && j < index) {
        /// pointer to next node
        p = p->next;
        j++;
    }
    /// can not get the element by index
    if(!p || j > index)
        return ERROR;
    /// get element from list
    *e = p->data;
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
CommonType LocateElem(LinkList* L, ElementType e)
{
    assert(L != NULL);
    /// pointer to the first data node
    CommonType index = 0;
    LinkList p = (*L)->next;
    /// pointer to next node
    while (p) {
        index++;
        /// get index of the first found element from list
        if(p->data == e)
            return index;
        p = p->next;
    }
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
Status ListInsert(LinkList* L, CommonType index, ElementType e)
{
    assert(L != NULL);
    CommonType j = 1;
    /// pointer to the first node
    LinkList s, p = *L;
    /// pointer to node of index
    while (p->next && j < index) {
        p = p->next;
        j++;
    }
    /// can not get the location by index
    if(!p->next || j > index)
        return ERROR;
    /// malloc memory
    if ((s = (LinkList)malloc(sizeof(Node))) == NULL) {
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// insert element
    s->data = e;
    s->next = p->next;
    p->next = s;
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
Status ListDelete(LinkList* L, CommonType index, ElementType* e)
{
    assert(L != NULL && e != NULL);
    CommonType j = 1;
    /// pointer to the first node
    LinkList q, p = *L;
    /// pointer to node of index
    while (p->next && j < index) {
        p = p->next;
        j++;
    }
    /// can not get the location by index
    if (!(p->next) || j > index)
        return ERROR;
    /// get deleted element
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}
