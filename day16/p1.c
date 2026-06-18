//wap to find missing number in an array
#include<stdio.h>
int findMissingNumber(int arr[], int size) {
    int xor_all = 0;
    int xor_arr = 0;
    int N = size + 1; 

    // XOR all numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        xor_all ^= i;
    }

    // XOR all elements present in the array
    for (int i = 0; i < size; i++) {
        xor_arr ^= arr[i];
    }

    // The missing number is the XOR of both results
    return xor_all ^ xor_arr;
}

int main() {
    // Example array 
    int arr[] = {1, 2, 4, 6, 3, 7, 8}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    int missingNumber = findMissingNumber(arr, size);

    printf("The missing number is: %d\n", missingNumber);

    return 0;
}
