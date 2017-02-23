#include <bits/stdc++.h>
using namespace std;
int n,d,i,j,a,dp[2048][22],ans;
int trans(int x){
	return x-x%10+(x%10>4?10:0);
}
int main(){
	while(cin>>n>>d){
		ans=0x3f3f3f3f;
		for(i=1;i<=n;i++){
			cin>>a;
			for(j=0;j<min(i,d+1);j++){
				if(!j)
					dp[i][j]=dp[i-1][j]+a;
				else if(j==i-1)
					dp[i][j]=trans(dp[i-1][j-1])+a;
				else
					dp[i][j]=min(trans(dp[i-1][j-1])+a,dp[i-1][j]+a);
				if(i==n)
					ans=min(ans,trans(dp[i][j]));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}