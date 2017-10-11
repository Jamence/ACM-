#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll steling(ll n)  
{  
    return ll(log10(sqrt(4*acos(0.0)*n))+n*log10(n/exp(1.0)))+1;    
}  
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		if(n==1)cout<<1<<endl;
		else
		cout<<steling(n)<<endl;
	}
	return 0;
} 
