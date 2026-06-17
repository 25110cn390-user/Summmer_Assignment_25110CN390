//wap to to count even and odd numbers
#include<stdio.h>
int main(){
    int arr[50],i,n ,even=0 ,odd=0 ;
    printf("enter the size of array : ");
    scanf("%d",&n);
    printf("enter the elements of array : ");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for (i=0;i<=n;i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    printf("the total odd count is %d",odd);
    printf("the total even count is %d ",even);
    return 0;
}