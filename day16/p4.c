//wap to remove duplicates from the end
#include <stdio.h>
int removeDuplicatesFromEnd(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // If a duplicate is found later in the array
            if (arr[i] == arr[j]) {
                // Shift all subsequent elements  to the left
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
                // Decrement j 
                j--; 
            }
        }
    }
    return size; 
}

int main() {
    int arr[] = {4, 5, 4, 6, 5, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    size = removeDuplicatesFromEnd(arr, size);

    printf("Array after removing duplicates from the end: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
