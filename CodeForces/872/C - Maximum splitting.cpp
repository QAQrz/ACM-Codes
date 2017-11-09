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
int q,n,x;
inline int check(int x){
	if(x<4)
		return -1;
	return x/4;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>q;
	while(q--){
		cin>>n;
		if(n==9)
			db(1);
		else if(n%2){
			x=check(n-9);
			db(~x?x+1:x);
		}
		else
			db(check(n));
	}
	return 0;
}