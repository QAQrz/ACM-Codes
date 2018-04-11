#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,next;
}p[212345];
int vis[11234],k,x,dis[11234],n,m,u,v,head[11234],ans,flag,cnt;
queue<int>q;
inline void add(int u,int v){
	p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	cin>>n>>m;
	memset(head,-1,sizeof head);
	while(m--){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	cin>>k;
	while(k--){
		cin>>x;
		memset(vis,0,sizeof vis);
		memset(dis,0x3f3f3f3f,sizeof dis);
		flag=vis[x]=1,ans=dis[x]=0;
		q.push(x);
		while(q.size()){
			u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];~i;i=p[i].next)
				if(dis[p[i].v]>dis[u]+1){
					dis[p[i].v]=dis[u]+1;
					if(!vis[p[i].v]){
						vis[p[i].v]=1;
						q.push(p[i].v);
					}
				}
		}
		for(int i=1;i<=n;i++){
			ans+=dis[i];
			if(dis[i]<0x3f3f3f3f)
				flag=0;
		}
		if(flag)
			printf("Cc(%d)=0.00\n",x);
		else
			printf("Cc(%d)=%.2f\n",x,(double)(n-1)/ans);
	}
	return 0;
}