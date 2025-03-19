#include<iostream>
#include<algorithm>
#define read(x) scanf("%d",&x)

using namespace std;

const int N = 5e4+10;
int n,k;
int a[N];

int main(){
    read(n);read(k);
    for(int i = 1; i <= n; i++)  read(a[i]);
    sort(a+1,a+n+1);
    
    int ans = 0;
    for(int i = 1, j = 1; i <= n; i++){
        while(j <= i && a[i]-a[j]>k)  j++;
        ans = max(ans,i-j+1);
    }
     cout << ans << endl;   
    return 0;
}
