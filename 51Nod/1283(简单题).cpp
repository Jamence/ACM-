#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int s; 
	while(cin>>s){
		int x=sqrt(s);
		int ans_x;
		for(int i=0;;i++){
			if(s%(x+i)==0){
				ans_x=x+i;
				break;
			}
			if(s%(x-i)==0){
				ans_x=x-i;
				break;
			}
		}
		cout<<2*(ans_x+s/ans_x)<<endl;
	}	
	return 0;
} 
