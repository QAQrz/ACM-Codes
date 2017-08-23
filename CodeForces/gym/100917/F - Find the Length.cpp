#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=333;
LL n,mmp[maxn][maxn],ans[maxn],pre[maxn],dis[maxn],vis[maxn],num,sum;
deque<LL>q;
inline LL find(LL x){
	LL t=x,temp;
	while(pre[x]!=x)
		x=pre[x];
	while(pre[t]!=t)
		temp=pre[t],pre[t]=x,t=temp;
	return x;
}
inline void spfa(LL s){
	for(int i=1;i<=n;i++)
		dis[i]=inf,pre[i]=i;
	q.pb(s);
	sum=dis[s]=0,num=vis[s]=1;
	while(q.size()){
		LL u=q.front();
		q.pop_front();
		if(dis[u]*num>sum){
			q.pb(u);
			continue;
		}
		vis[u]=0,num--,sum-=dis[u];
		for(int v=1;v<=n;v++)
			if(dis[v]>dis[u]+mmp[u][v]){
				dis[v]=dis[u]+mmp[u][v];
				if(u!=s)
					pre[v]=u;
				if(!vis[v]){
					vis[v]=1,num++,sum+=dis[v];
					if(!q.size()||dis[v]<dis[q.front()])
						q.pf(v);
					else
						q.pb(v);
				}
			}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>mmp[i][j];
			if(!~mmp[i][j])
				mmp[i][j]=inf;
		}
	ms(ans,inf);
	for(int s=1;s<=n;s++){
		spfa(s);
		for(int i=1;i<=n;i++){
			if(pre[i]!=i)
				ans[s]=min(ans[s],dis[i]+mmp[s][i]);
			for(int j=1;j<=n;j++)
				if(i!=s&&j!=s&&find(i)!=find(j))
					ans[s]=min(ans[s],dis[i]+dis[j]+mmp[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
		db(ans[i]<inf?ans[i]:-1);
	return 0;
}