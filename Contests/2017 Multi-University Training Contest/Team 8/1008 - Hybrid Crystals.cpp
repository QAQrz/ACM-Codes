#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=2123;
int t,n,a[maxn],k,l,r;
char s[maxn][2];
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>k;
		l=r=0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++){
			cin>>s[i];
			if(s[i][0]=='D')
				l-=a[i];
			else if(s[i][0]=='N')
				l-=a[i],r+=a[i];
			else
				r+=a[i];
		}
		db(l<=k&&k<=r?"yes":"no");
	}
	return 0;
}