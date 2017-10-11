/*
暴力做法 ：
从2开始枚举，然后暴力判断g^(P-1) = 1 (mod P)是否当且仅当指数为P-1的时候成立
25分0.0 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
long long Mi(int a,int m,int p)
{
    if(m==0)return 1;
    long long x=Mi(a,m/2,p)%p;
    x=x*x%p;
    if(m%2==1)x=x*a%p;
    return x;
}
int get_root(int p)
{
    for(int g=2;g;g++)
      {
          int x=Mi(g,p-1,p),falg=0;
          if(x!=1)continue;
          for(int i=2;i<=p-2;i++)
            if(Mi(g,i,p)==1)
              {
                falg=1;
                break;
            }
        if(falg==0)return g;
      }
}
int main()
{
    int p;
    scanf("%d",&p);
    printf("%d\n",get_root(p));
    return 0;
}

/*
求出x-1所有不同的质因子p1,p2...pm，对于任何2<=a<=x-1,判定a是否为x的原根，
只需要检验a^((x-1)/p1),a^((x-1)/p2),...a^((x-1)/pm)这m个数中，
是否存在一个数mod x为1，若存在，a不是x的原根，否则就是x的原根。
O(m)*log（P-1）
100分 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
using namespace std;
int n,prime[maxn],l,f[maxn],ans[maxn],num;
void get_prime()
{
    for(int i=2;i<=maxn;i++)
      {
          if(!f[i])prime[++l]=i;
          for(int j=1;j<=l;j++)
            {
                if(i*prime[j]>maxn)break;
                f[i*prime[j]]=1;
                if(i%prime[j]==0)break;
          }
      }
}
void get_num()
{
    int k=n-1;
    for(int i=1;i<=l;i++)
      {
          int falg=0;
          while(k%prime[i]==0)
            {
                k=k/prime[i];
                falg=1;
          }
        if(falg)ans[++num]=prime[i];
        if(k==1)break;
      }
}
long long Mi(int a,int m,int p)
{
    if(m==0)return 1;
    long long x=Mi(a,m/2,p)%p;
    x=x*x%p;
    if(m%2==1)x=x*a%p;
    return x;
}
int judge(int x)
{
    for(int i=1;i<=num;i++)
      if(Mi(x,(n-1)/ans[i],n)==1)
        return 0;
    return 1;
}
int main()
{
    scanf("%d",&n);
    get_prime();
    get_num();
    for(int i=2;i;i++)
      if(judge(i))
        {
          printf("%d\n",i);
          return 0;
        }
}
