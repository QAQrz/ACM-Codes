#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
typedef long long LL;
int a[3123],n,m,u,v,w,ans;
int main(){
	while(~scanf("%d %d",&n,&m)){
		ans=0x3f3f3f3f;
		memset(a,0,sizeof a);
		while(m--){
			scanf("%d %d %d",&u,&v,&w);
			if(u!=v)
				a[u]+=w,a[v]+=w;
		}
		for(int i=1;i<=n;i++)
			ans=min(ans,a[i]);
		db(ans);
	}
	return 0;
}