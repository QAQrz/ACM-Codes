#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,next,t,s;
}p[255555];
int n,m,s,d,cnt,dis[512],tim[512],u,v,l,t,head[512],vis[512],i;
void add(int u,int v,int s,int t){
	p[cnt].v=v,p[cnt].s=s,p[cnt].t=t,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	memset(head,-1,sizeof head);
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(tim,0x3f3f3f3f,sizeof tim);
	cin>>n>>m>>s>>d;
	while(m--){
		cin>>u>>v>>l>>t;
		add(u,v,l,t);
		add(v,u,l,t);
	}
	queue<int>q;
	q.push(s);
	dis[s]=tim[s]=0;
	while(q.size()){
		u=q.front();
		q.pop();
		vis[u]=0;
		for(i=head[u];~i;i=p[i].next)
			if(dis[p[i].v]>dis[u]+p[i].s||(dis[p[i].v]==dis[u]+p[i].s)&&tim[p[i].v]>tim[u]+p[i].t){
				dis[p[i].v]=dis[u]+p[i].s,tim[p[i].v]=tim[u]+p[i].t;
				if(!vis[p[i].v]){
					vis[p[i].v]=1;
					q.push(p[i].v);
				}
			}
	}
	cout<<dis[d]<<" "<<tim[d]<<endl;
	return 0;
}