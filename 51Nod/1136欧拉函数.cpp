#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull; 
ull euler(ull x)
{
	ull i,res=x;
	for(i=2;i<(int)sqrt(x*1.0)+1;i++){
		if(x%i==0){
			res=res/i*(i-1);
			while(x%i==0)x/=i;
		}
	}
	if(x>1)res=res/x*(x-1);
	return res;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ull n;
	while(cin>>n){
		cout<<euler(n)<<endl;
	}
	return 0;
}
