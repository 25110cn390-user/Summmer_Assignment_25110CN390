//wap to find frequency of element
#include<stdio.h>
int main() {
    int n, freq, count = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to find its frequency: ");
    scanf("%d", &freq);

    // Linear search to count occurrences
    for (int i = 0; i < n; i++) {
        if (arr[i] == freq) {
            count++;
        }
    }

    // Output the final frequency
    printf("The element %d occurs %d times in the array.\n", freq, count);

    return 0;
}
