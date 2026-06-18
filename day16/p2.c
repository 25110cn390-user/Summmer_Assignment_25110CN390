//wap to find max frequency of element in array
#include <stdio.h>

int main() {
    int n, i, j;
    int max_count = 0;
    int most_frequent_element;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    int visited[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // 0 means the element hasn't been processed 
    }

    // Logic to find the maximum frequency
    for (i = 0; i < n; i++) {
        // Skip this element if it is counted as a duplicate
        if (visited[i] == 1) {
            continue;
        }

        int current_count =1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                current_count++;
                visited[j] = 1; 
            }
        }
        if (current_count > max_count) {
            max_count = current_count;
            most_frequent_element = arr[i];
        }
    }

    printf("\nElement with the maximum frequency: %d\n", most_frequent_element);
    printf("Maximum frequency: %d times\n", max_count);

    return 0;
}
