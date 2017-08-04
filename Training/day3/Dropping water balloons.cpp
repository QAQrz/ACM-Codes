#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl
typedef long long LL;
LL dp[66][66],n,k,i;
int main(){
	for(i=1;i<64;i++)
		for(int j=1;j<64;j++)
			dp[i][j]=dp[i][j-1]+dp[i-1][j-1]+1;
	while(~scanf("%lld %lld",&k,&n),k){
		k=min(k,63LL);
		for(i=0;i<64;i++)
			if(dp[k][i]>=n){
				printf("%lld\n",i);
				break;
			}
		if(i>63)
			printf("More than 63 trials needed.\n");
	}
	return 0;
}