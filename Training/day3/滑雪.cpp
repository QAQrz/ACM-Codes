#include <cstdio>
#include <algorithm>
using namespace std;
#define debug(x) cout<<(x)<<endl
typedef long long LL;
int ans,a[128][128],dp[128][128],n,m,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int dfs(int x,int y){
	if(dp[x][y])
		return dp[x][y];
	dp[x][y]=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx&&xx<=n&&yy&&yy<=m&&a[x][y]>a[xx][yy])
			dp[x][y]=max(dp[x][y],dfs(xx,yy)+1);
	}
	return dp[x][y];
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=max(ans,dfs(i,j));
	printf("%d\n",ans);
	return 0;
}