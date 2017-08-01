#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	LL x,y;
};
LL s[333][333],ans,n,m,vis[333][333],dx[]={0,1,0,-1},dy[]={1,0,-1,0};
priority_queue<node>q;
bool operator < (node a,node b){
	return s[a.x][a.y]>s[b.x][b.y];
}
int main(){
	while(~scanf("%lld %lld",&m,&n)){
		ans=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf("%lld",&s[i][j]);
				if(i==1||i==n||j==1||j==m){
					node x=node{i,j};
					vis[i][j]=1;
					q.push(x);
				}
			}
		while(q.size()){
			node u=q.top();
			q.pop();
			for(int i=0;i<4;i++){
				node v=u;
				v.x+=dx[i],v.y+=dy[i];
				if(v.x&&v.x<=n&&v.y&&v.y<=m&&!vis[v.x][v.y]){
					vis[v.x][v.y]=1;
					if(s[v.x][v.y]<s[u.x][u.y])
						ans+=s[u.x][u.y]-s[v.x][v.y],s[v.x][v.y]=s[u.x][u.y];
					q.push(v);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}