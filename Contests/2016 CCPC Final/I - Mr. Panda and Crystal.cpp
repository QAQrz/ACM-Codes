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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=212,maxm=11234;
struct node{
	int next;
	vector<pair<int,int> >v;
}p[maxn];
int t,m,n,k,x,cnt,head[maxn],dis[maxn],price[maxn],u,v,w,vis[maxn],vvis[maxn],dp[maxm];
queue<int>q;
inline void add(int u,vector<pair<int,int> > v){
	p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++){
		scanf("%d %d %d",&m,&n,&k);
		cnt=0;
		ms(head,-1);
		ms(vis,0);
		ms(vvis,0);
		ms(dp,0);
		ms(dis,inf);
		vector<int>suf[maxn];
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x){
				scanf("%d %d",&dis[i],&price[i]);
				vvis[i]=1;
			}
			else
				scanf("%d",&price[i]);
		}
		while(k--){
			scanf("%d %d",&u,&x);
			vector<pair<int,int> >vec;
			while(x--){
				scanf("%d %d",&v,&w);
				vec.pb(mp(v,w));
				suf[v].pb(u);
			}
			add(u,vec);
		}
		for(int i=1;i<=n;i++)
			if(vvis[i])
				for(int j=suf[i].size()-1;~j;j--){
					q.push(suf[i][j]);
					vis[suf[i][j]]=1;
				}
		while(q.size()){
			u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];~i;i=p[i].next){
				LL sum=0;
				for(int j=p[i].v.size()-1;~j;j--)
					sum+=dis[p[i].v[j].first]*p[i].v[j].second;
				if(sum<dis[u]){
					dis[u]=sum;
					for(int j=suf[u].size()-1;~j;j--)
						if(!vis[suf[u][j]]){
							vis[suf[u][j]]=1;
							q.push(suf[u][j]);
						}
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=dis[i];j<=m;j++)
				dp[j]=max(dp[j],dp[j-dis[i]]+price[i]);
		printf("Case #%d: %d\n",ca,dp[m]);
	}
	return 0;
}