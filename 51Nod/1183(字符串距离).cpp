#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
char a[maxn],b[maxn];
//第一个参数：表示a 
//第二个参数： 表示b 
int dp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false); 
	while(cin>>a>>b){
		int lena=strlen(a),lenb=strlen(b);
		memset(dp,0,sizeof dp); 
		for(int i=0;i<=lena;i++)dp[i][0]=i;
		for(int i=0;i<=lenb;i++)dp[0][i]=i;
		
		for(int i=1;i<=lena;i++){
			for(int j=1;j<=lenb;j++){
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(a[i-1]!=b[j-1]));
			}
		}
		cout<<dp[lena][lenb]<<endl;
	}
	return 0;
} 
