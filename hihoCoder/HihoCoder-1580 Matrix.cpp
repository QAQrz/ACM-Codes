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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=312;
int n,m,p,a[maxn][maxn],sum[maxn],dp[maxn][2],mini[maxn],ans,minx,sumx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m>>p){
		ans=-inf;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		for(int l=0;l<n;l++){
			ms(sum,0);
			ms(mini,inf);
			for(int r=l;r<n;r++)
				if(l||r<n-1)
					for(int i=0;i<m;i++){
						sum[i]+=a[r][i],mini[i]=min(mini[i],a[r][i]);
						if(!i)
							dp[i][0]=sum[0],dp[i][1]=sum[0]+p-mini[i];
						else
							dp[i][0]=max(dp[i-1][0],0)+sum[i],dp[i][1]=max(dp[i-1][1]+sum[i],max(dp[i-1][0],0)+sum[i]+p-mini[i]);
						ans=max(ans,max(dp[i][0],dp[i][1]));
					}
				else
					for(int i=0;i<m;i++){
						minx=inf,sumx=0;
						for(int j=i;j<m;j++){
							minx=min(minx,min(mini[j],a[r][j])),sumx+=sum[j]+a[r][j];
							if(i||j<m-1)
								ans=max(ans,max(sumx,sumx+p-minx));
							else
								ans=max(ans,sumx+p-minx);
						}
					}
		}
		db(ans);
	}
	return 0;
}