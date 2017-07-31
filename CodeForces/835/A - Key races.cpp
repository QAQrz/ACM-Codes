#include <bits/stdc++.h>
using namespace std;
int s,v1,v2,t1,t2,a1,a2;
int main(){
	cin>>s>>v1>>v2>>t1>>t2;
	a1=s*v1+2*t1,a2=s*v2+2*t2;
	if(a1<a2)
		cout<<"First"<<endl;
	else if(a1>a2)
		cout<<"Second"<<endl;
	else
		cout<<"Friendship"<<endl;
	return 0;
}