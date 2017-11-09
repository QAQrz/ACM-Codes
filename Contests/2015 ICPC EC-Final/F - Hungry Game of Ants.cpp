#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int MAX = 1e6+10;
LL t, k, n, ans, ans2, j;
LL pre2[MAX], dp[MAX];
LL get_sum(LL l, LL r){
	return (r-l+1)*(l+r)/2;
}
int main(){
	pre2[0] = 1;
	for(LL i = 1; i<=1000000; ++i){
		pre2[i] = (pre2[i-1]*2)%mod;
	}
	scanf("%lld", &t);
	for(LL cas = 1; cas<=t; ++cas){
		scanf("%lld%lld", &n, &k);
		if(k==1)ans = 0;
		else {
			ans = 0;
			for(LL i = 1; i<=k-1; ++i){
				if(get_sum(1, i)<get_sum(i+1, k)){
					ans = (ans+pre2[i-1])%mod;
				}else break;
			}
			ans++;
			if(n==k){
				ans = (ans*2)%mod;
				ans2 = 1;
			}else {
				memset(dp, 0, sizeof(dp));
				j = k, dp[k] = 1LL;
				for(LL i = k+1; i<=n; ++i){
					while(get_sum(1, j)<get_sum(j+1, i))j++;
					dp[i] = (2*dp[i-1]-dp[j-1]+mod)%mod;
				}
				ans2 = (dp[n]-dp[j-1]+mod)%mod;
			}
		}
		printf("Case #%lld: %lld\n", cas, (ans*ans2)%mod);
	}
	return 0;
}