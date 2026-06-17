#include<stdio.h>
//wap to make function for fibbonacci series
void fibonacci(int n){
    int a=0,b=1,c;
    printf("Fibonacci series up to %d terms: ",n);
    for(int i=1;i<=n;i++){
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
    }
}
int main(){
    int num;
    printf("Enter the number of terms: ");
    scanf("%d",&num);
    fibonacci(num);
    return 0;
}