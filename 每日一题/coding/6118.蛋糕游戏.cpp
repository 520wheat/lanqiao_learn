#include<iostream>
#define read(x) scanf("%lld",&x)
#define ll long long
using namespace std;

const int N = 5e5+10;
ll t,n,a[N],s[N];
ll res1 = 0,res2 = 0;

int main(){
    read(t);
    while(t--){
        res1 = 0,res2 = 0;
        read(n);
        for(int i = 1; i <= n; i++){
            read(a[i]);
            s[i] = s[i-1]+a[i];//前缀和处理
        }
        
        int cnt = (n-2)/2;//埃尔茜吃的数量
        ll tmp;
        
        for(int k = 0; k <= cnt; k++){
            tmp = s[k] + s[n]-s[n-cnt+k];
            res1 = max(res1,tmp);
        }
        res2 = s[n]-res1;
        
        printf("%lld %lld\n",res2,res1);
    }
    
    return 0;
}
