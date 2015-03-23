/**
 * @file id_694.c
 * @brief AOAPC I 694
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-22
 */

#include <stdio.h>

int main()
{
    int L;
    long A;
    int num_case = 1;
    while (scanf("%ld%d", &A, &L) && (!(A < 0 && L < 0))) {
        long A_source = A;
        int count = 1;
        if (A != 1) {
            while (1) {
                if (A & 0x1)
                    A = 3 * A + 1;
                else
                    A = A / 2;
                if (A == 1) {
                    count++;
                    break;
                } else if (A > L) {
                    break;
                }
                count++;
            }
        }
        printf("Case: %d: A = %ld, limit = %d, number of terms = %d\n",
                num_case, A_source, L, count);
        num_case++;
    }
    return 0;
}
