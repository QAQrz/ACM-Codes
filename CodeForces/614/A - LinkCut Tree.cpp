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
LL l,r,k,a[66],t,ans=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>l>>r>>k;
	if(l<2)
		a[t++]=1;
	while(r/k>=ans){
		ans*=k;
		if(ans>=l)
			a[t++]=ans;
	}
	if(!t)
		db(-1);
	else
		for(int i=0;i<t;i++)
			printf("%lld%c",a[i],i<t-1?' ':'\n');
	return 0;
}