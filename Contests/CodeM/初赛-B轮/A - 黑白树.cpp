#include <bits/stdc++.h>
using namespace std;
int n,k[112345],x,ans,m[112345];
vector<int>v[112345];
void dfs(int x){
	for(int i=v[x].size()-1;~i;i--){
		dfs(v[x][i]);
		k[x]=max(k[v[x][i]]-1,k[x]),m[x]=max(m[v[x][i]]-1,m[x]);
	}
	if(!m[x])
		ans++,m[x]=k[x];
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		v[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}