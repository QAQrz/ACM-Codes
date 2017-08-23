#include <bits/stdc++.h>
using namespace std;
int cases,n,ans[112345];
double a=1;
int main(){
	for(int i=1;i<=100000;i++){
		a*=2;
		if(a>=10)
			a/=10,ans[i]=ans[i-1]+1;
		else
			ans[i]=ans[i-1];
	}
	while(~scanf("%d",&n))
		printf("Case #%d: %d\n",++cases,ans[n]);
	return 0;
}