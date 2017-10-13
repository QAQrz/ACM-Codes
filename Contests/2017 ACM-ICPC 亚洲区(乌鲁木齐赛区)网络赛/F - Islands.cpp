#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,maxn=1123456;
const int N = 11234;
stack<int> sta;
vector<int> gra[N];
int dfn[N];
int low[N];
int inStack[N];
vector<int> comp[N];
int inComp[N];
int idx, compNum;
int n;
struct node {
	int u,v;
} p[112345];
struct edge {
	int v,next;
} p1[112345];
int in[11234],head[11234],cnt,out[11234],a,b;
map<pair<int,int>,int>mmp;
void init() {
	a=b=cnt=0;
	mmp.clear();
	memset(in,0,sizeof in);
	memset(out,0,sizeof out);
	memset(head,-1,sizeof head);
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	memset(inStack, 0, sizeof inStack);
	idx = compNum = 0;
	for(int i=1; i<=n; ++i) {
		gra[i].clear();
		comp[i].clear();
	}
	while(!sta.empty()) {
		sta.pop();
	}
}
void tarjan(int u) {
	inStack[u] = 2;
	low[u] = dfn[u] = ++idx;
	sta.push(u);
	for(int i=0; i<(int)gra[u].size(); ++i) {
		int t = gra[u][i];
		if(dfn[t] == 0) {
			tarjan(t);
			low[u] = min(low[u], low[t]);
		} else if(inStack[t] == 2) {
			low[u] = min(low[u], dfn[t]);
		}
	}
	if(low[u] == dfn[u]) {
		++compNum;
		while(!sta.empty()) {
			int j = sta.top();
			sta.pop();
			inStack[j] = 1;
			comp[compNum].push_back(j);
			inComp[j] = compNum;
			if(j == u) break;
		}
	}
}
void solve() {
	for(int i=1; i<=n; ++i) {
		if(!dfn[i]) tarjan(i);
	}
}
inline void add(int u,int v) {
	p1[cnt].v=v,p1[cnt].next=head[u],head[u]=cnt++;
}
int main() {
	ios::sync_with_stdio(0);
	int t,m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		init();
		for(int i=0; i<m; i++) {
			cin>>p[i].u>>p[i].v;
			gra[p[i].u].pb(p[i].v);
		}
		solve();
		for(int i=0; i<m; i++) {
			if(inComp[p[i].u]!=inComp[p[i].v]&&!mmp.count(mp(inComp[p[i].u],inComp[p[i].v]))) {
				add(inComp[p[i].u],inComp[p[i].v]);
				mmp[mp(inComp[p[i].u],inComp[p[i].v])]=1;
			}
		}
		for(int i=1; i<=compNum; i++)
			for(int j=head[i]; ~j; j=p1[j].next)
				out[i]++,in[p1[j].v]++;
		for(int i=1; i<=compNum; i++) {
			if(!in[i])
				a++;
			if(!out[i])
				b++;
		}
		b=max(a,b);
		db(compNum>1?b:0);
	}
	return 0;
}