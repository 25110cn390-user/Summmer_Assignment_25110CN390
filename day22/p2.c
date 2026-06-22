//wap to count words in a sentence
#include <stdio.h>
#include <ctype.h>

int count_words(const char *str) {
    int count = 0;
    int in_word = 0; 

    while (*str) {
        // isspace() checks for ' ', '\t', '\n', '\v', '\f', '\r'
        if (isspace((unsigned char)*str)) {
            in_word = 0; 
        } 
        else if (in_word == 0) {
            in_word = 1; // Mark that we entered a word
            count++;    
        }
        str++; 
    }

    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    // fgets reads the entire line including spaces
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        int words = count_words(sentence);
        printf("Total number of words: %d\n", words);
    }

    return 0;
}
