#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+5; 
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		bool flag=0;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int z=j+1;z<n;z++){
					if(a[i]+a[j]+a[z]==0){
						flag=1;
						cout<<a[i]<<" "<<a[j]<<" "<<a[z]<<endl;
					}
						
				}
			}
		}
		if(flag==0)cout<<"No Solution"<<endl;
	}
	return 0;
}
