//wap to merge arrays
#include <stdio.h>

int main() {
    int size1, size2, size3;
    int i, j;
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    
    int arr1[size1]; 
    printf("Enter %d elements for the first array:\n", size1);
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("\nEnter the size of the second array: ");
    scanf("%d", &size2);
    
    int arr2[size2]; 
    printf("Enter %d elements for the second array:\n", size2);
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Define the size of the merged array
    size3 = size1 + size2;
    int mergedArr[size3];

    // Copy elements from the 1st array
    for (i = 0; i < size1; i++) {
        mergedArr[i] = arr1[i];
    }

    //  Copy elements from the second array 
    for (j = 0; j < size2; j++) {
        mergedArr[size1 + j] = arr2[j];
    }

    printf("\nThe merged array is:\n");
    for (i = 0; i < size3; i++) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");

    return 0;
}
