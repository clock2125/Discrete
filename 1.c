#include<stdio.h>
#include <stdlib.h>
int a[3006];
int cmp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}
int judge(int n, int sum){
    if(sum>n*(n-1)){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    int N;
    scanf("%d", &N);
    int i;
    for (i = 0; i < N;i++){
        scanf("%d", &a[i]);
    }
    int sum = 0;
    // int flag = 1;
    for (i = 0; i < N;i++){
        sum += a[i];
        if(a[i]>N-1){
            printf("no\n");
            return 0;
        }
    }
    if(judge(N,sum)==0){
        printf("no\n");
        return 0;
    }
    else{
        for (i = 0; i < N;i++){
            qsort(a, N - i, sizeof(int), cmp);
            sum -= 2 * a[N-i-1];
            int j;
            if(a[N-i-1]>N-i-1){
                printf("no\n");
                return 0;
            }
            for (j = 0; j<a[N-i-1];j++){
                a[j]--;
            }
            if (judge(N - 1 - i, sum) == 0)
            {
                printf("no\n");
                return 0;
            }
        }
        printf("yes\n");
    }
}