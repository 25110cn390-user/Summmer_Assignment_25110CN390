#include<stdio.h>
//wap to make function of finding factorial of a number
int factorial(int num) {
    if (num < 0) {
        return -1; // Factorial is not defined for negative numbers
    } else if (num == 0 || num == 1) {
        return 1; // Factorial of 0 and 1 is 1
    } else {
        int fact = 1;
        for (int i = 2; i <= num; i++) {
            fact *= i;
        }
        return fact;
    }
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int result = factorial(num);
    if (result == -1) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("The factorial of %d is: %d\n", num, result);
    }
    
    return 0;
}