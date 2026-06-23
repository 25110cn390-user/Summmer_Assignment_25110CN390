//wap to find maximum occuring character
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256 // Total possible ASCII characters

char getMaxOccurringChar(char* str) {
    int count[MAX_CHARS] = {0};
    
    // Calculate the length of the string
    int len = strlen(str);
    int max = -1;
    char result = '\0';
    
    for (int i = 0; i < len; i++) {
        count[(unsigned char)str[i]]++;
    }
    
    for (int i = 0; i < len; i++) {
        if (max < count[(unsigned char)str[i]]) {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }
    
    return result;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");

    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0'; 
    }
    
    if (strlen(str) == 0) {
        printf("The string is empty.\n");
        return 0;
    }
    
    char maxChar = getMaxOccurringChar(str);
    printf("The maximum occurring character is '%c'\n", maxChar);
    
    return 0;
}
