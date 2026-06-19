//wap to transpose of matrices
#include <stdio.h>

int main() {
    int r, c, i, j;
    int matrix[r][c];
    int trans[c][r];
    printf("enter the rows and columns :\n");
    scanf("%d %d",&r,&c);
    printf("\n enter the elements of matrix :\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("enter element at [%d][%d] ",i,j);
            scanf("%d" ,&matrix[i][j]);
        }
    }
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            trans[j][i] = matrix[i][j];
        }
    }

    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            printf("%d\t", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
