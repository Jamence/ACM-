#include <bits/stdc++.h>
using namespace std;
const int maxn=50000+5;
int a[maxn],c[maxn],cnt;
void MergeSort(int l,int r)
{
	int mid,i,j,tmp;
	if(r>l+1){
		mid=(l+r)/2;
		MergeSort(l,mid);
		MergeSort(mid,r);
		tmp=l;
		for(i=l,j=mid;i<mid&&j<r;){
			if(a[i]>a[j]){
				c[tmp++]=a[j++];
				cnt+=mid-i;
			}
			else
			c[tmp++]=a[i++];
		}
		if(j<r)for(;j<r;j++)c[tmp++]=a[j];
		else for(;i<mid;i++)c[tmp++]=a[i];
		for(i=l;i<r;i++)a[i]=c[i];
	}
}
int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)cin>>a[i];
		cnt=0;
		MergeSort(1,n+1);
		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		cout<<endl;
		cout<<cnt<<endl;
	}
}
