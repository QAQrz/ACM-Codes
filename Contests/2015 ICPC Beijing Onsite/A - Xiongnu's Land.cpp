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
const LL inf=1e16,mod=1e9+7,maxn=1123456;
LL k,r,n,l,t,w,h,x,y,b,a[maxn],sum,ans,p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>k;
	while(k--){
		ms(a,0);
		b=ans=sum=0,p=inf;
		cin>>r>>n;
		while(n--){
			cin>>l>>t>>w>>h;
			x=min(r,l+w),y=max(0LL,t-h),a[l+1]+=t-y,a[x+1]-=t-y,sum+=(x-l)*(t-y);
		}
		for(int i=1;i<=r;i++){
			a[i]+=a[i-1],b+=a[i];
			if(b>=sum-b&&b*2-sum<=p)
				ans=i,p=b*2-sum;
		}
		db(ans);
	}
	return 0;
}