#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}p[3333];
int pre[1024],n,m,i,ans,num,u,v;
int cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	int t=x,temp;
	while(pre[x]!=x)
		x=pre[x];
	while(pre[t]!=t)
		temp=pre[t],pre[t]=x,t=temp;
	return x;
}
int main(){
	cin>>n>>m;
	for(i=0;i<m;i++)
		cin>>p[i].u>>p[i].v>>p[i].w;
	sort(p,p+m,cmp);
	for(i=1;i<=n;i++)
		pre[i]=i;
	for(i=0;i<m;i++){
		u=find(p[i].u),v=find(p[i].v);
		if(u!=v)
			pre[v]=u,ans+=p[i].w,num++;
		if(num>n-2)
			break;
	}
	cout<<(i<m?ans:-1)<<endl;
	return 0;
}