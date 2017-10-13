#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=312345;
struct node{
	int v,next;
}p[maxn];
int n,m,x,l,head[maxn],vis[maxn],deg[maxn],num[maxn],cnt,u,v;
queue<int>q;
inline void add(int u,int v){
	p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>x>>l;
	ms(head,-1);
	while(m--){
		cin>>u>>v;
		add(u,v);
		add(v,u);
		deg[u]++,deg[v]++;
	}
	vis[l]=1;
	q.push(l);
	while(q.size()){
		u=q.front();
		q.pop();
		for(int i=head[u];~i;i=p[i].next)
			if(!vis[p[i].v]){
				num[p[i].v]++;
				if(num[p[i].v]*2>=deg[p[i].v]){
					vis[p[i].v]=1;
					q.push(p[i].v);
				}
			}
	}
	db(vis[x]?"leave":"stay");
	return 0;
}