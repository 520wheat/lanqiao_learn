#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)

using namespace std;

const int N = 10010;

int n,m;
int arr[N];//��¼����
int stast[N];//��¼�����˵���ʼ����
bool st[N];//�������Ƿ��Ѿ��ڸ����з�����
int res = 0;//�ӿ�ʼλ�ã�һ��ö���˶��ٷ�����
bool finish = false;

void dfs(int x){
    if(finish)    return;//��֦���ҵ��˾ͱ��������
    
    if(x > n){
        res++;
        if(res == m+1){//�����˱�ʾ�����ĵ�һ��������1������Ҫ����
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
