#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=312345;
struct node{
	LL idx,cost;
}p[maxn];
LL n,k,ans,a[maxn];
priority_queue<node>q;
bool operator <(node a,node b){
	if(a.cost==b.cost)
		return a.idx>b.idx;
	return a.cost<b.cost;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>p[i].cost;
		p[i].idx=i;
		if(i<=k)
			q.push(p[i]);
	}
	for(int i=k+1;i<=k+n;i++){
		if(i<=n)
			q.push(p[i]);
		node x=q.top();
		q.pop();
		ans+=x.cost*(i-x.idx),a[x.idx]=i;
	}
	db(ans);
	for(int i=1;i<=n;i++)
		printf("%lld%c",a[i],i<n?' ':'\n');
	return 0;
}