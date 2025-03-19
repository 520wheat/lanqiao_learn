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

    long long ans = 0;//�����������鶼��ʮ�򼶱�ģ���ô������ 1e5 * 1e5 * 1e5 = 1e15
    for(int i = 1,indexA = 1,indexC = 1; i <= n; i++){
    int B = b[i];
        while(a[indexA] < B && indexA <= n)  indexA++;
        while(c[indexC] <= B && indexC <= n) indexC++;
        ans += (long long)(indexA - 1)*(n - indexC + 1);//����ͬ��Ҫ���Ǳ�int�� 1e5*1e5 = 1e10
        //��һ��long long �͸��������һ������Ϊ�˻���������ת�����߾���
    }
    printf("%lld\n",ans);//����һ��Ҫ�ǵ�дlld,���˰��첻֪�����������������TwT
    
    return 0;
}
