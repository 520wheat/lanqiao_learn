/*
������������������50000,���ʹ��dpӦ����O(n^2),�ͳ�ʱ��
˼·Ӧ����ö�ٳ�һ���Ϸ���������Ծ����

����һ��ʲô������Ծ�����ǺϷ���
��ע����ö�ٳ��Ŀ��ܴ𰸺���������ߵ�ʯͷ��Ŀ M
�����뵽�������ܱ�������ʯͷ��ͬʱ��¼���ǵĵ�ǰλ��Pos
�������Ҫ����ȥ��ʯͷa[i]�����Ǵ�ʱ�ľ��������ö�ٳ��Ŀ��ܴ𰸻�С��
�����ʯͷӦ�����ߣ���a[i]-pos<xʱ�����ߴ���+1

���������ôö�ٴ�
�������һ��һ���ۼ�ö�٣������ǻᳬʱ��
��ʱ��͵�������ǵĶ��ִ���
*/
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5e4+10;
int a[N],len,n,m;

bool f(int x){
    int pos = 0,cnt = 0;//����㿪ʼ������POSȡֵ0
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
    a[++n] = len;//�㻹�������յ�

    int l = 0,r = len+1;
    while(l+1<r){
        int mid = (l+r)>>1;
        if(f(mid))  l = mid;
        else  r = mid;
    }
    cout << l << endl;
    
    return 0;
}
