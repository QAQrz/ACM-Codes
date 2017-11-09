#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pc(x) putchar(x)
#define ps(x) puts(x)
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=2123456;
struct node{
	int v,next;
	LL w;
}p[maxn];
int t,n,m,u,v,head[maxn],vis[maxn],cnt=0,num,a[maxn],x;
LL dis[maxn],dis1[maxn],ans,w;
queue<int>q;
inline void add(int u,int v,LL w){
	p[cnt].v=v,p[cnt].w=w,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		scanf("%d %d",&n,&m);
		ms(head,-1);
		ms(dis,inf);
		ms(dis1,inf);
		ms(vis,0);
		cnt=dis[1]=dis1[n]=0,vis[1]=1,ans=dis[0];
		q.push(1);
		for(int i=1;i<=m;i++){
			scanf("%lld %d",&w,&x);
			while(x--){
				scanf("%d",&v);
				add(i+n,v,w);
				add(v,i+n,w);
			}
		}
		while(q.size()){
			u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];~i;i=p[i].next)
				if(dis[p[i].v]>dis[u]+p[i].w){
					dis[p[i].v]=dis[u]+p[i].w;
					if(!vis[p[i].v]){
						vis[p[i].v]=1;
						q.push(p[i].v);
					}
				}
		}
		ms(vis,0);
		vis[n]=1;
		q.push(n);
		while(q.size()){
			u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];~i;i=p[i].next)
				if(dis1[p[i].v]>dis1[u]+p[i].w){
					dis1[p[i].v]=dis1[u]+p[i].w;
					if(!vis[p[i].v]){
						vis[p[i].v]=1;
						q.push(p[i].v);
					}
				}
		}
		for(int i=1;i<=n;i++)
			if(max(dis[i],dis1[i])<ans)
				ans=max(dis[i],dis1[i]),num=0,a[num++]=i;
			else if(max(dis[i],dis1[i])==ans)
				a[num++]=i;
		printf("Case #%d: ",k);
		if(ans<dis[0]){
			printf("%lld\n",ans/2);
			for(int i=0;i<num;i++)
				printf("%d%c",a[i],i<num-1?' ':'\n');
		}
		else
			printf("Evil John\n");
	}
	return 0;
}