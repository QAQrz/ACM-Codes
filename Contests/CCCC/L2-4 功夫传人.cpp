#include <bits/stdc++.h>
using namespace std;
long long n,m,x,i,vis[111111],deg[111111],pre[111111];
double ans,r,z;
long long dfs(long long x){
	if(!x)
		return 0LL;
	if(deg[x])
		return  deg[x];
	return deg[x]=dfs(pre[x])+1;
}
int main(){
	cin>>n>>z>>r;
	for(i=0;i<n;i++){
		cin>>m;
		if(!m)
			cin>>vis[i];
		else
			while(m--){
				cin>>x;
				pre[x]=i;
			}
	}
	for(i=0;i<n;i++)
		if(vis[i])
			x=dfs(i),ans+=pow((100-r)/100,x)*z*vis[i];
	printf("%d\n",(long long)ans);
	return 0;
}