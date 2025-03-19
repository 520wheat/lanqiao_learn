#include<iostream>
using namespace std;
#define read(x) scanf("%d",&x)

const int N = 1010;
int n,q;
int x,y,z;
int ans = 0;
int a[N][N],b[N][N],c[N][N];

int main(){
    read(n);read(q);
    while(q--){
        read(x);read(y);read(z);
        a[x][y]++;
        b[x][z]++;
        c[y][z]++;

        // if(a[x][y]==n || b[x][z]==n || c[y][z]==n)  ans++;
        if(a[x][y]==n)  ans++;
        if(b[x][z]==n)  ans++;
        if(c[y][z]==n)  ans++;

        printf("%d\n",ans);
    }
    return 0;
}
