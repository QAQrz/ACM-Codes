#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,timer,len,next;
}p[255555];
int flag,num[512],pre[512],cnt,n,m,i,j,u,v,a,b,timer,len,vis[512],head[512],dis[512],tim[512],roud[512],rout[512],t1,t2;
void add(int u,int v,int len,int timer){
	p[cnt].v=v,p[cnt].len=len,p[cnt].timer=timer,p[cnt].next=head[u],head[u]=cnt++;
}
void spfa(int x){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(tim,0x3f3f3f3f,sizeof tim);
	queue<int>q;
	q.push(x);
	vis[x]=1,tim[x]=0,dis[x]=0;
	while(q.size()){
		u=q.front();
		q.pop();
		vis[u]=0;
		for(i=head[u];~i;i=p[i].next)
			if(tim[p[i].v]>tim[u]+p[i].timer||(tim[p[i].v]==tim[u]+p[i].timer&&dis[p[i].v]>dis[u]+p[i].len)){
				tim[p[i].v]=tim[u]+p[i].timer,dis[p[i].v]=dis[u]+p[i].len,pre[p[i].v]=u;
				if(!vis[p[i].v]){
					vis[p[i].v]=1;
					q.push(p[i].v);
				}
			}
	}
	for(i=b;i!=a;i=pre[i])
		rout[t1++]=i;
	rout[t1++]=a,timer=tim[b];
}
void spfa1(int x){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(num,0x3f3f3f3f,sizeof num);
	queue<int>q;
	q.push(x);
	vis[x]=1,dis[x]=0,num[x]=0;
	while(q.size()){
		u=q.front();
		q.pop();
		vis[u]=0;
		for(i=head[u];~i;i=p[i].next)
			if(dis[p[i].v]>dis[u]+p[i].len||(dis[p[i].v]==dis[u]+p[i].len&&num[p[i].v]>num[u]+1)){
				num[p[i].v]=num[u]+1,dis[p[i].v]=dis[u]+p[i].len,pre[p[i].v]=u;
				if(!vis[p[i].v]){
					vis[p[i].v]=1;
					q.push(p[i].v);
				}
			}
	}
	for(i=b;i!=a;i=pre[i])
		roud[t2++]=i;
	roud[t2++]=a,len=dis[b];
}
int main(){
	memset(head,-1,sizeof head);
	scanf("%d %d",&n,&m);
	while(m--){
		scanf("%d %d %d %d %d",&u,&v,&a,&len,&timer);
		if(!(a%2))
			add(v,u,len,timer);
		add(u,v,len,timer);
	}
	scanf("%d %d",&a,&b);
	spfa(a);
	spfa1(a);
	if(t1==t2){
		for(i=0;i<t1;i++)
			if(rout[i]!=roud[i])
				break;
		if(i>=t1)
			flag=1;
	}
	if(flag){
		printf("Time = %d; Distance = %d: ",timer,len);
		for(i=t1-1;i>=0;i--)
			printf("%d%s",rout[i],i?" => ":"\n");
	}
	else{
		printf("Time = %d: ",timer);
		for(i=t1-1;i>=0;i--)
			printf("%d%s",rout[i],i?" => ":"\n");
		printf("Distance = %d: ",len);
		for(i=t2-1;i>=0;i--)
			printf("%d%s",roud[i],i?" => ":"\n");
	}
	return 0;
}