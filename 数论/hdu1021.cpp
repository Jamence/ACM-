//hdu1021(อฌำเ)
//
//
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int fin[maxn];
void pre()
{
	fin[0]=7%3,fin[1]=11%3;
	for(int i=2;i<maxn;i++)fin[i]=(fin[i-1]+fin[i-2])%3;
}
int main()
{
	std::ios::sync_with_stdio(false);
	pre();
	int n;
	while(cin>>n){
		if(fin[n])cout<<"no"<<endl;
		else
		cout<<"yes"<<endl;
	}
	return 0;
} 
