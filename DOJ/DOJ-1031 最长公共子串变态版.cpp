#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=112345;
int l,l1,dp[2][maxn][2],ans;
char s[maxn],s1[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin>>s>>s1;
	l=strlen(s),l1=strlen(s1);
	for(int i=0;i<l;i++)
		for(int j=0;j<l1;j++)
			if(s[i]==s1[j])
				ans=max(ans,max(dp[(i+1)%2][j+1][0]=dp[i%2][j][0]+1,dp[(i+1)%2][j+1][1]=dp[i%2][j][1]+1));
			else
				dp[(i+1)%2][j+1][0]=0,ans=max(ans,dp[(i+1)%2][j+1][1]=dp[i%2][j][0]+1);
	db(ans);
	return 0;
}