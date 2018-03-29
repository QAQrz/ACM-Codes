#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j;
double ans[11111],s[12],sum;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			scanf("%lf",&s[j]);
		sort(s,s+m);
		for(j=1,sum=0;j<m-1;j++)
			sum+=s[j];
		ans[i]=sum/(m-2);
	}
	sort(ans,ans+n);
	for(i=n-k;i<n;i++)
		printf("%.3f%c",ans[i],i<n-1?' ':'\n');
	return 0;
}