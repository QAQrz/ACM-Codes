#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=512;
struct node{
	double x,y;
}a[maxn];
struct edge{
	int u,v;
	double w;
}p[maxn*maxn];
int t,n,m,pre[maxn],cnt,u,v,x;
double ans[maxn];
inline double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline bool cmp(edge a,edge b){
	return a.w<b.w;
}
inline int find(int x){
	int t=x,temp;
	while(pre[x]!=x)
		x=pre[x];
	while(pre[t]!=t)
		temp=pre[t],pre[t]=x,t=temp;
	return x;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>m>>n;
		x=cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y;
			pre[i]=i;
			for(int j=1;j<i;j++)
				p[cnt].u=i,p[cnt].v=j,p[cnt++].w=dis(a[i],a[j]);
		}
		sort(p,p+cnt,cmp);
		for(int i=0;i<cnt;i++){
			u=find(p[i].u),v=find(p[i].v);
			if(u!=v)
				pre[v]=u,ans[x++]=p[i].w;
		}
		printf("%.2f\n",ans[x-m]);
	}
	return 0;
}