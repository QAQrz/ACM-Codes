#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,id;
}p[11111];
int n,m,i,u,v,w,maps[128][128],va[128],vb[128],in[128],out[128],mt,vis[128];
vector<int>v1,v2;
int cmp(node a,node b){
	if(a.u==b.u)
		return a.id>b.id;
	return a.u<b.u;
}
int main(){
	cin>>n>>m;
	memset(maps,-1,sizeof maps);
	memset(vb,0x3f3f3f3f,sizeof vb);
	for(i=0;i<m;i++){
		cin>>u>>v>>w;
		maps[u][v]=w,in[v]++,out[u]++,p[i].u=u,p[i].v=v,p[i].id=i;
	}
	for(i=1;i<=n;i++){
		if(!in[i])
			v1.push_back(i);
		if(!out[i])
			v2.push_back(i);
	}
	for(auto u:v1){
		queue<int>q;
		q.push(u);
		vis[u]=1;
		while(q.size()){
			v=q.front();
			q.pop();
			for(i=1;i<=n;i++)
				if(maps[v][i]>=0&&!vis[i]){
					in[i]--,va[i]=max(va[i],va[v]+maps[v][i]),mt=max(mt,va[i]);
					if(!in[i]){
						vis[i]=1;
						q.push(i);
					}
				}
		}
	}
	for(i=1;i<=n;i++)
		if(!vis[i]){
			cout<<0<<endl;
			return 0;
		}
	for(auto u:v2){
		queue<int>q;
		q.push(u);
		vb[u]=mt;
		while(q.size()){
			v=q.front();
			q.pop();
			for(i=1;i<=n;i++)
				if(maps[i][v]>=0){
					out[i]--,vb[i]=min(vb[i],vb[v]-maps[i][v]);
					if(!out[i])
						q.push(i);
				}
		}
	}
	cout<<mt<<endl;
	sort(p,p+m,cmp);
	for(i=0;i<m;i++)
		if(va[p[i].u]+maps[p[i].u][p[i].v]==vb[p[i].v])
			cout<<p[i].u<<"->"<<p[i].v<<endl;
	return 0;
}