#include<stdio.h>
//wap to check armstrong number
int main(){
    int n,temp,r,sum=0;
    printf("enter the number to check: ");
    scanf("%d",&n);
    temp=n;
    while(temp!=0){
        r=temp%10;
        sum=sum+(r*r*r);
        temp=temp/10;
    }
    if(sum==n){
        printf("the number is an armstrong number");
    }
    else{
        printf("the number is not an armstrong number");
    }
    return 0;
}