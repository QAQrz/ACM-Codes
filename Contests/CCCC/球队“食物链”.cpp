#include <bits/stdc++.h>
using namespace std;
char s[22][22];
int n,i,j,ans[22],vis[22],flag;
void dfs(int p,int x,int t){
	if(t==n&&x==p){
		flag=1;
		return;
	}
	ans[t]=x;
	for(int i=0;i<n&&!flag;i++)
		if((!vis[i]||t==n-1&&i==p)&&s[x][i]=='W'||s[i][x]=='L'){
			vis[i]=1;
			dfs(p,i,t+1);
			vis[i]=0;
		}
}
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",s[i]);
	for(i=0;i<n&&!flag;i++)
		for(j=0;j<n&&!flag;j++)
			if(s[i][j]=='W'||s[j][j]=='L'){
				vis[i]=vis[j]=1,ans[0]=i;
				dfs(i,j,1);
				vis[i]=vis[j]=0;
			}
	if(flag)
		for(i=0;i<n;i++)
			printf("%d%c",ans[i]+1,i<n-1?' ':'\n');
	else
		printf("No Solution\n");
	return 0;
}