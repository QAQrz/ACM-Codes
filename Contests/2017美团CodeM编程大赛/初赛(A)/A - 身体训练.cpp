#include <bits/stdc++.h>
using namespace std;
int n,i,j;
double v,u,c[1123],d[1123],ans;
int main(){
	cin>>n>>v>>u;
	for(i=0;i<n;i++)
		cin>>c[i];
	for(i=0;i<n;i++)
		cin>>d[i];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			ans+=u/(c[i]-j*d[i]-v);
	printf("%.3f\n",ans);
	return 0;
}