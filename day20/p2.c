//wap to to check symmetric matrix
#include <stdio.h>
#include<math.h>
int main() {
    int rows, cols;
    int isSymmetric = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // checking square matrix
    if (rows != cols) {
        printf("\nThe matrix is not a square matrix, so it cannot be symmetric.\n");
        return 0;
    }

    int matrix[rows][cols];
    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check for symmetry 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // if mismatch
                break;
            }
        }
        if (!isSymmetric) {
            break; 
        }
    }

    //  result
    if (isSymmetric) {
        printf("\nThe given matrix is a Symmetric Matrix.\n");
    } else {
        printf("\nThe given matrix is NOT a Symmetric Matrix.\n");
    }

    return 0;
}
