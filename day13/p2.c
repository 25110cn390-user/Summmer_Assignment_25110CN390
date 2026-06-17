//wap to find sum and average of array
#include<stdio.h>
int main()
{
    int arr[50],n,i,sum=0;
    float avg;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    avg = (float)sum/n;
    printf("The sum of array elements is: %d\n",sum);
    printf("The average of array elements is: %.2f\n",avg);
    return 0;
}