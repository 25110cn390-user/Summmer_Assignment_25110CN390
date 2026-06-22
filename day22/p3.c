//wap to character frequency
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[256] = {0}; 

    printf("Enter any string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline character
    str[strcspn(str, "\n")] = '\0';

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char index = str[i];
        freq[index]++;
    }

    // Print frequencies of characters
    printf("\nCharacter Frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("'%c' occurs %d time(s)\n", i, freq[i]);
        }
    }

    return 0;
}
