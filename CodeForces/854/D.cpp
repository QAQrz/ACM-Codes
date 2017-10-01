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
const LL inf=1e17,mod=1e9+7,maxn=1123456,maxd=1000000;
struct node{
	LL d,f,t,c;
}p[maxn];
LL n,m,k,cost[maxn],sum,a[maxn],b[maxn],num,ans=inf;
inline bool cmp(node a,node b){
	return a.d<b.d;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
		cin>>p[i].d>>p[i].f>>p[i].t>>p[i].c;
	sort(p,p+m,cmp);
	for(int i=0;i<m;i++){
		if(p[i].f){
			if(!cost[p[i].f])
				cost[p[i].f]=p[i].c,sum+=p[i].c,num++;
			else if(cost[p[i].f]>p[i].c)
				sum-=cost[p[i].f]-p[i].c,cost[p[i].f]=p[i].c;
		}
		if(num>=n)
			a[p[i].d]=sum;
	}
	for(int i=1;i<=maxd;i++)
		if(!a[i])
			a[i]=a[i-1];
	ms(cost,0);
	num=sum=0;
	for(int i=m-1;~i;i--){
		if(p[i].t){
			if(!cost[p[i].t])
				cost[p[i].t]=p[i].c,sum+=p[i].c,num++;
			else if(cost[p[i].t]>p[i].c)
				sum-=cost[p[i].t]-p[i].c,cost[p[i].t]=p[i].c;
		}
		if(num>=n)
			b[p[i].d]=sum;
	}
	for(int i=maxd;i>k;i--){
		if(!b[i])
			b[i]=b[i+1];
		if(a[i-k-1]&&b[i])
			ans=min(ans,a[i-k-1]+b[i]);
	}
	db(ans>=inf?-1:ans);
	return 0;
}