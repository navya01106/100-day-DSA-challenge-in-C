//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

#include<stdio.h>
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    
    int rows[200] = {0};
    int cols[200] = {0};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rows[i] || cols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}