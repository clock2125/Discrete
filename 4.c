#include <stdio.h>
int M[105][105];
int out[105];
int in[105];
int main(){
    int N;
    scanf("%d", &N);
    int i, j;
    for (i = 1; i <= N;i++){
        for (j = 1; j <= N;j++){
            scanf("%d", &M[i][j]);
            out[i] += M[i][j];
            in[j] += M[i][j];
        }
    }
    for (i = 1; i <= N;i++){
        printf("%d %d\n", out[i], in[i]);
    }
}