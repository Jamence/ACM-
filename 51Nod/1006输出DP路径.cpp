#include <bits/stdc++.h>
using namespace std;
const int maxn=1000+5;
char a[maxn],b[maxn];
int dp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while(~scanf("%s%s",a,b)){
		memset(dp,0,sizeof dp);
		int lena=strlen(a),lenb=strlen(b);
		for(int i=0;i<lena;i++){
			for(int j=0;j<lenb;j++){
				if(a[i]==b[j])dp[i+1][j+1]=dp[i+1-1][j+1-1]+1;
				else
				dp[i+1][j+1]=max(dp[i+1-1][j+1],dp[i+1][j+1-1]);
			}
		}
		string output = "";
		//回溯的方法 
		int n=lena,m=lenb;
		while (dp[n][m] > 0) {
			if (dp[n][m] == dp[n - 1][m])
				n--;
			else if (dp[n][m] == dp[n][m - 1])
				m--;
			else {
				output.insert(0, string(1, a[n - 1]));
				n--;
				m--;
			}
		}
		cout<<output<<endl;
	}
	
	return 0;
} 
