#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	int x,y,p,s;
};
int n,m,p,k,wall[16][16][16][16],s,key[16][16],x,y,x2,y2,a,vis[16][16][1<<10],ans,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
queue<node>q;
int main(){
	while(~scanf("%d %d %d %d",&n,&m,&p,&k)){
		ans=-1;
		while(q.size())
			q.pop();
		memset(wall,-1,sizeof wall);
		memset(key,0,sizeof key);
		memset(vis,0,sizeof vis);
		while(k--){
			scanf("%d %d %d %d %d",&x,&y,&x2,&y2,&a);
			wall[x][y][x2][y2]=wall[x2][y2][x][y]=a;
		}
		scanf("%d",&s);
		while(s--){
			scanf("%d %d %d",&x,&y,&a);
			key[x][y]|=(1<<(a-1));
		}
		node p={1,1,0,0};
		q.push(p);
		while(q.size()){
			node p=q.front();
			q.pop();
			if(p.x==n&&p.y==m){
				ans=p.s;
				break;
			}
			for(int i=0;i<4;i++){
				node v=p;
				v.x+=dx[i],v.y+=dy[i],v.s++;
				if(v.x&&v.x<=n&&v.y&&v.y<=m&&(wall[p.x][p.y][v.x][v.y]<0||(wall[p.x][p.y][v.x][v.y]>0&&(v.p>>(wall[p.x][p.y][v.x][v.y]-1))%2))){
					v.p|=key[v.x][v.y];
					if(!vis[v.x][v.y][v.p]){
						vis[v.x][v.y][v.p]=1;
						q.push(v);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}