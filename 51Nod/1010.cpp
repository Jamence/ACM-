#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int>inf;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	inf.insert(2),inf.insert(3),inf.insert(5);
	cout<<*(inf.begin())<<endl; 
	int i=0;
	//变相的打表 
	while(*(inf.end())<0){
		inf.insert(2* *(inf.begin()+i));
		inf.insert(3* *(inf.begin()+i));
		inf.insert(5* *(inf.begin()+i));
		i++;
	}
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
	}
	return 0;
} 
