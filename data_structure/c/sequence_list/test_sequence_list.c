/**
 * @file test_sequence_list.c
 * @brief test the SqList data struture
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-20
 */

#include <stdio.h>
#include <stdlib.h>

#include "sequence_list_dynamic.h"

int main(void)
{
    /// create list
    SqList List;
    InitList(&List);
    /// insert element to list
    ListInsert(&List, 1, 1);
    ListInsert(&List, 2, 2);
    ListInsert(&List, 3, 3);
    ListInsert(&List, 4, 4);
    ListInsert(&List, 5, 5);
    /// locate element
    printf("element %d is in %d\n", 4, LocateElem(&List, 4));
    /// list length
    int length = ListLength(&List);
    printf("List length is %d\n", length);
    /// get list element
    int i, element;
    for (i = 1; i <= length; i++) {
        GetElem(&List, i, &element);
        printf("element in %d is %d\n", i, element);
    }
    /// delect element from list
    ListDelete(&List, 4, &element);
    printf("deleted element in %d is %d\n", 4, element);
    /// clear list
    ClearList(&List);
    printf("List empty is %d\n", ListEmpty(&List));
    return EXIT_SUCCESS;
}
