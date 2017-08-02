#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl;
typedef long long LL;
int a[16][16],n,p[2666],pp[2666],k,ans,dp[16][2666];
char s;
inline bool check(int x){
	while(x>2){
		if((x&1)&((x>>1)&1))
			return 0;
		x>>=1;
	}
	return 1;
}
inline int trans(int x){
	int ans=0;
	for(int i=0;i<16;i++)
		if((x>>i)&1){
			ans|=((1<<i)|(1<<(i+1)));
			if(i)
				ans|=(1<<(i-1));
		}
	return ans;
}
inline int getsum(int r,int x){
	if(!x)
		return 0;
	int ans=0;
	for(int i=0;i<n;i++)
		if((x>>i)&1)
			ans+=a[r][i];
	return ans;
}
int main(){
	for(int i=0;i<(1<<16);i++)
		if(check(i))
			p[k]=i,pp[k++]=trans(i);
	while(~scanf("%d%*c",&a[0][0])){
		ans=0,n=1;
		memset(dp,0,sizeof dp);
		while(scanf("%d%c",&a[0][n++],&s),s!='\n');
		for(int i=1;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(int i=0;i<k&&p[i]<(1<<n);i++)
			dp[0][i]=getsum(0,p[i]);
		for(int i=1;i<n;i++)
			for(int j=0;j<k&&p[j]<(1<<n);j++){
				for(int x=0;x<k&&p[x]<(1<<n);x++)
					if(!(p[j]&pp[x]))
						dp[i][j]=max(dp[i][j],dp[i-1][x]+getsum(i,p[j]));
				if(i==n-1)
					ans=max(ans,dp[i][j]);
			}
		printf("%d\n",ans);
	}
	return 0;
}