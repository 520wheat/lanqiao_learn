#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)
using namespace std;

const int N = 30;
char g[N][N];
int n,m;
int res = 1;
bool st[N][N];//瓷砖是否走过

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void dfs(int x,int y){
    //写四个dfs调用也行

    for(int i = 0; i < 4; i++){
        int a = x+dx[i];
        int b = y+dy[i];

        if(a < 0 || a >= n || b < 0 || b >= m)  continue;
        if(g[a][b] != '.')    continue;
        if(st[a][b])    continue;

        st[a][b] = true;
        res++;
        dfs(a,b);
    }
}

int main(){
    scanf("%d %d",&m,&n);
    for(int i = 0; i < n; i++)
        scanf("%s",g[i]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(g[i][j] == '@'){
                st[i][j] = true;
                dfs(i,j);
            }
    
    printf("%d\n",res);
    return 0;
}
