//wap to check anagram string
#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256
int check_anagram(const char *str1, const char *str2) {
    int count[NO_OF_CHARS] = {0};
    int i;

    if (strlen(str1) != strlen(str2)) {
        return 0;
    }


    for (i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    // If any count is non-zero, strings are not anagrams
    for (i = 0; i < NO_OF_CHARS; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter first string: ");
    scanf("%99s", str1);

    printf("Enter second string: ");
    scanf("%99s", str2);

    if (check_anagram(str1, str2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are not anagrams.\n", str1, str2);
    }

    return 0;
}
