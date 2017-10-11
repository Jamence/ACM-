#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+5;
const int INF=0x3f3f3f;
int a[maxn],dp[maxn];
//01DP
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	while(cin>>n){
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];	
		}
		 
		int temp=sum/2;
		memset(dp,0,sizeof dp);
		for(int i=0;i<n;i++)
			for(int j=temp;j>=a[i];j--)
				dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
		cout<<abs(sum-dp[temp]-dp[temp])<<endl;
	}
	return 0;
} 
