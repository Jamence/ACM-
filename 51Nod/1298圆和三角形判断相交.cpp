//由于存在一个问题，即求开根，但是如果只求平方，不求开根，则不会有精度问题 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
struct node
{
	ll x,y;
};
node O,a,b,c;
ll r;
//返回平方 
double distance(node *p1,node *p2)
{
	return (p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y); 
}
//判断三角形和圆相交有三种情况
//点都在圆内 
//点都在圆外 
//一定相交 

bool segOnCircle(node *p_1, node *p_2)
{
    ll a, b, c, dist_1, dist_2, angle_1, angle_2;   //  ax + by + c = 0;
    if (p_1->x == p_2->x)                           //  当x相等
    {
        a = 1, b = 0, c = -p_1->x;
    }
    else if (p_1->y == p_2->y)                      //  当y相等
    {
        a = 0, b = 1, c = -p_1->y;
    }
    else
    {
        a = p_1->y - p_2->y;
        b = p_2->x - p_1->x;
        c = p_1->x * p_2->y - p_1->y * p_2->x;
    }
    dist_1 = a * O.x + b * O.y + c;
    dist_1 *= dist_1;
    dist_2 = (a * a + b * b) * r * r;
    if (dist_1 > dist_2)
    {
        return 0;
    }
     
    angle_1 = (O.x - p_1->x) * (p_2->x - p_1->x) + (O.y - p_1->y) * (p_2->y - p_1->y);
    angle_2 = (O.x - p_2->x) * (p_1->x - p_2->x) + (O.y - p_2->y) * (p_1->y - p_2->y);
    if (angle_1 > 0 && angle_2 > 0)
    {
        return 1;
    }
    return 0;
}
bool is_inter()
{
	double dis1=distance(&a,&O),dis2=distance(&b,&O),dis3=distance(&c,&O);
	if(dis1<r*r&&dis2<r*r&&dis3<r*r)return false;
	//表示在圆内
	if(dis1>r*r&&dis2>r*r&&dis3>r*r)
		return  segOnCircle(&a,&b)||segOnCircle(&a,&c)||segOnCircle(&b,&c);
	return true;
	
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){	
		cin>>O.x>>O.y>>r;
		cin>>a.x>>a.y;
		cin>>b.x>>b.y;
		cin>>c.x>>c.y;
		if(is_inter())puts("Yes");
		else
		puts("No");
	}
	return 0;
} 
