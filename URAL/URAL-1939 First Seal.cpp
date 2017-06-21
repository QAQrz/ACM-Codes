#include <bits/stdc++.h>
using namespace std;
double h,l,H,v,x,a,eps=1e-5,s,s1;
int main(){
	cin>>l>>h>>H>>v>>x>>a;
	s=v*v/a/2+l,s1=(H-h)/x*v;
	cout<<((s>s1||fabs(s-s1)<eps)?"Crash":"Safe")<<endl;
	return 0;
}