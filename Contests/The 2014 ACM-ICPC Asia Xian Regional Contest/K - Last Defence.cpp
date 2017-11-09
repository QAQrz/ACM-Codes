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
LL k, n, m, ans;

LL solve(LL a, LL b){
	if(b==0)return 1;
	else return 1+solve(b, a%b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	scanf("%d", &t);
	for(int tt = 1; tt<=t; ++tt){
		scanf("%lld%lld", &n, &m);
		if(n<m)swap(n, m);
		if(n==0&&m==0){
			ans = 1;
		}else if(n==0||m==0){
			ans = 2;
		}else {
			k = __gcd(n, m);
			n/=k;
			m/=k;
			ans = 1;
			while(n&&m){
				ans += n/m;
				n %=m;
				swap(n,m);
			}
		}
		
		printf("Case #%d: %lld\n", tt, ans);
	}



	return 0;
}