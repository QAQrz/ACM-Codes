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
const LL inf=0x3f3f3f3f,mod=1e9+7,MAX=1e6+10;
LL t, l, n, m, ans[MAX], maxx;
struct node{
	LL cost, t;
	bool operator < (const  node &a)const {
		if(t!=a.t)return t>a.t;
		return cost<a.cost;
	}
}ver;
int main(){
	scanf("%lld", &t);
	LL cas = 1;
	while(t--){
		priority_queue<node>que;
		scanf("%lld%lld%lld", &l,&n,&m);
		for(LL i = 0; i<n; ++i){
			scanf("%lld", &ver.cost);
			ver.t = ver.cost;
			que.push(ver);
		}
		int k = 0;
		while(!que.empty()&&k<l){
			ver = que.top();
			que.pop();
			ans[k++] = ver.t;
			ver.t+=ver.cost;
			que.push(ver);
		}
		while(!que.empty())que.pop();
		for(LL i = 0; i<m; ++i){
			scanf("%lld", &ver.cost);
			ver.t = ver.cost;
			que.push(ver);
		}
		k = l-1;
		maxx = -1;
		while(!que.empty()&&k>=0){
			ver = que.top();
			que.pop();
			maxx = max(maxx, ans[k--]+ver.t);
			ver.t+=ver.cost;
			que.push(ver);
		}
		printf("Case #%lld: %lld\n", cas++, maxx);
	}
	return 0;
}