//wap to check string rotation
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int areRotations(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If lengths are not equal, they cannot be rotations
    if (len1 != len2) {
        return 0;
    }

    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    // Initialize the temp buffer
    temp[0] = '\0';

    strcat(temp, str1);
    strcat(temp, str1);

    // Check if str2 is a substring of the concatenated string
    char *ptr = strstr(temp, str2);

    // Free dynamically allocated memory to prevent memory leaks
    free(temp);

    return (ptr != NULL);
}

int main() {
    char str1[] = "alala";
    char str2[] = "CDAB";

    if (areRotations(str1, str2)) {
        printf("'%s' and '%s' are rotations of each other.\n", str1, str2);
    } else {
        printf("'%s' and '%s' are NOT rotations of each other.\n", str1, str2);
    }

    return 0;
}
