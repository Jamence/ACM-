#include <bits/stdc++.h>
using namespace std;
const int maxn=50000+5;
struct node{
	int le;
	int ri;
};
bool cmp(node a,node b)
{
	if(a.le==b.le)return a.ri>b.ri;
	else
	return a.le<b.le;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	while(cin>>n){
		node inf[maxn];
		for(int i=0;i<n;i++)cin>>inf[i].le>>inf[i].ri;
		sort(inf,inf+n,cmp);
		int ans=0;
		int end=inf[0].ri;
		for(int i=1;i<n;i++){
			ans=max(ans,min(end,inf[i].ri)-inf[i].le);
			end=max(end,inf[i].ri);
		}
		cout<<ans<<endl;
		cout<<ans<<endl;
	} 
	return 0;
} 
