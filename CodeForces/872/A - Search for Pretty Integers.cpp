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
int n,m,a[11],b[11],ans,p,q,x;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		a[x]=1;
	}
	for(int i=0;i<m;i++){
		cin>>x;
		b[x]=1;
	}
	for(int i=1;i<10;i++)
		if(a[i]&&b[i]){
			db(i);
			return 0;
		}
		else if(!p&&a[i])
			p=i;
		else if(!q&&b[i])
			q=i;
	printf("%d%d\n",min(p,q),max(p,q));
	return 0;
}