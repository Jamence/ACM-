#include <bits/stdc++.h>
using namespace std;
bool is_ok(int n)
{
	int del=1+8*(n-1);
	if(del<0)return false;
	int sdel=sqrt(del);
	int x1=(1+sdel)/2,x2=(1-sdel)/2;
	if(x1*x1-x1==2*(n-1)||x2*x2-x2==2*(n-1))return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	int ncase;
	cin>>ncase;
	while(ncase--){
		int n;
		cin>>n;
		if(is_ok(n))cout<<"1"<<endl;
		else
		cout<<"0"<<endl;
	} 
	return 0;
}
