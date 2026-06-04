#include<stdio.h>
//wap program to find nth term of fibonacci series
int main(){
    int n,a=0,b=1,c;
    printf("enter the term: ");
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        c=a+b;
        a=b;
        b=c;
    }
    printf("the %dth term of fibonacci series is: %d",n,a);
}