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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=512345;
struct node{
	char s[5];
	int x;
}p[maxn],ans[12];
int n,t,a,b=1023,x=1023,y,z;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].s>>p[i].x;
		if(p[i].s[0]=='&')
			a&=p[i].x,b&=p[i].x;
		else if(p[i].s[0]=='|')
			a|=p[i].x,b|=p[i].x;
		else
			a^=p[i].x,b^=p[i].x;
	}
	for(int i=0;i<10;i++)
		if(((a>>i)&1)&&!((b>>i)&1))
			z^=1<<i;
		else if(((a>>i)&1)&&((b>>i)&1))
			y|=1<<i;
		else if(!((a>>i)&1)&&!((b>>i)&1))
			x&=~(1<<i);
	if(x<1023)
		ans[t].s[0]='&',ans[t++].x=x;
	if(y)
		ans[t].s[0]='|',ans[t++].x=y;
	if(z)
		ans[t].s[0]='^',ans[t++].x=z;
	db(t);
	for(int i=0;i<t;i++)
		printf("%s %d\n",ans[i].s,ans[i].x);
	return 0;
}