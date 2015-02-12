/**
 * @file test_linked_list.c
 * @brief test the LinkList data struture
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-20
 */

#include <stdio.h>
#include <stdlib.h>

#include "linked_list_dynamic.h"

int main(void)
{
    /// create list
    LinkList List;
    InitList(&List, 5);
    /// insert element to list
    ListInsert(&List, 4, 4);
    /// locate element
    printf("element %d is in %d\n", 4, LocateElem(&List, 4));
    /// list length
    int length = ListLength(&List);
    printf("List length is %d\n", length);
    /// get list element
    int i, element;
    for (i = 0; i < length; i++) {
        GetElem(&List, i, &element);
        printf("element in %d is %d\n", i, element);
    }
    /// delect element from list
    ListDelete(&List, 4, &element);
    printf("deleted element in %d is %d\n", 4, element);
    /// clear list
    ClearList(&List);
    printf("List empty is %d\n", ListEmpty(&List));
    /// destroy list
    DestroyList(&List);
    printf("List pointer is %p\n", List);
    return EXIT_SUCCESS;
}
