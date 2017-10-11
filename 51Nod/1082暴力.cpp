#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+1;
ll inf[maxn];
bool is_ok(ll n)
{
	if(n%7==0)return false;
	while(n){
		if(n%10==7)return false;
		n/=10;
	}
	return true;
}
void pre()
{
	inf[0]=0;	
	for(ll i=1;i<=1e6;i++){
		ll temp=0;
		if(is_ok(i))temp=i*i;
		inf[i]=inf[i-1]+temp;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	pre();
	ll ncase;
	cin>>ncase;
	while(ncase--){
		ll n;
		cin>>n;
		cout<<inf[n]<<endl;
	}
	return 0;
}
