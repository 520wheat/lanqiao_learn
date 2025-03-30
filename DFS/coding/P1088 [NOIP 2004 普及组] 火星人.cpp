#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)

using namespace std;

const int N = 10010;

int n,m;
int arr[N];//记录方案
int stast[N];//记录火星人的起始排列
bool st[N];//该数字是否已经在该排列方案里
int res = 0;//从开始位置，一共枚举了多少方案数
bool finish = false;

void dfs(int x){
    if(finish)    return;//剪枝。找到了就别继续找了
    
    if(x > n){
        res++;
        if(res == m+1){//火星人表示出来的第一个数字是1，所以要加上
            finish = true;
            for(int i = 1; i <= n; i++){
                printf("%d ",arr[i]);
            }
        }
        return;
    }
    
    for(int i = 1; i <= n; i++){
        if(!res)    i = stast[x];
        
        if(!st[i]){
            st[i] = true;
            arr[x] = i;
            dfs(x+1);
            st[i] = false;
            arr[x] = 0;
        }
    }
}

int main(){
    r(n);r(m);
    for(int i = 1; i <= n; i++)
        r(stast[i]);
        
    dfs(1);
    return 0;
}
