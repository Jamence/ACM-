#include <bits/stdc++.h>
using namespace std;
const int maxn=10000+5;
char s[maxn]; 
int num[30]; 
//¸ÄÎªÐ¡Ð´ 
void tostd()
{
	for(int i=0;i<strlen(s);i++){
		if(s[i]>'Z')
			s[i]-=32;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	while(cin>>s){
		memset(num,0,sizeof num);
		tostd();
//		cout<<s<<endl;
		for(int i=0;i<strlen(s);i++){
			num[s[i]-'A']++;
		}
		sort(num,num+26);
//		for(int i=0;i<26;i++)cout<<num[i]<<endl;
		int ans=0;
		for(int i=25;i>=0;i--){
			ans+=(i+1)*num[i];
		}
		cout<<ans<<endl;
	}	
	return 0;
} 
