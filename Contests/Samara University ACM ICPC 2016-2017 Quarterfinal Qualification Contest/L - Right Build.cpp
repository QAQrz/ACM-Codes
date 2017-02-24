#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,next;
}p[555555],pf[555555];
int vis[222222],head[222222],headf[555555],cnt,cntf,u,v,n,m,a,b,i;
long long dis[3][222222],ans=0x3f3f3f3f;
void add(int u,int v){
	p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
void addf(int u,int v){
	pf[cntf].v=v,pf[cntf].next=headf[u],headf[u]=cntf++;
}
void spfa(int k,int x){
	memset(vis,0,sizeof vis);
	queue<int>q;
	q.push(x);
	vis[x]=1,dis[k][x]=0;
	while(q.size()){
		u=q.front();
		q.pop();
		vis[u]=0;
		for(i=head[u];~i;i=p[i].next)
			if(dis[k][p[i].v]>dis[k][u]+1){
				dis[k][p[i].v]=dis[k][u]+1;
				if(!vis[p[i].v]){
					vis[p[i].v]=1;
					q.push(p[i].v);
				}
			}
	}
}
void spfaf(int k,int x){
	memset(vis,0,sizeof vis);
	queue<int>q;
	q.push(x);
	vis[x]=1,dis[k][x]=0;
	while(q.size()){
		u=q.front();
		q.pop();
		vis[u]=0;
		for(i=headf[u];~i;i=pf[i].next)
			if(dis[k][pf[i].v]>dis[k][u]+1){
				dis[k][pf[i].v]=dis[k][u]+1;
				if(!vis[pf[i].v]){
					vis[pf[i].v]=1;
					q.push(pf[i].v);
				}
			}
	}
}
int main(){
	memset(head,-1,sizeof head);
	memset(headf,-1,sizeof headf);
	memset(dis,0x3f3f3f3f,sizeof dis);
	cin>>n>>m>>a>>b;
	while(m--){
		cin>>u>>v;
		add(u,v);
		addf(v,u);
	}
	spfa(0,0);
	spfaf(1,a);
	spfaf(2,b);
	for(i=0;i<=n;i++)
		ans=min(dis[0][i]+dis[1][i]+dis[2][i],ans);
	cout<<ans<<endl;
	return 0;
}