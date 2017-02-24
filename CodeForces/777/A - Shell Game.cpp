#include <bits/stdc++.h>
using namespace std;
long long n,x,i,p[]={0,1,2,2,1,0};
int main(){
	cin>>n>>x;
	for(i=0;i<3;i++)
		if(p[(i*4+n)%6]==x)
			break;
	cout<<i<<endl;
	return 0;
}