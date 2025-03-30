#include<iostream>
#include<algorithm>
#include<cstring>
#define r(x) scanf("%d",&x)
using namespace std;

const int N = 30;

int n;
string words[N];//�浥��
int used[N];//ÿ�����ʵ�ʹ�ô���
int g[N][N];//Ԥ�������飬��¼�������ʵ��غϳ���
int res = 0;

void dfs(string dragon,int x){//�����ʹ�ʱ����ȥ�ĵ���(�������ڵ�β�͵���)
    res = max(res,(int)dragon.size());//ȷ������������ͬ����

    used[x]++;
    for(int i = 0; i < n; i++){
        if(g[x][i] && used[i] < 2){
            dfs(dragon + words[i].substr(g[x][i]),i);
        }
    }
    used[x]--;//����
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> words[i];
        
    char start;
    cin >> start;//��ͷ
    
    //Ԥ����
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            string a = words[i],b = words[j];
            for(int k = 1; k < min(a.size(),b.size()); k++){//ȡk����ĸ
                if(a.substr(a.size() - k, k) == b.substr(0,k)){
                    g[i][j] = k;
                    break;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(words[i][0] == start){//�ҵ�����ͷ���Ǹ�����
            dfs(words[i],i);
        }
    }
    
    printf("%d\n",res);
    
    return 0;
}
