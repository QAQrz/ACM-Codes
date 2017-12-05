#include <cstdio>
#include <vector>
using namespace std;
int n, a[10000];
vector<unsigned long long> v;
vector<long long> ans;
long long Solve() {
	unsigned long long res = 0, p = 1;
	for(int i=0; i<v.size(); ++i) {
		if(v[i] >= 128) v[i] -= 128;
		res += v[i]*p;
		p <<= 7;
	}
	if(res == 18446744073709551615ULL) {
		return res/2+1;
	}
	if(res & 1) return -((res+1)>>1);
	else return res/2;
}
int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	for(int i=0; i<n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; ++i) {
		v.push_back(a[i]);
		if(a[i] < 128) {
			ans.push_back(Solve());
			v.clear();
		}
	}
	for(int i=0; i<ans.size(); ++i) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}