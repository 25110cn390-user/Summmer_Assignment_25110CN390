#include<stdio.h>
//wap to print repeated number triangle
int main(){
    int i,j,n=5;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("%d",i);
        }
        printf("\n");
    }
}