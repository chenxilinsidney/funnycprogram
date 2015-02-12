/**
 * @file list.h
 * @brief list header that has macro definition used by many types of list.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-19
 */
#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define NDEBUG
#include <assert.h>

/// list return state
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

/// list array maz length used by static list, can be modified
#define LIST_MAXSIZE      1000
/// list initialize size used by dynamic sequence list, can be modified
#define LIST_INIT_SIZE      1000
/// list memory increated size used by dynamic sequence list, can be modified
#define LIST_INCREMENT       2

/// data type, can be modified
typedef int Status;         ///< status data type
typedef int ElementType;    ///< element data type
typedef int CommonType;     ///< common data type

#endif  // __LIST_H__
