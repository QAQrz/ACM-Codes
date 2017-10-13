#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
struct node{
	LL x,y;
}p[222];
struct edge{
	LL u,v,w;
}s[11234];
LL n,t,l,r,mid,ans,vis[222];
inline bool check(LL mid){
	ms(vis,0);
	for(int i=0;i<t;i++)
		if(s[i].w<=mid)
			vis[s[i].u]=vis[s[i].v]=1;
	for(int i=0;i<n*2;i++)
		if(!vis[i])
			return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(LL i=0;i<n*2;i++){
		cin>>p[i].x>>p[i].y;
		if(i>=n)
			for(LL j=0;j<n;j++)
				s[t].u=j,s[t].v=i,r=max(r,s[t++].w=abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y));
	}
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))
			r=mid-1,ans=mid;
		else
			l=mid+1;
	}
	db(ans);
	return 0;
}