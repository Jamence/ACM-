/*
1013 3的幂的和
基准时间限制：1 秒 空间限制：131072 KB 分值: 20 难度：3级算法题 收藏  关注
求：3^0 + 3^1 +...+ 3^(N) mod 1000000007
Input
输入一个数N(0 <= N <= 10^9)
Output
输出：计算结果
Input示例
3
Output示例
40

*/
//记住，要求逆元 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
//得用逆元，我去 
ll extgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll d=extgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return d;
} 
ll inv(ll a,ll mod)
{
	ll x,y;
	extgcd(a,mod,x,y);
	return (mod+x%mod)%mod;
}
ll fast_pow(ll a,ll b,ll mod)
{
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll n;
	while(cin>>n){
		ll ans=0;
//		cout<<fast_pow(3,n+1,mod)<<endl;
		ans=((fast_pow(3,n+1,mod)-1)*inv(2,mod))%mod;
		cout<<ans<<endl;
	}	
	return 0;
}
