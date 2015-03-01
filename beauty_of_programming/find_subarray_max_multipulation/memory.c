/**
 * @copyright Copyright (C),1988-1999, Cita109 Tech. Co., Ltd.
 * @file memory.c
 * @brief memory allocate and free with checking.
 * @author author           time      version   desc
 * @author Chen Xi Lin    14/12/17      1.2   build the module
 * @version 1.2
 * @date 2014-06-08
 */

#include "memory.h"

/**
 * @brief malloc with checking.
 *
 * @param[in]     size   bytes of memory
 *
 * @return pointer to memory
 */
void* safe_malloc(size_t size)
{
    void* new_mem;
    new_mem = malloc(size);
    if (NULL == new_mem) {
        printf("Out of memory!\n");
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    return new_mem;
}

/**
 * @brief malloc with checking.
 *
 * @param[in]     num_elements element nums
 * @param[in]     element_size size of element
 *
 * @return pointer to memory
 */
void* safe_calloc(size_t num_elements, size_t element_size)
{
    void* new_mem;
    new_mem = calloc(num_elements, element_size);
    if (NULL == new_mem) {
        printf("Out of memory!\n");
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    return new_mem;
}

/**
 * @brief realloc with checking.
 *
 * @param[in]      ptr  pointer to old memory
 * @param[in]      new_size new memory size
 *
 * @return pointer to memory
 */
void* safe_realloc(void* ptr, size_t new_size)
{
    void* new_mem;
    new_mem = realloc(ptr, new_size);
    if (NULL == new_mem) {
        printf("Out of memory!\n");
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    return new_mem;
}

/**
 * @brief free with assignment to NULL.
 *
 * @param[in]     pointer    pointer to memory
 */
void safe_free(void** pointer)
{
    free(*pointer);
    *pointer = NULL;
}