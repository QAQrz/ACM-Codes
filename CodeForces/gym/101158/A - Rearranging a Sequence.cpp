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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=212345;
int n,m,a[maxn],vis[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=m;i;i--)
		if(!vis[a[i]]){
			db(a[i]);
			vis[a[i]]=1;
		}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			db(i);
	return 0;
}