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
const LL inf=0x3f3f3f3f,mod=1e9+7,MAX=1e5+10;
namespace FastIO {
	#define BUF_SIZE 100000
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if(p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if(pend == p1) {
				IOerror = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch) {
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	inline void read(LL &x) {
		char ch;
		while(blank(ch = nc()));
		if(IOerror)
			return;
		for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
	}
	#undef BUF_SIZE
};
using namespace FastIO;
LL t, n, gcdd, k;
struct node{
	LL x,y,r;
	LL a, b, c;
}a[1010];
bool check(node a, node b){
	if((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)==(a.r+b.r)*(a.r+b.r))return 1;
	return 0;
}
bool vis[1010];
int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		for(LL i =0 ; i<n; ++i){
			scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].r);
			a[i].a = a[i].b = 0;
		}
		a[0].a = a[0].b = 1;
		a[0].c = 0;
		queue<LL>que;
		que.push(0);
		memset(vis, 0, sizeof(vis));
		vis[0] = 1;
		while(!que.empty()){
			k = que.front();
			que.pop();
			for(LL i = 1; i<n; ++i){
				if(!vis[i]&&check(a[k], a[i])){
					vis[i] = 1;
					a[i].a = a[0].r;
					a[i].b = a[i].r;
					gcdd = __gcd(a[i].a, a[i].b);
					a[i].a/=gcdd;
					a[i].b/=gcdd;
					a[i].c = 1-a[k].c;
					que.push(i);
				}
			}
		}
		for(LL i = 0; i<n; ++i){
			if(a[i].a&&a[i].b){
				if(a[i].a%a[i].b)printf("%lld/%lld ",a[i].a, a[i].b);
				else printf("%lld ", a[i].a/a[i].b);
				if(a[i].c)printf("counterclockwise\n");
				else printf("clockwise\n");
			}else {
				printf("not moving\n");
			}
		}
	}
	return 0;
}