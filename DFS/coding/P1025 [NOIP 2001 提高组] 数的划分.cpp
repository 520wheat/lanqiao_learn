#include<iostream>
#include<algorithm>
#include<cstring>
#define r(x) scanf("%d",&x)

using namespace std;

const int N = 10;

int n,k;
int res = 0;//方案数
int arr[N];//记录方案

void dfs(int x, int start, int nowsum){//枚举的位置，从哪个数开始枚举，目前的总和
    if(nowsum > n)  return;

    if(x > k){
        if(nowsum == n)    res++;
        return;
    }
    
    // for(int i = start; i <= n; i++){//不剪枝
    //     arr[x] = i;
    //     dfs(x+1,i,nowsum+i);
    //     arr[x] = 0;
    // }
    
    for(int i = start; nowsum + i*(k-x+1) <= n; i++){//剪枝,后续的选数如果会让总和超过就不要枚举了
        arr[x] = i;
        dfs(x+1,i,nowsum+i);
        arr[x] = 0;
    }
}

int main(){
    r(n);r(k);
    dfs(1,1,0);
    printf("%d\n",res);
    return 0;
}
