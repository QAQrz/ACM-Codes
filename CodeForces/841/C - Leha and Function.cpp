#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=212345;
struct node{
	LL a,b;
}p[maxn];
LL n,a[maxn];
inline bool cmp(node a,node b){
	return a.a>b.a;
}
inline bool cmp1(node a,node b){
	return a.b<b.b;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		cin>>p[i].a;
		p[i].b=i;
	}
	sort(a,a+n);
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++)
		p[i].a=a[i];
	sort(p,p+n,cmp1);
	for(int i=0;i<n;i++)
		printf("%lld%c",p[i].a,i<n-1?' ':'\n');
	return 0;
}