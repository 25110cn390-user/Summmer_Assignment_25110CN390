#include<stdio.h>
//wap to make fuction to check prime number
int Prime(int num) {
    if (num <= 1) {
        return 0; // for not prime
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0; // for not prime
        }
    }
    return 1; // prime
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (Prime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
    
    return 0;
}