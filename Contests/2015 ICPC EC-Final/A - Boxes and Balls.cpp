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
LL t,n,l,r,ans,mid;
int main(){
	scanf("%lld",&t);
	for(LL k=1;k<=t;k++){
		scanf("%lld",&n);
		ans=l=1,r=2e9;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*(mid+1)/2>n)
				r=mid-1;
			else
				l=mid+1,ans=mid*(mid+1)/2;
		}
		printf("Case #%lld: %lld\n",k,ans);
	}
	return 0;
}