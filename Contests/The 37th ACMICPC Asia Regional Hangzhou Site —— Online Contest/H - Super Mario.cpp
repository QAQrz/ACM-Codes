#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pc(x) putchar(x)
#define ps(x) puts(x)
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;



const int MAXN = 100010;

struct node {
	int sum, l, r;
} hjt[MAXN*40];

int a[MAXN], sorted[MAXN], num, root[MAXN], cnt;

int GetIdx(int v) {
	return lower_bound(sorted+1, sorted+1+num, v) - sorted;
}

void Init() {
	cnt = 0;
}

inline int CreateNode(int sum, int l, int r) {
	int idx = ++cnt;
	hjt[idx].sum = sum;
	hjt[idx].l = l;
	hjt[idx].r = r;

	return idx;
}

void Insert(int &root, int pre_rt, int pos, int l, int r) {
	root = CreateNode(hjt[pre_rt].sum+1, hjt[pre_rt].l, hjt[pre_rt].r);
	if(l == r) return;
	int m = (l+r) >> 1;
	if(pos <= m)
		Insert(hjt[root].l, hjt[pre_rt].l, pos, l, m);
	else Insert(hjt[root].r, hjt[pre_rt].r, pos, m+1, r);
}

int Query(int s, int e, int R, int l, int r) {
	if(r <= R) return hjt[e].sum - hjt[s].sum;
	int m = (l+r) >> 1;
	if(R <= m)
		return Query(hjt[s].l, hjt[e].l, R, l, m);
	else return hjt[hjt[e].l].sum-hjt[hjt[s].l].sum + Query(hjt[s].r, hjt[e].r, R, m+1, r);
}

int main(int argc, char const *argv[]) {
	int t, n, m, l, r, h;
	scanf("%d", &t);
	for(int cs=1; cs<=t; ++cs) {
		printf("Case %d:\n", cs);
		scanf("%d %d", &n, &m);
		Init();
		for(int i=1; i<=n; ++i) {
			scanf("%d", &a[i]);
			sorted[i] = a[i];
		}
		sort(sorted+1, sorted+1+n);
		num = unique(sorted+1, sorted+1+n) - (sorted+1);
		for(int i=1; i<=n; ++i) {
			Insert(root[i], root[i-1], GetIdx(a[i]), 1, num);
		}
		while(m--) {
			scanf("%d %d %d", &l, &r, &h);
			l++;
			r++;
			int idx = upper_bound(sorted+1, sorted+1+num, h) - sorted - 1;
			if(idx == 0) {
				printf("0\n");
				continue;
			}
			printf("%d\n", Query(root[l-1], root[r], idx, 1, num));
		}
	}
	
	return 0;
}