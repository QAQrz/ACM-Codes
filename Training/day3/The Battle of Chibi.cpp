#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl
typedef long long LL;
int dp[1024][1024],sum[1024][1024],t,n,m,p,mod=1000000007,a[1024],ans,b[1024];
void add(int r,int x,int v){
	while(x<=n)
		sum[r][x]=(sum[r][x]+v)%mod,x+=x&-x;
}
int query(int r,int x){
	int ans=0;
	while(x)
		ans=(ans+sum[r][x])%mod,x-=x&(-x);
	return ans;
}
int main(){
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		ans=0;
		memset(dp,0,sizeof dp);
		memset(sum,0,sizeof sum);
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++){
			p=lower_bound(b+1,b+n+1,a[i])-b;
			for(int j=1;j<=m&&j<=i;j++){
				if(j<2)
					dp[i][j]=1;
				else
					dp[i][j]=(dp[i][j]+query(j-1,p-1))%mod;
				add(j,p,dp[i][j]);
				if(j>=m)
					ans=(ans+dp[i][j])%mod;
			}
		}
		printf("Case #%d: %d\n",k,ans);
	}
	return 0;
}