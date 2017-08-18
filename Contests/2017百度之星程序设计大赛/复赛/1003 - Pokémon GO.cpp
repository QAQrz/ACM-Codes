#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=11234;
LL t,n,ans,dp[maxn][2];
int main(){
	ios::sync_with_stdio(false);
	dp[0][0]=dp[1][0]=0,dp[0][1]=1,dp[1][1]=2;
	for(int i=2;i<maxn;i++)
		dp[i][0]=((dp[i-1][0]+dp[i-1][1])*2+(dp[i-2][0]+dp[i-2][1])*4)%mod,dp[i][1]=dp[i-1][1]*2%mod;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			if(i<2||i>=n)
				ans=(ans+dp[n][0]+dp[n][1])%mod;
			else
				ans=(ans+dp[n-i+1][1]*(dp[i-1][0]+dp[i-1][1])+dp[i][1]*(dp[n-i][0]+dp[n-i][1]))%mod;
		}
		db(ans);
	}
	return 0;
}