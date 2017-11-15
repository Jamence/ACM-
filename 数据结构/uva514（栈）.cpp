#include <iostream>
#include <stack>
using namespace std;
const int maxn=1000+10;
int a[maxn];

int main()
{
    int n;
    while(cin>>n&&n){
    	while(cin>>a[1]){
    		if(a[1]==0){
    			cout<<endl;
    			break;
    		}
    		stack<int>s;
    		for(int i=2;i<=n;i++)cin>>a[i];
    		bool ok=true;
	    	int A=1,B=1;
	    	//A表示右边区域，B表示左边区域 
			while(B <= n)
	        {
	            if(A == a[B])
	            {
	                A++;
	                B++;
	            }
	            else if(!s.empty() && s.top() == a[B])
	            {
	                s.pop();
	                B++;
	            }
	            else if(A <= n)
	                s.push(A++);
	            else
	            {
	                ok = 0;
	                break;
	            }
	        }
			if(ok)cout<<"Yes"<<endl;
			else
			cout<<"No"<<endl;
    	}
    }
    return 0;
}
