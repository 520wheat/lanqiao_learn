#include<iostream>
#include<algorithm>
#include<cstring>
#define r(x) scanf("%d",&x)

using namespace std;

const int N = 10;

int n,k;
int res = 0;//������
int arr[N];//��¼����

void dfs(int x, int start, int nowsum){//ö�ٵ�λ�ã����ĸ�����ʼö�٣�Ŀǰ���ܺ�
    if(nowsum > n)  return;

    if(x > k){
        if(nowsum == n)    res++;
        return;
    }
    
    // for(int i = start; i <= n; i++){//����֦
    //     arr[x] = i;
    //     dfs(x+1,i,nowsum+i);
    //     arr[x] = 0;
    // }
    
    for(int i = start; nowsum + i*(k-x+1) <= n; i++){//��֦,������ѡ����������ܺͳ����Ͳ�Ҫö����
        arr[x] = i;
        dfs(x+1,i,nowsum+i);
        arr[x] = 0;
    }
}

int main(){
    r(n);r(k);
    dfs(1,1,0);
    printf("%d\n",res);
    return 0;
}
