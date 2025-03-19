#include<iostream>

using namespace std;

const int N = 1e5+10;
int n,m,k;
int a[N],b[N];
#define read(x) scanf("%d",&x)

bool f(int tmp,int x){
    if(tmp + b[x] <= k)    return true;
    return false;
}

int main(){
    read(n),read(m),read(k);
    for(int i = 0; i < n; i++)    read(a[i]);
    for(int j = 0; j < m; j++)    read(b[j]);
    
    for(int i = 0; i < n; i++){
        int l = -1,r = m;
        while(l+1 < r){
            int mid = (l+r)>>1;
            if(f(a[i],mid))  l = mid;
            else    r = mid;
        }
        if(l != -1 && a[i]+b[l]==k)    printf("%d %d\n",i,l);
    }

    return 0;
}
