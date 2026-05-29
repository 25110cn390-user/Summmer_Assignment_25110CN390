#include<stdio.h>
//WAP TO COUNT DIGITS IN A NUMBER
int main(){
    int n,count=0;
    printf("enter the no. to count its digits: ");
    scanf("%d",&n);
    while(n!=0){
        n=n/10;
        count=count+1;
    }
    printf("the number of digits in given numer is%d: ",count);
    return 0;
    
}