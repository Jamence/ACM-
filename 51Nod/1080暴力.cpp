#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		int flag=0;
		for(int i=0;i<=sqrt(n/2)+1;i++){
			int temp=n-i*i;
			int j=sqrt(temp);
			if(j*j==temp&&i<=j){
				cout<<i<<" "<<j<<endl;
				flag=1;
			}
		}
		if(!flag){
			cout<<"No Solution"<<endl;
		}
	}
	return 0;
}
