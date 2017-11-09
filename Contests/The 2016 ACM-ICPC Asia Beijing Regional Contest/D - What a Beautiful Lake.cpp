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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=212;
int n,a[maxn],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n&&n){
		ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i+n]=a[i];
		}
		for(int i=1,x=0,y=0;i<n*2;i++){
			if(a[i]>a[i-1])
				x++,ans=max(ans,x);
			else
				x=0;
			if(a[i]<a[i-1])
				y++,ans=max(ans,y);
			else
				y=0;
		}
		db(ans);
	}
	return 0;
}