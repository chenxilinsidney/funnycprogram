/**
 * @file heap.c
 * @brief heap method implements.
 * The methods use <assert.h> to help debug the program.
 * The heap use sequence list by dynamic array.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-02-05
 */

#include "heap.h"

/**
 * @brief swap two elements
 *
 * @param[in]     a      element pointer a
 * @param[in]     b      element pointer b
 */
static void swap(ElementType* a, ElementType* b)
{
    /// swap by third element
    ElementType c = *a;
    *a = *b;
    *b = c;
}

/**
 * @brief initialize heap:create an empty heap with special max size.
 *
 * @param[in,out] H     heap struct pointer
 * @param[in]     H     heap max size
 *
 */
void InitHeap(Heap* H, CommonType max_size)
{
    assert(H != NULL && max_size > 0);
    if ((H->data = (ElementType*)malloc((max_size + 1) *
                    sizeof(ElementType))) == NULL) {
        assert(0);
        exit(EXIT_FAILURE);
    }
    H->max_size = max_size;
    H->size = 0;
}

/**
 * @brief heap shift down: move a element down in the tree.
 * as long as needed(depending on the condition:min-heap or max-heap).
 *
 * @param[in]     array     heap elements array
 * @param[in]     index     array begin index to create heap
 * @param[in]     size      heap elements array length
 *
 */
void Heapify(ElementType* array, CommonType index,
        CommonType length)
{
    assert(array != NULL && index >= 1 && length >= 0);
    CommonType min_index;
    while (index < length) {
        min_index = index;
        /// get maximum or minimum child index
        if (LCHILD(index) <= length &&
                array[LCHILD(index)] HEAP_CMP_SYMBOL array[min_index])
            min_index = LCHILD(index);
        if (RCHILD(index) <= length &&
                array[RCHILD(index)] HEAP_CMP_SYMBOL array[min_index])
            min_index = RCHILD(index);
        if (min_index != index) {
            swap(array + index, array + min_index);
            index = min_index;
        } else {
            break;
        }
    }
}

/**
 * @brief create a heap out of given array of elements.
 *
 * @param[in,out] H         heap struct pointer
 * @param[in]     max_size  heap max size
 * @param[in]     array     heap elements array
 * @param[in]     length    heap elements array count
 *
 * @warning the heap elements array's first data should not be the
 * element in the heap.
 */
void BuildHeap(Heap* H, CommonType max_size,
        ElementType* array, CommonType length)
{
    assert(H != NULL && array != NULL && max_size > 0 && length > 0);
    /// memory pointer
    H->data = array;
    /// size
    H->max_size = max_size;
    H->size = length;
    /// heapify
    CommonType index;
    for (index = PARENT(length); index > 0; index--)
        Heapify(H->data, index, length);
}

/**
 * @brief clear heap: make heap as first initialized.
 *
 * @param[in,out] H     heap struct pointer
 *
 */
void ClearHeap(Heap* H)
{
    assert(H != NULL && H->data != NULL && H->max_size > 0);
    H->size = 0;
}

/**
 * @brief destroy heap: free heap memory, need to intitialize it if reused.
 *
 * @param[in,out] H     heap struct pointer
 *
 */
void DestroyHeap(Heap* H)
{
    assert(H != NULL);
    free(H->data);
    H->data = NULL;
    H->max_size = 0;
    H->size = 0;
}

/**
 * @brief return true if the heap is empty, false otherwise.
 *
 * @param[in]     H     heap struct pointer
 *
 * @return return TRUE if empty, FALSE otherwise
 */
Status HeapEmpty(Heap* H)
{
    assert(H != NULL && H->data != NULL && H->max_size > 0 && H->size >= 0);
    if (H->size)
        return FALSE;
    else
        return TRUE;
}

/**
 * @brief return true if the heap is full, false otherwise.
 *
 * @param[in]     H     heap struct pointer
 *
 * @return return TRUE if empty, FALSE otherwise
 */
Status HeapFull(Heap* H)
{
    assert(H != NULL && H->data != NULL && H->max_size > 0 && H->size >= 0);
    if (H->size == H->max_size)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief return the number of elements in the heap.
 *
 * @param[in]     H     heap struct pointer
 *
 * @return the number of elements in the heap
 */
CommonType HeapSize(Heap* H)
{
    assert(H != NULL && H->data != NULL && H->max_size > 0 && H->size >= 0);
    return H->size;
}

/**
 * @brief find the maximum item of a max-heap or a minimum item of a min-heap.
 *
 * @param[in]     H     heap struct pointer
 * @param[out]    e     the element
 *
 * @return OK if success, ERROR otherwise
 */
Status HeapGet(Heap* H, ElementType* e)
{
    assert(H != NULL && H->data != NULL && H->max_size > 0 && H->size >= 0);
    /// detect if heap if empty
    if (HeapEmpty(H) == TRUE)
        return ERROR;
    /// delete root element
    *e = H->data[1];
    return OK;
}

/**
 * @brief adding a new element to the heap.
 *
 * @param[in]     H     heap struct pointer
 * @param[in]     e     the element
 *
 * @return OK if success, ERROR otherwise
 */
Status HeapInsert(Heap* H, ElementType e)
{
    assert(H != NULL && H->data != NULL && H->max_size > 0 && H->size >= 0);
    /// detect if heap if full
    if (HeapFull(H) == TRUE)
        return ERROR;
    /// add element to last
    CommonType index = ++(H->size);
    /// heap shift up: move a element up in the tree.
    /// as long as needed(depending on the condition:min-heap or max-heap).
    while (index > 1 && e HEAP_CMP_SYMBOL H->data[PARENT(index)]) {
        H->data[index] = H->data[PARENT(index)];
        index = PARENT(index);
    }
    H->data[index] = e;
    return OK;
}

/**
 * @brief remove the root element of a max-heap or min-heap, respectively.
 *
 * @param[in]     H     heap struct pointer
 * @param[out]    e     the element
 *
 * @return OK if success, ERROR otherwise
 */
Status HeapDelete(Heap* H, ElementType* e)
{
    assert(H != NULL && H->data != NULL && H->max_size > 0 && H->size >= 0);
    /// detect if heap if empty
    if (HeapEmpty(H) == TRUE)
        return ERROR;
    /// delete root element and move last element to root
    *e = H->data[1];
    H->data[1] = H->data[(H->size)--];
    /// heapify
    Heapify(H->data, 1, H->size);
    return OK;
}

/**
 * @brief heap sort method for input array.
 *
 * @param[in,out] array     input and output array
 * @param[in]     length    array length
 *
 * @warning if the heap is max-heap, the elements in the array will increase
 * by index, otherwise decrease.
 */
void HeapSort(ElementType* array, CommonType length)
{
    /// make heap elements index begin from 1
    ElementType* array_new = array - 1;
    /// build heap by elements
    Heap heap;
    BuildHeap(&heap, length, array_new, length);
    /// move root element to the end and heapify smaller size array
    CommonType new_size = length;
    while (new_size > 1) {
        swap(array_new + new_size, array_new + 1);
        Heapify(array_new, 1, --new_size);
    }
}
