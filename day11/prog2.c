#include<stdio.h>
//wap to write a func to find maximun
int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}
int main(){
    int a,b;
    printf("enter the numbers :");
    scanf("%d%d",&a,&b);
    printf("the maximum of %d and %d is %d",a,b,max(a,b));
    return 0;
}