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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=2123;
int t,n,m,a[maxn],ans[maxn],len,q;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ms(ans,-1);
		for(int i=1;i<=n;i++)
			for(int j=i,x=0;j<=n;j++)
				x^=a[j],ans[x]=max(ans[x],j-i+1);
		scanf("%d",&m);
		while(m--){
			scanf("%d",&q);
			len=-1;
			for(int i=0;len<0&&i<maxn*2;i++){
				if(q-i>=0)
					len=max(len,ans[q-i]);
				if(q+i>=0&&q+i<2048)
					len=max(len,ans[q+i]);
			}
			printf("%d\n",len);
		}
		printf("\n");
	}
	return 0;
}