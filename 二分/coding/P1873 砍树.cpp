#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e6+10;
int n,m;
int q[N];

bool check(int x){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += max(0,q[i] - x);
        if(sum >= m)    return true;
    }
    return false;
}

int main(){
    scanf("%d %d",&n,&m);
    int mx = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d",&q[i]);
        mx = max(mx,q[i]);
    }
    
    int sum = 0;
    int res = 0;
    
    int l = 0,r = mx+1;
    while(l + 1 < r){
        int mid = (l+r) >> 1;
        if(check(mid))    l = mid;
        else    r = mid;
    }

    if(check(r))    cout << r << endl;
    else    cout << l << endl;
    return 0;
}
