#include <bits/stdc++.h>
using namespace std;
int a[22][22],n,dp[22][18888],s[18888],k,ans;
inline bool check(int x){
	while(x>2){
		if((x&1)&((x>>1)&1))
			return 0;
		x>>=1;
	}
	return 1;
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
	for(int i=0;i<(1<<20);i++)
		if(check(i))
			s[k++]=i;
	while(~scanf("%d",&n)){
		ans=0;
		memset(dp,0,sizeof dp);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		if(n<1){
			printf("0\n");
			continue;
		}
		if(n<2){
			printf("%d\n",a[0][0]);
			continue;
		}
		for(int i=0;i<k&&(s[i]<(1<<n));i++)
			dp[0][i]=getsum(0,s[i]);
		for(int i=1;i<n;i++)
			for(int j=0;j<k&&(s[j]<(1<<n));j++){
				for(int x=0;x<k&&(s[x]<(1<<n));x++)
					if(!(s[j]&s[x]))
						dp[i][j]=max(dp[i][j],dp[i-1][x]+getsum(i,s[j]));
				if(i==n-1)
					ans=max(ans,dp[i][j]);
			}
		printf("%d\n",ans);
	}
	return 0;
}