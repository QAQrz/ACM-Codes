#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const LL inf=0x3f3f3f3f;
struct node{
	LL v,w,next;
}p[212345];
LL t,n,m,u,v,w,vis[112345],head[112345],pre[112345],dis[112345],cnt,dis1[112345],ans,flag,vv[112345];
queue<LL>q;
inline void add(LL u,LL v,LL w){
	p[cnt].v=v,p[cnt].w=w,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	scanf("%lld",&t);
	while(t--){
		flag=cnt=0,ans=1e18;
		memset(dis,inf,sizeof dis);
		memset(dis1,inf,sizeof dis1);
		memset(vis,0,sizeof vis);
		memset(head,-1,sizeof head);
		scanf("%lld %lld",&n,&m);
		while(m--){
			scanf("%lld %lld %lld",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		q.push(1);
		dis[1]=dis1[n]=0,vis[1]=1;
		while(q.size()){
			u=q.front();
			q.pop();
			vis[u]=0;
			for(LL i=head[u];~i;i=p[i].next)
				if(dis[p[i].v]>dis[u]+p[i].w){
					dis[p[i].v]=dis[u]+p[i].w,pre[p[i].v]=u,vv[p[i].v]=p[i].w;
					if(!vis[p[i].v]){
						vis[p[i].v]=1;
						q.push(p[i].v);
					}
				}
		}
		memset(vis,0,sizeof vis);
		vis[n]=1;
		q.push(n);
		while(q.size()){
			u=q.front();
			q.pop();
			vis[u]=0;
			for(LL i=head[u];~i;i=p[i].next)
				if(dis1[p[i].v]>dis1[u]+p[i].w){
					dis1[p[i].v]=dis1[u]+p[i].w;
					if(!vis[p[i].v]){
						vis[p[i].v]=1;
						q.push(p[i].v);
					}
				}
		}
		memset(vis,0,sizeof vis);
		for(int i=n;i;i=pre[i])
			vis[i]=1;
		for(int i=1;i<=n&&!flag;i++)
			if(dis[i]+dis1[i]==dis[n]){
				if(!vis[i])
					ans=dis[n],flag=1;
			}
			else
				ans=min(ans,dis[i]+dis1[i]);
		if(!flag)
			for(int i=n;i>1;i=pre[i])
				ans=min(ans,dis[n]+vv[i]*2);
		printf("%lld\n",ans);
	}
	return 0;
}