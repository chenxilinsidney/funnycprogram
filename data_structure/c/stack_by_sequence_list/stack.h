/**
 * @file stack.h
 * @brief stack data structure header.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-21
 */

#ifndef __STACK_H__
#define __STACK_H__

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

/// stack array maz length, can be modified
#define STACK_MAXSIZE      1000

/// stack data structure
typedef struct {
    ElementType data[STACK_MAXSIZE];   ///< stack elements
    CommonType top;                    ///< stack top data index
}Stack;

/// stack methods

/// initialize stack
void InitStack(Stack* S);
/// destroy stack
void DestroyStack(Stack* S);
/// clear stack
void ClearStack(Stack* S);
/// detect if stack is empty
Status StackEmpty(Stack* S);
/// get stack length
CommonType StackLength(Stack* S);
/// get top element from the stack
Status GetTop(Stack* S, ElementType* e);
/// push element to the stack
Status Push(Stack* S, ElementType e);
/// pop element from the stack
Status Pop(Stack* S, ElementType* e);

#endif  // __STACK_H__
