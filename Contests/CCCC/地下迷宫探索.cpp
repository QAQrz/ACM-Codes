#include <bits/stdc++.h>
using namespace std;
vector<int>vec[1024];
int n,m,s,i,vis[1024],num,u,v;
void dfs(int x){
	vis[x]=1;
	if(num>0)
		printf(" ");
	printf("%d",x);
	if(++num>=n)
		return;
	int l=vec[x].size();
	for(int i=0;i<l;i++)
		if(!vis[vec[x][i]]){
			dfs(vec[x][i]);
			printf(" %d",x);
		}
}
int main(){
	scanf("%d %d %d",&n,&m,&s);
	while(m--){
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(i=1;i<=n;i++)
		sort(vec[i].begin(),vec[i].begin()+vec[i].size());
	dfs(s);
	if(num<n)
		printf(" 0");
	printf("\n");
	return 0;
}