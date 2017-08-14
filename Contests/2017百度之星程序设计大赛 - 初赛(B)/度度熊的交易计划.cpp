#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const int MAXN=512,MAXM=11234,INF=0x3f3f3f3f;
struct Edge{
	int to,next,cap,flow,cost;
}edge[MAXM];
int head[MAXN],tol,pre[MAXN],dis[MAXN],N;
bool vis[MAXN];
void init(int n){
	N=n,tol=0;
	ms(head,-1);
}
void addedge(int u,int v,int cap,int cost){
	edge[tol].to=v,edge[tol].cap=cap,edge[tol].cost=cost,edge[tol].flow=0,edge[tol].next=head[u],head[u]=tol++,edge[tol].to=u,edge[tol].cap=0,edge[tol].cost=-cost,edge[tol].flow=0,edge[tol].next=head[v],head[v]=tol++;
}
bool spfa(int s,int t){
	queue<int>q;
	for(int i=0;i<N;i++)
		dis[i]=INF,vis[i]=false,pre[i]=-1;
	dis[s]=0,vis[s]=true;
	q.push(s);
	while(q.size()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];~i;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost){
				dis[v]=dis[u]+edge[i].cost,pre[v]=i;
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	if(!~pre[t])
		return false;
	else
		return true;
}
int minCostMaxflow(int s,int t,int &cost){
	int flow=0;
	cost=0;
	while(spfa(s,t)){
		if(dis[t]>=0)
			break;
		int Min=INF;
		for(int i=pre[t];~i;i=pre[edge[i^1].to])
			if(Min>edge[i].cap-edge[i].flow)
				Min=edge[i].cap-edge[i].flow;
		for(int i=pre[t];~i;i=pre[edge[i^1].to])
			edge[i].flow+=Min,edge[i^1].flow-=Min,cost+=edge[i].cost*Min;
		flow+=Min;
	}
	return flow;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m,a1,b1,c1,d1,u,v,w,cost;
	while(cin>>n>>m){
		init(n+2);
		for(int i=1;i<=n;i++){
			cin>>a1>>b1>>c1>>d1;
			addedge(0,i,b1,a1);
			addedge(i,n+1,d1,-c1);
		}
		while(m--){
			cin>>u>>v>>w;
			addedge(u,v,0x3f3f3f3f,w);
			addedge(v,u,0x3f3f3f3f,w);
		}
		minCostMaxflow(0,n+1,cost);
		db(max(0,-cost));
	}
	return 0;
}