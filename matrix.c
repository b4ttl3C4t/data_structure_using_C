#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define MATRIX_SIZE 255

//construct mathematical model of matrix: 
typedef struct Matrix_s
{
    uint8_t row;
    uint8_t column;
    bool is_square;
    double **data;
}Matrix;

//function prototype of operation of matrix(setting):
Matrix* malloc_matrix(uint8_t, uint8_t);
Matrix* random_matrix(uint8_t, uint8_t, double, double);
void    free_matrix(Matrix*);
void    traverse(Matrix*);

//function prototype of operation of matrix(math):
Matrix* matrix_addition(Matrix*);
Matrix* matrix_mutiplication(Matrix*, Matrix*);
Matrix* transpose(Matrix*);
Matrix* UV_decomposition(Matrix*);
int64_t determinant(Matrix*);
Matrix* inverse(Matrix*);

int32_t main(void)
{
    
    return 0;
}

Matrix* malloc_matrix(uint8_t row, uint8_t column)
{
    if(row > MATRIX_SIZE || row == 0)
    {
        return NULL;
    }
    if(column > MATRIX_SIZE || column == 0)
    {
        return NULL;
    }

    Matrix *new_matrix      = calloc(1, sizeof(Matrix*));
    new_matrix->column      = column;
    new_matrix->row         = row;
    new_matrix->is_square   = (column == row) ? 1 : 0;
    new_matrix->data        = calloc(row, sizeof(*(new_matrix->data)));
    for(int i = 0; i < row; ++i)
    {
        new_matrix->data[i] = calloc(column, sizeof(**(new_matrix->data)));
    }

    return new_matrix;
}

Matrix* random_matrix(uint8_t row, uint8_t column, double minimum, double maximum)
{
    srand(time(NULL));
    Matrix *new_matrix = malloc_matrix(row, column);
    
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < column; ++j)
        {
            new_matrix->data[i][j] = minimum + (maximum * (rand() / RAND_MAX));
        }
    }

    return new_matrix;
}
/*
 *sentence (rand() / RAND_MAX) generate a random in the closed interval[0, 1].
 *then mutiple weight by using maximum and plus minimum to assure that its value is in the [minimum, maximum].
 */

void free_matrix(Matrix* matrix)
{
    for(int i = 0; i < matrix->row; ++i)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void traverse(Matrix* matrix)
{
    
}

Matrix* matrix_mutiplication(Matrix* matrix_x, Matrix* matrix_y)
{
    if(matrix_x->column != matrix_y->row)
    {
        return NULL;
    }

    Matrix *product = malloc_matrix(matrix_x->column, matrix_y->row);

    double n = matrix_x->row; //can be written by sentence "double n = matrix_y->column" .
    for(int i = 0; i < product->row; ++i)
    {       
        for(int j = 0; j < product->column; ++j)
        {
            for(int k = 0; k < n; ++k)
            {
                product->data[i][j] += matrix_x->data[i][k] * matrix_y->data[k][j];
            }
        }
    }

    return product;
}