//wap to sort names alphabatically
#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    
    char names[50][50]; 
    char temp[50]; 

    // get the total number of names from the user
    printf("Enter the number of names: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    while (getchar() != '\n');

    // input
    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++) {
        fgets(names[i], sizeof(names[i]), stdin);
        
        // remove newline character added by fgets
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    // sorting the names alphabetically using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // strcmp returns a positive number if conditions meet
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap names[j] and names[j+1]
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    //result
    printf("\nNames in Alphabetical Order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
