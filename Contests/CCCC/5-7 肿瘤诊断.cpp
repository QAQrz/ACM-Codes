#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
};
int s[66][1333][133],i,j,k,x,m,n,l,t,ans,num,jump[][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
queue<node>q;
int check(int x,int y,int z){
	if(x<0||x>=l||y<0||y>=m||z<0||z>=n)
		return 0;
	if(s[x][y][z])
		return 1;
	return 0;
}
int main(){
	scanf("%d %d %d %d",&m,&n,&l,&t);
	for(i=0;i<l;i++)
		for(j=0;j<m;j++)
			for(k=0;k<n;k++)
				scanf("%d",&s[i][j][k]);
	for(i=0;i<l;i++)
		for(j=0;j<m;j++)
			for(k=0;k<n;k++)
				if(check(i,j,k)){
					s[i][j][k]=0,num=1;
					node p={i,j,k};
					q.push(p);
					while(q.size()){
						node p=q.front();
						q.pop();
						for(x=0;x<6;x++){
							node y={p.x+jump[x][0],p.y+jump[x][1],p.z+jump[x][2]};
							if(check(y.x,y.y,y.z)){
								num++,s[y.x][y.y][y.z]=0;
								q.push(y);
							}
						}
					}
					if(num>=t)
						ans+=num;
				}
	printf("%d\n",ans);
	return 0;
}