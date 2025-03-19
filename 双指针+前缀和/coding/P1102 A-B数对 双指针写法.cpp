#include<iostream>
#include<algorithm>

using namespace std;
#define read(x) scanf("%d",&x)
#define ll long long

const int N = 2e5 + 10;
int n,c;
int a[N];

int main(){
    read(n),read(c);
    for(int i = 1; i <= n; i++)  read(a[i]);
    sort(a+1,a+n+1);
    int r1 = 1,r2 = 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        while(r1 <= n && a[r1]-a[i] <= c)  r1++;//�ҵ����һ���ĺ�һ��
        while(r2 <= n && a[r2]-a[i] < c)  r2++;//�ҵ���һ��
        if(a[r2]-a[i] == c && a[r1-1]-a[i] == c)
            ans += r1-r2;
    }
    printf("%lld\n",ans);
    return 0;
}
