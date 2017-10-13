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
LL a,b,s[66];
inline LL slo(LL x){
	return x*(x-1)/2;
}
inline LL cal(LL x){
	if(!x)
		return 0;
	LL n=0,t=0,ans=0;
	while(x){
		if(!(x&1))
			n++;
		s[t++]=x&1,x>>=1;
	}
	if(!n)
		return slo(t);
	for(int i=t-2;s[i];i--)
		ans++;
	if(n<2)
		return slo(t-1)+ans+1;
	return slo(t-1)+ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b;
	db(cal(b)-cal(a-1));
	return 0;
}