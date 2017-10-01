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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=212345;
struct node{
	int v,next;
}p[maxn];
LL n,ans,vis[maxn],u,v,head[maxn],cnt,a[3];
inline void add(int u,int v){
	p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
void dfs(int u,int c){
	vis[u]=1,a[c]++,ans+=a[c^1]-1;
	for(int i=head[u];~i;i=p[i].next)
		if(!vis[p[i].v])
			dfs(p[i].v,c^1);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	ms(head,-1);
	for(int i=1;i<n;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	db(ans+1);
	return 0;
}