//计算ax+by=c
//最小的x的值
// 
#include <iostream>
using namespace std;
typedef long long ll;
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
void solve(ll a,ll b,ll c)
{
	ll x,y,d;
	Ex_gcd(a,b,d,x,y);
	if(c%d!=0){
		cout<<"FOREVER"<<endl;
	}
	else{
		x=x*c/d;
		ll temp=b/d;
		cout<<(x%temp+temp)%temp<<endl;
	}
} 
int main()
{
	ios::sync_with_stdio(false);
	ll a,b,c,k;
	while(cin>>a>>b>>c>>k&&(a+b+c+k)){
		ll tempa=c,tempb=(ll)1<<k,tempc=b-a;
		solve(tempa,tempb,tempc);
	}
	return 0;
}
