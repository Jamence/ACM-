#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	int n=m%10;
	if(n==0)cout<<0<<endl;
	if(n==1)cout<<1<<endl;
	if(n==2){
		int temp=m%4;
		if(temp==0)cout<<6<<endl;
		if(temp==1)cout<<2<<endl;
		if(temp==2)cout<<4<<endl;
		if(temp==3)cout<<8<<endl;
	}
	if(n==3){
		int temp=m%4;
		if(temp==0)cout<<1<<endl;
		if(temp==1)cout<<3<<endl;
		if(temp==2)cout<<9<<endl;
		if(temp==3)cout<<7<<endl;
	}
	if(n==4){
		int temp=m%2;
		if(temp==0)cout<<6<<endl;
		if(temp==1)cout<<4<<endl;
	}
	if(n==5)cout<<5<<endl;
	if(n==6)cout<<6<<endl;
	if(n==7){
		int temp=m%4;
		if(temp==0)cout<<1<<endl;
		if(temp==1)cout<<7<<endl;
		if(temp==2)cout<<9<<endl;
		if(temp==3)cout<<3<<endl;	
	}
	if(n==8){
		int temp=m%4;
		if(temp==0)cout<<6<<endl;
		if(temp==1)cout<<8<<endl;
		if(temp==2)cout<<4<<endl;
		if(temp==3)cout<<2<<endl;
//		if(temp==4)cout<<6<<endl;
	}
	if(n==9)cout<<9<<endl;
	//cout<<ans<<endl;
	return 0;
} 
