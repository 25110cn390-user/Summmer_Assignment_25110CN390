//wap to find first non repeating character
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256 

char findFirstNonRepeating(const char *str) {
    int freq[MAX_CHAR] = {0}; // Initialize frequency array to 0
    
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i]; // Return the first unique character found
        }
    }
    
    return '\0'; // if no unique character exists
}

int main() {
    char str[] = "ississippihehh";
    
    char result = findFirstNonRepeating(str);
    
    if (result != '\0') {
        printf("The first non-repeating character is: %c\n", result);
    } else {
        printf("All characters are repeating.\n");
    }
    
    return 0;
}
