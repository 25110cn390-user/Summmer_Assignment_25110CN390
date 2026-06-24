//wap to compress a string
#include <stdio.h>
#include <string.h>

void compressString(const char *src, char *dest) {
    int i = 0;
    int j = 0; 
    int len = strlen(src);

    while (i < len) {
        int count = 1;
        
        // Count occurrences of the current character
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }
        dest[j++] = src[i];

        // Convert count integer to string characters and append
        int charsWritten = sprintf(&dest[j], "%d", count);
        j += charsWritten;

        i++; 
    }
    
    dest[j] = '\0'; // Append null terminator to complete the string
}

int main() {
    char inputString[100];
    char compressedString[200]; 

    printf("Enter a string to compress: ");
    // Safely read string excluding the newline character
    scanf("%99[^\n]", inputString); 

    compressString(inputString, compressedString);

    printf("Original String:   %s\n", inputString);
    printf("Compressed String: %s\n", compressedString);

    return 0;
}
