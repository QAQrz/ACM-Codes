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
LL t, n, sqrn, l, r;
int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		sqrn = 2*sqrtl(n);
		l = r = -1;
		if(n==1){
			printf("IMPOSSIBLE\n");
			continue;
		}
		for(LL i = 2; i<=sqrn; ++i){
			if(i%2==1&&n%i==0){
				l = n/i-i/2;
				r = n/i+i/2;
				break;
			}else if(i%2==0&&n%i!=0&&(n*2)%i==0){
				l = n/i-i/2+1;
				r = n/i+i/2;
				break;
			}
		}
		if(l!=-1){
			printf("%lld = ", n);
			for(LL i = l; i<r; ++i){
				printf("%lld + ", i);
			}
			printf("%lld\n", r);
		} else printf("IMPOSSIBLE\n");
	}
	return 0;
}