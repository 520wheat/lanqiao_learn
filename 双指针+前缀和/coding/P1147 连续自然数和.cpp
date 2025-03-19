#include<iostream>
using namespace std;
#define read(x) scanf("%d",&x)

const int N = 2e6+10;
int m;

int main(){
    read(m);
    int sum = 3;
    for(int i = 1,j = 2; i <= m/2;){
        if(sum == m){
            printf("%d %d\n",i,j);
            sum -= i;
            i++;
        }else if(sum < m){
            j++;
            sum += j;
        }else{
            sum -= i;
            i++;
        }
    }
    
    return 0;
}
