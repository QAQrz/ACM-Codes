#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl
typedef long long LL;
int v[5123],dp[5123][5123],n;
LL sum[5123];
int dfs(int l,int r){
	if(l>=r)
		return 0;
	if(~dp[l][r])
		return dp[l][r];
	dp[l][r]=v[r-l+1];
	for(int i=l,j=r;i<j;){
		LL suml=sum[i]-sum[l-1],sumr=sum[r]-sum[j-1];
		if(suml<sumr)
			i++;
		else if(suml>sumr)
			j--;
		else
			dp[l][r]=min(dp[l][r],dfs(i+1,j-1)+v[i-l+1]+v[r-j+1]),i++,j--;
	}
	return dp[l][r];
}
int main(){
	while(~scanf("%d",&n),n){
		memset(dp,-1,sizeof dp);
		for(int i=1;i<=n;i++){
			scanf("%lld",&sum[i]);
			sum[i]+=sum[i-1];
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&v[i]);
		printf("%d\n",dfs(1,n));
	}
	return 0;
}