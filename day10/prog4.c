#include<stdio.h>
//wap to print character pyramid
int main(){
    int i,j,n;
    char ch='A';
    printf("Enter the number of rows :");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            printf("  ");
        }
        for(j=1;j<=i;j++){
            printf("%c ",j+64);
        }
        for(j=i-1;j>=1;j--){
            printf("%c ",j+64);
        }
        printf("\n");
    }
    return 0;
}