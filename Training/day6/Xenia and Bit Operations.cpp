#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
typedef long long LL;
int ans[1<<20],n,m,q,a,b;
void build(int l,int r,int t,int x){
	if(l>=r){
		cin>>ans[t];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,t<<1,x^1);
	build(mid+1,r,t<<1|1,x^1);
	if(x&1)
		ans[t]=ans[t<<1]|ans[t<<1|1];
	else
		ans[t]=ans[t<<1]^ans[t<<1|1];
}
void update(int p,int l,int r,int t,int x,int v){
	if(l>=r){
		ans[t]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(p>mid)
		update(p,mid+1,r,t<<1|1,x^1,v);
	else
		update(p,l,mid,t<<1,x^1,v);
	if(x&1)
		ans[t]=ans[t<<1]|ans[t<<1|1];
	else
		ans[t]=ans[t<<1]^ans[t<<1|1];
}
int main(){
	cin>>n>>m;
	build(1,1<<n,1,n%2);
	while(m--){
		cin>>a>>b;
		update(a,1,1<<n,1,n%2,b);
		db(ans[1]);
	}
	return 0;
}