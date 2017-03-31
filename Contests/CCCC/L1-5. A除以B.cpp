#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	cin>>a>>b;
	if(!b)
		printf("%d/%d=Error\n",a,b);
	else if(b<0)
		printf("%d/(%d)=%.2lf\n",a,b,1.0*a/b);
	else
		printf("%d/%d=%.2lf\n",a,b,1.0*a/b);
	return 0;
}