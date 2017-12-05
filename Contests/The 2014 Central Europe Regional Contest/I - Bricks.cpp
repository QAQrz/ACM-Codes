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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=112345;
struct node{
	LL x;
	char flag;
}p[maxn];
LL t,n,top,x,y,a,b,g,ans;
char s[5];
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		a=b=ans=top=0;
		while(n--){
			scanf("%lld %s",&x,s);
			if(!top||s[0]!=p[top-1].flag)
				p[top].flag=s[0],p[top++].x=x;
			else
				p[top-1].x+=x;
		}
		if(top<2)
			ans=p[0].x;
		else{
			for(LL i=0;i<top;i++)
				if(i%2)
					b+=p[i].x;
				else
					a+=p[i].x;
			g=__gcd(a,b),a/=g,b/=g,x=y=0;
			for(LL i=0;i<top;i++)
				if(!i)
					x+=p[i].x;
				else if(i%2){
					if(!x||(x*b)%a||x*b/a>p[i].x+y||x*b/a<y)
						y+=p[i].x;
					else
						y=y+p[i].x-x*b/a,x=0,ans++;
				}
				else{
					if(!y||(y*a)%b||y*a/b>p[i].x+x||y*a/b<x)
						x+=p[i].x;
					else
						x=x+p[i].x-y*a/b,y=0,ans++;
				}
		}
		printf("%lld\n",ans);
	}
	return 0;
}