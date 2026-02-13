/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include<stdio.h>
 #include<stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int r = matrixSize;
    int c = matrixColSize[0];
    
    *returnSize = r * c;
    int* result = (int*)malloc(r * c * sizeof(int));
    
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int index = 0;
    
    while(top <= bottom && left <= right) {
        for(int j = left; j <= right; j++)
            result[index++] = matrix[top][j];
        top++;
        
        for(int i = top; i <= bottom; i++)
            result[index++] = matrix[i][right];
        right--;
        
        if(top <= bottom) {
            for(int j = right; j >= left; j--)
                result[index++] = matrix[bottom][j];
            bottom--;
        }
        
        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                result[index++] = matrix[i][left];
            left++;
        }
    }
    
    return result;
}
