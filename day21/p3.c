//wap to count vowels and constant
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[150];
    int vowels = 0;
    int consonants = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Loop through each character until the null terminator
    for (int i = 0; str[i] != '\0'; i++) {
        // Convert character to lowercase 
        char ch = tolower((unsigned char)str[i]);

        // Check if the character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        }
        // Check if the character is a constant
        else if (ch >= 'a' && ch <= 'z') {
            consonants++;
        }
    }

    printf("Total Vowels: %d\n", vowels);
    printf("Total Consonants: %d\n", consonants);

    return 0;
}
