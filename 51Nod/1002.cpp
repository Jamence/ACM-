#include<bits/stdc++.h>
using namespace std;
const int maxn=500+5;
int inf[maxn][maxn];
int dp[maxn][maxn];
int main()
{
	//O(n)µÄËã·¨ 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			cin>>inf[i][j];
			
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=i;j++){
			if(i==n-1)
				dp[i][j]=inf[i][j];
			else
			dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+inf[i][j];
		}
	}
	cout<<dp[0][0]<<endl;
	return 0;
} 
