#include<iostream>
#include<algorithm>

using namespace std;

int n,k;
int a[100010];

bool check(int x){
    long long cnt = 0;
    for(int i = 1; i <= n; i++)  cnt += a[i]/x;
    return cnt>=k;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)  cin >> a[i];

    int l = 0,r = 1e8+10;
    int mid;
    while(l+1<r){
        mid = (l+r)>>1;
        if(check(mid))  l = mid;
        else r = mid;
    }
    cout << l << endl;
    
    return 0;
}
