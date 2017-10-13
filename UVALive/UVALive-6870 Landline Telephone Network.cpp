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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123,maxm=112345;
struct node{
	int u,v,w;
}p[maxm];
int n,m,x,a,vis[maxn],pre[maxn],ans,u,v,flag,vvis[maxn];
inline bool cmp(node a,node b){
	return a.w<b.w;
}
inline int find(int x){
	int t=x,temp;
	while(pre[x]!=x)
		x=pre[x];
	while(pre[t]!=t)
		temp=pre[t],pre[t]=x,t=temp;
	return x;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m>>x){
		ms(vis,0);
		ms(vvis,0);
		ans=0,flag=1;
		for(int i=1;i<=n;i++)
			pre[i]=i;
		while(x--){
			cin>>a;
			vis[a]=1;
		}
		for(int i=0;i<m;i++)
			cin>>p[i].u>>p[i].v>>p[i].w;
		if(n<2){
			db(ans);
			continue;
		}
		else if(n<3&&vis[1]&&vis[2]){
			if(m)
				db(p[0].w);
			else
				db("impossible");
			continue;
		}
		sort(p,p+m,cmp);
		for(int i=0;i<m;i++){
			if(vis[p[i].u]&&vis[p[i].v])
				continue;
			else if(vis[p[i].u]){
				if(!vvis[p[i].u])
					vvis[p[i].u]=1;
				else
					continue;
			}
			else if(vis[p[i].v]){
				if(!vvis[p[i].v])
					vvis[p[i].v]=1;
				else
					continue;
			}
			u=find(p[i].u),v=find(p[i].v);
			if(u!=v)
				pre[max(u,v)]=min(u,v),ans+=p[i].w;
		}
		for(int i=1;i<=n;i++)
			if(find(i)>1)
				flag=0;
		if(flag)
			db(ans);
		else
			db("impossible");
	}
	return 0;
}