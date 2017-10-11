#include <bits/stdc++.h>
using namespace std;
const int maxn=2000+5;
const int INF=1<<30;
long long dp[maxn][maxn],sum[maxn];
int s[maxn][maxn]; 
int a[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	while(cin>>n){
		sum[0]=0;
//		int temp;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=1;i<=n;i++)sum[i+n]=sum[i+n-1]+a[i];
		for(int i=1;i<=2*n;i++)s[i][i]=i; 
		memset(dp,0,sizeof dp);
		int ans=INF;
		for(int len=2;len<=n;len++){
			
			for(int i=1;i+len-1<=2*n;i++){
				dp[i][i+len-1]=INF;
				int j=i+len-1;
				for(int k=s[i][j-1];k<=s[i+1][j];k++){
					int temp=dp[i][k]+dp[k+1][i+len-1]+sum[i+len-1]-sum[i-1];
					if(dp[i][i+len-1]>temp){
						dp[i][i+len-1]=temp;
						s[i][j]=k;
					}
//					dp[i][i+len-1]=min(dp[i][i+len-1],dp[i][k]+dp[k+1][i+len-1]+sum[i+len-1]-sum[i-1]);
				}
				if(len==n&&dp[i][i+len-1]<ans)ans=dp[i][i+len-1];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 


/*
#include <cstdio>  
#include <iostream>  
#include <cstring>  
using namespace std;  
#define LL int  
#define inf 1<<30  
#define min(a,b) ((a)<(b)?(a):(b))  
LL dp[2002][2002];  
LL s[2002][2002];  
LL p[2002];  
LL w[2002][2002];  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
  
        for(int i=1;i<=n;++i)  
        {  
            scanf("%d",&p[i]);  
            p[i+n]=p[i];  
        }  
        memset(s,0,sizeof(s));  
        memset(w,0,sizeof(w));  
        for(int i=1;i<2*n;++i)  
        {  
            for(int j=i;j<=i+n;++j)  
            {  
                w[i][j]=w[i][j-1]+p[j];  
            }  
            s[i][i]=i;  
            dp[i][i]=0;  
        }  
  
        for(int len=2;len<=n;++len)  
        {  
            for(int i=1;i<=2*n-len+1;++i)  
            {  
                int j=i+len-1;  
                dp[i][j]=inf;  
                for(int k=s[i][j-1];k<=s[i+1][j];++k)  
                {  
                    LL tmp=dp[i][k]+dp[k+1][j]+w[i][j];  
                    if(tmp<dp[i][j])  
                    {  
                        dp[i][j]=tmp;  
                        s[i][j]=k;  
                    }  
                }  
            }  
        }  
          
        LL ans=inf;  
        for(int i=1;i<=n;++i)  
        {  
            ans=min(ans,dp[i][i+n-1]);  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
} 
*/
