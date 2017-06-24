#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2123456,mod=1e9+9;
LL t,n,i,m,a[maxn],v[maxn*4],dp[maxn];
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(i=1,m=0;i<n;i++)
			a[i]=a[i+1]-a[i],m=min(m,a[i]);
		for(i=1;i<n;i++)
			a[i]-=m,v[a[i]]=-1;
		for(i=1;i<n;i++){
			if(~v[a[i]])
				dp[i]=(dp[i-1]*2-dp[v[a[i]]-1]+mod)%mod;
			else
				dp[i]=(dp[i-1]*2+1)%mod;
			v[a[i]]=i;
		}
		printf("%lld\n",dp[n-1]);
	}
	return 0;
}