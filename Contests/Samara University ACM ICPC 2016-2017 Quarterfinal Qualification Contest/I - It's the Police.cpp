#include <bits/stdc++.h>
using namespace std;
struct node{
	int deg,num;
	vector<int>v;
}p[222222];
int n,m,i,u,v,vis[222222];
int cmp(node a,node b){
	return a.deg<b.deg;
}
int main(){
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		p[u].deg++,p[v].deg++;
		p[u].v.push_back(v);
		p[v].v.push_back(u);
	}
	for(i=1;i<=n;i++)
		p[i].num=i;
	sort(p+1,p+n+1,cmp);
	vis[p[1].num]=1;
	for(i=0;i<p[1].v.size();i++)
		vis[p[1].v[i]]=1;
	for(i=1;i<=n;i++)
		printf("%d%c",vis[i]^1,i<n?' ':'\n');
	return 0;
}