#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e4+10;
typedef long long LL;
const LL mod = 1e9+7;
int t, n, k;
LL sum, a[MAX], pres[MAX][110], tmp, sum2[MAX][110];
char s[MAX];
LL c[111][111];
void Init(){	
	c[0][0] = 1;
	for(int i = 1; i<=110; ++i){
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j<i; ++j){
			c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
}
int main(){
	Init();
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s+1);
		for(int i = 1; i<=n; ++i){
			pres[i][0] = 1;
			pres[i][1] = pres[i-1][1]+s[i]-'0';
			for(int j = 2; j<=k; ++j){
				pres[i][j] = (pres[i][j-1]*pres[i][1])%mod;
			}
		}
		sum2[0][0] = 1;
		for(int i = 1; i<=n; ++i){
			for(int j = 0; j<=k; ++j){
				sum2[i][j] = (sum2[i-1][j]+pres[i][j])%mod;
			}
		}
		for(int i = 1; i<=n; ++i){
			sum = 0;
			for(int j = 0; j<=k; ++j){
				sum = (sum+(j%2?-1:1)*c[k][j]*pres[i][k-j]%mod*sum2[i-1][j]%mod+mod)%mod;
			}
			if(i==n)printf("%lld\n", sum);
			else printf("%lld ", sum);
		}
	}
	return 0;
}