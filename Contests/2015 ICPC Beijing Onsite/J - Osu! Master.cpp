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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	char s[2];
	while(~ scanf("%d", &n)) {
		int ans = 0, last = 0;
		for(int i=0; i<n; ++i) {
			scanf("%s", s);
			if(s[0] != 'S') {
				scanf("%d", &x);
				if(x == last+1) {
					last = x;
				}
				else {
					last = 1;
					ans++;
				}
				// printf("last %d ans %d\n", last, ans);
			}
			else {
				if(last) ans++;
				last = 1;
			}
		}
		if(n) ans++;
		printf("%d\n", ans);
	}
	
	return 0;
}

/*
10
C 1
C 2
B 3
C 1
B 2
B 1
S
C 1
S
B 1
1
S
0
2
S
B 1
*/