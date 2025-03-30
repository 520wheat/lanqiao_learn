#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)
using namespace std;

const int N = 110;

int n,m;
char g[N][N];
bool st[N][N];
int res = 0;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
void dfs(int x,int y){
    for(int i = 0; i < 8; i++){
        int a = x+dx[i];
        int b = y+dy[i];
        
        if(a<0 || a>=n || b<0 || b>=m)  continue;
        if(g[a][b] != 'W')  continue;
        if(st[a][b])    continue;
        
        st[a][b] = 'true';
        dfs(a,b);
    }
}

int main(){
    r(n);r(m);
    for(int i = 0; i < n; i++)
        scanf("%s",g[i]);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'W' && !st[i][j]){
                dfs(i,j);
                res++;
            }
        }
    }
    printf("%d\n",res);
    
    return 0;
}
