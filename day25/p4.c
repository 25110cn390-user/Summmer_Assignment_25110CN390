//wap to sort words by length
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char words[20][20];
    char temp[20];
    int i = 0, j = 0, wordCount = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    
    // removes newline character if present
    str[strcspn(str, "\n")] = '\0';
    char *token = strtok(str, " ");
    while (token != NULL && wordCount < 20) {
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }

    // sort the words array using Bubble Sort
    for (i = 0; i < wordCount - 1; i++) {
        for (j = 0; j < wordCount - i - 1; j++) {
            // Compare the lengths of adjacent words
            if (strlen(words[j]) > strlen(words[j + 1])) {
                // swap the words if the current one is longer
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for (i = 0; i < wordCount; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
