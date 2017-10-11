//
//动态规划 
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+5;
ll a[maxn],dp[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	while(cin>>N){
		memset(dp,0,sizeof dp);
		for(int i=1;i<=N;i++)cin>>a[i];
		ll ans=INT_MIN;
		for(int i=1;i<=N;i++){
			dp[i]=max(dp[i-1]+a[i],(ll)0);
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}


//
//归并 
// 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5e4+5;
ll a[maxn];
ll maxsum(ll *A,ll x,ll y)
{
	ll v,L,R,maxs;
	if(y-x==1)return A[x];
	int m=x+(y-x)/2;
	maxs=max(maxsum(A,x,m),maxsum(A,m,y));
	v=0;L=A[m-1];
	for(ll i=m-1;i>=x;i--)L=max(L,v+=A[i]);
	v=0;R=A[m];
	for(ll i=m;i<y;i++)R=max(R,v+=A[i]);
	return max(maxs,L+R);
} 
int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	while(cin>>N){
		for(int i=0;i<N;i++)cin>>a[i];
		cout<<maxsum(a,0,N)<<endl;
	}
	return 0;
}
