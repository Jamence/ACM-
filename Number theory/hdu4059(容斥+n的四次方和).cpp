#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll maxn=1000000;
ll prime[maxn];
ll que[maxn];
ll flag[maxn];
ll fast_pow(ll a,ll b)
{
	ll ans=1;
	while(b){
		if(b&1)ans=(ans*a%mod+mod)%mod;
		a=(a*a%mod+mod)%mod;
		b>>=1;
	}
	return ans;
}
ll sum_n(ll n)//计算i的四次方一直到n (6n^5+15n^4+10n^3-n)/30
{
//	ll INF=fast_pow(30,mod-2);
 //   return n*(n+1)%mod*(2*n+1)%mod*((3*n*n%mod+3*n-1)%mod)%mod*INF%mod;
	return (((( (6*fast_pow(n,5)%mod+mod)%mod + (15*fast_pow(n,4)%mod+mod)%mod +(10*fast_pow(n,3)%mod+mod)%mod -n + mod)%mod+mod)%mod)*fast_pow(30,mod-2)%mod+mod)%mod;
}
ll n_4(ll n)
{
	return fast_pow(n,4);
}
ll solve(ll n)
{
	//分解质因数
	ll temp=n;
	ll num=0;
	for(ll i=2;i*i<=n;i++){
		if(temp%i==0){
			prime[num++]=i;
			while(temp%i==0)
				temp/=i;
		}
	}
	if(temp>1)prime[num++]=temp;
	
	//容斥
	//表示有num个质因数 
	ll cnt=0;
	que[cnt]=1;
	flag[cnt++]=1;
	for(ll i=0;i<num;i++){
		
//		cout<<prime[i]<<endl;
		
		ll ep=prime[i];
//		ll ep_flag=flag[i];
		ll k=cnt;
		for(ll j=0;j<k;j++){
			que[cnt]=que[j]*ep;
			flag[cnt++]=flag[j]*(-1);
		}
	}
	ll ans=0;
	for(ll i=0;i<cnt;i++){
		ans=(ans+flag[i]*( (((n_4(que[i]))%mod)*(sum_n(n/que[i])%mod)+mod)%mod + mod)+mod)%mod;
//		cout<<flag[i]*que[i]<<"  "<<flag[i]*((n_4(que[i]))%mod)*(sum_n(n/que[i])%mod)<<endl;
	}
	cout<<ans<<endl;
}
int main()
{
//	cout<<fast_pow(30,mod-2)<<endl;
//	cout<<sum_n(3);
	ll T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		solve(n);
	}
	return 0;
}
