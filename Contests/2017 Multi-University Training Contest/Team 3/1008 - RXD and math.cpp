#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
LL n,k,t;
LL fp(LL n,LL x){
	LL ans=1,t=n%mod;
	while(x){
		if(x&1)
			ans=ans*t%mod;
		t=t*t%mod,x>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n>>k)
		printf("Case #%lld: %lld\n",++t,fp(n,k));
	return 0;
}