//wap to remove spaces from the string
#include <stdio.h>

void removeSpaces(char *str) {
    int i = 0; //  read characters
    int j = 0; // for non-space characters

    while (str[i] != '\0') {
        // If the current character is not a space, copy it
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    
    // Null-terminate the modified string
    str[j] = '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int k = 0;
    while (str[k] != '\0') {
        if (str[k] == '\n') {
            str[k] = '\0';
            break;
        }
        k++;
    }

    printf("Original string: '%s'\n", str);

    // function call
    removeSpaces(str);

    printf("String after removing spaces: '%s'\n", str);

    return 0;
}
