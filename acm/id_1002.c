/**
 * @file id_1002.c
 * @brief HDOJ Problem ID 1002.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-18
 */

#include <stdio.h>
#include <string.h>

int main()
{
    int count, i = 1, length_a = 0, length_b = 0, length_c = 0;
    int index;
    char inc, temp_a, temp_b;
    char a[1001], b[1001], c[1001];
    scanf("%d", &count);
    while (scanf("%s%s", a, b) != EOF) {
        length_a = strlen(a);
        length_b = strlen(b);
        length_c = (length_b > length_a ? length_b : length_a);
        c[length_c + 1] = '\0';
        inc = 0;
        for (index = length_c; index >= 0; index--, length_a--, length_b--) {
            temp_a = length_a >= 1 ? a[length_a - 1] - '0' : 0;
            temp_b = length_b >= 1 ? b[length_b - 1] - '0' : 0;
            if ((c[index] = temp_a + temp_b + inc) >= 10) {
                c[index] = c[index] - 10 + '0';
                inc = 1;
            } else {
                c[index] += '0';
                inc = 0;
            }
        }
        printf("Case %d:\n", i);
        if (c[0] == '0') {
            c[0] = ' ';
            printf("%s + %s =%s\n", a, b, c);
        } else {
            printf("%s + %s = %s\n", a, b, c);
        }
        if (i < count) printf("\n");
        i++;
    }
    return 0;
}
