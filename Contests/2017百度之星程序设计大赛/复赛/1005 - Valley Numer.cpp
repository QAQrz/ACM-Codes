#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=128;
LL t,l,dp[maxn][11][11],a[maxn];
char s[maxn];
LL dfs(LL pos,LL limit,LL first,LL now,LL pre){
	if(!~pos)
		return 1;
	if(!limit&&!first&&~dp[pos][pre][now])
		return dp[pos][pre][now];
	LL sum=0,up=limit?a[pos]:9;
	for(int i=0;i<=up;i++)
		if(!(now>pre&&now>i))
			sum=(sum+dfs(pos-1,limit&&i==up,!i&&first,(!i&&first)?10:i,i==now?pre:now))%mod;
	if(!limit&&!first)
		dp[pos][pre][now]=sum;
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	ms(dp,-1);
	while(t--){
		cin>>s;
		l=strlen(s);
		for(int i=0;i<l;i++)
			a[i]=s[i]-'0';
		for(int i=0;i<l/2;i++)
			swap(a[i],a[l-i-1]);
		db(dfs(l-1,1,1,10,10)-1);
	}
	return 0;
}