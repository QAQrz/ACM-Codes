#include <bits/stdc++.h>
using namespace std;
int maps[12][12],n,m,u,v,i,j,vis[12];
void dfs(int x){
	vis[x]=1;
	cout<<x<<" ";
	for(int i=0;i<n;i++)
		if(maps[x][i]&&!vis[i])
			dfs(i);
}
int main(){
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		maps[u][v]=maps[v][u]=1;
	}
	for(i=0;i<n;i++)
		if(!vis[i]){
			cout<<"{ ";
			dfs(i);
			cout<<"}"<<endl;
		}
	memset(vis,0,sizeof vis);
	for(i=0;i<n;i++)
		if(!vis[i]){
			cout<<"{ ";
			queue<int>q;
			q.push(i);
			vis[i]=1;
			while(q.size()){
				u=q.front();
				cout<<u<<" ";
				q.pop();
				for(j=0;j<n;j++)
					if(maps[u][j]&&!vis[j]){
						vis[j]=1;
						q.push(j);
					}
			}
			cout<<"}"<<endl;
		}
	return 0;
}