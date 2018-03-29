#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,w,next;
}p[44444];
map<string,int>maps;
int n,k,i,u,v,w,cnt,mapc,s,d,id,num[222],head[222],vis[222],dis[222],sum[222],psum[222],pre[222],t,a[222];
string str,str1,ans[222],m[222];
queue<int>q;
void add(int u,int v,int w){
	p[cnt].v=v,p[cnt].w=w,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	memset(head,-1,sizeof head);
	memset(pre,-1,sizeof pre);
	memset(dis,0x3f3f3f3f,sizeof dis);
	scanf("%d %d",&n,&k);
	cin>>str;
	s=maps[str]=++mapc,m[s]=str;
	cin>>str;
	d=maps[str]=++mapc,m[d]=str;
	for(i=1;i<n;i++){
		cin>>str;
		if(!maps[str])
			id=maps[str]=++mapc,m[id]=str;
		else
			id=maps[str];
		scanf("%d",&num[id]);
	}
	while(k--){
		cin>>str>>str1;
		scanf("%d",&w);
		u=maps[str],v=maps[str1];
		add(u,v,w);
		add(v,u,w);
	}
	q.push(s);
	a[s]=vis[s]=1,dis[s]=0,psum[s]=num[s];
	while(q.size()){
		u=q.front();
		q.pop();
		vis[u]=0;
		for(i=head[u];~i;i=p[i].next)
			if(dis[p[i].v]>dis[u]+p[i].w||(dis[p[i].v]==dis[u]+p[i].w&&sum[p[i].v]<sum[u]+1)||(dis[p[i].v]==dis[u]+p[i].w&&sum[p[i].v]==sum[u]+1&&psum[p[i].v]<psum[u]+num[p[i].v])){
				if(dis[p[i].v]>dis[u]+p[i].w)
					a[p[i].v]=a[u];
				else
					a[p[i].v]+=a[u];
				dis[p[i].v]=dis[u]+p[i].w,sum[p[i].v]=sum[u]+1,psum[p[i].v]=psum[u]+num[p[i].v],pre[p[i].v]=u;
				if(!vis[p[i].v]){
					vis[p[i].v]=1;
					q.push(p[i].v);
				}
			}
	}
	for(i=d;~i;i=pre[i])
		ans[t++]=m[i];
	for(i=t-1;~i;i--){
		cout<<ans[i];
		if(i)
			printf("->");
	}
	printf("\n%d %d %d\n",a[d],dis[d],psum[d]);
	return 0;
}