#include<iostream>
#include<algorithm>
#define read(x) scanf("%1d",&x)
using namespace std;

int n,m,ans = 0;
int a[110][110];

void dfs(int x,int y){
    if(x>n || x<1 || y>m || y<1 || a[x][y]==0)  return;
    a[x][y] = 0;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i<= n; i++)
        for(int j = 1; j <= m; j++)
            read(a[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1;j <= m; j++){
            if(a[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    printf("%d\n",ans);
    return 0;
}
