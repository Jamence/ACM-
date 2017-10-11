#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1e3+5;
const int maxk=2e4+5;
int dp[maxn][maxk];
void ini()
{
	for(int i=1;i<maxn;i++)dp[i][0]=1;
	for(int i=2;i<maxn;i++){
		int up=i*(i-1)/2;
		//用于减少不必要的循环及枚举 
		for(int j=1;j<=up&&j<maxk;j++){
			dp[i][j]=((dp[i][j-1]+dp[i-1][j]-(j>=i?dp[i-1][j-i]:0))%mod+mod)%mod; 
//			dp[i][j] = ((dp[i][j - 1] + dp[i - 1][j] - (j - i >= 0 ? dp[i - 1][j - i] : 0)) % mod ) % mod;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin>>T;
	ini();
	while(T--){
		int n,k;
		cin>>n>>k;
		cout<<dp[n][k]<<endl<<endl;
	}
	return 0;
} 
