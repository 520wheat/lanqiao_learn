#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)
using namespace std;
const int N = 20;

int n,res=1e9;
int sour[N],bitter[N];
int st[N];

void dfs(int x){
    if(x>n){
        bool flag = false;//����һ���������û��ѡ�κ�һ�ֵ��ϣ���ʱ res ��Ĭ�ϵ� 1
        int sum1 = 1,sum2 = 0;
        for(int i = 1; i <= n; i++){
            if(st[i] == 1){//ѡ�˸õ��ϲż�����Ȼ�����Ⱥ�
                flag = true;//�޸ı�־��˵��ѡ���˵���
                sum1 *= sour[i];
                sum2 += bitter[i];
            }
        }
        
        if(flag)//��ѡ����ϵ�����²��ܼ����ֵ
            res = min(res,abs(sum1-sum2));
        return;
    }
    
    //ѡ
    st[x] = 1;
    dfs(x+1);
    st[x] = 0;
    
    //��ѡ
    st[x] = 2;
    dfs(x+1);
    st[x] = 0;
}

int main(){
    r(n);
    for(int i = 1; i <= n; i++){
        r(sour[i]);
        r(bitter[i]);
    }
    
    dfs(1);
    printf("%d\n",res);

    return 0;
}
