#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//À©Õ¹GCD 
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
int main()
{
	std::ios::sync_with_stdio(false);
	ll m,n;
	while(cin>>m>>n){
		cout<<inv(m,n)<<endl; 
	} 
	return 0;
}
