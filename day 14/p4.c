//wap to find duplictes in array
#include <stdio.h>

int main() {
    int arr[50] ;
    int size = sizeof(arr) / sizeof(arr[0]);
    int visited[size];
    printf("enter the elemnets of array:");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }

    printf("Duplicate elements: ");
    for (int i = 0; i < size; i++) {
        if (visited[i] == 1) continue; 

        int isDuplicate = 0;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                visited[j] = 1; 
            }
        }

        if (isDuplicate) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
