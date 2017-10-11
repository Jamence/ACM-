#include <bits/stdc++.h>
using namespace std;
const int maxn=50000;
int a[maxn]; 
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<n;i++)cout<<a[i]<<endl;
	}
	return 0;
}
