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
#define M 4
#define N 4
#define P 4
/// matrix A, B, C
TYPE matrix_a[M*N] = {1, 0, 3, 3, 3, 5, 3, 4, 2, 4, 1, 5, 7, 5, 2, 0};
TYPE matrix_b[N*P] = {3, 1, 3, 4, 2, 2, 1, 5, 3, 4, 4, 2, 6, 4, 9, 4};
TYPE matrix_c[M*P] = {0}; 

/**
 * @brief get matrix C from C = A*B
 *
 * @param matrix_A matrix input A
 * @param matrix_B matrix input B
 * @param matrix_C matrix output C
 * @param size_M matrix A size:M * N
 * @param size_N matrix B size:N * P
 * @param size_P matrix C size:M * P
 */
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
                matrix_C[i * size_P + j] = 0;
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
