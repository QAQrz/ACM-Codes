#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
typedef long long LL;
LL n,m,ans=1,u,v,pre[55],mmp[55][55];
inline LL find(LL x){
	LL t=x,temp;
	while(x!=pre[x])
		x=pre[x];
	while(t!=pre[t])
		temp=pre[t],pre[t]=x,t=temp;
	return x;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		pre[i]=i;
	while(m--){
		cin>>u>>v;
		mmp[v][u]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(mmp[i][j]){
				v=find(j);
				if(v!=i)
					pre[v]=i,ans*=2;
			}
	db(ans);
	return 0;
}