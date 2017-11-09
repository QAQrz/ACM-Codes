#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pc(x) putchar(x)
#define ps(x) puts(x)
#define pf(x) push_front(x)
#define pb(x) push(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
const int INF = 0x3f3f3f3f;
struct info {
	string d;
	int cnt2, cnt3;
	int step;
};
int ans[100001];
bool vis[100001][4][3];
int StoI(string s) {
	int ret = 0;
	for(int i=0; i<5; ++i) {
		ret = ret*10 + s[i] - '0';
	}
	return ret;
}
void BFS() {
	memset(ans, 0x3f, sizeof ans);
	queue<info> q;
	q.push((info){"12345", 0, 0, 0});
	vis[12345][0][0] = true;
	ans[12345] = 0;
	while(!q.empty()) {
		info f = q.front();
		q.pop();
		for(int i=0; i<4; ++i) {
			info nxt = f;
			swap(nxt.d[i], nxt.d[i+1]);
			int n = StoI(nxt.d);
			if(!vis[n][nxt.cnt2][nxt.cnt3]) {
				nxt.step++;
				ans[n] = min(ans[n], nxt.step);
				q.push(nxt);
				vis[n][nxt.cnt2][nxt.cnt3] = true;
			}
		}
		if(f.cnt2 < 3) {
			for(int i=0; i<5; ++i) {
				info nxt = f;
				int tmp = nxt.d[i] - '0';
				tmp = (tmp+1) % 10;
				nxt.d[i] = tmp + '0';
				int n = StoI(nxt.d);
				nxt.cnt2++;
				if(!vis[n][nxt.cnt2][nxt.cnt3]) {
					nxt.step++;
					ans[n] = min(ans[n], nxt.step);
					q.push(nxt);
					vis[n][nxt.cnt2][nxt.cnt3] = true;
				}
			}
		}
		if(f.cnt3 < 2) {
			for(int i=0; i<5; ++i) {
				info nxt = f;
				int tmp = nxt.d[i] - '0';
				tmp = (tmp*2) % 10;
				nxt.d[i] = tmp + '0';
				int n = StoI(nxt.d);
				nxt.cnt3++;
				if(!vis[n][nxt.cnt2][nxt.cnt3]) {
					nxt.step++;
					ans[n] = min(ans[n], nxt.step);
					q.push(nxt);
					vis[n][nxt.cnt2][nxt.cnt3] = true;
				}
			}
		}
	}
}
int main(){
	BFS();
	char str[10];
	while(~ scanf("%s", str)) {
		int n = atoi(str);
		if(ans[n] != INF) printf("%d\n", ans[n]);
		else printf("-1\n");
	}
	return 0;
}