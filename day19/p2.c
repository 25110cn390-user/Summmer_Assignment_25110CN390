//wap to subtract two matrices
#include <stdio.h>

int main() {
    int r, c, i, j;
    int a[10][10], b[10][10], sub[10][10];

    printf("Enter rows and columns (max 10): ");
    scanf("%d %d", &r, &c);

    printf("\nEnter elements of 1st matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            scanf("%d", &a[i][j]);

    printf("Enter elements of 2nd matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            scanf("%d", &b[i][j]);

    // subtracting two matrices
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            sub[i][j] = a[i][j] - b[i][j];

    // result
    printf("\nsubtraction of two matrices:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            printf("%d  ", sub[i][j]);
            if (j == c - 1) printf("\n");
        }
    return 0;
}
