#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl;
typedef long long LL;
int n,dp[12][112345],x,t,a[12][112345];
int main(){
	while(~scanf("%d",&n),n){
		memset(dp,0,sizeof dp);
		memset(a,0,sizeof a);
		while(n--){
			scanf("%d %d",&x,&t);
			a[x][t]++;
		}
		for(int i=0;i<11;i++)
			dp[i][100000]=a[i][100000];
		for(int i=99999;~i;i--)
			for(int j=0;j<11;j++){
				dp[j][i]=max(dp[j][i],dp[j][i+1]+a[j][i]);
				if(j)
					dp[j][i]=max(dp[j][i],dp[j-1][i+1]+a[j][i]);
				if(j<10)
					dp[j][i]=max(dp[j][i],dp[j+1][i+1]+a[j][i]);
			}
		printf("%d\n",dp[5][0]);
	}
	return 0;
}