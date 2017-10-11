/*
1013 3���ݵĺ�
��׼ʱ�����ƣ�1 �� �ռ����ƣ�131072 KB ��ֵ: 20 �Ѷȣ�3���㷨�� �ղ�  ��ע
��3^0 + 3^1 +...+ 3^(N) mod 1000000007
Input
����һ����N(0 <= N <= 10^9)
Output
�����������
Inputʾ��
3
Outputʾ��
40

*/
//��ס��Ҫ����Ԫ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
//������Ԫ����ȥ 
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
