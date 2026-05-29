#include<stdio.h>
//this program calculates the sum of the digits of a number
int main(){
    int n, sum = 0;
    printf("Enter a number to find the sum of its digits: ");
    scanf("%d", &n);
    
    while(n > 0){
        sum += n % 10; 
        n = n/10; 
    }
    
    printf("The sum of the digits is: %d\n", sum);
    return 0;
}