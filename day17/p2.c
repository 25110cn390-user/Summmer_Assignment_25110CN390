//wap to union of arrays
#include <stdio.h>
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void findUnion(int arr1[], int size1, int arr2[], int size2) {
    int unionArr[100]; 
    int k = 0;         
    for (int i = 0; i < size1; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < k; j++) {
            if (unionArr[j] == arr1[i]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionArr[k++] = arr1[i];
        }
    }
    for (int i = 0; i < size2; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < k; j++) {
            if (unionArr[j] == arr2[i]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionArr[k++] = arr2[i];
        }
    }
    printf("Union of the two arrays: ");
    printArray(unionArr, k);
}

int main() {
    // Example
    int arr1[] = {1, 3, 2, 3, 4};
    int arr2[] = {2, 4, 5, 6, 2};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array 1: ");
    printArray(arr1, size1);

    printf("Array 2: ");
    printArray(arr2, size2);

    findUnion(arr1, size1, arr2, size2);

    return 0;
}
