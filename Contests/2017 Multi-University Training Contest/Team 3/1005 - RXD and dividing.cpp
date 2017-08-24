#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
struct node{
	LL v,w,next;
}p[maxn*2];
LL n,k,u,v,w,head[maxn],cnt,vis[maxn],num[maxn],ans;
inline void add(LL u,LL v,LL w){
	p[cnt].v=v,p[cnt].w=w,p[cnt].next=head[u],head[u]=cnt++;
}
void dfs(LL u){
	vis[u]=num[u]=1;
	for(LL i=head[u];~i;i=p[i].next)
		if(!vis[p[i].v]){
			dfs(p[i].v);
			num[u]+=num[p[i].v],ans+=min(num[p[i].v],k)*p[i].w;
		}
	vis[u]=0;
}
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n>>k){
		ans=cnt=0;
		ms(num,0);
		ms(head,-1);
		for(int i=1;i<n;i++){
			cin>>u>>v>>w;
			add(u,v,w);
			add(v,u,w);
		}
		dfs(1);
		db(ans);
	}
	return 0;
}