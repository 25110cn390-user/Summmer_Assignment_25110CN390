//wap to intersection of arrays
#include <stdio.h>
int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; 
        }
    }
    return 0;
}
int findIntersection(int arr1[], int size1, int arr2[], int size2, int intersectResult[]) {
    int k = 0; 
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            // If a match is found
            if (arr1[i] == arr2[j]) {
                if (!isDuplicate(intersectResult, k, arr1[i])) {
                    intersectResult[k] = arr1[i];
                    k++;
                }
                break; 
            }
        }
    }
    return k; // Return the total number of elements after intersection
}

int main() {
    int arr1[] = {1, 2, 2, 4, 6, 7};
    int arr2[] = {2, 3, 6, 7, 2, 9};
    int j;
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int intersectResult[size1 < size2 ? size1 : size2]; 

    // Calculate intersection
    int intersectSize = findIntersection(arr1, size1, arr2, size2, intersectResult);
    printf("Array 1: ");
    for (int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    
    printf("\nArray 2: ");
    for (int i = 0; i < size2; i++) printf("%d ", arr2[ j = i]); 

    printf("\nIntersection: ");
    if (intersectSize == 0) {
        printf("No common elements found.");
    } else {
        for (int i = 0; i < intersectSize; i++) {
            printf("%d ", intersectResult[i]);
        }
    }
    printf("\n");

    return 0;
}
