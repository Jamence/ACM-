#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mobi(ll n)
{
	ll m=1;
	for(ll i=2;i*i<=n;i++)
	if(n%i==0)
	{
		m*=-1;
		ll k=0;
		do{
			k++;
			if(k>1){
				m=0;
				break;
			}
			n/=i;
		}while(n%i==0);
	}
	if(n>1)m*=-1;
	return m;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	while(cin>>n){
		cout<<mobi(n)<<endl;
	}
	return 0;
} 
