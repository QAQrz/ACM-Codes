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
LL n,l,r,x,ans;
int main(){
	scanf("%lld",&n);
	while(n--){
		scanf("%lld %lld %lld",&x,&l,&r);
		if(l>r)
			swap(l,r);
		ans=x/r;
		printf("%s\n",x>ans*r&&x<(ans+1)*l?"TAT":"QWQ");
	}
	return 0;
}