#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
struct node{
	int x,y;
};
int n,m,dis[22][22],x,y,dx[]={0,1,0,-1},dy[]={1,0,-1,0},flag;
char s[22][22];
queue<node>q;
int main(){
	while(~scanf("%d %d",&n,&m)){
		memset(dis,0x3f3f3f3f,sizeof dis);
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
			for(int j=0;j<m;j++)
				if(s[i][j]=='S'){
					node a={i,j};
					dis[i][j]=0;
					q.push(a);
				}
				else if(s[i][j]=='T')
					x=i,y=j;
		}
		while(q.size()){
			node a=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				node b=a;
				b.x+=dx[i],b.y+=dy[i];
				if(b.x>=0&&b.x<n&&b.y>=0&&b.y<m){
					if(s[b.x][b.y]=='-'||s[b.x][b.y]=='|'){
						if(s[b.x][b.y]=='-')
							flag=1;
						else
							flag=0;
						if(dis[a.x][a.y]%2)
							flag^=1;
						if(flag){
							if(!(i%2)){
								b.x+=dx[i],b.y+=dy[i];
								if(b.x>=0&&b.x<n&&b.y>=0&&b.y<m&&s[b.x][b.y]!='*'&&dis[b.x][b.y]>dis[a.x][a.y]+1){
									dis[b.x][b.y]=dis[a.x][a.y]+1;
									q.push(b);
								}
							}
							else{
								b.x+=dx[i],b.y+=dy[i];
								if(b.x>=0&&b.x<n&&b.y>=0&&b.y<m&&s[b.x][b.y]!='*'&&dis[b.x][b.y]>dis[a.x][a.y]+2){
									dis[b.x][b.y]=dis[a.x][a.y]+2;
									q.push(b);
								}
							}
						}
						else{
							if(i%2){
								b.x+=dx[i],b.y+=dy[i];
								if(b.x>=0&&b.x<n&&b.y>=0&&b.y<m&&s[b.x][b.y]!='*'&&dis[b.x][b.y]>dis[a.x][a.y]+1){
									dis[b.x][b.y]=dis[a.x][a.y]+1;
									q.push(b);
								}
							}
							else{
								b.x+=dx[i],b.y+=dy[i];
								if(b.x>=0&&b.x<n&&b.y>=0&&b.y<m&&s[b.x][b.y]!='*'&&dis[b.x][b.y]>dis[a.x][a.y]+2){
									dis[b.x][b.y]=dis[a.x][a.y]+2;
									q.push(b);
								}
							}
						}
					}
					else if(s[b.x][b.y]!='*'&&dis[b.x][b.y]>dis[a.x][a.y]+1){
						dis[b.x][b.y]=dis[a.x][a.y]+1;
						q.push(b);
					}
				}
			}
		}
		printf("%d\n",dis[x][y]);
	}
	return 0;
}