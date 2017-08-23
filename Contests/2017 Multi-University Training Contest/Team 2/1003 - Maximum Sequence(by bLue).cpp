#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int MAXN = 250010;
const int INF = 0x3f3f3f3f;
const long long mod = 1000000007;
struct node {
	long long max;
	int idx;
} st[MAXN<<2];
int n, b[MAXN];
long long v[MAXN];
node Merge(node a, node b) {
	if(a.max > b.max)
		return a;
	else if(a.max < b.max) return b;
	else return (node){a.max, min(a.idx, b.idx)};
}
void PushUp(int rt) {
	st[rt] = Merge(st[rt<<1], st[rt<<1|1]);
}
void Build(int l, int r, int rt) {
	if(l == r) {
		scanf("%lld", &st[rt].max);
		st[rt].max -= l;
		st[rt].idx = l;
		return;
	}
	int m = (l+r) >> 1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}
node Query(int L, int R, int l, int r, int rt) {
	if(L<=l && r<=R) return st[rt];
	int m = (l+r) >> 1;
	node ret = (node){-INF, 0};
	if(L <= m) ret = Merge(ret, Query(L, R, lson));
	if(R > m) ret = Merge(ret, Query(L, R, rson));
	return ret;
}
int main(int argc, char const *argv[]) {
	while(~ scanf("%d", &n)) {
		Build(1, n, 1);
		memset(v,0,sizeof v);
		for(int i=1; i<=n; ++i) {
			scanf("%d", &b[i]);
			v[b[i]]++;
		}
		for(int i=1;i<=n;i++)
			v[i]+=v[i-1];
		long long ans = 0;
		int l = 1;
		long long e = -INF;
		while(l <= n) {
			node maxx = Query(l, n, 1, n, 1);
			if(maxx.max > e) {
				ans += maxx.max*(v[maxx.idx]-v[l-1]);
				ans %= mod;
				if(e == -INF && v[maxx.idx]-v[l-1]>0) e = maxx.max-(n+1);
				l = maxx.idx+1;
			}
			else {
				ans += e*(v[n]-v[l-1]);
				ans %= mod;
				l = n+1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}