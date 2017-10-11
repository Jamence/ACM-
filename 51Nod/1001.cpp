#include<bits/stdc++.h>
using namespace std;
const int maxn=50000+5;
int a[maxn];
int main()
{
	//O(n)µÄËã·¨ 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int k,n;
	cin>>k>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int sum=a[0]+a[n-1];
	int l=0,r=n-1;
	int flag=1;
	while(l<r){
		if(sum==k){
			cout<<a[l]<<" "<<a[r]<<endl;
			l++,r--;
			sum=a[l]+a[r];
			flag=0;
		}else
		if(sum>k){
			r--;
			sum=a[l]+a[r];
		}else
		if(sum<k){
			l++;
			sum=a[l]+a[r];
		}
	}
	if(flag==1)
		cout<<"No Solution"<<endl;
	return 0;
} 
