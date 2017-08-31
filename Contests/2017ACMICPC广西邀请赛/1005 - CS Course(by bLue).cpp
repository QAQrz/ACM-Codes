#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100001;
int n, q, p, a[MAXN], digit[MAXN][31], sum[31], x;
int main(int argc, char const *argv[]) {
	while(~scanf("%d %d", &n, &q)) {
		memset(sum, 0, sizeof sum);
		x = 0;
		for(int i=0; i<n; ++i) {
			scanf("%d", &a[i]);
			x ^= a[i];
			int tmp = a[i];
			for(int j=29; j>=0; --j) {
				digit[i][j] = tmp & 1;
				tmp >>= 1;
				sum[j] += digit[i][j];
			}
		}
		while(q--) {
			scanf("%d", &p);
			p--;
			int ans1 = 0, ans2 = 0, ans3 = x, d1, d2;
			for(int i=0; i<30; ++i) {
				int cnt = sum[i] - digit[p][i];
				if(cnt == n-1) d1 = 1;
				else d1 = 0;
				ans1 = ans1*2 + d1;
				if(cnt > 0) d2 = 1;
				else d2 = 0;
				ans2 = ans2*2 + d2;
			}
			ans3 = x^a[p];
			printf("%d %d %d\n", ans1, ans2, ans3);
		}
	}
	return 0;
}