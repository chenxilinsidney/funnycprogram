/**
 * @file test_heap.c
 * @brief test heap data structure.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-21
 */

#include "heap.h"

int main(void)
{
    /// create heap
    Heap heap;
    ElementType array[12] = {1,3,5,11,4,6,7,12,15,10,9,8};
    BuildHeap(&heap, 100, array, 12);
    /// insert element to heap
#if 0
    HeapInsert(&heap, 1);
    HeapInsert(&heap, 3);
    HeapInsert(&heap, 5);
    HeapInsert(&heap, 11);
    HeapInsert(&heap, 4);
    HeapInsert(&heap, 6);
    HeapInsert(&heap, 7);
    HeapInsert(&heap, 12);
    HeapInsert(&heap, 15);
    HeapInsert(&heap, 10);
    HeapInsert(&heap, 9);
    HeapInsert(&heap, 8);
    // HeapInsert(&heap, 2);
#endif
    /// heap length
    int length = HeapSize(&heap);
    printf("heap length is %d\n", length);
    int index;
    for (index = 1; index <= length; index++)
        printf("heap data is %d in %d\n", heap.data[index], index);
    /// get heap head element
    int element;
    HeapGet(&heap, &element);
    printf("element in root is %d\n", element);
    /// delete element from heap
    HeapDelete(&heap, &element);
    length = HeapSize(&heap);
    printf("deleted heap in head is %d\n", element);
    for (index = 1; index <= length; index++)
        printf("heap data is %d in %d\n", heap.data[index], index);
    /// clear list
    // ClearHeap(&heap);
    return EXIT_SUCCESS;
}
