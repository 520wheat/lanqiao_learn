#include<iostream>
using namespace std;

#define read(x) scanf("%d",&x)

const int N = 1e6+10;
int a[N];
int t,n,ans = 0;

int main(){
	read(t);
	while(t--){
		ans = 0;
		read(n);
		for(int i = 1; i <= n; i++)	read(a[i]);
		
		int i = 1;
		while(i <= n){
			if(i == a[i]){
				i++;
			}else{
				int mx = a[i];
				int j = i+1;
				mx = max(mx,a[j]);//±ðÂ©ÁË
				
				while(mx > j){
					j++;
					mx = max(mx,a[j]);
				} 
				
				ans += j-i+1;
				i = j+1;
			}
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
