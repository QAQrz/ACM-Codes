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
int a,b,c,x,y,z,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>x>>y>>z;
	if(a>x)
		ans+=(a-x)/2;
	if(b>y)
		ans+=(b-y)/2;
	if(c>z)
		ans+=(c-z)/2;
	if(a<x)
		ans-=x-a;
	if(b<y)
		ans-=y-b;
	if(c<z)
		ans-=z-c;
	db(ans<0?"No":"Yes");
	return 0;
}	