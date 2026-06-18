//wap to selection sort
#include <stdio.h>

void selectionSort(int arr[], int size) {
    // Move the boundary one by one
    for (int i = 0; i < size - 1; i++) {
        // Assume the current position holds the minimum element
        int min_idx = i;
        
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index if a smaller element is found
            }
        }
        
    
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, size);
    
    // Call the sorting function
    selectionSort(arr, size);
    
    printf("Sorted array:   ");
    printArray(arr, size);
    
    return 0;
}
