#include <bits/stdc++.h>
using namespace std;
const int maxw=10000+5;
const int maxn=100+5;
int dp[maxw];
int p[maxn];
int wei[maxn];
int main() 
{
	int n,w;
	while(cin>>n>>w){
		for(int i=0;i<n;i++)cin>>wei[i]>>p[i];
		
		for(int i=0;i<w;i++)dp[i]=0;
		
		for(int i=0;i<n;i++){
			for(int j=w;j>=wei[i];j--)
			dp[j]=max(dp[j],dp[j-wei[i]]+p[i]);
		}
		cout<<dp[w]<<endl;
	}
}
