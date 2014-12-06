/**
 * @file Functionjmp.c
 * @brief test c function setjmp and longjmp
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-06
 */

#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;

void is_input_number(char c)
{
    if (c >= '0' && c <= '9') {
        printf("The character is a number.\n");
    } else {
        printf("The character is not a number."
        "Input wrong!back to main function!.\n");
        getchar();
        longjmp(buf, 1);  // use second
    }
}

int main(void)
{
    setjmp(buf); // use first
    printf("Main function start!\n");
    printf("Please input a character.\n");
    while(1) {
        char c;
        scanf("%c", &c);
        is_input_number(c);
        printf("Please input a character again.\n");
        getchar();
    }
}

