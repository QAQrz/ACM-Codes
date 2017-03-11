#include <bits/stdc++.h>
using namespace std;
long long vis[111111],i,j,n,ans[111111];
int main(){
	vis[0]=vis[1]=1;
	for(i=2;i*i<111111;i++)
		if(!vis[i])
			for(j=i*i;j<111111;j+=i)
				vis[j]=1;
	for(i=2;i<=111111;i++)
		if(!vis[i]&&!vis[i-2])
			ans[i]=ans[i-1]+1;
		else
			ans[i]=ans[i-1];
	scanf("%lld",&n);
	printf("%lld\n",ans[n]);
	return 0;
}