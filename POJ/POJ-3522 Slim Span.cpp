#include <cstdio>
#include <cstring>
#include <cmath>
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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=128;
struct node{
	int u,v,w;
}p[maxn*maxn];
int n,m,pre[maxn],ans,maxw,flag,u,v;
inline bool cmp(node a,node b){
	return a.w<b.w;
}
inline int find(int x){
	int t=x,temp;
	while(x!=pre[x])
		x=pre[x];
	while(t!=pre[t])
		temp=pre[t],pre[t]=x,t=temp;
	return x;
}
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n>>m&&(n+m)){
		for(int i=0;i<m;i++)
			cin>>p[i].u>>p[i].v>>p[i].w;
		sort(p,p+m,cmp);
		ans=inf;
		for(int i=0;i<m-n+2;i++){
			flag=maxw=0;
			for(int j=1;j<=n;j++)
				pre[j]=j;
			for(int j=i;j<m;j++){
				u=find(p[j].u),v=find(p[j].v);
				if(u!=v)
					pre[max(u,v)]=min(u,v),maxw=max(maxw,p[j].w);
			}
			for(int j=1;j<=n;j++)
				if(find(j)>1){
					flag=1;
					break;
				}
			if(!flag)
				ans=min(ans,maxw-p[i].w);
		}
		if(ans>=inf)
			ans=-1;
		db(ans);
	}
	return 0;
}