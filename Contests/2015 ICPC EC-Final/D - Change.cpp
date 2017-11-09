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
int t;
double a, b;
int main(){
	scanf("%d", &t);
	for(int cs=1; cs<=t; ++cs) {
		scanf("%lf %lf", &a, &b);
		printf("Case #%d: ", cs);
		if(b==0.01 || b==0.1 || b==1.0 || b==10.0 || b==100.0) {
			if(fabs(a-b*2.0) <= eps) printf("0.01\n");
			else printf("0.02\n");
		}
		else printf("0.01\n");
	}
	return 0;
}