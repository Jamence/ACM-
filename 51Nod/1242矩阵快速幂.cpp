#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100;
const ll mod=1000000009;
struct Matrix
{
	ll a[maxn][maxn];
	ll r,c;
};
Matrix ori,res;
void ini()
{
	memset(res.a,0,sizeof res.a);
	ori.r=ori.c=res.r=res.c=2;
	for(int i=1;i<=res.r;i++)res.a[i][i]=1;
	ori.a[1][1]=1;
	ori.a[1][2]=1;
	ori.a[2][1]=1;
	ori.a[2][2]=0;
}
Matrix multi(Matrix x,Matrix y)
{
	Matrix z;
	z.r=x.r,z.c=y.c;
	memset(z.a,0,sizeof z.a);
	for(int i=1;i<=x.r;i++){
		for(int k=1;k<=x.c;k++){
			if(x.a[i][k]==0)continue;
			for(int j=1;j<=y.c;j++)
				z.a[i][j]=(z.a[i][j]+(x.a[i][k]*y.a[k][j])%mod)%mod;
		}
	}
	return z;
}
ll pow(ll n)
{
	while(n){
		if(n&1)res=multi(res,ori);
		ori=multi(ori,ori);
		n>>=1;
	}
	return res.a[1][2];
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	while(cin>>n){
		ini();
		cout<<pow(n)<<endl;
	}
} 
