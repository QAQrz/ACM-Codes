#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f;
LL n,k,a[512345],l,r,mid,low,high,mina=inf,maxa,sum,s;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mina=min(mina,a[i]),maxa=max(maxa,a[i]),s+=a[i];
	}
	l=mina,r=maxa;
	while(l<=r){
		mid=(l+r)>>1,sum=0;
		for(int i=0;i<n;i++)
			sum+=max(0LL,mid-a[i]);
		if(sum>k)
			r=mid-1;
		else
			low=mid,l=mid+1;
	}
	l=mina,r=maxa;
	while(l<=r){
		mid=(l+r)>>1,sum=0;
		for(int i=0;i<n;i++)
			sum+=max(0LL,a[i]-mid);
		if(sum>k)
			l=mid+1;
		else
			high=mid,r=mid-1;
	}
	db(max(s%n?1LL:0LL,high-low));
	return 0;
}