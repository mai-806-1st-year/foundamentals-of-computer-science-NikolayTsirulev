#include <stdio.h>

enum { maxn = 100 };
void matInput(int n, int (*mat)[n]);
void matOutput(int n, int (*mat)[n]);
void matReverseOrder(int n, int (*mat)[n]);

int main(void) {
    int mat[maxn][maxn];
    int n;
    scanf("%d", &n);
    matInput(n, (int (*)[n]) mat);
    matReverseOrder(n, (int (*)[n]) mat);
}

void matInput(int n, int (*mat)[n]){
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            scanf("%d", &mat[i][j]);
}

void matOutput(int n, int (*mat)[n]){
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int minElem(int n, int (*mat)[n]){ //searches for the minimum element in the matrix
    int res = 0x7FFFFFFF;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            if (mat[i][j] < res) res = mat[i][j];
    return res;
}
void matReverseOrder(int n, int (*mat)[n]){ //prints a matrix where the row elements with the minimum element are rearranged in reverse order
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            if (mat[i][j] == minElem(n, (int (*)[n]) mat)) {
                for (int k = 0; k!=(n / 2); ++k) {
                    int temp = mat[i][k];
                    mat[i][k] = mat[i][n - k - 1];
                    mat[i][n - k - 1] = temp;
                    temp = 0;
                }
                matOutput(n, (int (*)[n]) mat);
                return;
            }
}
