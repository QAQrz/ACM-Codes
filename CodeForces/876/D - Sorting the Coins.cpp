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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=312345;
int n,a[maxn],pre[maxn],sum[maxn],vis[maxn],u,v;
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
	cin.tie(0);
	cin>>n;
	printf("1");
	for(int i=1;i<=n;i++)
		pre[i]=i;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]=vis[a[i]]=1;
		if(a[i]>1&&vis[a[i]-1]){
			u=find(a[i]),v=find(a[i]-1);
			if(u!=v)
				pre[v]=u,sum[u]+=sum[v];
		}
		if(a[i]<n&&vis[a[i]+1]){
			u=find(a[i]),v=find(a[i]+1);
			if(u!=v)
				pre[u]=v,sum[v]+=sum[u];
		}
		printf(" %d",i-sum[n]+1);
	}
	ps("");
	return 0;
}