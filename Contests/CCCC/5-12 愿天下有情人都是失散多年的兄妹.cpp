#include <bits/stdc++.h>
using namespace std;
struct node{
	int id,fid,mid;
	char x[5];
}p[111111],a;
int n,i,vis[111111],l,r;
void dfs(int x,int h){
	vis[x]=1;
	if(h>4)
		return;
	if(~p[x].fid)
		dfs(p[x].fid,h+1);
	if(~p[x].mid)
		dfs(p[x].mid,h+1);
}
int dfs1(int x,int h){
	if(vis[x])
		return 0;
	if(h>4)
		return 1;
	int ans=1;
	if(~p[x].fid)
		ans&=dfs1(p[x].fid,h+1);
	if(~p[x].mid)
		ans&=dfs1(p[x].mid,h+1);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(i=0;i<111111;i++)
		p[i].fid=p[i].mid=-1;
	while(n--){
		scanf("%d %s %d %d",&a.id,a.x,&a.fid,&a.mid);
		p[a.id]=a;
		strcpy(p[a.fid].x,"M");
		strcpy(p[a.mid].x,"F");
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&l,&r);
		if(p[l].x[0]==p[r].x[0])
			printf("Never Mind\n");
		else{
			memset(vis,0,sizeof vis);
			dfs(l,1);
			printf("%s\n",dfs1(r,1)?"Yes":"No");
		}
	}
	return 0;
}