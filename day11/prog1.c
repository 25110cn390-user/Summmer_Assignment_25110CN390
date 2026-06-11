#include<stdio.h>
//wap to make function to find sum of two num
int sum(int a, int b){
    return a+b;
}
int main(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int result = sum(a, b);
    printf("The sum of %d and %d is: %d\n", a, b, result);
    return 0;
}