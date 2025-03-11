#include<iostream>
#include<algorithm>

using namespace std;

const int N = 2e6;
int n,C;
int a[N];

int searchB1(int a[],int len,int x){
    int l = 0, r = n+1;
    while(l+1 < r){
        int mid = (l+r) >> 1;
        if(a[mid] < x)    l = mid;
        else    r = mid;
    }
    if(a[r] == x)    return r;
    return -1;
}

int searchB2(int a[],int len,int x){
    int l = 0, r = n+1;
    while(l+1 < r){
        int mid = (l+r) >> 1;
        if(a[mid] <= x)    l = mid;
        else    r = mid;
    }
    if(a[l] == x)    return l;
    return -1;
}

int main(){
    scanf("%d %d",&n,&C);
    for(int i = 1; i <= n; i++)    scanf("%d",&a[i]);
    sort(a+1,a+n+1);

    long long cnt = 0;
    /*
    如何二分：
    转化为 A = B + C   －－－－ 移项
    C已知，枚举一个，可得另一个
    
    策略：
    C 已知
    枚举 B，加上 C，然后在数组里面寻找 A 的位置 和 个数
    
    */
    for(int B = 1; B <= n; B++){
        int A = a[B]+C;//B 是下标，别昏头了
        int res1 = searchB1(a,n,A);//找第一个
        if(res1 == -1)    continue;
        else{
            int res2 = searchB2(a,n,A);//找最后一个
            cnt += res2 - res1 + 1;
        }
    }
    printf("%lld\n",cnt);

    return 0;
}
