#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
typedef long long LL;
LL t,p,n,m,dp[1<<22],a[22]={1},b[22],ans,g;
int main(){
	for(int i=1;i<22;i++)
		a[i]=a[i-1]*i;
	scanf("%lld",&t);
	while(t--){
		memset(dp,0,sizeof dp);
		scanf("%lld %lld %lld",&p,&n,&m);
		for(int i=n;i<n+m;i++)
			scanf("%lld",&b[i]);
		dp[ans=0]=1;
		for(int i=0;i<(1<<(n+m));i++)
			if(dp[i]){
				LL n1=0,n2=0,sum=0;
				for(int j=0;j<n+m;j++)
					if(i>>j&1)
						if(j<n)
							n1++;
						else
							sum+=b[j],n2++;
				if(sum>=p||n1<n2){
					if(sum>=p)
						ans+=dp[i]*a[n+m-n1-n2];
					continue;
				}
				for(int j=0;j<n+m;j++)
					if(!(i>>j&1))
						dp[i|(1<<j)]+=dp[i];
			}
		g=__gcd(ans,a[n+m]);
		printf("%lld/%lld\n",ans/g,a[n+m]/g);
	}
	return 0;
}