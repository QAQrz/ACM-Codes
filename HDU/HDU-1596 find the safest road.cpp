#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1024;
int n,m,s,t,vis[maxn],u,num;
double dis[maxn],a[maxn][maxn],sum;
deque<int>q;
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%lf",&a[i][j]);
		scanf("%d",&m);
		while(m--){
			scanf("%d %d",&s,&t);
			ms(dis,0);
			ms(vis,0);
			q.pf(s);
			sum=dis[s]=vis[s]=num=1;
			while(q.size()){
				u=q.front();
				q.pop_front();
				vis[u]=0,num--,sum-=dis[u];
				for(int i=1;i<=n;i++)
					if(dis[i]<dis[u]*a[u][i]){
						dis[i]=dis[u]*a[u][i];
						if(!vis[i]){
							vis[i]=1,num++,sum+=dis[i];
							if(!q.size()||dis[i]*num>sum||dis[i]>dis[q.front()])
								q.pf(i);
							else
								q.pb(i);
						}
					}
			}
			if(dis[t]<eps)
				printf("What a pity!\n");
			else
				printf("%.3f\n",dis[t]);
		}
	}
	return 0;
}