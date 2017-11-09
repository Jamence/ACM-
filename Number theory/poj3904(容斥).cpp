#include<stdio.h>
#include<string.h>
using namespace std;
#define LL long long
#define maxn 10005

LL node[maxn],num[maxn],vist[maxn],prime[maxn];
void Init()
{
	LL i;
	for(i=4;i<maxn;i++)
		node[i]=i*(i-1)*(i-2)*(i-3)/24;
}

void make_count(int m)
{
	int i,j,tmp,flag,cnt=0;
	for(i=2;i*i<=m;i++)
		if(m&&m%i==0)
		{
			prime[cnt++]=i;
			while(m&&m%i==0)
				m/=i;
		}	
	if(m>1)
		prime[cnt++]=m;
		
	for(i=1;i<(1<<cnt);i++)//遍历所有情况 
	{
		tmp=1,flag=0;
		for(j=0;j<cnt;j++)
			if(i&(1<<j))
				flag++,tmp*=prime[j];
		num[tmp]++;  //统计当前因子出现的次数
		vist[tmp]=flag; //记录当前因子是由多少个素因子组成，奇加偶减
	}
}

int main()
{
	Init();
	int n,i,x;
	while(~scanf("%d",&n))
	{
		memset(num,0,sizeof(num));
		memset(vist,0,sizeof(vist));
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			make_count(x);
		}
		LL ans=0;
		for(i=1;i<maxn;i++)
			if(num[i])
			{
				if(vist[i]&1)
					ans+=node[num[i]];
				else
					ans-=node[num[i]];
			}
		printf("%I64d\n",node[n]-ans);			
	}
	return 0;
}
