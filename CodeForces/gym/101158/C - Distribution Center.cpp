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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=212345;
struct node{
	LL p,x;
}p[maxn];
LL n,m,ans[maxn],tmp,tmp1,a[maxn],b[maxn];
inline bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(LL i=1;i<=n;i++)
		ans[i]=1;
	for(LL i=0;i<m;i++)
		cin>>p[i].x>>p[i].p;
	sort(p,p+m,cmp);
	for(LL i=0;i<m;i++)
		tmp=ans[p[i].p],tmp1=ans[p[i].p+1],ans[p[i].p]+=tmp1-a[p[i].p],ans[p[i].p+1]+=tmp-b[p[i].p],a[p[i].p]=ans[p[i].p],b[p[i].p]=ans[p[i].p+1];
	for(LL i=1;i<=n;i++)
		printf("%lld%c",ans[i],i<n?' ':'\n');
	return 0;
}