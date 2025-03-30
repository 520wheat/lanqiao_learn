#include<iostream>
#include<algorithm>
#define read(x) scanf("%d",&x)
using namespace std;

const int N = 59050;//3^10大概
int n;
int res = 0;//方案数
int a[20];//枚举可能方案
int ans[N][20];//存放答案

void dfs(int x,int sum){
    if(sum > n)  return;
    
    if(x > 10){
        if(sum == n){
            res++;
            for(int i = 1; i <= 10; i++){
                ans[res][i] = a[i];
            }
        }
        return;
    }
    
    for(int i = 1; i <= 3; i++){
        a[x] = i;
        dfs(x+1,sum+i);
        a[x] = 0;
    }
}

int main(){
    read(n);
    dfs(1,0);//枚举到的位置，调料总数
    printf("%d\n",res);

    for(int i = 1; i <= res; i++){
        for(int j = 1; j <= 10; j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
