#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL maxn=1123456;
struct node{
	LL v,next;
}p[maxn*2];
LL n,a[maxn],u,v,w,head[maxn],dp[maxn][2],cnt,vis[maxn],ans,s,t,flag,temp;
inline void add(LL u,LL v){
	p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
void treedp(LL u,LL x){
	dp[u][0]=0,dp[u][1]=a[u],vis[u]=x;
	for(LL i=head[u];~i;i=p[i].next)
		if(vis[p[i].v]!=x){
			treedp(p[i].v,x);
			dp[u][0]+=max(dp[p[i].v][0],dp[p[i].v][1]),dp[u][1]+=dp[p[i].v][0];
		}
}
void dfs(LL u,LL f){
	vis[u]=1;
	for(LL i=head[u];~i;i=p[i].next)
		if(p[i].v!=f){
			if(vis[p[i].v])
				s=u,t=p[i].v,flag=1;
			else
				dfs(p[i].v,u);
		}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	ms(head,-1);
	for(LL i=1;i<=n;i++){
		cin>>a[i]>>v;
		add(i,v);
		add(v,i);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			flag=0;
			dfs(i,0);
			if(flag){
				treedp(s,-1);
				temp=dp[s][0];
				treedp(t,1);
				ans+=max(temp,dp[t][0]);
			}
			else{
				treedp(i,-1);
				ans+=max(dp[i][0],dp[i][1]);
			}
		}
	db(ans);
	return 0;
}