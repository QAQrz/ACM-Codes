#include <bits/stdc++.h>
using namespace std;
const int maxn=112345,maxm=312345;
struct node{
	int u,v,next;
}p[maxm];
int n,m,i,dfn[maxn],low[maxn],vis[maxn],head[maxn],u,v,cnt,top,idx,num,s[maxn],belong[maxn],a[maxn],deg[maxn],ans,b[maxn];
void add(int u,int v){
	p[cnt].u=u,p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
void tarjan(int x){
	int i,v;
	dfn[x]=low[x]=++idx,s[top++]=x,vis[x]=1;
	for(i=head[x];~i;i=p[i].next)
		if(!dfn[p[i].v]){
			tarjan(p[i].v);
			low[x]=min(low[x],low[p[i].v]);
		}
		else if(vis[p[i].v])
			low[x]=min(low[x],dfn[p[i].v]);
	if(dfn[x]==low[x]){
		num++;
		do{
			v=s[--top],vis[v]=0,belong[v]=num,a[num]++;
		}while(x!=v);
	}
}
int dfs(int x){
	if(b[x])
		return b[x];
	int i,ans=0;
	for(i=head[x];~i;i=p[i].next)
		ans=max(ans,dfs(p[i].v));
	return b[x]=ans+a[x];
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		ans=top=idx=num=cnt=0;
		memset(head,-1,sizeof head);
		memset(dfn,0,sizeof dfn);
		memset(a,0,sizeof a);
		memset(deg,0,sizeof deg);
		memset(b,0,sizeof b);
		for(i=0;i<m;i++){
			scanf("%d %d",&u,&v);
			add(u,v);
		}
		for(i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		memset(head,-1,sizeof head);
		for(i=cnt=0;i<m;i++)
			if(belong[p[i].u]!=belong[p[i].v]){
				deg[belong[p[i].v]]++;
				add(belong[p[i].u],belong[p[i].v]);
			}
		for(i=1;i<=num;i++)
			if(!deg[i])
				ans=max(ans,dfs(i));
		printf("%d\n",ans);
	}
	return 0;
}