#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const ULL Gold[3] = {618033988, 749894848, 204586834};
const ULL MOD = 1000000000;

int main()
{
    int t;
    cin >> t;
    ULL a, b;
    while (t--)
    {
        cin >> a >> b;
        if (a < b)
        {
            swap(a, b);
        }
        ULL dist = a - b;
        ULL pre = dist / MOD, las = dist % MOD;
        //pre��ʾС����ǰ�������las��ʾС����������
		//����С����������las��Gold��� 
        ULL a1 = las * Gold[2];						      //�������һ���� 
        ULL a2 = pre * Gold[2] + las * Gold[1] + a1 / MOD;//С�����������Եڶ����� ���� С����ǰ���� ���� ��λ 
        ULL a3 = pre * Gold[1] + las * Gold[0] + a2 / MOD;//����ͬ�� 
        ULL a4 = dist + pre * Gold[0] + a3 / MOD;         //��ΪֻҪȡ�������֣�������ȥС������ 
//        cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
        cout << (a4 == b ? 'B' : 'A') << endl;
    }
}
