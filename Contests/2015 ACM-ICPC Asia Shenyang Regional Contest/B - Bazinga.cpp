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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=512,maxm=2123;
int t,n,ans;
char s[maxn][maxm];
bool vis[maxn];
int main(){
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		scanf("%d",&n);
		ans=-1;
		memset(vis, 0, sizeof(vis));
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]);
			for(int j=1;j<i;++j)
				if(!vis[j]&&!strstr(s[i],s[j]))
					ans=i;
				else
					vis[j]=1;
		}
		printf("Case #%d: %d\n",k,ans);
	}
	return 0;
}