/**
 * @file debug.h
 * @brief debug with STDIO, your may use the follow three macro to debug width
 * a programme by IO. to remove the debug define NDBG_PRINT before including
 * the header.(this look likes <assert.h>)
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-17
 */

#include <stdio.h>

#ifndef NDBG_PRINT
#define DEBUG_PRINT_STATE  printf("File: %s Line: %d\n", __FILE__, __LINE__)
#define DEBUG_PRINT_VALUE(FORMAT, VALUE)  printf("value " #VALUE \
                                          " = " FORMAT "\n", (VALUE))
#define DEBUG_PRINT_STRING(STRING)  printf(STRING)
#else
#define DEBUG_PRINT_STATE  ((void)(0))
#define DEBUG_PRINT_VALUE(FORMAT, VALUE)  ((void)(0))
#define DEBUG_PRINT_STRING(STRING)  ((void)(0))
#endif
