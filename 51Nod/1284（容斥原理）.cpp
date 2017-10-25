#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	ll temp=0;
	temp+=n/2+n/3+n/5+n/7;
	temp-=(n/6+n/10+n/14+n/15+n/21+n/35);
	temp+=(n/85+n/70+n/42+n/30);
	temp-=(n/210);
	n-=temp;
	cout<<n<<endl;
} 
