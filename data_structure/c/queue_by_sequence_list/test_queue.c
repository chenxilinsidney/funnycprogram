/**
 * @file test_queue.c
 * @brief test queue data structure.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-21
 */

#include "queue.h"

int main(void)
{
    /// create queue
    Queue queue;
    InitQueue(&queue);
    /// insert element to queue
    EnQueue(&queue, 1);
    EnQueue(&queue, 11);
    EnQueue(&queue, 111);
    EnQueue(&queue, 1111);
    EnQueue(&queue, 11111);
    /// queue length
    int length = QueueLength(&queue);
    printf("queue length is %d\n", length);
    /// get queue head element
    int element;
    GetHead(&queue, &element);
    printf("element in head is %d\n", element);
    /// delete element from queue
    DeQueue(&queue, &element);
    printf("deleted element in head is %d\n", element);
    /// clear list
    ClearQueue(&queue);
    printf("queue empty after clear is %d\n", QueueEmpty(&queue));
    /// destroy list
    DestroyQueue(&queue);
    return EXIT_SUCCESS;
}
