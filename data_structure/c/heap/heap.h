/**
 * @file heap.h
 * @brief heap data structure header.
 * The heap use sequence list by dynamic array.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-02-05
 */

#ifndef __HEAP__
#define __HEAP__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define NDEBUG
#include <assert.h>

/// function return state
#ifndef OK
#define OK        1
#endif
#ifndef ERROR
#define ERROR     0
#endif
#ifndef TRUE
#define TRUE      1
#endif
#ifndef FALSE
#define FALSE     0
#endif

/// data type, can be modified
typedef int Status;         ///< status data type
typedef int ElementType;    ///< element data type
typedef int CommonType;     ///< common data type

/// heap data structure
#define MAX_HEAP      1
#define MIN_HEAP      0
#define HEAP_TYPE     MIN_HEAP         ///< heap type, can by modified
#if HEAP_TYPE == MAX_HEAP
#define HEAP_CMP_SYMBOL >
#elif HEAP_TYPE == MIN_HEAP
#define HEAP_CMP_SYMBOL <
#endif

typedef struct {
    ElementType* data;                 ///< heap elements array pointer
    CommonType max_size;               ///< heap max elements count
    CommonType size;                   ///< heap elements count
}Heap;

/// heap methods

/// initialize heap:create an empty heap with special max size
void InitHeap(Heap* H, CommonType max_size);
/// create a heap out of given array of elements
void BuildHeap(Heap* H, CommonType max_size,
        ElementType* array, CommonType length);
/// clear heap: make heap as first initialized
void ClearHeap(Heap* H);
/// destroy heap: free heap memory, need to intitialize it if reused
void DestroyHeap(Heap* H);
/// return true if the heap is empty, false otherwise
Status HeapEmpty(Heap* H);
/// return true if the heap is full, false otherwise
Status HeapFull(Heap* H);
/// return the number of items in the heap
CommonType HeapSize(Heap* H);
/// find the maximum item of a max-heap or a minimum item of a min-heap
Status HeapGet(Heap* H, ElementType* e);
/// adding a new key to the heap
Status HeapInsert(Heap* H, ElementType e);
/// remove the root node of a max-heap or min-heap, respectively
Status HeapDelete(Heap* H, ElementType* e);

#endif  // __HEAP__
