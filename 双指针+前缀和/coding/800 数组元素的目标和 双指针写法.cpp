#include<iostream>

using namespace std;

const int N = 1e5+10;
int n,m,k;
int a[N],b[N];
#define read(x) scanf("%d",&x)    //看题解的时候看到的，偷学一下大佬的写法

int main(){
    read(n),read(m),read(k);
    for(int i = 0; i < n; i++)    read(a[i]);
    for(int j = 0; j < m; j++)    read(b[j]);
    
    for(int i = 0, j = m-1; i < n; i++){
        while(j >= 0 && a[i]+b[j] > k)    j--;
        if(j >= 0 && a[i]+b[j] == k)    printf("%d %d\n",i,j);
    }

    return 0;
}
