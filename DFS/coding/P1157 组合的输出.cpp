#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 21;
int n,r;//总数，选出r个
int arr[N];

void dfs(int x,int start){
    if((x-1) + (n - start + 1) < r)    return;
    
    if(x > r){
        for(int i = 1;i <= r;i++)
            printf("%3d",arr[i]);
        printf("\n");
        return;
    }
    
    for(int i = start;i <= n;i++){
        arr[x] = i;
        dfs(x+1,i+1);
        arr[i] = 0;
    }
}

int main()
{
    cin >> n >> r;
    dfs(1,1);//位置，从数字几开始放
    return 0;
}
