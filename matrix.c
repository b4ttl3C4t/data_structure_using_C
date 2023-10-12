#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include "matrix.h"

#define MALLOC_ERROR    "The memory allocation for linked list aborts."

int main(void)
{
    Matrix* foo = random_matrix(8, 7, 0, 5);
    matrix_print(foo);

    return 0;
}

Matrix* malloc_matrix(uint8_t row, uint8_t column)
{
    if(row == 0)
    {
        fprintf(stderr, "\n%s%s", "> malloc_matrix: ", MALLOC_ERROR);
        return NULL;
    }
    if(column == 0)
    {
        fprintf(stderr, "\n%s%s", "> malloc_matrix: ", MALLOC_ERROR);
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

    if(new_matrix == NULL)
    {
        fprintf(stderr, "\n%s%s", "> random_matrix: ", MALLOC_ERROR);
        return NULL;
    }

    unsigned int i, j;

    for(i = 0; i < row; ++i)
    {
        for(j = 0; j < column; ++j)
        {
            new_matrix->data[i][j] = minimum + (maximum * ((double)rand() / RAND_MAX));
        }
    }
    new_matrix->row         = row;
    new_matrix->column      = column;
    new_matrix->is_square   = (row == column)? 1: 0;

    return new_matrix;
}
/*
 *sentence (rand() / RAND_MAX) generate a random in the closed interval[0, 1].
 *then mutiple weight by using maximum and plus minimum to assure that its value is in the [minimum, maximum].
 */

void free_matrix(Matrix* matrix)
{
    unsigned int i;

    for(i = 0; i < matrix->row; ++i)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void matrix_print(Matrix* matrix)
{
    unsigned int i, j;

    printf("\n> matrix_print: The size of row and column are *%u* and *%u* respectively.\n",
            matrix->row,
            matrix->column);
    
    for(i = 0; i < matrix->row; ++i)
    {
        printf("%s", "  |");
        for(j = 0; j < matrix->column; ++j)
        {
            printf("%lf\t", matrix->data[i][j]);
        }
        printf("%s", "\n");
    }

    if(matrix->is_square)
    {
        printf("\n%s", "> matrix_print: The matrix is square.");
    }
    else
    {
        printf("\n%s", "> matrix_print: The matrix is *not* square.");
    }
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