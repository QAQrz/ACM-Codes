#include <bits/stdc++.h>
using namespace std;
int a[101][101][11],n,q,c,x,y,s,x2,y2,ans,t;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>q>>c;
	while(n--){
		cin>>x>>y>>s;
		a[x][y][s]++;
	}
	for(int i=1;i<=100;i++)
		for(int j=2;j<=100;j++)
			for(int k=0;k<=c;k++)
				a[i][j][k]+=a[i][j-1][k];
	for(int i=2;i<=100;i++)
		for(int j=1;j<=100;j++)
			for(int k=0;k<=c;k++)
				a[i][j][k]+=a[i-1][j][k];
	while(q--){
		ans=0;
		cin>>t>>x>>y>>x2>>y2;
		for(int k=0;k<=c;k++)
			ans+=(a[x2][y2][k]-a[x-1][y2][k]-a[x2][y-1][k]+a[x-1][y-1][k])*((t+k)%(c+1));
		cout<<ans<<endl;
	}
	return 0;
}