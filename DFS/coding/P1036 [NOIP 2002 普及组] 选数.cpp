#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 36;
int n,k,sum=0,ans=0;
int arr[N],num[N];

bool isPrime(int sum){
    if(sum < 2) return false;
    for(int i = 2;i <= sum/i;i++)
        if(sum%i==0)    return false;
    
    return true;
}

void dfs(int x,int start){//当前枚举位置，和被枚举数组的开始位置
    //加上剪枝，看数据范围
    //已经选择的数字的数量 + 可以选择的数字的数量 >= k
    if((x-1) + (n - start + 1) < k)    return;
    //此时已经选择了x-1个，start的位置在x，所以可以选择的数量是 n - start + 1

    if(x > k){
        sum = 0;
        for(int i = 1;i <= k;i++)
            sum += arr[i];
    
        if(isPrime(sum))    ans++;
        return;
    }

    for(int i = start;i <= n;i++){
        arr[x] = num[i];
        dfs(x+1,i+1);
        arr[x] = 0;
    }
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i = 1;i <= n;i++){
        scanf("%d",&num[i]);
    }
    dfs(1,1);
    printf("%d\n",ans);
    return 0;
}
