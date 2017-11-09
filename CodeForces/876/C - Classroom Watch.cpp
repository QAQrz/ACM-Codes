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
int n,s,t,ans[maxn];
inline bool check(int x,int s){
	if(s<=0)
		return 0;
	int y=0;
	while(s)
		y+=s%10,s/=10;
	return x==y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	t=n;
	while(t)
		s+=9,t/=10;
	for(int i=1;i<s;i++)
		if(check(i,n-i))
			ans[t++]=n-i;
	sort(ans,ans+t);
	db(t);
	for(int i=0;i<t;i++)
		db(ans[i]);
	return 0;
}