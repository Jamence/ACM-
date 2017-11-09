#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=100000+1;
vector<ll>prime[maxn];
ll que[maxn];
void ini()
{
    for(ll i=0;i<=maxn;i++)prime[i].clear();
    for(ll i=2;i<=maxn;i++){
        ll temp=i;
        for(ll j=2;j*j<=i;j++){
            if(temp%j==0){
                prime[i].push_back(j);
                while(temp%j==0){
                    temp/=j;
                }
            }
        }
        if(temp>1)prime[i].push_back(temp);
    }
}
//n表示与n互质，a表示（1---a）的范围 
ll cal(ll n,ll a)
{
    ll num=0;
    que[num++]=1;
    for(ll i=0;i<prime[n].size();i++){
        ll temp=prime[n][i];
        if(temp>a)break;
        ll k=num;
        for(ll j=0;j<k;j++){
            que[num++]=temp*que[j]*(-1);
        }
    }
    ll sum=0;
    for(ll i=0;i<num;i++){
        sum+=a/que[i];
    }
    return sum;
}
int main()
{
    ini();
    ll T;
    cin>>T;
    ll m,n;
    while(T--){
        cin>>m>>n;
        ll sum=n;
        for(ll i=2;i<=m;i++){
            sum+=cal(i,n);
        }    
        cout<<sum<<endl;
    }
    return 0;
} 
