#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl;
typedef long long LL;
int a[1<<20],dp[1<<22],n;
int main(){
	scanf("%d",&n);
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[a[i]^((1<<22)-1)]=a[i];
	}
	for(int i=(1<<22)-1;i;i--)
		if(!~dp[i])
			for(int j=0;j<22;j++)
				if(~dp[i|(1<<j)]){
					dp[i]=dp[i|(1<<j)];
					break;
				}
	for(int i=1;i<=n;i++)
		printf("%d%c",dp[a[i]],i<n?' ':'\n');
	return 0;
}