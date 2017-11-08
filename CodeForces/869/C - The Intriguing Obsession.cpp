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
const LL inf=0x3f3f3f3f,mod=998244353,maxn=5123;
LL p[maxn],n[maxn],a,b,c,x,y,z;
inline LL exgcd(LL a,LL b,LL &x,LL &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	LL r=exgcd(b,a%b,x,y),temp=x;
	x=y,y=temp-a/b*y;
	return r;
}
inline LL cal(LL a,LL m){
	LL ans,x,y,gcd=exgcd(a,m,x,y);
	if(1%gcd)
		return -1;
	x*=1/gcd,m=abs(m),ans=x%m;
	if(ans<=0)
		ans+=m;
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	p[0]=1,n[0]=cal(p[0],mod);
	for(int i=1;i<maxn;i++)
		p[i]=(p[i-1]*i)%mod,n[i]=cal(p[i],mod);
	cin>>a>>b>>c;
	for(int i=min(a,b);i;i--)
		x=(x+p[a]*n[a-i]%mod*n[i]%mod*p[b]%mod*n[b-i]%mod*n[i]%mod*p[i]%mod)%mod;
	for(int i=min(a,c);i;i--)
		y=(y+p[a]*n[a-i]%mod*n[i]%mod*p[c]%mod*n[c-i]%mod*n[i]%mod*p[i]%mod)%mod;
	for(int i=min(b,c);i;i--)
		z=(z+p[b]*n[b-i]%mod*n[i]%mod*p[c]%mod*n[c-i]%mod*n[i]%mod*p[i]%mod)%mod;
	db((x+y+z+x*y%mod+x*z%mod+y*z%mod+x*y%mod*z%mod+1)%mod);
	return 0;
}