#include<stdio.h>
//wap to print character triangle
int main(){
    int i,j,n=5;
    char ch='A';
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("%c",j+64);
        }
        printf("\n");
    }
}