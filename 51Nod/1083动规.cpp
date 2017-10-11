#include <bits/stdc++.h>
using namespace std;
const int maxn=500+5;
int a[maxn][maxn],ans[maxn][maxn]; 
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int i=0;i<=n;i++)ans[i][0]=0;
		for(int i=0;i<=n;i++)ans[0][i]=0;
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				ans[i][j]=max(ans[i-1][j],ans[i][j-1])+a[i][j];
			}
		cout<<ans[n][n]<<endl;
	}
	return 0;
}
