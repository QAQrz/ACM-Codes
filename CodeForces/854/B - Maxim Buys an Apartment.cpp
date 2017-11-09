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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
LL n,k;
LL cal(){
	if(k*3<=n)
		return k*2;
	return n-k;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	if(!k||k==n)
		printf("0 0\n");
	else
		printf("1 %lld\n",cal());
	return 0;
}