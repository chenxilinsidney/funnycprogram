/**
 * @file UseStdlib.c
 * @brief use standard library.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-10
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<errno.h>
#include<float.h>
#include<limits.h>
#include<assert.h>

const int kmax_line_width = 80;
const char kdisplay_char = '=';
void display_string_in_middle(char* string)
{
    int string_length = strlen(string);
    if (string_length < kmax_line_width) {
        int line_offset = (kmax_line_width - string_length) / 2;
        int i = 0;
        for ( ; i < line_offset; i++)
            printf("=");
        printf("%s", string);
        i += string_length;
        for ( ; i < kmax_line_width; i++)
            printf("=");
        printf("\n");
    } else {
        printf("%s", string);
        printf("\n");
    }
}


int main(void)
{
    int i,j;
    display_string_in_middle("use for calculation");
    int a_i = -5;
    printf("abs for %d is %d.\n", a_i, abs(a_i));
    int d_i = 85, d_j = 6;
    div_t d_out = div(d_i, d_j);
    printf("div for %d / %d is %d...%d.\n", d_i, d_j,
            d_out.quot, d_out.rem);
    display_string_in_middle("use for generate random value");
    printf("max random value is %d\n", RAND_MAX); 
    const int krand_time = 20;
    const int krand_max = 60;
    printf("max value is %d\n", krand_max); 
    srand((unsigned int)time(NULL));
    for (i = 0; i < krand_time; i++) {
        printf("%d:random value is %d\n", i + 1, rand() % krand_max);
    }
    display_string_in_middle("use for generate random list");
#define LIST_RAND_LENGHT 10
    int list[LIST_RAND_LENGHT] = {0};
    for (i = 0; i < LIST_RAND_LENGHT; i++) list[i] = i;
    printf("source random list is:");
    for (j = 0; j < LIST_RAND_LENGHT; j++)
        printf(" %d", list[j]);
    printf("\n");
    for (i = 0; i < krand_time; i++) {
        int temp_i = rand() % LIST_RAND_LENGHT;
        int temp_j = rand() % LIST_RAND_LENGHT;
        int temp = list[temp_i];
        list[temp_i] = list[temp_j];
        list[temp_j] = temp; 
        printf("%d:random list is:", i + 1);
        for (j = 0; j < LIST_RAND_LENGHT; j++)
            printf(" %d", list[j]);
        printf("\n");
    }
#undef LIST_RAND_LENGHT
    display_string_in_middle("use for string interger conversion");
#define INTEGER_STRING_MAX 30
    printf("in put integer string: ");
    char si[INTEGER_STRING_MAX] = {0};
    scanf("%s", si);
    int si_out = atoi(si);
    printf("integer value: %d\n", si_out);
#undef INTEGER_STRING_MAX
    display_string_in_middle("use for math");
    display_string_in_middle("gcc argument add: -lm");
    double m_i = -3.3;
    printf("errno value = %d\n", errno); 
    printf("%lf sqrt value: %lf\n", m_i, sqrt(m_i));
    if (EDOM == errno)
        printf("errno value = EDOM\n"); 
    m_i = 3.3;
    printf("%lf exp value: %lf\n", DBL_MAX, exp(DBL_MAX));
    if (ERANGE == errno)
        printf("errno value = ERANGE\n"); 
    printf("%lf pow value: %lf\n", m_i, pow(m_i, 2.0));
    display_string_in_middle("use for cpu time tick high accuracy");
    printf("%ld clocks per second\n", CLOCKS_PER_SEC);
    clock_t c_i = clock();
    printf("%ld clocks now\n", (long)c_i);
    i = INT_MAX;
    while(i--) ;
    clock_t c_j = clock();
    printf("%ld clocks now\n", (long)c_j);
    clock_t c_k = c_j - c_i;
    printf("use clocks: %ld use time: %lf\n", (long)c_k,
            (double)c_k / CLOCKS_PER_SEC);
    display_string_in_middle("use for cpu time date accuracy:second");
    time_t tm_t1;
    if (-1 == time(&tm_t1)) assert(0);
    printf("second offset from 1070.01.01 now: %ld\n", tm_t1);
    time_t tm_t2;
    i = INT_MAX;
    while(i--) ;
    if (-1 == time(&tm_t2)) assert(0);
    printf("second offset from 1070.01.01 now: %ld\n", tm_t2);
    printf("use seconds: %lf\n", difftime(tm_t2, tm_t1));
    char tm_str[100] = {0};
    char* tm_temp = ctime(&tm_t2);
    memcpy(tm_str, tm_temp, strlen(tm_temp) + 1);
    printf("time string: %s\n", tm_str);
    struct tm tm_1 = *(gmtime(&tm_t2));
    printf("gmtime reconstruct: %02d:%02d:%02d /%02d/%02d/%02d\n",
            tm_1.tm_sec, tm_1.tm_min, tm_1.tm_hour,
            tm_1.tm_mday, tm_1.tm_mon + 1, tm_1.tm_year + 1900);
    struct tm tm_2 = *(localtime(&tm_t2));
    printf("localtime reconstruct: %02d:%02d:%02d /%02d/%02d/%02d\n",
            tm_2.tm_sec, tm_2.tm_min, tm_2.tm_hour,
            tm_2.tm_mday, tm_2.tm_mon + 1, tm_2.tm_year + 1900);
    display_string_in_middle("get system environment");
    printf("user env: %s\n", getenv("PATH"));
    display_string_in_middle("use system command");
    if(system(NULL)) {
        printf("list directory:\n");
        system("dir");
        printf("\n");
    } else {
        printf("can not use system command.\n");
    }
    display_string_in_middle("terminal system");
    exit(EXIT_SUCCESS);
    return 0;
}

