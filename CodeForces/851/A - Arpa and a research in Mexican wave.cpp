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
LL n,k,t;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>t;
	if(t>=n+k)
		db(0);
	else if(t<=k)
		db(t);
	else if(t<=n)
		db(k);
	else
		db(n-t+k);
	return 0;
}