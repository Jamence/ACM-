#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-9;
struct node
{
	ll x,y;
};
bool inter(node a, node b, node c, node d)
{
    if (min(a.x, b.x) > max(c.x, d.x) || min(a.y, b.y) > max(c.y, d.y) || min(c.x, d.x) > max(a.x, b.x) || min(c.y, d.y) > max(a.y, b.y))
    {
        return 0;
    }
    double h, i, j, k;
    h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
    //用于判断cd是否在ab两边 
    j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
    //用于判断ab是否在cd两边 
    return h * i <= eps && j * k <= eps;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		node x1,y1,x2,y2;
		cin>>x1.x>>x1.y>>y1.x>>y1.y>>x2.x>>x2.y>>y2.x>>y2.y;
		 if(inter(x1,y1,x2,y2))cout<<"Yes"<<endl;
		 else
		 cout<<"No"<<endl;
	} 
	return 0;
}
