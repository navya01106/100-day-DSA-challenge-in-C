
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    
    int matrix[n][n];
    
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    bool isIdentity = true;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = false;
                    break;
                }
            }
            else {
                if (matrix[i][j] != 0) {
                    isIdentity = false;
                    break;
                }
            }
        }
        if (!isIdentity) {
            break;
        }
    }
    
    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }
    
    return 0;
}