#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
const ll MOD=1e9+7;
ll inv[maxn+10],fac[maxn+10];
//费马小定理
/*
 *假如p是质数，且gcd(a,p)=1，那么 a^(p-1)≡1（mod p）    
 *根据这个性质我们可以知道 a的逆元为a^(p-2) 
 */ 
ll fast_pow(ll a,ll b)
{
	ll ans=1;
	while(b){
		if(b&1ll)ans=a*ans%MOD;
		a=a*a%MOD;
		b>>=1ll;
	}
	return ans;
}
void pre()
{
	inv[0]=1ll;
	fac[0]=1ll;
	for(int i=1;i<=maxn;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=fast_pow(fac[i],MOD-2ll);
	}
}
ll C(ll a,ll b)
{
	return fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}
int main()
{
	pre();
	ll a,b;
	while(cin>>a>>b){
		cout<<"a,b的组合数为：C(a,b):"<<endl; 
		cout<<C(a,b)<<endl;
	}
} 
