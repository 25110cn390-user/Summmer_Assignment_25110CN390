//wap to find second largest element
#include<stdio.h>
#include<limits.h>
int main(){
    int arr[50],i,n;
    int first , second;
    printf("enter the size of array");
    scanf("%d",&n);
    if(n<2){
        printf("array should contain atleast 2 elements/n");
        return 1;
    }
    printf("enter the elements:");
    for (int i=0;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    first=second==INT_MIN;
    for (i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first; 
            first = arr[i]; 
        } 
        else if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }
    if (second == INT_MIN) {
        printf("There is no distinct second largest element (all elements can be equal).\n");
    } else {
        printf("The largest element is: %d\n", first);
        printf("The second largest element is: %d\n", second);
    }
    return 0;
}