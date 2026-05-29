#include<stdio.h>
int main(){
    int n, rev= 0;
    printf("Enter a number to find its reverse: ");
    scanf("%d", &n);
    
    while(n > 0){
        rev = rev* 10 + n % 10; 
        n = n/10; 
    }
    
    printf("The reversed number is: %d\n", rev);
    return 0;
}