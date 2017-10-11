//���ڴ���һ�����⣬���󿪸����������ֻ��ƽ�������󿪸����򲻻��о������� 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
struct node
{
	ll x,y;
};
node O,a,b,c;
ll r;
//����ƽ�� 
double distance(node *p1,node *p2)
{
	return (p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y); 
}
//�ж������κ�Բ�ཻ���������
//�㶼��Բ�� 
//�㶼��Բ�� 
//һ���ཻ 

bool segOnCircle(node *p_1, node *p_2)
{
    ll a, b, c, dist_1, dist_2, angle_1, angle_2;   //  ax + by + c = 0;
    if (p_1->x == p_2->x)                           //  ��x���
    {
        a = 1, b = 0, c = -p_1->x;
    }
    else if (p_1->y == p_2->y)                      //  ��y���
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
	//��ʾ��Բ��
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
