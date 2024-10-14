// Name: Peter Barybin
// KUID: 3057437
// LAB Session: Thursday 4 p.m.
// LAB Assignment: 05
// Description: ADD

#include <stdio.h>
// quickly set size of matrices, this is also an error check on adding and multiplying matrices because they are the same size 
// (needed for addition) and the number of columns of m1 or m2 will equal the number of rows of the other (needed for multiplication)
#define SIZE 5

//use struct to create Matrix type and allow matrix to be returned from functions
typedef struct {
    int matrix[SIZE][SIZE];
} Matrix;

//function that adds two matrices and returns result
Matrix addMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE]) {
    Matrix result;
    for (int i=0; i < SIZE; i++) {
        for (int j=0; j < SIZE; j++) {
            result.matrix[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}
//function that multiplies two matrices and returns result (SIZE ensures compatible dimensions)
Matrix multiplyMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE]) {
    Matrix result;
    //set each entry in result to 0 so we can add to them in the multiplication
    for (int i=0; i < SIZE; i++) {
        for (int j=0; j < SIZE; j++) {
            result.matrix[i][j] = 0;
        }
    }
    //multiply row in mat1 by columns in mat2 (dot product) and then move to next row in mat1 and repeat 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result.matrix[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

//function that returns transpose of a matrix
Matrix transposeMatrix(int mat[SIZE][SIZE]) {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.matrix[i][j] = mat[j][i];
        }
    }
    return result;
}

//function that prints matrix in user friendly way
void printMatrix(Matrix mat) {
    printf("\n\n");
    for (int i = 0; i < SIZE; i++) {
        printf("\n");
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", mat.matrix[i][j]);
        }
    }
}

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    Matrix added;
    Matrix multiplied;
    Matrix transposed;

    added = addMatrices(m1, m2);
    printf("\n\nMatrices added:");
    printMatrix(added);
    multiplied = multiplyMatrices(m1, m2);
    printf("\n\nMatrices multiplied:");
    printMatrix(multiplied);
    transposed = transposeMatrix(m1);
    printf("\n\nMatrix transposed:");
    printMatrix(transposed);
}