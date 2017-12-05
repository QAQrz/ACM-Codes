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
const LL INF = 112345678;
LL n, cnt, val;
vector<LL>vec[MAX];
bool check(LL n){
	while(n>1){
		if(n&1)return 1;
		n>>=1;
	}
	return 0;
}
bool solve(LL n){
	if(!check(n))return 0;
	cnt = 0;
	vec[++cnt].push_back(n);
	for(LL i = 2; i*i*i<=n; ++i){
		if(n%i==0){
			vector<LL>p;
			val = n;
			while(val%i==0){
				val/=i;
				p.push_back(i);
			}
			while(val%(i+1)==0){
				val/=(i+1);
				p.push_back(i+1);
			}
			if(val==1){
				vec[++cnt] = p;
			}
		}
	}
	val = sqrt(n);
	if(val*val==n){
		vec[++cnt].push_back(val);
		vec[cnt].push_back(val);
	}else if(val*(val+1)==n){
		vec[++cnt].push_back(val);
		vec[cnt].push_back(val+1);
	}else if((val+1)*(val+1)==n){
		vec[++cnt].push_back(val+1);
		vec[cnt].push_back(val+1);
	}
	return 1;
}
int main(){
	freopen("little.in","r",stdin);
	freopen("little.out","w",stdout);
	scanf("%lld", &n);
	if(solve(n)){
		printf("%d\n", cnt);
		for(int i = 1; i<=cnt; ++i){
			printf("%d", (int)vec[i].size());
			for(int j = 0; j<(int)vec[i].size(); ++j){
				printf(" %lld", vec[i][j]);
			}
			printf("\n");
		}
	}else printf("-1\n");
	return 0;
}