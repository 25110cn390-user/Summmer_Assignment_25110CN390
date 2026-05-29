#include <stdio.h>
//WAP TO CALCULATE SUM OF FIRST N NATURAL NUMBERS
int main() {
    int N,sum=0;
    printf("enter the number upto which sum is to be printed");
    scanf("%d",&N);
    sum= (N*(N+1))/2;
    printf("sum of first %d natural numbers is %d",N,sum);
    return 0;
}
