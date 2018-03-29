#include <bits/stdc++.h>
using namespace std;
int n,m,s,d,i,num[512],dis[512],maps[512][512],u,v,w,vis[512],a[512],sum[512],pre[512],ans[512],t;
queue<int>q;
int main(){
	scanf("%d %d %d %d",&n,&m,&s,&d);
	memset(pre,-1,sizeof pre);
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(maps,0x3f3f3f3f,sizeof maps);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	while(m--){
		scanf("%d %d %d",&u,&v,&w);
		maps[u][v]=maps[v][u]=min(maps[u][v],w);
	}
	q.push(s);
	dis[s]=0,a[s]=vis[s]=1,sum[s]=num[s];
	while(q.size()){
		u=q.front();
		vis[u]=0;
		q.pop();
		for(i=0;i<n;i++)
			if(i!=u&&maps[u][i]<0x3f3f3f3f&&(dis[i]>dis[u]+maps[u][i]||(dis[i]==dis[u]+maps[u][i]&&sum[i]<sum[u]+num[i]))){
				if(dis[i]>dis[u]+maps[u][i])
					a[i]=a[u];
				else
					a[i]+=a[u];
				dis[i]=dis[u]+maps[u][i],sum[i]=sum[u]+num[i],pre[i]=u;
				if(!vis[i]){
					vis[i]=1;
					q.push(i);
				}
			}
	}
	printf("%d %d\n",a[d],sum[d]);
	for(i=d;~i;i=pre[i])
		ans[t++]=i;
	for(i=t-1;~i;i--)
		printf("%d%c",ans[i],i?' ':'\n');
	return 0;
}