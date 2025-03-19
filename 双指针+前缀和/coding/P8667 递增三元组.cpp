#include<iostream>
#include<algorithm>
#define read(x) scanf("%d",&x)

using namespace std;

const int N = 1e5+10;
int a[N],b[N],c[N];
int n;

int main(){
    read(n);
    for(int i = 1; i <= n; i++)  read(a[i]);
    for(int i = 1; i <= n; i++)  read(b[i]);
    for(int i = 1; i <= n; i++)  read(c[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);

    long long ans = 0;//假设三个数组都是十万级别的，那么最后就是 1e5 * 1e5 * 1e5 = 1e15
    for(int i = 1,indexA = 1,indexC = 1; i <= n; i++){
    int B = b[i];
        while(a[indexA] < B && indexA <= n)  indexA++;
        while(c[indexC] <= B && indexC <= n) indexC++;
        ans += (long long)(indexA - 1)*(n - indexC + 1);//这里同样要考虑爆int， 1e5*1e5 = 1e10
        //给一个long long 和给两个结果一样，因为乘积运算结果会转到更高精度
    }
    printf("%lld\n",ans);//这里一定要记得写lld,排了半天不知道哪里扣了两个样例TwT
    
    return 0;
}
