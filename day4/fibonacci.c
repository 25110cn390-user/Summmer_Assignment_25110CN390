#include<stdio.h>
//wap program to generate fibonacci series
int main(){
    int n,a=0,b=1,c;
    printf("enter the no.of terms: ");
    scanf("%d",&n);
    printf("the given fibonacci series is :");
    for(int i=0;i<n;i++){
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
    }    
}