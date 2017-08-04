#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl
typedef long long LL;
LL dp[333][333],mod=1000000000;
char s[333];
LL dfs(LL l,LL r){
	if(~dp[l][r])
		return dp[l][r];
	if(l>=r)
		return 1;
	if(s[l]!=s[r])
		return 0;
	dp[l][r]=0;
	for(int i=l+2;i<=r;i++)
		if(s[i]==s[l]&&s[i]==s[r])
			dp[l][r]=(dp[l][r]+dfs(l+1,i-1)*dfs(i,r))%mod;
	return dp[l][r];
}
int main(){
	freopen("exploring.in","r",stdin);
	freopen("exploring.out","w",stdout);
	cin>>s;
	memset(dp,-1,sizeof dp);
	debug(dfs(0,strlen(s)-1));
	return 0;
}