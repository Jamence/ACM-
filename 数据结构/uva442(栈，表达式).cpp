#include <bits/stdc++.h>
using namespace std;
struct matrix
{
	int a,b;
	matrix(int a=0,int b=0){
		this->a=a;
		this->b=b;
	}
}m[30];
stack<matrix>s;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string name;
		cin>>name;
		int k=name[0]-'A';
		cin>>m[k].a>>m[k].b;
	}
	string expr;
	while(cin>>expr){
		int len=expr.length();
		bool error=false;
		int ans=0;
		for(int i=0;i<len;i++){
			if(isalpha(expr[i]))s.push(m[expr[i]-'A']);
			else
			if(expr[i]==')'){
				matrix m1=s.top();s.pop();//¾ØÕóÏà³ËµÄÓÒ±ß 
				matrix m2=s.top();s.pop();
				if(m1.a!=m2.b){
					error=true;
					break;
				}
				ans+=m2.a*m1.b*m1.a;
				s.push(matrix(m2.a,m1.b));
			}
		}
		if(error){
			cout<<"error"<<endl;
		}
		else
		cout<<ans<<endl;
	}
	return 0;
} 
