//wap to merge two sorted arrays
#include <stdio.h>

void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0; 
    int j = 0; 
    int k = 0; 

    // traverse both arrays 
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // store remaining elements of 1st array
    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    // store remaining elements of 2nd array
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int n1, n2;

    printf("Enter number of elements in first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d sorted elements: ", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("\nEnter %d sorted elements: ", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // for storing the combined elements
    int merged[n1 + n2];

    // merge the arrays
    mergeSortedArrays(arr1, n1, arr2, n2, merged);

    printf("\nMerged sorted array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
