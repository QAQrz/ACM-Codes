#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=212345;
LL t,n,m,l,ans,a[maxn],p,s;
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>m>>l;
		for(int i=0;i<n;i++)
			cin>>a[i];
		p=ans=0,a[n++]=m,s=-l;
		sort(a,a+n);
		for(int i=0;i<n;i++){
			ans+=(a[i]-p)/(l+1)*2,s+=(a[i]-p)/(l+1)*(l+1);
			if(a[i]-s>l)
				s=p+(a[i]-p)/(l+1)*(l+1),ans++;
			p=a[i];
		}
		printf("Case #%d: %lld\n",k,ans);
	}
	return 0;
}