#include<stdio.h>
//this program calculates the product of the digits of a number
int main(){
    int n, product = 1;
    printf("Enter a number to find the product of its digits: ");
    scanf("%d", &n);
    
    while(n > 0){
        product *= n % 10; 
        n = n/10; 
    }
    
    printf("The product of the digits is: %d\n", product);
    return 0;
}