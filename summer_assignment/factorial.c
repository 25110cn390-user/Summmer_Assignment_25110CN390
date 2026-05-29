#include<stdio.h>
//wap to find factorial of a number
int main(){
    int n,fact=1;
    printf("enter the number to find its factorial: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    printf("Factorial of %d is %d", n, fact);
    return 1;
}