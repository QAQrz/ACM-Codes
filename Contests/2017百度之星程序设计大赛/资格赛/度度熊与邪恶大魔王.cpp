#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl
typedef long long LL;
LL n,m,a[112345],b[112345],k,p,v[1024],dp[12][1024],vb[12],ma,mp,mb,q,ans;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		memset(v,0x3f,sizeof v);
		memset(vb,0,sizeof vb);
		memset(dp,0x3f,sizeof dp);
		ans=ma=mb=mp=v[0]=0;
		debug(v[1]*2);
		for(LL i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			vb[b[i]]=1,ma=max(ma,a[i]),mb=max(mb,b[i]);
		}
		while(m--){
			cin>>k>>p;
			v[p]=min(v[p],k),mp=max(mp,p);
		}
		if(mp-mb<1)
			ans=-1;
		else{
			for(LL i=0;i<=mb;i++)
				if(vb[i]){
					dp[i][0]=0;
					for(LL j=1;j<=ma;j++){
						q=v[1001];
						for(LL x=i+1;x<=mp;x++)
							q=min(q,dp[i][max(i+j-x,0LL)]),dp[i][j]=min(dp[i][j],q+v[x]);
					}
				}
			for(LL i=1;i<=n;i++)
				ans+=dp[b[i]][a[i]];
		}
		debug(ans);
	}
	return 0;
}