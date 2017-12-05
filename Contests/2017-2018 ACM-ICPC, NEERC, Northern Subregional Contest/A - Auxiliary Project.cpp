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
int a[]={6,2,5,5,4,5,6,3,7,6},n;
int main(){
	freopen("auxiliary.in","r",stdin);
	freopen("auxiliary.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n%3>1)
		db(n/3*7+1);
	else if(n%3)
		db((n/3-1)*7+4);
	else
		db(n/3*7);
	return 0;
}