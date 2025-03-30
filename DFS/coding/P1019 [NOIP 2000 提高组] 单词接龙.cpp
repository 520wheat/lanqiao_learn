#include<iostream>
#include<algorithm>
#include<cstring>
#define r(x) scanf("%d",&x)
using namespace std;

const int N = 30;

int n;
string words[N];//存单词
int used[N];//每个单词的使用次数
int g[N][N];//预处理数组，记录两个单词的重合长度
int res = 0;

void dfs(string dragon,int x){//龙，和此时接上去的单词(就是现在的尾巴单词)
    res = max(res,(int)dragon.size());//确保两个参数是同类型

    used[x]++;
    for(int i = 0; i < n; i++){
        if(g[x][i] && used[i] < 2){
            dfs(dragon + words[i].substr(g[x][i]),i);
        }
    }
    used[x]--;//回溯
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> words[i];
        
    char start;
    cin >> start;//龙头
    
    //预处理
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            string a = words[i],b = words[j];
            for(int k = 1; k < min(a.size(),b.size()); k++){//取k个字母
                if(a.substr(a.size() - k, k) == b.substr(0,k)){
                    g[i][j] = k;
                    break;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(words[i][0] == start){//找到做龙头的那个单词
            dfs(words[i],i);
        }
    }
    
    printf("%d\n",res);
    
    return 0;
}
