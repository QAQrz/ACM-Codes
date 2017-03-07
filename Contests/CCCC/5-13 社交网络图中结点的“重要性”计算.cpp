#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,next;
}p[111111];
int n,m,x,cnt,dis[11111],u,v,head[11111],vis[11111],i;
double ans;
void add(int u,int v){
	p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	memset(head,-1,sizeof head);
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	cin>>m;
	while(m--){
		cin>>x;
		memset(dis,0x3f3f3f3f,sizeof dis);
		queue<int>q;
		q.push(x);
		ans=dis[x]=0,vis[x]=1;
		while(q.size()){
			u=q.front();
			q.pop();
			vis[u]=0;
			for(i=head[u];~i;i=p[i].next)
				if(dis[p[i].v]>dis[u]+1){
					dis[p[i].v]=dis[u]+1;
					if(!vis[p[i].v]){
						vis[p[i].v]=1;
						q.push(p[i].v);
					}
				}
		}
		for(i=1;i<=n;i++)
			if(dis[i]<0x3f3f3f3f)
				ans+=dis[i];
			else{
				ans=0;
				break;
			}
		if(ans)
			ans=1.0*(n-1)/ans;
		printf("Cc(%d)=%.2lf\n",x,ans);
	}
	return 0;
}