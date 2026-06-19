//wap to find diagonal sum
#include <stdio.h>

int main() {
    int size, i, j;
    int principal_sum = 0, secondary_sum = 0;
    int matrix[10][10];

    printf("Enter the size of the square matrix (max 10): ");
    scanf("%d", &size);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < size; i++) {
        principal_sum += matrix[i][i];               
        secondary_sum += matrix[i][size - i - 1];      
    }

    // Output results
    printf("\nSum of Principal Diagonal: %d\n", principal_sum);
    printf("Sum of Secondary Diagonal: %d\n", secondary_sum);

    return 0;
}
