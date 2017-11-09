#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAX=1e5+10;
LL t, n, m, a[MAX], k, ans;
LL pe[MAX], num[MAX], gcd_am, vis[MAX];
int main(){
	scanf("%lld", &t);
	for(LL cas = 1; cas<=t; ++cas){
		scanf("%lld%lld", &n, &m);
		LL sqr_m = sqrt(m);
		LL cnt = 0;
		for(LL i = 1; i<=sqr_m; ++i){
			if(m%i==0){
				pe[cnt++] = i;
				if(i*i!=m)pe[cnt++] = m/i;
			}
		}
		sort(pe, pe+cnt);
		memset(num, 0, sizeof(num));
		memset(vis, 0, sizeof(vis));
		for(LL i =0; i<n; ++i){
			scanf("%lld", &a[i]);
			gcd_am = __gcd(a[i], m);
			for(LL j = 0; j<cnt; ++j){
				if(pe[j]%gcd_am==0){
					vis[j] = 1;
				}
			}
		}
		vis[cnt-1] = 0;
		ans = 0;
		for(LL i = 0; i<cnt; ++i){
			if(vis[i]!=num[i]){
				LL tmp = m/pe[i], num2 = vis[i]-num[i];
				ans+=tmp*(tmp+1)/2*pe[i]*num2;
				for(LL j = i+1; j<cnt; j++){
					if(pe[j]%pe[i]==0){
						num[j]+=num2;
					}
				}
			}
		}
		printf("Case #%lld: %lld\n", cas, ans);
	}
	return 0;
}