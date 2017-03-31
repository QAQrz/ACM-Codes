#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,s,next;
}p[22222];
queue<int>q;
int n,m,i,j,u,v,cnt,ans,head[11111],pre[11111],dis[11111],vis[11111],s[11111],num[11111],r[11111],t;
void add(int u,int v,int s){
	p[cnt].v=v,p[cnt].s=s,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	cin>>n;
	memset(head,-1,sizeof head);
	for(i=1;i<=n;i++){
		cin>>m;
		for(j=0;j<m;j++){
			cin>>u;
			if(j){
				add(u,v,i);
				add(v,u,i);
			}
			v=u;
		}
	}
	cin>>m;
	while(m--){
		cin>>u>>v;
		if(u==v)
			cout<<0<<endl;
		else{
			memset(pre,-1,sizeof pre);
			memset(vis,0,sizeof vis);
			memset(dis,0x3f3f3f3f,sizeof dis);
			memset(s,0,sizeof s);
			memset(num,0,sizeof num);
			vis[u]=1,dis[u]=0;
			q.push(u);
			while(q.size()){
				u=q.front();
				vis[u]=0;
				q.pop();
				for(i=head[u];~i;i=p[i].next)
					if(dis[p[i].v]>dis[u]+1||(dis[p[i].v]==dis[u]+1&&num[p[i].v]>num[u]+(p[i].s==s[u]?0:1))){
						dis[p[i].v]=dis[u]+1,num[p[i].v]=num[u]+(p[i].s==s[u]?0:1),pre[p[i].v]=u,s[p[i].v]=p[i].s;
						if(!vis[p[i].v]){
							vis[p[i].v]=1;
							q.push(p[i].v);
						}
					}
			}
			if(dis[v]==0x3f3f3f3f)
				cout<<"Sorry, no line is available."<<endl;
			else{
				cout<<dis[v]<<endl;
				for(t=0,i=v;~i;i=pre[i])
					r[t++]=i;
				for(s[r[t-1]]=s[r[t-2]],u=i=t-1;~i;i--)
					if(!i||s[r[i-1]]!=s[r[i]]){
						printf("Go by the line of company #%d from %04d to %04d.\n",s[r[i]],r[u],r[i]);
						u=i;
					}
			}
		}
	}
	return 0;
}