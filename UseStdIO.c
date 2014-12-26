/**
 * @file UseStdIO.c
 * @brief using standard io by c.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-12
 */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(void)
{
    FILE* fp = fopen("a.txt", "r");
    if (NULL == fp) {
        perror("god");
        printf("%d\n", errno);
        fflush(stdout);
        exit(EXIT_FAILURE);
    }
    perror("god");
    printf("EOF = %d\n", EOF);
    printf("FOPEN_MAX = %d\n", FOPEN_MAX);
    printf("FILENAME_MAX = %d\n", FILENAME_MAX);
    // int c;
    // if (EOF != (c = getchar())) {
    //     printf("c = %c\n", (unsigned char)c);
    // } else {
    //     printf("%d\n", c);
    //     exit(EXIT_FAILURE);
    // }
    char buffer[100];
    if (NULL != fgets(buffer, 100, fp)) {
        int a, b;
        printf("%d\n", sscanf(buffer, "%d %d", &a, &b));
    } else {
        perror("can not get line from fp");
    }
    return EXIT_SUCCESS;
}

