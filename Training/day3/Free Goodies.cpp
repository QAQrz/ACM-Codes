#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl
typedef long long LL;
struct node{
	int p,j;
}a[1024];
int dp[1024][512],c[1024][512],n,t,cnt,sum;
char s[11];
inline bool cmp(node a,node b){
	if(a.p==b.p)
		return a.j<b.j;
	return a.p>b.p;
}
int main(){
	scanf("%d",&t);
	while(t--){
		sum=cnt=0;
		memset(dp,0,sizeof dp);
		memset(c,0,sizeof c);
		scanf("%d %s",&n,s);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&a[i].p,&a[i].j);
			sum+=a[i].p;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=(s[0]=='P'?2:1);i<=n;i++){
			cnt++;
			for(int j=1;j<=(cnt+1)/2;j++){
				dp[i][j]=dp[i-1][j],c[i][j]=c[i-1][j];
				if(dp[i][j]<dp[i-1][j-1]+a[i].j)
					dp[i][j]=dp[i-1][j-1]+a[i].j,c[i][j]=c[i-1][j-1]+a[i].p;
				else if(dp[i][j]==dp[i-1][j-1]+a[i].j)
					c[i][j]=min(c[i][j],c[i-1][j-1]+a[i].p);
			}
		}
		printf("%d %d\n",sum-c[n][(cnt+1)/2],dp[n][(cnt+1)/2]);
	}
	return 0;
}