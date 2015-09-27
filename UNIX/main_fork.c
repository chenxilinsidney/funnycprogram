/**
 * @file main_fork.c
 * @brief fork function
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-08-12
 */

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int g_num = 30;

int main(void)
{
    int num = 20;
    printf("in main function\n");
    pid_t pid;
    int i = 0;
    for (i = 0; i < 2; i++) { 
        if ((pid = fork()) < 0) {
            perror("can not fork");
            exit(errno);
        } else if (pid == 0) {
            g_num++;
            num++;
        } else {
            ;  // sleep(2);
        }
        printf("var: g_num = %d, num = %d\n", g_num, num);
        printf("ppid = %d, pid = %d\n", getppid(), getpid());
    }
    return 0;
}
