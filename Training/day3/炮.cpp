#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl
typedef long long LL;
LL dp[128][128][128],n,m,ans,mod=999983;
int main(){
	dp[0][0][0]=1;
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n;i++)
		for(LL j=0;j<=m;j++)
			for(LL k=0;j+k<=m;k++){
				dp[i][j][k]=dp[i-1][j][k];
				if(j)
					dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k]*(m-j-k+1))%mod;
				if(k)
					dp[i][j][k]=(dp[i][j][k]+dp[i-1][j+1][k-1]*(j+1))%mod;
				if(j>1)
					dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-2][k]*(m-j-k+2)*(m-j-k+1)/2)%mod;
				if(k>1)
					dp[i][j][k]=(dp[i][j][k]+dp[i-1][j+2][k-2]*(j+2)*(j+1)/2)%mod;
				if(k)
					dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k-1]*j*(m-j-k+1))%mod;
				if(i==n)
					ans=(ans+dp[i][j][k])%mod;
			}
	printf("%lld\n",ans);
	return 0;
}