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
int n,y,m,d,yy,mm,dd,x,flag;
char s[33];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d",&n);
	while(n--){
		scanf("%s %d/%d/%d %d/%d/%d %d",s,&y,&m,&d,&yy,&mm,&dd,&x);
		if(y>2009||yy>1990)
			flag=1;
		else if(x>40)
			flag=2;
		else
			flag=0;
		printf("%s %s\n",s,flag?(flag<2?"eligible":"ineligible"):"coach petitions");
	}
	return 0;
}