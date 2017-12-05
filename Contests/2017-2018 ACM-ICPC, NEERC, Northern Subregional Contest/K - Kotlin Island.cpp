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
LL nn, mm, n, m, w, r, c;
char mp[110][110];
void solve(LL r, LL c){
	for(LL i = 0; i<=n; ++i){
		for(LL j = 0; j<=m; ++j){
			mp[i][j] = '.';
		}
	}
	for(LL i = 0; i<r-1; ++i){
		for(LL j = 0; j<m; ++j){
			mp[2*i+1][j] = '#';
		}
	}
	for(LL i = 0; i<c-1; ++i){
		for(LL j = 0; j<m; ++j){
			mp[j][2*i+1] = '#';
		}
	}
	for(LL i = 0; i<n; ++i){
		for(LL j = 0; j<m; ++j){
			printf("%c", mp[i][j]);
		}
		printf("\n");
	}
}
int main(){
	freopen("kotlin.in","r",stdin);
	freopen("kotlin.out","w",stdout);
	while(~scanf("%lld%lld%lld", &n, &m, &w)){
		nn = (n+1)/2;
		mm = (m+1)/2;
		if(nn*mm<w)printf("Impossible\n");
		else {
			r = c = -1;
			for(LL i  = 1; i*i<=w; ++i){
				if(w%i==0){
					if(i<=nn&&(w/i)<=mm){
						r = i;
						c = w/i;
					}
					if(i<=mm&&(w/i)<=nn){
						r = w/i;
						c = i;
					}
				}
			}
			if(c==-1)printf("Impossible\n");
			else solve(r, c);
		}
	}
	return 0;
}