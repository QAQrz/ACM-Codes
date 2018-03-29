#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
int main(){
	scanf("%lf/%lf %lf/%lf",&a,&b,&c,&d);
	if(a/b>c/d)
		printf("%.0lf/%.0lf > %.0lf/%.0lf",a,b,c,d);
	else if(a/b<c/d)
		printf("%.0lf/%.0lf < %.0lf/%.0lf",a,b,c,d);
	else
		printf("%.0lf/%.0lf = %.0lf/%.0lf",a,b,c,d);
	return 0;
}