//wap to remove duplicate characters
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeDuplicates(char* str) {
    bool seen[256] = { false };
    
    int writeIndex = 0;
    int readIndex = 0;

    // traverse the string character by character
    while (str[readIndex] != '\0') {
        unsigned char currentChar = str[readIndex];

        // if the character has not been seen before
        if (!seen[currentChar]) {
            seen[currentChar] = true;        // mark it as seen
            str[writeIndex] = str[readIndex]; // keep it in the string
            writeIndex++;                     
        }
        readIndex++; 
    }

    str[writeIndex] = '\0';
}

int main() {
    // sample input string 
    char text[] = "c is programming language";

    printf("Original String: %s\n", text);

    // calling the function
    removeDuplicates(text);

    printf("String after removing duplicates: %s\n", text);

    return 0;
}
