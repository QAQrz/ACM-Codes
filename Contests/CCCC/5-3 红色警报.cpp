#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v;
}p[5555];
int n,m,k,pre[555],vis[555],i,x,ans,u,v,num;
int find(int x){
	int t=x,temp;
	while(pre[x]!=x)
		x=pre[x];
	while(pre[t]!=t)
		temp=pre[t],pre[t]=x,t=temp;
	return x;
}
int merge(){
	int num=0;
	for(i=0;i<n;i++)
		pre[i]=i;
	for(i=0;i<m;i++)
		if(!vis[p[i].u]&&!vis[p[i].v]){
			u=find(p[i].u),v=find(p[i].v);
			if(u!=v)
				pre[u]=v;
		}
	for(i=0;i<n;i++)
		if(!vis[i]&&find(i)==i)
			num++;
	return num;
}
int main(){
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d %d",&p[i].u,&p[i].v);
	ans=merge();
	scanf("%d",&k);
	while(k--){
		scanf("%d",&x);
		vis[x]=1;
		num=merge();
		if(ans<num){
			ans=num;
			printf("Red Alert: City %d is lost!\n",x);
		}
		else{
			ans=num;
			printf("City %d is lost.\n",x);
		}
	}
	if(!ans)
		printf("Game Over.\n");
	return 0;
}