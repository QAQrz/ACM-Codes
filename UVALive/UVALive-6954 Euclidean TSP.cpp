#include <bits/stdc++.h>
using namespace std;
double n,p,s,v,l,r,ml,mr;
const double eps=1e-7;
double cal(double x){
	return n*pow(log2(n),x*sqrt(2))/p/1e9+s*(1+1/x)/v;
}
int main(){
	while(cin>>n>>p>>s>>v){
		l=0,r=100;
		while(r-l>eps){
			ml=(l+r)/2,mr=(ml+r)/2;
			if(cal(ml)<cal(mr))
				r=mr;
			else
				l=ml;
		}
		printf("%lf %lf\n",cal(l),l);
	}
	return 0;
}