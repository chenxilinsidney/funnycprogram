/**
 * @file id_10300.c
 * @brief AOAPC I 10300
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-22
 */

#include <stdio.h>

int main()
{
    int test_case_num;
    int num_farmer;
    int size_farmeyard;
    int environment_friendliness;
    long budget;
    scanf("%d", &test_case_num);
    while (test_case_num--) {
        scanf("%d", &num_farmer);
        budget = 0;
        while (num_farmer--) {
            scanf("%d%*d%d", &size_farmeyard, &environment_friendliness);
            budget += (long)size_farmeyard * environment_friendliness;
        }
        printf("%ld\n", budget);
    }
    return 0;
}
