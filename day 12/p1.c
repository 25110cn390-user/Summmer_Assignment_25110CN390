#include<stdio.h>
//wap to make function for palindrome number
int palindrome(int n){
    int rev=0,rem,temp;
    temp=n;
    while(temp!=0){
        rem=temp%10;
        rev=rev*10+rem;
        temp=temp/10;
    }
    if(rev==n){
        return 1; //palindrome
    }
    else{
        return 0; //not palindrome
    }
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if(palindrome(num)){
        printf("%d is a palindrome number.",num);
    }
    else{
        printf("%d is not a palindrome number.",num);
    }
    return 0;
}
