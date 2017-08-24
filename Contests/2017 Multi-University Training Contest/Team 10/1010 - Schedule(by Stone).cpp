#include <bits/stdc++.h>
#define db(x) cout<<x<<endl;
typedef long long LL;
const int MAX = 1e5+10;
using namespace std;
int t, n;
struct node{
	LL l, r;
}p[MAX*2];
int cnt;
LL f[MAX*3], num[MAX*3];
int ll[MAX*2], rr[MAX*2], ans;
template <class T>
inline bool read(T &ret) {
	char c;
	int sgn;
	if(c=getchar(), c==EOF) return 0;
	while(c!='-' && (c<'0' || c>'9')) c = getchar();
	sgn = (c=='-')?-1:1;
	ret = (c=='-')?0:(c-'0');
	while(c=getchar(), c>='0'&&c<='9') ret = ret*10 + (c-'0');
	ret *= sgn;
	return 1;
}
int main() {
	read(t);
	while(t--){
		read(n);
		cnt = 0;
		for(int i = 0; i<n; ++i){
			read(p[i].l);read(p[i].r);
			f[cnt++] = p[i].l;
			f[cnt++] = p[i].r;
		}
		sort(f, f+cnt);
		cnt = unique(f, f+cnt)-f;
		memset(num, 0, sizeof(num));
		int l, r;
		for(int i = 0; i<n; ++i){
			l = lower_bound(f, f+cnt, p[i].l)-f;
			r = lower_bound(f, f+cnt, p[i].r)-f;
			num[l]++;
			num[r]--;
		}
		ans = 0;
		LL sum = 0;
		memset(ll, 0x3f3f3f3f, sizeof(ll));
		memset(rr, -1, sizeof(rr));
		for(int i = 0; i<cnt; ++i){
			rr[sum] = i;
			sum+=num[i];
			if(sum>ans){
				ans = sum;
				ll[ans] = i;
			}
		}
		sum = 0;
		for(int i = ans; i>=1; --i){
			rr[i] = max(rr[i], rr[i+1]);
			ll[i] = min(ll[i], ll[i+1]);
			sum+=f[rr[i]]-f[ll[i]];
		}
		printf("%d %lld\n", ans, sum);
	}
	return 0;
}