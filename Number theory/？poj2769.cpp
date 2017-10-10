//poj2769 
//同余定理 
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1e6+5;
bool flag[100001];
//难点在这里，为啥是5位数 
int inf[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
//	std::
	int n;
	cin>>n;
	while(n--){
		int ans; 
		int m;
		cin>>m;
		for(int i=0;i<m;i++)cin>>inf[i];
		for(int i=1;;i++){
			memset(flag,0,sizeof flag);
			bool find=1;
			for(int j=0;j<m;j++){
				if(flag[inf[j]%i]){
					find=0;
					break;
				}
				else{
					flag[inf[j]%i]=1;
					
				}
			}
			if(find){
				ans=i;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
