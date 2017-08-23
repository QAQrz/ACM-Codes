#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=112345;
struct node{
	LL k,l,s;
}p[maxn];
LL n,f,ans;
inline bool cmp(node a,node b){
	return a.s-a.k>b.s-b.k;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>f;
	for(int i=0;i<n;i++){
		cin>>p[i].k>>p[i].l;
		p[i].s=min(p[i].k*2,p[i].l),p[i].k=min(p[i].k,p[i].l);
	}
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++)
		ans+=i<f?p[i].s:p[i].k;
	db(ans);
	return 0;
}