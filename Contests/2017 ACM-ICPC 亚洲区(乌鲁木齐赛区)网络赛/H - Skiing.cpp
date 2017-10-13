#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,maxn=1123456;
struct ndoe{
	int v,w,next;
}p[maxn];
int t,n,m,head[maxn],u,v,w,vis[maxn],deg[maxn],ans,cnt,dis[maxn];
queue<int>q;
inline void add(int u,int v,int w){
	p[cnt].v=v,p[cnt].w=w,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		ans=cnt=0;
		memset(head,-1,sizeof head);
		memset(vis,0,sizeof vis);
		memset(dis,0,sizeof dis);
		memset(deg,0,sizeof deg);
		while(m--){
			cin>>u>>v>>w;
			deg[v]++;
			add(u,v,w);
		}
		for(int i=1;i<=n;i++)
			if(!deg[i]){
				q.push(i);
				vis[i]=1;
			}
		while(q.size()){
			u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];~i;i=p[i].next)
				if(dis[p[i].v]<dis[u]+p[i].w){
					ans=max(ans,dis[p[i].v]=dis[u]+p[i].w);
					if(!vis[p[i].v]){
						vis[p[i].v]=1;
						q.push(p[i].v);
					}
				}
		}
		db(ans);
	}
	return 0;
}