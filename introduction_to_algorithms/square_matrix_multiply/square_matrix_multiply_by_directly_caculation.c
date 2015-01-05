/**
 * @file square_matrix_multiply_by_directly_caculation.c
 * @brief caculate matrix C = A*B;A:M*N B:N*P C:M*P
 * with directly caculation method
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-05
 */

#include <stdio.h>
#include <stdlib.h>
// #define NDEBUG
#include <assert.h>

#include "memory.h"
// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

/// matrix size
#define M 2
#define N 2
#define P 2
/// matrix A, B, C
TYPE matrix_a[M*N] = {1, 0, 3, 5};
TYPE matrix_b[N*P] = {3, 1, 2, 2};
TYPE matrix_c[M*P] = {0}; 


void square_matrix_multiply(TYPE* matrix_A,
        TYPE* matrix_B,
        TYPE* matrix_C,
        TYPE size_M,
        TYPE size_N,
        TYPE size_P)
{
    TYPE i, j, k;
    for (i = 0; i < size_M; i++) {
        for (j = 0; j < size_P; j++) {
            for (k = 0; k < size_N; k++) {
                matrix_C[i * size_P + j] +=
                    matrix_A[i * size_N + k] * matrix_B[k * size_P + j];
            }
        }
    }
    return;
}

int main(void)
{
    /// square matrix multiply
    square_matrix_multiply(matrix_a, matrix_b, matrix_c, M, N, P);
    /// output result
    TYPE i, j;
    printf("matrix c = \n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < P; j++) {
            printf("%3d ", matrix_c[i * P + j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
