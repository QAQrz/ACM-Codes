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
struct node{
	int v,next;
}p[maxn*2];
int t,n,x,u,cnt,head[maxn],dis[maxn],vis[maxn];
queue<int>q;
inline void add(int u,int v){
	p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	freopen("jumping.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d",&t);
	while(t--){
		cnt=0;
		ms(head,-1);
		ms(dis,inf);
		ms(vis,0);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(i-x>0)
				add(i-x,i);
			if(i+x<=n)
				add(i+x,i);
		}
		vis[n]=1,dis[n]=0;
		q.push(n);
		while(q.size()){
			u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];~i;i=p[i].next)
				if(dis[p[i].v]>dis[u]+1){
					dis[p[i].v]=dis[u]+1;
					if(!vis[p[i].v]){
						vis[p[i].v]=1;
						q.push(p[i].v);
					}
				}
		}
		for(int i=1;i<=n;i++)
			printf("%d\n",dis[i]<inf?dis[i]:-1);
	}
	return 0;
}