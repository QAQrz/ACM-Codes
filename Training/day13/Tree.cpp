#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
struct node{
	int v,w,next;
}p[1123456];
int n,l[1123456],num[1123456],ans,k,cnt,head[1123456],u,v,w;
inline void add(int u,int v,int w){
	p[cnt].v=v,p[cnt].w=w,p[cnt].next=head[u],head[u]=cnt++;
}
void dfs(int u,int f){
	l[u]=0,num[u]=1;
	for(int i=head[u];~i;i=p[i].next)
		if(p[i].v!=f){
			int v=p[i].v;
			dfs(v,u);
			int temp=l[v]+p[i].w;
			if(temp+l[u]>ans)
				ans=temp+l[u],k=num[u]*num[v];
			else if(temp+l[u]==ans)
				k+=num[u]*num[v];
			if(temp>l[u])
				l[u]=temp,num[u]=num[v];
			else if(temp==l[u])
				num[u]+=num[v];
		}
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n){
		cnt=ans=k=0;
		ms(head,-1);
		for(int i=1;i<n;i++){
			cin>>u>>v>>w;
			add(u,v,w);
			add(v,u,w);
		}
		dfs(1,0);
		cout<<ans<<" "<<k<<endl;
	}
	return 0;
}