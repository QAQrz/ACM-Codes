#include <bits/stdc++.h>
using namespace std;
int n,m,i,deg[1024],u,v,pre[1024];
int find(int x){
	int t=x,temp;
	while(pre[x]!=x)
		x=pre[x];
	while(pre[t]!=t)
		temp=pre[t],pre[t]=x,t=temp;
	return x;
}
int main(){
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		pre[i]=i;
	while(m--){
		scanf("%d %d",&u,&v);
		deg[u]++,deg[v]++,u=find(u),v=find(v);
		if(u!=v)
			pre[u]=v;
	}
	u=find(1);
	for(i=1;i<=n;i++){
		find(i);
		if(!deg[i]||deg[i]%2)
			break;
		if(i>1&&find(i)!=pre[i-1])
			break;
	}
	printf("%d\n",i<=n?0:1);
	return 0;
}