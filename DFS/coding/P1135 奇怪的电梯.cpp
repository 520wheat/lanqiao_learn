#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)
using namespace std;

const int N = 1010;
int n,a,b;
int arr[N];
bool st[N];
int res = 1e9;

void dfs(int x,int cnt){
    if(cnt > res)    return;
    if(x < 0 || x > n)    return;

    if(x == b){
        res = min(res,cnt);
        return;
    }

    //ио
    if(x+arr[x] <= n && !st[x+arr[x]]){
        //printf("x+arr[x] = %d\n",x+arr[x]);
        st[x+arr[x]] = true;
        dfs(x+arr[x],cnt+1);
        st[x+arr[x]] = false;
    }

    //об
    if(x-arr[x] > 1 && !st[x-arr[x]]){
        //printf("x-arr[x] = %d\n",x-arr[x]);
        st[x-arr[x]] = true;
        dfs(x-arr[x],cnt+1);
        st[x-arr[x]] = false;
    }
}

int main(){
    r(n);r(a);r(b);
    for(int i = 1; i <= n; i++)
        r(arr[i]);

    dfs(a,0);

    if(res == 1e9)
        printf("-1\n");
    else
        printf("%d\n",res);
    return 0;
}
