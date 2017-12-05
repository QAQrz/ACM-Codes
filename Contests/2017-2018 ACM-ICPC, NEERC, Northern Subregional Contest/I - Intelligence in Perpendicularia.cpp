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
const int MAX = 1e3+10;
const LL INF = 112345678;
LL n, l, r, u, d;
struct node{
	LL x, y;
}p[MAX];
int main(){
	freopen("intel.in","r",stdin);
	freopen("intel.out","w",stdout);
	while(~scanf("%lld", &n)){
		l = u = INF;
		d = r = -INF;
		for(LL i = 0; i<n; ++i){
			scanf("%lld%lld", &p[i].x, &p[i].y);
			l = min(l, p[i].x);
			r = max(r, p[i].x);
			u = min(u, p[i].y);
			d = max(d, p[i].y);
		}
		LL sum = abs(p[0].x-p[n-1].x)+abs(p[0].y-p[n-1].y);
		for(LL i = 1; i<n; ++i){
			sum+=abs(p[i].x-p[i-1].x)+abs(p[i].y-p[i-1].y);
		}
		printf("%lld\n", sum-2*(r-l+d-u));
	}
	return 0;
}