//wap to check palindrome string
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left = 0;
    int right;
    int isPalindrome = 1; 

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character added by fgets if present
    str[strcspn(str, "\n")] = '\0';

    // Set right pointer to the last character of the string
    right = strlen(str) - 1;

    // Compare characters from both end
    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0; // Mismatch found
            break;
        }
        left++;
        right--;
    }

    //result
    if (isPalindrome) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
