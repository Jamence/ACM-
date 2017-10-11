#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7;
int vis[maxn],prime[maxn]; 
int ans[maxn];
int n,temp_num;
void ini()
{
	memset(vis,0,sizeof vis);
	int temp=sqrt(maxn+0.5);
	for(int i=2;i<=temp;i++){
		if(!vis[i])
		for(int j=i*i;j<=maxn;j+=i){
			vis[j]=1;
		}
	}
	int num=0;
	for(int i=2;i<=maxn;i++)if(!vis[i])prime[num++]=i;
//	for(int i=0;i<num;i++)cout<<prime[i]<<endl;
	temp_num=0;
	for(int i=0;i<num;i++){
		if(prime[i]<=num-1)
		ans[temp_num++]=prime[prime[i]-1];
		else
		break;
	}
//	for(int i=0;i<temp_num;i++){
//		cout<<ans[i]<<endl;
			
//	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	ini();
	while(cin>>n){
//		cout<<temp_num<<endl;
//		for(int i=0;i<=10;i++)cout<<ans[i]<<endl;
		cout<<*lower_bound(ans,ans+temp_num,n)<<endl;
	}
}   
