/**
 * @file square_matrix_multiply_by_divide_conquer.c
 * @brief caculate matrix C = A*B;A:M*N B:N*P C:M*P
 * with divide and conquer method.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-05
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>
#define NDEBUG
#include <assert.h>

#include "memory.h"
#define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

/// matrix size
#define N 4
/// matrix A, B, C
TYPE matrix_a[N*N] = {1, 0, 3, 3, 3, 5, 3, 4, 2, 4, 1, 5, 7, 5, 2, 0};
TYPE matrix_b[N*N] = {3, 1, 3, 4, 2, 2, 1, 5, 3, 4, 4, 2, 6, 4, 9, 4};
TYPE matrix_c[N*N] = {0}; 

/**
 * @brief get matrix C from C = A*B
 *
 * @param matrix_A matrix input A
 * @param matrix_B matrix input B
 * @param matrix_C matrix output C
 * @param size_N matrix C size:N * N
 * matrix B size:N * N
 * matrix C size:N * N
 */
void square_matrix_multiply(TYPE* matrix_A,
        TYPE* matrix_B,
        TYPE* matrix_C,
        TYPE size_N)
{
    DEBUG_PRINT_STRING("In recursion now.\n");
    /// demand size_N = 2^N
    assert((log2((double)size_N) - (int)log2((double)size_N)) <= FLT_EPSILON);
    DEBUG_PRINT_VALUE("%d", size_N);
    if(size_N == 1) {
        *matrix_C = *matrix_A * *matrix_B;
        DEBUG_PRINT_VALUE("%d", *matrix_C);
    } else {
        /// get four smaller size matrix for each A,B matrix
        TYPE size_half_N = (unsigned)size_N >> 1;
        DEBUG_PRINT_VALUE("%d", size_half_N);
        TYPE i, j;
        /// malloc memory
        TYPE* matrix_A11 = SMALLOC(size_half_N * size_half_N, TYPE);
        TYPE* matrix_A12 = SMALLOC(size_half_N * size_half_N, TYPE);
        TYPE* matrix_A21 = SMALLOC(size_half_N * size_half_N, TYPE);
        TYPE* matrix_A22 = SMALLOC(size_half_N * size_half_N, TYPE);
        TYPE* matrix_B11 = SMALLOC(size_half_N * size_half_N, TYPE);
        TYPE* matrix_B12 = SMALLOC(size_half_N * size_half_N, TYPE);
        TYPE* matrix_B21 = SMALLOC(size_half_N * size_half_N, TYPE);
        TYPE* matrix_B22 = SMALLOC(size_half_N * size_half_N, TYPE);
        /// copy data
        for(i = 0; i < size_half_N; i++) {
            memcpy(matrix_A11 + i * size_half_N,
                    matrix_A + i * size_N,
                    size_half_N * sizeof(TYPE));
            memcpy(matrix_A12 + i * size_half_N,
                    matrix_A + size_half_N + i * size_N,
                    size_half_N * sizeof(TYPE));
            memcpy(matrix_A21 + i * size_half_N,
                    matrix_A + (size_half_N + i) * size_N,
                    size_half_N * sizeof(TYPE));
            memcpy(matrix_A22 + i * size_half_N,
                    matrix_A + size_half_N +(size_half_N + i) * size_N,
                    size_half_N * sizeof(TYPE));
            memcpy(matrix_B11 + i * size_half_N,
                    matrix_B + i * size_N,
                    size_half_N * sizeof(TYPE));
            memcpy(matrix_B12 + i * size_half_N,
                    matrix_B + size_half_N + i * size_N,
                    size_half_N * sizeof(TYPE));
            memcpy(matrix_B21 + i * size_half_N,
                    matrix_B + (size_half_N + i) * size_N,
                    size_half_N * sizeof(TYPE));
            memcpy(matrix_B22 + i * size_half_N,
                    matrix_B + size_half_N +(size_half_N + i) * size_N,
                    size_half_N * sizeof(TYPE));
            DEBUG_PRINT_VALUE("%d", *(matrix_A11 + i * size_half_N));
            DEBUG_PRINT_VALUE("%d", *(matrix_A12 + i * size_half_N));
            DEBUG_PRINT_VALUE("%d", *(matrix_A21 + i * size_half_N));
            DEBUG_PRINT_VALUE("%d", *(matrix_A22 + i * size_half_N));
            DEBUG_PRINT_VALUE("%d", *(matrix_B11 + i * size_half_N));
            DEBUG_PRINT_VALUE("%d", *(matrix_B12 + i * size_half_N));
            DEBUG_PRINT_VALUE("%d", *(matrix_B21 + i * size_half_N));
            DEBUG_PRINT_VALUE("%d", *(matrix_B22 + i * size_half_N));
        }
        /// get result for each smaller matrix multiply
        TYPE* matrix_C1 = SMALLOC(size_half_N * size_half_N, TYPE);
        TYPE* matrix_C2 = SMALLOC(size_half_N * size_half_N, TYPE);
        square_matrix_multiply(matrix_A11, matrix_B11, matrix_C1, size_half_N);
        square_matrix_multiply(matrix_A12, matrix_B21, matrix_C2, size_half_N);
        for(i = 0; i < size_half_N; i++) {
            for(j = 0; j < size_half_N; j++) {
                matrix_C[i * size_N + j] =
                    matrix_C1[i * size_half_N + j] +
                    matrix_C2[i * size_half_N + j];
            }
        }
        square_matrix_multiply(matrix_A11, matrix_B12, matrix_C1, size_half_N);
        square_matrix_multiply(matrix_A12, matrix_B22, matrix_C2, size_half_N);
        for(i = 0; i < size_half_N; i++) {
            for(j = 0; j < size_half_N; j++) {
                matrix_C[i * size_N + size_half_N + j] =
                    matrix_C1[i * size_half_N + j] +
                    matrix_C2[i * size_half_N + j];
            }
        }
        square_matrix_multiply(matrix_A21, matrix_B11, matrix_C1, size_half_N);
        square_matrix_multiply(matrix_A22, matrix_B21, matrix_C2, size_half_N);
        for(i = 0; i < size_half_N; i++) {
            for(j = 0; j < size_half_N; j++) {
                matrix_C[(size_half_N + i) * size_N + j] =
                    matrix_C1[i * size_half_N + j] +
                    matrix_C2[i * size_half_N + j];
            }
        }
        square_matrix_multiply(matrix_A21, matrix_B12, matrix_C1, size_half_N);
        square_matrix_multiply(matrix_A22, matrix_B22, matrix_C2, size_half_N);
        for(i = 0; i < size_half_N; i++) {
            for(j = 0; j < size_half_N; j++) {
                matrix_C[(size_half_N + i) * size_N + size_half_N + j] =
                    matrix_C1[i * size_half_N + j] +
                    matrix_C2[i * size_half_N + j];
            }
        }
        DEBUG_PRINT_VALUE("%d", *matrix_C);
        /// free memory
        SFREE(&matrix_A11);
        SFREE(&matrix_A12);
        SFREE(&matrix_A21);
        SFREE(&matrix_A22);
        SFREE(&matrix_B11);
        SFREE(&matrix_B12);
        SFREE(&matrix_B21);
        SFREE(&matrix_B22);
        SFREE(&matrix_C1);
        SFREE(&matrix_C2);
    }
    DEBUG_PRINT_STRING("Out recursion now.\n");
    return;
}

int main(void)
{
    /// square matrix multiply
    square_matrix_multiply(matrix_a, matrix_b, matrix_c, N);
    /// output result
    TYPE i, j;
    printf("matrix c = \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", matrix_c[i * N + j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
