#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> prime;
ll que[5000];
ll a,b,n;
void pre()
{
	prime.clear();
	ll temp=n;
	for(ll i=2;i*i<=n;i++){
		if(temp%i==0){
			prime.push_back(i);
			while(temp%i==0){
				temp/=i;
			}
		}
	}
	if(temp>1)prime.push_back(temp);
//	for(int i=0;i<prime.size();i++)cout<<prime[i];
}
ll cal(ll a,ll n)
{
	ll num=0;
	que[num++]=1;
	for(int i=0;i<prime.size();i++){
		ll temp=prime[i];
		ll k=num;
		for(ll j=0;j<k;j++){
			que[num++]=temp*que[j]*(-1);
		}
	}
//	for(int i=0;i<num;i++)cout<<que[i]<<endl;
	ll sum=0;
	for(int i=0;i<num;i++){
		sum+=a/que[i];
	}
	return sum;
}
int main()
{
	int T;
	cin>>T;
	int ncase=1;
	while(T--){
		cin>>a>>b>>n;
		pre();
		
		cout<<"Case #"<<ncase++<<": "<<cal(b,n)-cal(a-1,n)<<endl;
	}
	return 0;
}
