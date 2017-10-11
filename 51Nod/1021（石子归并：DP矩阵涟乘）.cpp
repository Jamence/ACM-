#include <bits/stdc++.h>
using namespace std;
const int maxn=100+5;
const int INF=0x3f3f3f;
int dp[maxn][maxn],sum[maxn];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	while(cin>>n){
		sum[0]=0;
		int temp;
		for(int i=1;i<=n;i++){
			cin>>temp;
			sum[i]=sum[i-1]+temp;
		}
		memset(dp,0,sizeof dp);
		for(int len=2;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				dp[i][i+len-1]=INF;
				for(int k=i;k<=i+len-1;k++)
					dp[i][i+len-1]=min(dp[i][i+len-1],dp[i][k]+dp[k+1][i+len-1]+sum[i+len-1]-sum[i-1]);
			}
		}
		cout<<dp[1][n]<<endl;
	}
	return 0;
} 
