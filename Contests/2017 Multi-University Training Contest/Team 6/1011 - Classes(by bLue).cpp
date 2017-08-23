#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
	int t, n, a, b, c, d, e, f, g;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int ans = 0;
		for(int i=0; i<n; ++i) {
			scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
			a = a-(d+f-g);
			b = b-(d+e-g);
			c = c-(e+f-g);
			d = d-g;
			e = e-g;
			f = f-g;
			if(a>=0 && b>=0 && c>=0 && d>=0 && e>=0 && f>=0 && g>=0) {
				int sum = a+b+c+d+e+f+g;
				ans = max(ans, sum);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}