//wap to find common elements
#include <stdio.h>

int main() {
    int arr1[] = {4, 2, 9, 6, 2, 3, 8};
    int arr2[] = {2, 6, 1, 10, 6, 4};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int common[size1];
    int commonCount = 0;
    
    printf("Array 1: ");
    for(int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    
    printf("\nArray 2: ");
    for(int i = 0; i < size2; i++) printf("%d ", arr2[i]);
    
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                
                int isDuplicate = 0;
                for (int k = 0; k < commonCount; k++) {
                    if (arr1[i] == common[k]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate) {
                    common[commonCount] = arr1[i];
                    commonCount++;
                }
                break; 
            }
        }
    }
    printf("\n\nCommon elements: ");
    if (commonCount == 0) {
        printf("None");
    } else {
        for (int i = 0; i < commonCount; i++) {
            printf("%d ", common[i]);
        }
    }
    printf("\n");

    return 0;
}
