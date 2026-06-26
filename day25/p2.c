//wap to find common characters in string
#include <stdio.h>
#include <string.h>

void findCommonCharacters(char str1[], char str2[]) {
    // array to track character 
    int present[256] = {0}; 
    int found = 0;

    // mark characters present in the first string as 1
    for (int i = 0; str1[i] != '\0'; i++) {
        present[(unsigned char)str1[i]] = 1; 
    }

    printf("Common characters: ");

    for (int i = 0; str2[i] != '\0'; i++) {
        unsigned char index = (unsigned char)str2[i];
        
        if (present[index] == 1) {
            printf("%c ", str2[i]);
            present[index] = 2; 
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    //rmove newline character added by fgets
    str1[strcspn(str1, "\n")] = '\0'; 

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; 

    findCommonCharacters(str1, str2);

    return 0;
}
