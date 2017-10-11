/*
令a数组所有数的最小公倍数为lcm
方程在lcm范围内的非负整数解是a，则有a+lcm*x<=N,
若a！=0,解得的x为要求的解的个数
否则x-1为题目所求 
*/ 
#include <iostream>
using namespace std;
const int maxn=15;

typedef long long ll;
ll aa[15],r[15];
ll n,m,lcm;
ll  gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
void Ex_gcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	if(b==0){
		x=1,y=0;
		d=a;
		return ;
	}
	else{
		Ex_gcd(b,a%b,d,x,y);
		ll temp=x;
		x=y;
		y=temp-(a/b)*y;
	}
}
ll solve()
{
	ll a1,a2,r1,r2;
	ll a,b,c,d,x0,y0;
	bool ifhave=1;
	a1=aa[1];
	r1=r[1];
	for(int i=2;i<=m;i++){
		a2=aa[i],r2=r[i];
		a=a1,b=a2,c=r2-r1;
		Ex_gcd(a,b,d,x0,y0);
		if(c%d!=0){
			ifhave=0;
		}
		ll t=b/d;
		x0=(x0*(c/d)%t+t)%t;
		r1=a1*x0+r1;
		a1=a1*(a2/d);
	}
	if(!ifhave){
		r1=-1;
	}
	return r1;
}
int main()
{
	ios::sync_with_stdio(false);
	ll ncase;
	cin>>ncase;
	while(ncase--){
		lcm=1;
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>aa[i];
			lcm=lcm*aa[i]/gcd(lcm,aa[i]);
		}
		for(int i=1;i<=m;i++)cin>>r[i];
		ll temp=solve();
		if(temp==-1){
			cout<<"0"<<endl;
		}
		else{
			ll ans=0;
			if(temp<=n)ans=1+(n-temp)/lcm;
			if(ans&&temp==0)ans--;
			cout<<ans<<endl;
		}
	}
	return 0;
}
