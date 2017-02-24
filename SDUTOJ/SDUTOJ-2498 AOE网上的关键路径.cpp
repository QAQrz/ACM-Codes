#include <bits/stdc++.h>
using namespace std;
struct edge{//存储边的结构体-前向星
	int v,w,pre;
}p[55555];
int n,m,next[10086],head[10086],cnt,vis[10086],dis[10086],i,u,v,w;
int main(){
	while(~scanf("%d %d",&n,&m)){
		memset(head,-1,sizeof(head));
		memset(next,0,sizeof(next));//节点i的后继为next[i]
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));//节点i到起点n的最长路径长度为dis[i]
		cnt=0,vis[n]=1;
		for(i=0;i<m;i++){
			scanf("%d %d %d",&v,&u,&w);
			p[cnt].v=v,p[cnt].w=w,p[cnt].pre=head[u],head[u]=cnt++;//逆序添加有向边
		}
		queue<int>q;
		q.push(n);
		while(!q.empty()){//SPFA算法求最长路径
			u=q.front();
			q.pop();
			vis[u]=0;
			for(i=head[u];~i;i=p[i].pre)//检查并更新节点u的所有前驱节点
				if(dis[p[i].v]<dis[u]+p[i].w||(dis[p[i].v]==dis[u]+p[i].w&&next[p[i].v]>u)){
					dis[p[i].v]=dis[u]+p[i].w,next[p[i].v]=u;//设置节点v的后继为节点u
					if(!vis[p[i].v]){
						q.push(p[i].v);
						vis[p[i].v]=1;
					}
				}
		}
		printf("%d\n",dis[1]);//输出最长路径的长度
		for(i=1;next[i];i=next[i])//输出1-n的最长路径
			printf("%d %d\n",i,next[i]);
	}
	return 0;
}