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
        bool flag = false;//存在一种情况就是没有选任何一种调料，这时 res 是默认的 1
        int sum1 = 1,sum2 = 0;
        for(int i = 1; i <= n; i++){
            if(st[i] == 1){//选了该调料才计算酸度积，苦度和
                flag = true;//修改标志，说明选择了调料
                sum1 *= sour[i];
                sum2 += bitter[i];
            }
        }
        
        if(flag)//有选择调料的情况下才能计算差值
            res = min(res,abs(sum1-sum2));
        return;
    }
    
    //选
    st[x] = 1;
    dfs(x+1);
    st[x] = 0;
    
    //不选
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
