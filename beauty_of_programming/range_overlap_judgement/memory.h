/**
 * @copyright Copyright (C),1988-1999, Cita109 Tech. Co., Ltd.
 * @file memory.h
 * @brief memory allocate and free with checking.
 * @author author           time      version   desc
 * @author Chen Xi Lin    14/12/17      1.2   build the module
 * @version 1.2
 * @date 2014-06-08
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define SMALLOC(num, type) ((type *)safe_malloc((num)*sizeof(type)))
#define SCALLOC(num, type) ((type *)safe_calloc((num),sizeof(type)))
#define SREALLOC(ptr, num, type) ((type *)safe_realloc((ptr),(num)*sizeof(type)))
#define SFREE(pointer) (safe_free((void**)(pointer)))

void* safe_malloc(size_t size);
void* safe_calloc(size_t num_elements, size_t element_size);
void* safe_realloc(void* ptr, size_t new_size);
void safe_free(void** pointer);

#endif  // __MEMORY_H__