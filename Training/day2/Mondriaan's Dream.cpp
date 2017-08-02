#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL ans[16][16],n,m,dp[16][1<<11],t;
void dfs(LL r,LL x,LL c){
	if(c>=m){
		dp[r][x]+=t;
		return;
	}
	dfs(r,x,c+1);
	if(c<m-1&&!((x>>c)&1)&&!((x>>(c+1))&1))
		dfs(r,x|(1<<c)|(1<<(c+1)),c+2);
}
int main(){
	while(~scanf("%lld %lld",&n,&m),n+m){
		if((n*m)%2){
			printf("0\n");
			continue;
		}
		if(n<m)
			swap(n,m);
		if(ans[n][m]){
			printf("%lld\n",ans[n][m]);
			continue;
		}
		memset(dp,0,sizeof dp);
		t=1;
		dfs(1,0,0);
		for(int i=2;i<=n;i++)
			for(int j=0;j<(1<<m);j++){
				if(!dp[i-1][j])
					continue;
				t=dp[i-1][j];
				dfs(i,~j&((1<<m)-1),0);
			}
		printf("%lld\n",ans[n][m]=dp[n][(1<<m)-1]);
	}
	return 0;
}