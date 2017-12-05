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
const int MAX = 1e6+10;
const LL INF = 112345678;
int vis[MAX], n, x, m1, m2, ans[MAX], que1[MAX], que2[MAX], dp[MAX], cnt, sum;
int main(){
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	scanf("%lld", &n);
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i<=n ;++i){
		scanf("%d", &x);
		vis[x]++;
		dp[i] = INF;
	}
	cnt = m1 = m2 = 0;
	for(int i = 1; i<=1000000; ++i){
		if(vis[i]){
			cnt++;
			bool ok = false;
			que1[++m1] = vis[i];
			for(int j = i+i; j<=1000000; j+=i){
				if(vis[j]){ok = true;break;}
			}
			if(ok)que2[++m2] = vis[i];
		}
	}
	sort(que1+1, que1+1+m1);
	sort(que2+1, que2+1+m2);
	dp[0] = cnt;
	sum = 0;
	dp[0] = cnt;
	for(int i = 1; i<=m2; ++i){
		dp[(sum+=que2[i])] = cnt-i;
	}
	sum = que1[1];
	for(int i = 2; i<=m1; ++i){
		dp[(sum+=que1[i])] = min(cnt+1-i, dp[sum]);
	}
	printf("%d", cnt);
	for(int i=1; i<=n; ++i){
		dp[i] = min(dp[i], dp[i-1]);
		printf(" %d", dp[i]);
	}
	printf("\n", dp[n]);
	return 0;
}