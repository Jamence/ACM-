#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll witness(ll a,ll n)
{
	ll x,d=1,i=ceil(log(n-1.0)/log(2.0))-1;
	for(;i>=0;i--){
		x=d;
		d=(d*d)%n;
		if(d==1&&x!=1&&x!=n-1)return 1;
		if(((n-1)&(1<<i))>0)d=(d*a)%n;
	}
	return (d==1?0:1);
}
ll miller(ll n,ll s=50)
{
	if(n==2)return 1;
	if((n%2)==0)return 0;
	ll j,a;
	for(j=0;j<s;j++){
		a=rand()*(n-2)/RAND_MAX+1;
		if(witness(a,n))return 0;
	}
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	while(cin>>n){
		ll temp;
		for(ll i=0;i<n;i++){
			cin>>temp;
			if(miller(temp))cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
