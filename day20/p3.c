//wap to find row wise sum
#include <stdio.h>

int main() {
    int rows, cols;
    int i, j, rowSum;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n--- Row-Wise Sum Results ---\n");

    // Logic 
    for (i = 0; i < rows; i++) {
        rowSum = 0; // Reset sum 
        for (j = 0; j < cols; j++) {
            rowSum += matrix[i][j]; 
        }
        printf("Sum of elements in Row %d = %d\n", i + 1, rowSum);
    }

    return 0;
}
