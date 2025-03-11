/*
由于这道题的数据量是50000,如果使用dp应该是O(n^2),就超时了
思路应该是枚举出一个合法的最长最短跳跃距离

问题一：什么样的跳跃距离是合法的
关注我们枚举出的可能答案和至多可移走的石头数目 M
可以想到，我们能遍历所有石头，同时记录我们的当前位置Pos
如果我们要跳过去的石头a[i]和我们此时的距离比我们枚举出的可能答案还小，
那这块石头应该移走，即a[i]-pos<x时，搬走次数+1

问题二：怎么枚举答案
如果还是一个一个累加枚举，依旧是会超时的
这时候就得请出我们的二分答案了
*/
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5e4+10;
int a[N],len,n,m;

bool f(int x){
    int pos = 0,cnt = 0;//从起点开始，所以POS取值0
    for(int i = 1; i <= n; i++){
        if(a[i] - pos < x)  cnt++;
        else  pos = a[i];
    }
    if(cnt <= m)  return true;
    return false;
}

int main(){
    cin >> len >> n >> m;
    for(int i = 1; i <= n; i++)  cin >> a[i];
    a[++n] = len;//你还得跳到终点

    int l = 0,r = len+1;
    while(l+1<r){
        int mid = (l+r)>>1;
        if(f(mid))  l = mid;
        else  r = mid;
    }
    cout << l << endl;
    
    return 0;
}
