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

void dfs(int x,int start){//��ǰö��λ�ã��ͱ�ö������Ŀ�ʼλ��
    //���ϼ�֦�������ݷ�Χ
    //�Ѿ�ѡ������ֵ����� + ����ѡ������ֵ����� >= k
    if((x-1) + (n - start + 1) < k)    return;
    //��ʱ�Ѿ�ѡ����x-1����start��λ����x�����Կ���ѡ��������� n - start + 1

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
