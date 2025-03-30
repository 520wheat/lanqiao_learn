#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)

using namespace std;

const int N = 1010;

int n;
int res = 0,sum = 0;
int arr[N];
int nums[N] = {6,2,5,5,4,5,6,3,7,6};

void dfs(int x,int sum){
    if(sum > n)    return;

    if(x > 3){
        if(arr[1] + arr[2] == arr[3] && sum == n){
            res++;
        }
        return;
    }
    
    for(int i = 0; i <= N; i++){
        arr[x] = i;
        dfs(x+1,sum + nums[i]);//记忆化
        arr[x] = 0;
    }
}

int main(){
    r(n);
    n -= 4;
    
    for(int i = 10; i <= N; i++)//记忆化
        nums[i] = nums[i%10] + nums[i/10];
    
    dfs(1,0);
    
    printf("%d\n",res);
    return 0;
}
