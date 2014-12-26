
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "memory.h"

#define DEBUG_PRINT
#include "debug_print.h"

int main(void)
{
    int* p = SCALLOC(4, int);
    p = SREALLOC(p, 4, int);
    SFREE(&p);
    int i = 5;
    DEBUG_PRINT_STATE;
    DEBUG_PRINT_VALUE("%d", i);
    printf("p = %p\n", p);
#ifdef __FUNC__
    printf("__FUNC__ = %d\n", __FUNC__);
#endif
    printf("__GNUC__ = %d\n", __GNUC__);
    printf("__GNUC_MINOR__ = %d\n", __GNUC_MINOR__);
#ifdef _GNU_SOURCE
    printf("_GNU_SOURCE = %d\n", _GNU_SOURCE);
#endif
#ifdef _DEFAULT_SOURCE
    printf("_DEFAULT_SOURCE = %d\n", _DEFAULT_SOURCE);
#endif
#ifdef __STRICT_ANSI__
    printf("__STRICT_ANSI__ = %d\n", __STRICT_ANSI__);
#endif
#ifdef _BSD_SOURCE
    printf("_BSD_SOURCE = %d\n", _BSD_SOURCE);
#endif
#ifdef _SVID_SOURCE
    printf("_SVID_SOURCE = %d\n", _SVID_SOURCE);
#endif
#ifdef __cplusplus
    printf("__cplusplus = %d\n", __cplusplus);
#endif
#ifdef _POSIX_C_SOURCE
    printf("_POSIX_C_SOURCE = %d\n", _POSIX_C_SOURCE);
#endif
#ifdef _POSIX_SOURCE
    printf("_POSIX_SOURCE = %d\n", _POSIX_SOURCE);
#endif
    return 0;
}
