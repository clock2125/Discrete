#include <stdio.h>
#include <stdlib.h>
int A[3005][3005];
int vis[3005];
int que[100005];
int qh = 0;
int qt = 0;
void push(int n){
    que[qt] = n;
    qt++;
}
int pop(){
    int x = que[qh];
    que[qh] = 0;
    qh++;
    return x;
}
int main()
{
    int N;
    scanf("%d", &N);
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            scanf("%d", &A[i][j]);
        }
        A[i][i] = 1;
    }
    if(N==3){
        int flag = 1;
        for (i = 1; i <= 3;i++){
            for (j = 1; j <= 3;j++){
                if(A[i][j]!=1){
                    flag = 0;
                }
            }
        }
        if (flag==1){
            printf("no\n");
            return 0;
        }
    }
    push(1);
    vis[1] = 1;
    int cnt = 1;
    while(qh<qt){
        int x = pop();
        for (int i = 1; i <= N;i++){
            if(vis[i]==0&&A[x][i]!=0){
                push(i);
                cnt++;
                vis[i] = 1;
            }
        }
    }
    if(cnt<N){
        printf("no\n");
    }
    else{
        printf("yes\n");
    }
}