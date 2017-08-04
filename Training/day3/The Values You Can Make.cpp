#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl
typedef long long LL;
int dp[512][512],n,k,a[512],t;
int main(){
	cin>>n>>k;
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=k;j>=a[i];j--)
			for(int x=0;x<=k;x++){
				if(dp[j-a[i]][x]){
					dp[j][x]=1;
					if(x+a[i]<=k)
						dp[j][x+a[i]]=1;
				}
			}
	}
	for(int i=0;i<=k;i++)
		if(dp[k][i])
			a[t++]=i;
	debug(t);
	for(int i=0;i<t;i++)
		printf("%d%c",a[i],i<t-1?' ':'\n');
	return 0;
}