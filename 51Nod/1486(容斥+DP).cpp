#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2000+5;
const ll mod=1000000007;
const ll maxw=2e5+5;
ll inv[maxw],fac[maxw],dp[maxn];
struct node
{
	ll x;
	ll y;
}inf[maxn];
bool cmp(node a,node b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
ll fast_pow(ll a,ll b)
{
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void pre()
{
	inv[0]=fac[0]=1;
	for(int i=1;i<=maxw;i++){
		fac[i]=fac[i-1]*i%mod;
		inv[i]=fast_pow(fac[i],mod-2);
	}
}
ll C(ll a,ll b)
{
	return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
	int h,w,n;
	pre();
//	cin>>h>>w;
	while(cin>>h>>w>>n){
		for(int i=1;i<=n;i++)cin>>inf[i].x>>inf[i].y;
		inf[n+1].x=h,inf[n+1].y=w;
		sort(inf+1,inf+n+1,cmp); 
		for(int i=1;i<=n+1;i++){
			dp[i]=C(inf[i].x+inf[i].y-2,inf[i].x-1);
			for(int j=1;j<i;j++){
				if(inf[i].x>=inf[j].x&&inf[i].y>=inf[j].y)
					dp[i]=(dp[i]-dp[j]*(C(inf[i].x-inf[j].x+inf[i].y-inf[j].y,inf[i].x-inf[j].x))%mod+mod)%mod;
			}
		}
		cout<<dp[n+1]<<endl;
	}
}
