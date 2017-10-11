#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is_ok(ll x)
{
	ll temp=sqrt(2*x);
	if(temp*(temp+1)==2*x)return true;
	else
	return false;
}
int main()
{
	ll n;
	while(cin>>n){
		ll sum=0;
		sum=(1+n)*n/2;
		if(n==1)cout<<"0"<<endl;
		else
		if(is_ok(n))cout<<"1"<<endl;
		else{
			cout<<(n)/2<<endl;
		}
	}
	return 0;
}
