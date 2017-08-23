#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
LL t,n,m,ans;
int main(int argc, char const *argv[]) {
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld", &n, &m);
		m = min(m, n*(n-1)/2);
		ans = n*n*(n-1) - max(0LL, m-n+1)*2;
		for(int i=0; i<min(m, n-1); ++i) {
			ans -= 2*(n-1) + i*2*(n-2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}