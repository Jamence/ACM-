#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll p,a;
	while(cin>>p>>a){
		ll num=0;
		for(ll i=1;i<=p;i++){
			if((i%p)*(i%p)%p==a){
				if(num=0)cout<<i;
				else
					cout<<" "<<i;
				num++;
			}
		}
		if(num==0)
			cout<<"No Solution";
		cout<<endl; 
	} 
	return 0;
}
