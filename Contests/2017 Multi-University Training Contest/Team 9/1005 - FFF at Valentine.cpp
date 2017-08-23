#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,next;
}p[6123];
int n,m,vis[1024],head[1024],t,cnt,flag,u,v,mmp[1024][1024],vvis[1024];
inline void add(int u,int v){
	p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
void dfs(int s,int u){
	vis[u]=vvis[u]=mmp[s][u]=1;
	for(int i=head[u];~i;i=p[i].next)
		if(!vis[p[i].v]&&!vvis[p[i].v])
			dfs(s,p[i].v);
	vis[u]=0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		cnt=flag=0;
		memset(mmp,0,sizeof mmp);
		memset(head,-1,sizeof head);
		scanf("%d %d",&n,&m);
		while(m--){
			scanf("%d %d",&u,&v);
			add(u,v);
		}
		for(int i=1;i<=n;i++){
			memset(vvis,0,sizeof vvis);
			dfs(i,i);
		}
		for(int i=1;i<=n&&!flag;i++)
			for(int j=1;j<=n&&!flag;j++)
				if(!mmp[i][j]&&!mmp[j][i])
					flag=1;
		printf("%s\n",flag?"Light my fire!":"I love you my love and our love save us!");
	}
	return 0;
}