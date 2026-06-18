//wap to find pair with given sum
#include <stdio.h>
void findPair(int arr[], int size, int targetSum) {
    int pairFound = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            
            if (arr[i] + arr[j] == targetSum) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                pairFound = 1;
                return; 
            }
        }
    }

    if (!pairFound) {
        printf("No pair found with the given sum.\n");
    }
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int targetSum = 10;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTarget Sum: %d\n\n", targetSum);

    findPair(arr, size, targetSum);

    return 0;
}
