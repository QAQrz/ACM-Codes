#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl
typedef long long LL;
LL dp[5123][5],t,n,ans,a[1024],v[1024],l;
int main(){
	scanf("%lld",&t);
	for(int k=1;k<=t;k++){
		memset(dp,0,sizeof dp);
		scanf("%lld %lld",&n,&l);
		l*=2;
		for(int i=0;i<n;i++){
			scanf("%lld %lld",&a[i],&v[i]);
			a[i]*=2;
		}
		for(int i=0;i<n;i++)
			for(int j=l;j>=a[i]/2;j--)
				for(int x=0;x<3;x++){
					if(j>=a[i])
						dp[j][x]=max(dp[j][x],dp[j-a[i]][x]+v[i]);
					if(x)
						dp[j][x]=max(dp[j][x],dp[j-a[i]/2][x-1]+v[i]);
				}
		ans=dp[l][2];
		for(int i=0;i<n;i++)
			ans=max(ans,v[i]);
		printf("Case #%d: %lld\n",k,ans);
	}
	return 0;
}