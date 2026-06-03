#include<stdio.h>
//wap to check whether a given number is prime or not
int main(){
    int n,i,sol=0;
    printf("enter a number " );
    scanf("%d",&n);
    for(i=2;i<n;i++){
        if(n%i==0){
            sol=1;
            break;
        }

    }
    if(sol==0){
        printf("prime number");
    }
    else{
        printf("not a prime number");
        
    }
}