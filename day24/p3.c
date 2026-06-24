//wap to find longest word
#include <stdio.h>
#include <string.h>

int main() {
    char str[500];
    char longest[100] = "";
    char current[100] = "";
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    // for reading an entire line of text including spaces
    fgets(str, sizeof(str), stdin);

    // remove newline character  if it captured by fgets
    str[strcspn(str, "\n")] = '\0';

    while (str[i] != '\0') {
        // build words 
        if (str[i] != ' ' && str[i] != '.' && str[i] != ',' && str[i] != '!') {
            current[j++] = str[i];
        } else {
            current[j] = '\0';//for termination of current word
            
            // check if current word is longer than the previous longest one
            if (strlen(current) > strlen(longest)) {
                strcpy(longest, current);
            }
            j = 0; 
        }
        i++;
    }

    
    current[j] = '\0';
    if (strlen(current) > strlen(longest)) {
        strcpy(longest, current);
    }

    // results
    printf("\nLongest word: %s", longest);
    printf("\nLength: %lu\n", strlen(longest));

    return 0;
}
