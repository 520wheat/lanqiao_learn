#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int N = 1e6+10;

int n,m;
int q[N];

bool isBlue(int op,int x){
    if(op < x)
        return true;
    return false;
}

int search(int q[],int len,int x){
    int l = 0,r = len+1;
    while(l+1 < r){
        int mid = (l+r) >> 1;
        if(isBlue(q[mid],x))
            l = mid;
        else
            r = mid;
    }
    
    if(q[r] == x)
        return r;
    return -1;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)    scanf("%d",&q[i]);

    while(m--){
        int x;scanf("%d",&x);
        int ans = search(q,n,x);
        printf("%d ",ans);
    }
    
    return 0;
}
