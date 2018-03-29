#include <bits/stdc++.h>
using namespace std;
double a,b,c;
int n;
int main(){
	cin>>n;
	while(n--){
		scanf("%lf %lf",&a,&b);
		c=(a-100)*0.9,b/=2;
		if(abs(b-c)-c*0.1+1e-7<0)
			cout<<"You are wan mei!"<<endl;
		else if(b<c)
			cout<<"You are tai shou le!"<<endl;
		else
			cout<<"You are tai pang le!"<<endl;
	}
	return 0;
}