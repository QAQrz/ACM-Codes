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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=8123;
map<pair<int, int>, int> mp;
struct node{
	int v,w,next;
}p[maxn];
struct edge{
	int u,v,w;
}pp[maxn];
int cnt,head[maxn],vis[maxn],tot,num,ans,dis[maxn];
queue<int>q;
int GetIdx(int x, int y) {
	pair<int, int> p = make_pair(x, y);
	if(!mp[p]) mp[p] = ++cnt;
	return mp[p];
}
inline void add(int u,int v,int w){
	p[tot].v=v,p[tot].w=w,p[tot].next=head[u],head[u]=tot++;
}
inline int spfa(int s,int t){
	ms(dis,inf);
	ms(vis,0);
	q.push(s);
	vis[s]=1,dis[s]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=p[i].next)
			if(dis[p[i].v]>dis[u]+p[i].w){
				dis[p[i].v]=dis[u]+p[i].w;
				if(!vis[p[i].v]){
					vis[p[i].v]=1;
					q.push(p[i].v);
				}
			}
	}
	return dis[t];
}
int main(){
	int t, m, x1, y1, x2, y2, w;
	scanf("%d", &t);
	for(int cs=1; cs<=t; ++cs) {
		mp.clear();
		num=tot=cnt=0,ans=inf;
		ms(head,-1);
		scanf("%d", &m);
		for(int i=0; i<m; ++i) {
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &w);
			int p1 = GetIdx(x1, y1);
			int p2 = GetIdx(x2, y2);
			add(p1,p2,w);
			add(p2,p1,w);
			pp[num].u=p1,pp[num].v=p2,pp[num++].w=w;
		}
		for(int i=0,j;i<num;i++){
			for(j=head[pp[i].u];~j;j=p[j].next)
				if(p[j].v==pp[i].v){
					p[j].w=p[j+1].w=inf;
					break;
				}
			ans=min(spfa(pp[i].u,pp[i].v)+pp[i].w,ans),p[j].w=p[j+1].w=pp[i].w;
		}
		printf("Case #%d: %d\n",cs,ans<inf?ans:0);
	}
	return 0;
}