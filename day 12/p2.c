#include<stdio.h>
//wap to make function of armstrong number
int armstrong(int n){
    int sum=0,rem,temp;
    temp=n;
    while(temp!=0){
        rem=temp%10;
        sum=sum+(rem*rem*rem);
        temp=temp/10;
    }
    if(sum==n){
        return 1; //armstrong
    }
    else{
        return 0; //not armstrong
    }
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if(armstrong(num)){
        printf("%d is an armstrong number.",num);
    }
    else{
        printf("%d is not an armstrong number.",num);
    }
    return 0;
}