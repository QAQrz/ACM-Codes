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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=112345;
int n,k,a[maxn],maxi=-inf,mini=inf,minx[maxn],miny[maxn],ans=-inf;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		minx[i]=mini=min(mini,a[i]),maxi=max(maxi,a[i]);
	}
	for(int i=n-1;~i;i--)
		miny[i]=i>n-2?a[i]:min(a[i],miny[i+1]);
	if(k<2)
		db(mini);
	else if(k>2)
		db(maxi);
	else{
		for(int i=1;i<n;i++)
			ans=max(ans,max(minx[i-1],miny[i]));
		db(ans);
	}
	return 0;
}