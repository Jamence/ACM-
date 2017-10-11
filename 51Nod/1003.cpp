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
        //pre表示小数点前面的数，las表示小数点后面的数
		//利用小数点后面的数las和Gold相乘 
        ULL a1 = las * Gold[2];						      //乘以最后一部分 
        ULL a2 = pre * Gold[2] + las * Gold[1] + a1 / MOD;//小数点后的数乘以第二部分 加上 小数点前的数 加上 进位 
        ULL a3 = pre * Gold[1] + las * Gold[0] + a2 / MOD;//与上同理 
        ULL a4 = dist + pre * Gold[0] + a3 / MOD;         //因为只要取整数部分，所以舍去小数部分 
//        cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
        cout << (a4 == b ? 'B' : 'A') << endl;
    }
}
