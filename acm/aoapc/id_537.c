/**
 * @file id_537.c
 * @brief AOAPC I 537
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 101
char line[2][MAX_LINE_LENGTH];

double prefix(int character)
{
    switch (character) {
        case 'k':
            return 1000.0;
        case 'm':
            return 0.001;
        case 'M':
            return 1000000.0;
    }
    return 0.0;
}

int main()
{
    int num_case, index_case = 0;
    scanf("%d\n", &num_case);
    while (num_case--) {
        index_case++;
        double I, U, P;
        int flag_get_iup[3] = {0};
        int text;
        while ((text = getchar()) != '\n') {
            if (text == 'I' && (text = getchar()) == '=') {
                scanf("%lf", &I);
                flag_get_iup[0] = 1;
                if ((text = getchar()) != 'A')
                    I *= prefix(text);
            } else if (text == 'U' && (text = getchar()) == '=') {
                scanf("%lf", &U);
                flag_get_iup[1] = 1;
                if ((text = getchar()) != 'V')
                    U *= prefix(text);
            } else if (text == 'P' && (text = getchar()) == '=') {
                scanf("%lf", &P);
                flag_get_iup[2] = 1;
                if ((text = getchar()) != 'W')
                    P *= prefix(text);
            }
        }
        printf("Problem #%d\n", index_case);
        if (!flag_get_iup[0])
            printf("I=%.2lfA\n", P / U);
        else if (!flag_get_iup[1])
            printf("U=%.2lfV\n", P / I);
        else
            printf("P=%.2lfW\n", I * U);
        printf("\n");
    }
    return 0;
}
