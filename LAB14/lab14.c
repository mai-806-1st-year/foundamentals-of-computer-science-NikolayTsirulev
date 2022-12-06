#include <stdio.h>

enum { maxn = 100 };
void matInput(int n, int (*mat)[n]);
void matSolve(int n, int (*mat)[n]);

int main(void){
    int mat[maxn][maxn];
    int n;
    scanf("%d", &n);
    matInput(n, (int (*)[n]) mat);
    matSolve(n, (int (*)[n]) mat);
}

void matInput(int n, int (*mat)[n]){
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            scanf("%d", &mat[i][j]);
}

void matSolve(int n, int (*mat)[n]){
    int k = n - 1;
    for (int i = 0; i <= n / 2 - 1; ++i) {
        for (int j = i; j <= k - 1; ++j)
            printf("%d ", mat[j][i]);
        for (int j = i; j <= k - 1; ++j)
            printf("%d ", mat[k][j]);
        for (int j = k; j >= i + 1; j -= 1)
            printf("%d ", mat[j][k]);
        for (int j = k; j >= i + 1; j -= 1)
            printf("%d ", mat[i][j]);
        k -= 1;
    }
    if (n % 2 != 0)
        printf("%d\n", mat[n / 2][n / 2]);
}
