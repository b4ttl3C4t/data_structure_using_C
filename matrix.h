#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

//construct mathematical model of matrix: 
typedef struct Matrix_s
{
    uint8_t row;
    uint8_t column;
    bool is_square;
    double **data;
}Matrix;

//function prototype of operation of matrix(setting):
Matrix * malloc_matrix(uint8_t, uint8_t);
Matrix * random_matrix(uint8_t, uint8_t, double, double);
void     free_matrix(Matrix*);
void     matrix_print(Matrix*);

//function prototype of operation of matrix(math):
Matrix * matrix_addition(Matrix*);
Matrix * matrix_mutiplication(Matrix*, Matrix*);
Matrix * matrix_transpose(Matrix*);
Matrix * UV_decomposition(Matrix*);
int64_t  determinant(Matrix*);
Matrix * matrix_inverse(Matrix*);

#endif