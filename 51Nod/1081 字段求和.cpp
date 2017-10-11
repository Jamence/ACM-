#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+5;
ll sum[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	while(cin>>N){
		sum[0]=0;
		int temp;
		for(int i=1;i<=N;i++){
			cin>>temp;
			sum[i]=sum[i-1]+temp;
		}
		int Q;
		cin>>Q;
		int a,b;
		for(int i=0;i<Q;i++){
			cin>>a>>b;
			cout<<sum[a+b-1]-sum[a-1]<<endl;
		}
	}
	return 0;
} 
