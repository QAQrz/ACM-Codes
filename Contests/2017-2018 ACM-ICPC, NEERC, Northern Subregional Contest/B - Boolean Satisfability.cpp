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
const int MAX = 1e5+10;
char s[MAX];
int vis[333];
LL fast(LL a, LL n){
	LL ret = 1, base = a;
	while(n>0){
		if(n&1)ret = ret*base;
		base = base*base;
		n>>=1;
	}
	return ret;
}
int main(){
	freopen("boolean.in","r",stdin);
	freopen("boolean.out","w",stdout);
	while(~scanf("%s", s)){
		memset(vis, 0, sizeof(vis));
		for(int i = 0; s[i]; ++i){
			if(s[i]=='~'){
				vis[(int)s[i+1]] |=2;
				i++;
			}else if(s[i]=='|'){
				continue;
			}else {
				vis[(int)s[i]] |=1;
			}
		}
		int flag = 0;
		LL num = 0;
		for(int i = 0; i<200; ++i){
			if(vis[i]){
				num++;
				if(vis[i]==3)flag = 1;
			}
		}
		if(flag)printf("%lld\n", fast(2, num));
		else printf("%lld\n", fast(2, num)-1);
	}
	return 0;
}