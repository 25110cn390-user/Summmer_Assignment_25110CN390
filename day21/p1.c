//wap to find length of string without strlen()
#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    int length = 0;

    // Loop until the null character 
    while (str[length] != '\0') {
        length++;
    }

    printf("The length of the string is: %d\n", length);

    return 0;
}
