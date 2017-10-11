#include <bits/stdc++.h>
using namespace std;
const int maxn=100+5;
typedef long long ll;
ll a1[maxn][maxn],a2[maxn][maxn],ans[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)cin>>a1[i][j];
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)cin>>a2[i][j];
		
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				if(a1[i][k]==0)continue;
				for(int j=0;j<n;j++){
					ans[i][j]+=a1[i][k]*a2[k][j];
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==0)cout<<ans[i][j];
				else
				cout<<" "<<ans[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
} 
